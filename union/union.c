#include <unistd.h>

int main (int argc, char **argv)
{
	int i;
	int j;
	int k;
	char str[255];
	int rel;
	int ktmp;

	if (argc != 3)
		return (write(1, "\n", 1));
	i = -1;
	while (++i < 255)
		str[i] = 0;
	k = 0;
	i = 1;
	j = 0;
	while (argv[i][j] != '\0')
	{
		if (i == 1 && j == 0)
		{
			str[k] = argv[i][j];
			k++;
		}
		rel = 0;
		ktmp = -1;
		while (++ktmp < k)
			if(str[ktmp] == argv[i][j])
				rel = 1;
		if(rel == 0)
		{
			str[k] = argv[i][j];
			k++;
		}
		if (i == 1 && argv[i][j + 1] == '\0')
		{
			i++;
			j = 0;
		}
		else 
			j++;
	}
	i = -1;
	while (++i < k)
		write(1, "str[i]",1);
	write(1, "\n",1 );
	return (0);
}



