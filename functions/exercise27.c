#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidName(const char *name) {
    return strlen(name) >= 2;
}

int isValidID(const char *id) {
    return isalpha(id[0]) && isalpha(id[1]) && id[2] == '-' && isdigit(id[3]) && isdigit(id[4]) && isdigit(id[5]) && isdigit(id[6]);
}

int isValidZIP(const char *zip) {
    for (int i = 0; zip[i] != '\0'; i++)
        if (!isdigit(zip[i])) return 0;
    return 1;
}

int main() {
    char firstName[50], lastName[50], employeeID[10], zip[10];

    printf("Enter the first name: ");
    scanf("%s", firstName);
    printf("Enter the last name: ");
    scanf("%s", lastName);
    printf("Enter the ZIP code: ");
    scanf("%s", zip);
    printf("Enter an employee ID (AA-1234): ");
    scanf("%s", employeeID);

    if (!isValidName(firstName)) printf("First name must be at least 2 characters long.\n");
    if (!isValidName(lastName)) printf("Last name must be at least 2 characters long.\n");
    if (!isValidZIP(zip)) printf("ZIP code must be numeric.\n");
    if (!isValidID(employeeID)) printf("Employee ID must be in the format AA-1234.\n");

    return 0;
}

