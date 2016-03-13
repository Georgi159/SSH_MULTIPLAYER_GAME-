#include <stdio.h>
#include <string.h>
#include "colurs.h"
#include "hgame.h" 
#include <stdlib.h>
#include <time.h>
#define FWIT 45
#define FLEN 171
#define FIELD_S ')'
#define FIELD_B 4
#define FIELD_C_S 10

int update();
int initialize_feld(char a,int b ,int c);
int comand();
int move(int com);
// int set_player(player pl);
int initialize_player(player pl);

unsigned long long tiks=59;
char feld[FWIT][FLEN];
char feldB[FWIT][FLEN];
char feldS[FWIT][FLEN];


void print_colurs()
{
	puts("");
	for (int i = 0; i < 255; ++i)
	{
		char a[40]={0};
		sprintf(a , "%s%d%c" , "\033[48;5;" , i , 'm');
		printf("%s%3d ",a,i );
		if (i%16==0)
		{
			printf("%s\n","\033[33m");			
		}
	}
	puts("");
}

int main()
{	

//	 print_colurs();

	system("clear");
	//initialize_feld
	printf("\n");
	system("tput civis"); 
 	//printf("%s", ACB_RESET);
 //	printf("%s", ACC_RESET);
	
	initialize_feld(FIELD_S, FIELD_B , FIELD_C_S);

	// time1=time(NULL);
	// time2=time(NULL);

	player players[2];
	memset(players, 0 ,sizeof(player));
	initialize_player(players[0]);


	while(1)
	{
		update();

		sleep(0.35);
		//printf("%s%s ssssss\n",ACC_RED, ACB_GREEN );
		
		move(comand());
		tiks++;
	}

	
	return 0;
}


/*for (int i = 0; i < FWIT; ++i)
		{
			for (int l = 0; l < FLEN; ++l)
			{
				printf("%d", feldS[i][l]);
			}
			printf("\n");
		}
*/


int initialize_player(player pl)
{	
	// left a rigth d up 1 down 2
	//printf("%s ", "Input player name:");
	//scanf("%s", pl.name);
	//printf("%s ", "Input colur name:");
	//scanf("%1d", &pl.colur_s);
	 pl.colur_s=FIELD_B;
	 pl.colur_b=16;
	do
	{
		pl.x=rand()%FWIT;
		pl.y=rand()%FLEN;
	}while(feld[pl.x][pl.y]!= FIELD_S);

	feld[pl.x][pl.y]='0';
	feldS[pl.x][pl.y]=pl.colur_s;
	feldB[pl.x][pl.y]= pl.colur_b+1;

	return 0;

}



void game_exit()
{
	for (int i = 0; i < FWIT; ++i)
	{
		printf("%s", M_DOWN);
	}
	printf("%s", ACB_RESET );
	printf("%llu\n",tiks );
	system("tput cnorm"); 
	exit(0);
}

int move(int com)
{
	if (com==0) return 0;

	switch (com)
	{
		//case 2:  feld[x++][y]='#';feldB[x++][y]='5';feldS[x++][y]='5';
	}

	return 0;
}

int comand()
{
	int red=0;
	if (kbhit())
	{
		char a=getch();

		switch(a)
		{// left a rigth d up 1 down 2
			case 'w': red=1 ;
			case 's': red=2 ;
			case 'a': red=3 ;
			case 'd': red=4 ;
			case 'q': game_exit() ;

		}
	}
	sleep(0.1);

	return red;
}

int update()
{

	for (int i = 0; i < FWIT; ++i)
	{
		
			printf("%s", M_UP);
	}
	for (int l = 0; l < FLEN; ++l)
	{
		printf("%s", M_LEFT);
	}

	char sul_cus1[60]={0};
	//char sul_cus2[14]={0};
	
	for (int i = 0; i < FWIT; ++i)
	{
		for (int l = 0; l < FLEN; ++l)
		{	
			printf("%s", ACB_RESET );


			
			
			//sprintf(sul_cus1,"%s%d%s%d",CUSTOM_C_S,feldS[i][l],CUSTOM_C_B,feldB[i][l]);

			sprintf(sul_cus1,"%s%d%c%s%d%c",CUSTOM_C_S,feldS[i][l],'m',CUSTOM_C_B,feldB[i][l],'m');
		//	printf("%s%s",sul_cus2,sul_cus1 );
			

			printf("%s%c",sul_cus1, feld[i][l]);

			printf("%s", ACC_RESET );

			sleep(0.1);
			
			//printf("%d %d\n", feldS[i][l],feldB[i][l]);
			//pause();
			
		}
	printf("\n");
	}

	printf("%s", ACC_RESET );



	return 0;
}


int initialize_feld(char a,int b ,int c)
{
	for (int i = 0; i < FWIT; ++i)
	{
		for (int l = 0; l < FLEN; ++l)
		{
			feld[i][l]=a;
			feldB[i][l]=b;
			feldS[i][l]=c;
		}
	}
	return 0;

}
