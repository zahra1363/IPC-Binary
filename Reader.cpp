#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <bitset>

int main()
{

    // Open the named pipe for reading
    int fd = open("mypipe", O_RDONLY);

    if (fd == -1)
    {
        perror("Failed to open named pipe");
        return 1;
    }

    // Read the binary data from the named pipe
    char binary_buffer[256];
    ssize_t binary_size = read(fd, binary_buffer, 256);

    if (binary_size == -1)
    {
        perror("Failed to read from named pipe");
        close(fd);
        return 1;
    }

    // Print the binary data to the console
    std::cout << "Binary data received: ";
    for (int i = 0; i < binary_size; i++)
    {
        std::cout << (binary_buffer[i]) << " ";
    }
    std::cout << std::endl;

    // converting char array to equivalent integer
    std::cout << " the integer value of the binary number is: ";
    std::string binary_string(binary_buffer);    // Convert the char array to a std::string
    std::bitset<8> binary_number(binary_string); // Convert the binary string to a binary number using std::bitset

    std::cout << binary_number.to_ulong();
    std::cout << std::endl;

    // Close the named pipe
    close(fd);

    return 0;
}