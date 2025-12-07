#include <stdio.h>

double calculate_base_premium(int age, int health) {
    double base_premium = 0.0;

    if (age < 25) {
        if (health == 1) { // Healthy
            base_premium = 5000.0;
        } else { // Unhealthy
            base_premium = 0.0; 
        }
    } else if (age >= 25 && age <= 40) {
        if (health == 1) { // Healthy
            base_premium = 7000.0;
        } else { // Unhealthy
            base_premium = 9500.0;
        }
    } else if (age >= 41 && age <= 60) {
        if (health == 1) { // Healthy
            base_premium = 10000.0;
        } else { // Unhealthy
            base_premium = 13000.0;
        }
    } else if (age > 60) {
        if (health == 1) { // Healthy
            base_premium = 15000.0;
        } else { // Unhealthy
            return -1.0; // Use -1.0 as a flag for "Not Eligible"
        }
    }
    
    return base_premium;
}

int main() {
    int age;
    char gender;
    int health; // 1 for Healthy, 0 for Unhealthy
    double premium = 0.0;
    double final_premium = 0.0;
    int eligible = 1; // Flag to track eligibility, 1 means eligible

    // 1. Accept inputs
    printf("Enter age: ");
    scanf("%d", &age);

    while (getchar() != '\n'); 

    printf("Enter gender (M/F): ");
    scanf("%c", &gender);

    printf("Health condition (1-Healthy / 0-Unhealthy): ");
    scanf("%d", &health);

    if (gender >= 'a' && gender <= 'z') {
        gender = gender - 32; // ASCII conversion to uppercase
    }

    premium = calculate_base_premium(age, health);

    if (age > 60 && health == 0) {
        eligible = 0; // Set eligibility flag to false
    } 
    else if (age < 25 && health == 0) {
        if (premium == 0.0 && age < 25) {
             eligible = 1; // Still eligible, but premium is 0 based on rules.
        }
    }
    
    if (eligible == 1 && premium > 0.0) {
        final_premium = premium;

        if (gender == 'F') {
            final_premium = premium - (premium * 0.10); // 10% discount
        }

        printf("\nCustomer Details:\n");
        printf("Age: %d\n", age);
        printf("Gender: %c\n", gender);
        printf("Health: %s\n", (health == 1) ? "Healthy" : "Unhealthy");
        printf("Final Premium: ₹%.2lf\n", final_premium);
        
    } else if (eligible == 0) {
        printf("\nCustomer Details:\n");
        printf("Age: %d\n", age);
        printf("Gender: %c\n", gender);
        printf("Health: %s\n", (health == 1) ? "Healthy" : "Unhealthy");
        printf("Status: Not Eligible for Insurance\n");
    } else {
        printf("\nCustomer Details:\n");
        printf("Age: %d\n", age);
        printf("Gender: %c\n", gender);
        printf("Health: %s\n", (health == 1) ? "Healthy" : "Unhealthy");
        printf("Final Premium: ₹%.2lf\n", 0.0); // Display 0 premium
    }

    return 0;
}
