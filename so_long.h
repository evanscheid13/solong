/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:05:44 by evscheid          #+#    #+#             */
/*   Updated: 2023/02/17 18:28:51 by evscheid         ###   ########.fr       */
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


# ifndef LONGUEUR
#  define LONGUEUR 57
#endif

# ifndef HAUTEUR
#  define HAUTEUR 82
#endif 

typedef struct s_img{
	void	*floor;
	void	*top_wall;
	void	*bottom_wall;
	void	*left_wall;
	void	*right_wall;
	void	*space_background;
	void	*corner_gh;
	void	*corner_gb;
	void	*corner_dh;
	void	*corner_db;
	void	*obstacle;
	void	*dead_body;
	void	*vent;
}					t_img;

typedef struct s_player{
	void	*skin;	
}					t_player;

typedef struct s_game {
	void	*mlx_ptr;
	void	*win_ptr;
	int		player_x;
	int		player_y;
	int		str_x;
	int		str_y;
	int		height;
	int		width;
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
	int		count;
	char	**map;
	t_img	img;
	t_player	player;
	
}					t_game;

void	mlx_setup(t_game *game);
int		key_press(int keysim, t_game *game);
int		run(t_game *game);

#endif