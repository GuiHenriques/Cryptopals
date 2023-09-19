def xor_decrypt(ciphertext, key):
    plaintext = ""
    for byte in ciphertext:
        plaintext += chr(byte ^ key)
    return plaintext

def score_plaintext(plaintext):
    score = 0
    for char in plaintext:
        if char in "etaoin shrdlu":
            score += 1
    return score

def main():
    with open("data.txt", "r") as file:
        encoded_strings = [line.strip() for line in file.readlines()]

    potential_solutions = []

    for encoded_string in encoded_strings:
        for key in range(256):  # Try all possible single-byte keys
            plaintext = xor_decrypt(bytes.fromhex(encoded_string), key)
            score = score_plaintext(plaintext)
            potential_solutions.append((score, key, plaintext))

    # Sort potential solutions by score in descending order
    potential_solutions.sort(reverse=True)

    # Print the most likely plaintext
    best_score, best_key, best_plaintext = potential_solutions[0]
    print("Best Score:", best_score)
    print("Best Key:", hex(best_key))
    print("Best Plaintext:", best_plaintext)

if __name__ == "__main__":
    main()
