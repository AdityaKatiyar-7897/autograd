#include <stdio.h>

/* sample expression

a = 2
b = 3
e = 4

c = a * b
d = c + e
*/

typedef struct Value {

    float data;
    float grad;

    struct Value *left;
    struct Value *right;

    char op;

    char *label;

} Value;

Value value_create(float data)
{
    Value out;

    out.data = data;
    out.grad = 0.0f;

    out.left = NULL;
    out.right = NULL;

    out.op = ' ';
    out.label = NULL;

    return out;
}

void print_value(Value *v)
{
    printf("\n Value object  %s \n", v->label);

    printf("data = %.2f\n", v->data);
    printf("grad = %.2f\n", v->grad);
    printf("op   = %c\n", v->op);

    if (v->left != NULL)
    {
        printf("left  -> %s (%.2f)\n",
               v->left->label,
               v->left->data);

        printf("addr  -> %p\n",
               (void *)v->left);
    }

    if (v->right != NULL)
    {
        printf("right -> %s (%.2f)\n",
               v->right->label,
               v->right->data);

        printf("addr  -> %p\n",
               (void *)v->right);
    }
}

Value value_mul(Value *a, Value *b)
{
    Value out;

    out.data = a->data * b->data;
    out.grad = 0.0f;

    out.left = a;
    out.right = b;

    out.op = '*';
    out.label = NULL;

    return out;
}

Value value_add(Value *a, Value *b)
{
    Value out;

    out.data = a->data + b->data;
    out.grad = 0.0f;

    out.left = a;
    out.right = b;

    out.op = '+';
    out.label = NULL;

    return out;
}

int main()
{
    Value a;
    Value b;
    Value c;
    Value d;
    Value e;

    a = value_create(2.0f);
    a.label = "a";

    b = value_create(3.0f);
    b.label = "b";

    e = value_create(4.0f);
    e.label = "e";

    c = value_mul(&a, &b);
    c.label = "c";

    d = value_add(&c, &e);
    d.label = "d";

    print_value(&a);
    print_value(&b);
    print_value(&e);
    print_value(&c);
    print_value(&d);

    return 0;
}
