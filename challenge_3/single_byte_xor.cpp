#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int score_text(std::string &text);

int main()
{
    std::string hex_encoded = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    std::vector<unsigned char> hex_bytes; // list of bytes
    for (size_t i = 0; i < hex_encoded.length(); i+=2) // grouping of 2 hex (4 bits each) to complete 1 byte
    {
        std::string str_byte = hex_encoded.substr(i, 2); // string byte slice
        unsigned char byte = std::stoi(str_byte, 0, 16); // actual byte
        hex_bytes.push_back(byte); // append byte to list of bytes
    }

    // variables to store the best key, plaintext and score
    int best_key;
    std::string best_plaintext;
    int best_score;

    // iterate through the possible keys
    for (int key = 0; key <= 127; key++) {
        std::string plaintext;

        // xor all bytes with key
        for (unsigned char byte : hex_bytes) {
            plaintext += (byte ^ key); 
        }

        // score the xor result
        int score = score_text(plaintext);

        // update the best key, plaintext and socre
        if (score >= best_score){
            best_key = key;
            best_plaintext = plaintext;
            best_score = score;
        }
    }

    // Results
    std::cout << "Best Key: " << best_key << std::endl;
    std::cout << "Decrypted Message: " << best_plaintext << std::endl;
    std::cout << "Score: " << best_score << std::endl;
}

int score_text(std::string &text)
{
    int score = 0;

    for (char chr : text)
    {
        if (chr == 32 || isalpha(chr))
            score++;
        else
            score--;
    }
    return score;
}