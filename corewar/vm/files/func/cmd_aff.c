/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_aff_cmd(t_map *map, t_ps *ps);

void			cmd_aff(t_map *map, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[15].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}

	printf("%sAFF HAS BEEN USED BY:%s\n", GREEN, RESET);
	// print_process(ps);

	pc = fill_commands(map, ps);
	execute_aff_cmd(map, ps);
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_aff_cmd(t_map *map, t_ps *ps)
{
	if (map->flags->a_flag == 1)
		ft_printf("Aff: %c\n", ps->reg[ps->arg[0] - 1]);
}
