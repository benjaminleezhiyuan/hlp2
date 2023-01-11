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
  header file q.hpp and standalone in q.cpp. These files combine to perform
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
  void q(char const *input, char const *output)
  {
    std::ifstream ifs(input, std::ios_base::in);
    std::ofstream ofs(output, std::ios_base::out);

    if (!ifs.is_open())
    {
      std::cout << "File " << input << " not found.\n";
    }
    if (!ofs.is_open())
    {
      std::cout << "Unable to create output file " << output << ".\n";
    }
    // Counting
    int characters = 0, letters = 0, whitespaces = 0, digits = 0, others = 0;
    float letters_total = 0, whitespaces_total = 0, digits_total = 0, others_total = 0;
    int upper = 0, lower = 0;
    float upper_total = 0, lower_total = 0;
    char ch;

    // Letter Array
    char fill = 'a';
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
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      {
        // Letter Stats
        for (int i = 0; i < 26; i++)
        {
          if (ch == letter_array[i])
          {
            indv_letter[i]++;
            lower++;
            letters++;
          }
        }
        for (int i = 0; i < 26; i++)
        {
          if (ch == letter_array[i] - 32)
          {
            indv_letter[i]++;
            upper++;
            letters++;
          }
        }
        for (int i = 0; i < 26; i++)
        {
          letter_percentage[i] = 100.0 * indv_letter[i] / letters;
        }
      }
      else if (ch == ' ' || ch == '\t' || ch == '\n')
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
    ifs.open(input, std::ios_base::in);
    constexpr size_t MAX_LINE_LEN{2048};
    char line[MAX_LINE_LEN];
    int integer_sum = 0;
    float integer_avg = 0;
    while (ifs.getline(line, MAX_LINE_LEN - 1))
    {
      integer_sum += extract_integers(line);
    }
    if (integer > 0)
    {
      integer_avg = 1.0 * integer_sum / integer;
    }

    ifs.close();

    // Calculations
    letters_total = percentage * letters / characters;
    whitespaces_total = percentage * whitespaces / characters;
    digits_total = percentage * digits / characters;
    others_total = percentage * others / characters;
    upper_total = percentage * upper / letters;
    lower_total = percentage * lower / letters;

    ofs << "Statistics for file: " << input << std::endl;
    for (int i = 0; i < 69; i++)
    {
      ofs << "-";
      if (i == 68)
        ofs << std::endl
            << std::endl;
    }
    ofs << "Total # of characters in file: " << characters << std::endl
        << std::endl;
    ofs << "Category" << std::setw(28) << "How many in file" << std::setw(22) << "% of file" << std::endl;

    for (int i = 0; i < 69; i++)
    {
      ofs << "-";
      if (i == 68)
        ofs << std::endl;
    }
    ofs << std::fixed << std::setprecision(2);
    ofs << "Letters" << std::setw(29) << letters << std::setw(20) << letters_total << " %" << std::endl;
    ofs << "White space" << std::setw(25) << whitespaces << std::setw(20) << whitespaces_total << " %" << std::endl;
    ofs << "Digits" << std::setw(30) << digits << std::setw(20) << digits_total << " %" << std::endl;
    ofs << "Other characters" << std::setw(20) << others << std::setw(20) << others_total << " %" << std::endl
        << std::endl
        << std::endl;

    ofs << "LETTER STATISTICS" << std::endl
        << std::endl;
    ofs << "Category" << std::setw(28) << "How many in file" << std::setw(22) << "% of all letters" << std::endl;

    for (int i = 0; i < 69; i++)
    {
      ofs << "-";
      if (i == 68)
        ofs << std::endl;
    }

    ofs << "Uppercase" << std::setw(27) << upper << std::setw(20) << upper_total << " %" << std::endl;
    ofs << "Lowercase" << std::setw(27) << lower << std::setw(20) << lower_total << " %" << std::endl;

    for (int i = 0; i < 26; i++)
    {
      ofs << letter_array[i] << std::setw(35) << indv_letter[i] << std::setw(20) << letter_percentage[i] << " %" << std::endl;
      if (i == 25)
        ofs << std::endl
            << std::endl;
    }
    ofs << std::left;
    ofs << "NUMBER ANALYSIS" << std::endl
        << std::endl;
    ofs << std::setw(37) << "Number of integers in file:" << integer << std::endl;
    ofs << std::setw(37) << "Sum of integers:" << integer_sum << std::endl;
    ofs << std::setw(37) << "Average of integers:" << integer_avg << std::endl;

    for (int i = 0; i < 69; i++)
    {
      ofs << "_";
      if (i == 68)
        ofs << std::endl;
    }

    ofs.close();
  }
}
