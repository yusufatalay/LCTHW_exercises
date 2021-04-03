#include "minunit.h"
#include "<lcthw/list_algos.h>"
#include <assert.h>
#include <string.h>

char *values[] = {"XXXX","1234","abcd","xjvef","NDSS"};

#define NUM_VALUES 5

List *create_words()
{
    int i = 0;
    List *words = List_create() ;

    for(i = 0; i<NUM_VALUES; i++) {
        List_push(words, values[i]);
    }  

    return words;
}

int is_sorted(List * words)
{
    LIST_FOREACH(words, first,next,current){
        if(current->next && strcmp(current->value, current->next->value)>0){
            debug("%s %s",(char *)cur->value,(char *)cur->next->value);
            return 0;
        }
    }
    return 1;
}

char *test_bubble_sort()
{
    List *words = create_words();

    // should work on  a list which needs sorting
    int rc = List_bubble_sort(words,(List_compare) strcmp);
    mu_assert(rc == 0,"Buble sort failed");
    mu_assert(is_sorted(words),"List is not sorted after bubble sort");

    // should work on already sorted list
    rc = List_bubble_sort(words,(List_compare) strcmp);
    mu_assert(rc == 0,"Buble sort of already sorted  failed");
    mu_assert(is_sorted(words),"word should be sort if already bubble sorted");

    List_destroy(words);
    // shoul also work on empty list

    rc = List_bubble_sort(words,(List_compare) strcmp);
    mu_assert(rc == 0,"Buble sort failed on empty list");
    mu_assert(is_sorted(words),"words should be sorted if list is empty");

    List_destroy(words);

    return NULL;
}

char *test_merge_sort()
{
    List *words = create_words();

    // should work on a list that needs sorting
    List *res = List_merge_sort(words, (List_compare) strcmp) ;
    mu_assert(is_sorted(res),"Words are not sorted after merge sort");

    // should also work on already sorted list
    List *res2 = List_merge_sort(res, (List_compare) strcmp);

    mu_assert(is_sorted(res),"should still be sorted after merge sort");

    List_destroy(res);
    List_destroy(res2);

    List_destroy(words);
    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_bubble_sort);
    mu_run_test(test_merge_sort);

    return NULL;
}

RUN_TESTS(all_tests);













