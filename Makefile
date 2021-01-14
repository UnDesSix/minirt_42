NAME		=	miniRT
CC			=	clang -Wall -Werror -Wextra -flto=thin -Ofast -O3 -fno-stack-protector -fno-math-errno -funsafe-math-optimizations -fassociative-math -freciprocal-math -funroll-loops -ftree-vectorize -finline-functions -ffp-contract=fast
RM			=	rm -rf

MLX_PATH	=	./libs/minilibx-linux/
MLX_NAME	=	$(MLX_PATH)libmlx.a
MLX_INC		=	-I$(MLX_PATH)

LIBC_PATH	=	./libs/libft/
LIBC_NAME	=	$(LIBC_PATH)libft.a
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
				parser/error_manager.c \
				maths/vec.c \
				maths/vec2.c \
				shape/sphere.c \
				shape/plane.c \
				shape/square.c \
				shape/cylinder.c \
				shape/triangle.c \
				bmp/bitmap.c \
				visual/ray.c \
				visual/mlx_functions.c \
				visual/camera.c \
				visual/shape_light.c \
				visual/visibility.c \
				visual/light.c \
				visual/color.c

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		=	$(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
			@$(CC) -I$(INC) $(MLX_INC) $(LIBC_INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make --silent -C $(MLX_PATH)
			@make --silent -C $(LIBC_PATH)
			@$(CC) $(OBJS) $(MLX_NAME) $(LIBC_NAME) -L$(MLX_PATH) -L/usr/lib -L$(LIBC_PATH) $(LIBC_INC) $(MLX_INC) -I$(INC) -lXext -lX11 -lm -o $(NAME) 
			$(info minirt compiled)

clean:
			@make clean --silent -C $(LIBC_PATH)
			@$(RM) $(OBJS)

fclean:		clean
			@make fclean --silent -C $(LIBC_PATH)
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		re fclean all clean
