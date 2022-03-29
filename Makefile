# Manual for Makefile
# https://www.gnu.org/software/make/manual/html_node/index.html
NAME = push_swap

SRC += main.c
SRC += init_stack.c
SRC += operations_push.c operations_swap.c
SRC += operations_rotate.c operations_rev_rotate.c
SRC += score.c sort.c

SRCDIR = ./
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))
D_FILES = $(addprefix $(OBJDIR), $(notdir$(SRC:.c=.d)))
CC ?= gcc -Wall -Werror -Wextra
DEBUG = -g
OPTIMIZATION = -O1
LIB += -lft
LIBPATH += -L./libraries/libft/
LIBINC += -I./libraries/libft/

all : $(NAME)

# translation of assembly language code into machine code
# -c, stops after assembly stage
# -MD lists both system header files and user header files, dependencies
# -MMD lists only user header files, dependencies
# $< the first prerequisite (usually a source file) main.c (dependency %.c)
# $@ is the name of the target being generated main.o (target %.o)
$(OBJDIR)%.o : $(SRCDIR)%.c push_swap.h obj
	$(CC) $(DEBUG) $(LIBINC) -c $< -o $@ -MMD

# linking stage
$(NAME): $(OBJ)
	make bonus -C ./libraries/libft/
	$(CC) $(OBJ) $(LIBPATH) $(LIB) $(LIBINC)  -o $(NAME)

obj:
	mkdir -p $(OBJDIR)

include $(wildcard $(D_FILES))

bonus: all

norm:
	norminette $(SRC)

# rule for the cleaning
clean:
	make clean -C ./libraries/libft/
	rm -rf $(OBJDIR)

fclean:
	make fclean -C ./libraries/libft/
	rm -rf $(OBJDIR)
	rm -f $(NAME)

# rule for rebuild a project
re: fclean all

# directory exceptions
.PHONY: all clean fclean norm re bonus
