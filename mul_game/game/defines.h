//incl
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <time.h>
	#include <termios.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include "colurs.h"

//defs
	#define FWIT 30
	#define FLEN 30
	#define FIELD_S ' '
	#define FIELD_B 4
	#define FIELD_C_S 3
	#define FOOD '?'

//def STR
	typedef struct 
	{
		unsigned int x, y;
		char name[20];
		int comand, last_comand;
		int colur_s, colur_b;
		char player_sim;

	  int points;

	}player;

//def VAR
	int num_of_players=2;
	player players[2];
	int num_of_food=0;
	unsigned long long tiks=0;
	char feld[FWIT][FLEN];
	int feldB[FWIT][FLEN];
	int feldS[FWIT][FLEN];
	time_t a=0,b=0 ;


// def fun
	int spawn_food();
	int eat_food();

	void DONT_GET_OUT();

	void game_exit();
	int update();
	int initialize_feld(char a,int b ,int c);
	int comand();
	int move(int com);
	int initialize_player(player *pl);
	int move_player(int com, player *a);

	void print_colurs();
	int line_len();
	void print_ch(char ch,int col_s,int col_b);
	void clear();

