#include "h1game.h"

unsigned long long tiks=59;
char feld[FWIT][FLEN];
char feldB[FWIT][FLEN];
char feldS[FWIT][FLEN];
	time_t a=0,b=0;


int main()
{	

	a=time(0);
	system("clear");
	printf("\n");
	system("tput civis"); 
	
	initialize_feld(FIELD_S, FIELD_B , FIELD_C_S);

	player players[2];
	memset(players, 0 ,sizeof(player));
	initialize_player(&players[0]);

	update();

	while(1)
	{

		sleep(0.35);
		
		move_player(comand(),&players[0]);
		update();
		

		printf("%d %d    ", players[0].x,players[0].y );
		tiks++;
	}

	a=time(0);
	printf("%llu\n",tiks/(b-a) );
	return 0;
}


/*for (int i = 0; i < FWIT; ++i)
		{
			for (int l = 0; l < FLEN; ++l)
			{
				printf("%d", feldS[i][l]);
			}
			printf("\n");
		}	system("clear");
*/


int initialize_player(player *pl)
{	
	// left a rigth d up 1 down 2
	//printf("%s ", "Input player name:");
	//scanf("%s", (*pl).name);
	//printf("%s ", "Input colur name:");
	//scanf("%1d", &(*pl).colur_s);
	 (*pl).colur_s=3;
	 (*pl).colur_b=4;
	do
	{
		(*pl).x=rand()%FWIT;
		(*pl).y=rand()%FLEN;
	}while(feld[(*pl).x][(*pl).y]!= FIELD_S);

	feld [(*pl).x][(*pl).y]='0';
	feldS[(*pl).x][(*pl).y]=(*pl).colur_s;
	feldB[(*pl).x][(*pl).y]= (*pl).colur_b;

	return 0;

}





int move(int com)
{
	if (com==0) return 0;

	
	return 0;
}
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

int comand()
{
	int red=0;
	if (kbhit())
	{
		char a=getch();

		switch(a)
		{// left 3 rigth 4 up 1 down 2
			case 'w': red=1 ; break;
			case 's': red=2 ; break;
			case 'd': red=3 ; break;
			case 'a': red=4 ; break;
			case 'q': game_exit() ; break;

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
			printf("\033[7;0m\033[0m");


			
			
			//sprintf(sul_cus1,"%s%d%s%d",CUSTOM_C_S,feldS[i][l],CUSTOM_C_B,feldB[i][l]);

			sprintf(sul_cus1,"%s%d%c%s%d%c",CUSTOM_C_S,feldS[i][l],'m',CUSTOM_C_B,feldB[i][l],'m');
		//	printf("%s%s",sul_cus2,sul_cus1 );
			

			printf("%s%c",sul_cus1, feld[i][l]);

			printf("\033[7;0m\033[0m");
			sleep(0.1);
			
			//printf("%d %d\n", feldS[i][l],feldB[i][l]);
			//pause();
			
		}
	printf("\033[0m    ");   printf("\n");
	}

	printf("\033[7;0m\033[0m");



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
int line_len()
{

	FILE *fp = popen("tput cols", "r");
	int num_s_for_line;
	fscanf(fp, "%d", &num_s_for_line);
	printf("%d\n",num_s_for_line );
	pclose(fp);

	return num_s_for_line;
}


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

void game_exit()
{
	update();
	for (int i = 0; i < FWIT; ++i)
	{
		printf("%s", M_DOWN);
	}
	printf("%s", ACB_RESET );
	printf("%llu\n",tiks );

	system("tput cnorm"); 
	exit(0);
}