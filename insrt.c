/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insrt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:28:46 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/02 12:24:26 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**insert(char **field, t_point orgn, char c)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		field[orgn.x[k]][orgn.y[k]] = c;
		k++;
	}
	return (field);
}

t_point		zeropoint(t_point orgn, int k)
{
	while (k < 4)
	{
		orgn.x[k] = 0;
		orgn.y[k] = 0;
		k++;
	}
	return (orgn);
}

void		insrt_znach(t_point *orgn, int other_x, int other_y, int k)
{
	orgn->x[k] = other_x;
	orgn->y[k] = other_y;
}

int			prov_if(t_ttlist *tt, t_point *crd, int k, char **field)
{
	if (field[crd->x[0] + tt->point.x[k + 1] - tt->point.x[k]] &&
k < 3 && field[crd->x[0] + tt->point.x[k + 1] - tt->point.x[k]][crd->y[0] +
			tt->point.y[k + 1] - tt->point.y[k]] == '.')
	{
		insrt_znach(crd, crd->x[0] + tt->point.x[k + 1] - tt->point.x[k], \
			crd->y[0] + tt->point.y[k + 1] - tt->point.y[k], 0);
		return (1);
	}
	return (0);
}

t_point		where_to_insert(char **field, t_ttlist *tt, t_point indx)
{
	t_point		crd;
	int			k;
	t_point		orgn;

	k = 0;
	insrt_znach(&orgn, indx.x[0], indx.y[0], 0);
	crd.x[0] = indx.x[0] - 1;
	while (field[++crd.x[0]] != '\0')
	{
		crd.y[0] = (crd.x[0] == indx.x[0] ? indx.y[0] : 0);
		while (field[crd.x[0]][crd.y[0]] != '\0')
		{
			if (field[crd.x[0]][crd.y[0]] == '.')
			{
				insrt_znach(&orgn, crd.x[0], crd.y[0], k);
				if (prov_if(tt, &crd, k, field) == 1)
					k++;
				else
					return ((k == 3) ? (orgn) : (zeropoint(orgn, 0)));
			}
			else
				return (zeropoint(orgn, 0));
		}
	}
	return (zeropoint(orgn, 0));
}
