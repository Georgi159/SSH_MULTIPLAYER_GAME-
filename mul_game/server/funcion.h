
// funcions for the game

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

	if(com==0)
	{
		com=(*a).comand;

		if(tiks%SPEED_MULTIPLIER!=0) return 3;
	}

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

void DONT_GET_OUT()
{
	for (int i = 0; i < num_of_players; ++i)
	{
		if(players[i].x>FLEN-1) players[i].x=FLEN-1;
		if(players[i].x<0) players[i].x=0
			;
		if(players[i].y>FWIT-1) players[i].y=FWIT-1;
		if(players[i].y<0) players[i].y=0;
	}

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
					if(pr_pl==1)
					{
						l++;
					}
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
