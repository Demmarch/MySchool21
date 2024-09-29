FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module: Quest_1

Quest_1:
	gcc $(FLAGS) print_module.c main_module_entry_point.c -o ../build/$@

documentation_module: Quest_2

Quest_2:
	gcc $(FLAGS) print_module.c main_module_entry_point.c documentation_module.c -DDOC_MODULE -o ../build/$@

bst_create_test: Quest_3

Quest_3:
	gcc $(FLAGS) bst_create_test.c bst.c -o ../build/$@

bst_create_test: Quest_4

Quest_4:
	gcc $(FLAGS) bst.c bst_insert_test.c -o ../build/$@

bst_create_test: Quest_5

Quest_5:
	gcc $(FLAGS) bst.c bst_traverse_test.c -o ../build/$@

clean:
	$(RM) ../build/Quest_1 ../build/Quest_2 ../build/Quest_3 ../build/Quest_4 ../build/Quest_5

rebuild: clean all

.PHONY: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test all rebuild clean