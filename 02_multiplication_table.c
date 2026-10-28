#include <stdio.h>

void write_multiplication_table(void);

int main() {

    write_multiplication_table();

    return 0;
}

void write_multiplication_table(void) {
    FILE* fp = fopen("table.txt", "w");
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            fprintf(fp, "%4d", i * j);
        }
        fprintf(fp, "\n");
        
    }

    fclose(fp);
    
}