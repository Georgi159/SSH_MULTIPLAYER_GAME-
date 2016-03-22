#include "defines.h"
#include "utility.h"
#include "funcion.h"

	


int main()
{	
	//intalize


		int shmid;
	    char *shm, *s;

	    

	    /*
	     */
	    if ((shmid = shmget(key, SH_M_S, 0666)) < 0) {
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
	    s=shm;
	    players=(void *)s;
	  	feld=(void *) (s+sizeof(player)*num_of_players);
	  	feldS=(void *) ((sizeof(char)*FWIT*FLEN)+feld);
	  	feldB=(void *) ((sizeof(int)*FWIT*FLEN)+feldS);




		a=time(0);
		system("tput civis"); 
		clear();
		
		memset(players, 0 ,sizeof(player));
		
			initialize_player(&players[0]);
		
	//intalize

	// main loop
	while(1)
	{
		
		 players[0].comand=comand();


		update();

		printf("%d %d    ", players[0].x,players[0].y );
		b=time(0);
		printf("%llu\n%lf FPS\n",tiks, (double)tiks/(double)(b-a) );
		tiks++;
		system("sleep 0.009760");

	}

	

	return 0;
}





