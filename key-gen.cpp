// keygen.cpp
// Description: Generates and validates license keys for software you control.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <random>
#include <array>
#include <cstdint>

std::string generateKey()
{
    static constexpr char alphabet[] =
        "ABCDEFGHJKLMNPQRSTUVWXYZ23456789";

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(
        0, sizeof(alphabet) - 2
    );

    std::ostringstream key;

    for (int group = 0; group < 5; ++group) {
        if (group != 0)
            key << '-';

        for (int i = 0; i < 5; ++i)
            key << alphabet[dist(rng)];
    }

    return key.str();
}

uint32_t checksum(const std::string& key)
{
    uint32_t hash = 2166136261u;

    for (unsigned char c : key) {
        hash ^= c;
        hash *= 16777619u;
    }

    return hash;
}

bool validateKey(const std::string& key)
{
    if (key.size() != 29)
        return false;

    for (size_t i = 0; i < key.size(); ++i) {
        if ((i + 1) % 6 == 0) {
            if (key[i] != '-')
                return false;
        }
    }

    return true;
}

int main()
{
    std::cout << "--- C++ License Key Generator ---\n\n";

    std::string key = generateKey();

    std::cout << "Generated key: " << key << '\n';
    std::cout << "Checksum: 0x"
              << std::hex
              << std::uppercase
              << checksum(key)
              << std::dec
              << '\n';

    std::cout << "Format valid: "
              << (validateKey(key) ? "yes" : "no")
              << '\n';

    return 0;
}