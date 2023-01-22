/******************************************************************************
\file    pa.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Assignment 03
\date    22-01-23

\brief
This file contains functions to transform input text file with table of names
and countries into four output files containing tables with countries names 
sorted in increasing and decreasing orders and population counts sorted in 
increasing and decreasing order.

    -fill_vector_from_istream
        Fills vector object CountryInfo with names and populations of countries
        found in input text file.

    -max_name_length
        Finds the length of the longest country's name.

    -sort
        Sorts all elements in vector object using sorting criterion specified
        by function pointer cmp.
    
    - write_to_ostream
        Prints contents of vector object CountrInfo to output stream

    - cmp_name_less
        Compares names of 2 countries to check if one is lexicographically
        less than the other.

    -cmp_name_greater
        Compares names of 2 countries to check if one is lexicographically
        greater than the other.

    -cmp_pop_less
        Compares population of 2 countries to check if one is less than
        the other.

    -cmp_pop_greater
        Compares population of 2 countries to check if one is greater than
        the other.

********************************************************************************/
#include <vector>
#include <iomanip>
#include <string>
#include "pa.hpp"
// See the specs for more information on how to author pa.cpp ...
namespace HLP2
{
    /******************************************************************
     * @brief This function extracts the name and population of each country
     * in the list.
     *
     * @param is
     * Reference to the filename to read information from.
     *
     * @return
     * Returns the new vector object CountryInfo to caller.
     *********************************************************************/
    std::vector<CountryInfo> fill_vector_from_istream(std::istream &is)
    {
        // Declare needed strings.
        std::string country;
        std::string population;
        std::string whitespace = " \n\r\t\f\v";

        std::vector<CountryInfo> list;

        for (std::string line; getline(is, line);)
        {
            size_t countryIndex = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            size_t populationIndex = line.find_first_of("0123456789");
            // Find country string using the first letter found and first number found.
            country = line.substr(countryIndex, populationIndex - countryIndex);
            // find population string using the first number found.
            population = line.substr(populationIndex);
            // removes all whitespaces from the end of country.
            country = country.substr(0, country.find_last_not_of(whitespace) + 1);
            // removes commas from population number.
            for (char c : population)
            {
                if (c == ',')
                {
                    population.erase(population.find(c), 1);
                }
            }
            // add new CountryInfo object to end of vector
            list.push_back(CountryInfo{country, stol(population)});
        }
        return list;
    }
    /******************************************************************
     * @brief
     * function finds the length of the longest country's name.
     *
     * @param list
     * reference to the list of country information
     *
     * @return
     * length of longest country's name
     *********************************************************************/
    size_t max_name_length(std::vector<CountryInfo> const &list)
    {
        size_t length = 0;
        // checks through the whole list.
        for (CountryInfo i : list)
        { // checks if name of country is longer than previous
            if (i.name.length() > length)
            { // sets new max length.
                length = i.name.length();
            }
        }
        return length;
    }
    /******************************************************************
     * @brief sorts all elements in vector<CountryInfo> object.
     *
     * @param rv
     * refernce to CountryInfo object that has name and population of countries
     * to be sorted
     *
     * @param cmp
     * Function pointer to comparision function that determines the order of
     * the elements in the vector.
     *********************************************************************/
    void sort(std::vector<CountryInfo> &rv, Ptr_Cmp_Func cmp)
    { // goes through entire vector one element at a time.
        for (size_t i = 0; i < rv.size(); i++)
        { // goes through vector and compares pairs of elements.
            for (size_t j = 0; j < rv.size() - 1; j++)
            { // if both arguments are in the wrong order swap.
                if (cmp(rv[j], rv[j + 1]))
                {
                    // swaps the order of the arguments.
                    CountryInfo temp = rv[j];
                    rv[j] = rv[j + 1];
                    rv[j + 1] = temp;
                }
            }
        }
    }
    /******************************************************************
     * @brief
     * Prints the contents of vector object CountryInfo
     *
     * @param v
     * Reference to vector CountryInfo that is to be printed to output stream.
     *
     * @param os
     * Reference to output stream where info is to be printed
     *
     * @param fw
     * Field width to be used for formatting.
     *
     *********************************************************************/
    void write_to_ostream(std::vector<CountryInfo> const &v, std::ostream &os, size_t fw)
    { // goes through entire vector.
        for (CountryInfo i : v)
        {
            os << std::left << std::setw(fw) << i.name << i.pop << std::endl;
        }
    }
    /******************************************************************
     * @brief
     * Compares the lexicopgraphic order of 2 country's names
     *
     * @param left
     * reference to first country name
     *
     * @param right
     * reference to second country name
     *
     * @return
     * returns true if the first country is lexicographically less than the second.
     * else returns false.
     *********************************************************************/
    bool cmp_name_less(CountryInfo const &left, CountryInfo const &right)
    {
        if (std::string(left.name) > std::string(right.name))
        {
            return true;
        }
        else
            return false;
    }
    /******************************************************************
     * @brief
     * Compares the lexicopgraphic order of 2 country's names
     *
     * @param left
     * reference to first country name
     *
     * @param right
     * reference to second country name
     *
     * @return
     * returns true if the first country is lexicographically greater than the second.
     * else returns false.
     *********************************************************************/
    bool cmp_name_greater(CountryInfo const &left, CountryInfo const &right)
    {
        if (std::string(left.name) < std::string(right.name))
        {
            return true;
        }
        else
            return false;
    }
    /******************************************************************
     * @brief
     * Compares the population size between 2 countries
     *
     * @param left
     * reference to first country's population
     *
     * @param right
     * reference to second country's population
     *
     * @return
     * returns true if the population of the first country is less than that of
     * the second country.
     *********************************************************************/
    bool cmp_pop_less(CountryInfo const &left, CountryInfo const &right)
    {
        if (left.pop > right.pop)
        {
            return true;
        }
        else
            return false;
    }
    /******************************************************************
     * @brief
     * Compares the population size between 2 countries
     *
     * @param left
     * reference to first country's population
     *
     * @param right
     * reference to second country's population
     *
     * @return
     * returns true if the population of the first country is less than that of
     * the second country.
     *********************************************************************/
    bool cmp_pop_greater(CountryInfo const &left, CountryInfo const &right)
    {
        if (left.pop < right.pop)
        {
            return true;
        }
        else
            return false;
    }
}