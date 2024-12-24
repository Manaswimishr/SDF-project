#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_MEMORY_SLOTS 5
#define PI 3.14159265358979323846
#define E 2.71828182845904523536

// Structure for storing calculator memory
typedef struct {
    double values[MAX_MEMORY_SLOTS];
    int isOccupied[MAX_MEMORY_SLOTS];
} CalculatorMemory;

// Function declarations
void displayMenu();
void displayAdvancedMenu();
void displayMemoryMenu();
void displayUnitMenu();
void displayStatisticsMenu();
double getNumber();
char* getString();
void clearScreen();
void handleError(const char* message);
void saveToHistory(const char* operation, double num1, double num2, double result);
void readHistory();


// Basic arithmetic
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Power and root functions
double power(double base, double exponent);
double square(double num);
double cube(double num);
double squareRoot(double num);
double cubeRoot(double num);
double nthRoot(double num, double n);

// Factorial and combination functions
double factorial(double num);
double permutation(double n, double r);
double combination(double n, double r);

// Trigonometric functions
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double arcsine(double value);
double arccosine(double value);
double arctangent(double value);

// Logarithmic functions
double logarithm(double num);
double naturalLog(double num);
double logBaseN(double num, double base);

// Memory functions
void initializeMemory(CalculatorMemory* mem);
void storeInMemory(CalculatorMemory* mem, int slot, double value);
double recallFromMemory(CalculatorMemory* mem, int slot);
void clearMemory(CalculatorMemory* mem, int slot);
void displayMemoryContents(CalculatorMemory* mem);

// Unit conversion functions
double celsiusToFahrenheit(double celsius);
double fahrenheitToCelsius(double fahrenheit);
double kilogramsToPounds(double kg);
double poundsToKilograms(double lbs);
double metersToFeet(double meters);
double feetToMeters(double feet);
double radiansToDegrees(double radians);
double degreesToRadians(double degrees);

// Statistical functions
void calculateStatistics(double* numbers, int count, double* mean, double* variance, double* stdDev);
double calculateMedian(double* numbers, int count);
double calculateMode(double* numbers, int count);
void bubbleSort(double* numbers, int count);

// Number system conversion
void decimalToBinary(int decimal);
void decimalToOctal(int decimal);
void decimalToHexadecimal(int decimal);
int binaryToDecimal(const char* binary);

