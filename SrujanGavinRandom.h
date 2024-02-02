#pragma once
#include <random>
#include <chrono>

template <class T>
class SrujanGavinRandom
{
public:
    static SrujanGavinRandom<T>* GetInstance();
    T SrujanGavinRandomRange(T min, T max);

private:
    SrujanGavinRandom();
    static SrujanGavinRandom<T>* sInstance;
    std::mt19937 generator;
};
