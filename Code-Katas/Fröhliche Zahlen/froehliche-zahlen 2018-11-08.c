/**
 * Code Kata:
 * https://ccd-school.de/coding-dojo/function-katas/froehliche-zahlen/
 *
 * Author:  Christian Daehn
 * License: MIT copyleft license
 */
 
#include <stdio.h>

#define MAX_STRING_LENGTH 1024
#define MAX_LOOPS          100

int main(void) {
    char str[MAX_STRING_LENGTH + 1];

    for (int i = 10; i < 21; ++i) {
        int loops  = 0;
        int number = i;
        
        while (++loops < MAX_LOOPS && number != 1) {
            snprintf(str, MAX_STRING_LENGTH, "%d", number);
            int sum = 0;
            for (int c = 0; c < strlen(str); ++c) {
                int digit = str[c] - '0';
                sum += digit * digit;
            }
            printf("startvalue: %2d  loop: %3d  number: %4s  sum: %3d\n", i, loops, str, sum);
            number = sum;
            
            if (number == 1) {
                printf("*** %d is a happy number! ***\n", i);
                break;
            }
        }
    }
    
	// your code goes here
	return 0;
}

