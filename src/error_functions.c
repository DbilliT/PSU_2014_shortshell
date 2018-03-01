/*
** error_functions.c for error_functions in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Nov 22 17:02:28 2014 Pierre Bechade
** Last update Sat Nov 22 17:02:30 2014 Pierre Bechade
*/

#include "my.h"

void	my_putchar_e(char c)
{
  write(2, &c, 1);
}

void	my_putstr_e(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_e(str[i]);
      i++;
    }
}

void	my_put_nbr_calc_e(int nb)
{
  if (nb == -2147483648)
    {
      my_putchar_e('-');
      my_putchar_e('2');
      my_putchar_e('1');
      my_putchar_e('4');
      my_putchar_e('7');
      my_putchar_e('4');
      my_putchar_e('8');
      my_putchar_e('3');
      my_putchar_e('6');
      my_putchar_e('4');
      my_putchar_e('8');
    }
  else
    {
      if (nb < 0)
        {
          my_putchar_e('-');
          nb = nb * -1;
        }
      if (nb >= 10)
        my_put_nbr_calc_e(nb / 10);
      my_putchar_e(nb % 10 + '0');
    }
}

int	my_put_nbr_e(int nb)
{
  my_put_nbr_calc_e(nb);
  return (0);
}
