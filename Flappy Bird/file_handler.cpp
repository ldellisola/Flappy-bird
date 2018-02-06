#include "file_handler.h"

char ** init_list(char * file)
{
	FILE * product_list = NULL;

	int items, item_loader, name_loader = 0;

	items = count_lines(file);

	char ** complete_list = (char **) malloc((1 + items) * sizeof(char *));

	for (item_loader = 0; item_loader < items; ++item_loader)
	{
		complete_list[item_loader] = (char *) malloc(NAME_LENGHT * sizeof(char));
		clean_array(complete_list[item_loader], NAME_LENGHT);
	}
	complete_list[items] = NULL;


	if (product_list = fopen(file, "r"))
	{
		do
		{
			fgets(complete_list[name_loader], NAME_LENGHT, product_list);
			++name_loader;
		} while (complete_list[name_loader - 1] != NULL);
		fclose(product_list);
	}
	else
		printf("ERROR\n");

	for (item_loader = 0; item_loader < items; ++item_loader)
		remove_char(complete_list[item_loader], '\n');
	return complete_list;
}

void destroy_list(char ** list)
{
	int counter;
	for (counter = 0; list[counter] != NULL; ++counter)
		free(list[counter]);
	free(list);
}

int count_lines(char * file)
{
	int lines = 0;
	char character;
	FILE * document = NULL;

	if ((document = fopen(file, "r")))
	{
		while ((character = getc(document)) != EOF)
			if (character == '\n')
				++lines;
	}
	else
	{
		document = fopen(file, "w");
		while ((character = getc(document)) != EOF)
			if (character == '\n')
				++lines;
	}
	++lines;
	fclose(document);
	return lines;

}

char ** add_line(char * name, char * file, char ** list)
{
	FILE * document = NULL;
	char * name_local = (char *) malloc(100 * sizeof(char));
	strcpy(name_local, name);

	if (document = fopen(file, "a"))
	{
		fputs(name_local, document);
		fclose(document);
	}

	destroy_string(name_local);
	destroy_list(list);
	return init_list(file);
}

char ** remove_line(char * name, char * file, char ** list)
{
	FILE * document = NULL;
	FILE * temp_doc = NULL;
	char name_local[100];
	char buffer[100];
	int line = -1, counter;
	strcpy(name_local, name);

	if (document = fopen(file, "r"))
	{
		do
		{
			clean_array(buffer, 100);
			fgets(buffer, 100, document);
			remove_char(buffer, '\n');
			++line;
		} while (strcmp(buffer, name_local));
		rewind(document);

		if (temp_doc = fopen("temp", "w+"))
		{
			for (counter = 0; counter<line; ++counter)
			{
				if (fgets(buffer, 100, document) != NULL)
					fprintf(temp_doc, "%s", buffer);
			}

			fgets(buffer, 100, document);  // para borrar la linea que no se quiere

			while (fgets(buffer, 100, document))
			{
				fprintf(temp_doc, "%s", buffer);
			}
		}
	}
	fclose(document);
	fclose(temp_doc);
	remove(file);
	rename("temp", file);
	destroy_list(list);
	return init_list(file);
}

void read_first_line(char * file, char * dest, int max_lenght)
{

	FILE * document = NULL;

	if (!(document = fopen(file, "r"))) // fopen
	{
		create_file(file, "");
		document = fopen(file, "r");
	}

	fgets(dest, max_lenght, document);

	fclose(document);

}

void write_first_line(char * string, char * file)
{
	FILE * document = NULL;

	if ((document = fopen(file, "w+")))
	{
		fputs(string, document);

		fclose(document);
	}
}

void delete_file(char * file, char * path)
{
	char * item_path = append_string(path, file);
	remove(item_path);
	destroy_string(item_path);
}

void create_file(char * file, char * path)
{
	char * item_path = append_string(path, file);
	FILE * document = NULL;

	document = fopen(item_path, "w");
	fprintf(document, "0");
	fclose(document);
	destroy_string(item_path);
}