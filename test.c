int strprint(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int main(void)
{
	strprint("fjrbh");
	return (0);
}