# 서버 프로그램(UDP)
import socket
import threading
import time

host = 'localhost' # 서버 컴퓨터의 ip(여기선 내 컴퓨터를 서버 컴퓨터로 사용)
                   # (cmd -> ipconfig를 통해 자기 자신의 ip주소를 써도 무방함)
port = 3333 # 서버 포트번호(다른 프로그램이 사용하지 않는 포트번호로 지정해야 함)

# 서버소켓 오픈
# socket.AF_INET: 주소종류 지정(IP) / socket.SOCK_DGRAM: 통신종류 지정(UDP, TCP)
# SOCK_DGRAM은 UDP를 쓰겠다는 의미
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 여러번 ip.port를 바인드하면 에러가 나므로, 이를 방지하기 위한 설정이 필요
# socket.SOL_SOCKET: 소켓 옵션
# SO_REUSEADDR 옵션은 현재 사용 중인 ip/포트번호를 재사용할 수 있다.
# 커널이 소켓을 사용하는 중에도 계속해서 사용할 수 있다.
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# server socket에 ip와 port를 붙여줌(바인드)
server_socket.bind((host, port))

#UDP는 TCP와 다르게 연결 없이 서로 메세지를 곧바로 그 보내려는 주소와 함께 보내고, 받음
#그렇기 때문에 receive와 sender 함수를 다 만들어버리면 쓰레드 충돌이 일어나서 오류가 생김
#그래서 메세지를 받는 함수인 receive만 함수로 설정해주고, send 따로 반복문을 통해 main()에 두면 됨
def receive(sock):
    while True:
        try:
            data, _= sock.recvfrom(1024)# recvfrom함수를 사용하여 소켓에서 1024만큼 들고와서 할당함
            print('<상대방>: ', data.decode('utf-8'))# 서버에서 보낸 문자를 decoding해서 출력함
        except:
            pass
        
print('Waiting for access to port %d...'%port) # 클라이언트에서 서버로 접속하기전까지 나타나는 문장

# (메세지 전달 및 받기) + 쓰레드에 전달/실행
receiver = threading.Thread(target=receive, args = (server_socket,))

receiver.start()

while True:
    sendData = input('') # 서버로 보낼 msg 입력
    if sendData == '/end':
        print('서버 종료')
        server_socket.close() # /end 이후 클라이언트 소켓 닫아줌
        break

    else:
        # udp는 send 대신 sendto 함수를 쓰고 그와 메세지를 보낼 대상의 주소도 함께 보냄
        server_socket.sendto(sendData.encode('utf-8'), (host, 8888)) 


while True:
    time.sleep(1)
    pass