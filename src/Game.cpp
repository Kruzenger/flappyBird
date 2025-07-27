#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "./engine/Engine.h"
#include "./engine/entities/ColumnFactory.h"
#include "./engine/entities/GameObjectManager.h"
#include "./engine/components/Rectangle.h"
#include "./engine/components/Rigidbody2D.h"
#include "./engine/components/FlappyBirdPlayer.h"
#include <memory>

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT,
//                                       VK_LEFT, VK_UP, VK_DOWN, VK_RETURN)
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 -
//  left button, 1 - right button) schedule_quit_game() - quit game after act()

const int64_t kColumnDistance = 600;
const int64_t kColumnWidth = 150;
const int64_t kColumnGapSize = 250;
const Vector2D kPlayerStartPosition = Vector2D(400, SCREEN_HEIGHT / 2);
const Vector2D kPlayerSize = Vector2D(50, 50);

// colors
enum EColors {
    red = 0x00FF0000,
    green = 0x0000FF00,
    blue = 0x000000FF,
    white = 0x00FFFFFF
};

const int32_t kPlayerColor = EColors::red;
const int32_t kColumnColor = EColors::green;
const int32_t kBackgroundColor = EColors::white;

const int64_t kJumpTimeoutSize = 200;

/////////////////////////////////////////////////////

std::shared_ptr<GameObject> player;
std::shared_ptr<FlappyBirdPlayer> flappyBirdPlayer;
std::shared_ptr<GameObject> camera;
ColumnFactory factrory = ColumnFactory(kColumnWidth, kColumnGapSize, 400, kColumnColor);

int64_t score = 0;
int64_t distanceCounter = -1;
int64_t jumpTimeoutUntil = 0;


// initialize game data in this function
void initialize()
{
    camera = std::make_shared<GameObject>();
    GameObjectManager::getInstance().addCamera(camera);

    player = std::make_shared<GameObject>();
    player->addComponent(std::make_shared<Rectangle>(kPlayerSize.x, kPlayerSize.y, kPlayerColor));
    player->addComponent(std::make_shared<BoxCollider>(kPlayerSize.x, kPlayerSize.y));
    player->addComponent(std::make_shared<Rigidbody2D>(true));
    player->addComponent(flappyBirdPlayer = std::make_shared<FlappyBirdPlayer>());
    player->setLocalPosition(kPlayerStartPosition);
    GameObjectManager::getInstance().addObject(player);
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
    GameObjectManager::getInstance().updateCollisions(); 
    
    if (is_key_pressed(VK_ESCAPE) || !flappyBirdPlayer->isAlive())
        schedule_quit_game();

    if (is_key_pressed(VK_SPACE) && camera->getGlobalPosition().x > jumpTimeoutUntil) {
        flappyBirdPlayer->actionJump();
        jumpTimeoutUntil = camera->getGlobalPosition().x + kJumpTimeoutSize;
    }

    camera->setGlobalPosition(Vector2D(player->getGlobalPosition().x - (SCREEN_WIDTH / 2), 0)); 

    score = (camera->getGlobalPosition().x / 100);
    if(score / (kColumnDistance / 100) > distanceCounter) {
        ++distanceCounter;
        auto obj = factrory.create(kColumnGapSize - score, 150 + (50 * (std::rand() % 6)));
        obj->setLocalPosition(Vector2D(kColumnDistance * ((score / (kColumnDistance / 100)) + 3) + 100, 0));
        GameObjectManager::getInstance().addObject(obj);
    }

    GameObjectManager::getInstance().simulatePhysics(dt);
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors
// (8 bits per R, G, B)
void draw()
{
    // clear backbuffer
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

    // background // TODO сделать отдельного наследника класса Drawable который будет
    // рисовать объекты по своим локальным координатам. Сделать фон им. через него же 
    // сделать и счёт
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            buffer[i][j] = kBackgroundColor;
        }
    }

    // draw
    GameObjectManager::getInstance().renderObjects(camera->getGlobalPosition());
}

// free game data in this function
void finalize() {}
