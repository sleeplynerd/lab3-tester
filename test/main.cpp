#include "variant.h"

#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif /* end of include guard: IOSTREAM_H */


int main() {
    Variant v1;

    if( v1.isOrdered() )
        std::cout << "ORDERED" << std::endl;
}
