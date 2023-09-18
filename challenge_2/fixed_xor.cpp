#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string buffer1 = "1c0111001f010100061a024b53535009181c";
    std::string buffer2 = "686974207468652062756c6c277320657965";
    std::string result;

    for (int i = 0; i < buffer1.length(); i++) {
        int xored_bit = std::stoi(buffer1.substr(i, 1), 0, 16) ^ std::stoi(buffer2.substr(i, 1), 0, 16);
        
        std::stringstream ss;
        ss << std::hex << xored_bit;
        result += ss.str();
    }
    
    std::cout << result << std::endl;

   return 0;
}
