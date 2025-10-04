# 기본 concept

### Core 측

인증
1. node 에서 attach request 메시지로 key를 인증하면, id와 key를 node 클래스에 저장한다. 
2. 인증하면 core 는 node 측으로 attach accpet 메시지를 보내 통신을 시작한다. 인증이 실패하면 attach decline 메시지를 보낸다.  
3. 인증 이후 node는 core와 자유롭게 통신 가능하다. core는 저장된 node의 id일 경우 통신한다. 

메시지 처리
1. core는 각 노드의 메시지를 받을 경우 node 클래스의 msg 에 저장한다. 
2. core는 각 노드의 최근 메시지를 조회할 수 있다. 
3. 새로운 메시지가 도착할 경우 msg를 비운 후 새로운 메시지를 채운다. 
4. end code 까지를 유효한 메시지로 한다.

버퍼 처리
1. core는 버퍼를 두 개 갖는다. RX_buffer[64], TX_buffer[64]
2. serial 통신으로 통해 들어온 데이터는 RX_buffer에 저장된다. 
3. buffer class에서 버퍼의 정보를 node 정보로 copy한다. 


# class buffer
생성자는 기본 생성자
serial 통신을 읽을 수 있는 함수가 필요함. main함수의 loop에서 버퍼 클래스의 메소드 함수가 실행될 것. 
버퍼는 비어있을 때만 쓸 수 있음!

#### 필요한 멤버변수
1. 시작부터 end code 까지의 길이

#### 필요한 함수
1. 버퍼가 비어있는지 차있는지 확인하는 함수, bool
2. 버퍼에 담긴 문자열을 pop하는 함수, string
3. 버퍼에 문자열을 write하는 함수, bool
4. 버퍼를 clear 하는 함수, bool
5. serial 통신 시에 들어오는 char가 end code가 아니면 버퍼에 써주는 함수 (RX_buffer)
6. serial 통신이 아니더라도 end code 까지 버퍼에 써주는 함수 (TX_buffer)
7. TX_buffer에 저장된 내용 lora 아두이노로 내보내는 함수
8. TX_buffer에 저장된 내용 웹으로 내보내는 함수


# namespace core
각 노드를 관리한다.
RX_buffer, TX_buffer를 관리한다. 
RX_buffer를 읽고 인증된 id일 경우 해당 id의 node에 메시지를 업데이트 한다. 
RX_buffer를 읽고 새로운 id일 경우 인증 과정을 진행한다. 

TX_buffer를 쓰고 내보낸다. 


# class node
인증이 끝난 노드들은 core에 저장된다. 
node 안에는 id, key, 해당 노드가 가장 마지막으로 보낸 메시지가 저장된다. 

#### 필요한 멤버변수
1. id, key, 마지막으로 보낸 메시지
2. 현재 online 여부

#### 필요한 함수
1. 
2. 

# 메시지 구조
id (3 byte) + dir (1 byte) + pur (1 byte) + msg



# 업데이트 10.02
node 클래스의 인스턴스가 msg 객체 하나를 갖는다. msg 객체는 마지막으로 보낸 메시지이다. 

클래스 구조도는
buffer, node, msg 모두 .h 파일로 저장
hdr.h 삭제
세개의 헤더파일 core가 인클루드


# 업데이트 10.04
헤더 파일에 msg class, buffer class 정리