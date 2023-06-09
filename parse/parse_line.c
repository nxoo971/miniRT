/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewancti <jewancti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:00:34 by jewancti          #+#    #+#             */
/*   Updated: 2023/05/11 06:04:14 by jewancti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_data(char *s)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	start = i;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	if (!s[i])
		return (s + i);
	s[i] = 0;
	return (s + start);
}

static
bool	set_color(const char *s, int * const ptr)
{
	int			nb;
	int			i;

	i = 0;
	while (*s)
	{
		nb = 0;
		while (ft_isdigit(*s))
		{
			nb = (nb * 10) + *s++ - '0';
			if (nb > 255)
				return (false);
		}
		if (i != 2 && *s != ',')
			return (false);
		*(ptr + i++) = nb;
		if (!*s)
			break ;
		s++;
	}
	return (true);
}

static
char	*set_vector(char *s, float * const ptr)
{
	const size_t	size = ft_strlen(s);
	size_t			act_size;
	char			*find;
	int				i;

	i = 0;
	while (i < 3)
	{
		find = ft_strchr(s, ',');
		if (!find && i != 2)
			return (NULL);
		if (i != 2)
			*find = 0;
		*(ptr + i) = atof(s);
		act_size = ft_strlen(s);
		if (size > act_size + 1)
			s += act_size + 1;
		else
			return (NULL);
		i++;
	}
	return (s);
}

bool	fill_struct(char *content, char *origin, const size_t size, void * const ptr)
{
	size_t	act_size;

	content = get_data(content);
	if (ft_strcmp((char *)ptr, AMBIENT_LIGHT_IDENTIFIER) == 0) {
		*(float *)(ptr + sizeof(t_color) + sizeof(float)) = atof(content); // ratio
		act_size = ft_strlen(content);
		if (size > act_size + 1)
			content += act_size + 1;
		else
			return (false);
		return (set_color(content, ptr + sizeof(char [3]) + 1));
	}
	content = set_vector(content, ptr + sizeof(t_vector));	// viewpoint/point/center
	if (!content)
		return (false);
	if (ft_strcmp((char *)ptr, CAMERA_IDENTIFIER) == 0
		|| ft_strcmp((char *)ptr, PLAN_IDENTIFIER) == 0
		|| ft_strcmp((char *)ptr, CYLINDER_IDENTIFIER) == 0) {
		content = get_data(content);
		content = set_vector(content, ptr + (sizeof(t_vector) * 2)); // orientation
		if (!content)
			return (false);
		if (ft_strcmp((char *)ptr, PLAN_IDENTIFIER) == 0)
			return (set_color(content, ptr + (sizeof(t_vector) * 3)));
		content = get_data(content);
		*(float *)(ptr + sizeof(t_vector) * 3) = atof(content);
		if (ft_strcmp((char *)ptr, CYLINDER_IDENTIFIER))
			return (origin + (size - 1) == content + ft_strlen(content));
		content += ft_strlen(content) + 1;
		content = get_data(content);
		*(float *)(ptr + sizeof(t_vector) * 3 + sizeof(float)) = atof(content);
		content += ft_strlen(content) + 1;
		return (set_color(content, ptr + (sizeof(t_vector) * 3) + (sizeof(float) * 2)));
	}
	content = get_data(content);
	*(float *)(ptr + (sizeof(t_vector) * 2) + sizeof(t_color)) = atof(content); // ratio/diameter_sphere
	act_size = ft_strlen(content);
	return (size > act_size + 1 && set_color(content + act_size + 1, ptr + (sizeof(t_vector) * 2)));
}

static
int	get_index_from_identifier(const char *identifier)
{
	const char * const identifiers[MAX_PARAMETERS] = {
		AMBIENT_LIGHT_IDENTIFIER, CAMERA_IDENTIFIER, LIGHT_IDENTIFIER,
		SPHERE_IDENTIFIER, PLAN_IDENTIFIER, CYLINDER_IDENTIFIER
	};
	int	i;

	i = 0;
	while (i < MAX_PARAMETERS)
	{
		if (ft_strcmp(identifier, identifiers[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

bool	parse_line(t_content_file *node, t_figure *infos)
{
	static const int	jump[MAX_PARAMETERS] = { 0, 0, 0, sizeof(t_sphere), sizeof(t_plan), sizeof(t_cylinder) };
	static int			times[MAX_PARAMETERS] = { 0, 0, 0, -1, -1, -1 };
	void *const			addrs[MAX_PARAMETERS] = {
		& infos -> ambient_light,
		& infos -> camera,
		& infos -> light,
		& infos -> sphere,
		& infos -> plan,
		& infos -> cylinder,
	};
	char				*tmp;
	size_t				act_size;
	int					index;

	tmp = node -> line;
	tmp = get_data(tmp);
	index = get_index_from_identifier(tmp);
	if (index == -1)
		return (false);
	times[index]++;
	if (times[0] > 1 || times[1] > 1 || times[2] > 1)
		return (false);
	ft_strcpy((char *)addrs[index] + (times[index] * jump[index]), tmp);
	act_size = ft_strlen(tmp);
	if (node -> size > act_size + 1)
		tmp += act_size + 1;
	return (fill_struct(tmp, node -> line, node -> size, addrs[index] + (times[index] * jump[index])));
}
