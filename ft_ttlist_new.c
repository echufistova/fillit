/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttlist_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 17:25:27 by ychufist          #+#    #+#             */
/*   Updated: 2018/06/24 17:25:57 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ttlist	*ft_ttlist_new(char c)
{
	t_ttlist	*ttrmns;

	ttrmns = (t_ttlist*)malloc(sizeof(t_ttlist));
	if (!ttrmns)
		return (NULL);
	ttrmns->c = c;
	ttrmns->next = NULL;
	return (ttrmns);
}
