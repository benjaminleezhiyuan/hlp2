// Don't forget to include file-header and function-level Doxygen documentation blocks!!!
// A handout on documenting code using Doxygen is available on the course web page.

// Your definition of function wc can only rely on the following C++ Standard Library headers:

#include <iostream>
#include <iomanip>
#include <fstream>

// The use of functions declared in C Standard Library will be a violation of the Academic Integrity Policy ...
// If you are unsure about whether a function is declared in the Standard C library, use this reference: https://en.cppreference.com/w/c/header

// A text file consists of zero or more linesm, each line terminated by a line feed '\n' character.
// Watch out - don't use Windows OS programs [such as notepad.exe] to open and edit your text files.
// This is because Windows text files terminate each line by a carriage return '\r' character followed by a line feed '\n'.

// We don't want to deal with dynamic memory allocation/deallocation. Instead, we'll assume the longest length
// of a line [in any of the files that we'll process] is 2048 characters [including the null terminating character].

// This is an anonymous namespace - i.e., a namespace with no name.
// Anonymous namespaces are used by C++ programmers to make names declared at global scope private to this source file:
namespace
{
  const size_t MAX_LINE_LEN{2048};
}

// In C++ [unlike in C], variable MAX_LINE_LEN is considered a constant expression [i.e. like a literal].
// Therefore, you can define a static char array with dimension MAX_LINE_LEN that can be used to store the
// characters of each line of text that you'll read in each of the source files that you'll process ...

// Helper functions must also be private to this source file and must therefore be declared/defined in
// an anonymous namespace ...
namespace
{
  // Declare/define your helper functions here ...

}

// Now, define function wc in namespace hlp2 ...
namespace hlp2
{
  void wc(int argc, char *argv[])
  {
    int lines = 0, words = 0, bytes = 0; // initialize counters
    int total_lines = 0, total_words = 0, total_bytes = 0;
    for (int i = 1; i < argc; i++) // loop to check all text files
    {
      char const *filename = argv[i]; // set which file to read from first
      std::ifstream ifs(filename, std::ios_base::in);
      if (!ifs.is_open())
      {
        std::cout << "File" << filename << "not found" << std::endl;
      }
      constexpr size_t MAX_LINE_LEN{2048};
      char line[MAX_LINE_LEN];
      while (ifs.getline(line, MAX_LINE_LEN - 1))
      {
        lines++;
      }
      std::cout << lines << ' ' << words << ' ' << bytes << ' ' << filename << '\n';
      lines = 0, words = 0, bytes = 0;
    }
    // define function wc here ...
    std::cout << total_lines << ' ' << total_words << ' ' << total_bytes << " Total\n";
  }
} // end namespace hlp2
