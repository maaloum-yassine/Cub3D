/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:23:55 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 10:37:18 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/MLX42.h"
# include "utils_cub3d/utils_cub3d.h"
# include <fcntl.h>

typedef struct s_chck_path
{
	char	**cpy_mp;
	char	*tmp_sep;
}t_chck_path;

typedef struct s_ele_map
{
	t_chck_path	*s_shk_pth;
	char		**maps;
	char		**f;
	char		**c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			col_p;
	int			row_p;
	int			height_mp;
	int			width_mp;
	char		position;
}t_ele_map;

typedef struct s_texture
{
	mlx_texture_t		*s_img;
	int					img_x;
	int					img_y;
	char				status;
	struct s_texture	*next;
}t_texture;

typedef struct s_graphic
{
	t_texture		*s_texture;
	t_ele_map		*s_ele;
	mlx_t			*mlx;
	mlx_image_t		*mlx_img;
	double			pa;
	double			x_incr;
	double			y_incr;
	double			p_x;
	double			p_y;
	double			pdx;
	double			pdy;
	double			pdx_h;
	double			pdy_h;
	double			pdx_v;
	double			pdy_v;
	double			distance;
	int				mouse_x;
	int				mouse_y;
	int				mlx_win_img;
	int				w_height;
	int				start;
	int				end;
	char			v_ou_h;
}	t_graphic;

typedef struct s_data
{
	t_ele_map	*s_ele_mp;
	t_graphic	*s_grhc;
	char		**element;
	char		*path_mp;
	char		*line;
	char		*sep;
	int			fd;
	int			size_ele;
	char		check;
	char		empty;
}t_data;

void	ft_release_memory(t_data *s_dt);
void	ft_print_err(t_data *s_dt, char *err);
void	ft_protect_malloc(t_data *s_dt, void *ptr);
void	ft_handl_err(t_data *s_dt);
void	ft_raycasting(t_data *s_dt);
void	ft_free_texture(t_graphic *s_grhc);
#endif
