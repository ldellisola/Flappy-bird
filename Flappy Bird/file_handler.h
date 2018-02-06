#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "string_handler.h"

#define NAME_LENGHT (100)

// Inicia una lista de strings almacenados en un archivo. Si no existe un archivo con
// ese nombre, entonces la funcion "Count_Lines" lo crea.
char ** init_list(char * file);

// Destruye a una lista creada. Es necesario hacerlo cada vez que se crea una lista
void destroy_list(char ** list);

// Agrega una linea nueva de texto a un archivo existente y devuelve la lista correspondiente
// a ese archivo
char ** add_line(char * name, char * file, char ** list);

// Elimina una linea con un determinado texto (name) de un archivo y devuelve una lista al archivo
// modificado
char ** remove_line(char * name, char * file, char ** list);

// Copia la primer linea de un archivo a un arreglo.
void read_first_line(char * file, char * dest, int max_lenght);

// Escribe la primer linea de un archivo, si este no existe, entonces lo crea
void write_first_line(char * string, char * file);

// Cuentas las lineas que tiene un archivo, y si no existe, lo crea
int count_lines(char * file);

//Crea un archivo en un determinado directorio
void create_file(char * file, char * path);

// Elimina un archivo en un determinado directorio
void delete_file(char * file, char * path);