CFLAGS=-Wall -Werror -Wextra -Wno-unused-parameter
LDFLAGS=-lm
SOURCES=graph.c graph_lib.c stack.c calc_polish_file.c
BUILD_DIR=../build/
EXECUTABLE=graph
CC = gcc

all:: graph

rebuild:: clean all

graph:: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(BUILD_DIR)$(EXECUTABLE) $(LDFLAGS)

clean::
	$(RM) $(BUILD_DIR)$(EXECUTABLE)
