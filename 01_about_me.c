#include <stdio.h>

void write_user_info(char name[], int age, char city[]);
void read_user_info();

int main() {
    char name[16];
    int age;
    char city[16];

    printf("NAME = ");
    scanf("%15s", name);

    printf("AGE = ");
    scanf("%d", &age);

    printf("CITY = ");
    scanf("%15s", city);

    write_user_info(name, age, city);
    read_user_info();

    return 0;
}

void write_user_info(char name[], int age, char city[]) {
    FILE* fp = fopen("about_me.txt", "w");
    fprintf(fp, "name = %s\n age = %d\n city = %s\n", name, age, city);
    fclose(fp);
}

void read_user_info() {
    FILE* fp = fopen("about_me.txt", "r");
    char buffer[128];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);

}