/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:02 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:46:35 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

static int		is_valid(char *str, int p)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
			return (0);
	if (p < INTMIN || p > INTMAX)
		return (0);
	return (1);
}

/*
**	first we check that the input is a valid 32 bit integer
**	then we simply check for duplicate inputs
*/

void			check_valid(int argc, char **argv)
{
	int		i;
	int		j;
	int		p;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		p = ft_atoi(argv[i]);
		if (!is_valid(argv[i], p))
		{
			ERROR;
			exit(0);
		}
		j = i;
		while (++j < argc)
		{
			if (!strcmp(argv[i], argv[j]))
			{
				ERROR;
				exit(0);
			}
		}
	}
}

void			check_valid0(int argc, char **argv)
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
	check_valid(l, tab);
	tab ? ft_free_2d(tab) : 0;
	str ? free(str) : 0;
}
