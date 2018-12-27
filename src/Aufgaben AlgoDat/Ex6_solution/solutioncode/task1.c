#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A (sqrt(5)-1)/2
#define TABLE_SIZE 8

struct element {
    int value;
    struct element *next;
};

void init(struct element *H[]) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
        H[i] = NULL;
}

int h(int k) {
    return TABLE_SIZE*(A*k - (int)(A*k));
}

void insert(int key, struct element *H[]) {
    int i = h(key);
    struct element* e = malloc(sizeof(struct element));

    e->value = key;
    e->next = H[i];
    H[i] = e;
}

int search(int k, struct element *H[]) {
    int hkey = h(k);
    struct element *e = H[hkey];
    
    while (e != NULL) {
        if (e->value == k) { return hkey; }
        else { e = e->next; }
    }

    return -1;
}

void printHash(struct element *H[]) {
    struct element *e;
    int i;

    printf("Table size: %d\n", TABLE_SIZE);
    for (i = 0; i < TABLE_SIZE; i++) {
        if (H[i] != NULL) {
            printf("i: %d\t key:", i);
            e = H[i];
            while (e != NULL) {
                printf(" -> %d", e->value);
                e = e->next;
            }
            printf("\n");
        }
    }
}

void main () {
    struct element *H[TABLE_SIZE];
    int searchValues[] = {1, 10112, 1113, 5568, 337};
    int i;

    init(H);
    insert( 111, H);
    insert(10112, H);
    insert(1113, H);
    insert(5568, H);
    insert(63, H);
    insert(1342, H);
    insert(21231, H);
    
    printHash(H);
    
    for (i = 0; i < 5; i++) {
        printf("Searching for %d, found %d\n", searchValues[i],
               search(searchValues[i], H));
    }
}

// Linux, Mac: gcc task1.c -o task1; ./task1
// Windows: gcc task1.c -o task1; task1
