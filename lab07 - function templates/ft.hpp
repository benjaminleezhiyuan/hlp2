// make sure to add file-level documentation here!!!

//-------------------------------------------------------------------------
#ifndef FT_H
#define FT_H
//-------------------------------------------------------------------------
#include <iostream>
// Do not add any other header files. Otherwise, your submission
// will not compile!!!

namespace hlp2 {
// DECLARE (not define!!!) and DOCUMENT in ALPHABETIC ORDER the function
// templates you'll be defining. There are *13* function templates to be
// declared and defined.
  
// I'm providing the declaration and documentation for swap here:
/***************************************************************************/
/*!
\brief
 Swaps two objects. There is no return value but the two objects are
 swapped in place.

\param lhs
  Reference to the first object to swap.

\param rhs
 Reference to the second object to swap.
*/
/**************************************************************************/
template <typename T> void swap(T &lhs, T &rhs);
  
// Provide DEFINITIONS for each function template declared above ...


}

#endif
//-------------------------------------------------------------------------
