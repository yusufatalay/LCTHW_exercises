#include <stdio.h>

int main(int argc, char *argv[]){

    int numbers[4] = {0};
    char name[4] = {'a'};

    printf("numbers: ");
    for (int i = 0; i<4 ; i++){
    
        printf("%d ",numbers[i]);
    }
    printf("\n");
    
    printf("name each: ");
    for (int i = 0; i<4 ; i++){
    
        printf("%c ",name[i]);
    }
    printf("\n ");
    
    printf("%s\n",name);



    for (int i = 0; i<4 ; i++){
        
        numbers[i] = i+1;
    
    }
    
    name[0] = 'D';
    name[1] = 'e';
    name[2] = 's';
    name[3] = 'A';

    printf("numbers: ");
    for (int i = 0; i<4 ; i++){
    
        printf("%d ",numbers[i]);
    }
    printf("\n");

   printf("name each: ");
    for (int i = 0; i<4 ; i++){
    
        printf("%c",name[i]);
    }
    printf("\n ");
    
    printf("%s\n",name);

    char *another = "Des";

    printf("another : %s\n",another );

    printf("another each: ");
    for (int i = 0; i<4 ; i++){
    
        printf("%c ",another[i]);
    }
    printf("\n ");


    return 0;
}
