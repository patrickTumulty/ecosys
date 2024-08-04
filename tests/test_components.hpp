
#ifndef TEST_COMPONENTS_HPP
#define TEST_COMPONENTS_HPP

#include "ecosys/component.hpp"

struct ComponentA : public ecosys::Component
{
    int a;
    int b;
    int c;
};

struct ComponentB : public ecosys::Component
{
    int d;
    int e;
    int f;
};

struct ComponentC : public ecosys::Component
{
    int g;
    int h;
    int i;
};

#endif
