/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:04:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/03 06:09:54 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "content_file.h"

#ifndef EXTENSION_FILENAME
# define EXTENSION_FILENAME	".rt"
#endif

//	parse.c
t_content_file	*readfile(const char *filename);
bool			check_extension_filename(const char *filename);

#endif
