/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danperez <danperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:09:21 by danperez          #+#    #+#             */
/*   Updated: 2024/10/07 21:11:03 by danperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
    char    *dup;
    size_t  i;

    dup = malloc(ft_strlen(s) + 1);
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
/* 
int main()
{
    char    s[] = "Hello campus 42";
    char    *s2;

    s2 = ft_strdup(s);
    printf("Src: '%s'\nDuplicate: '%s'\n", s, s2);
    free(s2);
    return (0);
}
 */