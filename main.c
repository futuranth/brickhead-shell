#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	while(true) {
		char * restrict command;
		printf("bsh $ ");
		scanf("%s", command);
		if(feof(stdin) || ! strcmp(command, "exit")) break;
		pid_t child = fork();
		char * child_argv[] = {command};
		if(child == 0) {
			execv(command, child_argv);
		} else waitpid(child, 0, 0);
		if(errno) {
			perror("Error in bsh");
			continue;
		}
	}
	printf("Exit\n");
	return 0;
}
