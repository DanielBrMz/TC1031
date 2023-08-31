import string
import secrets

def generate_password(length, allowed_chars):
    password = ''.join(secrets.choice(allowed_chars) for i in range(length))
    return password

# Example usage
length = 30
allowed_chars = string.ascii_letters + string.digits + string.punctuation
password = generate_password(length, allowed_chars)
print(password)
