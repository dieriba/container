TARGET_DIR := target
BUILD_DIR  := $(TARGET_DIR)/build
LIB_DIR		:= $(BUILD_DIR)/lib
LIBS_DIR := libs
LIB_CLP_DIR := $(LIBS_DIR)/clp
LIB_D_LIB_DIR := $(LIBS_DIR)/c_lib
LIB_CLP		:= $(LIB_DIR)/libclp.a
LIB_D_LIB   := $(LIB_DIR)/libd_lib.a
BIN_DIR    := $(BUILD_DIR)/bin

NAME       := container
BIN        := $(BIN_DIR)/$(NAME)

SRC_DIRS   := src
SRCS       := $(shell find $(SRC_DIRS) -name '*.c')
OBJS       := $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS       := $(OBJS:.o=.d)

D_LIB_INCLUDE := $(LIB_D_LIB_DIR)/includes
CLP_LIB_INCLUDE := $(LIB_CLP_DIR)/includes

INC_DIRS   := includes $(D_LIB_INCLUDE) $(CLP_LIB_INCLUDE)
INC_FLAGS  := $(addprefix -I,$(INC_DIRS))

CPPFLAGS   := $(INC_FLAGS) -MMD -MP -Wall -Werror -Wextra

all: $(BIN)
.PHONY: all

$(BIN): $(OBJS) $(LIB_CLP) $(LIB_D_LIB)
	mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $(BIN)

$(LIB_D_LIB):
	mkdir -p $(LIB_DIR)
	$(MAKE) -C $(LIB_D_LIB_DIR)
	cp $(LIB_D_LIB_DIR)/$(LIB_DIR)/*.a $(LIB_DIR)

$(LIB_CLP):
	mkdir -p $(LIB_DIR)
	$(MAKE) C_LIB_DIR=$(CURDIR)/$(LIB_D_LIB_DIR) -C $(LIB_CLP_DIR)
	cp $(LIB_CLP_DIR)/$(LIB_DIR)/*.a $(LIB_DIR)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET_DIR)
	$(MAKE) -C $(LIB_D_LIB_DIR) clean
	$(MAKE) -C $(LIB_CLP_DIR) clean

.PHONY: clean

fclean: clean
	rm -f $(BIN)
.PHONY: fclean

re: fclean all
.PHONY: re

-include $(DEPS)
