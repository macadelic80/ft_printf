/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 08:51:22 by aben-azz          #+#    #+#             */
/*   Updated: 2019/02/06 03:45:53 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/includes/libft.h"
#include <stdio.h>



int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// printf("|%i,%i|\n",
	// count_flags(argv[1], ft_atoi(argv[2]))[0],
	// count_flags(argv[1], ft_atoi(argv[2]))[1]);
	// get_flags(argv[1], count_flags(argv[1], 0)[1]);
	// printf("xddddddd\n");
	// t_fmt flag = format("ui", 10);
	// t_fmt *flags = malloc(sizeof(flag) * 4);
	// 		flags[0] = format("ui", 10);
	// 		flags[1] = format("ui", 10);
	// 		flags[2] = format("ui", 10);
	// printf("%d,%d,%d,%d,%d\n", flag.precision, flag.length, flag.type, flag.minimal_length, flag.options);
	// printf("XDDD\n%d,%d,%d,%d,%d\n%d,%d,%d,%d,%d\n",
	// 	flags[0].precision, flags[0].length, flags[0].type, flags[0].minimal_length, flags[0].options,
	// 	flags[1].precision, flags[1].length, flags[1].type, flags[1].minimal_length, flags[1].options);
	// printf("________________________\n");
	//get_flags(argv[1], count_flags(argv[1], ft_atoi(argv[2]))[1]);
	//int a = ft_printf("xd\n%siu\n%s\nuiui%s: int: %d,%f\n", "mdr", "PTDR PRINTF", "xd", 1888, 18.21121);
	//int a = printf("xd: % -+012.13lhhhllls\n", 12);
	//printf("a vaut %d\n", a);
	// int o = get_options(argv[1]);
	// printf("types: %d\n", get_type(argv[1]));
	// int s = get_length(argv[1]);
	// printf("L:%d\nLL:%d\nH:%d\nHH:%d\nresult:%d\n",
	// 	s == L_,

	// 	s == LL_,
	// 	s == H_,
	// 	s == HH_,
	// 	s);
	// int type = get_type(argv[1]);
	// printf("c: %d\ns: %d\np: %d\nd: %d\ni: %d\no: %d\nu: %d\nX: %d\nx: %d\n",
	//  C_ == type,
	//  S_ == type,
	//  P_ == type,
	//  D_ == type,
	//  I_ == type,
	//  O_ == type,
	//  U_ == type,
	//  X_ == type,
	//  LOWX_ == type);
	// int length = get_minimal_lengths(argv[1]);
	//int precisions = get_precision(argv[1]);
	//printf("-------------\nprecision: %d\n", precisions);
	//view_fmt(xd, count_flags(argv[1], 0)[1]);
	//view_fmt(flags, 3);
	//t_fmt flag = format(argv[1], 10);
	 // printf("L:%d\nLL:%d\nH:%d\nHH:%d\n",
	 // 	flag.length == L_,
	 // 	flag.length == LL_,
	 // 	flag.length == H_,
	 // 	flag.length == HH_);
	 // printf("c: %d\ns: %d\np: %d\nd: %d\ni: %d\no: %d\nu: %d\nX: %d\nx: %d\n",
		//  C_ == flag.type,
		//  S_ == flag.type,
		//  P_ == flag.type,
		//  D_ == flag.type,
		//  I_ == flag.type,
		//  O_ == flag.type,
		//  U_ == flag.type,
		//  X_ == flag.type,
		//  LOWX_ == flag.type);
	//t_fmt *flags = get_flags((char*)argv[1],
	//						count_flags((char*)argv[1], 0)[1]);
	//ft_repeat_char(, 1);
	//char c = 'u';
	//format_string((char)c, 7, 0, 1);
	//ft_printf("|%-05.2s|%-010c|xd\n", "test", 'x');
	//printf("|%p|\n", p);
	// char* str = malloc(100);
	// double ff = 18.5535;
	// ft_ftoa(ff, 30, str);
	// printf("|%.30f|\n",ff);
	// printf("|%s|\n", str);

	long double n = 9.1465555533234545456465456465465465;
	long double n_ = -9.1465555533234545456465456465465465;
	(void)n;
	(void)n_;

	char *string = "%L3.10f\n";
	ft_printf(string, n);
	printf(string, n);
	ft_printf( string,n_);
	printf(string, n_);
	return (0);
}
/*
gerer les fields negatives pour %scf

*/
