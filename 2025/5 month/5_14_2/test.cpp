template <class T>
class Singleton
{
private:
    Singleton() {}
    ~Singleton() {}

public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static T &getInstance()
    {
        static T instance;
        return instance;
    }
};