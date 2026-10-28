#include <stdio.h>

typedef struct {
    char name[50];
    double grade;
} Student;

void printscan(Student *student, FILE* fp);

int main() {
    Student student;
    FILE* fp = fopen("grades.txt", "w");
    printscan(&student, fp);

    fclose(fp);

    fp = fopen("grades.txt", "r");

    double maxGrade = 0;
    int studentCount = 0;
    char maxGradeName[200];
    double averageGrade = 0;

    while (fscanf(fp, "%s %lf", student.name, &student.grade) == 2) {
        if (student.grade > maxGrade) {
            maxGrade = student.grade;
            snprintf(maxGradeName, sizeof(maxGradeName), "%s", student.name);   
        }
        studentCount++;
        averageGrade += student.grade;
        
    }

    averageGrade = averageGrade / studentCount;
    fprintf(stdout, "Միջին գնահատական՝ %.2lf Լավագույն ուսանող՝ %s (%.0lf)\n", averageGrade, maxGradeName, maxGrade);
    fclose(fp);
    

    return 0;
}

void printscan(Student *student, FILE* fp) {
    for (int i = 1; i <= 5; i++) {
        printf("Please enter the %d student name\n", i);
        scanf("%s", student->name);
        printf("Please enter the %d student grade(0 - 100)\n", i);
        scanf("%lf", &student->grade);
        while (student->grade < 0 || student->grade > 100) {
           printf("wrong grade please enter the number 0-100\n");
           scanf("%lf", &student->grade);
        }
        fprintf(fp, "%s %lf\n", student->name, student->grade);
    }
}