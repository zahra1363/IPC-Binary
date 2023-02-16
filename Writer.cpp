#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
# include <sys/stat.h>

int main() {

      char * mypipe = (char*)"/home/solmaz/Documents/intership c++ code/myfifo";// Change to your desired pipe name
    int ret = mkfifo(mypipe, 0666);  

    

    // Get binary input from the user
    std::string binary;
    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    // Convert the binary string to a binary buffer
    size_t binary_size = binary.size();
    char binary_buffer[binary_size + 1];
    std::strcpy(binary_buffer, binary.c_str());

    // Open the named pipe for writing
    int fd = open("mypipe", O_WRONLY);

    if (fd == -1) {
        perror("Failed to open named pipe");
        return 1;
    }

    // Write the binary buffer to the named pipe
    write(fd, binary_buffer, binary_size + 1);

    // Close the named pipe
    close(fd);
    std::cout << binary_buffer << std::endl;
    return 0;
}