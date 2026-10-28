#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFF_SIZE 1024

void check_creator(FILE* fp);

int main() {
    FILE* fp = fopen("shop.txt", "r");
    check_creator(fp);
    fclose(fp);

    return 0;
}

void check_creator(FILE* fp) {
    char buffer[BUFF_SIZE];
    char name[128];
    int count;
    int price;
    int itemTotal;
    int totalPrice = 0;
    int discount = 0;
    int amount_to_pay = 0;
    int size;

    int fd = open("receipt.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    while(fscanf(fp, "%99s %d %d", name, &count, &price) == 3) {
        itemTotal = price * count;
        size = snprintf(buffer, sizeof(buffer), "%-12s %3d x %5d = %6d\n", name, count, price, itemTotal);
        write(fd, buffer, size);
        totalPrice += itemTotal;
        //fprintf(stdout, "%-12s %3d x %5d = %6d\n", name, count, price, itemTotal);
    }

    size = snprintf(buffer, sizeof(buffer), "------------------------------\nԸնդհանուր՝ %d դրամ\n", totalPrice);
    write(fd, buffer, size);
    if (totalPrice > 10000) {
       discount = totalPrice * 10 / 100;
       amount_to_pay = totalPrice - discount;
       size = snprintf(buffer, sizeof(buffer), "Զեղչ 10%%՝ %d դրամ\n", discount);
       write(fd, buffer, size);
    } else {
       amount_to_pay = totalPrice;
    }

    size = snprintf(buffer, sizeof(buffer), "Վճարման ենթակա՝ %d դրամ\n", amount_to_pay);
    write(fd, buffer, size);
    close(fd);

}