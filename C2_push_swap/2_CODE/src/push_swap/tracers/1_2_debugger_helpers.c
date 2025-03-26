/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_2_debugger_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:52:30 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/26 18:54:47 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

#include "push_swap.h"

//quick_sort_pushswap(list_program);
void	sort_stack_dbg(t_list_program *list_program)
{
	if (!ft_strcmp(ALGO, "selec"))
		selection_sort(list_program);
	else if (!ft_strcmp(ALGO, "radix"))
		radix_sort_pushswap(list_program);
	else if (!ft_strcmp(ALGO, "quick"))
		gear_sort_pushswap(list_program);
	else if (!ft_strcmp(ALGO, "gear"))
		gear_sort_pushswap(list_program);
	if (list_program->stack_a_size == 501)
		radix_sort_pushswap(list_program);
	else if (list_program->stack_a_size == 502)
		gear_sort_pushswap(list_program);
	else if (list_program->stack_a_size == 503)
		gear_sort_pushswap(list_program);
}
