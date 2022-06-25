/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:31:02 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/22 02:02:27 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
t_stack	*create_stack(int capacity, char c)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	stack->top = -1;
	stack->stack = malloc(capacity * sizeof(int));
	stack->c = c;
	return (stack);
}

void	init_stack(t_stack *stack, char **argv)
{
	int	i;
	int	j;
	int r;

     	i = 1;
	j = stack->capacity - 1;
	while (j >= 0)
	{
		stack->stack[j] = ft_atoi(argv[i]);
		stack->top++;
		r=stack->top;
		//printf("%d",r);
		//how many arguments on it;
		i++;
		j--;
	}
}
