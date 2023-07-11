/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:24:14 by mparisse          #+#    #+#             */
/*   Updated: 2023/07/10 17:46:45 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

float4	matrix_tuple(m4 a, float4 b)
{
	float4 res;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		res[i] = 0.0;
		j = -1;
		while (++j < 4)
		{
			res[i] += b[j] * a[i][j];
		}
		i++;
	}
	return (res);
}

m4 matrix_transpose(m4 a)
{
	m4 res;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			res[j][i] = a[i][j];
		}
		i++;
	}
	return (res);
}

m4	inverted_matrix(m4	m)
{
	m4		cof_m;
	float	cof_tmp;
	float	det;

	det = determinant4(m);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cof_tmp = cofactor4(m, i, j);
			cof_m[j][i] = cof_tmp / det;
		}	
	}
	return (cof_m);
}
