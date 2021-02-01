#ifndef TEMPLAT_LATTICE_ALGEBRA_OPERATORS_ASINH_H
#define TEMPLAT_LATTICE_ALGEBRA_OPERATORS_ASINH_H
 
/* This file is part of CosmoLattice, available at www.cosmolattice.net .
   Copyright Daniel G. Figueroa, Adrien Florio, Francisco Torrenti and Wessel Valkenburg.
   Released under the MIT license, see LICENSE.md. */ 
   
// File info: Main contributor(s): Adrien Florio,  Year: 2020

#include "TempLat/util/tdd/tdd.h"
#include "TempLat/lattice/algebra/constants/onetype.h"
#include "TempLat/lattice/algebra/constants/zerotype.h"
#include "TempLat/lattice/algebra/conditional/conditionalunarygetter.h"
#include "TempLat/lattice/algebra/operators/unaryoperator.h"
#include "TempLat/lattice/algebra/operators/multiply.h"
#include "TempLat/lattice/algebra/operators/exponential.h"
#include "TempLat/lattice/algebra/helpers/getderiv.h"
namespace TempLat {


    /** \brief A class which computes the asinh.
     * 
     * 
     * Unit test: make test-asinh
     **/

    namespace Operators {

        template <typename T>
        class ASinh : public UnaryOperator<T> {
        public:

            /* Yes, need to do this 'using': parent class is template, stuff is not visible to the compiler yet. */
            using UnaryOperator<T>::mR;

            /* Put public methods here. These should change very little over time. */
            ASinh(T a) : UnaryOperator<T>(a) {   }

            /** \brief Getter for two instances. */
            inline auto get(ptrdiff_t i)  {
                using namespace std; /* not std::exp, but this way, for potential future data types. */
                return asinh(GetValue::get(mR, i));
            }

            /** \brief And passing on the automatic / symbolic derivatives. Having fun here, this is awesome. */
            template <typename U>
            inline auto d(const U& other)  {
                return 1 / sqrt(1  +  (*this) * (*this)) * GetDeriv::get(mR, other);
            }

            virtual std::string operatorString() const {
                return "asinh";
            }

        private:
            /* Put all member variables and private methods here. These may change arbitrarily. */


        };

    }


    /** \brief A mini struct for instiating the test case. */
    struct ASinhTester {
#ifdef TEMPLATTEST
        static inline void Test(TDDAssertion& tdd);
#endif
    };

    /** \brief Exposing our newly define exp operation to the world. */
    template <typename T>
    inline
    typename ConditionalUnaryGetter<Operators::ASinh, T>::type
    asinh( T a) {
        return Operators::ASinh<T>(a);
    }




} /* TempLat */

#ifdef TEMPLATTEST
#include "TempLat/lattice/algebra/operators/asinh_test.h"
#endif


#endif
