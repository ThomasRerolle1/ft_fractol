NAME = fractol

SRCS = main.c\
       srcs/init.c\
       srcs/parse.c\
       srcs/hook.c\
       srcs/clear.c\
       srcs/fractal.c

OBJ = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -g

MEMORYFLAGS = -g3 -fsanitize=address



.o: %.c
	#$(CC) $(CFLAGS)  -c $< -o $@
	$(CC) -Wall -Wextra -Werror -Imlx_mac -c $< -o $@

$(NAME): $(OBJ)
	make -C libft
	#$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft/libft.a -o $(NAME)
	$(CC) $(OBJ) $(MLXFLAGS) libft/libft.a -o $(NAME)
	
all: $(NAME)

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
	MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
else
	NPROC := $(shell sysctl -n hw.ncpu)
	MLXFLAGS = -Lmlx_mac -lmlx -framework OpenGL -framework Appkit

endif

clean:
	make clean -C libft
	/bin/rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

debug:	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) $(MLXFLAGS) $(MEMORYFLAGS) libft/libft.a -o $(NAME)

re: fclean all

.PHONY: all clean fclean re debug


