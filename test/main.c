#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("output start:\n");
	ft_printf("hello%i", 69);
	printf("\noutput end");
}
