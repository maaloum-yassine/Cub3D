/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaghrous <yaghrous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 01:20:25 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 06:12:23 by yaghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ft_free_strcut_graphic(t_graphic *s_grhc)
{
	if (s_grhc)
	{
		if (s_grhc->s_texture)
			ft_free_texture(s_grhc);
		if (s_grhc->mlx_img)
			mlx_delete_image(s_grhc->mlx, s_grhc->mlx_img);
		if (s_grhc->mlx)
			free (s_grhc->mlx);
	}
	free (s_grhc);
}

void	ft_release_memory(t_data *s_dt)
{
	if (s_dt)
	{
		if (s_dt->line != NULL)
			free (s_dt->line);
		if (s_dt->sep != NULL)
			free (s_dt->sep);
		ft_free_split(s_dt->element);
		if (s_dt->s_ele_mp)
		{
			ft_free_split(s_dt->s_ele_mp->maps);
			ft_free_split(s_dt->s_ele_mp->f);
			ft_free_split(s_dt->s_ele_mp->c);
			if (s_dt->s_ele_mp->no)
				free (s_dt->s_ele_mp->no);
			if (s_dt->s_ele_mp->so)
				free (s_dt->s_ele_mp->so);
			if (s_dt->s_ele_mp->ea)
				free (s_dt->s_ele_mp->ea);
			if (s_dt->s_ele_mp->we)
				free (s_dt->s_ele_mp->we);
			free (s_dt->s_ele_mp);
		}
		ft_free_strcut_graphic(s_dt->s_grhc);
		free (s_dt);
	}
}

void	ft_print_err(t_data *s_dt, char *err)
{
	if (s_dt->fd != -1)
		close(s_dt->fd);
	ft_release_memory(s_dt);
	write(2, "\033[31mError\n", 11);
	while (*err)
		write(2, err++, 1);
	exit(1);
}

static	void	ft_initialize_s_dt(t_data	**s_dt)
{
	(*s_dt)->s_ele_mp = NULL;
	(*s_dt)->s_grhc = NULL;
	(*s_dt)->element = NULL;
	(*s_dt)->line = NULL;
	(*s_dt)->sep = NULL;
	(*s_dt)->fd = -1;
	(*s_dt)->check = 5;
}

int	main(int ac, char **av)
{
	t_data	*s_dt;

	s_dt = malloc(sizeof(t_data));
	ft_protect_malloc(s_dt, s_dt);
	ft_initialize_s_dt(&s_dt);
	s_dt->path_mp = av[1];
	if (ac == 2)
	{
		ft_handl_err(s_dt);
		ft_raycasting(s_dt);
	}
	else if (ac > 2)
		ft_print_err(s_dt,
			"the program takes the file path of the '.cub' map alone ![^_^]\n");
	else
		ft_print_err(s_dt,
			"the program takes the file path of the '.cub' map! [^_^]\n");
	return (0);
}
