#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void gotoxy(int x, int y) 
{
	int xx=0x0b;
	HANDLE hOutput;
	COORD loc;
	loc.X = x;
	loc.Y=y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
}

void output(char *s)
{
	gotoxy(1,1);
	while(isalpha(*s)||*s==' ')
	{	
		Sleep(100);
		printf("%c",*s);
		s++;
	}
		while(*s!='\0')
	{	
		Sleep(50);
		printf("%c",*s);
		s++;
	}
}

void disappear()
{	
	int i,j;
	gotoxy(0,0);
	for(i=0;i<10;i++)
	{
		for(j=0;j<20;j++)
		{
			Sleep(50);
			printf(" ");
		}

		printf("\n");	
	}


}

void appear()
{
	int i;
	for(i=0;i<26;i++)
	{
		Sleep(100);
		gotoxy(i,0);
		printf("*");
		gotoxy(25-i,26);
		printf("*");
	}
	for(i=0;i<26;i++)
	{
		Sleep(100);
		gotoxy(25,i);
		printf("*");
		gotoxy(0,25-i);
		printf("*");
	}

}

int ybjpd(int y)
{
	if(y-5<0)
		return 0;
	else
	{
		if(47-y<20)
			return 22;
		else
			return y-5;
	}
}

int xbjpd(int x)
{
	if(x-5<0)
		return 0;
	else
	{
		if(29-x<10)
			return 14;
		else
			return x-5;
	}
}



int main()
{
	int i,x,y,p,q;
    char ch;
	char a[120][50]={"##########################################",
                    "#\001 #         ##  #         ##  #         #",
                    "# ##  #          #    #########  ###     #",
                    "#  ############ ##     ######   ######  ##",
                    "##        # #    ####### #    ######     #",
                    "#######    #### #######  # # #    #####  #",
					"#####    ###### #     ###### #    ## ### #",
                    "# #    # ############   # #    ######    #",
                    "# ##  #        #      ##### #    ######  #",
                    "#  #   ###### ####  #######  #######  #  #",
                    "##    #   ############## #   #########   #",
                    "## #   ##############      #####        ##",
					"###                   #########  #########",
                    "#  #         ##  #         ##            #",
                    "# ##  #          #    #########  ###     #",
                    "#  ## ######### ##     ######   ######  ##",
                    "##    #   # #    ####### #    ######     #",
                    "#######    #### #######  # # #    #####  #",
					"#####    ######        ##### #    ## ### #",
                    "# #    # ############   # #    ######   ##",
                    "# ##                  ##### #    ######  #",
                    "#  #   ###### ####  #######  #######  #  #",
                    "##    #   #########          ########### #",
                    "## #######################################",
                    };

	char *s=" Happy birthday to you!\n\n\
*        念哥撒~\n\n\
*     我拿你的迷宫\n\n\
*       调整了下\n\n\
*    变成了这个样子\n\n\
*     你看怎么样撒~\n\n\
*        哈哈哈\n\n\
*      这个代码的撒~\n\n\
*    虽然是你发我的撒~\n\n\
*    但勉强算生日礼物~\n\n\
*       送给你了撒~\n\n\
*         就这样\n\n\
*       生日快乐撒！\n\n";


 x=1;y=1;p=23;q=2;

	system("title 迷宫");
	system("mode con cols=80 lines=30");
	system("color 0e");

    for(i=x-5>0?x-5:0;i< (x+5>10?x+5:10); i++)
		printf("%.20s\n",&a[i][ybjpd(y)]);
    while(x!=p||y!=q)
    {
		ch=getch();
      if(ch=='s')
      {
		if(a[x+1][y]!='#')
        {
			a[x][y]=' ';
            x++;
            a[x][y]='\001';
        }
      }
      if(ch=='w')
      {
			if(a[x-1][y]!='#')
            {
				a[x][y]=' ';
                x--;
                a[x][y]='\001';
            }
      }
      if(ch=='a')
      {
			if(a[x][y-1]!='#')
            {
				a[x][y]=' ';
                y--;
                a[x][y]='\001';
            }
      }
      if(ch=='d')
      {
			if(a[x][y+1]!='#')
            {
				a[x][y]=' ';
                y++;
                a[x][y]='\001';
            }
      }
      system("cls");
	  for(i=xbjpd(x);i< (x+5>10?x+5:10) ;i++)
		  printf("%.20s\n",&a[i][ybjpd(y)]);
    }
	Sleep(1000);
	disappear();
    system("cls");
	appear();
	output(s);
    Sleep(10000);
	system("pause");
    return 0;
}
