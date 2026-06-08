#include <stdio.h>

typedef struct Value {

    float data;
    float grad;

    struct Value *left;
    struct Value *right;

} Value;

int main()
{
    Value a;
    Value b;
    Value c;

    a.data = 2.0f;
    a.grad = 0.0f;
    a.left = NULL;
    a.right = NULL;

    b.data = 3.0f;
    b.grad = 0.0f;
    b.left = NULL;
    b.right = NULL;

    c.data = a.data * b.data;
    c.grad = 0.0f;

    c.left = &a;
    c.right = &b;

    printf("Address of a      : %p\n", (void*)&a);
    printf("Stored in c.left  : %p\n\n", (void*)c.left);

    printf("Address of b      : %p\n", (void*)&b);
    printf("Stored in c.right : %p\n\n", (void*)c.right);

    printf("c.data = %.2f\n", c.data);

    return 0;
}
