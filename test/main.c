#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("output start:\n");
	ft_printf("hello%i %c%c%c", 69, '4', '2', '0');
	printf("\noutput end");
}
