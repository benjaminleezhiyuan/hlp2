// See specs for complete description of what you need to implement in this file.

// Don't forget documentation: a file header is required; every function and type that you
// define must have appropriate documentation
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <set>
#include "puncstream.hpp"

namespace hlp2 {
	std::pair<std::map<std::string, std::vector<std::pair<int, int>>>, int> xref(std::string const& filename, std::string const& whitespace, bool case_sensitivity, std::set<std::string> const& exclude);

	void print_wordmap(std::map<std::string, std::vector<std::pair<int, int>>> const& words);
}