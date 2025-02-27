/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_quicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/27 23:15:33 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_calculation(t_chunk *chunk_to_sort, t_split_chunks *split_chunks)
{
	int	delta;

	delta = chunk_to_sort->size - 1;
	split_chunks->min_number = chunk_to_sort->min;
	split_chunks->pivot1 = chunk_to_sort->min + delta / 3;
	split_chunks->pivot2 = chunk_to_sort->min + 2 * delta / 3;
	split_chunks->max_number = chunk_to_sort->max;
	split_chunks->position_from = chunk_to_sort->position;
	split_chunks->size_total = chunk_to_sort->size;

	split_chunks->min.position = BOTTOM_B;
	split_chunks->min.min = chunk_to_sort->min;
	split_chunks->min.max = split_chunks->pivot1;
	split_chunks->min.size = split_chunks->pivot1 - chunk_to_sort->min + 1;

	split_chunks->mid.position = TOP_B;
	split_chunks->mid.min = split_chunks->pivot1 + 1;
	split_chunks->mid.max = split_chunks->pivot2;
	split_chunks->mid.size = split_chunks->pivot2 - split_chunks->pivot1 ;

	split_chunks->max.position = BOTTOM_A;
	split_chunks->max.min = split_chunks->pivot2 + 1;
	split_chunks->max.max = chunk_to_sort->max;
	split_chunks->max.size = chunk_to_sort->max - split_chunks->pivot2 ;
}

void	merge_back_no_sort(t_chunk *chunk_to_sort, \
			t_split_chunks *split_chunks, t_list_program *list_program)
{
	printer_dbg_split(MERGE_NS, split_chunks, list_program);
	while (chunk_to_sort->size-- > 0)
		move_stack_fromto(split_chunks->position_from, TOP_A, list_program);
}

// Function to split a chunk into three parts
void	split_chunk( t_chunk *chunk_to_sort, t_split_chunks *split_chunks, \
			t_list_program *list_program)
{
	int	value;
	int	i;
	int	pivot1;
	int	pivot2;

	printer_dbg_split(SPLIT, split_chunks, list_program);
	i = chunk_to_sort->min - 1;
	pivot1 = split_chunks->pivot1;
	pivot2 = split_chunks->pivot2;
	if (chunk_to_sort->position == TOP_B || chunk_to_sort->position == BOTTOM_B)
		merge_back_no_sort(chunk_to_sort, split_chunks, list_program);
	while (i <= chunk_to_sort->max)
	{
		value = (*list_program->stack_a)->index;
		if (value > pivot2)
			move_stack_fromto(TOP_A, BOTTOM_A, list_program);
		else if (value > pivot1)
			move_stack_fromto(TOP_A, TOP_B, list_program);
		else
			move_stack_fromto(TOP_A, BOTTOM_B, list_program);
		i++;
	}
}

// Recursive function to sort a chunk
void	recursive_split_chunk(t_chunk *chunk_to_sort, \
			t_list_program *list_program)
{
	t_split_chunks	split_chunks;

	if (chunk_to_sort->size == 1)
	{
//		sort_3_chunk(list_program);
		return ;
	}
	pivot_calculation(chunk_to_sort, &split_chunks);
	split_chunk(chunk_to_sort, &split_chunks, list_program);

	recursive_split_chunk(&split_chunks.max, list_program);

	recursive_split_chunk(&split_chunks.mid, list_program);
	merge_back_no_sort(&split_chunks.mid, &split_chunks, list_program);

	recursive_split_chunk(&split_chunks.min, list_program);
	merge_back_no_sort(&split_chunks.min, &split_chunks, list_program);
}

void	quick_sort_pushswap(t_list_program *list_program)
{
	t_chunk	chunk_to_sort;

	ft_printers(QUICK, list_program);
	chunk_to_sort = (t_chunk) \
		{0, list_program->stack_a_size - 1, \
		list_program->stack_a_size, TOP_A};
	recursive_split_chunk(&chunk_to_sort, list_program);
}

//is_sorted_linked_list_push(list_program);

/* void	merge_back_and_sort(t_chunk *chunk_to_sort, \
			t_split_chunks *split_chunks, t_list_program *list_program)
{
	t_list_dls	**stack_a;
	t_list_dls	**stack_b;
	int			i;
	t_chunk		chunk_to_sort_new;

	printer_dbg_split(MERGE_AS, split_chunks, list_program);
	sort_3_chunk(list_program);
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
	sort_3_chunk(list_program);
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
	sort_3_chunk(list_program);
} */

/* static void	merge_back_max(t_chunk *chunk_to_sort, \
				t_split_chunks *split_chunks, t_list_program *list_program)
{
	int	i;

	printer_dbg_split(MERGE_AS, split_chunks, list_program);
	i = split_chunks->min.size ;
	while (i-- > 0)
		rotate("rr", 'a', list_program);
	i = split_chunks->mid.size;
	while (i-- > 0)
		push('a', list_program);
	while (*list_program->stack_b)
		push('a', list_program);
} */