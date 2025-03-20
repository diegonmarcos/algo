/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_0_input_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:30:32 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/20 19:29:37 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

//##############################################################################
// HEADER
//##############################################################################

// LIBRARIES
#include "push_swap.h"

//##############################################################################
// ERROR HANDLING
//##############################################################################
/**
 * @brief Error handling and egde cases
 *
 * @details
 * @par Details:
 * This module provides functions to handle errors and edge cases in the input
 * for the push_swap program. It includes checks for the following:
 * 
 * - Duplicate values in the input
 * - Non-integer values in the input
 * - Insufficient number of arguments
 * - Empty or null arguments
 * - Already sorted input
 * - Single element input
 * - Sorted linked list in stack_a
 * - Non-empty stack_b
 * 
 * @par Functions:
 * - error_handling_input_1: for duplicates, non-integers, and sorted input.
 * - error_handling_input_0: for the number of arguments and empty arguments.
 * - is_sorted_linked_list_push: Checks if stack_a is sorted,
 * 	if stack_b is empty, and handles memory release for termination.
 */
/*
** Function to check for the number of arguments
*/
void	error_handling_input_0(int argc, char **argv)
{
	if (argc < 2)
		halt_exit_(0);
	if (argv[1] == NULL || argv[1][0] == '\0')
		halt_exit_(0);
}

void	error_handling_input_1(t_list_program *list_program)
{
	char	**argv_1;
	int		size;

	argv_1 = list_program->stack_a_array;
	size = list_program->stack_a_size;
	if (ft_strcmp_duplicate_inter(argv_1)
		|| !ft_is_array_int(argv_1))
	{
		ft_free_push_swap_halt(list_program);
		halt_exit_(1);
	}
	else if (ft_is_sorted_array_char(&argv_1[1]) || size == 1)
	{
		ft_free_push_swap_halt(list_program);
		halt_exit_(0);
	}
	return ;
}

void	is_sorted_linked_list_push(t_list_program *list_program)
{
	if (*list_program->stack_b)
		return ;
	if (is_sorted_linked_list(*list_program->stack_a))
	{
		print_results(list_program);
		ft_free_push_swap_end(list_program);
		exit (0);
	}
}
