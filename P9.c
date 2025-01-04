#include <stdio.h>
#include <math.h>

int main() {
    int H, L;

    // Prompt the user to input H and L
    printf("Enter the height (H) and horizontal distance (L): ");
    scanf("%d %d", &H, &L);

    // Calculate the depth using the derived formula
    double depth = sqrt((double)H * H + (double)L * L) - H;

    // Print the result with six decimal places
    printf("The depth of the lake is: %.6lf\n", depth);
    printf("\n\nCreated by Jashkumar:24CE004");

    return 0;
}

