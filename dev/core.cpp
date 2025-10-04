#ifndef CORE
#define CORE

#include "hdr.h"
#include "node.cpp"
#include <vector>

class core {
public:
    // buffer rx_buffer;
    // buffer tx_buffer;
    std::vector<node> node_list;


    // rx_buffer.write_buffer(test_string);

    char* get_buffer_str(buffer& _buf) {
        char* popped_str = _buf.pop_buffer();
        std::cout << "core : popped buffer str" << std::endl;
        return popped_str;
    }

    void buffer_to_node_msg (buffer& _buf, node& _node) {
        char* tmp_str = _buf.pop_buffer();
        
        if (tmp_str == nullptr || strlen(tmp_str) < 3) {
            return; // 유효하지 않은 문자열
        }
        
        char tmp_id[4] = {0};  // null terminator 포함
        char tmp_dir;
        char tmp_pur;
        char tmp_pay[60] = {0}; // null terminator 포함
        
        int str_len = strlen(tmp_str);

        // id (3 byte)
        for (int i = 0; i < 3 && i < str_len; i++) {
            tmp_id[i] = tmp_str[i];
        }
        tmp_id[3] = '\0';
        
        // direction (4th byte)
        if (str_len > 3) {
            tmp_dir = tmp_str[3];
        }
        
        // purpose (5th byte)  
        if (str_len > 4) {
            tmp_pur = tmp_str[4];
        }
        
        // payload (left)
        if (str_len > 5) {
            int payload_len = str_len - 5;
            if (payload_len > 59) payload_len = 59; 
            
            for (int i = 0; i < payload_len; i++) {
                tmp_pay[i] = tmp_str[5 + i];
            }
            tmp_pay[payload_len] = '\0';
        }
        
        msg new_msg;
        new_msg.set_id(tmp_id);
        new_msg.set_direction(tmp_dir);
        new_msg.set_purpose(tmp_pur);
        new_msg.set_payload(tmp_pay);
        
        _node.set_msg(new_msg);
    }

};

#endif