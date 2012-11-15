#ifndef MAKE_STRING_H_
#define MAKE_STRING_H_

#include <iomanip>
#include <sstream>
#include <string>

//! \brief In place stream formatting 
//!
//!	Usage:
//!		void f( std::string const & );
//!
//!		f( make_string() << "This string has " << 1 << " number" );
//!
//!	\author David Rodríguez Ibeas
//!	
//!	const char* conversion intentionally left aside. To implement it, 
//!		the std::string would have to be internally stored and the returned
//!		pointer would only be valid for a brief period of time, any use of 
//!     the returned pointer after the full expression in which the make_string
//!     object is created would cause undefined behavior.
class make_string
{
public:
    //!	\brief Conversion to std::string so that a temporary can be used in
    //!        place for a string.
    operator std::string () const
    {
        return buffer.str();
    }

    //! \brief Insertion into make_string delegates the call to the internal
    //!        ostringbuffer
    template <typename T>
    make_string& operator<<( T const & datum )
    {
        buffer << datum;
        return *this;
    }

    //! \brief Support for manipulators
    make_string& operator<<( std::basic_ostream& (*manip)( std::basic_ostream& ) )
    {
        buffer << manip;
        return *this;
    }

    //! \brief Support for manipulators
    make_string& operator<<( std::ios_base& (*manip)( std::ios_base& ) )
    {
        buffer << manip;
        return *this;
    }

    //! \brief Support for manipulators
    make_string& operator<<( std::ios& (*manip)( std::ios& ) )
    {
        buffer << manip;
        return *this;
    }

private:
    std::ostringstream buffer;
};

#endif	// MAKE_STRING_H_
