typedef struct {
    double *data;
    int size;
    int len;
} Stack;

void init_stack(Stack *stack, double first_value);
void push(Stack *stack, double value);
double pop(Stack *stack);
void destroy_stack(Stack *stack);