/* 
$$      $$\ 
$$$\    $$$ |
$$$$\  $$$$ | $$$$$$\  $$\   $$\  $$$$$$\  $$\   $$\ 
$$\$$\$$ $$ | \____$$\ \$$\ $$  |$$  __$$\ $$ |  $$ |
$$ \$$$  $$ | $$$$$$$ | \$$$$  / $$ /  $$ |$$ |  $$ |
$$ |\$  /$$ |$$  __$$ | $$  $$<  $$ |  $$ |$$ |  $$ |
$$ | \_/ $$ |\$$$$$$$ |$$  /\$$\ \$$$$$$  |\$$$$$$  |
\__|     \__| \_______|\__/  \__| \______/  \______/

 * @ Author: Maxou
 * @ Create Time: 2023-06-02 16:03:27
 */

#include <stdio.h>
#include <math.h>

// struct foo
// {
//   int i1;
//   int i2;
//   unsigned long long x __attribute__ ((warn_if_not_aligned (16)));
// };
// typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float2 __attribute__((ext_vector_type(2)));

typedef int v4si __attribute__((__vector_size__(16)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float2 __attribute__((ext_vector_type(2)));
typedef float m4x4_t __attribute__((matrix_type(4, 4)));

float4 foo(float2 a, float2 b) {
  float4 c;
  c.xz = a;
  c.yw = b;
  return c;
}

int main()
{
    float4 i = foo(4.0, 6.0);
    m4x4_t m;

    m[0][0] = 42;

    printf(">> m 0 0 %f\n", m[0][0] );
    printf(">> i.x %f\n", i.x );
    printf(">> i.x %f\n", i.z );
    printf(">> i.x %f\n", i.y );
    printf(">> i.x %f\n", i.w );
}
