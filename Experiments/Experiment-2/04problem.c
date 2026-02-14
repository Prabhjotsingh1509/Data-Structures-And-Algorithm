// Write a menu-Driven Program to manage student records using a linked lists.Each record should store roll number, name,and marks.Perform the following.
/*
    add student record
    delete a record

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
typedef struct Student
{
    int rollNo;
    char name[50];
    float marks;
    struct Student *next;
} Student;

// Function to create a new student node
Student *createStudent(int rollNo, char name[], float marks)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student at the end of the list
void addStudent(Student **head)
{
    int rollNo;
    char name[50];
    float marks;

    printf("Enter Roll Number: ");
    scanf("%d", &rollNo);
    getchar(); // consume newline
    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // remove newline
    printf("Enter Marks: ");
    scanf("%f", &marks);

    Student *newStudent = createStudent(rollNo, name, marks);

    if (*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        Student *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
    printf("Student added successfully!\n");
}

// Function to delete a student by roll number
void deleteStudent(Student **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int rollNo;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNo);

    Student *temp = *head;
    Student *prev = NULL;

    while (temp != NULL && temp->rollNo != rollNo)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student with roll number %d not found.\n", rollNo);
        return;
    }

    if (prev == NULL)
    {
        // Deleting head
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Student record deleted successfully!\n");
}

// Function to display all student records
void displayStudents(Student *head)
{
    if (head == NULL)
    {
        printf("No student records.\n");
        return;
    }

    printf("RollNo\tName\tMarks\n");
    printf("----------------------------\n");
    Student *temp = head;
    while (temp != NULL)
    {
        printf("%d\t%s\t%.2f\n", temp->rollNo, temp->name, temp->marks);
        temp = temp->next;
    }
}

// Menu-driven function
int main()
{
    Student *head = NULL;
    int choice;

    do
    {
        printf("\n--- Student Record Menu ---\n");
        printf("1. Add Student Record\n");
        printf("2. Delete Student Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(&head);
            break;
        case 2:
            deleteStudent(&head);
            break;
        case 3:
            displayStudents(head);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    // Free all remaining nodes
    Student *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}