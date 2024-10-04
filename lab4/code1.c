#include <stdio.h>

int main() {
    int numbers[] = {8, 7, 6, 3, 2};  // Scoring plays: TD + 2pt (8), TD + FG (7), TD (6), FG (3), Safety (2)
    int target;  // Variable to hold user input
    int count[5];  // Array to keep track of counts of each number

    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &target);

        // Check for stop condition
        if (target <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays if a teams score is %d:\n", target);
        
        // Nested loops for each scoring play 
        for (count[0] = 0; count[0] <= target / numbers[0]; count[0]++) { // TD + 2pt condition is controlling how many of that paricualr score we can count while being equal or less than the target
            for (count[1] = 0; count[1] <= target / numbers[1]; count[1]++) { // TD + FG
                for (count[2] = 0; count[2] <= target / numbers[2]; count[2]++) { // TD
                    for (count[3] = 0; count[3] <= target / numbers[3]; count[3]++) { // FG
                        for (count[4] = 0; count[4] <= target / numbers[4]; count[4]++) { // Safety
                            // Calculate the sum of the selected combination
                            int sum = count[0] * numbers[0] + count[1] * numbers[1] + count[2] * numbers[2] + count[3] * numbers[3] + count[4] * numbers[4];

                            // Check if the sum equals to the target
                            if (sum == target) {
                                // Print the combination in the desired format
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety",count[0],count[1],count[2],count[3],count[4]);
                                printf("\n");
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
