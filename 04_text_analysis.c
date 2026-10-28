#include <stdio.h>

void analyze_text(void);

int main() {
    
    analyze_text();
    return 0;
}

void analyze_text(void) {
   FILE* fp = fopen("text.txt", "r");

   int uppercase = 0;
   int lowercase = 0;
   int num = 0;
   int space = 0;
   int line = 0;
   int byteCount = 0;
   int ch;
   while ((ch = fgetc(fp)) != EOF) {
    if (ch >= 'A' && ch <= 'Z') {
     uppercase++;
   } else if (ch >= 'a' && ch <= 'z') {
     lowercase++;
   } else if (ch >= '0' && ch <= '9') {
     num++;
   } else if (ch == 32) {
     space++;
   } else if (ch == 10) {
     line++;
   }

   }
   
   byteCount = uppercase + lowercase + num + space + line;
   fprintf(
    stdout, 
    "uppercase = %d\n lowercase = %d\n num = %d\n scope = %d\n line = %d\n bytecount = %d\n", 
    uppercase, lowercase, num, space, line, byteCount
   );
   fclose(fp);
   
}