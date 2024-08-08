CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
BIN_DIR := $(CUR_DIR)/bin
LIB_SHARED_DRI := $(CUR_DIR)/lib
OBJ_DIR := $(CUR_DIR)/obj
SCR_DIR := $(CUR_DIR)/src

LIB_NAME := gemtek_lib

create_obj:
	gcc -c -fPIC $(SCR_DIR)/gemtek_mathlib.c -o $(OBJ_DIR)/gemtek_lib.o -I $(INC_DIR)
	gcc -c -fPIC $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)

create_sharedlib:
	gcc -shared $(OBJ_DIR)/gemtek_lib.o -o $(LIB_SHARED_DRI)/lib$(LIB_NAME).so

install_shared:
	cp -f $(LIB_SHARED_DRI)/lib$(LIB_NAME).so /usr/lib

linking_sharedlib:
	gcc $(OBJ_DIR)/main.o -L$(LIB_SHARED_DRI) -l$(LIB_NAME) -o $(BIN_DIR)/use-shared-library

all_shared: create_obj create_sharedlib install_shared linking_sharedlib

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_SHARED_DRI)/*.so
	rm -rf $(BIN_DIR)/*