#include <cstdlib>
#include <ctime>
#include <iostream>

//-----------------------------------------------------------------
//-----------------------------------------------------------------

int RandomInt(int nMax)
{
    return rand() % (nMax + 1);
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

//
// ORIGINAL CODE BY SRUJAN AND GAVIN
//

float RandomFloat(float fMin, float fMax)
{
    const float fValue = fMin + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (fMax - fMin)));
    std::cout << fValue << std::endl;
    return fValue;
}