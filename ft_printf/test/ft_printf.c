#include <unistd.h>
#include <stdarg.h>

int ft_putconv(unsigned int n, unsigned int base)
{
	int cs;
	char *alphab = "0123456789abcdef"; 
	
	cs = 0;
	if (n >= base)
		cs += ft_putconv(n / base, base);
	cs += write(1, &alphab[n % base], 1);
	return (cs);
}

int ft_putnbr(int n)
{
	int cs;
	
	cs = 0;
	if (n < 0)
	{
		cs += write(1, "-", 1);
		n *= (-1);
	}
	cs += ft_putconv((unsigned int)n, 10);
	return (cs);
}

int ft_putstr(char *str)
{
	int cs, i;

	if (!str)
		return (write(1, "(null)",6));
	cs = 0;
	i = -1;
	while (str[++i] != '\0')
		cs += write(1, &str[i], 1);
	return (cs);
}

int ft_printf(const char *str, ...)
{
	int cs, i;
	va_list arg;

	va_start(arg, str);
	cs = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if(str[i] == 's')
				cs += ft_putstr(va_arg(arg, char *));
			if (str[i] == 'd')
				cs += ft_putnbr(va_arg(arg, int ));
			if(str[i] == 'x')
				cs += ft_putconv(va_arg(arg, unsigned int), 16);		
		}
		else 
			cs += write(i, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (cs);
}

#include <stdio.h>

int main (void)
{
	int i;
	char *str = "strunz";

	i = 16;
	printf("\n%d\n", ft_printf("%s", str));
	printf("\n%d\n",ft_printf("%d", i));
	printf("\n%x\n", ft_printf("%x", i));
	return (0);
}






