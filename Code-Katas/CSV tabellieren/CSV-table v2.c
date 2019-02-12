#include <stdio.h>
#include <string.h>

int main(void) {
	// your code goes here
	
	const int rowsCount = 4;
	const int columnsCount = 4;

	char rows[255][255][255] = { 
	    { "Name", "Strasse", "Ort", "Alter" },
        { "Peter Pan", "Am Hang 5", "12345 Einsam", "42" },
        { "Maria Schmitz", "Koelner Strasse 45", "50123 Koeln", "43" },
        { "Paul Meier", "Muenchener Weg 1", "87654 Muenchen", "65" }
	};
	
	// create array for column widths 
	int columnWidths[columnsCount];
	for (int c = 0; c < columnsCount; ++c) { 
	    columnWidths[c] = 0; 
	}
	
	// get max width for each column
	for (int r = 0; r < rowsCount; ++r) {
	    for (int c = 0; c < columnsCount; ++c) {
	        int length = strlen(rows[r][c]);
	        if (length > columnWidths[c]) {
	            columnWidths[c] = length;
	        }
	        //printf("[debug] get max width for row #%d column #%d: length=%d maxWidth=%d \n",
	        //    r, c, length, columnWidths[c]);
	    }
	}
	
	// output all rows with given fixed column width
	for (int r = 0; r < rowsCount; ++r) {
	    // print table border
	    if (r < 2) {
	        for (int c = 0; c < columnsCount; ++c) {
	            printf("|%.*s", columnWidths[c], "--------------------------------------------------------------------------");
	        }
    	    printf("|\n");
        }
        // print column values
	    for (int c = 0; c < columnsCount; ++c) {
            printf("|%*s", columnWidths[c], rows[r][c]);
	    }
	    printf("|\n");
	}
    for (int c = 0; c < columnsCount; ++c) {
        printf("|%.*s", columnWidths[c], "--------------------------------------------------------------------------");
    }
    printf("|\n");
	
	return 0;
}
