NAME		=	minirt
CC			=	clang -g -Wall -Werror -Wextra
#CC			=	gcc
RM			=	rm -rf

MLX_PATH	=	./libs/minilibx-linux/
MLX_NAME	=	$(MLX_PATH)libmlx.a
MLX_INC		=	-I$(MLX_PATH)

LIBC_PATH	=	./libs/printf/
LIBC_NAME	=	$(LIBC_PATH)libftprintf.a
LIBC_INC	=	-I$(LIBC_PATH)

SRCS_PATH	=	./srcs/
OBJS_PATH	=	./objs/
INC			=	./includes/

SRCS_NAME	=	main.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c \
				parser/annex1.c \
				parser/annex2.c \
				parser/annex3.c \
				parser/ft1_split.c \
				parser/line_checker_1.c \
				parser/line_checker_2.c \
				parser/line_filler_1.c \
				parser/line_filler_2.c \
				parser/parser.c \
				camera.c \
				vec.c \
				vec2.c \
				sphere.c \
				plane.c \
				triangle.c \
				light_apply.c \
				light.c

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		=	$(SRCS:.c=.o)
#OBJS		=	$(addprefix $(OBJS_PATH), $(OBJS_NAME))

all:		$(NAME)

%.o:		%.c
			@$(CC) -I$(INC) $(MLX_INC) $(LIBC_INC) -c $< -o $@
#			$(CC) -I$(INC) $(LIBC_INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make --silent -C $(MLX_PATH)
			@make --silent -C $(LIBC_PATH)
			@$(CC) $(OBJS) $(MLX_NAME) $(LIBC_NAME) -L$(MLX_PATH) -L/usr/lib -L$(LIBC_PATH) $(LIBC_INC) $(MLX_INC) -I$(INC) -lXext -lX11 -lm -lz -o $(NAME) 
#			$(CC) $(OBJS) $(LIBC_NAME) -L$(LIBC_PATH) $(LIB_INC) -I$(INC) -o $(NAME)
			$(info minirt compiled)

clean:
			@make clean --silent -C $(LIBC_PATH)
			@$(RM) $(OBJS)

fclean:		clean
			@make fclean --silent -C $(LIBC_PATH)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		re fclean all clean
