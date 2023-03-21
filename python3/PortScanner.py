import socket
import threading
import queue

targetip = "192.168.1.1"


def scanPort(port):
    try:
        connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        connection.connect((targetip, port))
        return True

    except:
        return False


def activity():
    while not portList.empty():
        port = portList.get()
        if scanPort(port):
            print(f"Port {port} is opened!")
            openPort.append(port)


def fill_queue(low_range, up_range):
    for i in range(low_range, up_range):
        portList.put(i)


if __name__ == "__main__":
    portList = queue.Queue()
    openPort = []
    thread_list = []
    fill_queue(1,10000)

    for s in range(1000):
        thread = threading.Thread(target=activity)
        thread_list.append(thread)

    for t in thread_list:
        t.start()

    for t in thread_list:
        t.join()

    print("The open ports are ", openPort)
