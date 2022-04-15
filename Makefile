# Manual for Makefile
# https://www.gnu.org/software/make/manual/html_node/index.html
NAME = push_swap
NAME_bonus = checker

SRC_ps = main.c init_stack.c operations_push.c operations_swap.c \
operations_rotate.c operations_rev_rotate.c score.c sort.c
SRC_bonus = bonus.c init_stack.c operations_push.c operations_swap.c \
operations_rotate.c operations_rev_rotate.c score.c sort.c

SRCDIR = ./
OBJDIR = ./obj/
OBJ_ps = $(addprefix $(OBJDIR), $(notdir $(SRC_ps:.c=.o)))
D_FILES_ps = $(addprefix $(OBJDIR), $(notdir$(SRC_ps:.c=.d)))
OBJ_bonus = $(addprefix $(OBJDIR), $(notdir $(SRC_bonus:.c=.o)))
D_FILES_bonus = $(addprefix $(OBJDIR), $(notdir$(SRC_bonus:.c=.d)))
CC = gcc -Wall -Werror -Wextra
DEBUG = -g
OPTIMIZATION = -O1
LIB += -lft
LIBPATH += -L./libraries/libft/
LIBINC += -I./libraries/libft/

all: $(NAME)

# translation of assembly language code into machine code
# -c, stops after assembly stage
# -MD lists both system header files and user header files, dependencies
# -MMD lists only user header files, dependencies
# $< the first prerequisite (usually a source file) main.c (dependency %.c)
# $@ is the name of the target being generated main.o (target %.o)
$(OBJDIR)%.o: $(SRCDIR)%.c push_swap.h | obj
	$(CC) $(DEBUG) $(LIBINC) -c $< -o $@ -MMD

# linking stage
$(NAME): obj $(OBJ_ps)
	make -C ./libraries/libft/
	$(CC) $(OBJ_ps) $(LIBPATH) $(LIB) $(LIBINC) -o $(NAME)

obj:
	mkdir -p $(OBJDIR)

include $(wildcard $(D_FILES_ps))
include $(wildcard $(D_FILES_bonus))

bonus: $(OBJ_bonus)
	make -C ./libraries/libft/
	$(CC) $(OBJ_bonus) $(LIBPATH) $(LIB) $(LIBINC) -o $(NAME_bonus)

norm:
	norminette

# rule for the cleaning
clean:
	make clean -C ./libraries/libft/
	rm -rf $(OBJDIR)

fclean:
	make fclean -C ./libraries/libft/
	rm -rf $(OBJDIR)
	rm -f $(NAME) $(NAME_bonus)

# rule for rebuild a project
re: fclean all

# directory exceptions
.PHONY: all clean fclean norm re bonus
