#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 1024

int my_grep(FILE *fp, const char *str);

int main(int argc, char *argv[]) {
    int file_start = 1;
    char *str;
  
    if (argc >= 3) {
        str = argv[1];
    } else if (argc < 3) {
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        FILE* fp = fopen(argv[i], "r");
        my_grep(fp, str);
        fclose(fp);
    }
    

    return 0;
}

int my_grep(FILE *fp, const char *str) {
    int line_number = 0;
    int matches = 0;
    char buffer[BUFF_SIZE];
    
    while((fgets(buffer, sizeof(buffer), fp)) != NULL) {
        line_number++;
        if (strstr(buffer, str) != NULL) {
            matches++;
            fprintf(stdout, "%d: %s", line_number, buffer);
        }
    }

    printf("Found in %d lines\n", matches);

    return 0;
}