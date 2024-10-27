// Online C compiler to run C program online
#include <stdio.h>

float convert(float temp, char main_scale, char convert_to_scale){
    float converted;
    if (main_scale == 'F'){
        if (convert_to_scale == 'C'){
            converted = (temp - 32) * (5.0/9.0);
        }
        else if (convert_to_scale == 'K'){
            converted = (temp - 32) * (5.0/9.0) + 273.15;
        }
        else {
            printf("The requested convertion %c is invalid", convert_to_scale);
        }
    }
    else if (main_scale == 'C'){
        if (convert_to_scale == 'F'){
            converted = (temp * (9.0/5.0)) + 32;
        }
        else if (convert_to_scale == 'K'){
            converted = temp + 273.15;
        }
        else {
            printf("The requested convertion %c is invalid", convert_to_scale);
        }
    }
    else if (main_scale == 'K'){
        if (convert_to_scale == 'F'){
            converted = (temp - 273.15) * (9.0/5.0) + 32;
        }
        else if (convert_to_scale == 'C'){
            converted = (temp - 273.15);
        }
        else {
            printf("The requested convertion %c is invalid", convert_to_scale);
        }
    }
    return converted;
    
    
}

void advise(float temp, char main_scale){
    float cel = temp;
    if (main_scale != 'C'){
        cel = convert(temp, main_scale, 'C');
    }
    if (cel < 0){
        printf("It is Freezing\nIts too risky to drive");
    }
    else if (cel < 11){
        printf("It is Cold\nMake sure to wear a jacket");
    }
    else if (cel < 26){
        printf("It is comfortable\nperfect tempreture for a walk");
    }
    else if (cel < 36){
        printf("It is Hot\nStay hydrated");
    }
    else{
        printf("Extreme Hot\nPlease Stay inside");
    }
}


int main() {
    // Write C code here
    float temp;
    char main_scale;
    char convert_to_scale;
    float converted;
    
    printf("Enter the temp value: ");
    scanf("%f", &temp);
    
    printf("Choose the temperature scale of the input value (F, C, K): ");
    scanf(" %c", &main_scale);
    
    printf("Choose the conversion target (F, C, K): ");
    scanf(" %c", &convert_to_scale);
    
    converted = convert(temp, main_scale, convert_to_scale);
    
    printf("The value is: %f \n", converted);
    advise(temp, main_scale);

    return 0;
}

// https://www.programiz.com/online-compiler/9UmneBcyyZS5D

// This one is case insensitive 
// https://www.programiz.com/online-compiler/0tHuR1FeKMuRy


// modified final
#include <stdio.h>
#include <ctype.h>

float convert(float temp, int main_scale, int convert_to_scale) {
    float converted = 0;

    // Check for invalid inputs
    if ((main_scale == 3 && temp < 0)) { // Kelvin check
        printf("Invalid temperature: Kelvin cannot be negative.\n");
        return -1; // Indicate an error
    }

    if (main_scale == 2) { // Fahrenheit
        if (convert_to_scale == 1) { // to Celsius
            converted = (temp - 32) * (5.0 / 9.0);
        } else if (convert_to_scale == 3) { // to Kelvin
            converted = (temp - 32) * (5.0 / 9.0) + 273.15;
        } else {
            printf("The requested conversion is invalid\n");
            return -1; // Indicate an error
        }
    } else if (main_scale == 1) { // Celsius
        if (convert_to_scale == 2) { // to Fahrenheit
            converted = (temp * (9.0 / 5.0)) + 32;
        } else if (convert_to_scale == 3) { // to Kelvin
            converted = temp + 273.15;
        } else {
            printf("The requested conversion is invalid\n");
            return -1; // Indicate an error
        }
    } else if (main_scale == 3) { // Kelvin
        if (convert_to_scale == 2) { // to Fahrenheit
            converted = (temp - 273.15) * (9.0 / 5.0) + 32;
        } else if (convert_to_scale == 1) { // to Celsius
            converted = temp - 273.15;
        } else {
            printf("The requested conversion is invalid\n");
            return -1; // Indicate an error
        }
    }

    return converted;
}

void advise(float temp, int main_scale) {
    float cel = temp;
    if (main_scale != 1) {
        cel = convert(temp, main_scale, 1);
        if (cel == -1) return; // Check for conversion error
    }

    if (cel < 0) {
        printf("It is Freezing\nIt's too risky to drive.\n");
    } else if (cel < 11) {
        printf("It is Cold\nMake sure to wear a jacket.\n");
    } else if (cel < 26) {
        printf("It is Comfortable\nPerfect temperature for a walk.\n");
    } else if (cel < 36) {
        printf("It is Hot\nStay hydrated.\n");
    } else {
        printf("Extreme Heat\nPlease stay inside.\n");
    }
}

int main() {
    float temp;
    int main_scale, convert_to_scale;
    float converted;

    while (1) {
        printf("Enter the temperature value: ");
        scanf("%f", &temp);

        // Input for main_scale with validation
        while (1) {
            printf("Choose the temperature scale of the input value (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
            scanf("%d", &main_scale);
            if (main_scale < 1 || main_scale > 3) {
                printf("Invalid scale. Please enter 1, 2, or 3.\n");
            } else {
                break; // Valid scale entered
            }
        }

        // Input for convert_to_scale with validation
        while (1) {
            printf("Choose the conversion target (1: Celsius, 2: Fahrenheit, 3: Kelvin): ");
            scanf("%d", &convert_to_scale);
            if (convert_to_scale < 1 || convert_to_scale > 3) {
                printf("Invalid scale. Please enter 1, 2, or 3.\n");
            } else {
                break; // Valid scale entered
            }
        }

        converted = convert(temp, main_scale, convert_to_scale);
        if (convert_to_scale == 3 && converted < 0){
            printf("Invalid temperature: Kelvin cannot be negative.\n");
        }
        else if (converted != -1) { // Check for conversion errors
            printf("The converted value is: %.2f \n", converted);
            advise(converted, convert_to_scale); // Advise based on converted temperature
        } 
    }

    return 0;
}