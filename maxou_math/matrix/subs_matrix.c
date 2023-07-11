/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subs_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:19:35 by mparisse          #+#    #+#             */
/*   Updated: 2023/07/10 17:46:43 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../matrix.h"

m2  submatrix_f3(m3 matrix, int row, int column)
{
    m2  res;
	int ii;
	int jj;

	ii = 0;
	jj = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != row)
        {
			jj = 0;
            for (int j = 0; j < 3; j++)
			{
                if (j != column)
				{
					res[ii][jj++] = matrix[i][j];
				}
			}
			ii++;
		}
    }
	printf("\n");
    return (res);
}

m3  submatrix_f4(m4 matrix, int row, int column)
{
    m3  res;
	int ii;
	int jj;

	ii = 0;
	jj = 0;
    for (int i = 0; i < 4; i++)
    {
        if (i != row)
        {
			jj = 0;
            for (int j = 0; j < 4; j++)
			{
                if (j != column)
				{
					res[ii][jj++] = matrix[i][j];
				}
			}
			ii++;
		}
    }
    return (res);
}
