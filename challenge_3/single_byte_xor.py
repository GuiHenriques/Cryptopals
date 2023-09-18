import string

# Define a function to score the plaintext based on character frequency
def score_plaintext(plaintext):
    # Define a dictionary of expected character frequencies in English text
    expected_frequencies = {
        'a': 0.0817, 'b': 0.0149, 'c': 0.0278, 'd': 0.0425,
        'e': 0.1270, 'f': 0.0223, 'g': 0.0202, 'h': 0.0609,
        'i': 0.0697, 'j': 0.0015, 'k': 0.0077, 'l': 0.0403,
        'm': 0.0241, 'n': 0.0675, 'o': 0.0751, 'p': 0.0193,
        'q': 0.0010, 'r': 0.0599, 's': 0.0633, 't': 0.0906,
        'u': 0.0276, 'v': 0.0098, 'w': 0.0236, 'x': 0.0015,
        'y': 0.0197, 'z': 0.0007, ' ': 0.1918
    }

    # Initialize a score
    score = 0

    # Calculate the score based on character frequency
    for char in plaintext.lower():
        if char in expected_frequencies:
            score += expected_frequencies[char]

    return score

# Hex-encoded ciphertext
hex_encoded_ciphertext = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"

# Convert the hex string to bytes
ciphertext_bytes = bytes.fromhex(hex_encoded_ciphertext)

# Initialize variables to store the best key and plaintext
best_key = None
best_plaintext = None
best_score = 0

# Iterate through all possible keys
for key in range(89, 110):
    # XOR the key with the ciphertext
    plaintext_bytes = bytes([byte ^ key for byte in ciphertext_bytes])
    
    # Convert the bytes to a string
    plaintext = plaintext_bytes.decode('utf-8', errors='ignore')
    
    # Score the plaintext
    current_score = score_plaintext(plaintext)
    
    # Update the best key and plaintext if the current score is higher
    if current_score > best_score:
        best_key = key
        best_plaintext = plaintext
        best_score = current_score

# Print the best key, plaintext, and score
print("Best Key:", best_key)
print("Decrypted Message:", best_plaintext)
print("Score:", best_score)
