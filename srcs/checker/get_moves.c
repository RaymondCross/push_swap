/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:06 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 03:01:03 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static void	display_stacks(t_check *check)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = check->a ? check->a : NULL;
	tmp2 = check->b ? check->b : NULL;
	ft_printf("=============\n");
	while (tmp1)
	{
		ft_printf("%i\n", check->a->data);
		check->a = check->a->next;
		if (check->a == tmp1)
			break ;
	}
	ft_printf("-------\n");
	ft_printf("STACK A\n\n");
	while (tmp2)
	{
		ft_printf("%i\n", check->b->data);
		check->b = check->b->next;
		if (check->b == tmp2)
			break ;
	}
	ft_printf("-------\n");
	ft_printf("STACK B\n");
	ft_printf("=============\n");
}

static int	read_more_inputs(t_check *check, char *buf)
{
	int		x;

	x = 0;
	if (ft_strequ(buf, "ra"))
		x = rotate(&check->a);
	else if (ft_strequ(buf, "rb"))
		x = rotate(&check->b);
	else if (ft_strequ(buf, "rr"))
		x = rr(check);
	else if (ft_strequ(buf, "rra"))
		x = revrotate(&check->a);
	else if (ft_strequ(buf, "rrb"))
		x = revrotate(&check->b);
	else if (ft_strequ(buf, "rrr"))
		x = rrr(check);
	return (x);
}

static int	read_inputs(t_check *check, char *buf)
{
	int		x;

	x = 0;
	if (ft_strequ(buf, "sa"))
		x = swap(check->a);
	else if (ft_strequ(buf, "sb"))
		x = swap(check->b);
	else if (ft_strequ(buf, "ss"))
		x = ss(check);
	else if (ft_strequ(buf, "pa"))
		x = push(&check->b, &check->a);
	else if (ft_strequ(buf, "pb"))
		x = push(&check->a, &check->b);
	if (x == 0)
		x = read_more_inputs(check, buf);
	if (x == 0)
		return (0);
	return (1);
}

int			get_moves(t_check *check)
{
	char	*buf;

	display_stacks(check);
	while (get_next_line(0, &buf) > 0)
	{
		if (!(read_inputs(check, buf)))
		{
			free(buf);
			return (0);
		}
		display_stacks(check);
		free(buf);
	}
	return (1);
}
