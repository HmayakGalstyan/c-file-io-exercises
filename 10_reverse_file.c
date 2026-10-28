#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("input.txt", O_RDONLY);
    int fd2 = open("reversed.txt", O_WRONLY);

    off_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    char buff;

    for (int i = size - 1; i >= 0; i--) {
        lseek(fd, i, SEEK_SET);
        int read_bytes = read(fd, &buff, 1);
        write(fd2, &buff, 1);
    }

    close(fd);
    close(fd2);

}