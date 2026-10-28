#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct {
    int id;
    char title[64];
    int year;
    
} Book;


int main() {
    int size = 5;
    long bookNum;
    Book books[5] = {
       {1, "Clean Code", 2008},
       {2, "Linux Kernel", 2005},
       {3, "C Programming", 1978},
       {4, "Algorithms", 2009},
       {5, "Computer Systems", 2015}
    };

    FILE* fp = fopen("books.dat", "wb");
    fwrite(books, sizeof(Book), size, fp);
    fclose(fp);
                   
    printf("Please enter the number 0-4: ");
    scanf("%ld", &bookNum);
    fp = fopen("books.dat", "r+b");
    fseek(fp, bookNum * sizeof(Book), SEEK_SET);
    Book book;
    fread(&book, sizeof(Book), 1, fp);

    
    int newYear;
    printf("Please enter new year: ");
    scanf("%d", &newYear);
    book.year = newYear;
    fseek(fp, bookNum * sizeof(Book), SEEK_SET);
    fwrite(&book, sizeof(Book), 1, fp);

    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < size; i++) {
      fread(&book, sizeof(Book), 1, fp);
      
      fprintf(stdout, "ID: %d, Title: %s, Year: %d\n",
        book.id, book.title, book.year);
    }

    fclose(fp);

    return 0;
}