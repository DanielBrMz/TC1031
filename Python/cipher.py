def caesar_decrypt(ciphertext, shift):
    plaintext = ""
    for char in ciphertext:
        ascii_offset = ord('A') if char.isupper() else ord('a')
        decrypted_char = chr((ord(char) - ascii_offset - shift) % 26 + ascii_offset)
        plaintext += decrypted_char
    return plaintext

ciphertext = "@ICE@JB=BIBA@EC?@DB=B?BG@IBACD?B"
shift = 8
plaintext = caesar_decrypt(ciphertext, shift)
print(plaintext)
