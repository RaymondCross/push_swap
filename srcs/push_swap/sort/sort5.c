/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:43:44 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:43:44 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sort5(t_ps *ps)
{
	t_stack	*tmp;

	if (ps->llen == 4 || ps->a->prev == ps->a->next->next->next)
	{
		sort4(ps);
		return ;
	}
	tmp = ps->a;
	findmax(ps, -1, -1, tmp);
	push_ps(&ps->a, &ps->b);
	PB;
	tmp = ps->a;
	findmin(ps, -1, -1, tmp);
	push_ps(&ps->a, &ps->b);
	PB;
	sort3(ps);
	push_ps(&ps->b, &ps->a);
	PA;
	push_ps(&ps->b, &ps->a);
	PA;
	rotate_ps(&ps->a);
	RA;
}
