/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:29:06 by ychufist          #+#    #+#             */
/*   Updated: 2018/07/09 16:37:12 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		connect(char **tt_sp_fld)
{
	int		i;
	int		j;
	int		n;

	i = -1;
	n = 0;
	while (tt_sp_fld[++i] != '\0')
	{
		j = -1;
		while (++j < 4)
			n = con(i, j, n, tt_sp_fld);
		if (n == 2 || (tt_sp_fld[i + 1] != '\0' && (i + 1) % 4 == 0 && n < 6) ||
				((i + 1) % 4 == 0 && n == 0))
			return (0);
		else if (tt_sp_fld[i + 1] != '\0' && (i + 1) % 4 == 0)
			n = 0;
		if ((n == 6 || n == 8) && (i + 1) % 4 == 0)
		{
			n = 0;
			continue;
		}
	}
	if (n == 0)
		return (1);
	return (0);
}

int		con(int i, int j, int n, char **tt_sp_fld)
{
	if (tt_sp_fld[i][j] == '#')
	{
		if (j + 1 != 5 && tt_sp_fld[i][j + 1] == '#')
			n++;
		if (j != 0 && tt_sp_fld[i][j - 1] == '#')
			n++;
		if ((i + 1) % 4 != 0 && tt_sp_fld[i + 1] != '\0'
			&& tt_sp_fld[i + 1][j] == '#')
			n++;
		if (i != 0 && i % 4 != 0 && tt_sp_fld[i - 1][j] == '#')
			n++;
	}
	return (n);
}

int		row_z_n(char const *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (file[4] != '\n')
		return (0);
	while (file[i] != '\0')
	{
		if (i > 0 && i % 20 == 0)
			j++;
		if (file[i] != '\0' && i > 4 && i % 5 == 0
				&& file[i + j + 4] != '\n' && file[i + j + 4] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int		n_mezdu(char const *file)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (file[4] != '\n')
		return (0);
	while (file[i] != '\0')
	{
		if (i > 20 && i % 20 == 0)
			j++;
		if (file[i] != '\0' && i > 0 && i % 20 == 0
				&& file[i + j] != '\n' && file[i + j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int		konec_fld(char *a)
{
	if ((ft_strlen(a) + 1) % 21 == 0)
		return (1);
	return (0);
}
