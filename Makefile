GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

CH		:= checker
PS		:= push_swap

DCH		:= d_$(CH)
DPS		:= d_$(PS)

CC		:= gcc

CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	:= -Wall -Wextra -g

CHFILES	:= main.c\
			get_stack.c\
			get_moves.c\
			list.c\
			push.c\
			swap.c\
			rotate.c\
			check_valid.c\

PSFILES	:= main.c\
			get_stack.c\
			check_valid.c\
			list.c\
			push.c\
			swap.c\
			rotate.c\
			sort/bestmove.c\
			sort/cheeseburger_special.c\
			sort/getleast.c\
			sort/sortleast.c\
			sort/sort3.c\
			sort/sort4.c\
			sort/sort5.c\
			sort/small_sort_helpers.c\

CHSRC	:= $(addprefix srcs/checker/, $(CHFILES))
PSSRC	:= $(addprefix srcs/push_swap/, $(PSFILES))


LIBFT	:= libft/libft.a
LIB		:= -I libft/ $(LIBFT)

all: $(CH) $(PS)

ch: $(CH)

ps: $(PS)

$(CH):
	@$(CC) $(CFLAGS) $(LIB) $(CHSRC) -o $(CH)
	@echo "[$(GREEN)$@$(RES)] compiled."

$(PS):
	@$(CC) $(CFLAGS) $(LIB) $(PSSRC) -o $(PS)
	@echo "[$(GREEN)$@$(RES)] compiled."

d: $(DCH) $(DPS)

dch: $(DCH)

dps: $(DPS)

$(DCH):
	@$(CC) $(DFLAGS) $(LIB) $(CHSRC) -o $(DCH)
	@echo "[$(GREEN)$@$(RES)] compiled."

$(DPS):
	@$(CC) $(DFLAGS) $(LIB) $(PSSRC) -o $(DPS)
	@echo "[$(GREEN)$@$(RES)] compiled."

libft:
	@make -sC libft re
	@echo "[$(GREEN)$@$(RES)] compiled."

clean:
	@echo "objects removed."

dclean:
	@rm -rf $(DCH) $(DCH).dSYM/
	@echo "[$(GREEN)$(DCH)$(RES)] removed."
	@rm -rf $(DPS) $(DPS).dSYM/
	@echo "[$(GREEN)$(DPS)$(RES)] removed."

fclean: clean
	@rm -f $(CH)
	@echo "[$(GREEN)$(CH)$(RES)] removed."
	@rm -f $(PS)
	@echo "[$(GREEN)$(PS)$(RES)] removed."

re: fclean all

.PHONY: all libft d clean dclean fclean re ch ps dch dps
