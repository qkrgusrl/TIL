# 클라이언트 프로그램
import socket
import threading
import time

server_ip = 'localhost' # 서버에서 설정한 ip
client_port = 8888 # 서버에서 설정한 포트번호(클라이언트에 대한 포트번호 따로 설정)

# 클라이언트가 서버에 연결하기 위해 서버 ip 접속(UDP는 TCP와 달리 connect 함수 필요 없음)
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

#server와 connect하는 형태가 아니기 때문에 이 자체의 ip와 port를 따로 bind 함
client_socket.bind((server_ip, client_port))

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

print('Connection complete')

# (메세지 전달 및 받기) + 쓰레드에 전달/실행
receiver = threading.Thread(target=receive, args=(client_socket,))

receiver.start()

while True:
    sendData = input('') # 서버로 보낼 msg 입력
    if sendData == '/end':
        print('서버 종료')
        client_socket.close() # /end 이후 클라이언트 소켓 닫아줌
        break

    else:
        client_socket.sendto(sendData.encode('utf-8'), (server_ip, 3333)) # udp는 send 대신 sendto 함수를 쓰고 그와 동시에 메세지를 보낼 대상의 주소도 함께 보냄

while True:
    time.sleep(1)
    pass