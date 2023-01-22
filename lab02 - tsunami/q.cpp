/*!*****************************************************************************
\file    q.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 02
\date    13-01-23

\brief
  This source file contains the definition of functions that are specified in
  header file q.hpp and standalone in q.cpp. These files combine to perform
  the counting of total characters, letters, white spaces, digits and other characters.

    -trim
      Deletes leading spaces from string.

    -read_tsunami_data
      Reads tsunami data from text file and stores them in a dynamically allocated
      array

    -print_tsunami_data
      Prints results of data to text file.

*******************************************************************************/

// This file can only have these 5 files included and therefore you should not
// remove the following include directives nor provide additional include directives!!!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "q.hpp" // compiler needs definition of type Tsunami

// anonymous namespace for any helper functions that you wish to implement
namespace
{
/*
\brief
    Reads string from input

\param[in] string
    String to trim

\return
    String with leading spaces removed.
****************************************************************************/
  std::string &trim(std::string &string) // remove leading and trailing whitespaces
  {
    size_t p = string.find_first_not_of(" ");
    string.erase(0, p);
    p = string.find_last_not_of(" ");
    if (p != std::string::npos)
    {
      string.erase(p + 1);
    }
    return string;
  }
}

namespace hlp2
{
  // provide definitions of functions declared in q.hpp here ...
  Tsunami *read_tsunami_data(std::string const &file_name, int &max_cnt)
  {
    std::ifstream ifs(file_name);
    if (!ifs)
    {
      // input file doesn't exist
      max_cnt = 0;
      return nullptr;
    }
    // determine number of tsunami events in input file
    std::string line;
    int count = 0;
    while (std::getline(ifs, line))
    {
      count++;
    }
    max_cnt = count;
    // allocate dataay of Tsunami objects
    Tsunami *data = new Tsunami[max_cnt];
    // read data for each tsunami event
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    for (int i = 0; i < max_cnt; i++)
    {
      ifs >> data[i].month;
      ifs >> data[i].day;
      ifs >> data[i].year;
      ifs >> data[i].fatalities;
      ifs >> data[i].maxwave;
      std::getline(ifs, data[i].geo);
      trim(data[i].geo);
    }
    return data;
  }

  void print_tsunami_data(Tsunami const *data, int size, std::string const &file_name)
  {
    std::ofstream ofs(file_name);
    // Wave calculations
    double maxwave = 0.0f, averagewave = 0.0f, wavetotal = 0.0f;
    // print header
    ofs << "List of tsunamis:\n";
    ofs << "-----------------\n";
    for (int i = 0; i < size; i++)
    {
      ofs << std::right << std::setw(2) << std::setfill('0') << data[i].month << " ";
      ofs << std::setw(2) << std::setfill('0') << data[i].day << " ";
      ofs << std::setw(4) << data[i].year << " ";
      ofs << std::setw(6) << std::setfill(' ') << data[i].fatalities << " ";
      ofs << std::setw(10) << std::setprecision(2) << std::fixed << data[i].maxwave << "     ";
      ofs << std::left << data[i].geo << std::endl;

      wavetotal += data[i].maxwave;
      maxwave = data[i].maxwave > maxwave ? data[i].maxwave : maxwave;
    }
    averagewave = wavetotal / size;
    ofs << "\n";
    ofs << "Summary information for tsunamis\n";
    ofs << "--------------------------------\n\n";
    ofs << "Maximum wave height (in meters): " << std::right << std::setw(5) << maxwave << std::endl
        << std::endl;
    ofs << "Average wave height (in meters): " << std::right << std::setw(5) << averagewave << std::endl
        << std::endl;
    ofs << std::right << std::setw(38) << "Tsunamis with greater than average height " << averagewave << ":\n";
    for (int i = 0; i < size; i++)
    {
      if (data[i].maxwave > averagewave)
      {
        ofs << data[i].maxwave << "     " << data[i].geo << std::endl;
      }
    }
  }
}
