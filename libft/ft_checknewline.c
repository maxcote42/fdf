/* Renvoie l'indice du premier '\n' ou la longueur si pas de '\n' */
int	checknewline(const char *stash)
{
	int	i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (i);
}
