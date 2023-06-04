/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_shifting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:54:17 by mparisse          #+#    #+#             */
/*   Updated: 2023/06/03 01:07:47 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

float negative(float a)
{
    static unsigned int masked = 1 << 31;
    unsigned int *nb_bits = (unsigned int *)&a;

    *nb_bits |= masked;
    return (a);
}

int main()
{
    float k = 14; // Bit pattern 00001110
    float i = 4; // Bit pattern 00001110

    float j = 1 << 31; 

    printf(">> %f\n", negative(i));
    printf(">> %f\n", negative(k));
}