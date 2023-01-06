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

  int countwords(char str[])
  {
    int i = 0;
    int is_word = 0, wordcount = 0;
    while (str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
      {
        is_word = 0;
      }
      else if (is_word == 0)
      {
        is_word = 1;
        wordcount++;
      }
      i++;
    }
    return wordcount;
  }
  // Declare/define your helper functions here ...
  int countbytes(std::string str)
  {
    int size = str.size();
    return size;
  }
}

// Now, define function wc in namespace hlp2 ...
namespace hlp2
{
  void wc(int argc, char *argv[])
  {
    int lines = 0, words = 0, bytes = 0;                   // initialize counters
    int total_lines = 0, total_words = 0, total_bytes = 0; // initialize total counters
    for (int i = 1; i < argc; i++)                         // loop to check all text files
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
        words += countwords(line);
        bytes += countbytes(line);
        lines++;
      }
      total_lines += lines, total_words += words, total_bytes += bytes;
      std::cout << std::setw(7);
      std::cout << lines << ' ' << std::setw(7) << words << ' ' << std::setw(7) << bytes << ' ' << std::setw(7) << filename << '\n';
      lines = 0, words = 0, bytes = 0;
    }
    // define function wc here ...
    if (argc > 2)
      std::cout << std::setw(7) << total_lines << ' ' << std::setw(7) << total_words << ' ' << std::setw(7) << total_bytes << " Total\n";
  }

} // end namespace hlp2
