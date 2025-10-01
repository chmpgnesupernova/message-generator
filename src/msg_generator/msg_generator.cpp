#include "../hdr/msg.h"
#include "functions/functions.cpp"



int main(){
    
    char buffer[64];

    msg test_msg;
    test_msg.set_id('1');

    pack_attach_accept(test_msg, buffer);
    std::cout << buffer << std::endl;

    pack_attach_request(test_msg, buffer);
    std::cout << buffer << std::endl;
}