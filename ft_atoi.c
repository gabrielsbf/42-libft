int	ft_atoi(const char *str)
{
	int minus;
	int	i;
	int	result;

	minus = 0;
	result = 0;
	i = 0;
	if (!(str[0] == 45 || str[0] == 43 || (str[0] >= 48 && str[0] <= 57)))
		return (0);
	if(str[0] == 45 || str[0] == 43)
	{
		minus = (str[0] == 45);
		i++;
	}
	while(str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (minus != 0)
		result *= -1;
	return (result );
}
