/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatic.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:39:55 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/20 22:25:05 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

#ifndef BISTROMATIC_H
# define BISTROMATIC_H
# define MCK(val, ret) if ((val) == NULL) return (ret)
# define RETURN_VAL(val, ret) if (val == ret) return (0)

typedef struct		s_parse
{
	int				size;
	char			base;
	char			*value_base;
	char			neg;
	int 			par;
}					t_parse;

int 				ft_printf(const char *fmt, ...);
char				*parse_input();
void				parse_argv(char **av, t_parse *parsing);
char				*add(char *a, char *b, t_parse *parse);
void				*mm_realloc (void *ptr, size_t size);
char				*sub(char *a, char *b, t_parse *parse);
void				swap(char **a, char **b, int *len_a, int *len_b);
char				*str_reverse_in_place(char *str, t_parse *parse);
char				*eval_expr(char *str, t_parse *parse);
char				*parse_sums_subs(char **str, t_parse *parse);
int					is_base(char c, t_parse *parse);
char				*mult(char *s1, char *s2, t_parse *parse);
int					is_op(char c);
char				*new_array(char *res, int len1, int len2, t_parse *parse);
void				shift_right_minus(char **str, int *len, t_parse *parse);
void				remove_elem(char **str, t_parse *parse, int len);
char				*division(char *a, char *b, t_parse *parse);
char				*del_spaces(char *str);



#endif
