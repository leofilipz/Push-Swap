/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:05:19 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 15:15:57 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_middle(t_stack *stack1, int len, int chunk)
{
	int		middle;
	int		count;
	t_stack	*temp;

	count = 0;
	middle = len / 2;
	temp = stack1;
	while (!(temp->order >= (len - chunk)))
	{
		temp = temp->next;
		count++;
	}
	if (count <= middle)
		return (1);
	else
		return (0);
}

void	sort_chunks(t_stack **stack1, t_stack **stack2, int len, int chunks)
{
	int	chunk;
	int	initial_len_b;

	initial_len_b = list_count(*stack2);
	chunk = (len / chunks);
	while ((list_count(*stack2) - initial_len_b) <= chunk)
	{
		if ((*stack1)->order >= (len - chunk))
			push(stack2, stack1, "pb");
		else
		{
			if (find_next_middle(*stack1, len, chunk) == 1)
				while (!((*stack1)->order >= (len - chunk)))
					rotate(stack1, "ra");
			else
				while (!((*stack1)->order >= (len - chunk)))
					rev_rotate(stack1, "rra");
		}
	}
}

void	sorting_big(t_stack **stack1, t_stack **stack2)
{
	int	chunks;
	int	len;

	len = list_count(*stack1);
	if (len <= 100)
		chunks = 5;
	else
		chunks = 7;
	while (list_count(*stack1) >= 5)
	{
		sort_chunks(stack1, stack2, len - 1, chunks);
		len = list_count(*stack1);
	}
	sorting_four(stack1, stack2);
	put_everything_back(stack1, stack2);
}
