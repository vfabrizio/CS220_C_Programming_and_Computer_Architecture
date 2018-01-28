#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define LOOPS 10
#define TIMES 1000000

extern void nop_0();
extern void nop_100();

int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void timeval_print(char *str, struct timeval *tv)
{
    printf("%s %ld sec, %06ld micro sec\n", str, tv->tv_sec, tv->tv_usec);
}

int main() {
	int i = 0;
	int j = 0;
	struct timeval tvDiff100, tvDiff0, tvDiff_final, tvStart, tvEnd;
	double accum = 0.0;

	for (j = 0; j < LOOPS; j++) {
		gettimeofday(&tvStart, NULL);
		for (i = 0; i < TIMES; i++) {
			nop_100();
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff100, &tvEnd, &tvStart);
		/*timeval_print("100 NOP: ", &tvDiff100);*/

		
		gettimeofday(&tvStart, NULL);
		for (i = 0; i < TIMES; i++) {
			nop_0();
		}
		gettimeofday(&tvEnd, NULL);
		timeval_subtract(&tvDiff0, &tvEnd, &tvStart);
		/*timeval_print("0 NOP: ", &tvDiff0);*/

		timeval_subtract(&tvDiff_final, &tvDiff100, &tvDiff0);
		/*timeval_print("subtracted: ", &tvDiff_final);*/
		accum += tvDiff_final.tv_sec + (tvDiff_final.tv_usec / 1000000.0);
	}

	/*printf("average: %f\n", avg);*/
	printf("%.2e\n", ( (TIMES*100) / (accum / LOOPS) ));

	return 0;
}