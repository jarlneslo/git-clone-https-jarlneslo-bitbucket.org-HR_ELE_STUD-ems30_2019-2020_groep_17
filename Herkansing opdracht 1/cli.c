#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"
#define WORD_LENGTH 20

int int_value(char *value)
{
    if (strcmp(value, "0") == 0)
    {
        return 0;
    }
    else if (strcmp(value, "1") == 0)
    {
        // do something else
        return 1;
    }
    else if (strcmp(value, "2") == 0)
    {
        // do something else
        return 2;
    }
    else if (strcmp(value, "3") == 0)
    {
        // do something else
        return 3;
    }
    else if (strcmp(value, "4") == 0)
    {
        // do something else
        return 4;
    }
    else if (strcmp(value, "5") == 0)
    {
        // do something else
        return 5;
    }
    else if (strcmp(value, "6") == 0)
    {
        // do something else
        return 6;
    }
    else if (strcmp(value, "7") == 0)
    {
        // do something else
        return 7;
    }
    return -1;
}

int text_value(char *value)
{
    if (strcmp(value, "nul") == 0)
    {
        return 0;
    }
    else if (strcmp(value, "een") == 0)
    {
        // do something else
        return 1;
    }
    else if (strcmp(value, "twee") == 0)
    {
        // do something else
        return 2;
    }
    else if (strcmp(value, "drie") == 0)
    {
        // do something else
        return 3;
    }
    else if (strcmp(value, "vier") == 0)
    {
        // do something else
        return 4;
    }
    else if (strcmp(value, "vijf") == 0)
    {
        // do something else
        return 5;
    }
    else if (strcmp(value, "zes") == 0)
    {
        // do something else
        return 6;
    }
    else if (strcmp(value, "zeven") == 0)
    {
        // do something else
        return 7;
    }
    return -1;
}

int set_led_status(char *color, char *value)
{
    return -1;
}

void help(int value, char *command)
{
}

bool should_exit(char *value)
{
    if (strcmp(value, "stop") == 0)
    {
        return true;
    }
    else if (strcmp(value, "exit") == 0)
    {
        // do something else
        return true;
    }
    else if (strcmp(value, "einde") == 0)
    {
        // do something else
        return true;
    }
    else if (strcmp(value, "end") == 0)
    {
        // do something else
        return true;
    }
    else if (strcmp(value, "quit") == 0)
    {
        // do something else
        return true;
    }

    return false;
}

void leds(int value, char *color)
{

}

void led(int value, char *color)
{
}

void exit_cli(int value, char *message)
{
    exit(0);
}

void sort_commandos(commando_node **start_commando)
{
    commando_node *list;
    char *tmp_name;
    char *tmp_help_text;
    command_function tmp_function;
    list = *start_commando;

    if (list)
    {
        while (list && list->next)
        {
            if (strcmp(list->name, list->next->name) > 0)
            {
                tmp_name = list->name;
                list->name = list->next->name;
                list->next->name = tmp_name;

                tmp_help_text = list->help_text;
                list->help_text = list->next->help_text;
                list->next->help_text = tmp_help_text;

                tmp_function = list->function;
                list->function = list->next->function;
                list->next->function = tmp_function;
            }
            list = list->next;
        }
    }
}

// This function will add 'newElement' at the end of the list 'alst'
void commando_add(commando_node **first_command, commando_node *new_command)
{
    commando_node *conductor; /* This will point to each node as it traverses the list */

    if (new_command)
    {
        new_command->next = *first_command;
        *first_command = new_command;
        sort_commandos(first_command);
    }
    else
    {
        printf("NULL entry\n");
    }
}

void print_help(commando_node *origin, parameters params)
{
    commando_node *last = origin;
    int first = 0;
    char *compare = NULL;
    int count_chars = strlen(params.command);
    if (params.color)
    {
        while (last != NULL)
        {
            if (params.color)
            {
                int result = strcmp(last->name, params.color);
                if (result == 0)
                {
                    printf("Commando \"%s <command>\": %s", last->name, last->help_text);
                    //				push(history, last->name);
                    break;
                }
            }
            last = last->next;
            first++;
        }
    }
    else
    {
        char *opties = NULL;

        while (last != NULL)
        {
            if (opties == NULL)
            {
                opties = malloc(200);
                sprintf(opties, "%s", last->name);
            }
            else
            {
                sprintf(opties, "%s, %s", opties, last->name);
            }

            last = last->next;
        }
        printf("Beschikbare commando's: %s\n", opties);
        printf("Type \"help <command>\" voor meer informatie over een specifieke commando\n");
    }
}

