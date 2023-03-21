import socket

HEADER = 16
PORT = 8080
FORMAT = "utf-8"
DISCONNECT_MESSAGE = "!DISCONNECTED"
# get host ip address automatically
SERVER = "192.168.1.13"
ADDR = (SERVER, PORT)

def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = (str(msg_length)).encode(FORMAT)
    send_length += b" " * (HEADER - len(send_length))
    client.send(send_length)
    client.send(message)


if __name__ == "__main__":
    client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client.connect(ADDR)
    loop = True
    while True:
        text = input("Your message:")
        if text == "!Q" or text == "!q":
            send(DISCONNECT_MESSAGE)
            loop = False
        else:
            send(text)
