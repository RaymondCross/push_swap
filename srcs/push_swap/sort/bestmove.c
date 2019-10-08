/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:51 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:42:54 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	bestmovea(t_ps *ps, t_stack *stack, int nbr)
{
	int		up;
	int		down;
	t_stack *tmp;

	down = 0;
	up = 0;
	tmp = stack;
	while (tmp->data != nbr)
	{
		down++;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp->data != nbr && up <= down)
	{
		up++;
		tmp = tmp->prev;
	}
	ps->au = (down <= up) ? 0 : 1;
	ps->aa = (down <= up) ? down : up;
}

int		bestmoveans(t_ps *ps, int up, int down)
{
	int		ans;

	if (down <= up)
	{
		ps->bu = 0;
		ps->bb = down;
	}
	else
	{
		ps->bu = 1;
		ps->bb = up;
	}
	if (ps->au == ps->bu)
		ans = (ps->aa >= ps->bb) ? ps->aa : ps->bb;
	else
		ans = ps->aa + ps->bb;
	return (ans);
}

void	bestmoveb(t_ps *ps, int nbr, int *up, int *down)
{
	t_stack	*tmp;

	tmp = ps->b;
	while (!(tmp->data < nbr && tmp->prev->data > nbr))
	{
		(*down)++;
		tmp = tmp->next;
	}
	tmp = ps->b;
	while (!(tmp->data < nbr && tmp->prev->data > nbr))
	{
		(*up)++;
		tmp = tmp->prev;
	}
}

int		bestmove(t_ps *ps, int nbr)
{
	int		up;
	int		down;
	t_stack	*tmp;

	bestmovea(ps, ps->a, nbr);
	down = 0;
	up = 0;
	tmp = ps->b;
	if (nbr > ps->max || nbr < ps->min)
	{
		while (tmp->data != ps->max)
		{
			down++;
			tmp = tmp->next;
		}
		tmp = ps->b;
		while (tmp->data != ps->max && up <= down)
		{
			up++;
			tmp = tmp->prev;
		}
	}
	else
		bestmoveb(ps, nbr, &up, &down);
	return (bestmoveans(ps, up, down));
}
