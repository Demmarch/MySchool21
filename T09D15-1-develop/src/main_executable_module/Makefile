TARGET = Quest_

SRC_FILES = main_executable_module.c ../data_libs/*.c ../yet_another_decision_module/decision.c ../data_module/data_process.c

BUILD_DIR = ../../build

AR = ar rcs

RM = rm -f

BUILD_LIB = ../data_libs

LIB_FILE = ../data_libs/data_stat

LIB = data_stat

BUILD_LIB_DYN = ../data_module

LIB_FILE_DYN = ../data_module/data_process

LIB_DYN = data_process

SRC_FILES_FOR_LIB = main_executable_module.c ../data_libs/data_io.c ../yet_another_decision_module/decision.c ../data_module/data_process.c

SRC_FILES_FOR_LIB_DYN = main_executable_module.c ../data_libs/*.c ../yet_another_decision_module/decision.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

END_FLAGS = -lm -fsanitize=address

all: $(BUILD_DIR)/$(TARGET)3

$(BUILD_DIR)/$(TARGET)3:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -o $@ $(SRC_FILES) $(END_FLAGS)

build_with_macro: $(BUILD_DIR)/$(TARGET)4

$(BUILD_DIR)/$(TARGET)4:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -USE_MACRO_IO -o $@ $(SRC_FILES) $(END_FLAGS)

data_stat.a: $(BUILD_LIB)/lib$(LIB).a

$(BUILD_LIB)/lib$(LIB).a:
	$(CC) -c $(LIB_FILE).c -o $(LIB_FILE).o
	$(AR) $@ $(LIB_FILE).o
	ranlib $@
	$(RM) $(LIB_FILE).o

build_with_static: $(BUILD_DIR)/$(TARGET)5

$(BUILD_DIR)/$(TARGET)5:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(SRC_FILES_FOR_LIB) -L$(BUILD_LIB) -l$(LIB) -o $@ $(END_FLAGS)

data_process.so:$(BUILD_LIB_DYN)/lib$(LIB_DYN).so

$(BUILD_LIB_DYN)/lib$(LIB_DYN).so:
	$(CC) -FPIC -c $(LIB_FILE_DYN).c -o $(LIB_FILE_DYN).o
	$(CC) -FPIC -shared -o $@ $(LIB_FILE_DYN).o
	$(RM) $(LIB_FILE_DYN).o

build_with_dynamic: $(BUILD_DIR)/$(TARGET)6

$(BUILD_DIR)/$(TARGET)6:
	mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) $(SRC_FILES_FOR_LIB_DYN) -L$(BUILD_LIB_DYN) -l$(LIB_DYN) -o $@ $(END_FLAGS)

clean:
	(RM) $(BUILD_DIR)/$(TARGET)3 $(BUILD_DIR)/$(TARGET)4 $(BUILD_DIR)/$(TARGET)5

rebuild: clean all