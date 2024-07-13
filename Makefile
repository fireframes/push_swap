NAME		:=	push_swap

CFLAGS		:=	-Wextra -Wall -Werror
HEADERS		:=	-Iinclude

LIBFT		:=	./lib/libft.a
LIBFTPRINTF	:=	./lib/libftprintf.a
LIBS		:=	$(LIBFT) $(LIBFTPRINTF)

SRCS_DIR	:=	./src/
SRCS 		:=	push_swap.c			\
				ps_dbllst_init.c	\
				ps_dbllst_utils.c	\
				ps_swap.c			\
				ps_push.c			\
				ps_rotate.c			\
				ps_rev_rotate.c		\
				ps_sort_stacks.c	\
				ps_sort_utils.c


SRCS		:=	$(addprefix $(SRCS_DIR), $(SRCS))

OBJS		:=	${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@echo "Compiling $< to $@..."
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(LIBFT) $(LIBFTPRINTF) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "Linking object files to create $(NAME)..."
	@echo "\n'$(NAME)' binary successfully created."

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJS)

fclean: clean
	@echo "\nPerforming full clean..."
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
