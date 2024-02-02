#include "SrujanGavinRandom.h"

template <class T>
SrujanGavinRandom<T>* SrujanGavinRandom<T>::sInstance = nullptr;

template <class T>
SrujanGavinRandom<T>::SrujanGavinRandom()
{
    // Seed with current time
    auto currentTime = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    generator.seed(currentTime);
}

template <class T>
T SrujanGavinRandom<T>::SrujanGavinRandomRange(T min, T max)
{
    std::uniform_int_distribution<T> distribution(min, max);
    return distribution(generator);
}

template<class T>
SrujanGavinRandom<T>* SrujanGavinRandom<T>::GetInstance()
{
    if (!sInstance)
    {
        sInstance = new SrujanGavinRandom();
    }
    return sInstance;
}

//Explicit template instantiation
template class SrujanGavinRandom<int>;
template class SrujanGavinRandom<short>;
template class SrujanGavinRandom<long>;
template class SrujanGavinRandom<long long>;
