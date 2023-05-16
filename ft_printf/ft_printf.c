#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_putnbr(unsigned int n, unsigned int base)
{
	int cs;
	char *alpab = "0123456789abcdef";

	cs = 0;
	if (n > base)
		cs += ft_putnbr(n / base, base);
	cs += write(1, &alpab[n % base], 1);
	return (cs);
}

int ft_putdec(int n)
{
	int cs;
		
	cs = 0;
	if (n < 0)
	{
		cs += write(1, "-", 1);
		n = n * (-1);
	}
	cs += ft_putnbr((unsigned int)n, 10);
	return (cs);
}

int ft_putstr(char *str)
{
	int cs;
	int i;
	
	cs = 0;
	i = -1;
	while(str[++i] != '\0')
		cs += write(1, &str[i], 1);
	return (cs);
}

int ft_printf(const char *str, ...)
{
	int cs;
	va_list arg;
	int i;
	
	va_start(arg, str);
	cs = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{	
			i++;
			if (str[i] == 's')
				cs += ft_putstr(va_arg(arg, char *));
			if (str[i] == 'd')
				cs += ft_putdec(va_arg(arg, int ));
			if (str[i] == 'x')
				cs += ft_putnbr(va_arg(arg, unsigned int), 16);
		}
		else
			cs += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (cs);
}


int main ()
{
    	int i;

    	i=14314;
    	printf("--- Il mio printf --- \n");

   	printf("COUNT: %d\n", ft_printf("T%s\n", "ciao"));
   	printf("COUNT: %d\n", ft_printf("Il numero è: %d\n", i));
    	printf("COUNT: %d\n", ft_printf("HEX %x\n", i));
	
        printf("--- Il printf standard --- \n");
 
	printf("COUNT: %d\n", printf("T%s\n", "ciao"));
	printf("COUNT: %d\n", printf("Il numero è: %d\n", i));
	printf("COUNT: %d\n", printf("HEX %x\n", i));

   	printf("L'output dei due printf devono essere identici\n");
	return(0);
}







