/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 17:44:00 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_split_chunk(t_chunk *chunk_to_sort, \
			t_list_program *list_program);


void	merge_back_and_sort(t_chunk *chunk_to_sort, \
			t_split_chunks *split_chunks, t_list_program *list_program)
{
	t_list_dls	**stack_a;
	t_list_dls	**stack_b;
	int			i;
	t_chunk		chunk_to_sort_new;

	printer_dbg_split(MERGE_AS, split_chunks, list_program);
	selection_sort_chunk(list_program);
	stack_a = list_program->stack_a;
	stack_b = list_program->stack_b;
//	merge_back_no_sort(&split_chunks->mid, split_chunks, list_program);
	i = split_chunks->mid.size;
	while (i-- > 0)
		push('a', list_program);
	chunk_to_sort_new.min = split_chunks->mid.min;
	chunk_to_sort_new.max = split_chunks->mid.max;
	chunk_to_sort_new.size = split_chunks->mid.size;
	chunk_to_sort_new.position = TOP_A;
//	split_chunks->mid.position = TOP_A;
	if (split_chunks->mid.size > 3)
//		recursive_split_chunk(&split_chunks->mid, list_program);
		recursive_split_chunk(&chunk_to_sort_new, list_program);
	selection_sort_chunk(list_program);
//	merge_back_no_sort(&split_chunks->min, split_chunks, list_program);
	i = split_chunks->min.size - 0;
	while (i-- > 0 && *stack_b)
	{
		rotate("rr", 'b', list_program);
		push('a', list_program);
	}
	chunk_to_sort_new.min = split_chunks->min.min;
	chunk_to_sort_new.max = split_chunks->min.max;
	chunk_to_sort_new.size = split_chunks->min.size;
//	chunk_to_sort_new.position = TOP_A;
	if (split_chunks->min.size > 3)
//		recursive_split_chunk(&split_chunks->min, list_program);
		recursive_split_chunk(&chunk_to_sort_new, list_program);
	selection_sort_chunk(list_program);
}

// Function to split a chunk into three parts
void	split_chunk( t_chunk *chunk_to_sort, t_split_chunks *split_chunks, \
			t_list_program *list_program)
{
	int	value;
	int	i;
	int	pivot1;
	int	pivot2;

	is_sorted_linked_list_push(list_program);
	pivot_calculation(chunk_to_sort, split_chunks);
	printer_dbg_split(SPLIT, split_chunks, list_program);
	i = chunk_to_sort->min - 1;
	pivot1 = split_chunks->pivot1;
	pivot2 = split_chunks->pivot2;
	while (i <= chunk_to_sort->max)
	{
		value = (*list_program->stack_a)->index;
		if (value > pivot2)
			rotate("r", 'a', list_program);
		else if (value > pivot1)
			push('b', list_program);
		else
		{
//			push_and_rotate('b','r', list_program);
			push('b', list_program);
			rotate("r", 'b', list_program);
		}
		i++;
	}
}

// Recursive function to sort a chunk
void	recursive_split_chunk(t_chunk *chunk_to_sort, \
			t_list_program *list_program)
{
	t_split_chunks	split_chunks;

	pivot_calculation(chunk_to_sort, &split_chunks);
	if (chunk_to_sort->size <= 3)
	{
		merge_back_and_sort(chunk_to_sort, &split_chunks, list_program);
		return ;
	}
	split_chunk(chunk_to_sort, &split_chunks, list_program);
	recursive_split_chunk(&split_chunks.max, list_program);
	recursive_split_chunk(&split_chunks.mid, list_program);
	recursive_split_chunk(&split_chunks.min, list_program);
}

void	quick_sort_pushswap(t_list_program *list_program)
{
	t_chunk	chunk_to_sort;

	ft_printers(QUICK, list_program);
	chunk_to_sort = (t_chunk){0, \
								list_program->stack_a_size - 1, \
								list_program->stack_a_size, \
								TOP_A};
	recursive_split_chunk(&chunk_to_sort, list_program);
}

/* void	merge_back_no_sort(t_chunk *chunk_to_sort, \
			t_split_chunks *split_chunks, t_list_program *list_program)
{
	int			i;

	printer_dbg_split(MERGE_NS, split_chunks, list_program);
	i = chunk_to_sort->size;
	while (i-- > 0)
	{
		if(split_chunks->position_from == TOP_B)
			push('a', list_program);
		else if(split_chunks->position_from == BOTTOM_B)
		{
			rotate("r", 'b', list_program);
			push('a', list_program);
		}
	}
} */


/* 
static void	recursive_split_chunk(t_chunk *chunk_to_sort, \
				t_list_program *list_program)
{
	t_split_chunks	split_chunks;

	if (chunk_to_sort->size <= 0)
	{
		selection_sort_chunk(list_program);
		return ;
	}
	split_chunk(chunk_to_sort, &split_chunks, list_program);
	merge_back_and_sort(chunk_to_sort, &split_chunks, list_program);

	split_chunk(&split_chunks.max, &split_chunks, list_program);
	merge_back_max(chunk_to_sort, &split_chunks, list_program);
 	recursive_split_chunk(&split_chunks.mid, list_program);
	recursive_split_chunk(&split_chunks.max, list_program);
 	merge_back_and_sort(&split_chunks.min, &split_chunks, list_program);
	merge_back_and_sort(&split_chunks.mid, &split_chunks, list_program);
	merge_back_and_sort(&split_chunks.max, &split_chunks, list_program);
} */