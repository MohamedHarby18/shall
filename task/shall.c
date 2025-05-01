#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for getcwd() and chdir()

int main(int argc, char *argv[]) {
    char path[100], dest[100], com[200], t;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1 - Copy file\n");
        printf("2 - Move file\n");
        printf("3 - Create directory\n");
        printf("4 - List directory contents\n");
        printf("5 - Remove file\n");
        printf("6 - Remove directory\n");
        printf("7 - Print current directory (pwd)\n");
        printf("8 - Change directory (cd)\n");
        printf("9 - Exit\n");

        int c;
        scanf("%d", &c);
        t = getchar(); // consume newline

        switch (c) {
            case 1: // cp
                strcpy(com, "cp ");
                printf("Enter the path of the file:\n");
                gets(path);
                strcat(com, path);
                printf("Enter the destination of the file:\n");
                gets(dest);
                strcat(com, " ");
                strcat(com, dest);
                system(com);
                break;

            case 2: // mv
                strcpy(com, "mv ");
                printf("Enter the path of the file:\n");
                gets(path);
                strcat(com, path);
                printf("Enter the destination of the file:\n");
                gets(dest);
                strcat(com, " ");
                strcat(com, dest);
                system(com);
                break;

            case 3: // mkdir
                strcpy(com, "mkdir ");
                printf("Enter the name of the directory to create:\n");
                gets(path);
                strcat(com, path);
                system(com);
                break;

            case 4: // ls
                strcpy(com, "ls ");
                printf("Enter the directory path (leave empty for current directory):\n");
                gets(path);
                if (strlen(path) > 0) {
                    strcat(com, path);
                }
                system(com);
                break;

            case 5: // rm
                strcpy(com, "rm ");
                printf("Enter the path of the file to remove:\n");
                gets(path);
                strcat(com, path);
                system(com);
                break;

            case 6: // rmdir
                strcpy(com, "rmdir ");
                printf("Enter the name of the directory to remove:\n");
                gets(path);
                strcat(com, path);
                system(com);
                break;

            case 7: // pwd
                if (getcwd(path, sizeof(path)) != NULL) {
                    printf("Current Directory: %s\n", path);
                } else {
                    perror("getcwd() error");
                }
                break;

            case 8: // cd
                printf("Enter the directory to change to:\n");
                gets(path);
                if (chdir(path) != 0) {
                    perror("chdir() error");
                }
                break;

            case 9: // exit
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

