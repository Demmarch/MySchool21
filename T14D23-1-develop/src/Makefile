FLAGS = -Wall -Wextra -Werror

BUILD_DIR = ../build

RM = rm -f

all: Quest_1 Quest_2 Quest_3

Quest_1: $(BUILD_DIR)/Quest_1

$(BUILD_DIR)/Quest_1:
	gcc $(FLAGS) state_sort.c -o $@ -lm

Quest_2: $(BUILD_DIR)/Quest_2

$(BUILD_DIR)/Quest_2:
	gcc $(FLAGS) state_search.c -o $@ -lm

Quest_3: $(BUILD_DIR)/Quest_3

$(BUILD_DIR)/Quest_2:
	gcc $(FLAGS) state_search.c -o $@ -lm

clean:
	$(RM) $(BUILD_DIR)/Quest_1 $(BUILD_DIR)/Quest_2 $(BUILD_DIR)/Quest_3

rebuild: clean all

.PHONY: Quest_1 Quest_2 Quest_3