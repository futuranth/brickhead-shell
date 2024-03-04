#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
	char * command;
	scanf("%s", command);
	pid_t child = fork();
	char * child_argv[] = {"NULL"};
	if(child == 0) {
		execv(command, child_argv);
		exit(127);
	} else waitpid(child, 0, 0);
	return 0;
}
