#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    char serial[20];
    float value;
} Item;

void saveCSV(Item items[], int count) {
    FILE *file = fopen("inventory.csv", "w");
    fprintf(file, "Name,Serial Number,Value\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,$%.2f\n", items[i].name, items[i].serial, items[i].value);
    }
    fclose(file);
    printf("Saved to inventory.csv\n");
}

void saveHTML(Item items[], int count) {
    FILE *file = fopen("inventory.html", "w");
    fprintf(file, "<html><body><h1>Inventory Report</h1><table border='1'><tr><th>Name</th><th>Serial</th><th>Value</th></tr>");
    for (int i = 0; i < count; i++) {
        fprintf(file, "<tr><td>%s</td><td>%s</td><td>$%.2f</td></tr>", items[i].name, items[i].serial, items[i].value);
    }
    fprintf(file, "</table></body></html>");
    fclose(file);
    printf("Saved to inventory.html\n");
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("Enter Item Name (or 'done' to finish): ");
        scanf(" %[^\n]", items[count].name);
        if (strcmp(items[count].name, "done") == 0) break;

        printf("Enter Serial Number: ");
        scanf(" %[^\n]", items[count].serial);

        printf("Enter Value: $");
        scanf("%f", &items[count].value);

        count++;
    }

    saveCSV(items, count);
    saveHTML(items, count);

    return 0;
}
