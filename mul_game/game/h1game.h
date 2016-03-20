#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hgame.h" 

#include "colurs.h"
#define FWIT 30
#define FLEN 30
#define FIELD_S ' '
#define FIELD_B 4
#define FIELD_C_S 3

unsigned long long tiks=59;
char feld[FWIT][FLEN];
int feldB[FWIT][FLEN];
int feldS[FWIT][FLEN];
	time_t a=0,b=0 ;


 
int spawn_food();

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
//int print_player(player *pl);

void print_ch(char ch,int col_s,int col_b)
{
	printf("%s%dm%s%dm%c",CUSTOM_C_S,col_s, CUSTOM_C_B,col_b,ch);

}

void set_player(player *a)
{
	feld[a->y][a->x]=a->player_sim;
	feldS[a->y][a->x]=a->colur_s;
	feldB[a->y][a->x]=a->colur_b;



}

void clear()
{
system("clear");	printf("\033[3J");


}


