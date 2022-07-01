// Figuring out data in
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>


#include "data_in.h"
#include "data.h"

void DataIn::Greeting()
{
    std::cout << "I can take a two column csv file as an input" << std::endl;
}

std::shared_ptr<Data> DataIn::Input()
{
    std::string filepath;
    std::ifstream my_file;

    std::vector<double> column_x;
    std::vector<double> column_y;

    auto data_ptr = std::shared_ptr<Data>{new Data()}; 

    std::cout << "Please Provide the path to the file you would like to analyze" << std::endl;
    std::getline(std::cin, filepath);
    std::stringstream(filepath) >> filepath;

    std::cout << "You entered " << filepath << "\n";

    my_file.open(filepath);

    if (my_file)
    {
        std::cout << "The file stream has been created!"
                  << "\n";
        std::string line;
        while (getline(my_file, line))
        {
            std::istringstream sline(line);
            double a;
            char b;
            double c;
            while (sline >> a >> b >> c)
            {
                column_x.push_back(a);
                column_y.push_back(c);
            }
        }
    }
    else
        throw std::invalid_argument("Please check for a valid file name");


    data_ptr->setXData(column_x);
    data_ptr->setYData(column_y);
    
    return data_ptr;
}