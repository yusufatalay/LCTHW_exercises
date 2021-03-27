#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


struct Person {
    char *name;
    int age;
    int height;
    int weight;
};


struct Person *Person_create(char *name, int age, int height, int weight){
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who){
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who){

    printf("Name: %s\n",who->name);
    printf("\tAge: %d\n",who->age);
    printf("\tHeight: %d\n",who->height);
    printf("\tWeight: %d\n",who->weight);
}

int main(int argc, char *argv[]){
    
    //make two people structures
    struct Person *desmond = Person_create("Desmond hume",22,184,91);
    struct Person *astrid = Person_create("Astrid Hofferson",22,190,90);

    printf("Desmond is at memory location %p:\n",desmond);
    Person_print(desmond);
    printf("Astrid is at memory location %p:\n",astrid);
    Person_print(astrid);

    desmond->age += 20;
    desmond->height +=2;
    desmond->weight +=5;
    Person_print(desmond);

    astrid->age += 20;
    astrid->height +=2;
    Person_print(astrid);

    Person_destroy(desmond);
    Person_destroy(astrid);
}
