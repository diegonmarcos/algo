/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0_sort_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:30:48 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/25 12:12:09 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
#include "push_swap.h"

//##############################################################################
// SORTING ALGORITHMS
//##############################################################################

/*
** Function to sort the stack
*/
void	sort_stack(t_list_program	*list_program)
{
	ft_printers(START, list_program);
	if (!ALGO)
	{
		if (list_program->stack_a_size <= 50)
			selection_sort(list_program);
		else if (list_program->stack_a_size < 100)
			radix_sort_pushswap(list_program);
		else if (list_program->stack_a_size <= 100)
			gear_sort_pushswap(list_program);
		else if (list_program->stack_a_size <= 500)
			gear_sort_pushswap(list_program);
		else
			sort_stack_dbg(list_program);
	}
	else
		sort_stack_dbg(list_program);
	moves_optimizations(list_program);
	ft_printers(END, list_program);
	ft_printers(MOVEF, list_program);
}
