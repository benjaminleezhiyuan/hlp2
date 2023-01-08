/*!*****************************************************************************
\file    wc.hpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\date    07-01-23

\brief
  This source file contains the declaration of funtions that are needed for
  the excecution of wc.cpp.
*******************************************************************************/

// Our convention is use suffix hpp for header files that will be consumed by C++ source files!!!

// We must always provide header guards in every header file to avoid types being defined
// multiple times [which will be flagged by the compiler]. This happens when this file
// will be included multiple times in a source file.
#ifndef WC_HPP
#define WC_HPP

// No header files must be included here!!!
// The presence of preprocesser directive include in this file will prevent compilation of your code.
// To avoid name clashes, everything we do this must be declared and defined in namespace hlp2:

namespace hlp2
{
/*!**************************************************************************
\brief
    Reads user inputted text files 

\param[in] argc
    Number of arguments to run with function wc.

\param[in] argv
    Pointer to names of txt files inputted by user.

\return
    Total number of lines, words and bytes for each txt file.
****************************************************************************/
    void wc(int argc, char *argv[]);

    // Add function-level Doxygen documentation block for function wc!!!

    // add declaration of function wc in this namespace
} // end namespace hlp2

#endif // end header guard
