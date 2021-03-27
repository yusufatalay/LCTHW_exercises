#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"
#include <glob.h>

#define MAX_LINE 1024
int list_files(glob_t *pglob)
{
    char *line = calloc(MAX_LINE,1);
    FILE* file = fopen(".logfind","r");
    int glob_flags = GLOB_TILDE;
    int i = 0;
    int rc = -1;

    check(pglob != NULL,"Invalid glob_t token given");
    check_mem(line);
    check(file,"Failed to open .logfind make that first");

    rc = glob("*.h", glob_flags,NULL,pglob);
    check(rc == 0, "Failed to glob");
     
    rc = glob("*.c",glob_flags | GLOB_APPEND,NULL,pglob);
    check(rc == 0,"Failed to glob");

    rc = glob("*.log",glob_flags | GLOB_APPEND, NULL, pglob);
    check(rc == 0,"Failed to glob");

    for(i = 0; i<pglob->gl_pathc;i++){
        debug("Mathced file: %s",pglob->gl_pathv[i]);
    }

    rc = 0;
error:
    if(line) free(line);
    return rc ;
}

int Grep(char *file_name, int argc, char *argv[])
{
    FILE *fp = NULL;
    fp = fopen(file_name,"r");
    char line[MAX_LINE];
    int match_counter  = 0;
    while(fgets(line,MAX_LINE,fp)){
        for(int i= 1; i<argc; i++){
            if(strstr(line,argv[i])){
                match_counter++;
            }else{
                continue;
            }
        }
    }

    if(strcmp(argv[1],"-o") == 0 && match_counter >0){
        printf("%s\n",file_name);
    }else if(match_counter == argc-1){
        printf("%s\n",file_name);
    }




    return 0;
}

int main(int argc, char *argv[])
{

    check(argc > 1 ,"Pleasse provide atleast one keyword to search");
    glob_t files;
   check(list_files(&files)== 0, "failed to list files");

   for(int i = 0; i< files.gl_pathc; i++){
        Grep(files.gl_pathv[i],argc,argv);
   }

    globfree(&files);
    return 0;
error:
    globfree(&files);

    return 1;
}
