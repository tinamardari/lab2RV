#ifndef LAB2_H
# define LAB2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

typedef struct clasa
{
  int  index;
  char nume[3];
} t_clasa;


void initialize_uni(float *tab, int n, ...);
void initialize_bi(float **tab, int r, int c, ...);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_my_strrev(char *str);
char			*ft_itoa(int n);
t_clasa *create_clasa(int index, char *nume);
void user_initialize_uni(float *tab, int n, char *title);
void print_y();
int		ft_atoi(const char *str);

#endif
