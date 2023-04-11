/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:04:56 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 14:38:01 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	teste_print(t_stack *a)
{
	t_stack	*tempor;
	
	tempor = a;
	while (tempor)
	{
		printf("%d, ", tempor->data);
		tempor = tempor->next;
	}
	printf("\n");
}*/

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (error_handler(ac, av) == 0)
	{
		exit_print_error("Error\n");
		exit(0);
	}
	fill_stack(av, &stack_a);
	if (in_order(stack_a) == 1)
		exit(0);
	if (ac < 7)
		sorting_small(ac, &stack_a, &stack_b);
	else
		sorting_big(&stack_a, &stack_b);
	list_remove(&stack_a);
	list_remove(&stack_b);
}
