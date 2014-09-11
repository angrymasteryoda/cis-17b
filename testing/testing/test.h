#ifndef TEST_H
#define TEST_H

using namespace std;

template <class T>
class test
{
    public:
        test(T);
        T get();
    private:
        T fish;
};

template<class T>
test<T>::test( T var ) {
    fish = var;
}

template<class T>
T test<T>::get() {
    return fish;
}

#endif // TEST_H
