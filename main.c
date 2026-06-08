#include <stdio.h>

typedef struct {
    float data;
    float grad;
} Value;

Value value_create(float data)
{
    Value v;

    v.data = data;
    v.grad = 0.0f;

    return v;
}

int main(void)
{
    Value a = value_create(2.0f);
    Value b = value_create(3.0f);

    printf("a = %.2f\n", a.data);
    printf("b = %.2f\n", b.data);

    return 0;
}
