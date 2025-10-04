#ifndef NODE
#define NODE

#include "hdr.h"

class node {
private:
    char id[3]; 
    char key[10];
    msg prev_msg;
    bool online;

public:
    node(const char* _id, char* _key) : online(false) {
        memcpy(id, _id, 3);
        memcpy(key, _key, 10);
        std::cout << "node : initialized node!" << std::endl;
    }

    void set_msg(msg _msg) {
        prev_msg = _msg;
        std::cout << "node : set message!" << std::endl;
    }

    void print_msg() {
        std::cout << "id: " << prev_msg.get_id() << std::endl;
        std::cout << "payload: ";
        prev_msg.print_payload();
    }

    const char* get_id() const {
        std::cout << "node id: " << id << std::endl;
        return id;
    }

    const char* get_key() const {
        std::cout << "node key: "<< key << std::endl;
        return key;
    }

    const bool is_online() {
        std::cout << "node online: " << online << std::endl;
        const bool tmp = online;
        return tmp;
    }

};

#endif