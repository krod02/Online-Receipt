//
//  fileOperationsRP.cpp
//  Receipt Project
//
//  Created by Kevin Rodriguez on 3/5/22.
//
#include "fileOperationsRP.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>


using std::cout;
using std::cin;
using std::string;

//appends receipt info to ejournal
void append_lines(std::vector<string> &lines){
    
    
    std::ofstream ofs {"/Users/krod/OneDrive - Florida Gulf Coast University/eJournal.csv", std::ios::app};

    for(const auto & l : lines){
        //ofs << std::setprecision(2);
        ofs <<  l << "\n";
    }
}
