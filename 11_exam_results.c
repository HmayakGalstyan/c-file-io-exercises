#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    FILE* fp = fopen("results.csv", "r");
    FILE* pass = fopen("passed.txt", "w");
    FILE* fail = fopen("failed.txt", "w");

    char name[100];
    int score;
    int passCount = 0;
    int failCount = 0;
    int maxScore = 0;
    char maxScoreName[15];

    while ((fscanf(fp, " %99[^,],%d", name, &score)) == 2) {
       if (score >= 50) {
        fprintf(pass, "%s,%d\n", name, score);
        passCount++;
       } else if (score <= 50) {
        fprintf(fail, "%s,%d\n", name, score);
        failCount++;
       }

       if (score >= maxScore) {
        maxScore = score;
        strcpy(maxScoreName, name);
       }
       
       
    }

    fprintf(stdout, "passed = %d\nfailed = %d\nmaximum score = %s (%d)\n", passCount, failCount, maxScoreName, maxScore);
    


    return 0;
}

