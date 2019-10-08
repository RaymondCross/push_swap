/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:08 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:42:10 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

/*
**	first we go through argv and check that the current number in argv is valid
**	then we add the current number to a new node in the list and doubly link it
**	at the end we link the first and last nodes to make it circular
*/

static int		read_args(int argc, char **argv, t_check *check)
{
	int		i;
	t_stack	*tmp;

	tmp = check->a;
	i = 0;
	while (++i < argc)
	{
		check->a->next = i < argc - 1 ? listnew() : tmp;
		check->a->data = ft_atoi(argv[i]);
		check->a->next->prev = check->a;
		check->a = i < argc - 1 ? check->a->next : check->a;
	}
	check->llen = i - 1;
	tmp->prev = check->a;
	return (1);
}

static int		read_args0(int argc, char **argv, t_check *check)
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
	if (!(read_args(l, tab, check)))
		return (0);
	tab ? ft_free_2d(tab) : 0;
	str ? free(str) : 0;
	return (1);
}

int				get_stack(int argc, char **argv, t_check *check)
{
	int		i;
	t_stack	*tmp;

	if (argc < 2)
		return (0);
	check->a = listnew();
	check->b = NULL;
	tmp = check->a;
	i = 0;
	if (argc == 2)
	{
		if (!(read_args0(argc, argv, check)))
			return (0);
	}
	else if (!(read_args(argc, argv, check)))
		return (0);
	check->a = tmp;
	return (1);
}
