printf("\033[7;0m\033[0m");		
			sprintf(sul_cus1,"%s%d%c%s%d%c",CUSTOM_C_S,feldS[i][l],'m',CUSTOM_C_B,feldB[i][l],'m');
			printf("%s%c",sul_cus1, feld[i][l]);
			printf("\033[7;0m\033[0m");














		int move_player(int com, player *a)
{
	(*a).last_comand=(*a).comand;
	(*a).comand=com;

	//feld [(*a).x][(*a).y]=FIELD_S;
	//feldS[(*a).x][(*a).y]=FIELD_C_S;
	//feldB[(*a).x][(*a).y]=FIELD_B;


	switch (com)
	{// left 3 rigth 4 up 1 down 2
			case 1: (*a).y++; feldS[(*a).x][(*a).y]=(*a).colur_s; feldS[(*a).x][(*a).y]=(*a).colur_b; return 1; break;
			case 2: (*a).y--; feldS[(*a).x][(*a).y]=(*a).colur_s; feldS[(*a).x][(*a).y]=(*a).colur_b; return 1; break;
			case 3: (*a).x++; feldS[(*a).x][(*a).y]=(*a).colur_s; feldS[(*a).x][(*a).y]=(*a).colur_b; return 1; break;
			case 4: (*a).x--; feldS[(*a).x][(*a).y]=(*a).colur_s; feldS[(*a).x][(*a).y]=(*a).colur_b; return 1; break;
	}
	return 0;
	//update();
	
}


	for (int i = 0; i < num_of_players; ++i)
	{
			print_player(&players[i]);
	}



int print_player(player *pl)
{
	FULL_RESET
	for (int i = 0; i < FWIT-(*pl).x; ++i)
	{
		printf("%s",M_UP );
		for (int l = 0; l < FLEN-(*pl).y; ++l)
		{

			if ((*pl).x==l  && (*pl).y==i)
			{
				print_ch((*pl).player_sim,(*pl).colur_s,(*pl).colur_b);
				FULL_RESET
			}
		printf("%s", M_LEFT);

		}	
	}
	return 0;
}




void set_player(player *a)
{
	feld[a->y][a->x]=a->player_sim;
	feldS[a->y][a->x]=a->colur_s;
	feldB[a->y][a->x]=a->colur_b;



}




/*
	for (int i = 0; i < FWIT; ++i)
	{
		printf("%s", M_UP);
	}
	for (int l = 0; l < FLEN; ++l)
	{
		printf("%s", M_LEFT);
	}*/


		// static struct termios old, new;

// /* Initialize new terminal i/o settings */
// void initTermios(int echo) 
// {
//   tcgetattr(0, &old); /* grab old terminal i/o settings */
//   new = old; /* make new settings same as old settings */
//   new.c_lflag &= ~ICANON; /* disable buffered i/o */
//   new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
//   tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
// }

//  Restore old terminal i/o settings 
// void resetTermios(void) 
// {
//   tcsetattr(0, TCSANOW, &old);
// }

// /* Read 1 character - echo defines echo mode */
// char getch_(int echo) 
// {
//   char ch;
//   initTermios(echo);
//   ch = getchar();
//   resetTermios();
//   return ch;
// }

// /* Read 1 character without echo */
// char getch(void) 
// {
//   return getch_(0);
// }

// /* Read 1 character with echo */
// char getche(void) 
// {
//   return getch_(1);
// }

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}




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
#define FOOD '?'
unsigned long long tiks=59;
char feld[FWIT][FLEN];
int feldB[FWIT][FLEN];
int feldS[FWIT][FLEN];
	time_t a=0,b=0 ;


 
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
//int print_player(player *pl);

void print_ch(char ch,int col_s,int col_b)
{
	printf("%s%dm%s%dm%c",CUSTOM_C_S,col_s, CUSTOM_C_B,col_b,ch);

}


void clear()
{
	system("clear");	
	printf("\033[3J");
}


