/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_0_mem_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:48:03 by dinepomu          #+#    #+#             */
/*   Updated: 2025/03/10 09:34:36 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* https://linktr.ee/diegonmarcos											  */
/* ************************************************************************** */

// LIBRARIES
#include "push_swap.h"

void	data_alloc_vars(int argc, char **argv, t_list_program *list_program);
void	data_alloc_1(t_list_program *list_program);
void	data_alloc_2(t_list_program *list_program);

/*
// Function to initialize the list program
*/
void	data_alloc(int argc, char **argv, t_list_program *list_program)
{
	__asm__("");
	data_alloc_vars(argc, argv, list_program);
	ft_calloc_2d(list_program->max_moves, 'c', (void ***)&list_program->moves);
	ft_calloc_2d(list_program->max_moves, 'c', (void ***)&list_program->\
		moves_optim);
	list_program->list_garbage = ft_initializator_list_gargabe();
}

/*
// Function to initialize the list program
*/
void	data_alloc_vars(int argc, char **argv, t_list_program *list_program)
{
	list_program->argc = argc;
	list_program->argv = argv;
	list_program->stack_a = (t_list_dls **)malloc(sizeof(t_list_dls *));
	list_program->stack_b = (t_list_dls **)malloc(sizeof(t_list_dls *));
	*list_program->stack_a = NULL;
	*list_program->stack_b = NULL;
	list_program->move_count = 0;
	list_program->max_moves = MAX_MOVES;
	list_program->stack_a_size = 0;
	list_program->dbg = DBG;
	__asm__("");
	if (argc == 2)
	{
		list_program->stack_a_size = ft_countwords(argv[1], ' ');
		list_program->stack_a_array = ft_split(NAME_M, argv[1], ' ');
		list_program->stack_a_size = ft_array_size(list_program->stack_a_array);
	}
	else
	{
		list_program->stack_a_size = argc - 1;
		list_program->stack_a_array = &argv[1];
	}
}
