#ifndef MSG_H
#define MSG_H

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define UL 'u'
#define DL 'd'

#define ATTACH_REQUEST '1'
#define ATTACH_ACCEPT  '2'
#define ATTACH_DECLINE '3'
#define GENERAL_MSG '4'

#define CORE 'C'


class msg {
private:
    char id;
    char direction;
    char purpose;
    char payload[60];

public:
    char get_id() const { return id; }
    char get_direction() const { return direction; }
    char get_purpose() const { return purpose; }

    void set_id(char _id) { id = _id; }
    void set_direction(char _dir) { direction = _dir; }
    void set_purpose(char _pur) { purpose = _pur; }
    void set_payload(const char* _payload) {
        int index = 0;
        while (*_payload != '\n') {
            payload[index] = *_payload;
            index++;
            _payload++;
        }
    }
};



class core {
private:
// 받은 메시지의 id가 subscriber id list 에 있는 id인가? 만약 아니라면 trigger decline, 맞다면 general msg 로 핸들링
// 코어는 노드의 정보를 저장하고 있어야 한다. 활성된 node 의 리스트를 갖는다. 만약 노드가 꺼진다면 리스트에서 pop한다.
// attach request 로 받은 메시지를 검사한다. id, key를 사용

    std::vector<char> subscriber_id_list = {};
    std::vector<node> subscriber_online = {};

public:
    bool is_subscriber (char _id) {
        std::vector<char>::iterator it;
        it = find(subscriber_id_list.begin(), subscriber_id_list.end(), _id);
        return it != subscriber_id_list.end();
    }

    bool is_online (node _node) {
        std::vector<node>::iterator it;
        it = find(subscriber_online.begin(), subscriber_online.end(), _node);
        return it != subscriber_online.end();                
    }

};

class node {
private:
    char id;

public:
    char get_id() { return id; }

};

#endif // MSG_H



