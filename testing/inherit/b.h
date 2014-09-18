#ifndef B_H
#define B_H

#include <iostream>

class B : public A {
    public:
        B( int a , int b){
            something = a;
            other = b;
        }

        void abc(){
            cout << "test" <<endl ;
        }

    protected:
        int something;
        int other;
};

#endif // B_H
