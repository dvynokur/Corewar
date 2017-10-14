/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_sti_cmd(t_map *map, t_ps *ps);

void			cmd_sti(t_map *map, t_ps *ps)
{
	int			pc;

	// проверка кодирующего бита
	
	// printf("%sSTI HAS BEEN USED BY:%s\n", GREEN, RESET);
	// printf("%sps->cycles_to_cmd:\t%d%s\n", GREEN, ps->cycles_to_cmd, RESET);
	// print_process(ps);

	pc = fill_commands(map, ps);
	execute_sti_cmd(map, ps);
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_sti_cmd(t_map *map, t_ps *ps)
{
	int			value[g_tab[10].count_arg];
	int			distance;
	int			pc;
	int			i;

	i = 0;
	while (i < g_tab[10].count_arg)
	{
		value[i] = get_variables_idxmod(map, ps, i, g_tab[10].arg[i]);
		if (ps->skip_cmd)
		{
			ps->skip_cmd = 0;
			return ;
		}
		i++;
	}
	pc = ps->pc;
	distance = (value[SECOND_ARG] + value[THIRD_ARG]) % IDX_MOD;
	move_map_counter(&pc, distance);
	write_value_on_map(map, pc, ps->reg[value[FIRST_ARG] - 1]);
}