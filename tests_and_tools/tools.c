/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:45:22 by mparisse          #+#    #+#             */
/*   Updated: 2023/06/03 16:43:52 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
// TRUE 1
// FALSE 0
#include <stdio.h>

#define EPSILON 0.00001

typedef float float4 __attribute__((ext_vector_type(4)));

bool    equal(float a, float b)
{
    if (fabs(a - b) < EPSILON)
        return true;
    return false;
}

bool equal_tuple(float4 a, float4 b)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (!equal(a[i], b[i]))
            return false;
        i++;
    }
    return (true);
}

float4  adding_tuple(float4 a, float4 b)
{
    float4 res;
    int i;

    i = 0;
    while (i < 3)
    {
        res[i] = a[i] + b[i];
        i++;
    }
    return (res);
}

float4  substracting_tuple(float4 a, float4 b)
{
    float4 res;
    int i;

    i = 0;
    while (i < 3)
    {
        res[i] = a[i] - b[i];
        i++;
    }
    return (res);
}

float4  negating_tuple(float4 a, float4 b)
{
    int     i;
    float4  res;

    (void) b;
    i = 0;
    while (i < 3)
    {
        res[i] = a[i] * -1;
        i++;
    }
    return (res);
}

float4  mutilplying_scalar_tuple(float4 a, float b)
{
    int     i;
    float4  res;

    (void) b;
    i = 0;
    while (i < 3)
    {
        res[i] = a[i] * b;
        i++;
    }
    return (res);
}

float  magnitude(float4 a)
{
    int     i;
    float   res;

    i = 0;
    while (i < 3)
    {
        res += a[i] * a[i];
        i++;
    }
    return (sqrtf(res));
}

float4 normalization(float4 a)
{
    float b;
    float4 res;
    int i;

    b = magnitude(a);
    i = 0;
    while (i < 3)
    {
        res[i] = a[i] / b;
        i++;
    }
    return (res);
}
/*
the smaller the dot product the larger angle between the vectors
*/
float dot_product(float4 a, float4 b)
{
    return ((a.x * b.x) + (a.y * b.y)+ (a.z * b.z));
}
/*
function cross(a, b)
return vector(a.y * b.z - a.z * b.y,
a.z * b.x - a.x * b.z,
a.x * b.y - a.y * b.x)
end function
*/
float4  cross_product(float4 a, float4 b)
{
    float4  res;

    res.x = (a.y * b.z) - (a.z * b.y);
    res.y = (a.z * b.x) - (a.x * b.z);
    res.y = (a.x * b.y) - (a.y * b.x);
    return (res);
}

void    display_tuple(float4 b, char *name_tuple)
{
    printf("%s tuple has the following values:\n", name_tuple);
    printf("x = %f\n", b.x);
    printf("y = %f\n", b.y);
    printf("z = %f\n", b.z);
}

int main()
{
    /*=== FIRST TOOL ===*/
    float4 i;

    i.x = 4.20001;
    i.y = 4.20001;
    int res = equal(i.x, i.y); 
    printf("Comparing two floating points together : \n");
    printf("%f and %f are %s equal\n",i.x, i.y   ,res ? "" : "not");

    /*=== SECOND TOOL ===*/

    float4 m = {3, -2, 5, 0};
    float4 m2 = {-2, 3, 1, 0};
    float4 m3 = negating_tuple(m, m2);

    int res2 = equal_tuple(m3, m2);
    printf("Tuples 1 and 2 are %s equal\n", res2 ? "" : "not");

    display_tuple(m3, "m2   ");

    /*=== THIRD TOOL ===*/


    float4 magn = {-1, -2, -3};

    printf("magnitude >> %f \n", magnitude(magn));

}