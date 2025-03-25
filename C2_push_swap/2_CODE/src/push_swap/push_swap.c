/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:35:06 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/25 18:16:17 by dinepomu         ###   ########.fr       */
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
// BODY
//##############################################################################
/**
 * @brief Implementation of the push_swap project from 42 school.
 *
 * @details
 * @par Details:
 *  - The push_swap project is a sorting algorithm project that involves sorting 
 *  	a two stack of integers using stacks operations. The goal is to sort 
 * 		the stack with the least number of operations possible. The allowed 
 * 		operations are pushing elements between two stacks, rotating or 
 * 		reversing the stacks, and swapping the top elements of the stacks.
 *
 * @par Usage Program: ./push_swap [ARGV]
 * 	- [parm2] @b argv: unsorted array of integers.
 * 	- return: @b return void
 * @code
 * 	make &&\
 * 	ARG="0 9 8 2 3"; ./push_swap $ARG | ./checker_linux $ARG
 * @endcode
 * 
 * @par Usage Make: make [option1] [option2] ...
 * 	- [static analysis]	make linting
 *	- [leaks]			make leaks
 *	- [tester]			make testing_alles
 *	- [visualizer]		make run_visualizer
 *
 *	- [tracers]			make DBG=1 ALGO=[X] re tests_run_[Y] 
 *  - [debug]			make debug-[Z]
 * 	- [verbose]			make VERBOSE=1 re 
 * 
 *  - [X] 				selec, radix, quick, gear
 * 	- [Y]				5, 50, 75, 100, 500
 *  - [Z]				vscode, lldb, gdb
 * 
 * @code
 * 	make DBG=1 ALGO=selec re tests_run_5
 * 	make DBG=1 ALGO=selec re tests_run_50
 * 	make DBG=1 ALGO=radix re tests_run_75
 * 	make DBG=1 ALGO=quick re tests_run_100
 * 	make DBG=0 ALGO=gear re tests_run_500
 * @endcode
 * @code
 * 	make debug-vscode
 * 	make debug-lldb
 * 	make debug-gdb
 * @endcode
 * 
 */
int	main(int argc, char **argv)
{
	t_list_program	*list_program;

	list_program = &(t_list_program){0, NULL, 0, NULL, NULL, 0, NULL, NULL, \
		NULL, 0, 0, NULL, 0};
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
