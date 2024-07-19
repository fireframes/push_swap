NAME		:=	push_swap

CFLAGS		:=	-Wextra -Wall -Werror
HEADERS		:=	-Iinclude

LIBFT		:=	./lib/libft.a
LIBFTPRINTF	:=	./lib/libftprintf.a
LIBS		:=	$(LIBFT) $(LIBFTPRINTF)

SRCS_DIR	:=	./src/
SRCS 		:=	push_swap.c		\
				dbllst_init.c	\
				dbllst_utils.c	\
				swap.c			\
				push.c			\
				rotate.c			\
				rev_rotate.c		\
				normalize_stack.c	\
				sort_utils.c		\
				sort_stack.c


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
