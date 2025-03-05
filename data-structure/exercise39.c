#include <stdio.h>
#include <string.h>

typedef struct {
    char firstName[20],lastName[20] ,position[30] ,sepDate[15];

} Employee;

void sortEmployees(Employee employees[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(employees[j].lastName, employees[j + 1].lastName) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
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

    sortEmployees(employees, numEmployees);

    printf("Name                 | Position          | Separation Date\n");
    printf("---------------------|------------------|----------------\n");

    for (int i = 0; i < numEmployees; i++) {
        printf("%s %s | %s | %s \n", employees[i].firstName, employees[i].lastName,
               employees[i].position, employees[i].sepDate);
    }

    return 0;
}
