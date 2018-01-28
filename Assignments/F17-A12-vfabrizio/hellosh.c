/* hellosh.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define DELIM " \t\r\n\a"

char **split_args(char *line) {
	int buffer_size = 64;
	char **tokens = (char **) malloc (buffer_size * sizeof(char *));
	char *token;
	int i = 0;
	if (tokens == NULL) {
		printf("Allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);
	while (token != NULL) {
		tokens[i] = token;
		i++;

		if(i >= buffer_size) {
			buffer_size += 4;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (tokens == NULL) {
				printf("Allocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}

	tokens[i] = NULL;
	return tokens;
}

int main() {
	char line[1024];
	int pid, i;
	char **args;

	while(1) {
		printf("Hello!!>");
		if(!fgets(line, 1023, stdin)) {
			break;
		}

		if(strcmp(line, "exit\n") == 0) break;

		for(i = 0; i< strlen(line); i++) {
			if(line[i] == '\n') line[i] = '\0';
		}

		args = split_args(line);

		pid = fork();

		if(pid == 0) {
			/* This is the child */
			execvp(args[0], args);
			fprintf(stderr, "Hello!!: %s\n", strerror(errno));
			exit(errno);
		} else {
			/* This is the parent */
			wait(NULL);
		}
	}
	return 0;
}
