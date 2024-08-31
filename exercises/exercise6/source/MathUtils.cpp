#include "MathUtils.h"
#include <math.h>

double MathUtils::CalPentagonArea(double side)
{
    return ((pow(side, 2) / 4) * sqrt(25 + 10 * sqrt(5)));
}

double MathUtils::CalHexagonArea(double side)
{
    return (pow(side, 2) * ((3 * sqrt(3)) / 2));
}
