/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leborges <leborges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:03:48 by leborges          #+#    #+#             */
/*   Updated: 2023/02/15 14:26:01 by leborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ERROR HANDLING

int	exit_print_error(char *str)
{
	write (1, str, ft_strlen(str));
	return (0);
}

int	check_doubles(char **av)
{
	int		i;
	int		j;
	char	**av2;

	av2 = av;
	j = 2;
	i = 1;
	while (av[i])
	{
		while (av2[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av2[j]))
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_overflow(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 2)
		{
			if (ft_atoi(av[i]) == 0 || ft_atoi(av[i]) == -1)
				return (1);
		}
	i++;
	}
	return (0);
}

int	error_handler(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac <= 2)
	{
		exit(0);
	}
	while (av[i])
	{
		if (string_digit_checker(av[i]) == 0)
			return (0);
		i++;
	}
	if (check_overflow(av) == 1)
		return (0);
	if (check_doubles(av) == 1)
		return (0);
	return (1);
}
