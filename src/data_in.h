#ifndef DATA_IN_H
#define DATA_IN_H


#include <iostream>
#include <memory>
#include "data.h"

class DataIn
{
    public:
    void Greeting();
    std::shared_ptr<Data> Input();
};

#endif

