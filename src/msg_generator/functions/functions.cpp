#include "../../hdr/msg.h"


//*************universal funtions *************/
char* msg_to_string (const char* _string) {
    

}


//*************handle buffer ******************/

bool is_buffer_clear (const char* _buffer) {
    return _buffer[0] == '\0';
}

bool is_buffer_full (const char* _buffer) {
    // if (_buffer[63] == '\n') { return true; }
    // else { return false; }
    return strlen(_buffer) >= 63;
}

void clear_buffer (char* _buffer) {
    char* tmp_ptr = _buffer;
    while (*tmp_ptr != '\0') {
        *tmp_ptr = '0';
        tmp_ptr++;
    }
    _buffer[0] = '\0';
}

//***********packing message ****************/

void pack_attach_request (msg _msg, char* _buffer){
    if (is_buffer_full(_buffer) == true || is_buffer_clear(_buffer) == false) { 
        clear_buffer(_buffer);
    }

    char* tmp_ptr = _buffer;
    *tmp_ptr = _msg.get_id();
    tmp_ptr++;

    *tmp_ptr = UL;
    tmp_ptr++;

    *tmp_ptr = ATTACH_REQUEST;
    tmp_ptr++;

    *tmp_ptr = '\0';
}

void pack_attach_accept (msg _msg, char* _buffer){
    if (is_buffer_full(_buffer) == true || is_buffer_clear(_buffer) == false) { 
        clear_buffer(_buffer);
    }

    char* tmp_ptr = _buffer;
    *tmp_ptr = _msg.get_id();
    tmp_ptr++;

    *tmp_ptr = DL;
    tmp_ptr++;

    *tmp_ptr = ATTACH_ACCEPT;
    tmp_ptr++;

    *tmp_ptr = '\0';
}

void pack_attach_decline (const msg _msg, char* _buffer){
    if (is_buffer_full(_buffer) == true || is_buffer_clear(_buffer) == false) { 
        clear_buffer(_buffer);
    }

    char* tmp_ptr = _buffer;
    *tmp_ptr = _msg.get_id();
    tmp_ptr++;

    *tmp_ptr = DL;
    tmp_ptr++;

    *tmp_ptr = ATTACH_DECLINE;
    tmp_ptr++;

    *tmp_ptr = '\0';
}

void pack_general_msg (const msg _msg, char* _buffer, char* _payload) {
    if (is_buffer_full(_buffer) == true || is_buffer_clear(_buffer) == false) { 
        clear_buffer(_buffer);
    }

    char* tmp_ptr = _buffer;
    *tmp_ptr = _msg.get_id();
    tmp_ptr++;

    *tmp_ptr = DL;
    tmp_ptr++;

    *tmp_ptr = GENERAL_MSG;
    tmp_ptr++;

    while (*_payload != '\0') {
        *tmp_ptr = *_payload;
        tmp_ptr++;
    }
    *tmp_ptr = '\0';
}



