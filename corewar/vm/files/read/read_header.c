/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

unsigned int		magic_reading(unsigned char *buf, t_info *info)
{
	unsigned int	res;

	res = get_value(buf, 4);
	if (res != COREWAR_EXEC_MAGIC)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(info->file_name, 2);
		ft_putstr_fd(" has an invalid header\n", 2);
		exit(0);
	}
	return (res);
}

char				*name_reading(unsigned char *buf, t_info *info)
{
	int				i;
	int				j;
	char			*res;

	i = 0;
	j = sizeof(unsigned int);
	res = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	while (i < PROG_NAME_LENGTH + 1)
	{
		res[i] = buf[j];
		i++;
		j++;
	}
	return (res);
}

unsigned int		size_reading(unsigned char *buf, t_info *info)
{
	int				i;
	unsigned int	res;

	res = 0;
	i = sizeof(unsigned int) + PROG_NAME_LENGTH + 1;
	while (i % 4 != 0)
		i++;
	res = get_value(buf + i, 4);
	if (res > 682)
	{
		ft_putstr_fd("Error: File  ../../42.cor(change it) has too large a code (", 2);
		ft_putnbr_fd(res, 2);
		ft_putstr_fd(" bytes > 682 bytes)\n", 2);
		exit(0);
	}
	return (res);
}

char				*comment_reading(unsigned char *buf, t_info *info)
{
	char			*res;
	int				i;
	int				j;

	i = 0;
	j = sizeof(unsigned int) + PROG_NAME_LENGTH + 1;
	while (j % 4 != 0)
		j++;
	j += sizeof(unsigned int);
	res = (char *)malloc(sizeof(char) * COMMENT_LENGTH + 1);
	while (i < COMMENT_LENGTH + 1)
	{
		res[i] = buf[j];
		i++;
		j++;
	}
	return (res);
}