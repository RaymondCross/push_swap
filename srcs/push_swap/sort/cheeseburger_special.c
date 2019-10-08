/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheeseburger_special.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:58 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:42:59 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	no_pickles_extra_sauce(t_ps *ps)
{
	sort3(ps);
	ps->max = ps->b->data;
	while (ps->b)
	{
		if (ps->a->prev->data != ps->max
			&& ps->a->prev->data > ps->b->data)
		{
			revrotate_ps(&ps->a);
			RRA;
			ps->max = (ps->a->data > ps->max) ? ps->a->data : ps->max;
		}
		else
		{
			push_ps(&ps->b, &ps->a);
			PA;
		}
	}
	while (ps->a->data > ps->a->prev->data)
	{
		revrotate_ps(&ps->a);
		RRA;
	}
}

void	pushfirsttwo(t_ps *ps)
{
	push_ps(&ps->a, &ps->b);
	PB;
	ps->min = ps->b->data;
	push_ps(&ps->a, &ps->b);
	PB;
	if (ps->min > ps->b->data)
	{
		ps->max = ps->min;
		ps->min = ps->b->data;
	}
	else
		ps->max = ps->b->data;
}

void	cheeseburger_special(t_ps *ps)
{
	pushfirsttwo(ps);
	while (ps->a->prev->data != ps->a->next->next->data)
	{
		ps->least = getleast(ps);
		bestmove(ps, ps->least);
		sortleast(ps);
	}
	bestmovea(ps, ps->b, ps->max);
	while (ps->b->data != ps->max)
	{
		if (ps->au == 0)
		{
			rotate_ps(&ps->b);
			RB;
		}
		else
		{
			revrotate_ps(&ps->b);
			RRB;
		}
	}
	no_pickles_extra_sauce(ps);
}
