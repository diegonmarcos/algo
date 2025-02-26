/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z3.4.1.Quicksort_alt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:22 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/22 08:51:28 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_split_chunk1(t_chunk1 *chunk_to_sort, \
			t_list_program *list_program);
void	selection_sort_chunk1(t_chunk1 *chunk_to_sort, t_list_program *list_program);
void	pivot_calculation1(t_chunk1 *chunk_to_sort);

void	merge_back_to_a1(t_chunk1 *chunk_to_sort, t_list_program *list_program)
{
	t_list_dls	**stack_a;
	t_list_dls	**stack_b;
	int			i;

	printer_dbg_split1(MERGE_AS, chunk_to_sort, list_program);
	stack_a = list_program->stack_a;
	stack_b = list_program->stack_b;
	i = chunk_to_sort->split_chunks_mid->min;
	while (i <= chunk_to_sort->split_chunks_mid->max)
	{
		push('a', list_program);
		i++;
	}
	if (chunk_to_sort->split_chunks_mid->max - chunk_to_sort->split_chunks_mid->min >= 2)
	{
		recursive_split_chunk1(chunk_to_sort->split_chunks_mid, list_program);
		return ;
	}
	selection_sort_chunk1(chunk_to_sort, list_program);
	i = chunk_to_sort->split_chunks_min->min;
	while (i <= chunk_to_sort->split_chunks_min->max)
	{
		push('a', list_program);
		i++;
	}
	if (chunk_to_sort->split_chunks_min->max - chunk_to_sort->split_chunks_min->min >= 2)
	{
		recursive_split_chunk1(chunk_to_sort->split_chunks_min, list_program);
		return ;
	}
	selection_sort_chunk1(chunk_to_sort, list_program);
}

// Function to split a chunk into three parts
void	split_chunk1( t_chunk1 *chunk_to_sort, t_list_program *list_program)
{
	int	value;
	int	i;
	int	pivot1;

	if (!*list_program->stack_b)
		is_sorted_linked_list_push(list_program);
	pivot_calculation1(chunk_to_sort);
	printer_dbg_split1(SPLIT, chunk_to_sort, list_program);
	i = chunk_to_sort->min - 1;
	pivot1 = chunk_to_sort->pivot1;
	while (i <= chunk_to_sort->max)
	{
		value = (*list_program->stack_a)->index;
		if (value > chunk_to_sort->pivot2)
			rotate("r", 'a', list_program);
		else if (value > pivot1)
			push('b', list_program);
		else
		{
			push('b', list_program);
			rotate("r", 'b', list_program);
		}
		i++;
	}
}

// Recursive function to sort a chunk
void	recursive_split_chunk1(t_chunk1 *chunk_to_sort, \
			t_list_program *list_program)
{
	if ((chunk_to_sort->max - chunk_to_sort->min <= 2))
	{
		merge_back_to_a1(chunk_to_sort, list_program);
		return ;
	}
	split_chunk1(chunk_to_sort, list_program);
	recursive_split_chunk1(chunk_to_sort->split_chunks_max, list_program);
	recursive_split_chunk1(chunk_to_sort->split_chunks_mid, list_program);
	recursive_split_chunk1(chunk_to_sort->split_chunks_min, list_program);
}

void	quick_sort_pushswap(t_list_program *list_program)
{
	t_chunk1	chunk_to_sort;

	chunk_to_sort.min = 0;
	chunk_to_sort.max = list_program->stack_a_size - 1;

	recursive_split_chunk1(&chunk_to_sort, list_program);
}

void	pivot_calculation1(t_chunk1 *chunk_to_sort)
{
	t_chunk1	split_chunks_max = {0, 0, 0, 0, NULL, NULL, NULL};
	t_chunk1	split_chunks_mid = {0, 0, 0, 0, NULL, NULL, NULL};
	t_chunk1	split_chunks_min = {0, 0, 0, 0, NULL, NULL, NULL};

	chunk_to_sort->pivot2 = 0;
	chunk_to_sort->pivot1 = 0;

	chunk_to_sort->split_chunks_max = &split_chunks_max;
	chunk_to_sort->split_chunks_mid = &split_chunks_mid;
	chunk_to_sort->split_chunks_min = &split_chunks_min;

	chunk_to_sort->pivot1 = chunk_to_sort->min + \
							(chunk_to_sort->max - chunk_to_sort->min) / 3;
	chunk_to_sort->pivot2 = chunk_to_sort->min
		+ 2 * (chunk_to_sort->max - chunk_to_sort->min) / 3;

	chunk_to_sort->split_chunks_max->max = chunk_to_sort->max;
	chunk_to_sort->split_chunks_max->min = chunk_to_sort->pivot2 + 1;

	chunk_to_sort->split_chunks_mid->max = chunk_to_sort->pivot2;
	chunk_to_sort->split_chunks_mid->min = chunk_to_sort->pivot1 + 1;

	chunk_to_sort->split_chunks_min->max = chunk_to_sort->pivot1;
	chunk_to_sort->split_chunks_min->min = chunk_to_sort->min;
}

void	selection_sort_chunk1(t_chunk1 *chunk_to_sort, t_list_program *list_program)
{
	t_list_dls	**stack_a;
	int			first;
	int			second;
	int			third;

	stack_a = list_program->stack_a;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && first == third)
		swap('a', list_program);
	else if (first > second && second > third && first > third)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		swap('a', list_program);
		push('a', list_program);

	}
	else if (first > second && second < third && first > third)
	{
		swap('a', list_program);
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if (first > second && second < third && first < third)
		swap('a', list_program);
	else if (first < second && second > third && first > third)
	{
		rotate("r", 'a', list_program);
		rotate("r", 'a', list_program);
		push('b', list_program);
		rotate("rr", 'a', list_program);
		rotate("rr", 'a', list_program);
		push('a', list_program);
	}
	else if (first < second && second > third && first < third)
	{
		push('b', list_program);
		swap('a', list_program);
		push('a', list_program);
	}
	else if ((first < second && second < third && first < third) \
		|| first == second)
		return ;
}

