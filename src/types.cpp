#include "types.h"
#include "Background/Exception.h"
#include <string>
#include <iostream>

RayUnit::RayUnit(const char* val) {
    std::string strValue(val);
    int index = 0;
    for (index = 0; ((strValue[index] <= '9') && (strValue[index] >= '0')) || (strValue[index] == '.'); index++);
    this->value_ = std::stod(strValue.substr(0, index));
    this->type_ = recognise(strValue.substr(index).c_str());
}

void RayUnit::operator=(const char* val) {
    std::string strValue(val);
    int index = 0;
    for (index = 0; ((strValue[index] <= '9') && (strValue[index] >= '0')) || (strValue[index] == '.'); index++);
    this->value_ = std::stod(strValue.substr(0, index));
    this->type_ = recognise(strValue.substr(index).c_str());
}

UnitType RayUnit::recognise(const char* type) {
    std::string strType(type);
    if (strType.size() == 0) return UnitType::PIXEL;
    if (!strType.compare("%")) return UnitType::PERCENT;
    if (!strType.compare("px")) return UnitType::PIXEL;
    throw NotAUnitTypeException(
        "Unsupported units: ", strType
    );
}

