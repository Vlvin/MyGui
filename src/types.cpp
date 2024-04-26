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


RayUnit::RayUnit(float val) {
    this->value_ = val;
    this->type_ = UnitType::PIXEL;
}

void RayUnit::operator=(const char* val) {
    std::string strValue(val);
    int index = 0;
    for (index = 0; ((strValue[index] <= '9') && (strValue[index] >= '0')) || (strValue[index] == '.'); index++);
    this->value_ = std::stod(strValue.substr(0, index));
    this->type_ = recognise(strValue.substr(index).c_str());
}

void RayUnit::operator=(float val) {
    this->value_ = val;
}

UnitType RayUnit::type() {
    return this->type_;
}

UnitType RayUnit::recognise(const char* type) {
    std::string strType(type);
    if (!strType.compare("%")) return UnitType::PERCENT;
    if (!strType.compare("px")) return UnitType::PIXEL;
    if (strType.size() == 0) {
        return UnitType::PIXEL;
    }
    throw NotAUnitTypeException(
        "Unsupported units: ", strType
    );
}

float RayRect::operator[](const char* index) {
    std::string strIndex(index);
    if (!strIndex.compare("x")) return this->x.value_;
    if (!strIndex.compare("y")) return this->y.value_;
    if (!strIndex.compare("width")) return this->width.value_;
    if (!strIndex.compare("height")) return this->height.value_;
    throw NoSuchElementException(
        "RayRect have no element ", strIndex
    );
}