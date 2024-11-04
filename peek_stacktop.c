#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void traverse(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isempty(struct node* top) {
    return (top == NULL);
}

int isfull() {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        return 1;
    } else {
        free(p);
        return 0;
    }
}
struct node* push(struct node* top, int x) {
    if (isfull()) {
        printf("Stack overflow\n");
        return top;
    } else {
        struct node* n = (struct node*)malloc(sizeof(struct node));
        if (n == NULL) {
            printf("Memory allocation failed\n");
            return top;
        }
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int peek(struct node* top, int pos) {
    struct node* ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        return ptr->data;
    } else {
        return -1;
    }
}

int main() {
    struct node* top = NULL;
    top = push(top, 6);
    top = push(top, 5);
    top = push(top, 2);
    top = push(top, 1);
    traverse(top);
    for (int i = 1; i <= 4; i++) {
        printf("Value at position %d is: %d\n", i, peek(top, i));
    }
   return 0;
}
