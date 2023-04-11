/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:05:28 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 15:19:22 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_two(t_stack *stack)
{
	if (in_order(stack) == 0)
		swap(stack, "sa");
}

void	sorting_three(t_stack **stack)
{
	while (in_order((*stack)) == 0)
	{
		if ((*stack)->order == 2)
			rotate(stack, "ra");
		else if ((*stack)->next->order > (*stack)->order)
			rev_rotate(stack, "rra");
		else if ((*stack)->order > (*stack)->next->order)
			swap((*stack), "sa");
	}
}

void	sorting_four(t_stack **stack1, t_stack **stack2)
{
	t_stack	*temp;
	int		count;

	temp = *stack1;
	count = 0;
	while (temp->order != 3)
	{
		temp = temp->next;
		count++;
	}
	while ((*stack1)->order != 3)
	{
		if (count >= 2)
			rev_rotate(stack1, "rra");
		else
			rotate(stack1, "ra");
	}
	push(stack2, stack1, "pb");
	sorting_three(stack1);
	push(stack1, stack2, "pa");
	rotate(stack1, "ra");
}

void	sorting_five(t_stack **stack1, t_stack **stack2)
{
	t_stack	*temp;
	int		count;

	temp = *stack1;
	count = 0;
	while (temp->order != 4)
	{
		temp = temp->next;
		count++;
	}
	while ((*stack1)->order != 4)
	{
		if (count > 2)
			rev_rotate(stack1, "rra");
		else
			rotate(stack1, "ra");
	}
	push(stack2, stack1, "pb");
	sorting_four(stack1, stack2);
	push(stack1, stack2, "pa");
	push(stack1, stack2, "pa");
	rotate(stack1, "ra");
}

void	sorting_small(int ac, t_stack **stack1, t_stack **stack2)
{
	if (ac == 3)
		sorting_two((*stack1));
	else if (ac == 4)
		sorting_three(stack1);
	else if (ac == 5)
		sorting_four(stack1, stack2);
	else if (ac == 6)
		sorting_five(stack1, stack2);
}
