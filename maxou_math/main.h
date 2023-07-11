/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:10:13 by mparisse          #+#    #+#             */
/*   Updated: 2023/07/10 18:14:04 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdbool.h>

# define EPSILON 0.00001

// different types of tuples for colors, points and vector
typedef float float4 __attribute__((ext_vector_type(4)));
typedef int int4 __attribute__((ext_vector_type(4)));

// matrices 
typedef float m2 __attribute__((matrix_type(2, 2)));
typedef float m4 __attribute__((matrix_type(4, 4)));
typedef float m3 __attribute__((matrix_type(3, 3)));


#endif