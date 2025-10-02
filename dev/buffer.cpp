#include "hdr.h"

class buffer {
private:
    int length = 0;
    char buffer_array[64];

public:
    void clear() {
        buffer_array[0] = '\0';
        length = 0;
    }

    bool is_empty() {
        return buffer_array[0] == '\0';
    }

    void write_buffer(const char* str) {
        if (buffer_array[0] == '\0' && length == 0) {
            strncpy(buffer_array, str, 63);
            buffer_array[63] = '\0';
            length = strlen(buffer_array);
        } else { 
            std::cout << "buffer error : buffer not clear" << std::endl;
        }
    }

    const char* pop_buffer() {
        const char* tmp = buffer_array;
        clear();
        return tmp;
    }

    int get_length() const {
        std::cout << length << std::endl;
        return strlen(buffer_array);
    }

    void print() const {
        printf("Buffer: '%s' (length: %d)\n", buffer_array, (int)strlen(buffer_array));
    }
};
