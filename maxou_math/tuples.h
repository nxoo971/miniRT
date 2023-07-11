/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:11:37 by mparisse          #+#    #+#             */
/*   Updated: 2023/07/10 18:18:10 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include "main.h"

// ops_tuples.c
bool    equal(float a, float b);
bool    equal_tuple(float4 a, float4 b);
float4  adding_tuple(float4 a, float4 b);
float4  substracting_tuple(float4 a, float4 b);
float4  negating_tuple(float4 a, float4 b);
float4  multiplying_scalar_tuple(float4 a, float b);

// utils.c
float  magnitude(float4 a);
float4 normalization(float4 a);
float dot_product(float4 a, float4 b);
float4  cross_product(float4 a, float4 b);

#endif