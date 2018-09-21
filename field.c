/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:56:37 by ychufist          #+#    #+#             */
/*   Updated: 2018/06/25 14:45:58 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 1

int		field_length(int tetraminos)
{
	int		i;
	int		n;

	i = tetraminos * 4;
	while (!ft_sqrt(i))
		i++;
	n = ft_sqrt(i);
	return (n);
}

char	**field(int n)
{
	int		i;
	int		j;
	char	**field;

	field = (char**)ft_memalloc(sizeof(char*) * (n + 1));
	i = 0;
	while (i < n)
	{
		field[i] = (char*)ft_memalloc(sizeof(char) * (n + 1));
		j = 0;
		while (j < n)
		{
			field[i][j] = '.';
			j++;
		}
		field[i][j] = '\0';
		i++;
	}
	field[i] = 0;
	return (field);
}

void	output(char **field)
{
	int		row;

	row = 0;
	while (field[row])
	{
		ft_putendl(field[row]);
		row++;
	}
}

char	*copy_a(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*a;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	a = (char*)malloc(sizeof(char) + 1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		a = ft_strjoin(a, buf);
	}
	close(fd);
	return (a);
}
