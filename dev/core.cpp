#include "hdr.h"
#include "buffer.cpp"
#include "node.cpp"


namespace core {

    buffer rx_buffer;
    buffer tx_buffer;

    char* test_string = "ad11234567890hello";

    void store_buffer(char* _str, buffer& _buf) {
        if (_buf.is_empty() == true) {
            _buf.write_buffer(_str);
        }
    }

    const char* get_buffer(buffer& _buf) {
        const char* popped_str = _buf.pop_buffer();
        return popped_str;
    }

    void map_elements (buffer& _buf, node& _node) {
        char* tmp_id;
        char* tmp_key;
        int tmp_len;

        const char* tmp_str = _buf.pop_buffer();
        strncpy (tmp_id, tmp_str, 3);

    }

};