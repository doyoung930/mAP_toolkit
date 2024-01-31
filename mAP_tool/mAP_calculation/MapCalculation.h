#pragma once
#include "header.h"

class MapCalculation
{
public:
    virtual void calculateMap(const vector<string>& data) = 0;
    virtual ~MapCalculation() {}
};