/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:05:02 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 15:05:54 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "utils/ft_printf.h"

typedef struct s_stack
{
	int				data;
	int				order;
	struct s_stack	*next;
}						t_stack;

// string checker
int		string_digit_checker(char *str);
int		is_digit(int c);

// error handling
int		exit_print_error(char *str);
int		check_doubles(char **av);
int		check_overflow(char **av);
int		error_handler(int ac, char **av);

// initialize the stack
void	set_the_order(t_stack **stack);
void	set_the_order2(t_stack **stack, int *array, int size);
void	fill_stack(char **av, t_stack **stack);

// lists
t_stack	*ft_new_list(int num);
void	list_add_back(t_stack **list, t_stack *new);
int		list_count(t_stack *list);
void	list_add_front(t_stack **list, t_stack *new);
void	list_remove(t_stack **list);

// rules
void	swap(t_stack *stack, char *str);
void	push(t_stack **stack1, t_stack **stack2, char *str);
void	rotate(t_stack **stack, char *str);
void	rev_rotate(t_stack **stack, char *str);
int		in_order(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
// sorting a small stack
void	sorting_two(t_stack *stack);
void	sorting_three(t_stack **stack);
void	sorting_four(t_stack **stack1, t_stack **stack2);
void	sorting_five(t_stack **stack1, t_stack **stack2);
void	sorting_small(int ac, t_stack **stack1, t_stack **stack2);

void	sort_chunks(t_stack **stack1, t_stack **stack2, int len, int chunks);
int		find_next_middle(t_stack *stack1, int len, int chunk);
void	sorting_big(t_stack **stack1, t_stack **stack2);
void	put_everything_back(t_stack **stack1, t_stack **stack2);

int		main(int ac, char **av);
//void		teste_print(t_stack *a);
#endif
