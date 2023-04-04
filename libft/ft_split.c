/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osericol <osericol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:31:16 by osericol          #+#    #+#             */
/*   Updated: 2023/04/03 14:30:58 by osericol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// This function counts words
int count_words(char const *str, char c)
{
	int 	i;
	int counter;

	i = 0;
	counter = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
		{
			i++;
		}
		else
		{
			counter++;
			while(str[i] && str[i] != c)
			{
				i++;
			}
		}	
	}
	return (counter);	
}

// This function frees dinamicly allocated memory, we are decrementing i because of rule FILO (First In, Last Out)
char **free_memory(char **ptr, int i)
{
	while(i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

// This function puts splited words in array of strings 
char *put_words(char *word, char const *s, int i, int len)
{
	int j;

	j = 0;
	while(len > 0)
	{
		word[j] = s[i - len];
		j++;
		len--;
	}
	word[j] = '\0';
	return (word);
}

// This function should split words 
char **split_words(char const *s, char c, char **s2, int num_of_words)
{
	int i;
	int word;
	int word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while(word < num_of_words)
	{
		while(s[i] && s[i] == c)
		{
			i++;
		}
		while(s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if(!s2)
		{
			return (free_memory(s2, word));
		}
		put_words(s2[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	s2[word] = 0;
	return(s2);
}



//  Main function that is splitting words using delimiter char c
char **ft_split(char const *s, char c)
{
	char **s2;
	unsigned int number_of_words;

	if(!s)
	{
		return (0);
	}
	number_of_words = count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (number_of_words + 1));
	if(!s2)
	{
		return (0);
	}
    split_words(s, c, s2, number_of_words);
  return (s2);	
}


int main()
{
	char string[] = "Ciao sono Oscar e non sono capace a scrivere funzione da solo grazie per la vostra attenzione";
    char **res = ft_split(string,  ' ');	
    for (int i = 0; res[i]; i++) {
    printf("%s\n", res[i]);
}
	return(0);
}