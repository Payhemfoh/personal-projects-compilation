import socket
import threading


HEADER = 16
PORT = 8080
FORMAT = "utf-8"
DISCONNECT_MESSAGE = "!DISCONNECTED"
# get host ip address automatically
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)


# handle connection between client and server
#
def handle_client(conn, addr):
    print(f"[MESSAGE] {addr} connected.")
    connected = True
    while connected:
        # receive the message from client then go to next code
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if len(msg_length)>0:
            msg = conn.recv(int(msg_length)).decode(FORMAT)
            print(f"[{addr}] {msg}")

            if msg == DISCONNECT_MESSAGE:
                connected = False

    conn.close()


# let the server start to listen and handling the connections
def start():
    server.listen()
    print(f"[MESSAGE] Server is listening on {SERVER}")
    loop = True
    while loop:
        # when new connection occur, address is stored
        # conn stores the object for sent back data (SOCKET object)
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[MESSAGE] {threading.active_count() - 1}")


if __name__ == "__main__":
    # open a socket to open connection to other devices
    # type of socket or address
    # type of data sent
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # bind the socket to the address built up by ip and port
    server.bind(ADDR)

    # print out message and wait for connection
    print("[Message] Server is starting....")
    start()
