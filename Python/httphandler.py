import requests

url = 'https://ctf-server-url.com/api/endpoint'  # Replace with the actual URL
data = {'ifname': 'your_interface_name'}

response = requests.post(url, data=data)

# Print the server's response
print(response.text)
