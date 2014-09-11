#include <cstdlib>
#include <iostream>
#include <ctime>

#include "test.h"

using namespace std;


int main( int argc, char** argv ){
    test<int> gg(5);
    cout << gg.get();
    return 0;
}
