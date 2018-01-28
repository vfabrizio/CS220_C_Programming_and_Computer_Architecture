#include <stdio.h>
#include <pthread.h>

char array[256];

void *write(void *param) {
	printf("%s\n", array);
}

void *read(void *param) {
	printf("enter a message:\n");
	fgets(array, 256, stdin);
}

int main() {
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, read, NULL);
	pthread_join(tid1, NULL);
	
	pthread_create(&tid2, NULL, write, NULL);	
	pthread_join(tid2, NULL);

	return 0;
}