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

GameObjectManager GAME_OBJ_MNG;
std::shared_ptr<GameObject> player;
std::shared_ptr<FlappyBirdPlayer> flappyBirdPlayer;
Vector2D camera_position;
ColumnFactory factrory = ColumnFactory(100, 200, 400, 0x00FFFFFF);
int64_t score = 0;
int64_t distanceCounter = -1;

// initialize game data in this function
void initialize()
{
    camera_position = Vector2D(0, 0);
    player = std::make_shared<GameObject>();
    player->addComponent(std::make_shared<Rectangle>(50, 50, 0x00FF0000));
    player->addComponent(std::make_shared<BoxCollider>(50, 50));
    player->addComponent(std::make_shared<Rigidbody2D>(true));
    player->addComponent(flappyBirdPlayer = std::make_shared<FlappyBirdPlayer>());
    player->setLocalPosition(400, SCREEN_HEIGHT / 2);
    GAME_OBJ_MNG.addObject(player);
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
    GAME_OBJ_MNG.updateCollisions(); 
    
    if (is_key_pressed(VK_ESCAPE) || !flappyBirdPlayer->isAlive())
        schedule_quit_game();

    if (is_key_pressed(VK_SPACE))
        flappyBirdPlayer->actionJump();

    camera_position.x = player->getLocalPosition().x - (SCREEN_WIDTH / 2); 

    score = (camera_position.x / 100);
    if(score / 10 > distanceCounter) {
        ++distanceCounter;
        auto obj = factrory.create(300, 150 + (50 * (std::rand() % 6)));
        obj->setLocalPosition(Vector2D(1000 * (score / 10) + 1100, 0));
        GAME_OBJ_MNG.addObject(obj);
    }

    GAME_OBJ_MNG.simulatePhysics(dt);
}
// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors
// (8 bits per R, G, B)
void draw()
{
    // clear backbuffer
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

    // draw
    GAME_OBJ_MNG.renderObjects(camera_position);
}

// free game data in this function
void finalize() {}
