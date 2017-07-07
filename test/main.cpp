#include "variant.h"
#include "gtest/gtest.h"

// #ifndef IOSTREAM_H
// #define IOSTREAM_H
// #include <iostream>
// #endif /* end of include guard: IOSTREAM_H */

TEST( Variant1, isOrdered ) {
    Variant v( 1 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant1, isRandom ) {
    Variant v( 1 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant1, isParallel ) {
    Variant v( 1 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant1, isFull ) {
    Variant v( 1 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant2, isOrdered ) {
    Variant v( 2 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant2, isRandom ) {
    Variant v( 2 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant2, isParallel ) {
    Variant v( 2 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant2, isFull ) {
    Variant v( 2 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant3, isOrdered ) {
    Variant v( 3 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant3, isRandom ) {
    Variant v( 3 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant3, isParallel ) {
    Variant v( 3 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant3, isFull ) {
    Variant v( 3 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant4, isOrdered ) {
    Variant v( 4 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant4, isRandom ) {
    Variant v( 4 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant4, isParallel ) {
    Variant v( 4 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant4, isFull ) {
    Variant v( 4 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant5, isOrdered ) {
    Variant v( 5 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant5, isRandom ) {
    Variant v( 5 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant5, isParallel ) {
    Variant v( 5 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant5, isFull ) {
    Variant v( 5 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant6, isOrdered ) {
    Variant v( 6 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant6, isRandom ) {
    Variant v( 6 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant6, isParallel ) {
    Variant v( 6 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant6, isFull ) {
    Variant v( 6 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant7, isOrdered ) {
    Variant v( 7 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant7, isRandom ) {
    Variant v( 7 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant7, isParallel ) {
    Variant v( 7 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant7, isFull ) {
    Variant v( 7 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant8, isOrdered ) {
    Variant v( 8 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant8, isRandom ) {
    Variant v( 8 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant8, isParallel ) {
    Variant v( 8 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant8, isFull ) {
    Variant v( 8 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant9, isOrdered ) {
    Variant v( 9 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant9, isRandom ) {
    Variant v( 9 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant9, isParallel ) {
    Variant v( 9 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant9, isFull ) {
    Variant v( 9 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant10, isOrdered ) {
    Variant v( 10 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant10, isRandom ) {
    Variant v( 10 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant10, isParallel ) {
    Variant v( 10 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant10, isFull ) {
    Variant v( 10 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant11, isOrdered ) {
    Variant v( 11 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant11, isRandom ) {
    Variant v( 11 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant11, isParallel ) {
    Variant v( 11 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant11, isFull ) {
    Variant v( 11 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant12, isOrdered ) {
    Variant v( 12 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant12, isRandom ) {
    Variant v( 12 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant12, isParallel ) {
    Variant v( 12 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant12, isFull ) {
    Variant v( 12 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant13, isOrdered ) {
    Variant v( 13 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant13, isRandom ) {
    Variant v( 13 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant13, isParallel ) {
    Variant v( 13 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant13, isFull ) {
    Variant v( 13 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant14, isOrdered ) {
    Variant v( 14 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant14, isRandom ) {
    Variant v( 14 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant14, isParallel ) {
    Variant v( 14 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant14, isFull ) {
    Variant v( 14 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant15, isOrdered ) {
    Variant v( 15 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant15, isRandom ) {
    Variant v( 15 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant15, isParallel ) {
    Variant v( 15 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant15, isFull ) {
    Variant v( 15 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant16, isOrdered ) {
    Variant v( 16 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant16, isRandom ) {
    Variant v( 16 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant16, isParallel ) {
    Variant v( 16 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant16, isFull ) {
    Variant v( 16 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant17, isOrdered ) {
    Variant v( 17 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant17, isRandom ) {
    Variant v( 17 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant17, isParallel ) {
    Variant v( 17 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant17, isFull ) {
    Variant v( 17 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant18, isOrdered ) {
    Variant v( 18 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant18, isRandom ) {
    Variant v( 18 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant18, isParallel ) {
    Variant v( 18 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant18, isFull ) {
    Variant v( 18 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant19, isOrdered ) {
    Variant v( 19 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant19, isRandom ) {
    Variant v( 19 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant19, isParallel ) {
    Variant v( 19 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant19, isFull ) {
    Variant v( 19 );
    EXPECT_TRUE( v.isFull() );
}
TEST( Variant20, isOrdered ) {
    Variant v( 20 );
    EXPECT_TRUE( v.isOrdered() );
}
TEST( Variant20, isRandom ) {
    Variant v( 20 );
    EXPECT_TRUE( v.isRandom() );
}
TEST( Variant20, isParallel ) {
    Variant v( 20 );
    EXPECT_TRUE( v.isParallel() );
}
TEST( Variant20, isFull ) {
    Variant v( 20 );
    EXPECT_TRUE( v.isFull() );
}


/*int main() {
    Variant v1(9);

    if( v1.isOrdered() )
        std::cout << "ORDERED" << std::endl;
    if( v1.isFull() )
        std::cout << "FULL" << std::endl;
    if( v1.isParallel() )
        std::cout << "PARALLEL" << std::endl;
    if( v1.isRandom() )
        std::cout << "RANDOM" << std::endl;
}*/
