/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:30:55 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/05 03:27:39 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "content_file.h"

t_content_file	*cf_new(void)
{
	t_content_file	*cf;

	cf = malloc(sizeof(t_content_file));
	if (cf)
	{
		cf -> size = 0;
		cf -> capacity = MIN_CONTENT_CAPICITY;
		cf -> line = malloc(cf -> capacity + 1);
		cf -> next = 0;
	}
	return (cf);
}

void	cf_add(char c, t_content_file *cf)
{
	if (cf -> size == cf -> capacity)
	{
		cf -> capacity *= 2;
		cf -> line = realloc(cf -> line, cf -> capacity);
	}
	cf -> line[cf -> size++] = c;
}

void	cf_delete(t_content_file *cf)
{
	t_content_file	*tmp;

	tmp = cf;
	while (cf)
	{
		cf -> size = 0;
		cf -> capacity = 0;
		ft_memdel((void **)& cf -> line);
		tmp = cf -> next;
		free(cf);
		cf = tmp;
	}
}

size_t	cf_size(t_content_file *cf)
{
	return cf -> size;
}
