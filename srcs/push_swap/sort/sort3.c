/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:43:08 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:43:08 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sort3_options1(t_ps *ps, t_stack *s)
{
	if (s->data > s->prev->data)
	{
		if (s->next->data > s->prev->data)
		{
			swap_ps(ps->a);
			SA;
			revrotate_ps(&ps->a);
			RRA;
		}
		else
		{
			rotate_ps(&ps->a);
			RA;
		}
	}
	else
	{
		swap_ps(ps->a);
		SA;
	}
}

void	sort3_options2(t_ps *ps, t_stack *s)
{
	if (s->data > s->prev->data)
	{
		revrotate_ps(&ps->a);
		RRA;
	}
	else
	{
		swap_ps(ps->a);
		SA;
		rotate_ps(&ps->a);
		RA;
	}
}

void	sort3(t_ps *ps)
{
	t_stack	*s;

	s = ps->a;
	if (s->data < s->next->data && s->prev->data > s->next->data)
		return ;
	if (s->data > s->next->data)
		sort3_options1(ps, s);
	else
		sort3_options2(ps, s);
}
