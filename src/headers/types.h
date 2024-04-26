#pragma once
#include <raylib.h>

typedef enum UnitType {
    PIXEL,
    PERCENT
} UnitType;

class RayUnit {
protected:
    float value_;
    UnitType type_;
    static UnitType recognise(const char* type);
public:
    RayUnit(const char* val);
    RayUnit(float val);
    void operator=(const char* val);
    void operator=(float val);
    UnitType type();
    friend class RayRect;
};


typedef struct RayRect {
    RayUnit x, y, width, height;
    float operator[](const char* index);
} RayRect;