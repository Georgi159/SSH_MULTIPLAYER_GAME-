#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "colurs.h"
#include "hgame.h" 
#define FWIT 30
#define FLEN 30
#define FIELD_S ' '
#define FIELD_B 4
#define FIELD_C_S 3

void game_exit();
int update();
int initialize_feld(char a,int b ,int c);
int comand();
int move(int com);
int initialize_player(player *pl);
int move_player(int com, player *a);
void print_colurs();
int line_len();
void print_colurs();
