#define APPNAME "pi-apps-cli"
#define APPVER "0.0.3"
#define VER_MAJOR 0
#define VER_MINOR 0
#define VER_REVISION 3

void echo(char text[256]);
int help(void);
int about(void);
int list_files(int argc, char **argv);