# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 08:35:58 by ymaaloum          #+#    #+#              #
#    Updated: 2024/06/28 10:52:24 by ymaaloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	= 	-Wall -Wextra -Werror
NAME1	=	cub3D
NAME2   =	cub3D_BONUS
SRC1	=	mandatory/cub3d.c \
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c \
			mandatory/utils_cub3d/utils1.c\
			mandatory/utils_cub3d/utils2.c\
			mandatory/utils_cub3d/utils3.c\
			mandatory/utils_cub3d/utils4.c\
			mandatory/handl_err/handl_err1.c\
			mandatory/handl_err/handl_err2.c\
			mandatory/handl_err/handl_err3.c\
			mandatory/handl_err/handl_err4.c\
			mandatory/handl_err/handl_err5.c\
			mandatory/handl_err/handl_err6.c\
			mandatory/handl_err/handl_err7.c\
			mandatory/raycasting/ray.c\
			mandatory/raycasting/ray_move_key.c\
			mandatory/raycasting/ray_distance.c\
			mandatory/raycasting/ray_draw1.c\
			mandatory/raycasting/ray_draw2.c\
			mandatory/raycasting/draw_texture.c\

SRC2	= 	bonus/cub3d_bonus.c \
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c \
			bonus/utils_cub3d_bonus/utils1_bonus.c\
			bonus/utils_cub3d_bonus/utils2_bonus.c\
			bonus/utils_cub3d_bonus/utils3_bonus.c\
			bonus/utils_cub3d_bonus/utils4_bonus.c\
			bonus/handl_err_bonus/handl_err1_bonus.c\
			bonus/handl_err_bonus/handl_err2_bonus.c\
			bonus/handl_err_bonus/handl_err3_bonus.c\
			bonus/handl_err_bonus/handl_err4_bonus.c\
			bonus/handl_err_bonus/handl_err5_bonus.c\
			bonus/handl_err_bonus/handl_err6_bonus.c\
			bonus/handl_err_bonus/handl_err7_bonus.c\
			bonus/raycasting_bonus/ray_bonus.c\
			bonus/raycasting_bonus/ray_move_key_bonus.c\
			bonus/raycasting_bonus/ray_move_mouse_bonus.c\
			bonus/raycasting_bonus/ray_distance_bonus.c\
			bonus/raycasting_bonus/ray_draw1_bonus.c\
			bonus/raycasting_bonus/ray_draw2_bonus.c\
			bonus/raycasting_bonus/ray_draw3_bonus.c\
			bonus/raycasting_bonus/draw_texture_bonus.c\

RESET		= 	\033[1;97m
GREEN 		= 	\033[1;32m
RED			= 	\033[1;31m

OBJ1			= 	$(SRC1:.c=.o)
OBJ1			:=	$(addprefix obj/, $(OBJ1))
OBJ_DIR1		= 	obj/ obj/mandatory/ obj/get_next_line obj/mandatory/handl_err obj/mandatory/utils_cub3d obj/mandatory/raycasting
OBJ2			= 	$(SRC2:.c=.o)
OBJ2			:=	$(addprefix obj_bonus/, $(OBJ2))
OBJ_DIR2		= 	obj_bonus/ obj_bonus/bonus/ obj_bonus/get_next_line obj_bonus/bonus/handl_err_bonus obj_bonus/bonus/utils_cub3d_bonus obj_bonus/bonus/raycasting_bonus
GLFW_DIR 		= 	$(shell brew --prefix glfw)/lib
FRAMEWORKS 		= 	-framework Cocoa -framework OpenGL -framework IOKit
MLX_DIR 		= 	./MLX42
MLX_LIB 		= 	-L$(MLX_DIR) -L$(GLFW_DIR) -lmlx42 -lglfw

CUB =  $(FRAMEWORKS) $(MLX_LIB)

all: $(OBJ_DIR1) ${NAME1}

$(OBJ_DIR1):
			@echo "$(GREEN)$(OBJ_DIR1) : Created ! [^_^]$(RESET)"
			mkdir -p $(OBJ_DIR1)


$(NAME1): $(OBJ1)
		@$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)  $(CUB)
		@echo "$(GREEN)$(NAME1) : Created ! [^_^]$(RESET)"

obj/%.o: %.c
		$(CC) $(CFLAGS) -c  $< -o $@

$(OBJ_DIR2):
		@echo "$(GREEN)$(OBJ_DIR2) : Created ! [^_^]$(RESET)"
		mkdir -p $(OBJ_DIR2)

bonus: $(OBJ_DIR2) ${NAME2}

$(NAME2): $(OBJ2)
		@$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)  $(CUB)
		@echo "$(GREEN)$(NAME2) : Created ! [^_^]$(RESET)"

obj_bonus/%.o: %.c
		$(CC) $(CFLAGS) -c  $< -o $@

clean:
		@rm -rf obj
		@rm -rf obj_bonus
		@echo "$(RED)$(NAME1) : file obj deleted ! [^_^]$(RESET)"
fclean: clean
			@rm -f $(NAME1)
			@rm -f $(NAME2)
			@echo "$(RED)$(NAME1) : file obj and file executable deleted ! [^_^]$(RESET)"
re: fclean all
