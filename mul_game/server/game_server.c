#include "defines.h"
#include "utility.h"
#include "funcion.h"




int main()
{	
	//intalize
		initialize_file_pointers();



		a=time(0);
		initialize_feld(FIELD_S,FIELD_C_S,FIELD_B);

		write_to_file_everything();
		memset(&players[0], 0 ,sizeof(player));
		for (int i = 0; i < num_of_players; ++i)
		{
			initialize_player(&players[i]);
		}
	//intalize

	// main loop
	while(1)
	{
		//for (int i = 0; i < num_of_players; ++i)
		{
			move_player(comand(),&players[0]);
		}
				update();

		DONT_GET_OUT();
		eat_food();
		spawn_food();

		b=time(0);
		printf("%llu\n%lf FPS\n",tiks, (double)tiks/(double)(b-a) );
		tiks++;
		system("sleep 0.010960");

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
	//getchar();
	//getchar();
	feld[y][x]= FOOD;
	feldS[y][x]= 132;
	feldB[y][x]= 123;
	num_of_food++;
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
			feldS[players[i].y][players[i].x]=FIELD_C_S;
			feldB[players[i].y][players[i].x]=FIELD_B;

			  num_of_food--;
		}
	}
	
	return 0;
}


