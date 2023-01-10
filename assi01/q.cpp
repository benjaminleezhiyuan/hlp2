// You must only include the following header files ...
#include <iostream>
#include <iomanip>
#include <fstream>

// Important notes:

// The auto grader will look for exactly the above three includes.
// If there any additional includes, it will not compile your file.
// The auto grade will not accept any functions not declared in
// these three header files [even in comments]!!!
// You're warned!!!
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
      std::cout << input << ": No such file\n";
    }
    if (!ofs.is_open())
    {
      std::cout << output << ": Failed to create file\n";
    }

    int characters = 0, letters = 0, whitespaces = 0, digits = 0, others = 0;
    char ch;

    while (ifs.get(ch))
    {
      if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
      {
        letters++;
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
    }
    std::cout << characters << std::setw(7) << letters << std::setw(7) << whitespaces << std::setw(7) << digits << std::setw(7) << others << std::endl;
  }
}
