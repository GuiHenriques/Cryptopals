# Convert ascii string to base64
from math import ceil

txt = ""
binary = ""
result = ""
base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

for letter in txt:
    binary += f"{ord(letter):08b}"

letters = ceil(len(binary)/6)
print()
for i in range(letters):
    sextet = binary[i*6:(i+1)*6]
    
    if (len(sextet) < 6):
        sextet += "0" * (6 - len(sextet))
    result += base64[int(sextet, 2)]

print(result)