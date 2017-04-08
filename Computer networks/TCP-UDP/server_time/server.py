import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

print(sock)

server = "pythonprogramming.net"
port = 80

server_ip = socket.gethostbyname(server)

print(server_ip)

request = "GET /HTTP/1.1\nHost: " + server + "\n\n"

sock.connect((server, port))

print(request)

sock.send(request.encode())

result = sock.recv(40)

while len(result) > 0:
    print(result )
    result = sock.recv(40)


