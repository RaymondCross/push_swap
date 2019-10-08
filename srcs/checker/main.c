/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:24 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:51:35 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int		is_sorted(t_stack *list)
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

static void		ft_error(t_check *check)
{
	ERROR;
	free_everything(check);
	exit(0);
}

/*
**	first we read argv, check for errors, and then get our initial stack
**	next we read and apply moves given through STDIN
**	finally we check that list a is sorted and list b is empty
*/

int				main(int argc, char **argv)
{
	t_check	*check;

	if (argc < 2)
		return (0);
	argc == 2 ? check_valid0(argc, argv) : check_valid(argc, argv);
	check = malloc(sizeof(t_check));
	if (!(get_stack(argc, argv, check)))
		ft_error(check);
	if (!(get_moves(check)))
		ft_error(check);
	check->llen = argc - 1;
	if (check->b || !(is_sorted(check->a)))
	{
		KO;
		free_everything(check);
		exit(0);
	}
	OK;
	free_everything(check);
	return (0);
}
