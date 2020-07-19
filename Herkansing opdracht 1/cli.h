#include <stdbool.h> 
typedef void (*command_function)(int, char *);

typedef struct command_node_tag
{
	char* name;
	command_function function;
	char* help_text;
	struct command_node_tag * next;
} commando_node;

typedef struct
{
	char* name;
	command_function function;
    char* help_text;
} commando;

typedef struct {
    int value;
	char* color;
    char* command;
    bool help;
    bool valid;
    bool exact;
} parameters;

typedef struct {
    int count;
    char *text;
} options;

parameters command_parameters(char *input);
bool cli_read(commando_node* commands, char *input);
void execute_commando(commando_node* origin, parameters params);
int int_value(char *value);
int text_value(char *value);
int set_led_status(char *color, char *value);
void help(int value, char *command);
bool should_exit(char *value);
void exit_cli(int value, char *message);
void leds(int value,  char *message);
void led(int value, char *color);
commando_node * create_commando(char *name, command_function function, char *help_text);
void commando_add(commando_node **first_command, commando_node *new_command);
void sort_commandos(commando_node **start_commando);
void print_help(commando_node *origin, parameters params);
options command_options(commando_node *origin, char *text);