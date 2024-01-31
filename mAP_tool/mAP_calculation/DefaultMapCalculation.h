#pragma once
#include "MapCalculation.h"
#include <iostream>
class DefaultMapCalculation : public MapCalculation {
public:
    void calculateMap(const std::vector<std::string>& data) override;
};

