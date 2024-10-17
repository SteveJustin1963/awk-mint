#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define DEFAULT_DELIMITER " "  // Default delimiter (whitespace)

// Function prototypes
void process_line(char *line, const char *delimiter, int choice);
void print_specific_columns(char **fields, int num_fields, int col1, int col2);
void sum_column(char **fields, int num_fields, int col);
void condition_check(char **fields, int num_fields, int col, int threshold);
void formatted_print(char **fields, int num_fields);
void list_commands();

// Global variable for summing column values
static int sum_col2 = 0;  // Running sum for column 2

// Function to split and process the entered string based on the chosen commands
void process_line(char *line, const char *delimiter, int choice) {
    char *fields[MAX_FIELDS];
    int num_fields = 0;
    char *token = strtok(line, delimiter);
    
    // Tokenize the input string based on the delimiter
    while (token != NULL) {
        fields[num_fields++] = token;
        token = strtok(NULL, delimiter);
    }

    // Run the selected command
    switch (choice) {
        case 1:
            print_specific_columns(fields, num_fields, 1, 3);  // Print columns 1 and 3
            break;
        case 2:
            sum_column(fields, num_fields, 2);                 // Sum values in column 2
            break;
        case 3:
            condition_check(fields, num_fields, 3, 100);       // Check if column 3 > 100
            break;
        case 4:
            formatted_print(fields, num_fields);               // Formatted output
            break;
        case 5:
            printf("Printing entire line:\n%s\n", line);       // Print entire line
            break;
        case 6:
            printf("Number of fields: %d\n", num_fields);      // Print number of fields (NF)
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

// Function to print specific columns
void print_specific_columns(char **fields, int num_fields, int col1, int col2) {
    if (col1 <= num_fields && col2 <= num_fields) {
        printf("Columns %d and %d: %s %s\n", col1, col2, fields[col1 - 1], fields[col2 - 1]);
    } else {
        printf("Invalid column numbers\n");
    }
}

// Function to sum values in a specified column
void sum_column(char **fields, int num_fields, int col) {
    if (col <= num_fields) {
        sum_col2 += atoi(fields[col - 1]);  // Convert field to integer and add to sum
    }
    printf("Running sum of column %d: %d\n", col, sum_col2);
}

// Function to check if a value in a column exceeds a threshold
void condition_check(char **fields, int num_fields, int col, int threshold) {
    if (col <= num_fields) {
        int value = atoi(fields[col - 1]);
        if (value > threshold) {
            printf("Column %d has value greater than %d: %d\n", col, threshold, value);
        }
    }
}

// Function to print formatted output (similar to AWK printf)
void formatted_print(char **fields, int num_fields) {
    if (num_fields > 1) {
        printf("Formatted output: %-10s %5.2f\n", fields[0], atof(fields[1]));
    }
}

// Function to list available commands (comprehensive AWK-like commands)
void list_commands() {
    printf("\nChoose from a comprehensive list of AWK commands:\n");
    printf("1. Print specific columns (1 and 3)\n");
    printf("2. Sum values in column 2\n");
    printf("3. Check if column 3 is greater than 100\n");
    printf("4. Print formatted output (AWK printf style)\n");
    printf("5. Print the entire line\n");
    printf("6. Print the number of fields (NF)\n");
}

// Main function for interactive string input processing
int main() {
    char input[MAX_LINE_LENGTH];
    char delimiter[10];
    char choice;
    int command_choice;

    // Prompt user for the input string
    printf("Enter the string to process (space-delimited by default):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove the newline character

    // Ask if user wants a custom delimiter
    printf("Do you want to specify a custom delimiter? (y/n): ");
    scanf(" %c", &choice);  // Note the space before %c to consume leftover newline

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the delimiter to use (e.g., space, comma): ");
        scanf("%s", delimiter);
    } else {
        strcpy(delimiter, DEFAULT_DELIMITER);  // Use default whitespace delimiter
    }

    // List available commands and prompt the user to choose one
    list_commands();
    printf("Enter the number of the command you want to run: ");
    scanf("%d", &command_choice);

    // Process the entered string using the selected command and delimiter
    process_line(input, delimiter, command_choice);

    return 0;
}
