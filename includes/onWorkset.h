#ifndef ON_WORKSET

struct Instance{ 
    int id;
    char *name;
    char **packages; 
};

typedef struct Instance Game_Instance;


Game_Instance **list_instance();
void create_instance(const char *path);

#endif