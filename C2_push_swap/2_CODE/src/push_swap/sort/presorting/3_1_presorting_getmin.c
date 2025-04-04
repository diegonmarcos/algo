/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_1_presorting_getmin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:31:15 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/25 07:27:56 by dinepomu         ###   ########.fr       */
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
// UTILS/SORTING
//##############################################################################
/** GET_NEXT_MIN
 * Selection sort for doubly linked list = Get_next_min!
 * intro_sort = quick_sort + heap_sort + insertion_sort
 * hash_map = hash_table + hash_map
 */
t_list_dls	*get_next_min(t_list_dls **stack)
{
	t_list_dls	*head;
	t_list_dls	*min_node;
	int			first_iteration;

	head = *stack;
	min_node = NULL;
	first_iteration = 1;
	if (head == NULL)
		return (NULL);
	while (first_iteration || head != *stack)
	{
		if (head->index == -1 && (min_node == NULL || head->value
				< min_node->value))
			min_node = head;
		head = head->next;
		first_iteration = 0;
	}
	return (min_node);
}

/* ADD_INDEX_NUMBERS
Selection sort for doubly linked list = Get_next_min!
*/
void	add_index_numbers(t_list_dls *list)
{
	t_list_dls	*node;
	int			index;

	index = 0;
	node = get_next_min(&list);
	while (node)
	{
		node->index = index++;
		node = get_next_min(&list);
	}
}
