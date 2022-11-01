# 클라이언트 프로그램
import socket
import threading
import time


def send(sock):
    while True:# /end 입력될 때 까지 계속해서 서버에 패킷을 보냄(무한 루프 활용)
        sendData = input('') # 서버로 보낼 msg 입력
        sock.send(sendData.encode('utf-8'))
        if sendData == '/end':
            print('서버 종료')
            client_socket.close() # /end 이후 클라이언트 소켓 닫아줌
            break

def receive(sock):
    while True:
        # recv(메세지 크기): 소켓에서 크기만큼 읽는 함수
        recvData = sock.recv(100)
        print('<상대방>: ', recvData.decode('utf-8'))# 읽은 데이터 디코딩(해독)

server_ip = 'localhost' # 서버에서 설정한 ip
server_port = 3333 # 서버에서 설정한 포트 번호

#클라이언트가 서버에 연결하기 위해 서버 ip 접속
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((server_ip, server_port))

print('Connection complete')

# 클라이언트 연결 시, 1:1 통신소켓을 오픈(메세지 전달 및 받기) + 쓰레드에 전달/실행
sender = threading.Thread(target=send, args=(client_socket,))
receiver = threading.Thread(target=receive, args=(client_socket,)) 

sender.start()
receiver.start()

while True:
    time.sleep(1)
    pass