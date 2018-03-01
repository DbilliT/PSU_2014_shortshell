/*
** my_exit.c for exit in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Nov 28 17:24:41 2014 Pierre Bechade
** Last update Fri Nov 28 18:35:14 2014 Pierre Bechade
*/

#include "my.h"

int	my_calc_getnbr(char *str, int i, double nb_final, int nb_return)
{
  while (((str[i] != '\0') && ((str[i] >= '0') && (str[i] <= '9')))
         || ((str[i] == '-') || (str[i] == '+')))
    {
      if (str[i] >= '0' && str[i] <= '9')
        nb_final = (nb_final * 10) + (str[i] - 48);
      if (str[i] == '-')
        nb_return = nb_return + 1;
      i++;
    }
  if ((nb_return % 2) != 0)
    nb_final = nb_final - (2 * nb_final);
  if (nb_final > 2147483647 || nb_final < -2147483648)
    return (0);
  nb_return = nb_final;
  return (nb_return);
}

int		my_getnbr(char *str)
{
  int		result;
  double	nb_final;
  int		i;
  int		nb_return;

  result = 0;
  nb_final = 0;
  i = 0;
  nb_return = 0;
  result = my_calc_getnbr(str, i, nb_final, nb_return);
  return (result);
}

int	my_exit(char **tab)
{
  int	i;

  i = 0;
  if (tab[1] == NULL)
    {
      my_putstr("exit\n");
      exit(EXIT_SUCCESS);
    }
  while (tab[1][i])
    {
      if ((tab[1][i] < '0' || tab[1][i] > '9') && tab[1][i] != '-')
	{
	  my_putstr_e("exit: Expression Syntax.\n");
	  return (0);
	}
      i++;
    }
  my_putstr("exit\n");
  exit(my_getnbr(tab[1]));
  return (0);
}
