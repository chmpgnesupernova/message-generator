#ifndef MSG_H
#define MSG_H

#include <iostream>
#include <cstring>

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

public:
    char get_id() const { return id; }
    char get_direction() const { return direction; }
    char get_purpose() const { return purpose; }

    void set_id(char _id) { id = _id; }
    void set_direction(char _dir) { direction = _dir; }
    void set_purpose(char _pur) { purpose = _pur; }
};

#endif // MSG_H



