#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Array of month names for reference
const char *months[] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };

// Function to summarize sales data
int summary(float sales[12]){
    float sum;
    float max = sales[0]; // Start with the first month's sales as max
    float min = 10000000.0f; // Set an initially high value for min
    float avg;
    
    int max_month; // Index for the month with maximum sales
    int min_month; // Index for the month with minimum sales
    
    // Loop through each month's sales data
    for (int i = 0; i < 12; i++)
    {
        sum += sales[i]; // calculate sum
        
        if (sales[i] > max) // Check for new maximum sales
        {
            max = sales[i];
            max_month = i; // Store month index for max
        }
        
        if (sales[i] < min) // Check for new minimum sales
        {
            min = sales[i];
            min_month = i; // Store month index for min
        }
    }
    
    avg = sum / 12.0f; // Calculate average sales
    
    // Print the sales summary report
    printf("Sales summary report:\n\nMinimum sales:\t%.2f (%s)\nMaximum sales:\t%.2f (%s)\nAverage sales:\t%.2f\n\n", min, months[min_month], max, months[max_month], avg);
    return 0;
}

// Function to calculate and display the six-month moving average
int moving_avg(float sales[12]){
    int j = 0; // Start index for moving average
    int k = 0; // Counter for moving averages
    int r = 6; // End index for moving average window
    float moving_avg[6]; // Array to store moving averages
    int sum_m = 0; // Variable to accumulate sales for moving average
    
    // Loop to calculate moving averages
    while(k < 7)
    {   
        int start_month = j; // Starting month for current average
        for (j; j < r; j++)
        {
            sum_m += sales[j]; // Accumulate sales in the window
        }
        
        moving_avg[k] = sum_m / 6.0f; // Calculate average for the window
        
        // Print the moving average for the specified months
        printf("%s-%s\t%.2f\n",months[start_month] ,months[j-1] ,moving_avg[k]);
        sum_m = 0; // Reset sum for next iteration
        k += 1; // Move to next average
        j = k; // Set starting month for next window
        r += 1; // Expand the end index for the next window
    }
    printf("\n");
    return 0;
}

// Function prototype for comparison function used in qsort
int compare(const void *a, const void *b);

// Structure to hold sales data for each month
typedef struct
{
    float price; // Sales amount
    const char *month; // Month name
} MonthSale;

// Function to combine sales data into an array of MonthSale structures
MonthSale combine(float sales[12], MonthSale arr[12]){
    for (int i = 0; i < 12; i++){
        arr[i].price = sales[i];
        arr[i].month = months[i];
    }
    return arr[12];
}

// Function to sort sales data and display it
int sort(float sales[12], MonthSale arr[12], int n){
    combine(sales, arr); // Combine sales data into MonthSale array
    qsort(arr, n, sizeof(MonthSale), compare); // Sort the array in descending order

    // Print sorted sales data
    for (int i = 0; i < n; i++){
        printf("%-15s %.2f\n", arr[i].month, arr[i].price);
    }
    return 0;
}

int main() {
    float sales[12]; // Array to hold sales data for each month
    int n = sizeof(sales) / sizeof(sales[0]); // Determine the number of months
    MonthSale arr[12]; // Array of MonthSale structures

    FILE *fp; // File pointer
    float num; // Variable to hold each number read from file
    int i = 0; // Index for sales array

    // Open the file for reading
    fp = fopen("sales.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n"); // Handle file opening error
        return 1;
    }

    // Read numbers from the file
    while (fscanf(fp, "%f", &num) == 1) {
        sales[i] = num;
        //printf("%.2f\n", num);
        i++;
    }

    // Close the file
    fclose(fp);
    
    // Print the sales summary report
    printf("Sales Summary Report:\n\n");
    summary(sales);

    // Print the six-month moving average report
    printf("Six-Month moving average report:\n\n");
    moving_avg(sales);

    // Print the sorted sales report
    printf("Sales Report (highest to lowest):\n\n");
    sort(sales, arr, n);
    

    return 0;
}

// Comparison function for qsort to sort MonthSale structures by price
int compare(const void *a, const void *b) {
    float priceA = ((MonthSale *)a)->price; // Cast and get price of first element
    float priceB = ((MonthSale *)b)->price; // Cast and get price of second element
    
    // For descending order
    if (priceA < priceB) return 1;  // priceA should come after priceB
    if (priceA > priceB) return -1; // priceA should come before priceB
    return 0; // They are equal
}