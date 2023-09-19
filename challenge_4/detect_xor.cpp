#include <iostream>
#include <fstream>

int score_plaintext(std::string plaintext);
std::string xor_decrypt(std::string ciphertext, char key);

int main()
{
    std::fstream data("data.txt");

    if (!data.is_open()) // Check if file is open
    {
        std::cerr << "Error opeing file" << std::endl;
        return 1;
    }

    std::string ciphertext;
    std::string plaintext;
    std::string best_plaintext;

    int score;
    int best_score = -1000;
    
    char best_key = 0;
    
    // For each encoded string in the file
    while (std::getline(data, ciphertext))
    {

        // For each possible key
        for (char key = 0; key < 127; key++)
        {
            plaintext = xor_decrypt(ciphertext, key); // Decrypt the string using single-byte XOR
            score = score_plaintext(plaintext); // Score the resulting plaintext

            if (score > best_score) 
            {
                best_score = score;
                best_key = key; 
                best_plaintext = plaintext;
            }
        }
    }

    // Print the best result
    std::cout << "Best score: " << best_score << std::endl;
    std::cout << "Best key: " << best_key << std::endl;
    std::cout << "Best plaintext: " << best_plaintext << std::endl;
}

int score_plaintext(std::string plaintext)
{
    int score = 0;

    for (char c : plaintext)
    {
        if (isalpha(c) || c == 32)
            score++;
        else
            score--;
    }

    return score;
}

std::string xor_decrypt(std::string ciphertext, char key)
{
    std::string plaintext;
    char xored_byte;

    for (int i = 0; i < ciphertext.length() / 2; i++)
    {
        std::string hex_pair = ciphertext.substr(i * 2, 2); 
        xored_byte = std::stoi(hex_pair, nullptr, 16) ^ key; // Convert hex pair to int, xor with key
        plaintext += xored_byte;
    }

    return plaintext;
}
