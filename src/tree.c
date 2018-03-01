/*
** tree.c for tree in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 24 12:01:55 2014 Pierre Bechade
** Last update Thu Nov 27 14:21:18 2014 Pierre Bechade
*/

#include "my.h"
#include "tree.h"

t_tree		*my_create(char *s1, char *opr)
{
  t_tree	*tree;

  tree = my_xmalloc(sizeof(t_tree));
  tree->op = s1;
  tree->cmd = opr;
  tree->left = NULL;
  tree->right = NULL;
  return (tree);
}
