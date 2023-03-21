import socket
import threading


def broadcast(message):
    for client in clients:
        client.send(message)

def handle(client):
    while True:
        try:
            message = client.recv(1024)
            broadcast(message)
        except:
            index = clients.index(client)
            nickname = nicknames[index]
            broadcast(f"{nickname} has left the chat.".encode("ascii"))
            clients.remove(client)
            nicknames.remove(nickname)
            break

def receive():
    while True:
        client, address = server.accept()
        print("connected with "+str(address))

        client.send("NICK".encode("ascii"))
        nickname = client.recv(1024).decode("ascii")
        nicknames.append(nickname)
        clients.append(client)

        print(f"Nickname of the client is {nickname}")
        broadcast(f"{nickname} has join the chat.".encode("ascii"))
        client.send("Connected to the server!".encode("ascii"))

        thread = threading.Thread(target=handle,args=(client,))
        thread.start()

hostIp = "localhost"
port = 8080

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind((hostIp,port))
server.listen()

clients = []
nicknames = []

print("Server is listening")
receive()