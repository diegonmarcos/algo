/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0_sort_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:30:48 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/25 17:53:12 by dinepomu         ###   ########.fr       */
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
// SORTING ALGORITHMS
//##############################################################################
/**
 * @file 3_0_sort_stack.c
 * @brief Implements the main sorting logic for the push_swap program.
 *
 * @details
 * @par Details:
 * This module selects and applies the appropriate sorting algorithm based on
 * the size of stack A:
 * 
 * - Selection Sort of sorting algorithm for below 50 elements
 * - Radix for 50 to 65 elements
 * - Quick Sort for 65 to 75 elements
 * - Gear Sort for 75 to 100 elements
 * - Gear Sort for 100 to 500 elements
 * - Optimization of moves after sorting:
 * 		- Replace with double rotate or double reverse rotate when possible
 * 		- Remove unnecessary moves(canceling moves)
 * 
 * @par Functions:
 * - void sort_stack(t_list_program *list_program):
 *   Main function to sort the stack using the appropriate algorithm.
 * - void selection_sort(t_list_program *list_program):
 *   Sorts the stack using the selection sort algorithm.
 * - void radix_sort_pushswap(t_list_program *list_program):
 *   Sorts the stack using the radix sort algorithm.
 * - void quick_sort_pushswap(t_list_program *list_program):
 *   Sorts the stack using the quick sort algorithm.
 * - void gear_sort_pushswap(t_list_program *list_program):
 *   Sorts the stack using the gear sort algorithm.
 * - void sort_stack_dbg(t_list_program *list_program):
 *   Debug function for sorting the stack.
 * - void moves_optimizations(t_list_program *list_program):
 *   Optimizes the moves after sorting.
 * 	 quick_sort_pushswap(list_program);
 */
void	sort_stack(t_list_program	*list_program)
{
	ft_printers(START, list_program);
	if (!ALGO)
	{
		if (list_program->stack_a_size <= 50)
			selection_sort(list_program);
		else if (list_program->stack_a_size < 65)
			radix_sort_pushswap(list_program);
		else if (list_program->stack_a_size <= 75)
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
