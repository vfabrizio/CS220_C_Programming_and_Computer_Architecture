#include <stdio.h>
#include <unistd.h>

int main() {
	int x = 1;
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		x++;
		printf("x child=%d\n", x);
		printf("In child\n");
		printf("pid in child: %d\n", getpid());
		printf("parent pid in child: %d\n", getppid());
	} else {
		x--;
		printf("x parent=%d\n", x);
		sleep(1);
		printf("In parent\n");
		printf("pid: %d\n", pid);
		printf("parent pid: %d\n", getppid());
	}

	return 0;
}
