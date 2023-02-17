/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:48:36 by evscheid          #+#    #+#             */
/*   Updated: 2023/02/17 18:36:13 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->input_a = 0;
	game->input_w = 13;
	game->input_d = 2;
	game->input_s = 1;
	game->player.skin = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/perso_base.xpm", &game->blabla, &game->bloblo);
	game->img.floor = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/floorAS.xpm", &game->blabla, &game->bloblo);
	game->img.top_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/bottom_big_wall.xpm", &game->blabla, &game->bloblo);
	game->img.bottom_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/top_big_wall.xpm", &game->blabla, &game->bloblo);
	game->img.left_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/right_big_wall.xpm", &game->blabla, &game->bloblo);
	game->img.right_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/left_big_wall.xpm", &game->blabla, &game->bloblo);
	game->img.corner_gh = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/corner_gh.xpm", &game->blabla, &game->bloblo);
	game->img.corner_gb = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/corner_gb.xpm", &game->blabla, &game->bloblo);
	game->img.corner_dh = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/corner_dh.xpm", &game->blabla, &game->bloblo);
	game->img.corner_db = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/corner_db.xpm", &game->blabla, &game->bloblo);
	game->img.obstacle = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/obstacle.xpm", &game->blabla, &game->bloblo);
	game->img.dead_body = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/dead_body.xpm", &game->blabla, &game->bloblo);
	game->img.vent = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/vent.xpm", &game->blabla, &game->bloblo);
}


int	parse_hauteur(t_game *game)
{
	int	i;

	i = 0;	
	while (game->map[i])
	{
		i++;
	}
	return (i);
}


void 	print_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image, x +32, y);
}

void	set_exit(t_game *game)
{
	int	i;
	int j;
	
	i = 1;
	while (game->map[i + 1])
	{
		j = 1;
		while (game->map[i + 1][j + 1])
		{
			if (game->map[i][j] == 'E')
			{
				print_image(game, game->img.vent, j * LONGUEUR, i * HAUTEUR);
			}
			j ++;
			
		}
		i++;
	}
}

void	set_obstacle(t_game *game)
{
	int	i;
	int j;
	
	i = 1;
	while (game->map[i + 1])
	{
		j = 1;
		while (game->map[i + 1][j + 1])
		{
			if (game->map[i][j] == '1')
				print_image(game, game->img.obstacle, j * LONGUEUR, i * HAUTEUR);
			j ++;
			
		}
		i++;
	}
}

void	set_collecible(t_game *game)
{
	int	i;
	int j;
	int c;
	
	c = 0;
	i = 1;
	while (game->map[i + 1])
	{
		j = 1;
		while (game->map[i + 1][j + 1])
		{
			if (game->map[i][j] == 'C')
			{
				print_image(game, game->img.dead_body, j * LONGUEUR, i * HAUTEUR);
				c++;
				printf("count = %d\n", game->count);
			}
			j ++;
		}
		i++;
	}
	game->count = c;
}

int	parse_longueur(t_game *game)
{
	int i;
	
	i = ft_strlen(game->map[0]);
	return (i);
}

void 	print_left_wall(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		print_image(game, game->img.left_wall, -32, j);
		j += 454;
		i++;
	}
}

void 	print_right_wall(t_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		print_image(game, game->img.right_wall, game->width - LONGUEUR, j);
		j += 454;
		i++;
	}
}

void	print_bottom_wall(t_game *game)
{
	int i;
	int j;
	
	i = game->height;
	printf("%d\n", LONGUEUR);
	j = 0;
	printf("%d\n", i);
	while (j < game->width)
	{
		print_image(game, game->img.bottom_wall, j - 32, i - HAUTEUR);
		j += 454;	
 	}
}
void	print_top_wall(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->width)
	{
		print_image(game, game->img.top_wall, j - 32, 0);
		j += 454;
 	}
}

void	print_floor(t_game *game)
{
	int i;
	int j;
	
		i = 1;
		while (game->map[i + 1])
		{
			j = 1;
			while (game->map[i + 1][j + 1])
			{
				print_image(game, game->img.floor, j * LONGUEUR, i * HAUTEUR);
				j ++;
				
			}
			i++;
		}
}

void	player_setup(t_game *game)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
			{
				print_image(game, game->player.skin, j * LONGUEUR, i * HAUTEUR);
				game->player_x = j * LONGUEUR;
				game->player_y = i * HAUTEUR;
				game->str_x = j;
				game->str_y = i; 
			}
			i++;
		}
		j++;
	}
}

int	background(t_game *game)
{
	print_floor(game);
	print_bottom_wall(game);
	print_top_wall(game);
	print_right_wall(game);
	print_left_wall(game);
	print_image(game, game->img.corner_gh, -32, 0);
	print_image(game, game->img.corner_gb, -32, game->height - HAUTEUR);
	print_image(game, game->img.corner_dh, game->width - LONGUEUR, 0);
	print_image(game, game->img.corner_db, game->width - LONGUEUR, game->height - HAUTEUR);
	set_obstacle(game);
	set_collecible(game);
	player_setup(game);
	set_exit(game);
	return (0);
}


static void	player_moove(int whopress, t_game *game)
{
	static int x;
	static int y;
	
	x = game->str_x;
	y = game->str_y;
	printf("VALEUR DE X :%d\nVALEUR DE Y : %d\n", game->player_x, game->player_y);
	print_image(game, game->img.floor, game->player_x, game->player_y);
	
	if (whopress == 13)
	{
		if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'P' || game->map[y - 1][x] == 'C' || game->map[y - 1][x] == 'E')
		{
			if (game->map[y - 1][x] == 'E')
			{
				mlx_clear_window(game->mlx_ptr, game->win_ptr);
				mlx_destroy_image(game->mlx_ptr, game->win_ptr);
			}
			game->player_y -= 82;
			game->str_y--;
			print_image(game, game->player.skin, game->player_x, game->player_y);
		}
		else
			print_image(game, game->player.skin, game->player_x, game->player_y);		
	}
	else if (whopress == 0)
	{
		if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'P' || game->map[y][x - 1] == 'C' || game->map[y][x - 1] == 'E')
		{
			if (game->map[y][x - 1] == 'E')
			{
				mlx_clear_window(game->mlx_ptr, game->win_ptr);
				mlx_destroy_image(game->mlx_ptr, game->win_ptr);
			}
			game->player_x -= 57;
			game->str_x--;
			print_image(game, game->player.skin, game->player_x, game->player_y);
		}
		else
			print_image(game, game->player.skin, game->player_x, game->player_y);	
	}
	else if (whopress == 2)
	{
		if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'P' || game->map[y][x + 1] == 'C' || game->map[y][x + 1] == 'E')
		{
			if (game->map[y][x + 1] == 'E')
			{
				mlx_clear_window(game->mlx_ptr, game->win_ptr);
				mlx_destroy_image(game->mlx_ptr, game->win_ptr);
			}
			game->player_x += 57;
			game->str_x++;
			print_image(game, game->player.skin, game->player_x, game->player_y);
		}
		else
			print_image(game, game->player.skin, game->player_x, game->player_y);	

			
	}
	else if (whopress == 1)
	{
		if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C' || game->map[y + 1][x] == 'P' || game->map[y + 1][x] == 'E')
		{
			if (game->map[y + 1][x] == 'E')
			{
				mlx_clear_window(game->mlx_ptr, game->win_ptr);
				mlx_destroy_image(game->mlx_ptr, game->win_ptr);
			}
			game->player_y += 82;
			game->str_y++;
			print_image(game, game->player.skin, game->player_x, game->player_y);
		}
		else
			print_image(game, game->player.skin, game->player_x, game->player_y);
	}
	// printf("VALEUR DE Y : %c\n", game->map[game->str_x][game->str_y]);

}

int		key_press(int keysim, t_game *game)
{
	printf("%d\n", keysim);
	if (keysim == 53)
		exit(1);
	if (keysim == 13)
		player_moove(13, game);
	if (keysim == 0)
		player_moove(0, game);
	if (keysim == 2)
		player_moove(2, game);
	if (keysim == 1)
		player_moove(1, game);
	return (0);
}

void	mlx_setup(t_game *game)
{
	game->width = parse_longueur(game) * LONGUEUR;
	game->height =  parse_hauteur(game) * HAUTEUR;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width +63, game->height, "so_long_Amoung_Us.");
	init(game);
	background(game);
	mlx_hook(game->win_ptr, 2, 0, &key_press, game);
	mlx_loop(game->mlx_ptr);
}

int main(void)
{
	t_game	game;
	
	int fd;
	char *line;
	char *stock;
	char **map;
	char *tmp;
	int	i;

	i = 0;
	stock = NULL;
	line = NULL;
	tmp = NULL;
	fd = open("map/map_test_sec.ber", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!stock)
			stock = ft_strdup(line);
		else
		{
			tmp = ft_strdup(stock);
			free(stock);
			stock = ft_strjoin(tmp, line);
			free(tmp);
		}
		if (line)
			free(line);
	}
	game.map = ft_split(stock, '\n');
	mlx_setup(&game);
	return(0);
}
