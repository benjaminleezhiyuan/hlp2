/*!*****************************************************************************
\file    q.hpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 02
\date    13-01-23

\brief
  This source file contains the declaration of functions that are specified in
  header file q.hpp and standalone in q.cpp. These files combine to perform
  the counting of total characters, letters, white spaces, digits and other characters.
*******************************************************************************/

#ifndef Q_HPP
#define Q_HPP

// This file can have only one include directive ...

// required since type Tsunami has data member of type std::string
#include <string> // don't remove

namespace hlp2 {
  struct Tsunami {
    // declare data members ...

    int month;
    int day;
    int year;
    int fatalities;
    double maxwave;
    std::string geo;
  };
  
  // declaration of interface functions ...

/*!**************************************************************************
\brief
    Reads data from text file

\param[in] file_name
    Name of file to read data from

\param[out] max_cnt
    Maximum number of data in text file

\return
    Data of all tsunamis read from file
****************************************************************************/
  Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt);

  /*!**************************************************************************
\brief
    Prints data to text file

\param[in] arr
    Array for struct Tsunami data.

\param[in] size
    Number of data to write

\param[in] file_name
    Name of file to write output to.

\return
    Formatted results of data
****************************************************************************/

  void print_tsunami_data(Tsunami const *arr,int size, std::string const& file_name);
  
  
} // end namespace hlp2
#endif
