#include <iostream>
#include <random>
#include <string>

std::string generateKey()
{
    static constexpr char alphabet[] =
        "ABCDEFGHJKLMNPQRSTUVWXYZ23456789";

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(
        0, sizeof(alphabet) - 2
    );

    std::string key;

    for (int group = 0; group < 5; ++group) {
        if (group > 0)
            key += '-';

        for (int i = 0; i < 5; ++i)
            key += alphabet[dist(rng)];
    }

    return key;
}

int main()
{
    std::cout << "--- 10 License Keys ---\n\n";

    for (int i = 1; i <= 10; ++i) {
        std::cout << i << ": "
                  << generateKey()
                  << '\n';
    }

    return 0;
}