#include "hdr.h"

class node {
private:
    const char* id; // 3 byte
    const char* key;// 10 byte
    char msg[64];
    int length;
    bool online;

public:
    node(char* _id, char* _key, int _len) : 
        id(_id), key(_key), length(_len) {}

    void set_msg(const char* str) {
        strncpy(msg, str, 63);
        msg[63] = '\0';
        length = strlen(msg);
    }

    const char* get_msg() {
        const char* tmp = msg;
        return tmp;
    }

    const char* get_id() const {
        return id;
    }

    const char* get_key() const {
        return key;
    }

    const bool is_online() {
        const bool tmp = online;
        return tmp;
    }

};