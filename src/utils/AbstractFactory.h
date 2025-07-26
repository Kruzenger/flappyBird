template <typename T>
class AbstractFactory {
  public:
    virtual T* create() = 0;
    virtual ~AbstractFactory() = default;  
};