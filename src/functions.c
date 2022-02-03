#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "include/functions.h"

void echo(char text[256]) {
	printf("%s\n", text);
}

int help(void) {
	printf("%s, v%s\n", APPNAME, APPVER);
	printf("\e[7m\e[1m\e[94mUSAGE:\e[0m\n-------\n\e[4m\e[92mpi-apps [option]\e[0m\n\n");
	printf("\e[7m\e[1m\e[94mAvailable options:\e[0m\n-------------------\n");
	printf("\n\e[100minstall \"[appname]\"\e[0m - install any app available on pi-apps.\n");
	printf("\n\e[100muninstall \"[appname]\"\e[0m - uninstall any app installed by pi-apps. You can also use \e[100mremove\e[0m.\n");
        printf("\n\e[100mlist-all \e[0m - list all apps available in pi-apps.");
	printf("\n\e[100mupdate\e[0m - update pi-apps.\n");
	printf("\n\e[100mgui\e[0m - start pi-apps gui.\n");
	printf("=====\n");
	printf("\nIf you don't pass any option, pi-apps will start normally.\n");
}

int about(void) {
	printf("Pi-Apps CLI v%s\n", APPVER);
}

int listall(void) {
        char dir[128] = {0};
        char *home = getenv("HOME");
	if(d == NULL) {
                fprintf(stderr, "error: %s\n", strerror(errno));
                return 1;
        }
        strcat(dir, home);
        strcat(dir, "/pi-apps/apps");
        struct dirent *entry = NULL;
        DIR *d = opendir(dir);
        while((entry = readdir(d)) != NULL) {
                printf("%s\n", entry->d_name);
        }
        closedir(d);
        return 0;
}
