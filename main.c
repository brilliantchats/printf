#include "main.h"

int main(void)
{
	int len;
	len = _printf("My intials are %c.%c %s", 'B', 'C', "MD");
	_printf("%b\n", len);
	return (0);
}
