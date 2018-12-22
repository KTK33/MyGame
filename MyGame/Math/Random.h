#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>

// NX
class Random {
public:
    // Ά¬νΜϊ»
    static void randomize();
    // Ά¬νΜϊ»
    static void randomize(unsigned int seed);
    // int^Μπίι
    static int rand(int l, int h);
    // float^Μπίι
    static float rand(float l, float h);
    // ΜV[hπζΎ
    static unsigned int seed();
private:
    // Ά¬ν
    static std::mt19937 mt_;
    // ΜV[h
    static unsigned int seed_;
};

#endif

// end of file
