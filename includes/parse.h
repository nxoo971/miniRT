/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:04:44 by jewancti          #+#    #+#             */
/*   Updated: 2023/06/02 12:33:29 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "content_file.h"
# include "figure.h"
# include <stdio.h>

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
