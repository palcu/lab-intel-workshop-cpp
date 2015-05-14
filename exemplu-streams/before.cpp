#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const unsigned MAX_NAME_LENGTH = 30;

struct FullName {
    char surname[MAX_NAME_LENGTH];
    char firstName[MAX_NAME_LENGTH];
};

int readNamesFromFile(const char* fileName, FullName*& names) {
    FILE * file = fopen(fileName, "r");
    int nameCount=0;
    FullName name;
    while ( fscanf(file, "%s %s", name.firstName, name.surname) == 2) {
        nameCount++;
        names = (FullName*)realloc(names, nameCount*sizeof(FullName));
        names[nameCount - 1] = name;
    }
    fclose(file);
    return nameCount;
}

void printNamesForsurname(int nameCount, char searchedSurname[], FullName* names) {
    unsigned foundNamesCount = 0;
    for (unsigned int i = 0; i < nameCount; i++) {
        if (strcmp(names[i].surname, searchedSurname) == 0) {
            foundNamesCount++;
            printf("%s\n", names[i].firstName);
        }
    }
    if (foundNamesCount == 0) {
        printf("No first name found for surname %s\n", searchedSurname);
    }
}

int main() {
    FullName* names = NULL;
    int nameCount = readNamesFromFile("input.txt", names);

    printf("Enter surname: ");
    char searchedSurname[MAX_NAME_LENGTH];
    scanf("%s", searchedSurname);
    printNamesForsurname(nameCount, searchedSurname, names);

    free(names);
    return 0;
}


