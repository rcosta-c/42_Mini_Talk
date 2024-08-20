/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:44:59 by rcosta-c          #+#    #+#             */
/*   Updated: 2024/05/08 07:56:20 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printformat(va_list ap, const char *format)
{
	int		x;

	x = 0;
	if (*format == 'c')
		x += (ft_printchar(va_arg(ap, int), STDOUT_FILENO));
	else if (*format == 's')
		x += (ft_printstr(va_arg(ap, char *), STDOUT_FILENO));
	else if (*format == 'p')
		x += ft_printptr(va_arg(ap, unsigned long long));
	else if (*format == 'i' || *format == 'd')
		x += (ft_printnbr(va_arg(ap, int), STDOUT_FILENO));
	else if (*format == 'u')
		x += (ft_printu(va_arg(ap, unsigned int)));
	else if (*format == 'x')
		x += (ft_printx_lbase(va_arg(ap, unsigned int)));
	else if (*format == 'X')
		x += (ft_printx_ubase(va_arg(ap, unsigned int)));
	else if (*format == '%')
		x += (ft_printchar('%', STDOUT_FILENO));
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += printformat(ap, format);
		}
		else
		{
			ft_printchar(*format, STDOUT_FILENO);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}
/*
#include "ft_printchar.c"
#include "ft_printnbr.c"
#include "ft_printnbr_base.c"
#include "ft_printstr.c"
#include "ft_printptr.c"
#include "ft_p_strlen.c"
#include "ft_strdup.c"
#include "ft_printx_lbase.c"
#include "ft_printu.c"
#include "ft_printx_ubase.c"

int	main()
{
    char ch = 'A';
    
    char *str = "Hello, world!";
    int num = 42;
    int	num1 = 542780;
    long num2 = 98139126313;
    long long num3 = 8712392131703;
    unsigned int uns_num = 123;
    void *ptr = &num;
    int	reslt_ft;
    int	reslt;

    reslt = 0;
    reslt_ft = 0;
    // Teste %c
    printf("Teste %%c:\n");
    reslt += printf("printf: %c\n", ch);
    reslt_ft += ft_printf("frintf: %c\n", ch);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);

    reslt = 0;
    reslt_ft = 0;
    // Teste %s
    printf("\nTeste %%s:\n");
    reslt += printf("printf: %s\n", str);
    reslt_ft += ft_printf("frintf: %s\n", str);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
	 reslt = 0;
    reslt_ft = 0;

    // Teste %p
    printf("\nTeste %%p:\n");
    reslt += printf("printf: %p\n", ptr);
    reslt_ft += ft_printf("frintf: %p\n", ptr);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
 reslt = 0;
    reslt_ft = 0;

    // Teste %d e %i
    printf("\nTeste %%d e %%i:\n");
    reslt += printf("printf: %d, %i\n", num, num);
    reslt_ft += ft_printf("frintf: %d, %i\n", num, num);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
 reslt = 0;
    reslt_ft = 0;

    // Teste %u
    printf("\nTeste %%u:\n");
    reslt += printf("printf: %u\n", uns_num);
    reslt_ft += ft_printf("frintf: %u\n", uns_num);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
 reslt = 0;
    reslt_ft = 0;

    // Teste %x e %X
    printf("\nTeste %%x e %%X:\n");
    reslt += printf("printf: %x, %X\n", num, num);
    reslt_ft += ft_printf("frintf: %x, %X\n", num, num);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
 reslt = 0;
    reslt_ft = 0;

    printf("\nTeste %%x e %%X:\n");
    reslt += printf("printf: %x, %X\n", num1, num1);
    reslt_ft += ft_printf("frintf: %x, %X\n", num1, num1);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
 reslt = 0;
    reslt_ft = 0;

    printf("\nTeste %%x e %%X:\n");
    reslt += printf("printf: %lx, %lX\n", num2, num2);
    reslt_ft += ft_printf("frintf: %x, %X\n", num2, num2);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
 reslt = 0;
    reslt_ft = 0;

    printf("\nTeste %%x e %%X:\n");
    reslt += printf("printf: %llx, %llX\n", num3, num3);
    reslt_ft += ft_printf("frintf: %x, %X\n", num3, num3);
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
 reslt = 0;
    reslt_ft = 0;


    // Teste %%
    printf("\nTeste %%:\n");
    reslt += printf("printf: %%\n");
    reslt_ft += ft_printf("frintf: %%\n");
    printf("reslt: %d\n reslt_ft: %d\n", reslt, reslt_ft);
    return 0; 
}*/
