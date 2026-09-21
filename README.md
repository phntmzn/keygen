
# C++ License Key Generator

A small C++17 program that generates 10 randomly generated license-key-style strings.

## Features

- Generates 10 keys per execution
- Uses C++ `<random>`
- Uses uppercase letters and digits
- Avoids visually ambiguous characters
- Formats each key into five groups of five characters
- Runs natively on macOS
- Requires no external libraries

## Key Format

Each generated key has this format:

```text
XXXXX-XXXXX-XXXXX-XXXXX-XXXXX
```

Example:

```text
8K4QM-7X2TR-P9H3C-W6N5Y-D8F2K
```

## Requirements

- macOS
- Apple Clang
- C++17 or newer

Check the compiler:

```bash
clang++ --version
```

## Compile

Save the source as:

```text
keygen.cpp
```

Compile:

```bash
clang++ -std=c++17 -O2 keygen.cpp -o keygen
```

## Run

```bash
./keygen
```

Example output:

```text
--- 10 License Keys ---

1: 8K4QM-7X2TR-P9H3C-W6N5Y-D8F2K
2: M7Q3R-2K9TX-H5C8P-N4Y6W-F7D3G
3: Q6N8T-Y4K2P-7F3HM-R9C5W-X8D6G
4: 3P7KY-H6Q9M-T2X4R-C8N5W-F7D3G
5: W4M8Q-2R7TX-K9C3H-P6Y5N-D8F4G
6: H5T9P-X3K7M-Q8R2C-W4N6Y-F7D3G
7: K8Q4M-N7T2X-P9H3C-Y6W5R-D4F8G
8: R6P3K-W8M4T-X2Q9H-C7N5Y-F3D8G
9: T7X5M-Q3K8P-H4R2C-W9N6Y-D7F3G
10: N4C8Q-Y7M2T-K5P9R-X3H6W-F8D4G
```

## Project Structure

```text
keygen/
├── keygen.cpp
└── README.md
```

## How It Works

The generator defines an alphabet:

```cpp
"ABCDEFGHJKLMNPQRSTUVWXYZ23456789"
```

`std::random_device` provides a seed for the random-number generator, and `std::mt19937` selects characters from the alphabet.

The program generates:

- 5 groups
- 5 characters per group
- 25 characters total
- 4 separators

This produces a 29-character formatted key.

## Important Note

These strings are suitable for demonstrations, prototypes, testing, or software you control. They are **not cryptographic license credentials**.

For production licensing, use a cryptographic signature scheme such as Ed25519 rather than putting a secret verification algorithm or secret signing key inside the application.

## License

MIT License.