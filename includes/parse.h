/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:04:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/05 00:33:50 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "content_file.h"
# include "figure.h"

#ifndef EXTENSION_FILENAME
# define EXTENSION_FILENAME	".rt"
#endif

#ifndef MAX_PARAMETERS
# define MAX_PARAMETERS 6
#endif

typedef bool (*t_fill_infos)(char *, void *structure);

//	parse.c
t_content_file	*readfile(const char *filename, t_figure *infos);
bool			check_extension_filename(const char *filename);
bool	        parse_line(t_content_file *node, t_figure *infos);
#endif
