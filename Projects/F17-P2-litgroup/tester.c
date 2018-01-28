#include "parser.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	struct student *head;
	char error_string[1024];
	memset(error_string, 0, sizeof(error_string));

	if (argc != 2) {
		fprintf(stderr, "USAGE: [driver|static-driver] input_file\n");
	} else {
		head = read_bin(argv[1], error_string);
		if (head == NULL) {
			printf("READ failure: %s\n", error_string);
		}
	}

	return 0;
}
