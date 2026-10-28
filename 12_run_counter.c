#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int visit = 0;
    FILE* fp = fopen("visit.txt", "r");

    if (fp != NULL) {
       fscanf(fp, "%d", &visit);
       fclose(fp);
    }
    
    visit++;
    fp = fopen("visit.txt", "w");
    fprintf(fp, "%d", visit);

    if (visit == 1) {
        printf("Բարի գալուստ։ Սա ձեր առաջին այցն է։\n");
    } else {
        printf("Դուք այստեղ եք %d-րդ անգամ:\n", visit);
    }

    fclose(fp);

    int fd = open("runs.log", O_WRONLY | O_CREAT | O_APPEND, 0664);
    pid_t pid = getpid();
    char buffer[100];
    int size = sprintf(buffer, "Run %d, Pid %d\n", visit, pid);
    write(fd, buffer, size);

    close(fd);
    return 0;
}