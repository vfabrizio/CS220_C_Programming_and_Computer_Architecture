#include "define.h"
#include<stdio.h>
#include<math.h>

float distance(struct point p1, struct point p2) {
	float xVal = pow(p1.x - p2.x, 2);
	float yVal = pow(p1.y - p2.y, 2);
	float zVal = pow(p1.z - p2.z, 2);
	float retVal = sqrt(xVal + yVal + zVal);
	return retVal;
}

int strrindex(char s[], char t[]) {
	int i, j, count, ans;
	int lenS, lenT;
	count = j = lenS = lenT = 0;
	ans = -1;
	for (i = 0; i < 200; i++) {
		if (s[i] == '\0') {
			break;
		}
		lenS++;
	}
	for (i = 0; i < 200; i++) {
		if (t[i] == '\0') {
			break;
		}
		lenT++;
	}
	/*printf("length of s: %d\n", lenS);
	printf("length of t: %d\n", lenT);*/
	for (i = 0; i < lenS; i++) {
		if (j == lenT) {
			j = 0;
		}
		/*printf("s[%d]: %c t[%d]: %c\n", i, s[i], j, t[j]);*/
		if (s[i] == t[j]) {
			count++;
			j++;
		}
		
		if (count == lenT) {
			ans = i+1 - count;
			count = 0;
		}
	}
	return ans;
}


int is_int(char str[]) {
	int i, len, retVal;
	i = len = 0;
	retVal = 1;
	for (i = 0; i < 200; i++) {
		if (str[i] == '\0') {
			break;
		}
		len++;
	}
	/*printf("retVal = %d\n", retVal);*/
	for (i = 1; i < len; i++) {
		if (str[0] == '-') {
			if (str[1] == '0' || str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5' || str[1] == '6' || str[1] == '7' || str[1] == '8' || str[1] == '9')  {
				retVal == 1;
			}else {
				retVal = 0;
			}
		}
		/*printf("retVal = %d, str[%d] = %c\n", retVal, i, str[i]);*/
		if (retVal == 1) {
			if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')  {
				retVal = 1;
			}else {
				retVal = 0;
			}
		}
		/*printf("retVal = %d, str[%d] = %c\n", retVal, i, str[i]);*/
	}
	return retVal;
}




