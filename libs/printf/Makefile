NAME		=	libftprintf.a

LBPATH		=	../libft/
LBNAME		=	$(LBPATH)libft.a

SRCS		=	./srcs/ft_annex1.c \
				./srcs/ft_cases_char.c \
				./srcs/ft_cases_pour.c \
				./srcs/ft_cases_str.c \
				./srcs/ft_cases_addr.c \
				./srcs/ft_conv_nbr.c \
				./srcs/ft_annex2.c \
				./srcs/ft_cases_negnb.c \
				./srcs/ft_conv1.c \
				./srcs/ft_printf.c \
				./srcs/ft_annex3.c \
				./srcs/ft_cases_posnb.c \
				./srcs/ft_conv2.c

OBJS_NAME	=	${SRCS:.c=.o}
OBJS_PATH	=	./

OBJS		=	$(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC	 		=	gcc -Wall -Werror -Wextra
RM	 		=	rm -rf

all:				$(NAME)

$(NAME):			$(OBJS)
					@make -C $(LBPATH)
					@cp $(LBNAME) $(NAME)
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					$(info ft_printf compiled)

$(OBJS_PATH)%.o:	%.c
					@mkdir $(OBJS_PATH) 2> /dev/null || true
					@$(CC) -I /srcs/ft_printf.h -c $< -o $@

clean:
					@$(RM) $(OBJS)
					@make fclean -C $(LBPATH)
					@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean:				clean
					@$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
