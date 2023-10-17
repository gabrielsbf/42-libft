int	ft_isalpha(int c)
{
	if(c >= 97 && c <=122)
		return 2;
	else if (c >= 65 && c <= 90)
		return 1;
	else
		return 0;
}
