#####################################################################
include ../rules.mk

VERSION		:= v2.4

PWD        := $(shell pwd)

LIB_NAME	:= -lrtmp
LIB_SRC		:= $(PWD)/librtmp


EXE_TARGET  := $(PWD)/rtmp_server
EXE_SRC		:= $(PWD)/librtmp_send264.c \
				$(PWD)/main.c 

PHONY := all
all: librtmp2 exe


PHONY += librtmp2
librtmp2:
	cd $(LIB_SRC); make;
	
PHONY += exe
exe:	
	$(CC) -o $(EXE_TARGET) $(EXE_SRC) -I$(LIB_SRC) -L$(LIB_SRC) $(LIB_NAME)
	
clean:
	@rm -rf $(EXE_TARGET)
	@cd $(LIB_SRC); make clean;
