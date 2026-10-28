#include <stdio.h>

void calculate_number_statistics(void);

int main() {

    calculate_number_statistics();

    return 0;
}

void calculate_number_statistics() {
    int buffer;
    int read_bytes;
    int count = 0;
    int sum = 0;
    int max;
    int min;
    FILE* fp = fopen("numbers.txt", "r");
    

    while ((read_bytes = fscanf(fp, "%d", &buffer)) == 1) {
        count++;
        sum += buffer;

        if (count == 1) {
            max = buffer;
            min = buffer;
        } else {
          if (buffer > max) {
            max = buffer;
          }

          if (buffer < min) {
            min = buffer;
          }
          
        }

    }

    double average = (double)sum / count;
    fprintf(stdout, "count = %d\n sum = %d\n max = %d\n min = %d\n average = %.2f\n", count, sum, max, min, average);
    fclose(fp);

}
