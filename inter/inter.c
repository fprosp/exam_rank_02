#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int itmp;
	int j;
	int rel;

	if (argc != 3)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[1][i] != '\0')
	{
		j = 0;
		while (argv[2][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
			{
				if (i == 0)
				{
					write(1, &argv[1][i], 1);
					break ;
				}
				rel = 0;
				itmp = i - 1;
				while (itmp >= 0)
				{
				   if (argv[1][i] == argv[1][itmp])
					   rel = 1;
					itmp--;
				}
				if (rel == 0)
				{
					write(1, &argv[1][i], 1);
					break ;
				}
			}
			j++;
		}	
		i++;
	}
	write(1, "\n", 1);
	return (0);	
}
