#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

int global_var = 4;

/*each thread could get a different worker function or the same worker function could be used by multiple functions*/

void *worker_function(void *payload) {
	/*thread's code goes here*/
	global_var++;
	printf("In thread %d\n", (int) payload);
}

#define NUM_THREADS 3

int main() {
	pthread_t threads [NUM_THREADS];
	int i;
	
	/*declare payload here*/
	int payload = 0;
	
	
	for(i=0; i < NUM_THREADS; i++) {
		pthread_create(&threads[i], NULL, worker_function, (void *) payload);
		printf("%d\n", (int) global_var);
		payload++;
	}
	
	printf("In main thread\n");
	
	for(i=0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
		printf("%d\n", (int) global_var);
	}
	
	
	printf("Exiting main thread\n");
	pthread_exit(NULL);
	return 0;
}
