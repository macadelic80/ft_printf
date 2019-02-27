/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 09:26:43 by aben-azz          #+#    #+#             */
/*   Updated: 2019/02/27 10:58:40 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_precision(char *str, t_fmt *fmt, va_list ap)
{
	int prec;
	int point;

	point = 0;
	while (*str && !~ft_indexof(TYPES, *str))
	{
		if (*str == '.' && (point = 1) && str++)
		{
			prec = 0;
			(ft_isdigit(*str)) && (prec = ft_atoi(str));
			while (ft_isdigit(*str))
				str++;
			if (*str == '*' && *(str - 1) == '.' && str++)
			{
				prec = va_arg(ap, int);
				point = prec < 0 ? 0 : point;
			}
			continue;
		}
		str++;
	}
	(!point) && (prec = -1);
	if (!point && ~ft_indexof("fF", fmt->type))
		prec = 6;
	return (prec);
}

static int		get_field(char *str, t_fmt *fmt, va_list ap)
{
	int width;
	int temp;

	width = 0;
	while (*str && !~ft_indexof(TYPES, *str))
	{
		if (*str == '.' && str++)
		{
			while (ft_isdigit(*str))
				str++;
			str += (*str == '*' && *(str - 1) == '.');
			continue;
		}
		(*str == '*') && (width = va_arg(ap, int));
		(*str == '*' && width < 0) && (fmt->opt |= SUB);
		(*str == '*') && (width = ABS(width));
		if (ft_isdigit(*str) && (temp = ft_atoi(str)))
		{
			width = temp;
			while (ft_isdigit(*(str + 1)))
				str++;
		}
		str++;
	}
	return (width);
}
#include <stdio.h>
// static int		get_length(char *s, char c)
// {
// 	int n;
// 	int i;
//
// 	i = 0;
// 	n = 0;
// 	while (!~ft_indexof(LENGTH, s[n++]) && s[n] && n < ft_indexof(s, c)){
// 		//(void)i++;
// 		printf("ft_indexof: %d|%s|%d|\n", ft_indexof(s, c), s, i++);
// 	}
//
// 	if (~(n = ft_indexof(LENGTH, s[i])))
// 		return (ft_count(s, s[i]) ? (1 << (n)) + (ft_count(s, s[i]) % 2) : -1);
// 	else
// 		return (-1);

int				get_length(char *str, char c)
{
	int lcount;
	int hcount;

	lcount = ft_counti(str, 'l', ft_indexof(str, c));
	hcount = ft_counti(str, 'h', ft_indexof(str, c));
	if (c == 'f' && ft_counti(str, 'L', ft_indexof(str, c)) > 0)
		(LU_);
	if (ft_counti(str, 'j', ft_indexof(str, c)))
		return (J_);
	if (ft_counti(str, 'z', ft_indexof(str, c)))
		return (Z_);
	if (lcount)
		return (lcount % 2 ? L_ : LL_);
	if (hcount && hcount % 2)
		return (H_);
	return (hcount ? HH_ : 0);
}

static void		get_type(char *s, t_fmt *fmt, va_list ap)
{
	int i;

	i = 0;
	fmt->opt = 0;
	fmt->prefixe = 0;
	fmt->signe = 0;
	while (!~ft_indexof(TYPES, s[i]))
		i++;
	fmt->type = s[i];
	fmt->field = get_field(s, fmt, ap);
	fmt->length = get_length(s, fmt->type);
	fmt->prec = get_precision(s, fmt, ap);
}

t_fmt			*get_options(char *s, va_list ap)
{
	t_fmt *fmt;

	if (!(fmt = (t_fmt *)malloc(sizeof(t_fmt))))
		exit(1);
	get_type(s, fmt, ap);
	if (~ft_indexof("DOUF", fmt->type))
	{
		fmt->length = L_;
		fmt->type = ft_tolower(fmt->type);
	}
	while (*s && !~ft_indexof(TYPES, *s))
	{
		if (*s == '0' && !ft_isdigit(*(s - 1)) && *(s - 1) != '.')
			fmt->opt |= ZERO;
		if (*s == ' ' && !fmt->signe && (~ft_indexof("FfiIdD", fmt->type)))
			fmt->signe = ' ';
		(*s == '+' && (~ft_indexof("fFiIdD", fmt->type))) && (fmt->signe = '+');
		(*s == '#') && (fmt->opt |= HASH);
		(*s == '-') && (fmt->opt |= SUB);
		(*s == '#' && (~ft_indexof("oOfF", fmt->type))) && (fmt->prefixe = 1);
		((*s == '#' && (~ft_indexof("xX", fmt->type)))) && (fmt->prefixe = 2);
		s++;
	}
	(~ft_indexof("pP", fmt->type)) && (fmt->prefixe = 2);
	return (fmt);
}