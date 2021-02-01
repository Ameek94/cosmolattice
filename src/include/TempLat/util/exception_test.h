#ifndef TEMPLAT_UTIL_EXCEPTION_TEST_H
#define TEMPLAT_UTIL_EXCEPTION_TEST_H
 
/* This file is part of CosmoLattice, available at www.cosmolattice.net .
   Copyright Daniel G. Figueroa, Adrien Florio, Francisco Torrenti and Wessel Valkenburg.
   Released under the MIT license, see LICENSE.md. */ 
   
// File info: Main contributor(s): Wessel Valkenburg,  Year: 2019



MakeException(TestException);

inline void TempLat::Exception::Test(TempLat::TDDAssertion& tdd) {
    
    tdd.verify( Throws<TestException>( [] { throw TestException("Hoi!"); }) );

}

#endif
