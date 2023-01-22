/******************************************************************************
\file    ocean.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Assignment 03
\date    22-01-23

\brief
********************************************************************************/
#include<vector>
#include<iomanip>
#include<string>
#include"pa.hpp"
// See the specs for more information on how to author pa.cpp ...
namespace hlp2
{
    /******************************************************************
     * @brief This function extracts the name and population of each country
     * in the list.
     * 
     * @param is 
     * Reference to the filename to read information from.
     * 
     * @return
     * Returns the object 
     *********************************************************************/
     std::vector<CountryInfo> fill_vector_from_istream(std::istream &is)
    {
        //Declare needed strings.
        std::string country;
        std::string population;
        std::string whitespace = " \n\r\t\f\v";

        std::vector<CountryInfo> list;

        for (std::string line; getline(is, line);)
        {
            size_t countryIndex = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            size_t populationIndex = line.find_first_of("0123456789");
            //Find country string using the first letter found and first number found.
            country = line.substr(countryIndex, populationIndex - countryIndex);
            //find population string using the first number found.
            population = line.substr(populationIndex);

            country = (country.find_last_not_of(whitespace) == std::string::npos) ? "" : country.substr(0, country.find_last_not_of(whitespace) + 1);
            for (char c : population)
                if (c == ',')
                    population.erase(population.find(c), 1);
            //add new CountryInfo object to end of vector
            list.push_back(CountryInfo{country, stol(population)});
        }
        return list;
    }
/******************************************************************
 * @brief 
 * 
 * @param list 
 * @return size_t 
 *********************************************************************/
    size_t max_name_length(std::vector<CountryInfo> const & list)
    {
        size_t length = 0;
        for (CountryInfo i : list)
        {
            if(i.name.length()> length)
            {
                length = i.name.length();
            }
        }
        return length;
    }
/******************************************************************
 * @brief 
 * 
 * @param rv 
 * @param cmp 
 *********************************************************************/
    void sort(std::vector<CountryInfo> &rv, Ptr_Cmp_Func cmp)
    {
        for(size_t i = 0; i<rv.size();i++)
        {
            for(size_t j = 0;j<rv.size()-1;j++)
            {
                if(cmp(rv[j],rv[j+1]))
                {
                    CountryInfo temp = rv[j];
                    rv[j]=rv[j+1];
                    rv[j+1] = temp;
                }
            }
        }
    }
/******************************************************************
 * @brief 
 * 
 * @param v 
 * @param os 
 * @param fw 
 *********************************************************************/
    void write_to_ostream(std::vector<CountryInfo> const &v, std::ostream &os, size_t fw)
    {
        for(CountryInfo i : v)
        {
            os << std::left <<std::setw(fw) << i.name << i.pop << std::endl;
        }
    }
/******************************************************************
 * @brief 
 * 
 * @param left 
 * @param right 
 * @return true 
 * @return false 
 *********************************************************************/
    bool cmp_name_less(CountryInfo const &left, CountryInfo const &right)
    {
        if(std::string(left.name)>std::string(right.name))
        {
            return true;
        }
        else return false;
    }
/******************************************************************
 * @brief 
 * 
 * @param left 
 * @param right 
 * @return true 
 * @return false 
 *********************************************************************/
    bool cmp_name_greater(CountryInfo const &left, CountryInfo const &right)
    {
        if(std::string(left.name)<std::string(right.name))
        {
            return true;
        }
        else return false;
    }
/******************************************************************
 * @brief 
 * 
 * @param left 
 * @param right 
 * @return true 
 * @return false 
 *********************************************************************/
    bool cmp_pop_less(CountryInfo const &left, CountryInfo const &right)
    {
        if(left.pop > right.pop)
        {
            return true;
        }
        else return false;
    }
/******************************************************************
 * @brief 
 * 
 * @param left 
 * @param right 
 * @return true 
 * @return false 
 *********************************************************************/
    bool cmp_pop_greater(CountryInfo const &left, CountryInfo const &right)
    {
        if(left.pop < right.pop)
        {
            return true;
        }
        else return false;
    }
}