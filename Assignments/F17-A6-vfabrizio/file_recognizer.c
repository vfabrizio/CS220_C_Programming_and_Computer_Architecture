#include "file_recognizer.h"
#include <stdio.h>


void readfile(const char *filename) {

	FILE *fp = fopen(filename, "r");
	unsigned char arr[8];
	int correct = 1;
	int i;

	if (fp == 0) {
		printf("Invalid input.\n");
	}else {
		fread(arr, 1, 8, fp);
		/*for (int i = 0; i < 8; i++) {
			printf("arr[%d] = %lx\n", i, arr[i]);
		}*/
	
		fclose(fp);

		/*test GIF*/
		for (i = 0; i < 6; i++) {
			if (arr[i] ==  allfiles[0].signature[i] || arr[i] == allfiles[1].signature[i]) {
				correct = 1;
			}else {
				correct = 0;
				break;
			}
		}
		if (correct == 1) {
			printf("%s\n", allfiles[0].type);
			return;
		}
	
		/*test ELF*/
		for (i = 0; i < 4; i++) {
			if (arr[i] ==  allfiles[2].signature[i]) {
				correct = 1;
			}else {
				correct = 0;
				break;
			}
		}
		if (correct == 1) {
			printf("%s\n", allfiles[2].type);
			return;
		}
	
		/*test PDF*/
		for (i = 0; i < 4; i++) {
			if (arr[i] == allfiles[3].signature[i]) {
				correct = 1;
			}else {
				correct = 0;
				break;
			}
		}
		if (correct == 1) {
			printf("%s\n", allfiles[3].type);
			return;
		}
	
		/*test ZIP*/
		for (i = 0; i < 2; i++) {
			if (arr[i] ==  allfiles[4].signature[i]) {
				correct = 1;
			}else {
				correct = 0;
				break;
			}
		}
		if (correct == 1) {
			printf("%s\n", allfiles[4].type);
			return;
		}
	
		/*test Java*/
		for (i = 0; i < 4; i++) {
			if (arr[i] ==  allfiles[5].signature[i]) {
				correct = 1;
			}else {
				correct = 0;
				break;
			}
		}
		if (correct == 1) {
			printf("%s\n", allfiles[5].type);
			return;
		}

		/*test PNG*/
		for (i = 0; i < 8; i++) {
			if (arr[i] ==  allfiles[6].signature[i]) {
				correct = 1;
			}else {
				correct = 0;
				break;
			}
		}
		if (correct == 1) {
			printf("%s\n", allfiles[6].type);
			return;
		}


		printf("File type unknown.\n");
	}
}


int main(int argc, char const *argv[]) {
	
	if (argc != 2) {
		printf("Invalid input.\n");
	}else {
		readfile(argv[1]);
	}
	return 0;
}
