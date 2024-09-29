FLAGS = -Wall -Wextra -Werror

BUILD_DIR = ../build

RM = rm -f

all: build_db

build_db: $(BUILD_DIR)/build_db

$(BUILD_DIR)/build_db:
	gcc $(FLAGS) modules_db.c master_status_events.c master_modules.c master_levels.c shared.c -o $@ -lm

clean:
	$(RM) $(BUILD_DIR)/build_db

rebuild: clean all

.PHONY: build_db