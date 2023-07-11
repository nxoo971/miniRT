/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:40:25 by mparisse          #+#    #+#             */
/*   Updated: 2023/07/10 18:12:04 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "main.h"
// # include "tools.h"

// determinants.c
float   determinant_2b2(m2 matrix);
float   minor_f3(m3 m, int row, int column);
float	cofactor(m3 m, int row, int column);
float	cofactor4(m4 m, int row, int column);
float	determinant4(m4 m);

// prints.c 
void    print_matrix_pirate(m4 a);
void    print_matrix_pirate3(m3 a);
void    print_matrix_pirate2(m2 a);
void    print_tuple(float4 f);

// ops_matrix.c
float4  matrix_tuple(m4 a, float4 b);
m4      matrix_transpose(m4 a);
m4      inverted_matrix(m4	m);

// ops matrix
m4  scaling_matrix(float x, float y, float z);
m4	translated_matrix(float x, float y, float z);

// subs_matrix.c
m2  submatrix_f3(m3 matrix, int row, int column);
m3  submatrix_f4(m4 matrix, int row, int column);

// bool    equal_matrix(matrix2 a, matrix2 b);

#endif