int main() {
  
    char choice;
    double num1, num2, result;
    int continueCalc = 1;
    CalculatorMemory memory;
    initializeMemory(&memory);
    
    printf("\n=== Welcome to Advanced Scientific Calculator ===\n");

    while (continueCalc) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            // Basic Operations (1-4)
            case '1': {
                printf("\nEnter first number: ");
                num1 = getNumber();
                printf("Enter second number: ");
                num2 = getNumber();
                result = add(num1, num2);
                printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, result);
                saveToHistory("Addition", num1, num2, result);
                break;
            }
            
            case '2': {
                printf("\nEnter first number: ");
                num1 = getNumber();
                printf("Enter second number: ");
                num2 = getNumber();
                result = subtract(num1, num2);
                printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, result);
                saveToHistory("Subtraction", num1, num2, result);
                break;
            }

            case '3': {
                printf("\nEnter first number: ");
                num1 = getNumber();
                printf("Enter second number: ");
                num2 = getNumber();
                result = multiply(num1, num2);
                printf("\nResult: %.2f × %.2f = %.2f\n", num1, num2, result);
                saveToHistory("Multiplication", num1, num2, result);
                break;
            }

            case '4': {
                printf("\nEnter first number: ");
                num1 = getNumber();
                printf("Enter second number: ");
                num2 = getNumber();
                if (num2 == 0) {
                    handleError("Division by zero is not allowed!");
                } else {
                    result = divide(num1, num2);
                    printf("\nResult: %.2f ÷ %.2f = %.2f\n", num1, num2, result);
                }
                saveToHistory("Division", num1, num2, result);
                break;
            }

            // Advanced Operations (5-9)
            case '5': {
                printf("\nEnter base number: ");
                num1 = getNumber();
                printf("Enter exponent: ");
                num2 = getNumber();
                result = power(num1, num2);
                printf("\nResult: %.2f ^ %.2f = %.2f\n", num1, num2, result);
                saveToHistory("Power", num1, num2, result);
                break;
            }

            case '6': {
                printf("\nEnter number for nth root: ");
                num1 = getNumber();
                printf("Enter the root value (n): ");
                num2 = getNumber();
                if (num2 == 0) {
                    handleError("Root value cannot be zero!");
                } else {
                    result = nthRoot(num1, num2);
                    printf("\nResult: %.2f th root of %.2f = %.2f\n", num2, num1, result);
                    saveToHistory("Nth Root", num1, num2, result);

                }
                break;
            }

            case '7': {
                printf("\nEnter n (total items): ");
                num1 = getNumber();
                printf("Enter r (items to choose): ");
                num2 = getNumber();
                if (num1 < num2 || num1 < 0 || num2 < 0) {
                    handleError("Invalid input for combination calculation!");
                } else {
                    result = combination(num1, num2);
                    printf("\nC(%.0f,%.0f) = %.0f\n", num1, num2, result);
                    saveToHistory("Combination", num1, num2, result);
                }                
                break;
            }

            case '8': {
                printf("\nEnter n (total items): ");
                num1 = getNumber();
                printf("Enter r (items to arrange): ");
                num2 = getNumber();
                if (num1 < num2 || num1 < 0 || num2 < 0) {
                    handleError("Invalid input for permutation calculation!");
                } else {
                    result = permutation(num1, num2);
                    printf("\nP(%.0f,%.0f) = %.0f\n", num1, num2, result);
                    saveToHistory("Combination", num1, num2, result);

                }
                break;
            }

            case '9': {
                char subChoice;
                displayStatisticsMenu();
                printf("\nEnter your choice: ");
                scanf(" %c", &subChoice);
                
                switch (subChoice) {
                    case '1': {
                        int count;
                        printf("Enter the number of values: ");
                        scanf("%d", &count);
                        if (count <= 0) {
                            handleError("Invalid count!");
                            break;
                        }
                        
                        double* numbers = (double*)malloc(count * sizeof(double));
                        printf("Enter %d numbers:\n", count);
                        for (int i = 0; i < count; i++) {
                            numbers[i] = getNumber();
                        }
                        
                        double mean, variance, stdDev;
                        calculateStatistics(numbers, count, &mean, &variance, &stdDev);
                        double median = calculateMedian(numbers, count);
                        double mode = calculateMode(numbers, count);
                        
                        printf("\nStatistical Analysis Results:\n");
                        printf("Mean: %.2f\n", mean);
                        printf("Median: %.2f\n", median);
                        printf("Mode: %.2f\n", mode);
                        printf("Variance: %.2f\n", variance);
                        printf("Standard Deviation: %.2f\n", stdDev);
                        saveToHistory("Mean", 0, 0, mean);        // Save mean
                        saveToHistory("Median", 0, 0, median);    // Save median
                        saveToHistory("Mode", 0, 0, mode);        // Save mode
                        saveToHistory("Variance", 0, 0, variance); // Save variance
                        saveToHistory("Standard Deviation", 0, 0, stdDev); // Save standard deviation

                        
                        free(numbers);
                        break;
                    }
                    default:
                        printf("\nInvalid choice!\n");
                }
                break;
            }

            // Trigonometric Functions (10-15)
            case 'A': {
                printf("\nEnter angle in degrees: ");
                num1 = getNumber();
                result = sine(num1);
                printf("\nResult: sin(%.2f°) = %.2f\n", num1, result);
                saveToHistory("Sine", num1, 0, result);

                break;
            }

            case 'B': {
                printf("\nEnter angle in degrees: ");
                num1 = getNumber();
                result = cosine(num1);
                printf("\nResult: cos(%.2f°) = %.2f\n", num1, result);
                saveToHistory("Cosine", num1, 0, result);

                break;
            }

            case 'C': {
                printf("\nEnter angle in degrees: ");
                num1 = getNumber();
                result = tangent(num1);
                printf("\nResult: tan(%.2f°) = %.2f\n", num1, result);
                saveToHistory("Tangent", num1, 0, result);

                break;
            }

            case 'D': {
                printf("\nEnter value (-1 to 1): ");
                num1 = getNumber();
                if (num1 < -1 || num1 > 1) {
                    handleError("Value must be between -1 and 1!");
                } else {
                    result = arcsine(num1);
                    printf("\nResult: arcsin(%.2f) = %.2f°\n", num1, result);
                    saveToHistory("Arcsine", num1, 0, result);

                }
                break;
            }

            case 'E': {
                printf("\nEnter value (-1 to 1): ");
                num1 = getNumber();
                if (num1 < -1 || num1 > 1) {
                    handleError("Value must be between -1 and 1!");
                } else {
                    result = arccosine(num1);
                    printf("\nResult: arccos(%.2f) = %.2f°\n", num1, result);
                    saveToHistory("Arccosine", num1, 0, result);

                }
                break;
            }

            case 'F': {
                printf("\nEnter value: ");
                num1 = getNumber();
                result = arctangent(num1);
                printf("\nResult: arctan(%.2f) = %.2f°\n", num1, result);
                saveToHistory("Arctangent", num1, 0, result);

                break;
            }

            // Memory Operations (M)
            case 'M': {
                char memChoice;
                displayMemoryMenu();
                printf("\nEnter your choice: ");
                scanf(" %c", &memChoice);
                
                switch (memChoice) {
                    case '1': {
                        int slot;
                        printf("Enter memory slot (1-%d): ", MAX_MEMORY_SLOTS);
                        scanf("%d", &slot);
                        if (slot < 1 || slot > MAX_MEMORY_SLOTS) {
                            handleError("Invalid memory slot!");
                            break;
                        }
                        printf("Enter value to store: ");
                        num1 = getNumber();
                        storeInMemory(&memory, slot - 1, num1);
                        printf("Value stored in memory slot %d\n", slot);
                        break;
                    }
                    case '2': {
                        int slot;
                        printf("Enter memory slot to recall (1-%d): ", MAX_MEMORY_SLOTS);
                        scanf("%d", &slot);
                        if (slot < 1 || slot > MAX_MEMORY_SLOTS) {
                            handleError("Invalid memory slot!");
                            break;
                        }
                        result = recallFromMemory(&memory, slot - 1);
                        if (memory.isOccupied[slot - 1]) {
                            printf("Value in memory slot %d: %.2f\n", slot, result);
                            saveToHistory("Memory Recall", slot, 0, result);
                        } else {
                            printf("Memory slot %d is empty\n", slot);
                        }
                        break;
                    }
                    case '3': {
                        int slot;
                        printf("Enter memory slot to clear (1-%d, 0 for all): ", MAX_MEMORY_SLOTS);
                        scanf("%d", &slot);
                        if (slot < 0 || slot > MAX_MEMORY_SLOTS) {
                            handleError("Invalid memory slot!");
                            break;
                        }
                        if (slot == 0) {
                            for (int i = 0; i < MAX_MEMORY_SLOTS; i++) {
                                clearMemory(&memory, i);
                            }
                            printf("All memory slots cleared\n");
                        } else {
                            clearMemory(&memory, slot - 1);
                            printf("Memory slot %d cleared\n", slot);
                        }
                        break;
                    }
                    case '4': {
                        displayMemoryContents(&memory);
                        break;
                    }
                    default:
                        printf("\nInvalid choice!\n");
                }
                break;
            }

            // Unit Conversions (U)
            case 'U': {
                char unitChoice;
                displayUnitMenu();
                printf("\nEnter your choice: ");
                scanf(" %c", &unitChoice);
                
                switch (unitChoice) {
                    case '1': {
                        printf("Enter temperature in Celsius: ");
                        num1 = getNumber();
                        result = celsiusToFahrenheit(num1);
                        printf("%.2fC = %.2fF\n", num1, result);
                        saveToHistory("Celsius to Fahrenheit", num1, 0, result);

                        break;
                    }
                    case '2': {
                        printf("Enter temperature in Fahrenheit: ");
                        num1 = getNumber();
                        result = fahrenheitToCelsius(num1);
                        printf("%.2f°F = %.2f°C\n", num1, result);
                        saveToHistory("Fahrenheit to Celsius", num1, 0, result);

                        break;
                    }
                    case '3': {
                        printf("Enter weight in kilograms: ");
                        num1 = getNumber();
                        result = kilogramsToPounds(num1);
                        printf("%.2f kg = %.2f lbs\n", num1, result);
                        saveToHistory("Kilograms to Pounds", num1, 0, result);

                        break;
                    }
                    case '4': {
                        printf("Enter weight in pounds: ");
                        num1 = getNumber();
                        result = poundsToKilograms(num1);
                        printf("%.2f lbs = %.2f kg\n", num1, result);
                        saveToHistory("Pounds to Kilograms", num1, 0, result);

                        break;
                    }
                    case '5': {
                        printf("Enter length in meters: ");
                        num1 = getNumber();
                        result = metersToFeet(num1);
                        printf("%.2f m = %.2f ft\n", num1, result);
                        saveToHistory("Meters to Feet", num1, 0, result);

                        break;
                    }
                    case '6': {
                        printf("Enter length in feet: ");
                        num1 = getNumber();
                        result = feetToMeters(num1);
                        printf("%.2f ft = %.2f m\n", num1, result);
                        saveToHistory("Feet to Meters", num1, 0, result);

                        break;
                    }
                    default:
                        printf("\nInvalid choice!\n");
                }
                break;
            }
            case 'H': {
                readHistory();
                break;
            }

            case 'X': {
                printf("\nThank you for using the Scientific Calculator!\n");
                continueCalc = 0;
                break;
            }

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        
        if (continueCalc) {
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');
            getchar();
            clearScreen();

        }
    }

    return 0;
}

