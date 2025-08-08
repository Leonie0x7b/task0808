#pragma once
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} vector3f;

vector3f vadd(vector3f v1,vector3f v2);
vector3f vsub(vector3f v1,vector3f v2);
float vdot(vector3f v1,vector3f v2);
float vlength(vector3f v);
vector3f vnorm(vector3f v);
vector3f vcross(vector3f v1,vector3f v2);