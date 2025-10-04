#ifndef HDR
#define HDR 

#include <iostream>
#include <cstring>


class buffer {
private:
    int length = 0;
    char buffer_array[64];

public:
    void clear() {
        buffer_array[0] = '\0';
        length = 0;
        std::cout << "buffer : buffer cleared" << std::endl;
    }

    bool is_empty() {
        if (buffer_array[0] == '\0' && length == 0) { 
            return true; 
        } else if (buffer_array[0] == '\0' != length == 0) { 
            std::cout << "buffer error : buffer length worng!" << std::endl;
            return  false;
        } else {
            return false;
        }
    }

    void write_buffer(char* str) {
        if ( this -> is_empty() ) {
            memcpy(buffer_array, str, strlen(str));
            buffer_array[63] = '\0';
            length = strlen(str);
        } else { 
            std::cout << "buffer error : buffer not clear" << std::endl;
        }
    }

    char* pop_buffer() {
        char* tmp = buffer_array;
        this -> clear();
        std::cout << "buffer : buffer popped" << std::endl;
        return tmp;
    }

    int get_length() const {
        std::cout << "buffer length : " << length << std::endl;
        return length;
    }

    void print() const {
        printf("Buffer: '%s' (length: %d)\n", buffer_array, (int)strlen(buffer_array));
    }
};


class msg {
private:
    char id[3];
    char direction;
    char purpose;
    char payload[59];

public:
    char* get_id() { 
        return id; 
    }
    char get_direction() {
         return direction; 
    }
    char get_purpose() { 
        return purpose; 
    }
    void print_payload() {
        std::cout << payload << std::endl;
    }
    void set_id(char* _id) { 
        memcpy(id, _id, 3); 
    }
    void set_direction(char _dir) { 
        direction = _dir; 
    }
    void set_purpose(char _pur) { 
        purpose = _pur; 
    }
    void set_payload(const char* _payload) { 
        memcpy(payload, _payload, 59); 
    }
};

#endif