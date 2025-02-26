/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:35:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 12:46:51 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################
// LIBRARIES
#include "push_swap.h"

//##############################################################################
// MAIN																		   #
//##############################################################################
int	main(int argc, char **argv)
{
	t_list_program	*list_program;

	list_program = &(t_list_program){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	error_handling_input_0(argc, argv);
	data_alloc(argc, argv, list_program);
	error_handling_input_1(list_program);
	*list_program->stack_a = \
		array_to_d_linked_list(list_program->stack_a_array);
	add_index_numbers(*list_program->stack_a);
	sort_stack(list_program);
	print_results(list_program);
	ft_free_push_swap_end(list_program);
	return (0);
}
