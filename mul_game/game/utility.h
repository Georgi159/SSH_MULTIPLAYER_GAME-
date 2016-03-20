// side funcions to make live easy


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


int line_len()
{

	FILE *fp = popen("tput cols", "r");
	int num_s_for_line;
	fscanf(fp, "%d", &num_s_for_line);
	printf("%d\n",num_s_for_line );
	pclose(fp);

	return num_s_for_line;
}


void print_ch(char ch,int col_s,int col_b)
{
	printf("%s%dm%s%dm%c",CUSTOM_C_S,col_s, CUSTOM_C_B,col_b,ch);

}


void clear()
{
	system("clear");	
	printf("\033[3J");
}



//unKNOWN
	int kbhit(void)
	{
	  struct termios oldt, newt;
	  int ch;
	  int oldf;
	 
	  tcgetattr(STDIN_FILENO, &oldt);
	  newt = oldt;
	  newt.c_lflag &= ~(ICANON | ECHO);
	  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	 
	  ch = getchar();
	 
	  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	  fcntl(STDIN_FILENO, F_SETFL, oldf);
	 
	  if(ch != EOF)
	  {
	    ungetc(ch, stdin);
	    return 1;
	  }
	 
	  return 0;
	}

	int getch(void)
	{
	    struct termios oldattr, newattr;
	    int ch;
	    tcgetattr( STDIN_FILENO, &oldattr );
	    newattr = oldattr;
	    newattr.c_lflag &= ~( ICANON | ECHO );
	    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	    ch = getchar();
	    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
	    return ch;
	}


