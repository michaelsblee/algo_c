#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255
#define TEST_CASES 5

typedef struct node {
    int candy;
    struct node *left, *right;
} node;

node *new_house(int candy) {
    node *house = malloc(sizeof(node));
    if (house == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    house->candy = candy;
    house->left = NULL;
    house->right = NULL;
    return house;
}

node *new_nonhouse(node *left, node *right) {
    node *nonhouse = malloc(sizeof(node));
    if (nonhouse == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);  
    }
    nonhouse->left = left;
    nonhouse->right = right;
    return nonhouse;
}

