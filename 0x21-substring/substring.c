#include "substring.h"
/**
 * cmp_values - Function that compare two values
 * @a: first value
 * @b: second value
 * Return: substraction
 **/
int cmp_values(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
/**
 * check_words - Function that chek if all words are continous
 * @aux_index: array with index for ever word
 * @wordlen: word size
 * @idx_len: aux_index size
 * Return: index firt word or zero
 **/
int check_words(int *aux_index, int wordlen, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_index[i + 1] - aux_index[i]  != wordlen)
			return (0);
	}
	return (1);
}
/**
 * search_word - Function that search words in string
 * @s: string base
 * @words: array of words to search in the string
 * @nb_words: number of words
 * Return: array with size of substring for every word, otherwise NULL
 **/
int *search_word(char const *s, char const **words, int nb_words)
{
	int *aux_index, i, j;
	char *aux;
	int len;

	aux_index = malloc((sizeof(int) * nb_words));
	if (!aux_index)
		return (NULL);
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
		{
			free(aux_index);
			return (NULL);
		}
		len = (int)strlen(aux);
		for (j = 0; j < i; j++)
		{
			if (len == aux_index[j])
			{
				aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
				if (!aux)
				{
					free(aux_index);
					return (NULL);
				}
				len = (int)strlen(aux);
				aux_index[i] = len;
				continue;
			}
		}
		aux_index[i] = len;
	}
	return (aux_index);
}
/**
 * find_substring - Function that search_word words in string
 * @s: string base
 * @words: array of words to searh in the string
 * @nb_words: number of words
 * @n: return size
 * Return: array with index for every word or NULL
 *
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *index, *aux_index, wordlen, j, diff, s_len, f_indx, tmp;

	*n = 0;
	wordlen = (int)strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		aux_index = search_word(s, words, nb_words);
		if (!aux_index)
			break;
		qsort(aux_index, nb_words, sizeof(int), cmp_values);
		f_indx = check_words(aux_index, wordlen, nb_words);
		tmp = aux_index[nb_words - 1];
		free(aux_index);
		if (f_indx == 1)
		{
			diff = s_len - tmp;
			if (*n == 0 || diff != index[*n - 1])
			{
				if (*n == 0)
				{
					index = malloc((sizeof(int)));
					if (!index)
						return (NULL);
				}
				else
					index = realloc(index, sizeof(int) * (*n + 1));
				index[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	if (*n == 0)
		return (NULL);
	return (index);
}
