#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* fp = fopen("text.txt", "r");
    FILE* fp2 = fopen("censored.txt", "w");
    
    int ch;
    int count = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (toupper(ch) == 'A' || toupper(ch) == 'E' || toupper(ch) == 'I' || toupper(ch) == 'O' || toupper(ch) == 'U') {
            ch = '*';
            count++;
        }
        fputc(ch, fp2);
    }

    printf("Փոխարինվեց %d ձայնավոր", count);
    
    return 0;
}

