#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int init() {
	return rand()%9001+1000;
}

int scade() {
	return rand()%11+10;
}

int main(int argc, char** argv) {
	srand(clock());

	int N, i;
	if(argc > 1) sscanf(argv[1], "%d", &N);
	else return 0 * printf("Nu exista numar.\n");

	printf(">> Se creeaza %d procese.\n", N);

	int p2c[2];
	int val;

	val = init(); printf(">> S-a pornit cu %d.\n", val);
	pipe(p2c);
	write(p2c[1], &val, sizeof(val));

	for(i = 0; i < N; i++) {
		read(p2c[0], &val, sizeof(val));printf("S-a primit %d.\n", val);
		val -= scade();
		
		if(i == N-1) {
			printf(">> S-a finalizat cu %d.\n", val);
			exit(0);
		}
		
		pipe(p2c);

		wait(0);
	
		if(fork() != 0) {
			write(p2c[1], &val, sizeof(val));
			exit(0);
		}
	}
	
	return 0;
}
