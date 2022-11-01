# 서버 프로그램(TCP)
import socket
import threading
import time


def send(sock):
    while True:# /end 입력될 때 까지 계속해서 서버에 패킷을 보냄(무한 루프 활용)
        sendData = input('') # 클라이언트로 보낼 msg 입력
        if sendData == '/end':
            print('서버 종료')
            server_socket.close() # /end 이후 서버 소켓 닫아줌 -> 서버 소켓은 닫아도 클라이언트는 계속 활동함.
            break
        sock.send(sendData.encode('utf-8'))

def receive(sock):
    while True:
        # recv(메세지 크기): 소켓에서 크기만큼 읽는 함수
        recvData = sock.recv(100)
        print('<상대방>: ', recvData.decode('utf-8'))# 읽은 데이터 디코딩(해독)

host = 'localhost' # 서버 컴퓨터의 ip(여기선 내 컴퓨터를 서버 컴퓨터로 사용)
                   # (cmd -> ipconfig를 통해 자기 자신의 ip주소를 써도 무방함)
port = 3333 # 서버 포트번호(다른 프로그램이 사용하지 않는 포트번호로 지정해야 함)

# 서버소켓 오픈
# socket.AF_INET: 주소종류 지정(IP) / socket.SOCK_STREAM: 통신종류 지정(UDP, TCP)
# SOCK_STREAM은 TCP를 쓰겠다는 의미
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 여러번 ip.port를 바인드하면 에러가 나므로, 이를 방지하기 위한 설정이 필요
# socket.SOL_SOCKET: 소켓 옵션
# SO_REUSEADDR 옵션은 현재 사용 중인 ip/포트번호를 재사용할 수 있다.
# 커널이 소켓을 사용하는 중에도 계속해서 사용할 수 있다.
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# server socket에 ip와 port를 붙여줌(바인드)
server_socket.bind((host, port))

# 클라이언트 접속 준비 완료
server_socket.listen(1)

print('Waiting for access to port %d...'%port) # 클라이언트에서 서버로 접속하기전까지 나타나는 문장

# accept(): 클라이언트 접속 기다리며 대기
# 클라이언트가 접속하면 서버-클라이언트 1:1 통신이 가능한 작은 소켓(client_soc)을 만들어서 반환
# 접속한 클라이언트의 주소(addr) 역시 반환 
client_soc, addr = server_socket.accept()

print('connected client addr:', addr)

# 클라이언트 연결 시, 1:1 통신소켓을 오픈(메세지 전달 및 받기) + 쓰레드에 전달/실행
sender = threading.Thread(target=send, args=(client_soc,))
receiver = threading.Thread(target=receive, args=(client_soc,)) 

sender.start()
receiver.start()

while True:
    time.sleep(1)
    pass