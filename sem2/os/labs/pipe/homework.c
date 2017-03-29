#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	int sp[2]; // shared pipe channel between main and children
	pipe(sp); // establish communication between main and children

	// iterate through arguments from command line
	int i;
	for (i = 1; i < argc; i++) {
		if (fork() == 0) {
			// I'm in child (process A)
			int pp[2]; // private pipe channel between current child and nephew
			pipe(pp); // establish communication between child and nephew

			if (fork() == 0) {
				// I'm in nephew (process B)

				// launch command for counting vowels
				char cmd[50];
				sprintf(cmd, "echo %s | grep -o [aeiouAEIOU] | wc -l", argv[i]);
				FILE * np = popen(cmd, "r");

				// retrieve information from command
				int vowels = 0;
				fscanf(np, "%d", &vowels);
				pclose(np);

				// send information from nephew to child
				write(pp[1], &vowels, sizeof(vowels));
				close(pp[0]);
				close(pp[1]);

				exit(0);
			}

			wait(0);

			int vowels = 0;
			// retrieve information from nephew
			read(pp[0], &vowels, sizeof(vowels));
			close(pp[0]);
			close(pp[1]);

			// send information from child to main
			write(sp[1], &vowels, sizeof(vowels));
			close(sp[0]);
			close(sp[1]);

			exit(0);
		}

		wait(0);

		// retrieve information from child
		int vowels;
		read(sp[0], &vowels, sizeof(vowels));
		printf("\"%s\" has %d vowels.\n", argv[i], vowels);
	}

	close(sp[0]);
	close(sp[1]);

	return 0;
}
