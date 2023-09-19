#include <iostream>

int main()
{
    std::string key = "ICE";
    std::string input = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    std::string output = "";

    for (size_t i = 0; i < input.length(); i++)
    {
        char xored_char = input[i] xor key[i % key.size()];
        output += xored_char;
    }

    for (char c : output)
    {
        printf("%02x", static_cast<unsigned char>(c));
    }
    std::cout << std::endl;
}