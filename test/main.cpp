#include "variant.h"

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif /* end of include guard: IOSTREAM_H */
//

int main() {
    Variant v1(1);

    if( v1.isOrdered() )
        std::cout << "ORDERED" << std::endl;
    if( v1.isFull() )
        std::cout << "IS FULL" << std::endl;
    if( v1.isParallel() )
        std::cout << "IS PARALLEL" << std::endl;
}
