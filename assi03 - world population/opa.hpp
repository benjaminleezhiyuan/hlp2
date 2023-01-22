#ifndef PA_HPP
#define PA_HPP

#include <vector>
#include <iostream>
using namespace std;

namespace HLP2 {
    struct CountryInfo {
        string name;
        long int pop;
    };
    
    using Ptr_Cmp_Func = bool (*)(CountryInfo const&, CountryInfo const&);

    vector<CountryInfo> fill_vector_from_istream(istream& is);
    size_t max_name_length(vector<CountryInfo> const& list);
    void sort(vector<CountryInfo>& rv, Ptr_Cmp_Func cmp);
    void write_to_ostream(vector<CountryInfo> const& v, ostream& os, size_t fw);
    bool cmp_name_less(CountryInfo const& left, CountryInfo const& right);
    bool cmp_name_greater(CountryInfo const& left, CountryInfo const& right);
    bool cmp_pop_less(CountryInfo const& left, CountryInfo const& right);
    bool cmp_pop_greater(CountryInfo const& left, CountryInfo const& right);
}
#endif