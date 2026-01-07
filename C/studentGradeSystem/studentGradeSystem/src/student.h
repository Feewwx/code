#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_CLASS_LEN 20
#define NUM_COURSES 3

typedef struct {
    char id[20];           
    char name[MAX_NAME_LEN]; 
    char gender[10];      
    int age;              
    char className[MAX_CLASS_LEN];
    float scores[NUM_COURSES];
} Student;

extern Student students[MAX_STUDENTS];
extern int studentCount;

void showMenu();
void addStudent();
void batchAddStudents();
void queryStudent();
void modifyStudent();
void deleteStudent();
void statisticsAnalysis();
void displayStudent(Student s);
int findStudentById(char id[]);
int validateStudentData(Student s);

#endif
