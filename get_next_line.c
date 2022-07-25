/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharuni <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:02:59 by eharuni           #+#    #+#             */
/*   Updated: 2021/12/16 01:03:34 by eharuni          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_read_file(char	*main_str, int fd)
{
	ssize_t	r;
	char	*buff;

	buff = (char *)malloc((100 + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r = 1;
	buff[0] = '\0';
	while (!ft_strchr(buff, '\n'))
	{
		r = read(fd, buff, 100);
		if (r == -1)
		{
			free(buff);
			return (NULL);
		}
		if (r == 0)
			break ;
		buff[r] = '\0';
		main_str = ft_strjoin_new(main_str, buff);
	}
	free(buff);
	return (main_str);
}

static char	*ft_get_line(char *main_str)
{
	size_t	len;
	char	*line;

	len = 0;
	while (main_str[len] && main_str[len] != '\n')
		len++;
	line = (char *)malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	len = 0;
	while (main_str[len] && main_str[len] != '\n')
	{
		line[len] = main_str[len];
		len++;
	}
	if (main_str[len] == '\n')
	{
		line[len] = main_str[len];
		len++;
	}
	line[len] = '\0';
	return (line);
}

static char	*ft_new_main(char *main_str)
{
	size_t	i;
	size_t	i2;
	char	*new_str;

	i = 0;
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i] || !main_str[i + 1])
	{
		free(main_str);
		return (NULL);
	}	
	new_str = (char *)malloc((ft_strlen(main_str) - i) * sizeof(char));
	if (!new_str)
		return (NULL);
	i2 = 0;
	while (main_str[i + 1 + i2])
	{
		new_str[i2] = main_str[i + 1 + i2];
		i2++;
	}
	new_str[i2] = '\0';
	free(main_str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*main_str;
	char		*line;

	if (fd < 0)
		return (NULL);
	main_str = ft_read_file(main_str, fd);
	if (!main_str)
		return (NULL);
	line = ft_get_line(main_str);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	main_str = ft_new_main(main_str);
	return (line);
}
