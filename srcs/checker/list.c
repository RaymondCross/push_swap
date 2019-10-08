/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:19 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:42:20 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

t_stack		*listnew(void)
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

void		deletelist(t_stack *stack)
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

void		free_everything(t_check *check)
{
	check->a ? deletelist(check->a) : 0;
	check->b ? deletelist(check->b) : 0;
	free(check);
}
