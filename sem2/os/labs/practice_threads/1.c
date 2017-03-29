#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int total_lines;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* count(void* _filename) {
	char* filename = (char*)_filename;
	char cmd[256];
	sprintf(cmd, "cat %s 2> /dev/null | wc -l", filename);
	FILE* p = popen(cmd, "r");
	int nr_lines = 0;
	fscanf(p, "%d", &nr_lines);
	
	printf("File \"%s\" has %d lines.\n", filename, nr_lines);

	pthread_mutex_lock(&mutex);
	total_lines += nr_lines;
	pthread_mutex_unlock(&mutex);
	
	return NULL;
}

int main(int argc, char** argv) {
	int i;
	pthread_t* threads = (pthread_t*)malloc(argc * sizeof(pthread_t));
	
	for(i = 1; i < argc; i++) 
		pthread_create(&threads[i], NULL, count, (void*)argv[i]);	
	
	for(i = 1; i < argc; i++)
		pthread_join(threads[i], NULL);

	printf("Total lines: %d\n", total_lines);

	free(threads);
	return 0;
}
