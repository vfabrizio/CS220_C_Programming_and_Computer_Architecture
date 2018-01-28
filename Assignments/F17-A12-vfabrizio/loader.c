#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
	/* TODO: Declare a function pointer type that matches the
	 * calc function's type. Call it  "Calc_fptr"*/
	typedef int (*Calc_fptr) (char, int, int);

	FILE *fp;
	unsigned int i;
	Calc_fptr calculator;

	/* TODO: if number of arguments is not 4 (5 including program name)
		print ("Usage %s <filename> <uint> <operation> <uint>\n", argv[0]) and exit */
	if (argc != 5) {
		printf("Usage %s <filename> <uint> <operation> <uint>\n", argv[0]);
		exit(0);
	}

	/* TODO: Open and read the binary file into raw_bytes. Use fopen and fread. */
	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		printf("Cannot open file\n");
		exit(0);
	}

	fseek(fp, 0L, SEEK_END);
	i = (unsigned int) ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	/* TODO: Declare an array large enough to hold the raw bytes. Raw bytes are best stored in byte-addressable arrays. Pick the appropriate type. Call it "raw_bytes"*/
	unsigned char raw_bytes[i];

	fread(&raw_bytes, sizeof(unsigned char), i, fp);
	
	/*mprotect(raw_bytes, i, PROT_EXEC);
	mprotect(raw_bytes, i, PROT_READ);*/
	
	calculator = (Calc_fptr) raw_bytes;

	/* TODO: Print the result. Refer to sample input and output. */
	int result = calculator (*argv[3], atoi(argv[2]), atoi(argv[4]));
	printf("%d %c %d = %d\n", atoi(argv[2]), *argv[3], atoi(argv[4]), result);
	
	fclose(fp);

	return 0;
}
