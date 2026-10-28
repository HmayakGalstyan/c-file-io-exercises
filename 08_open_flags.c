#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void readFunction(void);
void writeFunction(int fd);
void resetFile(void);

int main(void) {
    int fd;

    resetFile();
    fd = open("test.txt", O_WRONLY);
    writeFunction(fd);
    close(fd);
    readFunction();

    resetFile();
    fd = open("test.txt", O_WRONLY | O_APPEND);
    writeFunction(fd);
    close(fd);
    readFunction();

    resetFile();
    fd = open("test.txt", O_WRONLY | O_TRUNC);
    writeFunction(fd);
    close(fd);
    readFunction();

    fd = open("test.txt", O_WRONLY | O_CREAT | O_EXCL, 0644);
    perror("O_CREAT | O_EXCL");

    return 0;
}

void readFunction(void) {
    int fd = open("test.txt", O_RDONLY);
    char buffer[100];

    ssize_t bytes = read(fd, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, bytes);
    write(STDOUT_FILENO, "\n", 1);

    close(fd);
}

void writeFunction(int fd) {
    write(fd, "abc", 3);
}

void resetFile(void) {
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buff[] = "HELLO WORLD";

    write(fd, buff, sizeof(buff) - 1);
    close(fd);
}