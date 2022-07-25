NAME = fdf

SRCS = main.c get_next_line.c read_map.c get_next_line_utils.c draw.c set_dots.c \
		key_hook.c color.c error.c free.c

OBJS = $(SRCS:.c=.o)


MLX = minilibx_macos/libmlx.a

LIBFT = libft/libft.a

CC = gcc

FRAMEWORKS= -framework OpenGL -framework AppKit

%.o:%.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(OBJS) $(MLX)  $(LIBFT) -o $(NAME) $(FRAMEWORKS)


$(MLX) :
	@make -C minilibx_macos/

$(LIBFT) :
	@make -C libft/ 

clean: 
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(LIBFT) $(NAME)

norm:	
	norminette $(SRCS) fdf.h
	@make -C libft/ norm

re: fclean all

.PHONY: all clean fclean re