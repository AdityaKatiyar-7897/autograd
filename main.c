#include <stdio.h>

typedef struct Value {

    float data;
    float grad;

    struct Value *left;
    struct Value *right;

    char op;

} Value;

int main()
{
    Value a;
    Value b;
    Value c;
    Value d;
    Value e;

    a.data = 2.0f;
    a.grad = 0.0f;
    a.left = NULL;
    a.right = NULL;
    a.op = ' ';

    b.data = 3.0f;
    b.grad = 0.0f;
    b.left = NULL;
    b.right = NULL;
    b.op = ' ';

    e.data = 4.0f;
    e.grad = 0.0f;
    e.left = NULL;
    e.right = NULL;
    e.op = ' ';

    c.data = a.data * b.data;
    c.grad = 0.0f;
    c.left = &a;
    c.right = &b;
    c.op = '*';

    d.data = c.data + e.data;
    d.grad = 0.0f;
    d.left = &c;
    d.right = &e;
    d.op = '+';

    printf("\nValue object a\n");
    printf("data = %.2f\n", a.data);
    printf("grad = %.2f\n", a.grad);
    printf("op   = %c\n", a.op);
    
    printf("\nValue object b\n");
    printf("data = %.2f\n", b.data);
    printf("grad = %.2f\n", b.grad);
    printf("op   = %c\n", b.op);
    
    printf("\nValue object e\n");
    printf("data = %.2f\n", e.data);
    printf("grad = %.2f\n", e.grad);
    printf("op   = %c\n", e.op);
    
    printf("\nValue object c\n");
    printf("data = %.2f\n", c.data);
    printf("grad = %.2f\n", c.grad);
    printf("op   = %c\n", c.op);
    
    printf("\nValue object d\n");
    printf("data = %.2f\n", d.data);
    printf("grad = %.2f\n", d.grad);
    printf("op   = %c\n", d.op);

    printf("%p\n", (void*)c.left);
    printf("%p\n", (void*)&a);

    printf("%p\n", (void*)d.left);
    printf("%p\n", (void*)&c);

    printf("%p\n", (void*)d.right);
    printf("%p\n", (void*)&e);

    
    return 0;
}
