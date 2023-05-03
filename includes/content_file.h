/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 04:32:29 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/03 06:15:07 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTENT_FILE_H
# define CONTENT_FILE_H

# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

#ifndef MIN_CONTENT_CAPICITY
# define MIN_CONTENT_CAPICITY	20
#endif

#ifndef MAX_CONTENT_READ
# define MAX_CONTENT_READ	1
#endif

typedef struct	s_content_file
{
	size_t					size;
	size_t					capacity;
	char					*line;
	struct s_content_file	*next;
}				t_content_file;

t_content_file	*cf_new(void);
size_t			cf_size(t_content_file *cf);
void			cf_add(char c, t_content_file *cf);
void			cf_delete(t_content_file *cf);

#endif
