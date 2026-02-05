void free_map(int **z, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(z[i]);
		i++;
	}
	free(z);
}
