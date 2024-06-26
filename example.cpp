#include <iostream>
#include "property.h"

template<typename T>
T Clamp(T value, T min, T max)
{
    value = value < min ? min : value;
    value = value > max ? max : value;
    return value;
}

struct WithoutProperty
{
    int x;
    int y;
};

struct WithProperty
{
private:
    static void SetX(int &value, int newValue)
    {
        value = Clamp(newValue, -10, 10);
    }
    
    static void SetY(int &value, int newValue)
    {
        value = Clamp(newValue, -10, 10);
    }
public:
    Property<int, SetX> x;
    Property<int, SetY> y;
};

int main()
{
    WithoutProperty p1;
    p1.x = 10000;
    p1.y = -10000;
    printf("WithoutProperty : {x = %d, y = %d}\n", (int)p1.x, (int)p1.y);
    
    WithProperty p2;
    p2.x = 10000;
    p2.y = -10000;
    printf("WithProperty : {x = %d, y = %d}\n", (int)p2.x, (int)p2.y);

    return 0;
}
