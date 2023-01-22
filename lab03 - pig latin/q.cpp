#include <string> // std::string
#include "q.hpp"  // to_piglatin
// See the specs for more information on how to author q.cpp ...
// don't forget - all names introduced by you must be in namespace hlp2 ...
namespace
{
    std::string vowels{"aeiouAEIOU"};    // all vowels
    std::string vowelsy{"aeiouAEIOUyY"}; // all vowels and y

    bool vowelcheck(char c)
    {
        c = std::tolower(c);
        if (vowels.find(c) != std::string::npos)
        {
            return true;
        }
        return false;
    }

    bool vowelchecky(char c)
    {
        c = std::tolower(c);
        if (vowelsy.find(c) != std::string::npos)
        {
            return true;
        }
        return false;
    }
}

namespace hlp2
{
    std::string to_piglatin(std::string word)
    {
        std::string yay = "-yay";
        std::string ay = "-ay";
        std::string way = "-way";

        if (vowelcheck(word[0]))
        {
            return word.append(yay);
        }

        if (word.find_first_of(vowelsy) == std::string::npos)
        {
            return word.append(way);
        }

        bool cap{false};
        if (std::isupper(word[0]))
        {
            cap = true;
            word[0] = std::tolower(word[0]);
        }
        do
        {
            word += word[0];
            word.erase(0, 1);
        } while (!vowelchecky(word[0]));

        if (cap)
        {
            word[0] = std::toupper(word[0]);
        }
        return word.append(ay);
    }
}