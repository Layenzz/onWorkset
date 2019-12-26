#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> 
#include <sys/stat.h>
#include <sys/types.h>

#include "../includes/onWorkset.h"

void checkIfExist(const char *path)
{
    struct stat sb;

    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        
    } else {
        mkdir(path);
    }
}

int getCountInstance(const char *path){
    int nb = 0;

    DIR *d;
    struct dirent *dir;
    d = opendir(path);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            nb++;
        }
        closedir(d);
    }
    return nb - 2;
}

void create_instance(const char *path){
    char name[30] = {0};
    printf("Please enter a name for your new onset instance: \n");
    scanf("%s", name);
    
    char *truePath;
    strcpy(truePath, path);
    strcat(truePath, "/");
    strcat(truePath, name);

    printf("Yo\n");
    printf("Path : %s\n", truePath);
}

Game_Instance **list_instance(){
    char *path = "instances";

    checkIfExist(path);
    int instanceCount = getCountInstance(path);

    Game_Instance **list = malloc(sizeof(Game_Instance *) * instanceCount + 1);

    DIR *d;
    struct dirent *dir;
    d = opendir("instances");
    int nb = 0;
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (!(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)){
                list[nb] = malloc(sizeof(Game_Instance));
                list[nb]->name = malloc(sizeof(char) * strlen(dir->d_name));
                strcpy(list[nb]->name, dir->d_name);
                nb++;
            }
        }
        closedir(d);
    }
    list[nb] = NULL;
    return list;
}


