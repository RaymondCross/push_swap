/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:44:04 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:49:15 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int		is_sorted_ps(t_stack *list)
{
	t_stack	*tmp;

	if (list->prev == list)
		return (1);
	tmp = list->prev;
	while (list != tmp)
	{
		if (list->data > list->next->data)
			return (0);
		else
			list = list->next;
	}
	list = tmp;
	return (1);
}

static void		ft_error_ps(t_ps *ps)
{
	ERROR;
	free_everything_ps(ps);
	exit(0);
}

/*
**	first we read argv, check for errors, then get our initial stack
**	then we run the sorting algorithm and print the moves to STDOUT
*/

int				main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (0);
	argc == 2 ? check_valid_ps0(argc, argv) : check_valid_ps(argc, argv);
	ps = malloc(sizeof(t_ps));
	if (!(get_stack_ps(argc, argv, ps)))
		ft_error_ps(ps);
	ps->max = INTMIN;
	ps->min = INTMAX;
	if (ps->llen > 1 && !is_sorted_ps(ps->a))
	{
		if (ps->llen <= 3)
			sort3(ps);
		else if (ps->llen <= 5)
			sort5(ps);
		else
			cheeseburger_special(ps);
	}
	free_everything_ps(ps);
	return (0);
}
