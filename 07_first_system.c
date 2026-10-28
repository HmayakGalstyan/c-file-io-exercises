#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 100

void first_system_calls(int fd);

int main() {
    int fd = open("hello.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    first_system_calls(fd);
    close(fd);

    return 0;
}

void first_system_calls(int fd) {
    char buffer[] ="Line one\n""Line two\n""Line three\n";
    ssize_t write_bytes = write(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    fd = open("hello.txt", O_RDONLY);
    char buff[BUFF_SIZE];
    ssize_t read_bytes;
    while ((read_bytes = read(fd, buff, sizeof(buff))) > 0) {
        printf("Read bytes %zd \n", read_bytes);
        write(STDOUT_FILENO, buff, read_bytes);
    }

}

