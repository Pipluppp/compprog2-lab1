#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define N 60

typedef struct 
{
    char name[N];
    char book_title[N];
    char book_author[N];
    int days_borrowed;
    int fine;
} borrow;

borrow *make_borrow_instance(void);
bool is_borrow_valid(borrow *instance);
void print_lib_borrows(borrow *library[10]);

    
borrow *library_borrows[10];

int main(void)
{    
    // NULL safety of pointers
    for (int i = 0; i < 10; i++)
        library_borrows[i] = NULL;

    int i = 0;
    while (library_borrows[i] == NULL && i < 10)
    {
        library_borrows[i] = make_borrow_instance();

        if (library_borrows[i] != NULL)
        {
            i++;
        }

        // Another pass of the program
        printf("Will someone borrow again? (Yes - 1, No - 0)");
        int check;
        scanf("%d", &check);

        if (!check)
            break;
        
    }
    
    print_lib_borrows(library_borrows);
}


borrow *make_borrow_instance(void)
{
    borrow *ptr = malloc(sizeof(borrow));

    printf("Borrow something:\n");

    // Name of borrower
    printf("What's your name? ");
    fgets(ptr->name, N, stdin);
    ptr->name[strlen(ptr->name) - 1] = 0;

    // Book to borrow
    printf("What's the book you'll borrow? ");
    fgets(ptr->book_title, N, stdin);
    ptr->book_title[strlen(ptr->book_title) - 1] = 0;

    // Book author
    printf("Who's the book author? ");
    fgets(ptr->book_author, N, stdin);
    ptr->book_author[strlen(ptr->book_author) - 1] = 0;

    // Days you've borrowed
    printf("How long borrow? ");
    scanf("%d", &ptr->days_borrowed);
    getchar();

    // Calculate fine
    ptr->fine = 0;
    int days = ptr->days_borrowed;
    if (days > 3)
        ptr->fine = 5 * (days - 3);

    // Check if the borrow is valid
    if (is_borrow_valid(ptr))
    {
        printf("Thank you, borrow success!");
        return ptr;
    }

    free(ptr);
    return NULL;
}

bool is_borrow_valid(borrow *instance)
{
    // Check if borrewer had already borrowed
    printf("Enters is_borrow_valid\n");
    for (int i = 1; library_borrows[i] != NULL; i++)
    {
        if (strcmp(library_borrows[i]->name, instance->name) == 0)
        {
            printf("You've borrowed already!");
            return false;
        }
    }

    return true;
}

void print_lib_borrows(borrow *library[10])
{
    for (int i = 0; i < 10; i++)
    {
        borrow *borrower = library[i];

        printf("Borrower %d is:\n", i + 1);
        printf("Name: %s\n", borrower->name);
        printf("Book title: %s\n", borrower->book_title);
        printf("Book author: %s\n", borrower->book_author);
        printf("Days borrowed: %d\n", borrower->days_borrowed);
        printf("Fine is: %d\n", borrower->fine);
    }
    
}