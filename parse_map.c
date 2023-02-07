/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evscheid <evscheid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:55:57 by evscheid          #+#    #+#             */
/*   Updated: 2023/02/02 01:25:27 by evscheid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	int fd;
	char *buf;
	char *stock;
	char **map;
	char *tmp;
	int		i;

	i = 0;
	fd = open("map/map_test.ber", O_RDONLY);
	while (1)
	{
		if (read(fd, &buf, 1) > 0)
		{
			printf("buf == %s\n", buf);
			if (!stock)
				stock = ft_strdup(buf);
			else
			{
				tmp = ft_strdup(stock);
				free(stock);
				stock = ft_strjoin(tmp, buf);
				free(tmp);
			}
		}
		else
			break ;
	}
	printf("%s", stock);
	exit (1);
	map = ft_split(stock, '\n');
	printf("%s", map[i]);
	exit(1);
	while (map[i])
		printf("%s", map[i++]);
	return(0);
}
