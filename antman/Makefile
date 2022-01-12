##
## EPITECH PROJECT, 2021
## LIBMY
## File description:
## make the antman
##

# COLOUR
CYAN		=	'\033[0;36m'
GREEN 		= 	'\033[0;32m'
RESET		=	'\033[0m'

# CURRENT RULE
CURR_RULE	=	all

# TARGET
TARGET		=	antman

SRCDIR		=	src/

VPATH		=	$(SRCDIR)

SRC		=	$(shell find $(SRCDIR) -name '*.c') \
			$(shell find ../$(SRCDIR) -name '*.c')

OBJ		:=	$(SRC:%.c=%.o)

CFLAGS		=	-I../include -I../lib/include -Wall -Wextra -Wpedantic

LFLAGS		=	-L../lib -lmy

# ----------------------------------------------------------------------------

%.o: %.c
	@$(CC)     $(CFLAGS)     $^ -c -o $@

.PHONY: all
all:	CURR_RULE = all
all:	init $(TARGET) ## Call $(TARGET)
	@echo -e $(GREEN)[finished]: $(TARGET): make $(CURR_RULE)$(RESET)

$(TARGET):	CURR_RULE = $(TARGET)
$(TARGET):	init $(OBJ) ## Build the lib
	@$(CC) $(OBJ) $(SAME_OBJ) -o $(TARGET) $(LFLAGS) $(CFLAGS)
	@echo -e $(GREEN)[finished]: $(TARGET): make $(CURR_RULE)$(RESET)

init:
	@echo -e $(CYAN)[starting]: $(TARGET): make $(CURR_RULE) ...$(RESET)

.PHONY: clean
clean: ## Clean obj/*.o
	@$(RM) $(OBJ)

.PHONY: fclean
fclean: CURR_RULE = fclean
fclean:	init clean ## Clean the binary
	@$(RM) $(TARGET)
	@echo -e $(GREEN)[finished]: $(TARGET): make $(CURR_RULE)$(RESET)

.PHONY: re
re:	fclean all ## Fclean+All
