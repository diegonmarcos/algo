/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_1_data_release.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:11:43 by dinepomu          #+#    #+#             */
/*   Updated: 2025/02/26 13:01:23 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function to free all allocated memory
*/
void	ft_free_push_swap_end(t_list_program *list_program)
{
	if (list_program->argc == 2)
		ft_free_array_2d(list_program->stack_a_array);
	ft_free_array_2d(list_program->moves);
	ft_free_array_2d(list_program->moves_optim);
	free(list_program->list_garbage);
	{
		ft_free_ls_doubly(*list_program->stack_a);
		free(list_program->stack_a);
	}
	{
		ft_free_ls_doubly(*list_program->stack_b);
		free(list_program->stack_b);
	}
}

/*
** Function to free all allocated memory on halt stage!
*/
void	ft_free_push_swap_halt(t_list_program *list_program)
{
	if (list_program->argc == 2)
		ft_free_array_2d(list_program->stack_a_array);
}

//	ft_free_gb_all(list_program->list_garbage);
