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

