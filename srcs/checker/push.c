/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:28 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:42:29 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/*
**	check if stack2 is empty
**	else check if stack2 has only 1 element
**	else stack2 has more than 1 element
*/

static void	push_commit(t_stack **stack2, t_stack **new)
{
	if (*stack2 == NULL)
	{
		(*new)->next = *new;
		(*new)->prev = *new;
		*stack2 = *new;
	}
	else if ((*stack2)->next == *stack2)
	{
		(*stack2)->next = *new;
		(*stack2)->prev = *new;
		(*new)->next = *stack2;
		(*new)->prev = *stack2;
		*stack2 = *new;
	}
	else
	{
		(*stack2)->prev->next = *new;
		(*new)->prev = (*stack2)->prev;
		(*stack2)->prev = *new;
		(*new)->next = *stack2;
		*stack2 = *new;
	}
}

/*
**	check if stack1 is empty
**	pop off top of stack1
**	check if stack1 has only 1 element
**	else stack1 has more than 1 element
*/

int			push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*new;

	if (*stack1 == NULL)
		return (1);
	new = *stack1;
	if ((*stack1)->next == *stack1)
	{
		push_commit(stack2, &new);
		*stack1 = NULL;
	}
	else
	{
		(*stack1)->prev->next = new->next;
		(*stack1)->next->prev = new->prev;
		*stack1 = (*stack1)->next;
		push_commit(stack2, &new);
	}
	return (1);
}
