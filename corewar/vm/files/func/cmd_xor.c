/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_xor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void		execute_xor_cmd(t_map *map, t_ps *ps);

void			cmd_xor(t_map *map, t_ps *ps)
{
	int			pc;

	if (ps->cycles_to_cmd < g_tab[7].cycle)
	{
		ps->cycles_to_cmd++;
		return ;
	}
	
	printf("%sXOR HAS BEEN USED BY:%s\n", GREEN, RESET);
	// print_process(ps);

	pc = fill_commands(map, ps);
	execute_xor_cmd(map, ps);
	ps->pc = pc;

	null_commands_variables(ps);
}

static void		execute_xor_cmd(t_map *map, t_ps *ps)
{
	int			value[g_tab[7].count_arg];
	int			res;
	int			i;

	i = 0;
	while (i < g_tab[7].count_arg)
	{
		value[i] = get_variables_idxmod(map, ps, i, g_tab[7].arg[i]);
		if (ps->skip_cmd)
		{
			ps->skip_cmd = 0;
			return ;
		}
		i++;
	}
	res = value[FIRST_ARG] ^ value[SECOND_ARG];
	if (!res)
		ps->carry = 1;
	else
		ps->carry = 0;
	ps->reg[ps->arg[THIRD_ARG] - 1] = res;
}

