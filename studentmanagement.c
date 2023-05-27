#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student
{
    int rollNumber;
    char name[50];
    
    char address[100];
    char phoneNumber[20];
    char parentsName[50];
};

struct Student students[MAX_STUDENTS];
int count = 0;

void addStudent()
{
    if (count >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached.\n");
        return;
    }

    struct Student student;
    printf("Enter Roll Number: ");
    scanf("%d", &student.rollNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", student.name);

    

    printf("Enter Address: ");
    scanf(" %[^\n]", student.address);

    printf("Enter Phone Number: ");
    scanf(" %[^\n]", student.phoneNumber);

    printf("Enter Parents' Name: ");
    scanf(" %[^\n]", student.parentsName);

    students[count++] = student;
    printf("Student added successfully.\n");
}

void displayStudents()
{
    if (count == 0)
    {
        printf("No students to display.\n");
        return;
    }

    printf("Roll Number\tName\t\tAddress\t\tPhone Number\tParents' Name\n");
    printf("----------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t\t%s\t%s\t%s\t%s\n", students[i].rollNumber, students[i].name, 
               students[i].address, students[i].phoneNumber, students[i].parentsName);
    }
}

int findStudent(int rollNumber)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNumber == rollNumber)
        {
            return i;
        }
    }
    return 1;
}

void updateStudent()
{
    int rollNumber;
    printf("Enter Roll Number of student to update: ");
    scanf("%d", &rollNumber);

    int index = findStudent(rollNumber);
    if (index == -1)
    {
        printf("Student with Roll Number %d not found.\n", rollNumber);
        return;
    }

    printf("Enter New Name: ");
    scanf(" %[^\n]", students[index].name);

    

    printf("Student information updated successfully.\n");
}

void deleteStudent()
{
    int rollNumber;
    printf("Enter Roll Number of student to delete: ");
    scanf("%d", &rollNumber);

    int index = findStudent(rollNumber);
    if (index == -1)
    {
        printf("Student with Roll Number %d not found.\n", rollNumber);
        return;
    }

    // Move all the students after the deleted student one position up
    for (int i = index; i < count - 1; i++)
    {
        students[i] = students[i + 1];
    }
    count--;

    printf("Student deleted successfully.\n");
}

void displayMenu()
{
    printf("\nStudent Record Management System\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Update Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;

    while (1)
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            printf("Thank you for using the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
