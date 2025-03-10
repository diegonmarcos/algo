/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_3_radixsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:31:23 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 09:38:21 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
//#include "all_inc_inc.h"
#include "push_swap.h"

//##############################################################################
// SORTING ALGORITHMS
//##############################################################################
int	max_node_finder(t_list_dls **stack, t_list_program *list_program);

void	radix_sort_pushswap(t_list_program *list_program)
{
	int	i;
	int	max_node;
	int	max_bits;
	int	size;

	ft_printers(RADIX, list_program);
	size = ft_lstsize(*list_program->stack_a);
	i = 0;
	max_node = max_node_finder(list_program->stack_a, list_program);
	max_bits = digits_to_bits(max_node);
	while (i < max_bits)
	{
		radix_sort_step(i, size, list_program);
		i++;
	}
}

void	radix_sort_step(int bit, int size, t_list_program *list_program)
{
	t_list_dls	**stack_a;
	int			j;
	int			pushes;

	stack_a = list_program->stack_a;
	j = 0;
	pushes = 0;
	while (j++ < size)
	{
		if ((((*stack_a)->index >> bit) & 1) == 1)
			rotate("r", 'a', list_program);
		else
		{
			push('b', list_program);
			pushes++;
		}
	}
	while (pushes-- > 0)
		push('a', list_program);
}
