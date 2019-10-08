/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:44:10 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:44:10 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		rotate_ps(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return (1);
	else
		*stack = (*stack)->next;
	return (1);
}

int		rr_ps(t_ps *ps)
{
	rotate_ps(&ps->a);
	rotate_ps(&ps->b);
	return (1);
}

int		revrotate_ps(t_stack **stack)
{
	if (*stack == NULL || (*stack)->prev == *stack)
		return (1);
	else
		*stack = (*stack)->prev;
	return (1);
}

int		rrr_ps(t_ps *ps)
{
	revrotate_ps(&ps->a);
	revrotate_ps(&ps->b);
	return (1);
}
