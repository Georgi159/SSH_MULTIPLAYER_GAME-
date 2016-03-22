#include "defines.h"
#include "utility.h"
#include "funcion.h"




int main()
{	
	//intalize

		int shmid;
	    char  *s=NULL;
	    char *shm;


	    /*
	     * Create the segment.
	     */
	     
	    if ((shmid = shmget(key, SH_M_S, IPC_CREAT | 0666)) < 0) {
	        perror("shmget");
	        exit(1);
	    }
	    /*
	     * Now we attach the segment to our data space.
	     */
	    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
	        perror("shmat");
	        exit(1);
	    }

	    
	    printf("%d\n",SH_M_S );
	    s=shm;
	    printf("%p %p %p %p %p\n",(void *)s ,(void *)players, (void *)feld,(void *)feldS,(void *)feldB );

	    players=(player *)s;

	  	feld=(char **) (s+sizeof(player)*num_of_players);
	  	feldS=(int **) ((sizeof(char)*FWIT*FLEN)+feld);
	  	feldB=(int **) ((sizeof(int)*FWIT*FLEN)+feldS);

	    printf("%p %p %p %p %p\n",(void *)s ,(void *)players, (void *)feld,(void *)feldS,(void *)feldB );




		a=time(0);
		initialize_feld(FIELD_S,FIELD_C_S,FIELD_B);
		memset(players, 0 ,sizeof(player));
		for (int i = 0; i < num_of_players; ++i)
		{
			initialize_player(&players[i]);
		}
	//intalize

	// main loop
	while(1)
	{
		for (int i = 0; i < num_of_players; ++i)
		{
			move_player(players[i].comand,&players[i]);
		}
		

		DONT_GET_OUT();
		eat_food();

		spawn_food();

		b=time(0);
		printf("%llu\n%lf FPS\n",tiks, (double)tiks/(double)(b-a) );
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


