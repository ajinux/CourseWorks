import socket
import threading

lock = threading.Lock()
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server = "pythonprograming.net"


def psacn(port):
    try:
        sock.connect((server, port))
        return True
    except Exception as E:
        # print(E)
        return False


for x in range(1,100):
    if psacn(x):
        print("Port ", x, " is open")
    else:
        print("Port ", x, "is closed")
