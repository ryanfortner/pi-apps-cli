#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "include/functions.h"

int main(int argc, char **argv) {
	char app[50], command[50];
	while(argc>1) {
		if(!strcmp(argv[1],"install")) {
			if(!app) {
				strcpy(app, argv[2]);
			} else {
				fprintf(stderr, "\e[31m\e[1mERROR:\e[0m\e[31m 'install' option passed, but no app provided!\e[0m\n");
				break;
			}
			strcpy(command, "$HOME/pi-apps/manage install ");
			strcat(command, app);
			system(command);
			break;
		} else if(!strcmp(argv[1], "uninstall") || !strcmp(argv[1], "remove")) {
			if(!app) {
				strcpy(app, argv[2]);
			} else {
				fprintf(stderr, "\e[31m\e[1mERROR:\e[0m\e[31m 'install' option passed, but no app provided!\e[0m\n");
				break;
			}
			strcpy(command, "$HOME/pi-apps/manage uninstall ");
			strcat(command, app);
			system(command);
			break;
		} else if(strcmp(argv[1], "update")==0) {
			system("echo 'u' | $HOME/pi-apps/updater");
			break;
		} else if(strcmp(argv[1], "list-all")==0) {
			listall();
			break;
		} else if(strcmp(argv[1], "gui")==0) {
			system("$HOME/pi-apps/gui");
			break;
		} else if(!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help") || !strcmp(argv[1], "--help") || !strcmp(argv[1], "help")) {
			help();
			break;
		} else if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version") || !strcmp(argv[1], "-a") || !strcmp(argv[1], "--about")) {
			about();
			break;
		} else {
			fprintf(stderr, "\e[1m\e[31mInvalid option '%s'!\e[0m\n", argv[1]);
			break;
		}
	}
	if(argc==1) {
		system("$HOME/pi-apps/gui");
	}
	return 0;
}
