/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:43 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:55:32 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ERROR	ft_putendl_fd("Error", 2);
# define KO	ft_putendl_fd("KO", 2);
# define OK	ft_putendl_fd("OK", 2);
# define INTMIN	-217478368
# define INTMAX	217478367

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_check
{
	t_stack			*a;
	t_stack			*b;
	int				llen;
}					t_check;

int					get_stack(int argc, char **argv, t_check *check);
int					get_moves(t_check *check);
int					push(t_stack **stack1, t_stack **stack2);
int					swap(t_stack *stack);
int					ss(t_check *check);
int					rotate(t_stack **stack);
int					rr(t_check *check);
int					revrotate(t_stack **stack);
int					rrr(t_check *check);
t_stack				*listnew(void);
void				deletelist(t_stack *stack);
void				free_everything(t_check *check);
int					get_stack(int argc, char **argv, t_check *check);
void				check_valid0(int argc, char **argv);
void				check_valid(int argc, char **argv);

#endif
