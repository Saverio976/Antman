##
## EPITECH PROJECT, 2021
## LIBMY
## File description:
## make the antman
##

# ----------------------------------------------------------------------------
# COLOUR
CYAN		=	'\033[1;36m'
GREEN 		= 	'\033[1;32m'

RESET		=	'\033[0m'
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# TARGET
TARGET		=	antman
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# FOLDER
SRCDIR		=	src/

INCDIR		=	../include ../lib/include

LIBDIR		=	../lib
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# SRC
SRC		:=	get_value.c \
			init_tree_list.c \
			main.c

SRC		:=	$(addprefix $(SRCDIR),$(SRC))

SRC		:=	$(SRC) \
			../src/main.c \
			../src/read_header.c \
			../src/write_header.c \
			../src/print_code.c

OBJ		:=	$(SRC:%.c=%.o)
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# FLAGS
CFLAGS		=	$(foreach idir,$(INCDIR), -I$(idir)) \
			-Wall -Wextra -Wpedantic

LDFLAGS		=	$(foreach ldir,$(LIBDIR), -L$(ldir)) \
			-lmy
# ----------------------------------------------------------------------------

# ----------------------------------------------------------------------------
# IN-MAKEFILE
CURR_RULE	=	all
# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC)     $(CFLAGS)     $^ -c -o $@

.PHONY: all
all:	CURR_RULE = all
all:	init $(TARGET) ## Call $(TARGET)
	@echo -e $(GREEN)'[finished]: $(TARGET): make $(CURR_RULE)'$(RESET)

$(TARGET):	CURR_RULE = $(TARGET)
$(TARGET):	init $(OBJ) ## Build the lib
	@$(CC) $(OBJ) $(SAME_OBJ) -o $(TARGET) $(LDFLAGS) $(CFLAGS)
	@echo -e $(GREEN)'[finished]: $(TARGET): make $(CURR_RULE)'$(RESET)

init:
	@echo -e $(CYAN)'[starting]: $(TARGET): make $(CURR_RULE) ...'$(RESET)

debug:	CFLAGS += -g3
debug:	all

.PHONY: clean
clean:
	@$(RM) $(OBJ)

.PHONY: fclean
fclean: CURR_RULE = fclean
fclean:	init clean
	@$(RM) $(TARGET)
	@echo -e $(GREEN)'[finished]: $(TARGET): make $(CURR_RULE)'$(RESET)

.PHONY: re
re:	fclean all

tests_bin: CFLAGS += -fprofile-arcs -ftest-coverage
tests_bin: LDFLAGS += -lgcov
tests_bin: re
