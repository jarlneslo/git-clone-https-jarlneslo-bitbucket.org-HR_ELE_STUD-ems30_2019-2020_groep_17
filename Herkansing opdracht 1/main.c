#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <pthread.h>

#include "termios.h"
#include "cli.h"
#define WORD_LENGTH 20

static struct termios term;

static void set_stdin_to_raw(void) { //i.p.v. de zogenaamde cooked mode (begin)

	tcgetattr(0, &term);
	struct termios raw = term;
	raw.c_lflag &= ~ICANON;
	raw.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &raw);
	setvbuf(stdout, NULL, _IONBF, 0);
}

static void restore_stdin(void)	{ //terugkeer naar de cooked mode (eind)
	tcsetattr(0, TCSANOW, &term);
}

commando commandos[]=
{
		{"nul"	, &leds, 	"zet de decimale waarde 0 op de leds.\n"},
		{"een"	, &leds,  	"zet de decimale waarde 1 op de leds.\n"},
		{"twee"	, &leds, 		"zet de decimale waarde 2 op de leds.\n"},
		{"drie"	, &leds, 	"zet de decimale waarde 3 op de leds.\n"},
		{"vier"	, &leds, 	"zet de decimale waarde 4 op de leds.\n"},
		{"vijf"	, &leds, 	"zet de decimale waarde 5 op de leds.\n"},
		{"zes"	, &leds,  	"zet de decimale waarde 6 op de leds.\n"},
		{"zeven", &leds, 	"zet de decimale waarde 7 op de leds.\n"},

		{"led"	, &led,  "zet de naam en waarde op de led.\n\rHierbij kan er voor de naam gekozen worden uit: rood, geel of groen, met een waarde van 0 of 1."},
		{"leds"	, &leds,  		"zet de decimale waarde op de leds.\n\rHierbij kan er voor de waarden gekozen worden voor decimale getallen van 0 t/m 7."},
		{"rood"	, &led, 		"zet een waarde op de rode led.\n\rHierbij kan er voor de waarden gekozen worden tussen 0 of 1.\n"},
		{"geel"	, &led,		"zet een waarde op de rode led.\n\rHierbij kan er voor de waarden gekozen worden tussen 0 of 1.\n"},
		{"groen", &led, 		"zet een waarde op de rode led.\n\rHierbij kan er voor de waarden gekozen worden tussen 0 of 1.\n"},
		{"help"	, &help,		"geeft helptekst voor <command>.\n"},
		{"stop"	, &exit_cli,  	"beeindigt het programma.\n"},
		{"exit"	, &exit_cli,  	"beeindigt het programma.\n"},
		{"einde", &exit_cli,  	"beeindigt het programma.\n"},
		{"end"	, &exit_cli,  	"beeindigt het programma.\n"},
		{"quit"	, &exit_cli,  	"beeindigt het programma.\n"}

};



int main(int argc, char *argv[]) {
    set_stdin_to_raw();
	char received_command[WORD_LENGTH];
    commando_node *  origin, *iter; //= start_list(void); maken van de Dynamische lijst
    origin = create_commando(commandos[0].name, commandos[0].function, commandos[0].help_text);

    for (int i = 1; i < sizeof(commandos)/sizeof(commandos[0]); i++)
	{
        commando_node * next_command;
        next_command = create_commando(commandos[i].name, commandos[i].function,  commandos[i].help_text);
        commando_add(&origin, next_command);
    }

    // iter = origin;
    // int j = 0;
    // while (iter)
    // {
    //     j++;
    //     printf("Printing sorted list: element %d = %s\n",j,iter->help_text);
    //     iter = iter->next;
    // }
    while(1)
	{
		cli_read(origin, received_command);
	}
	restore_stdin();
    return EXIT_SUCCESS;
}