/* 
Specifications:
- Record of each student in BSCS 1-1N
- Set common information (e.g., student number, name, course, year level), but not too invasive information
- Roughly a maximum of 10 students

TODO:
- Struct data structure for the student
- Function for receiving manual inputs for student information, and receiving files containing student information

 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 60
#define CLASS_SIZE 10

typedef struct student
{
    char name[N];
    char number[N];
    char course[N];
    int year;
    int age;
} student;

void print_student(student person);
student *make_student(void);


int main(void)
{
    student *class[CLASS_SIZE];

    // Input student information
    for (int i = 0; i < CLASS_SIZE; i++)
        class[i] = make_student();

    // Print students
    for (int i = 0; i < CLASS_SIZE; i++)
        print_student(*class[i]);
}


student *make_student(void)
{
    student *ptr = malloc(sizeof(student));

    strncpy(ptr->name, "Goo goo Gaa gaa", N);
    strncpy(ptr->number, "2022-GGLODS", N);
    strncpy(ptr->course, "BSCS", N);
    ptr->year = 1969;
    ptr->age = 69;

    return ptr;
}

void print_student(student person)
{
    printf("Student name: %s\n", person.name);
    printf("Student number: %s\n", person.number);
    printf("Student course: %s\n", person.course);
    printf("Student year: %d\n", person.year);
    printf("Student age: %d\n\n", person.age);

}