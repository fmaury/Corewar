/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaury <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:06:22 by fmaury            #+#    #+#             */
/*   Updated: 2017/09/25 12:13:49 by fmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lecture(int fd, char *buf, char **line, int ret)
{
	int			i;
	int			save_ret;
	char		str[BUFF_SIZE + 1];

	save_ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		buf[ret] = '\0';
		if (ret < 0)
			return (-1);
		while ((buf[i] != '\n' && buf[i] != '\0') && i < BUFF_SIZE)
		{
			str[i] = buf[i];
			i++;
		}
		str[i] = '\0';
		if (i == BUFF_SIZE)
			i--;
		(*line) = ft_strjoin((*line), str, 1);
		save_ret = ret;
		if (buf[i] == '\n' || buf[i] == '\0')
			break ;
	}
	return (save_ret);
}

void			ft_check2(int i, int len, char **line, char *str)
{
	int			j;
	char		tmp[BUFF_SIZE];

	j = 0;
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	ft_strclr(*line);
	free(*line);
	*line = ft_strdup(tmp);
	j = 0;
	while (i + j < len)
	{
		str[j] = str[i + j + 1];
		j++;
	}
	str[j] = '\0';
}

static int		ft_check(char **line, char *str)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (str[0] != '\0')
	{
		len = ft_strlen(str);
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i == len)
		{
			ft_strclr(*line);
			free(*line);
			(*line) = ft_strdup(str);
			ft_strclr(str);
			return (0);
		}
		else
		{
			ft_check2(i, len, line, str);
			return (1);
		}
	}
	return (-1);
}

void			ft_cpy_buf(char *buf, char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] != '\0')
		i++;
	while (buf[i + j] && i + j <= BUFF_SIZE)
	{
		str[j] = buf[i + j];
		j++;
	}
	str[j] = '\0';
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static char		str[BUFF_SIZE + 1];
	int				test;

	test = 0;
	if (fd < 0 || (line) == NULL)
		return (-1);
	ft_strclr(buf);
	if (!((*line) = ft_memalloc(1)))
		return (-1);
	test = ft_check(line, str);
	if (test == 1)
		return (1);
	ret = ft_lecture(fd, buf, line, 0);
	if (ret < 0)
		return (-1);
	if (ret == 0 && str[0] == '\0' && test == -1)
		return (0);
	ft_cpy_buf(buf, str);
	return (1);
}
