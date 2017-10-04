/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:01:24 by coleksii          #+#    #+#             */
/*   Updated: 2017/09/12 16:02:06 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/create.h"

int		write_rev_char(int fd, char arg)
{
	char tmp;

	tmp = 0;
	tmp = tmp | ((0xFF00 & arg) >> 8);
	tmp = tmp | ((0x00FF & arg) << 8);
	//tmp = arg << 8;
	write(fd, &tmp, 2);
	return (0);
}

int 	first_arg(t_cmd	*cmd, int fd)
{
	char	ar;

	ar = cmd->arg_types >> 6;
	ar = 0x3 & ar; //перестраховка от ошибок
	if (ar == 1)
		write(fd, &cmd->arg[0]->shrt, 1);
	else if (ar == 2)
	{
		if (g_sizes[cmd->code][2] == 2)
			write_rev_char(fd, cmd->arg[0]->num);
		else if (g_sizes[cmd->code][2] == 4)
			write_revers_bytes(fd, cmd->arg[0]->num);
		else
			write(2, "some wrong with size_dir", 24);
	}
	else if (ar == 3)
		write_rev_char(fd, cmd->arg[0]->chr);
	//printf("%d", ar);
	return (0);
}

int 	second_arg(t_cmd *cmd, int fd)
{
	char	ar;

	ar = cmd->arg_types >> 4;
	ar = 0x3 & ar; //перестраховка от ошибок
	//printf("%d", ar);
	if (ar == 1)
		write(fd, &cmd->arg[1]->shrt, 1);
	else if (ar == 2)
	{

		if (g_sizes[cmd->code][2] == 2)
			write_rev_char(fd, cmd->arg[1]->num);
		else if (g_sizes[cmd->code][2] == 4)
			write_revers_bytes(fd, cmd->arg[1]->num);
		else
			write(2, "some wrong with size_dir", 24);
	}
	else if (ar == 3)
		write_rev_char(fd, cmd->arg[1]->chr);

	return (0);
}

int 	write_arg(int fd, t_header *header, t_cmd *cmd)
{
	first_arg(cmd, fd);
	second_arg(cmd, fd);
	return (0);
}