void displayMenu() {
    printf("Scientific Calculator Menu:\n");
    printf("Basic Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("\nAdvanced Operations:\n");
    printf("5. Power\n");
    printf("6. Nth Root\n");
    printf("7. Combination (nCr)\n");
    printf("8. Permutation (nPr)\n");
    printf("9. Statistical Functions\n");
    printf("\nTrigonometric Functions:\n");
    printf("A. Sine\n");
    printf("B. Cosine\n");
    printf("C. Tangent\n");
    printf("D. Arcsine\n");
    printf("E. Arccosine\n");
    printf("F. Arctangent\n");
    printf("\nOther Functions:\n");
    printf("M. Memory Operations\n");
    printf("U. Unit Conversions\n");
    printf("H. View Calculation History\n"); 
    printf("X. Exit\n");
}

void displayMemoryMenu() {
    printf("\nMemory Operations:\n");
    printf("1. Store value\n");
    printf("2. Recall value\n");
    printf("3. Clear memory\n");
    printf("4. Display all memory slots\n");
}

void displayUnitMenu() {
    printf("\nUnit Conversion Menu:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("5. Meters to Feet\n");
    printf("6. Feet to Meters\n");
}

void displayStatisticsMenu() {
    printf("\nStatistical Functions:\n");
    printf("1. Calculate Mean, Median, Mode, Variance, and Standard Deviation\n");
}

// Basic arithmetic implementations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

// Power and root functions implementations
double power(double base, double exponent) {
    return pow(base, exponent);
}

double square(double num) {
    return num * num;
}

double cube(double num) {
    return num * num * num;
}

double squareRoot(double num) {
    return sqrt(num);
}

double cubeRoot(double num) {
    return cbrt(num);
}

double nthRoot(double num, double n) {
    return pow(num, 1.0/n);
}

// Factorial and combination functions implementations
double factorial(double num) {
    if (num <= 1)
        return 1;
    return num * factorial(num - 1);
}

double permutation(double n, double r) {
    return factorial(n) / factorial(n - r);
}

double combination(double n, double r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Trigonometric functions implementations
double sine(double angle) {
    return sin(angle * PI / 180.0);
}

double cosine(double angle) {
    return cos(angle * PI / 180.0);
}

double tangent(double angle) {
    return tan(angle * PI / 180.0);
}

double arcsine(double value) {
    return asin(value) * 180.0 / PI;
}

double arccosine(double value) {
    return acos(value) * 180.0 / PI;
}

double arctangent(double value) {
    return atan(value) * 180.0 / PI;
}

double sineH(double angle) {
    return sinh(angle * PI / 180.0);
}

double cosineH(double angle) {
    return cosh(angle * PI / 180.0);
}

double tangentH(double angle) {
    return tanh(angle * PI / 180.0);
}

// Logarithmic functions implementations
double logarithm(double num) {
    return log10(num);
}

double naturalLog(double num) {
    return log(num);
}

double logBaseN(double num, double base) {
    return log(num) / log(base);
}

// Memory functions implementations
void initializeMemory(CalculatorMemory* mem) {
    for (int i = 0; i < MAX_MEMORY_SLOTS; i++) {
        mem->values[i] = 0;
        mem->isOccupied[i] = 0;
    }
}

void storeInMemory(CalculatorMemory* mem, int slot, double value) {
    mem->values[slot] = value;
    mem->isOccupied[slot] = 1;
}

double recallFromMemory(CalculatorMemory* mem, int slot) {
    return mem->values[slot];
}

void clearMemory(CalculatorMemory* mem, int slot) {
    mem->values[slot] = 0;
    mem->isOccupied[slot] = 0;
}

void displayMemoryContents(CalculatorMemory* mem) {
    printf("\nMemory Contents:\n");
    for (int i = 0; i < MAX_MEMORY_SLOTS; i++) {
        if (mem->isOccupied[i]) {
            printf("Slot %d: %.2f\n", i + 1, mem->values[i]);
        } else {
            printf("Slot %d: Empty\n", i + 1);
        }
    }
}

// Unit conversion functions implementations
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

double kilogramsToPounds(double kg) {
    return kg * 2.20462;
}

double poundsToKilograms(double lbs) {
    return lbs / 2.20462;
}

double metersToFeet(double meters) {
    return meters * 3.28084;
}

double feetToMeters(double feet) {
    return feet / 3.28084;
}

double radiansToDegrees(double radians) {
    return radians * 180.0 / PI;
}

double degreesToRadians(double degrees) {
    return degrees * PI / 180.0;
}

// Statistical functions implementations
void calculateStatistics(double* numbers, int count, double* mean, double* variance, double* stdDev) {
    // Calculate mean
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    *mean = sum / count;
    
    // Calculate variance
    sum = 0;
    for (int i = 0; i < count; i++) {
        sum += pow(numbers[i] - *mean, 2);
    }
    *variance = sum / count;
    
    // Calculate standard deviation
    *stdDev = sqrt(*variance);
}

double calculateMedian(double* numbers, int count) {
    // Sort numbers first
    bubbleSort(numbers, count);
    
    if (count % 2 == 0) {
        return (numbers[count/2 - 1] + numbers[count/2]) / 2;
    } else {
        return numbers[count/2];
    }
}

double calculateMode(double* numbers, int count) {
    double mode = numbers[0];
    int maxCount = 1;
    
    for (int i = 0; i < count; i++) {
        int currentCount = 1;
        for (int j = i + 1; j < count; j++) {
            if (numbers[j] == numbers[i]) {
                currentCount++;
            }
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            mode = numbers[i];
        }
    }
    
    return mode;
}

void bubbleSort(double* numbers, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

// Utility functions implementations
double getNumber() {
    double num;
    while (scanf("%lf", &num) != 1) {
        printf("Invalid input! Please enter a number: ");
        while (getchar() != '\n');
    }
    return num;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void handleError(const char* message) {
    printf("\nError: %s\n", message);
}

void saveToHistory(const char* operation, double num1, double num2, double result) {
    FILE *file = fopen("history.txt", "a"); // Open in append mode
    if (file == NULL) {
        printf("Error opening history file!\n");
        return;
    }
    fprintf(file, "%s: %.2f, %.2f = %.2f\n", operation, num1, num2, result);
    fclose(file);
}

void readHistory() {
    FILE *file = fopen("history.txt", "r"); // Open in read mode
    if (file == NULL) {
        printf("No history available.\n");
        return;
    }
    printf("\n=== Calculation History ===\n");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}
