#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h> 

int main() {
	srand(clock());

	int child;
	int c2p[2];
	int p2c[2];

	pipe(c2p);
	pipe(p2c);

	if((child = fork()) == 0) {
		int a, b, sum;
		read(p2c[0], &a, sizeof(a));
		read(p2c[0], &b, sizeof(b));
		
		sum = a + b;

		printf("Fiul insumeaza %d si %d.\n", a, b);

		write(c2p[1], &sum, sizeof(sum));

		close(c2p[0]); close(c2p[1]);
		close(p2c[0]); close(p2c[1]);

		exit(0);
	}

	int a = rand()%10+1, b = rand()%10+1, sum;
	write(p2c[1], &a, sizeof(a));
	write(p2c[1], &b, sizeof(b));
	
	read(c2p[0], &sum, sizeof(sum));

	printf("Parintele primeste suma %d.\n", sum);
	
	close(c2p[0]); close(c2p[1]);
	close(p2c[0]); close(p2c[1]);	

	wait(0);

	return 0;
}
