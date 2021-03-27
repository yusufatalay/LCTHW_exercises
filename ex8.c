#include <stdio.h>

int main(int argc, char *argv[]){

    int areas[] = {10,12,13,14,20};
    char name[] = "Des";
    char full_name[]= {'D','e','s',' ','H','u','m'};

    printf("The size of an int %ld\n",sizeof(int));
    printf("the size of areas (int[]):%ld\n",sizeof(areas));
    printf("The numbers of ints in the areas %ld\n",sizeof(areas)/sizeof(int));
    
    printf("the size of the char %ld\n",sizeof(char));
    printf("the size of the name %ld\n",sizeof(name));
    printf("the number of the chars %ld\n",sizeof(name)/sizeof(char));

    printf("the size of the full-name %ld\n",sizeof(full_name));  
    printf("the number of the chars %ld\n",sizeof(name)/sizeof(char));

    return 0;
}
