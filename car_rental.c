#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct car {
    char car_name[100];
    char model[100];
    char brand[100];
    float price_per_day;
} car;

typedef struct detail {
    char name[100];
    char phone_no[10];
} customer;

typedef struct rental {
    customer a1;
    car c2;
    int days;
    float total_cost;
} rental;

int no;
car cars[100];
customer customers[100];
rental rentals[100];
int customer_count = 0;
int rental_count = 0;

void save_cars_to_file();
void save_customers_to_file();
void save_rentals_to_file();
void add_cars();
void view_cars();
void add_customer();
void rent_car();
void delete_car();
void update_car_price();

void save_cars_to_file() {
    FILE *file = fopen("cars.txt", "a"); 
    if (file == NULL) {
        printf("Error opening file for writing\n");
        exit(1);
    }

    for (int i = 0; i < no; i++) {
        fprintf(file, "%s\n%s\n%s\n%.2f\n", cars[i].car_name, cars[i].model, cars[i].brand, cars[i].price_per_day);
    }
    fclose(file);
}

void save_customers_to_file() {
    FILE *file = fopen("customers.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        exit(1);
    }

    for (int i = 0; i < customer_count; i++) {
        fprintf(file, "%s\n%s\n", customers[i].name, customers[i].phone_no);
    }
    fclose(file);
}

void save_rentals_to_file() {
    FILE *file = fopen("rent_cars.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        exit(1);
    }

    for (int i = 0; i < rental_count; i++) {
        fprintf(file, "%s %s %s %s %s %d %.2f\n", rentals[i].a1.name, rentals[i].a1.phone_no, rentals[i].c2.car_name, rentals[i].c2.model, rentals[i].c2.brand, rentals[i].days, rentals[i].total_cost);
    }
    fclose(file);
}

void add_cars() {
    printf("How many cars do you want to add? ");
    scanf("%d", &no);

    for (int i = 0; i < no; i++) {
        printf("Enter your car's name: ");
        getchar();
        fgets(cars[i].car_name, sizeof(cars[i].car_name), stdin);
        cars[i].car_name[strcspn(cars[i].car_name, "\n")] = '\0';

        printf("Enter your car's model: ");
        fgets(cars[i].model, sizeof(cars[i].model), stdin);
        cars[i].model[strcspn(cars[i].model, "\n")] = '\0';

        printf("Enter your car's brand: ");
        fgets(cars[i].brand, sizeof(cars[i].brand), stdin);
        cars[i].brand[strcspn(cars[i].brand, "\n")] = '\0';

        printf("Enter your car's price per day: ");
        scanf("%f", &cars[i].price_per_day);
    }
    save_cars_to_file();
}

