/*
  Student Name: Yanal Abu Rahmeh
  Student ID: 1284819
  Due Date: March, 8, 2024
  Course: CIS*2500

  I have exclusive control over this submission via my password.
  By including this header comment, I certify that:
   1) I have read and understood the policy on academic integrity.
   2) I have completed Moodle's module on academic integrity.
   3) I have achieved at least 80% on the academic integrity quiz
  I assert that this work is my own. I have appropriate acknowledged
  any and all material that I have used, be it directly quoted or
  paraphrased. Furthermore, I certify that this assignment was written
  by me in its entirety.
*/

#include "../include/givenA2.h"
#define SIZE 200

int searchContacts(char *fileName, int keyId) // function to search for a contact based on their id
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    struct contact readContact;
    int empId;
    int matchFound = 0;

    char *data = malloc(SIZE * sizeof(char)); // allocate memory for data string
    if (!data)
    {
        printf("Memory allocation failed!\n"); // exit if memory can not be allocated
        fclose(file);
        return -1;
    }

    while (fread(&readContact, sizeof(struct contact), 1, file) == 1) // while there are still contacts left in the file
    {
        fseek(file, readContact.empIdPosn, SEEK_SET); // set position of file pointer to employee Id position
        fread(&empId, sizeof(empId), 1, file);        // read employee ID from file

        if (empId == keyId)
        {
            // Employee ID
            printf("\n");
            printf("****************************\n");
            printf("Employee Id: %d\n", empId);

            // First Name
            fseek(file, readContact.firstNamePosn, SEEK_SET);
            fscanf(file, "%[^\n]%*c", data); // For file input, consuming the newline
            printf("First Name: %s\n", data);

            // Last Name
            fseek(file, readContact.lastNamePosn, SEEK_SET);
            fscanf(file, "%[^\n]%*c", data); // For file input, consuming the newline
            printf("Last Name: %s\n", data);

            // Email
            fseek(file, readContact.emailPosn, SEEK_SET);
            fscanf(file, "%[^\n]%*c", data); // For file input, consuming the newline
            printf("Email: %s\n", data);
            printf("****************************\n");

            matchFound = 1; // employee is found
            break;          // Stop after finding the contact
        }

        // Move to the start of the next record
        fseek(file, readContact.next, SEEK_SET);
    }

    free(data); // free allocated memory for first name and last name
    fclose(file);
    return matchFound;
}
