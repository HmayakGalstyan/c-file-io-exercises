#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    FILE* fp = fopen("data.txt", "w");
    fprintf(fp, "5 12 8 3 20 7 15 1 9 10");
    fclose(fp);
    pid_t pid = fork();

    if (pid == -1) {
        perror("error\n");
        exit(1);
    } else if (pid == 0) {
        FILE *fp = fopen("data.txt", "r");
        char buffer[200];
        int number;

        fscanf(fp, "%d", &number);
        int max = number;
        int sum = number;
        while (fscanf(fp, "%d", &number) == 1) {
            sum += number;
            if (number > max) {
                max = number;
            }
        }

        int fd = open("results.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
        int len = snprintf(buffer, sizeof(buffer), "Երեխայի արդյունքը՝ Գումար՝ %d, Ամենամեծ՝ %d", sum, max);
        write(fd, buffer, len);

        fclose(fp);
        close(fd);

        exit(0);
    } else {
        int status;
        char str[256];
        pid_t chPid = wait(&status);
        FILE* fp2 = fopen("results.txt", "r");
        
        fgets(str, sizeof(str), fp2);
        
        printf("%s\n", str);
        fclose(fp2);
    }
    
}