#include "Random.h"

// Ά¬ν
std::mt19937 Random::mt_;
// ΜV[h
unsigned int Random::seed_{ std::mt19937::default_seed };

// Ά¬νΜϊ»
void Random::randomize() {
    std::random_device rd;
    randomize(rd());
}

// Ά¬νΜϊ»
void Random::randomize(unsigned int seed) {
    seed_ = seed;
    mt_ = std::mt19937(seed_);
}

// int^Μπίι
int Random::rand(int l, int h) {
    std::uniform_int_distribution<int> dist(l, h);
    return dist(mt_);
}

// float^Μπίι
float Random::rand(float l, float h) {
    std::uniform_real_distribution<float> dist(l, h);
    return dist(mt_);
}

// ΜV[hπζΎ
unsigned int Random::seed() {
    return seed_;
}

// end of file
