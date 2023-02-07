/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:05:44 by evscheid          #+#    #+#             */
/*   Updated: 2023/02/02 02:19:11 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "lib/gnl/get_next_line.h"
# include "lib/libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct s_img{
	void	*floor;
	void	*top_wall;
	void	*bottom_wall;
	void	*space_background;
}					t_img;

typedef struct s_player{
	void	*skin;	
}					t_player;

typedef struct s_game {
	void	*mlx_ptr;
	void	*win_ptr;
	int		blabla;
	int		bloblo;
	int		frame;
	int		verif;
	int		case_size_X;
	int		case_size_Y;
	int		input_w;
	int		input_a;
	int		input_s;
	int		input_d;
	int		screen_X;
	int		screen_Y;
	char	**map;
	t_img	img;
	t_player	player;
	
}					t_game;

void	mlx_setup(t_game *game);
int		key_press(int keysim, t_game *game);
int		run(t_game *game);

#endif