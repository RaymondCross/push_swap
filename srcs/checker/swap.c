/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:33 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:42:33 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int		swap(t_stack *stack)
{
	int		tmp;

	if (stack == NULL || stack->prev == stack || stack->next == stack)
		return (1);
	tmp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = tmp;
	return (1);
}

int		ss(t_check *check)
{
	swap(check->a);
	swap(check->b);
	return (1);
}
