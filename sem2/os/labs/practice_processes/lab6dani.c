#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char source[50];
	char keychar;

	printf("Read filename: ");
	scanf("%s", source);
	printf("Read key: ");
	scanf("\n%c", &keychar);

	if(fork() == 0) {
		char destination[60];
		strcpy(destination, source);
		strcat(destination, ".crypt");
		
		FILE * in = fopen(source, "r");
	
		if(in == NULL) {
			printf("Input file not found.\n");
			fclose(in);
			exit(1);
		}
	
		FILE * out = fopen(destination, "w");
		
		char buffer[300];
		while(fread(buffer, 1, sizeof(buffer), in)) {
			int len = strlen(buffer), i;
			for(i = 0; i < len; i++)
				buffer[i] ^= keychar;
			fprintf(out, "%s", buffer);
		}

		printf("Crypting done in \"%s\".\n", destination);

		fclose(in);
		fclose(out);
		exit(0);
	}

	return 0;
}
