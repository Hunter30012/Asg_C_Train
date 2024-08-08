CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
BIN_DIR := $(CUR_DIR)/bin
LIB_STATIC_DRI := $(CUR_DIR)/lib
OBJ_DIR := $(CUR_DIR)/obj
SCR_DIR := $(CUR_DIR)/src

LIB_NAME := gemtek_lib

create_obj:
	gcc -c $(SCR_DIR)/gemtek_mathlib.c -o $(OBJ_DIR)/gemtek_lib.o -I $(INC_DIR)
	gcc -c $(CUR_DIR)/main.c -o $(OBJ_DIR)/main.o -I $(INC_DIR)

create_staticlib:
	ar rcs $(LIB_STATIC_DRI)/lib$(LIB_NAME).a $(OBJ_DIR)/gemtek_lib.o

create_symbol:
	ranlib $(LIB_STATIC_DRI)/lib$(LIB_NAME).a

linking_staticlib:
	gcc $(OBJ_DIR)/main.o -L$(LIB_STATIC_DRI) -l$(LIB_NAME) -o $(BIN_DIR)/statically-linked

all_static: create_obj create_staticlib create_symbol linking_staticlib

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_SHARED_DRI)/*.so
	rm -rf $(BIN_DIR)/*
	rm -rf $(LIB_STATIC_DRI)/*.a