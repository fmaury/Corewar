/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:17:05 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/05 19:17:06 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	check_double(t_vm *vm, int id)
{
	int			i;

	i = 0;
	while (i < vm->nb_players)
		if (vm->players[i++].id == id)
			return (0);
	return (1);
}

static int	add_player(t_vm *vm, int fd, int flag, int id_arg)
{
	static int		id = 1;
	int				index;

	index = vm->nb_players;
	if (index == MAX_PLAYERS)
		return (0);
	vm->players[index].index = index + 1;
	if (flag && id_arg == -id)
		id++;
	if (flag)
		while (!check_double(vm, id_arg))
			id_arg = -1 * id++;
	vm->players[index].id = flag ? id_arg : -id;
	vm->players[index].fd = fd;
	vm->nb_players++;
	if (!flag)
		while (!check_double(vm, -id))
			id++;
	return (1);
}

static int	get_next_int(int *a_int, int *aindex, char **argv)
{
	int	index;

	index = *aindex;
	if (!argv[index + 1])
		return (0);
	if (!ft_myatoi(argv[index + 1], a_int))
		return (0);
	*aindex = index + 2;
	return (1);
}

static int	get_player(t_vm *vm, int *aindex, char **argv)
{
	int		index;
	int		id_arg;
	int		tmp;
	int		fd;

	index = *aindex;
	id_arg = 0;
	if (!ft_strcmp(argv[index], "-n"))
		if (!get_next_int(&id_arg, aindex, argv))
			return (0);
	if (!argv[*aindex] || (tmp = ft_strlen(argv[*aindex])) < 4)
		return (0);
	if (ft_strcmp(&argv[*aindex][tmp - 4], ".cor"))
		return (0);
	if ((fd = open(argv[*aindex], O_RDONLY)) < 0)
	{
		ft_fprintf(2, "Can't open the file\n");
		return (0);
	}
	tmp = (*aindex > index ? 1 : 0);
	*aindex = *aindex + 1;
	return (add_player(vm, fd, tmp, id_arg));
}

int			parse_argv(t_vm *vm, int argc, char **argv)
{
	int		index;
	int		ret;

	index = 1;
	ret = 1;
	while (index < argc)
	{
		if (!ft_strcmp(argv[index], "-dump")
		|| !ft_strcmp(argv[index], "-d"))
			ret = get_next_int(&(vm->dump), &index, argv);
		else if (!ft_strcmp(argv[index], "-v"))
			ret = get_next_int(&(vm->verbose), &index, argv);
		else if (!ft_strcmp(argv[index], "-ncurse") && (vm->ncurse = 1))
			ret = ++index;
		else if (!ft_strcmp(argv[index], "-a") && (vm->aff = 1))
			ret = ++index;
		else if (!ft_strcmp(argv[index], "-sound") && (vm->sound = 1))
			ret = ++index;
		else if (!get_player(vm, &index, argv))
			return (0);
		if (!ret)
			return (0);
	}
	return (vm->nb_players > 0 && vm->nb_players <= 4);
}
