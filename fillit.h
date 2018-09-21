/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:29:14 by amartyne          #+#    #+#             */
/*   Updated: 2018/07/02 12:53:20 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int					row_z_n(char const *file);
int					n_mezdu(char const *file);
int					konec_fld(char *a);
int					connect(char **tt_sp_fld);
int					symbols(char *a);
int					ttrmns(char *s);
char				*copy_a(char *argv);
char				**field(int ttrmns);
int					field_length(int amount_ttrmnss);
void				output(char **field);
int					count_hash(char *a);
typedef struct		s_point
{
	int		x[4];
	int		y[4];
}					t_point;

typedef struct		s_ttlist
{
	struct s_ttlist		*next;
	t_point				point;
	char				c;
}					t_ttlist;
t_ttlist			*cut_ttrmns(char **ttrmns_split_filed, int amount_ttrmns);
t_point				where_to_insert(char **fld, t_ttlist *ttrmnss, t_point on);
t_ttlist			*ft_ttlist_new(char c);
t_point				zeropoint(t_point orgn, int k);
char				**insert(char **field, t_point orgn, char c);
int					while_back(char **fld, t_ttlist *arr_tt, int n, t_point ix);
int					backtracking (char **fld, t_ttlist *arr_ttrmns, int n,
		t_point orgn);
int					ai2(char *a);
int					con(int i, int j, int n, char **tt_sp_fld);
void				ft_arrfree(char **s);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *restrict dst, const void *restrict src, \
		size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
int					ft_sqrt(int nb);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
#endif
