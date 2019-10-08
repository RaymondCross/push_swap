/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:31 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:42:31 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return (1);
	else
		*stack = (*stack)->next;
	return (1);
}

int		rr(t_check *check)
{
	rotate(&check->a);
	rotate(&check->b);
	return (1);
}

int		revrotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->prev == *stack)
		return (1);
	else
		*stack = (*stack)->prev;
	return (1);
}

int		rrr(t_check *check)
{
	revrotate(&check->a);
	revrotate(&check->b);
	return (1);
}
