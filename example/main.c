#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	ft_printf("%p\n", 0xBABECAFE);
	ft_printf("hel");
	ft_printf("");
	ft_printf("lo\n\n");

	ft_printf("Voici %s: %d\n", "int max", INT_MAX);
	printf("On devrait voir %d\n", INT_MAX);
	const char* int_min = "int min";
	ft_printf("Et voici %s: %d\n", int_min, INT_MIN);
	printf("On devrait voir %d\n", INT_MIN);

	ft_printf("%x\n", 0xBABECAFE);
	ft_printf("%X\n", 0xBABECAFE);
}
