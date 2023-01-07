/*!*****************************************************************************
\file    wc.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee@digipen.edu
\par     Course: CSD1171
\par     Section: A
\date    07-01-23

\brief
  This source file contains the definition of functions that are specified in 
  header file wc.hpp and standalone in wc.cpp. These files combine to perform 
  the counting of lines, words and bytes within text files. The funcions include:

    -countwords
      Private to this source file and counts the number of words in
      a given line
    
    -countbytes
      Private to this source file and counts the number of bytes in a given 
      line.

    -wc
      Takes a number of txt files and returns the amount of lines, words and bytes
      for each txt file and also the total of all files combined.
    
*******************************************************************************/

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
        std::cout << "wc: " << filename << ": No such file" << std::endl;
        return;
      }
      constexpr size_t MAX_LINE_LEN{2048};
      char line[MAX_LINE_LEN];
      while (ifs.getline(line, MAX_LINE_LEN - 1))
      {
        if (!ifs.eof())
          lines++;
        words += countwords(line);
        bytes += countbytes(line);
      }
      ifs.close();
      bytes += lines; // add back all the '\n'
      std::cout << std::setw(7) << lines << ' ' << std::setw(7) << words << ' ' << std::setw(7) << bytes << ' ' << std::setw(7) << filename << '\n';
      total_lines += lines, total_words += words, total_bytes += bytes;
      lines = 0, words = 0, bytes = 0;
    }
    // define function wc here ...
    if (argc > 2)
      std::cout << std::setw(7) << total_lines << ' ' << std::setw(7) << total_words << ' ' << std::setw(7) << total_bytes << " total\n";
  }

} // end namespace hlp2
