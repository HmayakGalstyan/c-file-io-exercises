#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char fName[255];
    printf("Please enter the file name: ");
    scanf("%255s", fName);

    int fd = open(fName, O_RDONLY);
    
    if (fd == -1) {
        perror("open");
        return 1;
    }

    int fSize = lseek(fd, 0, SEEK_END) - 1;
    lseek(fd, 0, SEEK_SET);
    char buffer[255];
    
    int i = 0;
    printf("Ֆայլի չափը՝ %d բայթ\n", fSize);
    while (read(fd, buffer, 1) != '\n') {
        if (buffer[i] == '\n') {
          break;
        }
        fprintf(stdout, "%s", buffer);
    }
    printf("\n");
    

    
    
    




    return 0;
}