void execute_commando(commando_node *origin, parameters params)
{
    commando_node *commando;
    if (origin == NULL)
    {
        printf("Empty command list have been provided");
        return;
    }
    
    if (strcmp(params.command, "help") == 0){
        print_help(origin, params);
        return;
    }
    if (params.exact == 1)
    {
        if (!params.valid)
        {
            printf("Onbekende commando \"%s\"\n", params.command);
            return;
        }
        commando_node *last = origin;
        while (last != NULL)
        {
            int result = strcmp(last->name, params.command);
            if (result == 0)
            {
                if (last->function)
                {
                    last->function(params.value, params.color);
                    printf("\n");
                }
                //				push(history, last->name);
                break;
            }
            last = last->next;
        }
    }
}

options command_options(commando_node *origin, char *text){
    options found_options;
    
    commando_node *last = origin;
    int found = 0;
    char *opties = NULL;
    char *compare = NULL;
    
    int count_chars = strlen(text);

    while (last != NULL)
    {
        compare = malloc(count_chars);
        strncpy(compare, last->name, count_chars);
        compare[count_chars] = '\0';
        if (strcmp(compare, text) == 0)
        {
            found++;
            if (opties == NULL)
            {
                opties = malloc(200);
                found_options.text = last->name;
                sprintf(opties, "%s", last->name);
            }
            else
            {
                sprintf(opties, "%s, %s", opties, last->name);
            }
        }

        last = last->next;
    }
    if (found == 0)
    {
        printf("Er zijn geen opties gevonden");
        found_options.count = 0;
        found_options.text = "";
    }
    else if (found == 1)
    {
        found_options.count = 1;
    }
    else
    {
        found_options.count = found;
        found_options.text = opties;
    }
    return found_options;
}

commando_node *create_commando(char *name, command_function function, char *help_text)
{
    commando_node *command;

    command = (commando_node *)malloc(sizeof(commando_node));

    // printf("Add:command= %s\n",name);

    if (command)
    {
        command->name = name;
        command->function = function;
        command->help_text = help_text;
        command->next = NULL;
    }

    return (command);
}

