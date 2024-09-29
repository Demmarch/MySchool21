FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: door_struct list_test stack_test

door_struct: Quest_1

Quest_1:
	gcc $(FLAGS) dmanager_module.c -o ../build/$@

list_test: Quest_2

Quest_2:
	gcc $(FLAGS) list.c list_test.c -o ../build/$@

stack_test: Quest_3

Quest_3:
	gcc $(FLAGS) stack.c stack_test.c -o ../build/$@

clean:
	$(RM) ../build/Quest_1 ../build/Quest_2 ../build/Quest_3 

rebuild: clean all