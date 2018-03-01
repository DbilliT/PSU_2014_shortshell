/*
** tree.h for tree in /home/bechad_p/rendu/PSU_2014_minishell2/include
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 24 11:59:37 2014 Pierre Bechade
** Last update Thu Nov 27 16:54:53 2014 Pierre Bechade
*/

#ifndef _TREE_H_
# define _TREE_H_

typedef struct	s_tree
{
  char		*cmd;
  char		*op;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

/* IN SRC/TREE.C */
t_tree	*my_create(char *s1, char *opr);

#endif /* _TREE_H_  */
