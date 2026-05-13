include c_lib/config.mk

TARGET_DIR := target
BUILD_DIR  := $(TARGET_DIR)/build

NAME       := container
BIN        := $(BUILD_DIR)/$(NAME)

SRC_DIRS   := src
SRCS       := $(shell find $(SRC_DIRS) -name '*.c')
OBJS       := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS       := $(OBJS:.o=.d)

INC_DIRS   := includes $(D_LIB_INCLUDE)
INC_FLAGS  := $(addprefix -I,$(INC_DIRS))

CPPFLAGS   := $(INC_FLAGS) -MMD -MP -Wall -Werror -Wextra

all: $(D_LIB_PATH) $(BIN)
.PHONY: all

$(D_LIB_PATH):
	$(MAKE) -C $(D_LIB_DIR) all

$(BIN): $(OBJS) $(D_LIB_PATH)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET_DIR)
	$(MAKE) -C $(D_LIB_DIR) clean
.PHONY: clean

fclean: clean
	rm -f $(BIN)
.PHONY: fclean

re: fclean all
.PHONY: re

-include $(DEPS)
