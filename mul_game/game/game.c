#include "defines.h"
#include "utility.h"
#include "funcion.h"

	


int main()
{	

	clear();
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

		
		
		move_player(comand(),&players[0]);

		DONT_GET_OUT();
		eat_food();

		if(tiks%60==0)spawn_food();
		update();



		printf("%d %d    ", players[0].x,players[0].y );
		printf("%llu\n",tiks );
		tiks++;
		system("sleep 0.009760");

	}

	

	return 0;
}


int spawn_food()
{

	int x=0,y=0;
	x=rand()%FWIT;
	y=rand()%FLEN;

	if (num_of_food>=4)
	{
		return 1;
	}

	feld[y][x]= FOOD;

	feldS[y][x]= 132;

	feldB[y][x]= 123;
	num_of_food++;
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

int eat_food()
{
	for (int i = 0; i < num_of_players; ++i)
	{
		if(feld[players[i].y][players[i].x]== FOOD) 
		{
			players[i].points++;
			feld[players[i].y][players[i].x]=FIELD_S;
			  num_of_food--;
		}
	}
	
	return 0;
}


