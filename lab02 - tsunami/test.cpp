// see specs
//#ifndef Q_HPP
//#define Q_HPP
#include <string> // to use C++ standard library std::string type
#include <fstream> // to use C++ file I/O interface
#include <iomanip>
// other C++ [not C] standard library headers
#include "q.hpp"
#include <iostream>


namespace hlp2 {

  

    Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt){
        
        int line_count = 0;
        std::ifstream testfile(file_name, std::ios_base::in);
        
        std::string testline;
        while(std::getline(testfile, testline)){
            //std::cout<<"line is: "<<testline<<std::endl;
            line_count++;
        }
        //std::cout<<"line count is "<<line_count<<std::endl;
        
        //std::cout<<"--------------------------------------------------"<<std::endl;
        testfile.close();
        std::ifstream input(file_name, std::ios_base::in);
        //std::ofstream outputtest("testFile.txt", std::ios_base::out);
        std::string line;
        Tsunami arr1[100];
        int index = 0;
        //int zx = 1;
        //for every line
        while(std::getline(input, line)){
            //std::cout<<"line is: "<<line<<std::endl;
            std::stringstream ss(line);
            //int cnt = 0;
            std::string remains;
            Tsunami* ptr = &arr1[index++];
            ss >> ptr->month >> ptr->day >> ptr->year >> ptr->fatalities >> ptr->maxwave;
            //for the remaining string in the line
            std::getline(ss, remains);
            //std::cout<<"remains is "<<remains<<std::endl;
            std::string extract;
            size_t pos_1 = remains.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
            size_t pos_2 = remains.find_last_of("abcdefghijklmnopqrstuvwxyz");
           /* if(zx){
                pos_2-=1;
                zx = 0;
            }*/
            //std::cout<<"1:"<<remains[pos_1]<<" 2:"<< remains[pos_2]<<std::endl;
            extract = remains.substr(pos_1, ((pos_2+1)-pos_1));
            //outputtest<<extract<<std::endl;
            ptr->geo = extract;
            //outputtest<<extract<<std::endl;

            //need to account for whitespace
        };
        
        //input>>sample.month>>sample.day>>sample.year>>sample.max_wh>>sample.fatals;
       
        Tsunami* returnPtr = new Tsunami [line_count];

        int someCnt = 0;
        for(int i = 0;i<line_count;i++){
            *(returnPtr+someCnt) = arr1[someCnt];
            someCnt++;
            //change loop type
        }
        max_cnt = line_count;
        input.close();
        return returnPtr;
        //std::array<Tsunami, sizeof(arr1)/sizeof(arr1[0])> returnPtr = arr1;
       
    }


    void print_tsunami_data(Tsunami const *arr,int size, std::string const& file_name){
        std::ofstream output(file_name, std::ios_base::out);
        output<<"List of tsunamis:"<<std::endl;
        output<<"-----------------"<<std::endl;
        double true_max = 0;
        double total_wh = 0.0;
        double avg_wh = 0.0;

        for(int i = 0; i<size; i++){
            output  << std::setfill('0')<<std::setw(2)<<arr[i].month;
            output  << " "<<std::setfill('0') <<std::setw(2)<<arr[i].day;
            output  << " " <<arr[i].year << std::setfill(' ');
            output  << std::setw(7)<< arr[i].fatalities;//<<"      ";
            output  << std::setw(11)<< std::setprecision(2)<<std::fixed<< arr[i].maxwave<< "     ";
            output  <<arr[i].geo <<std::endl;
            if(true_max<arr[i].maxwave){
                true_max = arr[i].maxwave;
            }
            total_wh+=arr[i].maxwave;
        }
        output<<"\n";
        avg_wh = total_wh/((double)size);
        output<<"Summary information for tsunamis"<<std::endl;
        output<<"--------------------------------"<<std::endl;
        output<<"\n";
        output<<"Maximum wave height (in meters): "<<std::setw(5)<<true_max<<std::endl;
        output<<"\n";
        output<<"Average wave height (in meters): "<<std::setw(5)<<avg_wh<<std::endl;
        output<<"\n";
        output<<"Tsunamis with greater than average height "<<avg_wh<<":"<<std::endl;
        for(int i = 0; i<size; i++){
            if(arr[i].maxwave>avg_wh){
                output<<arr[i].maxwave<<"     "<<arr[i].geo<<std::endl;
            }
        }


    } 
}// end namespace hlp2