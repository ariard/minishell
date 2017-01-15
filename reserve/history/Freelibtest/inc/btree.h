/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 23:22:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/09 19:35:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct		s_btree
{
	void			*data;
	void			*key;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

typedef struct		s_root
{
	int				(*cmp)(const char *key1, const char *key2);
	int				size;
	t_btree			*root;
}					t_root;

void				ft_btree_init(t_root *btree_root,
		int (*cmp)(const char *key1, const char *key2));

t_btree				*ft_btree_ins_left(t_root *tree, t_btree *father,
		void *key, void *data);

t_btree				*ft_btree_ins_right(t_root *tree, t_btree *father,
		void *key, void *data);

t_btree				*ft_btree_create_node(t_btree **position, void *data, void *key);

t_btree				*ft_get_node(t_btree *root, void *key,
		int (*cmp)(const char *key1, const char *key2));

t_btree				*ft_get_father(t_btree *root, t_btree *father, void *key,
		int (*cmp)(const char *key1, const char *key2));

t_btree				*ft_btree_rem_node(t_root *tree, void *key);

void				ft_btree_destroy(t_btree *root);

void				ft_display_prefix(t_btree *root);

void				ft_execute_ast(t_root *tree, char **env, t_cht *sym_tab);

#endif
