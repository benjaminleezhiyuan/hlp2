/*!******************************************************************
 * \file      xref.cpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 12
 * \date      04-04-2023
 * 
 * \brief     This file contains the definitions of functions to obtain and print out the number of 
occurrances of all the words in a std::map along with their locations
 *********************************************************************/

#include "xref.hpp"
#include "puncstream.hpp"

namespace hlp2 {

    using VPII = std::vector<std::pair<int,int>>;

    /***************************************************************************/
    /*!
    \brief
        Function xref take a string indicating a filename and the characters to be ignored
        along with a boolean to determine case sensitivity and specific strings to be excluded.
        The function returns a pair contains the number of occurrances of all the words along
        with their locations.
    \param[in] filename
        The string containing the name of the file to be read

    \param[in] whitespace
        The string of characters to be ignored

    \param[in] case_sensitivity
        Boolean determining if uppercase and lowercase letters are seen as unique

    \param[in] exclude
        The words to be ignored

    \return
        The a std::pair consisting of a std::map<std::string,VPII> and an int
    */
    /**************************************************************************/

    std::pair<std::map<std::string, VPII>,int>xref(std::string const& filename,
                                                   std::string const& whitespace,
                                                   bool case_sensitivity,
                                                   std::set<std::string> const& exclude) 
    {
        //========================
        //Variable Declarations
        int linecount = 1;
        int wordcount = 0;
        std::map<std::string, VPII> ret;
        //========================
        //Preparing for >>
        std::ifstream in(filename);
        if(!in.is_open()){
            std::cerr<< "Failed to open file\n";
        }
        hlp2::punc_stream temp{in};
        temp.whitespace(whitespace);
        temp.case_sensitive(case_sensitivity);
        //========================
        //For loop to remove all the whitespaces
        //Iterates line by line
        for (std::vector<std::string> words; temp >> words;)
        {
            wordcount = 0;
            for (std::string const &word : words){
                if(!exclude.count(word)){
                    wordcount++;
                    ret[word].push_back(std::make_pair(linecount, wordcount));
                }
            }
            linecount++;
        }
            linecount--;
            in.close();
            return std::make_pair(ret, linecount);
    }

    /***************************************************************************/
    /*!
    \brief
        Outputs a std::map containing the number of occurrances of all the words along
        with their locations in a specified format.
    \param[in] words
        the std::map to be output

    \return
        NIL
    */
    /**************************************************************************/

    void print_wordmap(std::map<std::string, VPII> const& words) {
        for (std::pair<std::string, VPII> temp : words) {
            std::cout << "\"" << temp.first << "\" occurs " << temp.second.size();
            if (temp.second.size() > 1){
                std::cout << " times";
            }
            else{
                std::cout <<" time";
            }
            std::cout << " and is located at: " << std::endl;
            //For more than one occurrance
            for(size_t i = 0; i < temp.second.size(); i++){
                std::cout << "\tline: " << temp.second[i].first;
                std::cout << ", position: " << temp.second[i].second << std::endl;
            }
        }

    }


}