#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	ft_printf("hel");
	ft_printf("");
	ft_printf("lo\n\n");

	ft_printf("Voici %s: %d\n", "int max", INT_MAX);
	const char* int_min = "int min";
	ft_printf("Et voici %s: %d\n", int_min, INT_MIN);
}
