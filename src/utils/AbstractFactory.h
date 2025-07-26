#include <memory>

template <typename T>
class AbstractFactory {
  public:
    virtual std::shared_ptr<T> create() = 0;
    virtual ~AbstractFactory() = default;  
};