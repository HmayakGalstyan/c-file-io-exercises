#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int encrypt_decrypt(int input, int output, int key);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        return 1;
    }

    int input = open(argv[1], O_RDONLY);
    int output = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (input == -1 || output == -1) {
      perror("open");
    }
    
    int key = (int)argv[3];
    encrypt_decrypt(input, output, key);

    close(input);
    close(output);
    

    return 0;
}

int encrypt_decrypt(int input, int output, int key) {
    char buffer[64];
    ssize_t read_bytes;
    while ((read_bytes = read(input, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < read_bytes; i++) {
            buffer[i] ^= key;
        }

        if (write(output, buffer, read_bytes) != read_bytes) {
            perror("write");
            return 1;
        }
    }
    
    return read_bytes == -1 ? 1 : 0;
}