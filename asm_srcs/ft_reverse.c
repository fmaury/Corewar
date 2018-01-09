/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <fmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:41:56 by fmaury            #+#    #+#             */
/*   Updated: 2017/10/05 14:55:52 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_check_error(char *file, t_asm *sfile)
{
	int		len;

	len = ft_strlen(file);
	if (len < 4 || (file[len - 1] != 'r' || file[len - 2] != 'o' ||
				file[len - 3] != 'c' || file[len - 4] != '.'))
	{
		ft_putstr("Error: Bad file extension, should be a '.cor'\n");
		return (0);
	}
	else if ((sfile->fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("Error: Can't open the file\n");
		return (0);
	}
	if (file)
	{
		sfile->origin = ft_strdup(file);
		file[ft_strlen(file) - 1] = '\0';
		file[ft_strlen(file) - 2] = '\0';
		file[ft_strlen(file) - 3] = '\0';
	}
	sfile->file = ft_strjoin(file, ".s");
	return (1);
}

void			ft_com_name(t_asm *sfile)
{
	char	*tmp;

	tmp = ft_strdup(sfile->bin + 4);
	sfile->code = ft_strjoinzfree(".name \"", tmp, 2);
	sfile->code = ft_strjoinzfree(sfile->code, "\"\n", 1);
	tmp = ft_strdup(sfile->bin + 12 + PROG_NAME_LENGTH);
	sfile->code = ft_strjoinzfree(sfile->code, ".comment \"", 1);
	sfile->code = ft_strjoinzfree(sfile->code, tmp, 3);
	sfile->code = ft_strjoinzfree(sfile->code, "\"\n\n", 1);
}

int				ft_reverse(char *file, t_asm *sfile)
{
	int		ret;

	if (!ft_check_error(file, sfile))
		return (0);
	if ((ret = read(sfile->fd, sfile->bin, CHAMP_MAX_SIZE +
					PROG_NAME_LENGTH + COMMENT_LENGTH + 1)) < 0)
	{
		ft_fprintf(2, "Error: read failed ret = %d\n", ret);
		return (0);
	}
	if (ret > CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH)
	{
		ft_fprintf(2, "Error: champ is too big\n");
		return (0);
	}
	ft_com_name(sfile);
	ft_reverse_code(sfile);
	ft_printf("%s", sfile->code);
	return (0);
}
