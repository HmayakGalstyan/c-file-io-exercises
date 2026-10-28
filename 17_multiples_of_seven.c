#include <stdio.h>

int main() {
    FILE* fp = fopen("nums.txt", "w");
    int count = 0;
    int write_bytes;
    for (int i = 1; i <= 100; i++) {
        write_bytes = fprintf(fp, "%d\n", i);
    }
    fclose(fp);

    fp = fopen("nums.txt", "r");
    int numbers[100];
    for (int i = 1; i < 100; i++) {
        fscanf(fp, "%d", &numbers[i]);
        if (numbers[i] % 7 == 0) {
           count++;
           fprintf(stdout, "%d ", numbers[i]);     
        }
        
    }
    fprintf(stdout, "\nCount = %d\n", count);
    fclose(fp);


    return 0;
   
}