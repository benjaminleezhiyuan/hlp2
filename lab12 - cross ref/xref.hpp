/*!******************************************************************
 * \file      xref.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 12
 * \date      04-04-2023
 * 
 * \brief  This file contains the declarations of functions to obtain and print out the number of 
occurrances of all the words in a std::map along with their locations
 *********************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <iterator>

namespace hlp2{

    using VPII = std::vector<std::pair<int,int>>;

    /***************************************************************************/
    /*!
    \brief
        Function xref take a string indicating a filename and the characters to be ignored
        along with a boolean to determine case sensitivity and specific strings to be excluded.
        The function returns a pair contains the number of occurrances of all the words along
        with their locations.

    \return
        The a std::pair consisting of a std::map<std::string,VPII> and an int
    */
    /**************************************************************************/    

    std::pair<std::map<std::string, VPII>,int>xref(std::string const& filename,
                                                   std::string const& whitespace,
                                                   bool case_sensitivity,
                                                   std::set<std::string> const& exclude);

    /***************************************************************************/
    /*!
    \brief
        Outputs a std::map containing the number of occurrances of all the words along
        with their locations in a specified format.
    */
    /**************************************************************************/

    void print_wordmap(std::map<std::string, VPII> const& words);

}