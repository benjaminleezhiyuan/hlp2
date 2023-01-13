// This file can only have these 5 files included and therefore you should not
// remove the following include directives nor provide additional include directives!!!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "q.hpp" // compiler needs definition of type Tsunami

// anonymous namespace for any helper functions that you wish to implement
namespace {
  // ...
}

namespace hlp2 {
  // provide definitions of functions declared in q.hpp here ...

  Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt)
  {
    std::ifstream ifs(file_name,std::ios_base::in);
    if(!ifs.is_open())
    {
      return NULL;
    }

    //Count how many elements neede.
    max_cnt=0;
    std::string elementcount;
    while (getline(ifs,elementcount))
    {
      max_cnt++;
    }

    Tsunami *data = new Tsunami [max_cnt]; //Allocate array for tsunami data
    std::string line;//line to read data.
    while(getline(ifs,line))
    { std::string temp;
      for(int i=1;i<7;i++)
      {
        ifs >> temp;
        switch (i)
        {
          case 1:
          data->month = stoi(temp);
          break;
          case 2:
          data->day = stoi(temp);
          break;
          case 3:
          data->year = stoi(temp);
          break;
          case 4:
          data->fatalities = stoi(temp);
          break;
          case 5:
          data->maxwave = stod(temp);
          break;
        }
      }
          std::string extract;
          size_t pos_1 = line.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
          size_t pos_2 = line.find_last_of("abcdefghijklmnopqrstuvwxyz");
          extract = line.substr(pos_1, ((pos_2+1)));
          std::cout << extract << std::endl;
          data->geo = extract;
          break;
    }
    
    return data;

  }
  void print_tsunami_data(Tsunami const *arr,int size, std::string const& file_name)
  {
    std::ofstream ofs(file_name,std::ios_base::out);
    std::cout << size << arr <<  std::endl;
  }
}
