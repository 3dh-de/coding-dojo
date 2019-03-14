#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLUMNS 4

int main(void) {

    const char* table[ROWS][COLUMNS] = {
        { "Name", "Strasse", "Ort", "Alter" },
        { "Peter Pan", "Am Hang 5", "12345 Einsam", "42" },
        { "Maria Schmitz", "Koelner Strasse 45", "50123 Koeln", "43" },
        { "Paul Meier", "Muenchener Weg 1", "87654 Muenchen", "65" }
    };
    
    int maxLength[COLUMNS];
    int lineLength = COLUMNS + 2;
    
    for (int row = 0; row < ROWS; ++row) {
        for (int column = 0; column < COLUMNS; ++column) {
            int len = strlen(table[row][column]);
            if (row == 0 || maxLength[column] < len) {
                maxLength[column] = len;
            }
            // DEBUG:
            if (row + 1 == ROWS) {
                lineLength += maxLength[column];
                printf("column #%d maxlength = %d\n", column, maxLength[column]);
            }
        }
    }
    
    char* line = (char*)malloc(lineLength);
    memset(line, '-', lineLength);
    line[lineLength-1] = '\0';
    
    printf("%s\n", line);
    for (int row = 0; row < ROWS; ++row) {
        for (int column = 0; column < COLUMNS; ++column) {
            if (column == 0) { 
                printf("|"); 
            }
            printf("%-*s|", maxLength[column], table[row][column]);
        }
        printf("\n");
        if (row == 0 || row + 1 == ROWS) {
            printf("%s\n", line);
        }
    }
    
	return 0;
}
