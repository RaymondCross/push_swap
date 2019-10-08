/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:43:05 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:43:05 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rotuntil(t_stack **s, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		rotate_ps(s);
		RA;
		i++;
	}
}

void	revrotuntil(t_stack **s, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		revrotate_ps(s);
		RRA;
		i++;
	}
}

void	findmin(t_ps *ps, int up, int down, t_stack *tmp)
{
	int		u;
	int		d;

	u = INTMAX;
	d = INTMAX;
	while (++up < 5)
	{
		if (tmp->data < ps->min)
		{
			u = up;
			ps->min = tmp->data;
		}
		tmp = tmp->prev;
	}
	while (++down < 5)
	{
		if (tmp->data < ps->min)
		{
			d = down;
			ps->min = tmp->data;
		}
		tmp = tmp->next;
	}
	u <= d ? revrotuntil(&ps->a, u) : rotuntil(&ps->a, d);
}

void	findmax(t_ps *ps, int up, int down, t_stack *tmp)
{
	int		u;
	int		d;

	u = INTMAX;
	d = INTMAX;
	while (++up < 5)
	{
		if (tmp->data > ps->max)
		{
			u = up;
			ps->max = tmp->data;
		}
		tmp = tmp->prev;
	}
	while (++down < 5)
	{
		if (tmp->data > ps->max)
		{
			u = up;
			ps->max = tmp->data;
		}
		tmp = tmp->next;
	}
	u <= d ? revrotuntil(&ps->a, u) : rotuntil(&ps->a, d);
}
