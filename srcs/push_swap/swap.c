/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:44:13 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:44:13 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		swap_ps(t_stack *stack)
{
	int		tmp;

	if (stack == NULL || stack->prev == stack || stack->next == stack)
		return (1);
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	return (1);
}

int		ss_ps(t_ps *ps)
{
	swap_ps(ps->a);
	swap_ps(ps->b);
	return (1);
}
