/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tubaeraslan <tubaeraslan@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:49:45 by tubaeraslan       #+#    #+#             */
/*   Updated: 2024/11/01 19:59:34 by tubaeraslan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_print_char(int c){
    write(1,&c,1);
}

void ft_print_str(char *str){
    int i;

    i = 0;
    while (str[i]!='\0')
    {
        write(1,&str[i],1);
        i++;
    }   
}

void ft_print_nbr(int nb){
    if (nb == -2147483648)
    {
        write(1,"-",1);
        write(1,"2147483648",10);
    }
    else if(nb <0){
        write(1,"-",1);
        ft_print_nbr(-nb);
    }
    else{
        if (nb >= 10)
        {
            ft_print_nbr(nb/10);
        }
        ft_print_char((nb%10)+48);
    }
}

void ft_printint(int n){
    char a= n+48;
    write(1,&a,1);
}
void ft_print_hexa(long n,char c){
    char *hex;
    if (c=='x')
    {
        hex = "0123456789abcdef";
    }
    else{
        hex = "0123456789ABCDEF";
    }
    if (n < 0)
    {
       n = -n;
    }
    else if (n < 16)
    {
        ft_print_char(hex[n]);
    }
    else{
        ft_print_hexa(n / 16,c);
        ft_print_hexa(n % 16,c);
    }
}

int ft_print_format(char c,va_list ap){
    int count;

    count = 0;
    if (c == 'c')
    {
        ft_print_char(va_arg(ap,int));
        count++;
    }
    else if(c == 's'){
        ft_print_str(va_arg(ap,char *));
        count++;
    }
    else if (c == 'p')
    {
       ft_print_ptr(va_arg(ap,void *));
    }
    else if(c == 'd' || c == 'i'){
        ft_print_nbr(va_arg(ap,int));
        count++;
    }
    else if(c == 'u'){
        ft_printint(va_arg(ap,int));
        count++;
    }
    else if(c == 'x' || c == 'X'){
        ft_print_hexa(va_arg(ap,unsigned int),c);
        count++;
    }
    else if(c == '%'){
        ft_print_char('%');
    }
    else{
        write(1,&c,1);
        count++;
    }
    return count;
}

int ft_printf(const char *format, ...){
    int count;
    va_list ap;

    va_start(ap,format);
    count = 0;
    while (*format)
    {
        if (*format=='%')
        {
            ft_print_format(*(++format),ap);
            count++;
            format++;
        }
        else{
            write(1,&format,1);
            count++;
            format++;
        }
    }
    va_end(ap);
    return count;
}

int main(void)
{
    ft_printf("%%");
    printf("\n");
    printf("%%");
    return 0;
}
