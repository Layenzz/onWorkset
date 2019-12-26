#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/onWorkset.h"

void usage(){
    printf("\n");
    printf("------------- Welcome to OnWorkset -------------\n");
    printf("\n");
    printf("-list => List all your instance of Onset server\n");
    printf("-create => Create new instance of Onset server\n");
    printf("-run [InstanceName||InstanceId] => Run one of your instance of Onset server\n");
}

void badCall(){
    
}

void emptyCall(){
    printf("This programm can't be runned without parameters\n");
    printf("Type onWorkset.exe -h or -help for more infos\n");
}

int main(int ac, char **av)
{
    printf("\n");
    if (ac == 1)
        emptyCall();

    if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "-help") == 0)
        usage();

    if(strcmp(av[1], "-list") == 0){
        Game_Instance **list = list_instance();

        int nb = 0;
        while(list[nb] != NULL){
            
            printf("Instance [%s]\n", list[nb]->name);
            nb++;
        }
    }

    if(strcmp(av[1], "-create") == 0){
        create_instance("instances");
    }
}