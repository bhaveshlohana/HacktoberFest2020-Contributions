import socket

# This is using HTTP 1.0 - not all servers support the oldest protocol

url = input('Enter: ')
words = url.split('/')
host = words[2]

mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect((host, 80))
mysock.send(('GET '+url+' HTTP/1.0\r\n\r\n').encode())

while True:
    data = mysock.recv(512)
    if (len(data) < 1):
        break
    print(data.decode(), end='')

mysock.close()
