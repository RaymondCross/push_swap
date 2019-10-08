/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getleast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:43:02 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:43:03 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	normisbitch(t_ps *ps, t_stack **tmp, int *tempm, int *leastm)
{
	if (*tempm == *leastm)
	{
		if ((*tmp)->data < ps->min)
			ps->leastnbr = (*tmp)->data;
		else if ((*tmp)->data > ps->max)
			ps->leastnbr = (*tmp)->data;
		else if ((*tmp)->data > ps->leastnbr)
			ps->leastnbr = (*tmp)->data;
	}
	else
	{
		*leastm = *tempm;
		ps->leastnbr = (*tmp)->data;
	}
}

int		getleast(t_ps *ps)
{
	t_stack	*tmp;
	int		leastmoves;
	int		tmpmoves;

	tmp = ps->a;
	tmp->prev->next = NULL;
	leastmoves = bestmove(ps, tmp->prev->data);
	ps->leastnbr = ps->a->prev->data;
	while (tmp)
	{
		tmpmoves = bestmove(ps, tmp->data);
		if (tmpmoves <= leastmoves)
			normisbitch(ps, &tmp, &tmpmoves, &leastmoves);
		tmp = tmp->next;
	}
	ps->a->prev->next = ps->a;
	return (ps->leastnbr);
}
