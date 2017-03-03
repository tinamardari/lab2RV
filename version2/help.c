#include "lab2.h"

void user_initialize_uni(float *tab, int n, char *title)
{
  int i;

  printf("%s\n", title);
  while (i < n)
  {
    printf("x[%d] = ",i);
    scanf("%f",&tab[i]);
    i++;
  }
}

void initialize_uni(float *tab, int n, ...)
{
  va_list ap;
  int i;
  float value;

  va_start(ap, n);
  i = 0;
  while (i < n)
  {
    value = va_arg(ap, double);
    tab[i] = value;
    i++;
  }
  va_end(ap);
}

void initialize_bi(float **tab, int r, int c, ...)
{
  va_list ap;
  int i;
  int j;
  float value;

  va_start(ap, c);
  i = 0;
  while (i < r)
  {
    j = 0;
    while (j < c)
    {
      value = va_arg(ap, double);
      tab[i][j] = value;
      j++;
    }
    i++;
  }
  va_end(ap);
}



size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		temp[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		temp[i] = *s2;
		s2++;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	ft_my_strrev(char *str)
{
	char	temp;
	int		begin;
	int		end;

	begin = 0;
	end = ft_strlen(str) - 1;
	while (begin < end)
	{
		temp = str[begin];
		str[begin++] = str[end];
		str[end--] = temp;
	}
}

char			*ft_itoa(int n)
{
	long long	nb;
	char		*str;
	int			i;

	i = 0;
	nb = n;
	str = (char *)malloc(sizeof(char) * 21);
	if (!str)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		nb = -nb;
	while (nb)
	{
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_my_strrev(str);
	return (str);
}

t_clasa *create_clasa(int index, char *nume)
{
  t_clasa *new;

  new = (t_clasa *)malloc(sizeof(t_clasa));
  if (!new)
    return (NULL);
  new->index = index;
  strcpy(new->nume, nume);
  return (new);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}
