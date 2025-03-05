#include <stdio.h>
#include <string.h>

typedef struct {
    char firstName[20];
    char lastName[20];
    char position[30];
    char separationDate[15];
} Employee;

void searchEmployees(Employee employees[], int size, char *query) {
    printf("\nResults:\n");
    printf("Name                 | Position          | Separation Date\n");
    printf("---------------------|------------------|----------------\n");

    for (int i = 0; i < size; i++) {
        if (strcasestr(employees[i].firstName, query) || strcasestr(employees[i].lastName, query)) {
            printf("%-10s %-10s | %-17s | %-15s\n",
                   employees[i].firstName, employees[i].lastName,
                   employees[i].position, employees[i].separationDate);
        }
    }
}

int main() {
    Employee employees[] = {
        {"John", "Johnson", "Manager", "2016-12-31"},
        {"Tou", "Xiong", "Software Engineer", "2016-10-05"},
        {"Michaela", "Michaelson", "District Manager", "2015-12-19"},
        {"Jake", "Jacobson", "Programmer", ""},
        {"Jacquelyn", "Jackson", "DBA", ""},
        {"Sally", "Weber", "Web Developer", "2015-12-18"}
    };

    int numEmployees = sizeof(employees) / sizeof(employees[0]);

    char query[20];
    printf("Enter a search string: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0;

    searchEmployees(employees, numEmployees, query);

    return 0;
}
