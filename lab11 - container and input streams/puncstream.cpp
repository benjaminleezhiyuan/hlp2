/*!******************************************************************
 * \file      puncstream.cpp
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
#include "puncstream.hpp"

namespace hlp2
{
    punc_stream::punc_stream(std::istream &is)
        : source{is}
    {
        sensitive = false;
        complete = false;
    }
    void punc_stream::whitespace(std::string const &s)
    {
        white = s;
    }
    void punc_stream::add_whitespace(char ch)
    {
        white += ch;
    }
    bool punc_stream::is_whitespace(char ch) const
    {
        size_t found = white.find(ch);

        if (found != std::string::npos)
        {
            return true;
        }
        return false;
    }
    void punc_stream::case_sensitive(bool b)
    {
        sensitive = b;
    }
    bool punc_stream::is_case_sensitive() const
    {
        return sensitive;
    }
    punc_stream &punc_stream::operator>>(std::vector<std::string> &s)
    {
        s.clear();
        std::string line;
        std::getline(source, line);
        for (size_t i = 0; i < line.size(); i++)
        {
            if (!sensitive && line[i] >= 'A' && line[i] <= 'Z')
            {
                line[i] += 32;
            }
            else if (is_whitespace(line[i]))
            {
                line[i] = ' ';
            }
        }

        std::istringstream iss{line};
        std::string word;

        while (iss >> word)
        {
            s.push_back(word);
        }

        return *this;
    }
    punc_stream::operator bool() const
    {
        if (source)
        {
            return true;
        }
        return false;
    }

    void print(std::map<std::string, size_t> histogram, std::string const &pre, std::string const &post)
    {
        std::cout << pre;
        for (std::pair<const std::string, size_t> const &p : histogram)
        {
            std::cout << "<" << p.first << ">: " << p.second << '\n';
        }
        std::cout << post;
    }
}
