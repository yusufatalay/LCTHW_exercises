#include <stdio.h>

int main(int argc, char *argv[]){

    int i = 0;
    while(i<argc){
        printf("arg %d: %s\n",i,argv[i]);
        i++;
    }

    char *states[] = {"Delaware","LA","KALI","Kars"};

    int state_num = 4;

    i = 0; 
    while(i< state_num){
        printf("state %d: %s\n",i,states[i]);
        i++;
    }
 
    return 0;
}
