/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:13:04 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/03 07:12:48 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parse.h"
# include "content_file.h"

#ifndef MAX_READ_SIZE
# define MAX_READ_SIZE	4096
#endif

bool	check_extension_filename(const char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 3)
		return (false);
	return (ft_strcmp((filename + i) - 3, EXTENSION_FILENAME) == 0);
}

t_content_file	*readfile(const char *filename)
{
	t_content_file			*cf;
	t_content_file			*cf_tmp;
	const int				fd = open(filename, O_RDONLY);
	char					tmp[MAX_CONTENT_READ + 1];
	int						ret;

	if (fd < 0)
		return (false);
	ret = 1;
	cf = cf_new();
	cf_tmp = cf;
	while (ret)
	{
		ret = read(fd, tmp, MAX_CONTENT_READ);
		if (ret < 0)
		{
			cf_delete(cf);
			close(fd);
			return (NULL);
		}
		if (ret == 0)
			break ;
		if (*tmp == '\n')
		{
			if (cf_tmp -> size)
			{
				cf_add('\0', cf_tmp);
				cf_tmp -> next = cf_new();
				cf_tmp = cf_tmp -> next;
			}
			continue ;
		}
		cf_add(*tmp, cf_tmp);
	}
	close(fd);
	cf_add('\0', cf_tmp);
	return (cf);
}
