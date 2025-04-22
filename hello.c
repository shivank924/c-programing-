#include <stdio.h>
#include <math.h>

// Function prototypes
float area_circle(float radius);
float circumference_circle(float radius);
float area_rectangle(float length, float width);
float perimeter_rectangle(float length, float width);
float area_triangle(float a, float b, float c);
float perimeter_triangle(float a, float b, float c);
int is_valid_triangle(float a, float b, float c);

int main() {
    int choice;
    float a, b, c;

    while (1) {
        // Display menu
        printf("\n=== Geometry Calculator ===\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                // Circle calculations
                printf("Enter radius: ");
                if (scanf("%f", &a) != 1 || a <= 0) {
                    printf("Invalid radius. Must be a positive number.\n");
                    while(getchar() != '\n');
                    break;
                }
                printf("Area: %.2f\n", area_circle(a));
                printf("Circumference: %.2f\n", circumference_circle(a));
                break;

            case 2:
                // Rectangle calculations
                printf("Enter length and width: ");
                if (scanf("%f %f", &a, &b) != 2 || a <= 0 || b <= 0) {
                    printf("Invalid dimensions. Both must be positive numbers.\n");
                    while(getchar() != '\n');
                    break;
                }
                printf("Area: %.2f\n", area_rectangle(a, b));
                printf("Perimeter: %.2f\n", perimeter_rectangle(a, b));
                break;

            case 3:
                // Triangle calculations
                printf("Enter three sides: ");
                if (scanf("%f %f %f", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0) {
                    printf("Invalid sides. All must be positive numbers.\n");
                    while(getchar() != '\n');
                    break;
                }
                if (!is_valid_triangle(a, b, c)) {
                    printf("The sides do not form a valid triangle.\n");
                    break;
                }
                printf("Area: %.2f\n", area_triangle(a, b, c));
                printf("Perimeter: %.2f\n", perimeter_triangle(a, b, c));
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select between 1 and 4.\n");
        }
    }

    return 0;
}

// Circle area
float area_circle(float radius) {
    return M_PI * radius * radius;
}

// Circle circumference
float circumference_circle(float radius) {
    return 2 * M_PI * radius;
}

// Rectangle area
float area_rectangle(float length, float width) {
    return length * width;
}

// Rectangle perimeter
float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

// Triangle area using Heron's formula
float area_triangle(float a, float b, float c) {
    float s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Triangle perimeter
float perimeter_triangle(float a, float b, float c) {
    return a + b + c;
}

// Check if triangle is valid
int is_valid_triangle(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}