#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File created successfully: %s\n", filename);
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    char data[1000];
    printf("Enter data to write (end with # in a new line):\n");
    while (fgets(data, sizeof(data), stdin)) {
        if (data[0] == '#' && data[1] == '\n') break;
        fputs(data, fp);
    }

    printf("Data written successfully.\n");
    fclose(fp);
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }

    char data[1000];
    printf("Enter data to append (end with # in a new line):\n");
    while (fgets(data, sizeof(data), stdin)) {
        if (data[0] == '#' && data[1] == '\n') break;
        fputs(data, fp);
    }

    printf("Data appended successfully.\n");
    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char ch;
    printf("Contents of the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    char filename[100];
    int choice;

    printf("Enter file name: ");
    scanf("%s", filename);
    getchar(); // consume newline

    while (1) {
        printf("\n--- File Operations Menu ---\n");
        printf("1. Create File\n");
        printf("2. Write to File (overwrite)\n");
        printf("3. Append to File\n");
        printf("4. Read File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                readFile(filename);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
