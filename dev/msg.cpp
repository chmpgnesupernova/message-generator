#include <cstring>

class msg {
private:
    char id[3];
    char direction;
    char purpose;
    char payload[59];

public:
    char* get_id() { return id; }
    char get_direction() { return direction; }
    char get_purpose() { return purpose; }

    void set_id(char* _id) { strncpy(id, _id, 3); }
    void set_direction(char _dir) { direction = _dir; }
    void set_purpose(char _pur) { purpose = _pur; }
    void set_payload(const char* _payload) { strncpy(payload, _payload, 59); }
};