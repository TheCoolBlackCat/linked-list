#include <stdio.h>
#include "linkedlist.h"

int main () {
    node* list = createLL('a');
    printLL(list);
    addToLL(list, 'b');
    printLL(list);
    addToLL(list, 'c');
    printLL(list);

    reverseLL(&list);
    printLL(list);

    reverseLL(&list);
    printLL(list);

    int n = removeFromLL(list);
    printf("REMOVED: {%c -> {}}\n", n);
    printLL(list);

    n = removeFromLL(list);
    printf("REMOVED: {%c -> {}}\n", n);
    printf("HEAD: %d -> %p\n", list->c, list->next);
    printLL(list);

    n = removeFromLL(list);
    printf("REMOVED: {%c -> {}}\n", n);
    printf("HEAD: %d -> %p\n", list->c, list->next);
    printLL(list);

    n = removeFromLL(list);
    printf("REMOVED: {%c -> {}}\n", n);
    printf("HEAD: %d -> %p\n", list->c, list->next);
    printLL(list);

    n = removeFromLL(list);
    printf("REMOVED: {%c -> {}}\n", n);
    printf("HEAD: %d -> %p\n", list->c, list->next);
    printLL(list);

    n = removeFromLL(list);
    printf("REMOVED: {%c -> {}}\n", n);
    printf("HEAD: %d -> %p\n", list->c, list->next);
    printLL(list);

    n = popFromLL(&list);
    printf("POPPED: {%c -> {}}\n", n);
    // printf("HEAD: %d -> %p\n", list->c, list->next);
    printLL(list);
}
