#include <stdio.h>
#include <stdlib.h>

int encrypt_decrypt(FILE *input, FILE *output, int key);

int main(int argc, char *argv[]) {
    
    if (argc < 4) {
        return 1;
    }

    
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    if (input == NULL || output == NULL) {
      perror("fopen");
    }
    
    int key = atoi(argv[3]);
    encrypt_decrypt(input, output, key);

    fclose(input);
    fclose(output);
    
    
    return 0;
}

int encrypt_decrypt(FILE* input, FILE* output, int key) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            int position = ch - 'A';
            position = (position + key % 26 + 26) % 26;
            ch = 'A' + position;
        } else if (ch >= 'a' && ch <= 'z') {
            int position = ch - 'a';
            position = (position + key % 26 + 26) % 26;
            ch = 'a' + position;
    }

        fputc(ch, output);
    }

    return 0;
}