/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_ttrmns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:29:03 by ychufist          #+#    #+#             */
/*   Updated: 2018/07/02 12:29:51 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		znachenie(t_ttlist *ttrmnss, int k, t_point indx, t_point *orgn)
{
	if (k == 0)
	{
		orgn->x[0] = indx.x[0];
		orgn->y[0] = indx.y[0];
		ttrmnss->point.y[k] = 0;
		ttrmnss->point.x[k] = 0;
	}
	else if (k >= 1)
	{
		ttrmnss->point.y[k] = indx.y[0] - orgn->y[0];
		ttrmnss->point.x[k] = indx.x[0] - orgn->x[0];
	}
}

void		ym(t_point *kq, int amount_ttrmnss, t_ttlist **ttrmnss)
{
	if (kq->y[0] == 4 && amount_ttrmnss - 1 != kq->x[0] - 'A')
	{
		kq->x[0]++;
		(*ttrmnss)->next = ft_ttlist_new((char)kq->x[0]);
		(*ttrmnss) = (*ttrmnss)->next;
		kq->y[0] = 0;
	}
}

t_ttlist	*cut_ttrmns(char **ttrmns_split_field, int amount_ttrmnss)
{
	t_point		indx;
	t_point		kq;
	t_point		orgn;
	t_ttlist	*head_ttr;
	t_ttlist	*ttrmnss;

	indx.x[0] = -1;
	kq.x[0] = 65;
	kq.y[0] = 0;
	ttrmnss = ft_ttlist_new(kq.x[0]);
	head_ttr = ttrmnss;
	orgn.x[0] = 0;
	while (ttrmns_split_field[++indx.x[0]] != '\0')
	{
		indx.y[0] = -1;
		while (ttrmns_split_field[indx.x[0]][++indx.y[0]] != '\0')
		{
			if (ttrmns_split_field[indx.x[0]][indx.y[0]] == '#')
				znachenie(ttrmnss, kq.y[0]++, indx, &orgn);
			ym(&kq, amount_ttrmnss, &ttrmnss);
		}
	}
	return (head_ttr);
}
