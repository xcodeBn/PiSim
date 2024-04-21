#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>
#include <string>
#include <vector>
#include <chrono>
#include <limits>

namespace piutil{
class RandomGenerator {
private:
    std::default_random_engine engine;

public:
    RandomGenerator() {
        // Seed the random number generator with the current time
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        engine.seed(static_cast<unsigned>(seed));
    }

    int generateRandomInt(int min = 0, int max = 100) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(engine);
    }

    double generateRandomDouble(double min = 0.0, double max = 1.0) {
        std::uniform_real_distribution<double> dist(min, max);
        return dist(engine);
    }

    std::string generateRandomString(size_t length = 10) {
        std::string str(length, '\0');
        std::uniform_int_distribution<char> dist('a', 'z');
        for (char &c : str) {
            c = dist(engine);
        }
        return str;
    }

    std::vector<char> generateRandomCharArray(size_t length = 10) {
        std::vector<char> arr(length);
        std::uniform_int_distribution<char> dist('a', 'z');
        for (char &c : arr) {
            c = dist(engine);
        }
        return arr;
    }
};

#endif // RANDOM_GENERATOR_H
}
