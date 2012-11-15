#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

//! \brief Array utils
//!
//! Type safe array utilities that allow for obtaining the size
//! of an array as a runtime value or a constant expression 
//! as well as container like 'begin' and 'end'.
//!
//! Usage:
//!    T a[K];
//!
//!    for (int i = 0; i < array::size(a); ++i) {   // runtime value
//!       a[i] = i*i;
//!    }
//!
//!    int ints[ ARRAY_SIZE(a) ];                   // constant expression
//!
//!    std::transform( array::begin(array), array::end(array),
//!                    array::begin(ints), transformation );
//!
//! \author David Rodríguez Ibeas
namespace array {
    //! \brief Container like begin iterator (trivial, provided only for
    //!        consistency
	template <typename T, unsigned int N>
	T* begin( T (&array)[N] ) {
		return array;
	}

    //! \brief Container like end iterator
	template <typename T, unsigned int N>
	T* end( T (&array)[N] ) {
		return array+N;
	}

    //! \brief Runtime size of an array
	template <typename T, unsigned int N>
	unsigned int size( T (&)[N] ) {
		return N;
	}

    //! \brief Helper function for the static array size macro
    //! \note This template is declared but not defined
    template <typename T, unsigned int N>
    char (&static_array_impl( T(&)[N] ))[N];
//! \brief Type safe constant expression size of an array
#define ARRAY_SIZE(x) sizeof(::array::static_array_impl(x))
}

#endif	// ARRAY_UTILS_H
