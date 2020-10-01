import socket
from threading import Thread
def thread():
    while True:
        data = conn.recv(1024)
        print('Client Request: ' + data.decode())
        if data == 'quit' or not data:
            print("Server Exiting")
            break
        data = input('Server Response: ')
        conn.sendall(data.encode())
        
host = socket.gethostname()
port = 6986
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host,port))
s.listen(5)
print("Waiting...")
while True:
    conn,addr = s.accept()
    print("Connected with", addr)
    pr = Thread(target=thread)
    pr.start()
conn.close()
