TARGET = Quest_

BUILD_DIR = ../build

RM = rm -f

CC = gcc

FLAGS = -Wall -Wextra -Werror

END_FLAGS = -lm

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

strlen_tests: $(BUILD_DIR)/$(TARGET)1

$(BUILD_DIR)/$(TARGET)1:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) s21_string_test.c s21_string.c -DTEST_LEN -o $@ $(END_FLAGS)

strcmp_tests: $(BUILD_DIR)/$(TARGET)2

$(BUILD_DIR)/$(TARGET)2:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) *.c -DTEST_COMPARE -o $@ $(END_FLAGS)

strcpy_tests: $(BUILD_DIR)/$(TARGET)3

$(BUILD_DIR)/$(TARGET)3:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) s21_string_test.c s21_string.c -DTEST_COPY -o $@  $(END_FLAGS)

strcat_tests: $(BUILD_DIR)/$(TARGET)4

$(BUILD_DIR)/$(TARGET)4:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) s21_string_test.c s21_string.c -DTEST_CAT -o $@ $(END_FLAGS)

strchr_tests: $(BUILD_DIR)/$(TARGET)5

$(BUILD_DIR)/$(TARGET)5:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) s21_string_test.c s21_string.c -DTEST_CHR -o $@ $(END_FLAGS)

strstr_tests: $(BUILD_DIR)/$(TARGET)6

$(BUILD_DIR)/$(TARGET)6:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) s21_string_test.c s21_string.c -DTEST_STR -o $@ $(END_FLAGS)

strtok_tests: $(BUILD_DIR)/$(TARGET)7

$(BUILD_DIR)/$(TARGET)7:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) s21_string_test.c s21_string.c -DTEST_TOK -o $@ $(END_FLAGS)

clean:
	$(RM) $(BUILD_DIR)/$(TARGET)1 $(BUILD_DIR)/$(TARGET)2 $(BUILD_DIR)/$(TARGET)3 $(BUILD_DIR)/$(TARGET)4 $(BUILD_DIR)/$(TARGET)5 $(BUILD_DIR)/$(TARGET)6 $(BUILD_DIR)/$(TARGET)7

rebuild: clean all