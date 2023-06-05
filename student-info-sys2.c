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

    // Set pointers to NULL for safety
    for (int i = 0; i < CLASS_SIZE; i++)
        class[i] = NULL;

    // Input student information
    int i = 0;
    while (i < 10)
    {
        printf("Input a student's information:");        
        class[i] = make_student();


        // Ask if add another student
        int check;
        printf("Add another student? (Yes - 1, No - 0) ");
        scanf("%d", &check);
        getchar();

        if (check == 0)
            break;

        i++;
    }

    // Print students
    printf("\n\nTHE STUDENTS ARE:");
    for (int i = 0; class[i] != NULL; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        print_student(*class[i]);
    }
}


student *make_student(void)
{
    // Create an instance of struct, and set pointer to it
    student *ptr = malloc(sizeof(student));
    
    // Get name
    printf("\nInput name: ");
    fgets(ptr->name, N, stdin);
    ptr->name[strlen(ptr->name) - 1] = 0;
    
    // Get student number
    printf("Input student number: ");
    fgets(ptr->number, N, stdin);
    ptr->number[strlen(ptr->number) - 1] = 0;
    
    // Get course
    printf("Input course: ");
    fgets(ptr->course, N, stdin);
    ptr->course[strlen(ptr->course) - 1] = 0;

    // Get age
    printf("Input age: ");
    scanf("%d", &ptr->age);
    getchar();
    
    // Get year
    printf("Input year: ");
    scanf("%d", &ptr->year);
    getchar();
    
    return ptr;
}

void print_student(student person)
{   
    printf("Student name: %s\n", person.name);
    printf("Student number: %s\n", person.number);
    printf("Student course: %s\n", person.course);
    printf("Student year: %d\n", person.year);
    printf("Student age: %d\n", person.age);

}