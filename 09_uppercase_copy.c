#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#define BUFF_SIZE 64

int main() {
    int fd = open("input.txt", O_RDONLY);
    int fd2 = open("upper.txt", O_RDWR | O_CREAT | O_TRUNC, 0664);
    if (fd == -1 || fd2 == -1) {
        perror("open");
        return -1;
    }
    
    char buffer[BUFF_SIZE];
    ssize_t read_bytes;
    ssize_t total_reads = 0;
    int i = 0;
    int changeWords = 0;

    while ((read_bytes = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < read_bytes; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                changeWords++;
                buffer[i] = toupper(buffer[i]);
            }
        }
        
        ssize_t write_bytes = write(fd2, buffer, read_bytes);
        total_reads += read_bytes;
    }

    printf("Change words = %d, Read bytes = %zd\n upper.txt`\n ", changeWords, total_reads);
    lseek(fd2, 0, SEEK_SET);
    while ((read_bytes = read(fd2, buffer, sizeof(buffer))) > 0) {
      write(STDOUT_FILENO, buffer, read_bytes);
      printf("\n");
    }

    close(fd);
    close(fd2);
    

    
    return 0;
}


