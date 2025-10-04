// #include "hdr.h"

// class buffer {
// private:
//     int length = 0;
//     char buffer_array[64];

// public:
//     void clear() {
//         buffer_array[0] = '\0';
//         length = 0;
//         std::cout << "buffer : buffer cleared" << std::endl;
//     }

//     bool is_empty() {
//         if (buffer_array[0] == '\0' && length == 0) { 
//             return true; 
//         } else if (buffer_array[0] == '\0' != length == 0) { 
//             std::cout << "buffer error : buffer length worng!" << std::endl;
//             return  false;
//         } else {
//             return false;
//         }
//     }

//     void write_buffer(const char* str, int _len) {
//         if ( this -> is_empty() ) {
//             memcpy(buffer_array, str, _len);
//             buffer_array[63] = '\0';
//             length = _len;
//         } else { 
//             std::cout << "buffer error : buffer not clear" << std::endl;
//         }
//     }

//     const char* pop_buffer() {
//         const char* tmp = buffer_array;
//         this -> clear();
//         std::cout << "buffer : buffer popped" << std::endl;
//         return tmp;
//     }

//     int get_length() const {
//         std::cout << "buffer length : " << length << std::endl;
//         return length;
//     }

//     void print() const {
//         printf("Buffer: '%s' (length: %d)\n", buffer_array, (int)strlen(buffer_array));
//     }
// };
