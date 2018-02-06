#include <stdlib.h>

#include "string_handler.h"

void clean_array(char * array, int lenght)
{
	int counter;
	for (counter = 0; counter < lenght; ++counter)
		array[counter] = 0;
}

void remove_char(char * string, char remove)
{
	int counter = 0;
	char * pointer = NULL;
	double offset = 0;

	while ((pointer = strchr(string, remove)))
	{
		*pointer = 0;
		strcat(string, ++pointer);
	}
}

void minimizer(char * string, int lenght)
{
	int counter = 0;

	for (counter = 0; (counter < lenght) && (string[counter] != 0); ++counter)
		if ((string[counter] >= 'A') && (string[counter] <= 'Z'))
			string[counter] += 'a' - 'A';
}

int letter_counter(char * string, char final_char)
{
	int counter = 0;

	while (string[counter++] != final_char);

	return --counter;
}

char ** load_strings(int number_of_strings, ...)
{
	char ** strings = (char **) malloc((1 + number_of_strings) * sizeof(char *));
	int counter;
	va_list paramlist;
	va_start(paramlist, number_of_strings);

	for (counter = 0; counter<number_of_strings; ++counter)
		strings[counter] = va_arg(paramlist, char *);
	strings[number_of_strings] = NULL;

	va_end(paramlist);
	return strings;
}


int convert_to_int(char * string)
{
	int counter = 0;
	int number = 0;

	while (string[counter] != 0)
	{
		number = number * 10 + (string[counter] - '0');
		++counter;
	}
	return number;
}

void convert_to_string(int numero, char * dest, int max_lenght)
{
	int counter;
	int how_long, try_num = numero;

	clean_array(dest, max_lenght);

	for (how_long = 0; (try_num != 0); ++how_long)
	{
		try_num = try_num / 10;
	}

	try_num = numero;

	for (counter = how_long; counter != 0; --counter)
	{
		dest[how_long - counter] = ((try_num / power(10, counter - 1)) + '0');
		try_num = try_num - ((try_num / power(10, counter - 1)) * power(10, counter - 1));
	}
}

void destroy_string(char * string)
{
	free(string);
}

bool is_string_in_list(char * string, char ** list)
{
	int counter = 0;
	bool valid = false;
	char * temp = string;
	for (counter = 0; (list[counter] != NULL) && !valid; ++counter)
	{
		if (are_strings_equal(list[counter], temp))
			valid = true;
	}
	return valid;
}

bool is_string_a_number(char * string)
{
	int counter;
	bool valid = true;
	for (counter = 0; (string[counter] != 0) && (valid); ++counter)
	{
		if ((string[counter]<'0') || (string[counter]> '9'))
			valid = false;
	}
	return valid;
}

bool are_strings_equal(char * string_a, char * string_b)
{
	int counter, lenght_a = letter_counter(string_a, 0), lenght_b = letter_counter(string_b, 0);
	bool valid = true;

	if (lenght_a == lenght_b)
	{
		for (counter = 0; (string_a[counter] != 0) && valid; ++counter)
			if (string_a[counter] != string_b[counter])
				valid = false;
	}
	else
		valid = false;

	return valid;


}

char * append_string(const char * first, char * last)
{
	char * temp =(char *) malloc(200 * sizeof(char));

	strcpy(temp, first);
	strcat(temp, last);

	return temp;
}

bool are_all_strings_in_list_numbers(char ** list, int ammount_of_strings)
{
	int counter;
	bool valid = true;

	for (counter = 0; counter < ammount_of_strings; ++counter)
	{
		if (!is_string_a_number(list[counter]))
			valid = false;
	}

	return valid;
}

void destroy_int_array(int * array)
{
	free(array);
}

int * transform_list_to_numbers(char ** list, int size)
{
	int counter;
	int * array =(int *) malloc(sizeof(int) * size);
	for (counter = 0; counter < (size - 1); ++counter)
		array[counter] = convert_to_int(list[counter]);
	return array;
}