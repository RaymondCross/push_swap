/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortleast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:43:47 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:43:48 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rotatestacks(t_ps *ps)
{
	if (ps->au == 0)
	{
		rr_ps(ps);
		RR;
	}
	else
	{
		rrr_ps(ps);
		RRR;
	}
}

void	rotatestack(t_stack **stack, int u, int z)
{
	if (u == 0)
	{
		rotate_ps(stack);
		z == 0 ? ft_putendl_fd("ra", 1) : RB;
	}
	else
	{
		revrotate_ps(stack);
		z == 0 ? ft_putendl_fd("rra", 1) : RRB;
	}
}

void	sortleastm(t_ps *ps)
{
	if (ps->au == ps->bu)
	{
		while (ps->a->data != ps->least && ps->b->data != ps->max)
			rotatestacks(ps);
	}
	while (ps->a->data != ps->least)
		rotatestack(&ps->a, ps->au, 0);
	while (ps->b->data != ps->max)
		rotatestack(&ps->b, ps->bu, 1);
	if (ps->least > ps->max)
		ps->max = ps->least;
	else
		ps->min = ps->least;
}

void	sortleaste(t_ps *ps)
{
	if (ps->au == ps->bu)
	{
		while (ps->a->data != ps->least &&
				(ps->b->data > ps->least ||
				ps->b->prev->data < ps->least))
			rotatestacks(ps);
	}
	while (ps->a->data != ps->least)
		rotatestack(&ps->a, ps->au, 0);
	while (ps->b->data > ps->least ||
			ps->b->prev->data < ps->least)
		rotatestack(&ps->b, ps->bu, 1);
}

void	sortleast(t_ps *ps)
{
	if (ps->least > ps->max || ps->least < ps->min)
		sortleastm(ps);
	else
		sortleaste(ps);
	push_ps(&ps->a, &ps->b);
	PB;
}