bool cli_read(commando_node *commandos, char *commando_uit)
{
    char c;
    int i = 0;
    char zinnetje[WORD_LENGTH];

    for (i = 0; i < sizeof(zinnetje) / sizeof(zinnetje[0]); i++)
    {
        zinnetje[i] = '\0';
    }
    i = 0;
    commando_node commando;
    int tabs = 0;
    while (1) // 0 tm 18 letters en de 19e wordt gereserveerd voor '\0'
    {
        c = getchar(); //normaal getchar(); maar voor de test is het stub_getletter()

        if (c == '\177')
        {
            printf("\x1b[D \x1b[D");
            printf("\x1b[D \x1b[D");
            i--;
        }

        //als hij op zijn laatste plekje van de buffer zit en input geen enter is
        else if (i >= (WORD_LENGTH - 1) && (c != '\n'))
        {
            printf("\x1b[D \x1b[D");
        }
        else
        {
            //als c een ascii waarde heeft van een letter(hoofd- of kleine letter)
            if (((65 <= c) && (c <= 90)) || ((97 <= c) && (c <= 122)) || (c == 32) || ((48 <= c) && (c <= 57)))
            {
                zinnetje[i] = c;
                i++;
            }
            else if (c == '\n') // als enter wordt ingedrukt, splits eventeel commando en stuur door naar uitvoerende functie
            {

                zinnetje[i] = '\0';
                parameters params = command_parameters(zinnetje);
                params.exact = true;
                execute_commando(commandos, params);
                break;
            }
            else if (c == '\t') //als tab wordt ingedrukt, zoek dan bijbehorende commandos
            {
                //				zinnetje[i] = '\t';
                i++;
                zinnetje[i] = '\0';

                parameters params = command_parameters(zinnetje);
                params.exact = false;

                options available_options = command_options(commandos, zinnetje);
                tabs++;
                if(available_options.count == 1){
                    params.command = available_options.text;
                    params.exact = true;
                    params.valid = true;
                    int j;
                    int end = strlen(params.command);
                    int typed_count = strlen(zinnetje);
                    int tabremove = 8- typed_count;
                    for(int k = 0; k< tabremove; k++){
                        printf("\x1b[D \x1b[D");
                    }
                    for(j = i-1; j < end;j++){
                        printf("%c", params.command[j]);
                    }
                    execute_commando(commandos, params);
                    tabs = 0;
                    printf("\n");
                    break;

                }
                if(tabs == 2){
                    if(available_options.count == 0){

                    }
                    if(available_options.count > 1){
                        printf("Er zijn %d opties: %s\n",available_options.count,  available_options.text);
                    }
                    tabs = 0;
                    printf("\n");
                    break;
                }
            }
            // else if (c == 43)
            // {
            //     navigeer_history(origin, history, 1);
            //     break;
            // }
            // else if (c == 45)
            // {
            //     navigeer_history(origin, history, -1);
            //     break;
            // }
            else
            {
                //als het geen letter is, negeer het
                printf("\x1b[D \x1b[D");
            }
        }
    }

    zinnetje[i] = '\0';

    return true;
}

parameters command_parameters(char *input)
{
    parameters params;
    params.color = NULL;
    params.command = NULL;
    params.exact = true;
    params.value = -1;
    params.valid = false;
    params.help = false;
    char *compare = NULL;

    if (input != NULL)
    {
        int size_input = strlen(input);
        compare = malloc(size_input);
        strncpy(compare, input, size_input);
        compare[size_input] = '\0';

        char delim[] = " ";
        char *ptr = strtok(compare, delim);
        if (ptr == NULL)
        {
            return params;
        }
        int command_count = 1;
        params.command = ptr;
        if (strcmp(params.command, "help") == 0)
        {
            params.help = true;
            params.valid = true;
            params.color = NULL;
        }
        if (should_exit(params.command))
        {
            params.valid = true;
            params.color = "";
            return params;
        }
        int text_to_num = text_value(ptr);
        if (text_to_num > -1 && text_to_num < 8)
        {
            params.value = text_to_num;
            params.valid = true;
        }
        while (ptr != NULL)
        {
            ptr = strtok(NULL, delim);
            if (ptr == NULL)
            {
                break;
            }
            if (command_count == 1)
            {
                if (strcmp(params.command, "leds") == 0)
                {
                    params.value = int_value(ptr);
                }
                else if (strcmp(params.command, "rood") == 0)
                {
                    // do something else
                    params.value = int_value(ptr);
                    params.valid = params.value == 0 || params.value == 1;
                    params.color = params.command;
                }
                else if (strcmp(params.command, "geel") == 0)
                {
                    // do something else
                    params.value = int_value(ptr);
                    params.valid = params.value == 0 || params.value == 1;
                    params.color = params.command;
                }
                else if (strcmp(params.command, "groen") == 0)
                {
                    // do something else
                    params.value = int_value(ptr);
                    params.valid = params.value == 0 || params.value == 1;
                    params.color = params.command;
                }
                else if (strcmp(params.command, "help") == 0)
                {
                    // do something else
                    params.color = ptr;
                }
                else if (strcmp(params.command, "led") == 0)
                {
                    // do something else
                    params.color = ptr;
                }
            }
            else if (command_count == 2)
            {
                if (strcmp(params.command, "led") == 0)
                {
                    // do something else
                    params.value = int_value(ptr);
                    params.valid = (params.value == 0 || params.value == 1) && ((strcmp(params.color, "rood") == 0) || (strcmp(params.color, "groen") == 0) || (strcmp(params.color, "geel") == 0));
                }
            }
            command_count++;
        }
    }

    return params;
}