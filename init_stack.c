/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:03:58 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 14:31:48 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_the_order2(t_stack **stack, int *array, int size)
{
	int		i;
	int		j;
	int		order;
	t_stack	*temp;

	i = 0;
	j = 0;
	order = 0;
	temp = *stack;
	while (i < size)
	{
		j = 0;
		order = 0;
		while (j < size)
		{
			if (array[i] > array[j])
				order++;
			j++;
		}
		(*stack)->order = order;
		*stack = (*stack)->next;
		i++;
	}
	*stack = temp;
}

void	set_the_order(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		size;
	int		*numbers;

	temp = (*stack);
	size = list_count(*stack);
	i = 0;
	numbers = malloc(sizeof(int) * size + 1);
	while (temp)
	{
		numbers[i] = temp->data;
		temp = temp->next;
		i++;
	}
	set_the_order2(stack, numbers, size);
	free (numbers);
}

void	fill_stack(char **av, t_stack **stack)
{
	int		i;
	t_stack	*new;

	i = 1;
	(*stack) = ft_new_list(ft_atoi(av[i++]));
	while (av[i])
	{
		new = ft_new_list(ft_atoi(av[i]));
		list_add_back(stack, new);
		i++;
	}
	set_the_order(stack);
}
