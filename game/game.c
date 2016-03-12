#include <stdio.h>
#include <string.h>
#include "colurs.h"
#include "hgame.h" 
#include <stdlib.h>
#include <time.h>
#define FWIT 20
#define FLEN 171
int update();
int initial(char a);
int comand();
int move(int com);

unsigned int x=0 ,y=0;

unsigned long long tiks=59;
char feld[FWIT][FLEN];
char feldB[FWIT][FLEN];
char feldS[FWIT][FLEN];


time_t time2, time1;


int main()
{	
	system("clear");

printf("\n");
system("tput civis"); 
 printf("%s", ACB_RESET);
  printf("%s", ACC_RESET);
	
	initial('*');

	//update();
	// getchar();

	// time1=time(NULL);
	// time2=time(NULL);
	// time_t a=time2-time1;
	while(1)
	{
		feldS[3][3]=7;
		

		update();
		sleep(0.35);
		

		//move(comand());


		tiks++;
//		if(tiks==600)
		{
//			break;
		}

		
	}
	printf("%s", ACB_RESET );
	printf("%llu\n",tiks );
	system("tput cnorm"); 
	return 0;
}

int move(int com)
{
	if (com==0) return 0;

	switch (com)
	{
		case 2:  feld[x++][y]='#';feldB[x++][y]='5';feldS[x++][y]='5';
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
		{
			case 'w': red=1 ;
			case 's': red=2 ;
			case 'a': red=3 ;
			case 'd': red=4 ;
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

	char sul_cus1[14]={0};
	char sul_cus2[14]={0};
	
	for (int i = 0; i < FWIT; ++i)
	{
		for (int l = 0; l < FLEN; ++l)
		{	


			switch(feldB[i][l])
			{
				case 1:  strcpy(sul_cus1, ACC_BLACK);break;
				case 2:  strcpy(sul_cus1, ACC_RED);break;
				case 3:  strcpy(sul_cus1, ACC_GREEN);break;
				case 4:  strcpy(sul_cus1, ACC_BROWN);break;
				case 5:  strcpy(sul_cus1, ACC_BLUE);break;
				case 6:  strcpy(sul_cus1, ACC_MAGENTA);break;
				case 7:  strcpy(sul_cus1, ACC_CYAN);break;
				case 8:  strcpy(sul_cus1, ACC_WHITE); break;
				
			}

			switch(feldS[i][l])
			{
				case 1:  strcpy(sul_cus2, ACB_BLACK );break;
				case 2:  strcpy(sul_cus2, ACB_RED );break;
				case 3:  strcpy(sul_cus2, ACB_GREEN) ;break;
				case 4:  strcpy(sul_cus2, ACB_BROWN );break;
				case 5:  strcpy(sul_cus2, ACB_BLUE );break;
				case 6:  strcpy(sul_cus2, ACB_MAGENTA );break;
				case 7:  strcpy(sul_cus2, ACB_CYAN );break;
				case 8:  strcpy(sul_cus2, ACB_WHITE );break;
				
			}


			printf("%s%s%c",sul_cus1,sul_cus2 , feld[i][l]);
			sleep(0.1);
			
			
		}
	printf("\n");
	}

	printf("%s", ACC_RESET );



	return 0;
}


int initial(char a)
{
	for (int i = 0; i < FWIT; ++i)
	{
		for (int l = 0; l < FLEN; ++l)
		{
			feld[i][l]=a;
			feldB[i][l]=7;
			feldS[i][l]=1;
		}
	}
	return 0;

}