void view_cars() {
    FILE *file = fopen("cars.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void add_customer() {
    printf("How many customers do you want to add? ");
    scanf("%d", &no);
    getchar();

    for (int i = 0; i < no; i++) {
        if (customer_count < 100) {
            printf("Enter customer's name: ");
            fgets(customers[customer_count].name, sizeof(customers[customer_count].name), stdin);
            customers[customer_count].name[strcspn(customers[customer_count].name, "\n")] = '\0';

            printf("Enter customer's 5 digit phone no: ");
            fgets(customers[customer_count].phone_no, sizeof(customers[customer_count].phone_no), stdin);
            customers[customer_count].phone_no[strcspn(customers[customer_count].phone_no, "\n")] = '\0';

            customer_count++;
        }  
    }
    save_customers_to_file();
}

void rent_car() {
    printf("How many cars do you want to rent? ");
    scanf("%d", &no);
    getchar();

    printf("Enter customer's name: ");
            fgets(rentals[rental_count].a1.name, sizeof(rentals[rental_count].a1.name), stdin);
            rentals[rental_count].a1.name[strcspn(rentals[rental_count].a1.name, "\n")] = '\0';

            printf("Enter customer's 5 digit phone no: ");
            fgets(rentals[rental_count].a1.phone_no, sizeof(rentals[rental_count].a1.phone_no), stdin);
            rentals[rental_count].a1.phone_no[strcspn(rentals[rental_count].a1.phone_no, "\n")] = '\0';
    for (int i = 0; i < no; i++) {

       
            
            printf("Enter your car's name: ");
            fgets(rentals[rental_count].c2.car_name, sizeof(rentals[rental_count].c2.car_name), stdin);
            rentals[rental_count].c2.car_name[strcspn(rentals[rental_count].c2.car_name, "\n")] = '\0';

            printf("Enter your car's model: ");
            fgets(rentals[rental_count].c2.model, sizeof(rentals[rental_count].c2.model), stdin);
            rentals[rental_count].c2.model[strcspn(rentals[rental_count].c2.model, "\n")] = '\0';

            printf("Enter your car's brand: ");
            fgets(rentals[rental_count].c2.brand, sizeof(rentals[rental_count].c2.brand), stdin);
            rentals[rental_count].c2.brand[strcspn(rentals[rental_count].c2.brand, "\n")] = '\0';

            printf("Enter how many days: ");
            scanf("%d", &rentals[rental_count].days);
            getchar();

            FILE *file = fopen("cars.txt", "r");
            if (file == NULL) {
                printf("Error opening file for reading\n");
                exit(1);
            }

            char car_name[100], model[100], brand[100];
            float price_per_day;
            int car_found = 0;

            while (fgets(car_name, sizeof(car_name), file)) {
                car_name[strcspn(car_name, "\n")] = '\0';
                fgets(model, sizeof(model), file);
                model[strcspn(model, "\n")] = '\0';
                fgets(brand, sizeof(brand), file);
                brand[strcspn(brand, "\n")] = '\0';
                fscanf(file, "%f\n", &price_per_day);

                if (strcmp(car_name, rentals[rental_count].c2.car_name) == 0 &&
                    strcmp(model, rentals[rental_count].c2.model) == 0 &&
                    strcmp(brand, rentals[rental_count].c2.brand) == 0) {
                    car_found = 1;
                    rentals[rental_count].c2.price_per_day = price_per_day;
                    break;
                }
            }
            fclose(file);

            if (car_found) {
                rentals[rental_count].total_cost = rentals[rental_count].c2.price_per_day * rentals[rental_count].days;
                printf("Total cost: %.2f\n", rentals[rental_count].total_cost);

                rental_count++;
                save_rentals_to_file();
                printf("Car rented successfully.\n");
            } else {
                printf("Car not available.\n");
            }
        }
    }


void delete_car() {
    char car_name[100];
    printf("Enter the name of the car to delete: ");
    getchar();
    fgets(car_name, sizeof(car_name), stdin);
    car_name[strcspn(car_name, "\n")] = '\0';

    FILE *file = fopen("cars.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");
    if (file == NULL || temp_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, car_name) == NULL) {
            fputs(line, temp_file);
        } else {
            found = 1;
            for (int i = 0; i < 3; i++) {
                fgets(line, sizeof(line), file);
            }
        }
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove("cars.txt");
        rename("temp.txt", "cars.txt");
        printf("Car deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("Car not found.\n");
    }
}

void update_car_price() {
    char car_name[100];
    printf("Enter the name of the car to update the price: ");
    fgets(car_name, sizeof(car_name), stdin);
    // getchar();  
    car_name[strcspn(car_name, "\n")] = '\0';
    // puts(car_name);

    // printf("Debuggingh: %s\n", car_name);

    FILE *file = fopen("cars.txt", "r");
    FILE *temp_file = fopen("temp.txt", "w");

    char file_car_name[100], model[100], brand[100];
    float price_per_day;
    int found = 0;

    while (fgets(file_car_name, sizeof(file_car_name), file)) {
        file_car_name[strcspn(file_car_name, "\r\n")] = '\0'; 

        fgets(model, sizeof(model), file);
        model[strcspn(model, "\r\n")] = '\0';

        fgets(brand, sizeof(brand), file);
        brand[strcspn(brand, "\r\n")] = '\0';

        if (fscanf(file, "%f\n", &price_per_day) != 1) {
            printf("Error reading price from file.\n");
            break;
        }


        if (strcmp(file_car_name, car_name) == 0) {
            found = 1;
            printf("Enter new price per day: ");
            scanf("%f", &price_per_day);
            getchar(); 
        }

        fprintf(temp_file, "%s\n%s\n%s\n%.2f\n", file_car_name, model, brand, price_per_day);
    }

    fclose(file);
    fclose(temp_file);

    if (found) {
        remove("cars.txt");
        rename("temp.txt", "cars.txt");
        printf("Car price updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("Car not found. Ensure correct spelling.\n");
    }
}




int main() {
    int choice;
    do {
        printf("\nCAR RENTAL SYSTEM\n");
        printf("1. Add cars\n");
        printf("2. View cars\n");
        printf("3. Add customer\n");
        printf("4. Rent a car\n");
        printf("5. Delete a car\n");
        printf("6. Update car price\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_cars();
                break;
            case 2:
                view_cars();
                break;
            case 3:
                add_customer();
                break;
            case 4:
                rent_car();
                break;
            case 5:
                delete_car();
                break;
            case 6:
                update_car_price();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
 return 0;
}