// File header documentation is required!!!

// This file must contain definitions of ALL member functions of class hlp2::punc_stream.

// Don't forget to add the definition of function hlp2::print that was declared in puncstream.hpp!!!
#include "xref.hpp"

namespace hlp2 {
	using VPII = std::vector<std::pair<int, int>>;

	// find all the line and word position pairs that refer
// to each word in the input file
// return a map and an int as a pair ...
	std::pair<std::map<std::string, std::vector<std::pair<int, int>>>, int> xref(std::string const& filename, std::string const& whitespace, bool case_sensitivity, std::set<std::string> const& exclude) {

		// define a map from string to vector<pair<int,int>>
		std::pair<std::map<std::string, std::vector<std::pair<int, int>>>, int> ret;

		// Open file stream
		std::ifstream ifs{ filename };

		hlp2::punc_stream ps{ ifs };
		ps.whitespace(whitespace);
		ps.case_sensitive(case_sensitivity);

		std::map<std::string, VPII> sm; // xref table

		int lineNum = 1;
		int wordPos = 1;
		bool excluded = false;

		// purge whitespace from line and split into words ...
		for (std::vector<std::string> line_words; ps >> line_words; ) {
			// write the words and associated counts
			for (std::string const& word : line_words) {

				for (std::string const& exclude_word : exclude) {
					if (word == exclude_word) {
						excluded = true;
						break;
					}
				}
				if (excluded) { excluded = false; continue; }

				sm[word].push_back(std::make_pair(lineNum, wordPos));
				++wordPos;
			}
			++lineNum;
			wordPos = 1;
		}

		ifs.close();

		ret.first = sm;
		ret.second = lineNum;
		std::pair<std::map<std::string, std::vector<std::pair<int, int>>>, int> result;
		result.first = sm;
		result.second = lineNum;
		return result;

	} // end function xref

	void print_wordmap(std::map<std::string, std::vector<std::pair<int, int>>> const& words) {
		std::map<std::string, std::vector<std::pair<int, int>>>::iterator it;

		for (auto const& word : words)
		{
			std::cout << "\"word.first\"" << " occurs " << word.second.size() << "and is located at:" << '\n';
			for (auto const& loc : word.second) {
				std::cout << "  line" << loc.first << ", position " << loc.second << '\n';
			}
		}

	}

} // end namespace
