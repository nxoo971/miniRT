/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:21:58 by mparisse          #+#    #+#             */
/*   Updated: 2023/07/10 18:02:17 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

float   determinant_2b2(m2 m)
{
    return ((m[0][0] * m[1][1]) - (m[0][1] * m[1][0]));
}

float	minor_f3(m3 m, int row, int column)
{
	return (determinant_2b2(submatrix_f3(m, row, column)));
}

float	cofactor(m3 m, int row, int column)
{
	float res;

	if (((row + column) % 2) != 0)
	{
		res = minor_f3(m, row, column) * -1;
		return (res);
	}
	return (minor_f3(m, row, column));
}

// pour avoir le cofactor de m4 0 0 ils suffit d'obtenir le cofactor
// de la submatrice m4 0 0 
float	cofactor4(m4 m, int row, int column)
{
	float	res;
	m3		sub;

	sub = submatrix_f4(m, row, column);
	res = 0;
	for (int i = 0; i < 3; i++)
	{
		res += cofactor(sub, 0, i) * sub[0][i];
	}
	if (((row + column) % 2) != 0)
		return res * -1; 
	return (res);
}

float	determinant4(m4 m)
{
	float	res;
	float	cof;
	m3		sub3;

	res = 0;
	for (int i = 0; i < 4; i++)
	{
		sub3 = submatrix_f4(m, 0, i);
		cof = sub3[0][0] * (sub3[1][1]*sub3[2][2] - sub3[1][2]*sub3[2][1]) 
		- sub3[0][1] * (sub3[1][0] * sub3[2][2] - sub3[1][2] * sub3[2][0])
		+ sub3[0][2] * (sub3[1][0] * sub3[2][1] - sub3[1][1] * sub3[2][0]);
		if (i % 2)
			cof = cof * -1;
		res += (m[0][i] * cof);
	}
	return res;
}