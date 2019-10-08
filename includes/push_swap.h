/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 02:42:41 by rcross            #+#    #+#             */
/*   Updated: 2019/09/30 02:55:26 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define ERROR	ft_putendl_fd("Error", 2);
# define SA	ft_putendl_fd("sa", 1);
# define SB	ft_putendl_fd("sb", 1);
# define SS	ft_putendl_fd("ss", 1);
# define PA	ft_putendl_fd("pa", 1);
# define PB	ft_putendl_fd("pb", 1);
# define RA	ft_putendl_fd("ra", 1);
# define RB	ft_putendl_fd("rb", 1);
# define RR	ft_putendl_fd("rr", 1);
# define RRA	ft_putendl_fd("rra", 1);
# define RRB	ft_putendl_fd("rrb", 1);
# define RRR	ft_putendl_fd("rrr", 1);
# define INTMIN	-217478368
# define INTMAX	217478367

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_ps
{
	t_stack			*a;
	t_stack			*b;
	int				llen;
	int				max;
	int				min;
	int				least;
	int				leastnbr;
	int				aa;
	int				au;
	int				bb;
	int				bu;
}					t_ps;

int					get_stack_ps(int argc, char **argv, t_ps *ps);
t_stack				*listnew_ps(void);
void				deletelist_ps(t_stack *stack);
int					push_ps(t_stack **stack1, t_stack **stack2);
int					rrr_ps(t_ps *ps);
int					revrotate_ps(t_stack **stack);
int					rr_ps(t_ps *ps);
int					rotate_ps(t_stack **stack);
int					ss_ps(t_ps *ps);
int					swap_ps(t_stack *stack);
void				free_everything_ps(t_ps *ps);
void				rotuntil(t_stack **stack, int end);
void				revrotuntil(t_stack **stack, int end);
void				findmax(t_ps *ps, int up, int down, t_stack *tmp);
void				findmin(t_ps *ps, int up, int down, t_stack *tmp);
void				sort5(t_ps *ps);
void				sort4(t_ps *ps);
void				sort3(t_ps *ps);
void				check_valid_ps0(int argc, char **argv);
void				check_valid_ps(int argc, char **argv);
int					getleast(t_ps *ps);
void				bestmovea(t_ps *ps, t_stack *stack, int nbr);
int					bestmove(t_ps *ps, int nbr);
void				sortleast(t_ps *ps);
void				cheeseburger_special(t_ps *ps);

#endif
