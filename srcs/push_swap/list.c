/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:44:01 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:44:02 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack		*listnew_ps(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = -69;
	new->next = new;
	new->prev = new;
	return (new);
}

void		deletelist_ps(t_stack *stack)
{
	t_stack	*tmp;

	if (stack->next == stack)
	{
		free(stack);
		return ;
	}
	tmp = stack->next;
	stack->prev->next = NULL;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void		free_everything_ps(t_ps *ps)
{
	ps->a ? deletelist_ps(ps->a) : 0;
	ps->b ? deletelist_ps(ps->b) : 0;
	free(ps);
}
