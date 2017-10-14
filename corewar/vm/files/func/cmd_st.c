/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_st_cmd(t_map *map, t_ps *ps);

void			cmd_st(t_map *map, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[2].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sST HAS BEEN USED BY:%s\n", GREEN, RESET);
	// print_process(ps);
	
	pc = fill_commands(map, ps);
	execute_st_cmd(map, ps);
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_st_cmd(t_map *map, t_ps *ps)
{
	int			second_arg;
	int			first_arg;
	int			distance;
	int			pc;

	first_arg = ps->arg[FIRST_ARG];
	second_arg = ps->arg[SECOND_ARG];
	if (first_arg < 1 || first_arg > 16)
			return ;
	if(ps->arg_types[SECOND_ARG] == REG_CODE)
	{
		if (second_arg < 1 || second_arg > 16)
			return ;
		ps->reg[second_arg - 1] = ps->reg[first_arg - 1];
	}
	else
	{
		pc = ps->pc;
		distance = second_arg % IDX_MOD;
		move_map_counter(&pc, distance);
		write_value_on_map(map, pc, ps->reg[first_arg - 1]);
	}
}
