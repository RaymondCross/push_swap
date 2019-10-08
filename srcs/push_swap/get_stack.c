/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:43:58 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:43:58 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
**	first we go through argv and check that the current number in argv is valid
**	then we add the current number to a new node in the list and doubly link it
**	at the end we link the first and last nodes to make it circular
*/

static int		read_args_ps(int argc, char **argv, t_ps *ps)
{
	int		i;
	t_stack	*tmp;

	tmp = ps->a;
	i = 0;
	while (++i < argc)
	{
		ps->a->next = i < argc - 1 ? listnew_ps() : tmp;
		ps->a->data = ft_atoi(argv[i]);
		ps->a->next->prev = ps->a;
		ps->a = i < argc - 1 ? ps->a->next : ps->a;
	}
	ps->llen = i - 1;
	tmp->prev = ps->a;
	return (1);
}

static int		read_args_ps0(int argc, char **argv, t_ps *ps)
{
	char	**tab;
	char	*str;
	int		l;

	(void)argc;
	l = 0;
	str = ft_strjoin("a ", argv[1]);
	tab = ft_strsplit(str, ' ');
	while (tab[l])
		l++;
	if (!(read_args_ps(l, tab, ps)))
		return (0);
	tab ? ft_free_2d(tab) : 0;
	str ? free(str) : 0;
	return (1);
}

int				get_stack_ps(int argc, char **argv, t_ps *ps)
{
	int		i;
	t_stack	*tmp;

	if (argc < 2)
		return (0);
	ps->a = listnew_ps();
	ps->b = NULL;
	tmp = ps->a;
	i = 0;
	if (argc == 2)
	{
		if (!(read_args_ps0(argc, argv, ps)))
			return (0);
	}
	else if (!(read_args_ps(argc, argv, ps)))
		return (0);
	ps->a = tmp;
	return (1);
}
