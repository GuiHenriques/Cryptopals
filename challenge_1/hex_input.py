from math import ceil

input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
binary = ""
result = ""
base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

for letter in input:
    byte = f"{int(letter, 16):04b}"
    # print(byte)
    binary += byte

letters = ceil(len(binary)/6)

for i in range(letters):
    sextet = binary[i*6:(i+1)*6]
    
    if len(sextet) < 6:
        sextet += "0" * (6 - len(sextet))
    # print(sextet, base64[int(sextet, 2)])
    result += base64[int(sextet, 2)]

print(result)
