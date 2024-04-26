#pragma once

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
    void operator=(const char* val);
};


typedef struct RayRect {
    RayUnit x, y, width, height;
} RayRect;