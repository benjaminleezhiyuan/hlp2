/*!******************************************************************
 * \file      puncstream.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 11
 * \date      27-03-2023
 * 
 * \brief     Contains function declarations to count number of distinctive words
 *            occur in a text file.
 *********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

namespace hlp2
{
    class punc_stream
    {
        public:
        punc_stream(std::istream &is);                        // attach to input stream
        void whitespace(std::string const &s);                // make s the whitespace set
        void add_whitespace(char ch);                         // add to whitespace set
        bool is_whitespace(char ch) const;                    // is ch in whitespace set?
        void case_sensitive(bool b);                          // set stream's case-sensitivity
        bool is_case_sensitive() const;                       // return case sensitivity
        punc_stream &operator>>(std::vector<std::string> &s); // see below
        operator bool() const;
        private:
        std::istream& source; // source of characters
        std::string white; // characters considered whitespace
        bool sensitive;
        bool complete;
    };
    void print(std::map<std::string, size_t> histogram, std::string const& pre = "", std::string const& post = "\n");

}
