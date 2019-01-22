#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGE_MIN  10
#define RANGE_MAX  20
#define MAX_LOOP_CYCLES  10
#define MAX_STRING_LENGTH  1024

using namespace std;

/**
 * Take the digits of given number, calculate and return their sum.
 */
int sumOfDigits(int number, int origNumber = -1, int loopCycle = 0) {
    char str[MAX_STRING_LENGTH] = "";
    snprintf(str, MAX_STRING_LENGTH - 1, "%d", number);
    
    origNumber = (origNumber == -1) ? number : origNumber;
    
    int sum = 0;
    for (int i = 0; i < strlen(str); ++i) {
        int digit = str[i] - '0';   // substract the ASCII value of "0" to get the digit value
        sum += digit * digit;
    }
    
    printf("number #%03d  loop #%02d  sumOfDigits for %03d = %03d\n", origNumber, loopCycle, number, sum);

	if (sum == 1) {
	    printf("*** found HAPPY NUMBER: %d ***\n", number);
	    return 1;
	}

    if (MAX_LOOP_CYCLES && loopCycle < MAX_LOOP_CYCLES && sum > 9) {
        return sumOfDigits(sum, origNumber, ++loopCycle);
    }    
    return sum;
}

int main(void) {
    // 1. Step: develop & test the summing algorithm
	printf("num 23...\n");
	sumOfDigits(23);
	
	// 2. Step: get the "happy numbers" between RANGE_MIN and RANGE_MAX
	for (int i = RANGE_MIN; i <= RANGE_MAX; ++i) {
	    sumOfDigits(i);
	}
	return 0;
}

