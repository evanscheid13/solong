/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:48:36 by evscheid          #+#    #+#             */
/*   Updated: 2023/02/02 02:45:34 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int screen_Y = 1080;
int screen_X = 1920;

void	init(t_game *game)
{
	game->input_a = 0;
	game->input_w = 13;
	game->input_d = 2;
	game->input_s = 1;
	game->player.skin = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/perso_base.xpm", &game->blabla, &game->bloblo);
	game->img.floor = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/floorAS.xpm", &game->blabla, &game->bloblo);
	game->img.top_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/top_wall.xpm", &game->blabla, &game->bloblo);
	game->img.bottom_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./xpm/bottom_wall.xpm", &game->blabla, &game->bloblo);
}

int	background(t_game *game)
{
	int i;
	int j;
	int a;
	int b;
	
	i = 0;
	j = 0;
	a = 0;
	b = 0;

	while (j < screen_Y)
	{
		while (i < screen_X)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, i, j);
			i += 57;
		}
		j += 82;
		i = 0;
 	}
	while (a < screen_X)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.top_wall, a, b);
		a += 227;
	}
	a = 0;
	b = screen_Y - 82;
	while (a < screen_X)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.bottom_wall, a, b);
		a += 227;
	}
	return (0);
}

void	render_map(t_game *game)
{
	int	i;
	int j;
	int x;
	int y;

	x =0;
	y =0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			printf("[%c]x=%d y=%d", game->map[j][i], x, y);
			if (game->map[j][i] == '1' && j == 0)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.top_wall, x, y);
			else if (game->map[j][i] == '1' && j != 0)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.bottom_wall, x, y);
			else if (game->map[j][i] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, x, y);
			else if (game->map[j][i] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, x, y);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.skin, x, y);
			}
			i++;
			x += 227;
		}
		printf("\n\n");
		y += 82;
		x = 0;
		i = 0;
		j++;
	}	
}

static void	player_moove(int whopress, t_game *game)
{
	static int i;
	static int j;

	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.floor, i, j);
	if (whopress == 13)
	{
		j -= 82;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.skin, i, j);
	}
	else if (whopress == 0)
	{
		i -= 57;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.skin, i, j);
	}
	else if (whopress == 2)
	{
		i += 57;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.skin, i, j);
	}
	else if (whopress == 1)
	{
		j += 82;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.skin, i, j);
	}
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
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 1920, 1080, "so_long_Amoung_Us.");
	init(game);
	render_map(game);
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
	fd = open("map/map_test.ber", O_RDONLY);
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