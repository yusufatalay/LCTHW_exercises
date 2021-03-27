#include <stdio.h>


void crash(){
    char *test = NULL;
    int i = 0;

    for(i = 0; i<10000000; i++){
        printf("%c",test[i]);
    }
}

int main(int argc , char *argv[]){

    int age=22;
    int height=185;

    printf("I am %d centimeters tall ",height);
    printf("I am %d years old",height);

    return 0;


}
