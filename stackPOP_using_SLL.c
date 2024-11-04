#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
void traverse(struct node*ptr){
    while(ptr!=NULL){
        printf("element %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int isempty(struct node*top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct node*top){
    struct node*p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct node*push(struct node*top,int x){
    if(isfull(top)){
        printf("stack overflov\n");
    }
    else{
        struct node*n;
        n=(struct node*)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct node**top){
    if(isempty(*top)){
        printf("stack Underflow\n");
    }
    else{
        struct node*n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int main(){
    struct node*top=NULL;
    top=push(top,6);
    top=push(top,5);
    top=push(top,3);
    int element=pop(&top);
    printf("popped element is %d\n",element);
    traverse(top);
    return 0;
}