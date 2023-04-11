/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_everything_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:04:25 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 15:11:07 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_middle(t_stack **stack, int len, int highest)
{
	int		middle;
	int		count;
	t_stack	*temp;

	count = 0;
	middle = len / 2;
	temp = *stack;
	while (temp->order != highest)
	{
		temp = temp->next;
		count++;
	}
	if (count <= middle)
		return (1);
	else
		return (0);
}

int	find_highest(t_stack **stack)
{
	int		highest;
	t_stack	*temp;

	highest = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->order > highest)
			highest = temp->order;
		temp = temp->next;
	}
	return (highest);
}

void	put_everything_back(t_stack **stack1, t_stack **stack2)
{
	int	highest;
	int	i;

	i = 0;
	highest = find_highest(stack2);
	while (list_count(*stack2) > 0)
	{
		if ((*stack2)->order == highest)
		{
			push(stack1, stack2, "pa");
			highest--;
		}
		else
		{
			if (find_highest_middle(stack2, list_count(*stack2), highest) == 1)
				rotate(stack2, "rb");
			else
				rev_rotate(stack2, "rrb");
		}
	}
	while (i < 4)
	{
		rev_rotate(stack1, "rra");
		i++;
	}
}
