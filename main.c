/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:47:26 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/10 13:51:59 by amartyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*a;
	t_ttlist	*arr_ttrmnss;
	t_point		indx;
	int			n;
	char		**fld;

	if (argc == 2)
	{
		indx.x[0] = 0;
		indx.y[0] = 0;
		a = copy_a(argv[1]);
		if (ai2(a) == 1)
			return (0);
		fld = ft_strsplit(a, '\n');
		n = count_hash(a) / 4;
		arr_ttrmnss = cut_ttrmns(fld, n);
		n = field_length(n);
		fld = field(n);
		if (while_back(fld, arr_ttrmnss, n, indx) == 0)
			return (0);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}

int		ai2(char *a)
{
	char		**fld;

	if (a == 0 || (konec_fld(a) == 0) || (symbols(a) == 0) ||
		(count_hash(a) == 0) || (count_hash(a) % 4 != 0) || (row_z_n(a) == 0) ||
		(count_hash(a) / 4 > 26) || (n_mezdu(a) == 0) ||
		(ft_strlen(a) + 1) / 21 != count_hash(a) / 4)
	{
		ft_putstr("error\n");
		return (1);
	}
	fld = ft_strsplit(a, '\n');
	if (connect(fld) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}

int		while_back(char **fieldd, t_ttlist *arr_ttrmnss, int n, t_point indx)
{
	while (arr_ttrmnss)
	{
		if (backtracking(fieldd, arr_ttrmnss, n, indx) == 0)
		{
			n++;
			fieldd = field(n);
		}
		else
		{
			output(fieldd);
			return (0);
		}
	}
	return (1);
}
