#include <iostream>
#include <bitset>
#include <math.h>


int main()
{
    const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    
    std::string binary_string;
    std::string result;

    int decimal;
    for (char c : input) // for each hex value in input
    {
        decimal = (std::isdigit(c) ? c - '0' : c - 'a' + 10); // hex to dec
        std::bitset<4> bin(decimal); // dec to bin
        binary_string += bin.to_string(); // append binary value to binary_string
    }

    int n = ceil(binary_string.length() / 6.0); // number of characters in the final result

    for (int i = 0; i < n; i++)
    {
        std::string sextet = binary_string.substr(i * 6, 6); // group of six bits

        if (sextet.length() < 6) // check if last group has six bits
        {
            for (int i = sextet.length(); i != 6; i++)
                sextet += "0"; // 0 padding to complete 6 bits
        }

        decimal = std::stoi(sextet, 0, 2); // convert 6-bit binary group to decimal

        result += base64Chars[decimal]; // find corresponding character using encoding table
    }

    for (int i = input.length(); i % 3 != 0; i++)
        result += "="; // = padding to make result a multiple of 3
 
    std::cout << result << std::endl;
}