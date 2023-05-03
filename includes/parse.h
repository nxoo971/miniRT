/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:04:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/04 01:22:17 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "content_file.h"
# include "figure.h"

#ifndef EXTENSION_FILENAME
# define EXTENSION_FILENAME	".rt"
#endif

//	parse.c
t_content_file	*readfile(const char *filename, t_infos *infos);
bool			check_extension_filename(const char *filename);
bool	        parse_line(t_content_file *node, t_infos *infos);
#endif
