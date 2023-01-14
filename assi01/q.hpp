/*!*****************************************************************************
\file    q.hpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Assignment 01
\date    10-01-23

\brief
  This source file contains the declaration of funtions that are needed for
  the excecution of q.cpp.
*******************************************************************************/

#ifndef Q_HPP_
#define Q_HPP_

// Important note:
// If there any includes in this file, the auto grade will not
// accept the submission.

namespace hlp2
{
  // declare function q here ...
/*!**************************************************************************
\brief
    Reads text files and writes to textfile

\param[in] input
    Name of text file to be read from.

\param[in] output
    Name of text file to be written to.

\return
    Total characters in text file and all their stats.
****************************************************************************/
  void q(char const *input, char const *output);
}

#endif
