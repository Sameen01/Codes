#include <stdio.h>
#include <string.h>

int wordCount(char *arr, int size);
char* pair_Word(char *string_arr, int size, int *index);
void word_sort(char **string_arr, int row);
void printArray(char **arr, int row);

int main()
{
	const int sentence_size = 100;
	char *sentence = (char*)malloc(sentence_size * sizeof(char));
	
	printf("Enter a Sentence: ");
	gets(sentence);
	printf("\n");
	
	int count = wordCount(sentence, strlen(sentence));
	
	char **word = (char**)malloc(count * sizeof(char *));
	
	int i;
	int index = 0;
	const int word_size = 30;
	for(i = 0; i < count; ++i)
	{
		*(word + i) = pair_Word(sentence, strlen(sentence), &index);
	}
	word_sort(word, count);
	printArray(word, count);
	return 0;
}

int wordCount(char *arr, int size)
{
	int i;
	int count = 0;
	int flag = 0;
	for(i = 0; i < size; ++i)
	{
		if(*(arr + i) == ' ')
		{
			if(flag == 0)
			{
				++count;
			}
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	if(arr[0] == ' ')
	{
		--count;
	}
	if(arr[size - 1] == ' ')
	{
		--count;
	}
	return count + 1;
}

char* pair_Word(char *string_arr, int size, int *index)
{
	int i;
	const int array_size = 30;
	char *str = (char*)malloc(array_size * sizeof(char));
	
	for(i = *index; i < size; ++i)
	{
		if(string_arr[i] == ' ')
		{
			
		}
		else
		{
			break;
		}
	}
	
	int j = 0;
	for(i; i < size; ++i)
	{
		if(string_arr[i] == ' ')
		{
			break;
		}
		*(str + j) = string_arr[i];
		++j;
	}
	
	*(str + j) = '\0';
	*index = i;
	
	return str;
}

void word_sort(char **string_arr, int row)
{
	int i, j;
	for(i = 0; i < row; ++i)
	{
		for(j = 0; j < row - 1; ++j)
		{
			int a = strlen(*(string_arr + j));
			int b = strlen(*(string_arr + j + 1));
			if(a < b)			
			{
				char *temp_word = *(string_arr + j);
				*(string_arr + j) = *(string_arr + j + 1);
				*(string_arr + j + 1) = temp_word;	
			}
		}
	}
}
void printArray(char **arr, int row)
{
	int i;
	for(i = 0; i < row; ++i)
	{
		printf("%s\n", *(arr + i));
	}
}
