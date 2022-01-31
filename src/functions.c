#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void echo(char text[256]) {
	printf("%s\n", text);
}

int help(void) {
	printf("%s, v%s\n", APPNAME, APPVER);
	printf("\e[7m\e[1m\e[94mUSAGE:\e[0m\n-------\n\e[4m\e[92mpi-apps [option]\e[0m\n\n");
	printf("\e[7m\e[1m\e[94mAvailable options:\e[0m\n-------------------\n");
	printf("\n\e[100minstall \"[appname]\"\e[0m - install any app available on pi-apps.\n");
	printf("\n\e[100muninstall \"[appname]\"\e[0m - uninstall any app installed by pi-apps. You can also use \e[100mremove\e[0m.\n");
	printf("\n\e[100mupdate\e[0m - update pi-apps.\n");
	printf("\n\e[100mgui\e[0m - start pi-apps gui.\n");
	printf("=====\n");
	printf("\nIf you don't pass any option, pi-apps will start normally.\n");
}

int about(void) {
	printf("Pi-Apps CLI v%s\n", APPVER)
}


/*
int list_all(void) {
    char command[40];
    strcpy(command, "cd $");
}
*.
*/
