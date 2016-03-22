//incl
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <time.h>
	#include <termios.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include "colurs.h"
	#include <sys/shm.h>
	#include <sys/types.h>	
	#include <sys/ipc.h>
	#include <sys/mman.h>

//incl

//defs
	#define FWIT 30
	#define FLEN 50
	#define FIELD_S ' '
	#define FIELD_B 4
	#define FIELD_C_S 3
	#define FOOD '?'
	#define SPEED_MULTIPLIER 5
	#define FOOD_MULTIPLIER 60


	#define SH_M_S (sizeof(player)*num_of_players+(sizeof(int)*FWIT*FLEN)*2+(sizeof(char)*FWIT*FLEN)+3)

//defs

//def STR
	typedef struct 
	{
		unsigned int x, y;
		char name[20];
		int comand, last_comand;
		int colur_s, colur_b;
		char player_sim;
		int id;
	  	int points;

	}player;
//def STR

//def VAR
	int num_of_players=2;
	player *players;
	int num_of_food=0;
	unsigned long long tiks=0;
	char **feld;
	int **feldB;
	int **feldS;
	time_t a=0,b=0 ;


	key_t key=1234;

//def VAR


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

// def fun
