#include "h1game.h"
int num_of_players=2;


	player players[2];


int main()
{	

	a=time(0);
	system("clear");
	printf("\n");
	system("tput civis"); 
	
	initialize_feld(FIELD_S, FIELD_B , FIELD_C_S);

	memset(players, 0 ,sizeof(player));

	for (int i = 0; i < num_of_players; ++i)
	{
		initialize_player(&players[i]);
	}
	

	update();
	while(1)
	{

		sleep(0.4);
		
		move_player(comand(),&players[0]);

		DONT_GET_OUT();
		if(tiks%60==0)spawn_food();
		update();



		printf("%d %d    ", players[0].x,players[0].y );
		tiks++;
	}

	a=time(0);
	printf("%llu\n",tiks/(b-a) );

	return 0;
}
int spawn_food()
{
	static int num_of_food=0;

	int x=0,y=0;
	x=rand()%FWIT;
	y=rand()%FLEN;

	if (num_of_food>=4)
	{
		return 1;
	}

	feld[y][x]= '0';

	feldS[y][x]= 132;

	feldB[y][x]= 123;
	num_of_food++;
	return 0;
}


int update()
{
	clear();
	char pr_pl=0;
	for (int i = 0; i < FWIT; ++i)
	{
		for (int l = 0; l < FLEN; ++l)
		{	
			pr_pl=0;

			for (int count = 0; count < num_of_players; ++count)
			{
				if(players[count].x==l && players[count].y==i)
				{
					print_ch(players[count].player_sim , players[count].colur_s , players[count].colur_b);
					pr_pl=1;
				}
			}


			if(pr_pl==0)
			{
				print_ch(feld[i][l],feldS[i][l],feldB[i][l]);
			}
		}
		printf("\033[7;0m\033[0m");
  		printf("   \n");
	}

	printf("\033[7;0m\033[0m");


	return 0;
}


int initialize_player(player *pl)
{	
	// left a rigth d up 1 down 2
	//printf("%s ", "Input player name:");
	//scanf("%s", (*pl).name);
	//printf("%s ", "Input colur name:");
	//scanf("%1d", &(*pl).colur_s);
	 (*pl).colur_s=123;
	 (*pl).colur_b=200;
	 (*pl).player_sim='0';
	do
	{
		(*pl).x=rand()%FWIT;
		(*pl).y=rand()%FLEN;
	}while(feld[(*pl).x][(*pl).y]!= FIELD_S);

	return 0;

}

int move_player(int com, player *a)
{
	(*a).last_comand=(*a).comand;
	(*a).comand=com;


	switch (com)
	{
			case 1: (*a).y--;  return 1; break;
			case 2: (*a).y++;  return 1; break;
			case 3: (*a).x++;  return 1; break;
			case 4: (*a).x--;  return 1; break;
	}
	return 0;

}

int comand()
{
	int red=0;
	if (kbhit())
	{

		char b;
		scanf("%c", &b);

		char a=getch();
		printf("%c", b);

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
void DONT_GET_OUT()
{
	for (int i = 0; i < num_of_players; ++i)
	{
		if(players[i].x>FLEN-1) players[i].x=FLEN-1;
		
		if(players[i].y>FWIT-1) players[i].y=FWIT-1;
	}

}

