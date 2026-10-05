#include <stdio.h>
#include <stdlib.h>

/* Enumeration */
enum Status
{
    REGULAR = 1,
    LATERAL_ENTRY
};

/* Union */
union Contact
{
    long phone;
    char email[30];
};

/* Structure */
struct Student
{
    int rollNo;
    char name[30];
    float cgpa;

    enum Status status;
    union Contact contact;

    int contactType;   /* 1 = Phone, 2 = Email */
};

/* Function declarations */
void readStudents(struct Student *s, int n);
void displayStudents(struct Student *s, int n);

int main()
{
    struct Student *s;
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    /* Dynamic memory allocation */
    s = (struct Student *)malloc(n * sizeof(struct Student));

    if (s == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    /* Read student details */
    readStudents(s, n);

    /* Display student details */
    displayStudents(s, n);

    /* Release memory */
    free(s);

    return 0;
}

/* Function to read student details */
void readStudents(struct Student *s, int n)
{
    int i;
    int choice;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &(s + i)->rollNo);

        printf("Name: ");
        scanf("%s", (s + i)->name);

        printf("CGPA (0-10): ");
        scanf("%f", &(s + i)->cgpa);

        /* Enumeration */
        printf("Status (1-Regular, 2-Lateral Entry): ");
        scanf("%d", &choice);

        if (choice == 1)
            (s + i)->status = REGULAR;
        else
            (s + i)->status = LATERAL_ENTRY;

        /* Union */
        printf("\nChoose Contact Type:\n");
        printf("1. Phone Number\n");
        printf("2. Email\n");
        printf("Enter choice: ");
        scanf("%d", &(s + i)->contactType);

        if ((s + i)->contactType == 1)
        {
            printf("Enter Phone Number: ");
            scanf("%ld", &(s + i)->contact.phone);
        }
        else
        {
            printf("Enter Email: ");
            scanf("%s", (s + i)->contact.email);
        }
    }
}

/* Function to display student details */
void displayStudents(struct Student *s, int n)
{
    int i;

    printf("\n\n========== STUDENT RECORDS ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Roll Number: %d\n", (s + i)->rollNo);
        printf("Name: %s\n", (s + i)->name);
        printf("CGPA: %.2f\n", (s + i)->cgpa);

        /* Display Enumeration */
        if ((s + i)->status == REGULAR)
            printf("Status: Regular\n");
        else
            printf("Status: Lateral Entry\n");

        /* Display Union */
        if ((s + i)->contactType == 1)
            printf("Phone: %ld\n", (s + i)->contact.phone);
        else
            printf("Email: %s\n", (s + i)->contact.email);
    }
}

