/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:20:14 by ychufist          #+#    #+#             */
/*   Updated: 2018/06/25 14:55:37 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**clean(char **field, char c)
{
	int		i;
	int		j;

	i = 0;
	while (field[i] != '\0')
	{
		j = 0;
		while (field[i][j] != '\0')
		{
			if (field[i][j] == c)
				field[i][j] = '.';
			j++;
		}
		i++;
	}
	return (field);
}

int		backtracking(char **fld, t_ttlist *arr_ttrmns, int n, t_point orgn)
{
	t_ttlist	*tmp;
	t_point		indx;

	indx.x[0] = -1;
	tmp = arr_ttrmns;
	if (!tmp)
		return (1);
	while (++indx.x[0] < n)
	{
		indx.y[0] = -1;
		while (++indx.y[0] < n)
		{
			orgn = where_to_insert(fld, tmp, indx);
			if (orgn.x[1] != 0 || orgn.y[1] != 0 || orgn.x[2] != 0 ||
					orgn.y[2] != 0)
			{
				insert(fld, orgn, tmp->c);
				if ((backtracking(fld, tmp->next, n, indx)) == 1)
					return (1);
				else
					fld = clean(fld, tmp->c);
			}
		}
	}
	return (0);
}
