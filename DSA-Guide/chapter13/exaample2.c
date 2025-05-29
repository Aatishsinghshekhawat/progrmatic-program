#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTES 10
#define MAX_NAME_LEN 50

struct City;

typedef struct Route {
    struct City* destination;
    int price;
} Route;

typedef struct City {
    char name[MAX_NAME_LEN];
    Route routes[MAX_ROUTES];
    int route_count;
} City;

City* create_city(const char* name) {
    City* new_city = (City*)malloc(sizeof(City));
    strncpy(new_city->name, name, MAX_NAME_LEN);
    new_city->route_count = 0;
    return new_city;
}

void add_route(City* from, City* to, int price) {
    if (from->route_count >= MAX_ROUTES) {
        printf("Cannot add more routes to %s\n", from->name);
        return;
    }
    from->routes[from->route_count].destination = to;
    from->routes[from->route_count].price = price;
    from->route_count++;
}

void print_routes(City* city) {
    printf("Routes from %s:\n", city->name);
    for (int i = 0; i < city->route_count; i++) {
        printf("  To %s - $%d\n", city->routes[i].destination->name, city->routes[i].price);
    }
}

int main() {

    City* atlanta = create_city("Atlanta");
    City* boston = create_city("Boston");
    City* chicago = create_city("Chicago");
    City* denver = create_city("Denver");
    City* el_paso = create_city("El Paso");


    add_route(atlanta, boston, 100);
    add_route(atlanta, denver, 160);
    add_route(boston, chicago, 120);
    add_route(boston, denver, 180);
    add_route(chicago, el_paso, 80);
    add_route(denver, chicago, 40);
    add_route(denver, el_paso, 140);

    print_routes(atlanta);
    print_routes(boston);
    print_routes(chicago);
    print_routes(denver);
    print_routes(el_paso);

    free(atlanta);
    free(boston);
    free(chicago);
    free(denver);
    free(el_paso);

    return 0;
}
