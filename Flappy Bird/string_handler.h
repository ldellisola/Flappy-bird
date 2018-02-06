#pragma once
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include "math_handler.h"
// It fills an array with zeros
//
// - char * array: It is the array to be cleaned
// int lenght : it is the lenght of the array
void clean_array(char * array, int lenght);

// It removes a single char from an array.
// - char * string : the string that has toe char to be removed
// - char remove : the char to be removed. 
void remove_char(char * string, char remove);

// it checks if a string has any uppercase chars and transforms it to lowercase
//
// char * string : the string to be modified.
// int lenght : the lenght of the string.
void minimizer(char * string, int lenght);

// it counts the ammount of chars before a given char in a string. To count the total lenght of the string, final_char should be 0.
//
// - char * string : The string we want to find the lenght of
// - char final_char : it is the char up until where it will count the ammount of letters
int letter_counter(char * string, char final_char);

// It loads a given number of strings to an array of strings
char ** load_strings(int number_of_strings, ...);

// It transforms an string into a unsigned integer 
//
// - char * string : the string to be transformed
int convert_to_int(char * string);

// It transforms an array of strigns to an array of integers
//
// - char ** list : it is the array of string to be transformed
// - int size : it is the ammount of strings to be transformed
int * transform_list_to_numbers(char ** list, int size);

// It transforms an unsigned integer into a string
//
// - int numero : The number to be transformed
// - char * dest : The string where the number will be stored
// - int max_lenght : it is the max lenght of the string.
void convert_to_string(int numero, char * dest, int max_lenght);

// It destroys a string. This must be done for every string initializated with any of my functions!
void destroy_string(char * string);

// It destroys an array of int. This must be done for every string initializated with any of my functions!
void destroy_int_array(int * array);

// It checks if any given string is in an array of strings
//
// - char * string : The string we want to see if it is in the array.
// - char ** list : The array of string where we will search for the string.
bool is_string_in_list(char * string, char ** list);

// It checks if a given string is an unsigned integer
//
// - char * string : It is the string to be checked
bool is_string_a_number(char * string);

// It checks of two strings are equal
bool are_strings_equal(char * string_a, char * string_b);

// It checks if all strings in an array are unsigned integers
//
// - char ** list : It is the array of strings to be checked.
// - int ammount_of_strings : it is the ammount of strings in the array
bool are_all_strings_in_list_numbers(char ** list, int ammount_of_strings);

// It appends two strings.
//
// - const char * first: It is the string that will come first in the appended string
// - char * last : It is the string that will come second in the appended string
char * append_string(const char * first, char * last);