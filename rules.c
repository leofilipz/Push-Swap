/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:04:37 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 15:14:06 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *operation)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	if (operation)
		ft_printf("%s\n", operation);
}

void	push(t_stack **stack1, t_stack **stack2, char *operation)
{
	t_stack	*temp;

	if (*stack2 == NULL)
		return ;
	temp = *stack2;
	*stack2 = temp->next;
	temp->next = NULL;
	list_add_front(stack1, temp);
	if (operation)
		ft_printf("%s\n", operation);
}

void	rotate(t_stack **stack, char *operation)
{
	t_stack	*new;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	new = *stack;
	*stack = new->next;
	new->next = NULL;
	list_add_back(stack, new);
	if (operation)
		ft_printf("%s\n", operation);
}

void	rev_rotate(t_stack **stack, char *operation)
{
	t_stack	*temp;

	temp = (*stack);
	while (temp->next->next)
	{
		temp = temp->next;
	}
	list_add_front(stack, temp->next);
	temp->next = NULL;
	if (operation)
		ft_printf("%s\n", operation);
}

int	in_order(t_stack *stack)
{
	while (stack->next && (stack->data < stack->next->data))
		stack = stack->next;
	if (stack->next == NULL)
		return (1);
	else
		return (0);
}
