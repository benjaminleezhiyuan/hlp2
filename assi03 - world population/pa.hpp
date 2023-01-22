
/******************************************************************************
\file    pa.hpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Assignment 03
\date    22-01-23

\brief
Contains declarations for all functions in pa.cpp needed to run program.
********************************************************************************/
// See the specs for more information on how to author pa.hpp ...
#ifndef PA_HPP
#define PA_HPP
#include <iostream>
#include <vector>
// necessary includes of header files except the following:
namespace HLP2
{
    // structure to encapsulate a country's name and its population ...
    struct CountryInfo
    {
        std::string name; // country's name - *exactly* as in input file
        long int pop;     // country's population
    };
    // other declarations ...
    using Ptr_Cmp_Func = bool (*)(CountryInfo const &, CountryInfo const &);

    std::vector<CountryInfo> fill_vector_from_istream(std::istream &is);

    size_t max_name_length(std::vector<CountryInfo> const &list);

    void sort(std::vector<CountryInfo> &rv, Ptr_Cmp_Func cmp);

    void write_to_ostream(std::vector<CountryInfo> const &v,

                          std::ostream &os, size_t fw);

    bool cmp_name_less(CountryInfo const &left, CountryInfo const &right);

    bool cmp_name_greater(CountryInfo const &left, CountryInfo const &right);

    bool cmp_pop_less(CountryInfo const &left, CountryInfo const &right);

    bool cmp_pop_greater(CountryInfo const &left, CountryInfo const &right);

} // end namespace hlp2
#endif
