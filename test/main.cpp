#include "variant.h"

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif /* end of include guard: IOSTREAM_H */
//

int main() {
    Variant v1(9);

    if( v1.isOrdered() )
        std::cout << "ORDERED" << std::endl;
    if( v1.isFull() )
        std::cout << "FULL" << std::endl;
    if( v1.isParallel() )
        std::cout << "PARALLEL" << std::endl;
    if( v1.isRandom() )
        std::cout << "RANDOM" << std::endl;
}
