/*!*****************************************************************************
\file    q.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Assignment 01
\date    10-01-23

\brief
  This source file contains the definition of functions that are specified in
  header file q.hpp and standalone in wc.cpp. These files combine to perform
  the counting of total characters, lettres, white spaces, digits and other characters.

    -q
      Private to this source file and counts the number of words in
      a given line.

    -extract_integers
      Private to this source file and extracts integers from a given line.
*******************************************************************************/

// You must only include the following header files ...
#include <iostream>
#include <iomanip>
#include <fstream>

#define percentage 100.0
// Important notes:

// The auto grader will look for exactly the above three includes.
// If there any additional includes, it will not compile your file.
// The auto grade will not accept any functions not declared in
// these three header files [even in comments]!!!
// You're warned!!!
namespace
{
  const size_t MAX_LINE_LEN{2048};
}

namespace
{
  int extract_integers(std::string str)
  {
    int length = str.size();
    int extracted_value = 0;
    // This variable will store each founded
    // integer temporarily
    std::string temp = "";
    for (int i = 0; i < length; i++)
    {

      // If current character is an integer, then
      // accumulate add it in temp
      // str - '0' converts char to int;
      if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
      {
        temp += str[i];
      }

      // Otherwise, check if temp is empty or not
      // If it isn't then convert temp to integer
      // and empty it after printing
      else
      {
        if (temp.size() > 0)
        {
          extracted_value += std::stoi(temp);
          temp = "";
        }
      }
    }

    // if temp isn't empty then convert temp
    // to integer and sum it
    if (temp.size() > 0)
    {
      extracted_value += std::stoi(temp);
    }
    return extracted_value;
  }
}

namespace hlp2
{
  // provide definition of q here ...
  void q(char const *output, char const *input)
  {
    char const *inputfile = input;
    char const *outputfile = output;

    std::ifstream ifs(inputfile, std::ios_base::in);
    std::ofstream ofs(outputfile, std::ios_base::out);

    if (!ifs.is_open())
    {
      std::cout << input << "File " << inputfile << " not found.\n";
    }
    if (!ofs.is_open())
    {
      std::cout << output << "Unable to create output file " << outputfile << ".\n";
    }
    // Counting
    int characters = 0, letters = 0, whitespaces = 0, digits = 0, others = 0;
    float letters_total = 0, whitespaces_total = 0, digits_total = 0, others_total = 0;
    int upper = 0, lower = 0;
    float upper_total = 0, lower_total = 0;
    char ch;

    // Letter Array
    int fill = 'a';
    int indv_letter[26];
    float letter_percentage[26];
    char letter_array[26];
    for (int i = 0; i < 26; i++, fill++)
    {
      letter_percentage[i] = 0;
      indv_letter[i] = 0;
      letter_array[i] = fill;
    }

    // Integer Counter
    int integer = 0, is_integer = 0;

    // Go through text file character by character
    while (ifs.get(ch))
    {
      // counter for needed stats
      if (ch >= 'a' && ch <= 'z')
      {
        letters++;
        lower++;
      }
      else if (ch >= 'A' && ch <= 'Z')
      {
        letters++;
        upper++;
      }
      else if (ch == ' ' || ch == '\t')
      {
        whitespaces++;
      }
      else if (ch >= '0' && ch <= '9')
      {
        digits++;
      }
      else
      {
        others++;
      }
      characters++;

      // Letter Stats
      for (int i = 0; i < 26; i++)
      {
        if (ch == letter_array[i])
        {
          indv_letter[i]++;
        }
      }
      for (int i = 0; i < 26; i++)
      {
        letter_percentage[i] = 100.0 * indv_letter[i] / letters;
      }

      // Integer counter
      if (!(ch >= '0' && ch <= '9'))
      {
        is_integer = 0;
      }
      else if (is_integer == 0)
      {
        is_integer = 1;
        integer++;
      }
    }
    ifs.close();

    // Read inputfile line by line
    ifs.open(inputfile, std::ios_base::in);
    constexpr size_t MAX_LINE_LEN{2048};
    char line[MAX_LINE_LEN];
    int integer_sum = 0;
    float integer_avg = 0;
    while (ifs.getline(line, MAX_LINE_LEN - 1))
    {
      integer_sum += extract_integers(line);
    }
    integer_avg = 1.0 * integer_sum / integer;
    ifs.close();

    // Calculations
    letters_total = percentage * letters / characters;
    whitespaces_total = percentage * whitespaces / characters;
    digits_total = percentage * digits / characters;
    others_total = percentage * others / characters;
    upper_total = percentage * upper / letters;
    lower_total = percentage * lower / letters;

    ofs << "Statistics for file: " << inputfile << std::endl;
    for (int i = 0; i < 70; i++)
    {
      ofs << "-";
      if (i == 69)
        ofs << std::endl
            << std::endl;
    }
    ofs << "Total # of characters in file: " << characters << std::endl
        << std::endl;
    ofs << "Category" << std::setw(28) << "How many in file" << std::setw(23) << "% of file\n";

    for (int i = 0; i < 70; i++)
    {
      ofs << "-";
      if (i == 69)
        ofs << std::endl;
    }
    ofs << std::fixed << std::setprecision(2);
    ofs << "Letters" << std::setw(29) << letters << std::setw(20) << letters_total << " %\n";
    ofs << "White space" << std::setw(25) << whitespaces << std::setw(20) << whitespaces_total << " %\n";
    ofs << "Digits" << std::setw(30) << digits << std::setw(20) << digits_total << " %\n";
    ofs << "Other characters" << std::setw(20) << others << std::setw(20) << others_total << " %\n \n \n";

    ofs << "LETTER STATISTICS \n \n";
    ofs << "Category" << std::setw(28) << "How many in file" << std::setw(23) << "% of all letters\n";

    for (int i = 0; i < 70; i++)
    {
      ofs << "-";
      if (i == 69)
        ofs << std::endl;
    }

    ofs << "Uppercase" << std::setw(27) << upper << std::setw(20) << upper_total << " %\n";
    ofs << "Lowercase" << std::setw(27) << lower << std::setw(20) << lower_total << " %\n";

    for (int i = 0; i < 26; i++)
    {
      ofs << letter_array[i] << std::setw(35) << indv_letter[i] << std::setw(20) << letter_percentage[i] << " %\n";
      if (i == 25)
        ofs << "\n \n";
    }
    ofs << std::left;
    ofs << "NUMBER ANALYSIS\n \n";
    ofs << std::setw(37) << "Number of integers in file:" << integer << "\n";
    ofs << std::setw(37) << "Sum of integers:" << integer_sum << "\n";
    ofs << std::setw(37) << "Average of integers:" << integer_avg << "\n";

    for (int i = 0; i < 70; i++)
    {
      ofs << "_";
      if (i == 69)
        ofs << std::endl;
    }

    ofs.close();
  }
}
