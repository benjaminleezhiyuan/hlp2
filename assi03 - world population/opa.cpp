#include <vector>
#include <iomanip>
#include <string>
#include "pa.hpp"
using namespace std;

namespace HLP2
{
    vector<CountryInfo> fill_vector_from_istream(istream &is)
    {
        string country;
        string population;
        string white = " \n\r\t\f\v";
        vector<CountryInfo> list;
        for (string line; getline(is, line);)
        {
            size_t countryIndex = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            size_t populationIndex = line.find_first_of("0123456789");

            country = line.substr(countryIndex, populationIndex - countryIndex);
            population = line.substr(populationIndex);

            country = (country.find_last_not_of(white) == string::npos) ? "" : country.substr(0, country.find_last_not_of(white) + 1);
            for (char c : population)
                if (c == ',')
                    population.erase(population.find(c), 1);
            list.push_back(CountryInfo{country, stol(population)});
        }
        return list;
    }

    size_t max_name_length(vector<CountryInfo> const &list)
    {
        size_t length = 0;
        for (CountryInfo i : list)
            if (i.name.length() > length)
                length = i.name.length();
        return length;
    }

    void sort(vector<CountryInfo> &rv, Ptr_Cmp_Func cmp)
    {
        for (size_t x = 0; x < rv.size(); x++)
            for (size_t i = 0; i < rv.size() - 1; i++)
                if (cmp(rv[i], rv[i + 1]))
                {
                    CountryInfo temp = rv[i];
                    rv[i] = rv[i + 1];
                    rv[i + 1] = temp;
                }
    }

    void write_to_ostream(vector<CountryInfo> const &v, ostream &os, size_t fw)
    {
        for (CountryInfo i : v)
        {
            os << left << setw(fw) << i.name << i.pop << endl;
        }
    }

    bool cmp_name_less(CountryInfo const &left, CountryInfo const &right)
    {
        if (string(left.name) > string(right.name))
            return true;
        else
            return false;
    }

    bool cmp_name_greater(CountryInfo const &left, CountryInfo const &right)
    {
        if (string(left.name) < string(right.name))
            return true;
        else
            return false;
    }
    bool cmp_pop_less(CountryInfo const &left, CountryInfo const &right)
    {
        if (left.pop > right.pop)
            return true;
        else
            return false;
    }

    bool cmp_pop_greater(CountryInfo const &left, CountryInfo const &right)
    {
        if (left.pop < right.pop)
            return true;
        else
            return false;
    }
}