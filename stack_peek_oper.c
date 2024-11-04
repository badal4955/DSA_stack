#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("stack underflow!cannot push %d to stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int peek(struct stack *sp, int i)
{
    int arrayind = sp->top - i + 1;

    if (arrayind < 0)
    {
        printf("not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return sp->arr[arrayind];
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("before pusing, full:%d\n", isfull(sp));
    printf("before pusing, empty:%d\n", isempty(sp));
    printf("\n");

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);
    push(sp, 7);
    push(sp, 8);
    push(sp, 9);
    push(sp, 10);

    printf("after pusing, full:%d\n", isfull(sp));
    printf("after pusing, empty:%d\n", isempty(sp));

    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at pos %d is %d\n", j, peek(sp, j));
    }
    return 0;
}
