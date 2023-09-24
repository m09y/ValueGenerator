#ifndef VALUE_GENERATOR_H
#define VALUE_GENERATOR_H

#include <limits>

enum class RANDOMIZER_TYPE
{
    POWEROF02,
    POWEROF03,
    POWEROF04,
    POWEROF05,
    POWEROF08,
    POWEROF10,
    POWEROF16,
    POWEROF32,
    POWEROF64,
    EVENVALUES,
    ODDVALUES,
    PRIMEVALUES,
    RANDOMVALUES
};

template <typename T>
class ValueGenerator
{
    T curValue;
    T maxLimit;
    T minLimit;
    T maxAllowedLimit;
    int maxRangeIndex;
    int minRangeIndex;
    int curIndex;
    RANDOMIZER_TYPE valRandomizerType = RANDOMIZER_TYPE::POWEROF02;
public:
    ValueGenerator();
    T CurVal();
    T NextVal();
    T MaxVal();
    void SetRandomizerTechnique(RANDOMIZER_TYPE);
    void Reset();
    T GeneratePowerOfN(const unsigned int);
};

template<typename T>
ValueGenerator<T>::ValueGenerator()
{
    Reset();
}

template<typename T>
void ValueGenerator<T>::SetRandomizerTechnique(RANDOMIZER_TYPE type)
{
    valRandomizerType = type;
    return;
}

template<typename T>
void ValueGenerator<T>::Reset()
{
    minLimit = std::numeric_limits<T>::min();
    maxLimit = std::numeric_limits<T>::max();
    maxAllowedLimit = maxLimit - 1;
    maxRangeIndex = std::numeric_limits<T>::digits;
    minRangeIndex = (true == std::is_signed<T>::value) ? (-1 * maxRangeIndex) : 0;
    curIndex = minRangeIndex;
    curValue = minLimit; 
    return;
}

template<typename T>
T ValueGenerator<T>::CurVal()
{
    return curValue;
}

template<typename T>
T ValueGenerator<T>::NextVal()
{
    if(true == std::is_integral<T>::value)
    {
        T nextVal = 0;
        switch(valRandomizerType)
        {
            case RANDOMIZER_TYPE::POWEROF02: nextVal = GeneratePowerOfN(2);break;
            case RANDOMIZER_TYPE::POWEROF03: nextVal = GeneratePowerOfN(3);break;
            case RANDOMIZER_TYPE::POWEROF04: nextVal = GeneratePowerOfN(4);break;
            case RANDOMIZER_TYPE::POWEROF05: nextVal = GeneratePowerOfN(5);break;
            case RANDOMIZER_TYPE::POWEROF08: nextVal = GeneratePowerOfN(8);break;
            case RANDOMIZER_TYPE::POWEROF10: nextVal = GeneratePowerOfN(10);break;
            case RANDOMIZER_TYPE::POWEROF16: nextVal = GeneratePowerOfN(16);break;
            case RANDOMIZER_TYPE::POWEROF32: nextVal = GeneratePowerOfN(32);break;
            case RANDOMIZER_TYPE::POWEROF64: nextVal = GeneratePowerOfN(64);break;
        }
        return nextVal;
    }
    else
    {
        //Boolean type
        T nextVal = true;
        return nextVal;
    }
}

template<typename T>
T ValueGenerator<T>::MaxVal()
{
    return maxLimit;
}

template<typename T>
T ValueGenerator<T>::GeneratePowerOfN(const unsigned int N)
{
    //Signed Value
    if ((true == std::is_signed<T>::value) && (curValue < 0))
    {
        curValue = curValue / N;
        ++curIndex;
    }
    else if (curValue == 0)
    {
        curValue = 1;
        curIndex = 1;
    }
    else if (curValue > 0)
    {
        if (curValue == maxAllowedLimit)
        {
            curValue = maxLimit;
        }
        else if (curValue >= (maxLimit/N))
        {
            curValue = maxAllowedLimit;
        }
        else
        {
            curValue = curValue * N;
        }
    }
    return curValue;
}
#endif
