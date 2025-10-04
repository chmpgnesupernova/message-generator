#include "hdr.h"
#include "core.cpp"
#include "node.cpp"

int main(){
    buffer rx_buffer;
    buffer tx_buffer;
    node node1("ad1","1234567890");

    char* test_str = "ad1u1234567890";
    core coresystem;
    rx_buffer.write_buffer(test_str);
    rx_buffer.print();

    coresystem.buffer_to_node_msg(rx_buffer, node1);
    node1.print_msg();
    std::cout << node1.get_id();
    std::cout << node1.get_key();
    std::cout << node1.is_online();

}