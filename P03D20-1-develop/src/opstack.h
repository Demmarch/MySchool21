/* Struct for building a stack o operations. char value is one of the
   following:
   '+' for addition,
   '-' for substraction,
   '*' for multiplication,
   '/' for division,
   '(' for opening bracket,
   's' for sin,
   'c' for cos,
   't' for tan,
   'g' for ctg,
   'q' for sqrt, and
   'l' for ln (log).*/
struct opstack {
    char value;
    struct opstack *prev;
};

struct opstack *initStack(char value);
struct opstack *pushToStack(struct opstack *opstack, char value);
struct opstack *popFromStack(struct opstack *opstack, char *value);