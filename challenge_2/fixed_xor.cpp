#include <iostream>
#include <sstream>

int main() {
    std::string buffer1 = "1c0111001f010100061a024b53535009181c";
    std::string buffer2 = "686974207468652062756c6c277320657965";
    std::string result;
    
    int buffer_length = buffer1.length(); // Buffers length

    for (int i = 0; i < buffer_length; i+=2) { // For each character in buffer
        int bit1 = std::stoi(buffer1.substr(i, 2), 0, 16); // convert char to int
        int bit2 = std::stoi(buffer2.substr(i, 2), 0, 16); //convert char to int

        int xored_bit = bit1 ^ bit2; // xor operation

        std::stringstream ss;
        ss << std::hex << xored_bit; // convert int to hex value
        result += ss.str(); // append hex value to result
    }
    
    std::cout << result << std::endl;

   return 0;
}
