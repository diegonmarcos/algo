/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:57:09 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 10:57:56 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/* ***************************************************************** */
/* HEADERS PROGRAM													 */
/* ***************************************************************** */
# include "push_swap_defines.h"
# include "push_swap_data.h"

/* ***************************************************************** */
/* DEPENDENCIES														 */
/* ***************************************************************** */
# include "mylibc.h"

//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
//##################################################################### */
// DATA STRUCTURE / INITIALIZATORS / FREE								*/
//##################################################################### */
void	data_alloc(int argc, char **argv, \
			t_list_program *list_program);
void	ft_free_push_swap(t_list_program *list_program, char **argv,
			t_list_dls *stack_a, int argc);
void	ft_free_push_swap_end(t_list_program *list_program);
void	ft_free_push_swap_halt(t_list_program *list_programm);

//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
//##################################################################### */
// SORTING ALGORITHMS													*/
//##################################################################### */
void	sort_stack(t_list_program *list_program);

/* ***************************************************************** */
/* SELECTION SORT													 */
/* ***************************************************************** */
void	selection_sort(t_list_program *list_program);
void	selection_sort_recursion(int *pushes, t_list_program *list_program);
void	sort_3(t_list_dls **stack_a, t_list_program *list_program);
void	selection_sort_merge_back(int *pushes, t_list_program *list_program);
int		min_node_pos(t_list_program *list_program);

/* ***************************************************************** */
/* RADIX SORT														 */
/* ***************************************************************** */
void	radix_sort_pushswap(t_list_program *list_program);
void	radix_sort_step(int bit, int size, t_list_program *list_program);

/* ***************************************************************** */
/* QUICK SORT														 */
/* ***************************************************************** */
void	quick_sort_pushswap(t_list_program *list_program);
//void	recursive_split_chunk(t_chunk *chunk_to_sort, \
//			t_list_program *list_program);
void	sort_3_chunk(t_list_program *list_program);

/* ***************************************************************** */
/* GEAR SORT														 */
/* ***************************************************************** */
void	gear_sort_pushswap(t_list_program *list_program);
void	sort_gearing(char stack_from, char stack_to, int base_case, \
			t_list_program *list_program);
void	sort_move_lower_cost(char stack_from, t_move_lower_cost *v, \
			t_list_program *list_program);
int		node_pos_locator(int value, t_list_program *list_program, char type, \
		char stack_from);
int		sort_gearing_is_base_case(int base_case, t_list_program *list_program);
int		node_pos_locator_is_in_place(char stack_from, int value, \
		t_node_pos_locator *v);
void	high_up_stack(t_list_program *list_program);
void	low_up_stack(t_list_program *list_program);
int		max_node_finder(t_list_dls **stack, t_list_program *list_program);
void	quick_sort_partial(t_list_program *list_program);

/* ***************************************************************** */
/* SMALL SORT AND UTILS												 */
/* ***************************************************************** */
void	pivot_calculation(t_chunk *chunk_to_sort, t_splits *split_chunks);
void	selection_sort_chunk(t_list_program *list_dls_program);
void	moves_optimizations(t_list_program *list_program);

//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
//######################################################################### */
// STACK MOVES																*/
//######################################################################### */
void	rotate(char *direction, char stack_name, \
					t_list_program *list_program);
void	push(char direction, t_list_program *list_program);
void	swap(char stack_name, t_list_program *list_program);
void	swap_both(t_list_program *t_list_program);
void	rotate_both(char *direction, t_list_program *t_list_program);
void	move_stack_fromto(t_position from, t_position to, t_list_program \
			*list_program);
void	move_stack_fromto_case(char *move_case, t_list_program *list_program);

//  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  //
//######################################################################### */
// UTILS																	*/
//######################################################################### */
void	add_index_numbers(t_list_dls *list);
int		digits_to_bits(int digits);
int		is_sorted_array_int(int *arr, int size);
int		is_sorted_linked_list(t_list_dls *stack);
void	is_sorted_linked_list_push(t_list_program *list_program);
void	print_results(t_list_program *list_program);

//###################################################################### */
// ERROR HANDLING														 */
//###################################################################### */
void	error_handling_input_0(int argc, char **argv);
void	error_handling_input_1(t_list_program *list_program);

//###################################################################### */
// TRACERS																 */
//###################################################################### */
typedef enum e_ft_printers_db
{
	START,
	END,
	MOVEF,
	MOVES,
	SELEC,
	RADIX,
	QUICK,
	GEAR,
	SPLIT,
	MERGE_NS,
	MERGE_AS,
	PRICES
}	t_ft_printers_db;

void	sort_stack_dbg(t_list_program *list_program);
void	ft_printers(t_ft_printers_db s, t_list_program *list_program);
void	ft_printers_gearsort(t_ft_printers_db s, t_move_lower_cost *v, \
					t_list_program *list_program);
void	printer_dbg_split(t_ft_printers_db s, \
					t_splits *split_chunks, t_list_program *list_program);
void	printer_dbg_split1(t_ft_printers_db s, \
					t_chunk1 *split_chunks, t_list_program *list_program);

#endif