FLAGS = -Wall -Wextra -Werror

BUILD_DIR = ../build

RM = rm -f

all: cipher logging_cipher

cipher: $(BUILD_DIR)/cipher

$(BUILD_DIR)/cipher:
	gcc $(FLAGS) cipher.c -DNON_LOG -o $@ -lm

logging_cipher: $(BUILD_DIR)/logging_cipher

$(BUILD_DIR)/logging_cipher:
	gcc $(FLAGS) cipher.c logger.c -DLOG -o $@ -lm

clean:
	$(RM) ../build/cipher ../build/logging_cipher

rebuild: clean all

.PHONY: cipher logging_cipher