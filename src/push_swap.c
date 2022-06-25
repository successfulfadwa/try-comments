/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faljaoui <faljaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:30:52 by igvaz-fe          #+#    #+#             */
/*   Updated: 2022/06/21 05:26:02 by faljaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!validate(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stack_a = create_stack(argc - 1, 'a');
	stack_b = create_stack(argc - 1, 'b');
	init_stack(stack_a, argv);
	sort(stack_a, stack_b);
	free(stack_a->stack);
	free(stack_a);
	free(stack_b->stack);
	free(stack_b);
	return (0);
}
