# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 13:19:56 by vst-pier          #+#    #+#              #
#    Updated: 2023/07/24 15:50:19 by vst-pier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = libft/libft.a
DEP = inc/fractol.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address -g

MK = mkdir -p					
RM = rm -rf

#Sources directories
INCDIR = inc
SRCDIR = src
LIBFTDIR = libft

SRC = fractol.c mandelbrot.c atod.c burningship.c color.c hook.c julia.c image.c
VPATH = $(SRCDIR)

#MLX
MLXDIR = MLX42/build
MLX_A = libmlx42.a
MLX = $(MLXDIR)/$(MLX_A)
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

#Object directories
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
$(OBJDIR)/%.o : %.c $(DEP)
	$(CC) $(CFLAGS) -I$(INCDIR) -Ilibft/inc -c $< -o $@

$(OBJDIR):
	$(MK) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all