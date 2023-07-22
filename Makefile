NAME	=	cub3D

SRCDIR		= ./src/
SRCNAMES	= $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC 		= $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ			= $(SRC:.c=.o)
INC 		= ./inc/cub3d.h
BUILDDIR 	= ./build/
BUILDOBJS 	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))
FLAGS_MAC	= -framework OpenGL -framework AppKit

LIBDIR 		= ./libft/
LIBFT 		= ./libft/libft.a
LIBINC 		= ./libft/
MLXDIR 		= ./mlx/
MLX			= ./mlx/libmlx.a

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

DEBUG 		= -g

all:		$(MLX) $(LIBFT) $(BUILDDIR) $(NAME)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) -I$(LIBINC) -I$(INC) $(CFLAGS) -g -o $@ -c $<

$(NAME): $(BUILDOBJS) $(INC)
	$(CC) -g -o $(NAME) $(BUILDOBJS) $(LIBFT) $(MLX) $(FLAGS_MAC)

$(LIBFT):
	make -C $(LIBDIR)

$(MLX):
	make -C $(MLXDIR)

clean:
	rm -rf $(SRCDIR)$(OBJ)
	make -C $(LIBDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BUILDDIR)
	make -C $(LIBDIR) fclean
	make -C $(MLXDIR) clean

re: fclean all

.PHONY: all fclean clean re
