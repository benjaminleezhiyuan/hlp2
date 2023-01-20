#include <iostream> // std::cout
#include <iomanip>  // std::setw, std::endl 
#include <string>   // std::string
#include <fstream>  // std::ifstream
#include <vector>   // std::vector<std::string>
#include <iterator> // std::istream_iterator<std::string>
#include "q.hpp"    // to_piglatin
// See the specs for more information on how to author q.cpp ...
// don't forget - all names introduced by you must be in namespace hlp2 ...
namespace hlp2
{
    std::string to_piglatin(std::string word)
    {
        std::string yay = "-yay";
        std::string ay = "-ay";
        std::string way = "-way";
        std::string temp;
        std::string firstcharacter;
        firstcharacter=word.at(0);

        if(word.find_first_of("aeiouAEIOU")==std::string::npos)
        {
        word.append(way);
        return word;
        }
        int i=0;
        if(firstcharacter.find_first_of("aeiouAEIOU")==std::string::npos)
        {   
            if(firstcharacter.find_first_of("yY")!=std::string::npos)
            {
            i = word.find_first_of("aeiouAEIOU");
            temp = word.substr(0,i);
            word.erase(0,i);
            word.append(temp);
            word.append(ay);
            return word;
            }
            else
            {
            i = word.find_first_of("aeiouAEIOUyY");
            temp = word.substr(0,i);
            word.erase(0,i);
            word.append(temp);
            word.append(ay);
            return word;               
            }
        }


        if(firstcharacter.find_first_of("aeiouAEIOU")!=std::string::npos)
        {
            word.append(yay);
            return word;
        }


        return word;
    }
}