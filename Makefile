##
## EPITECH PROJECT, 2021
## sample
## File description:
## make the [gi]antman
##

# COLOUR
CYAN		=	'\033[0;36m'
GREEN 		= 	'\033[0;32m'
RESET		=	'\033[0m'

# TARGET
NAME		=	[gi]antman

LIB_TARGET	=	lib/libmy.a

ANTMAN		=	antman/antman

GIANTMAN	=	giantman/giantman

CFLAGS		=	-Wall -Wextra -Wpedantic -Iinclude -Ilib/include

SRC		=	$(shell find src/ -name '*.c')

OBJ		=	$(SRC:.c=.o)

VPATH		=	$(dir $(ANTMAN)) $(dir $(GIANTMAN)) lib/ include/ tests/

TEST_BASH	=	./tests/fn_tests.sh

# ----------------------------------------------------------------------------

.PHONY: all
all:	$(LIB_TARGET) $(OBJ) $(ANTMAN) $(GIANTMAN) ## Build lib+binary
	@echo -e $(GREEN)' -> [finished]: $(NAME): make all'$(RESET)

$(ANTMAN):	## Build the binary for the antman
	@$(MAKE) -C $(dir $(ANTMAN)) -s
	@echo -e $(GREEN)' -> [finished]: $(NAME): make $(ANTMAN)'$(RESET)

$(GIANTMAN):	## Build the binary for the giantman
	@$(MAKE) -C $(dir $(GIANTMAN)) -s
	@echo -e $(GREEN)' -> [finished]: $(NAME): make $(GIANTMAN)'$(RESET)

debug: CFLAGS += -g3
debug: fclean $(OBJ)
	$(MAKE) -C $(dir $(LIB_TARGET)) debug
	$(MAKE) -C $(dir $(ANTMAN)) debug
	$(MAKE) -C $(dir $(GIANTMAN)) debug

$(LIB_TARGET): ## Build the lib
	@$(MAKE) -C lib/ -s
	@echo -e $(GREEN)' -> [finished]: $(NAME): make $(LIB_TARGET)'$(RESET)

.PHONY: clean
clean: ## Clean gcno/gcda vgcore
	@$(RM) $(shell find . -name 'vgcore.*')
	@$(RM) $(shell find . -name '*.gcno') $(shell find . -name '*.gcda')
	@$(RM) $(shell find tests/ -name '*.antman')
	@$(RM) $(shell find tests/ -name '*.giantman')

.PHONY: fclean
fclean:	clean ## Clean+Remove target/target_test and call lib fclean
	@$(MAKE) -C lib/ fclean -s
	@$(MAKE) -C $(dir $(ANTMAN)) fclean -s
	@$(MAKE) -C $(dir $(GIANTMAN)) fclean -s
	@echo -e $(GREEN)' -> [finished]: $(NAME): make fclean'$(RESET)

.PHONY: re
re:	fclean all ## Fclean+All

.PHONY: tests_run
tests_run: fn_tests_run ## The rule called by Marvin to make coverage

.PHONY: fn_tests_run
fn_tests_run: fclean $(LIB_TARGET) ## Fonctional tests
	$(MAKE) -C $(dir $(ANTMAN)) tests_bin
	$(MAKE) -C $(dir $(GIANTMAN)) tests_bin
	$(TEST_BASH) ./$(ANTMAN) ./$(GIANTMAN)
	gcovr --exclude tests/ --merge-mode-function=separate || echo 'no gcovr'
	gcovr --exclude tests/ --branch --merge-mode-function=separate || \
		echo 'no gcovr'
