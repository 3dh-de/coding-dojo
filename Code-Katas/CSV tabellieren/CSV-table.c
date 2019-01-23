/**
 * Code Kata "CSV tabellieren"
 * 
 * @see https://ccd-school.de/coding-dojo/function-katas/csv-tabellieren/
 */
 
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLUMS     255
#define MAX_ROWS       2048
#define MAX_TEXTLENGTH 1024

/**
 * Define nice looking types for complex arrays
 */
typedef char         columnsArray[MAX_COLUMS][MAX_TEXTLENGTH];
typedef int          columnWidthsArray[MAX_COLUMS];
typedef columnsArray rowsArray[MAX_ROWS];

/**
 * Print given array as formatted table row 
 * 
 * @arg int columCount
 * @arg char[][] columValues
 * @arg int[] columWidths 
 */
void printTableRow(int columCount, columnsArray columnValues, columnWidthsArray columWidths) {
   if (columCount < 1 || columCount > MAX_COLUMS) {
       printf("Error: too much colums given for printTableRow()!");
       return;
   }
   
   // @see https://stackoverflow.com/questions/4133318/variable-sized-padding-in-printf
   for (int column = 0; column < columCount; ++column) {
       printf("| %*s ", columWidths[column], columnValues[column]);
   }
   printf("|\n");
}

/**
 * Parse and display CSV file as formatted table
 */
int main(void) {
	// your code goes here
	int rowCount = 4;
	
	// @see https://www.programiz.com/c-programming/c-multi-dimensional-arrays  
	rowsArray rows = {
	    { "Head1", "Head2", "Head3" },
	    { "r1 c1", "r1 c2", "r1 c3" },
	    { "r2 c1", "r2 c2", "r2 c3" },
	    { "r3 c1", "r2 c2", "r3 c3" },
	    { "r4 c1", "r4 c2", "r4 c3" }
	};
	
	columnWidthsArray columnWidths = { 6, 12, 30 };
	
	printTableRow(3, rows[0], columnWidths);
	
	return 0;
}
