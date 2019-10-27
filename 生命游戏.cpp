#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define High 25
#define Width 50 //游戏画面尺寸

//全局变量
int cells[High][Width];

void gotoxy(int x , int y )//将光标移到xy位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle ,pos);
}

void startup()//数据初始化
{
    int i , j;
    for(i = 0;i<High;i++)
        for(j=0;j<Width;j++)
        {
            cells[i][j] = rand()%2;
        }
}

void show()//显示画面
{
    gotoxy(0,0);
    int i , j;
    for (i = 0;i<=High;i++)
    {
        for(j=0;j<Width;j++)
        {
            if(cells[i][j] == 1)
                printf("*");//输出活的细胞
            else
                printf(" ");//输出空格
        }
        printf("\n");
    }
}

void updateWithoutInput()
{
    int NewCells[High][Width];
    int NeibourNumber;
    int i,j;
    for(i=1;i<=High-1;i++)
    {
        for(j=0;j<Width;j++)
        {
            NeibourNumber = cells[i-1][j-1] + cells[i-1][j]+cells[i-1][j+1]+cells[i][j-1]+cells[i][j+1]+cells[i+1][j-1]+cells[i+1][j]+cells[i+1][j+1];
            if(NeibourNumber == 3)
                NewCells[i][j] = 1;
            else if(NeibourNumber == 2)
                NewCells[i][j] = cells[i][j];
            else
                NewCells[i][j]=0;
        }
    }
    for(i=1;i<=High-1;i++)
        for(j=0;j<Width;j++)
            cells[i][j]=NewCells[i][j];
}


int main() {

    startup();
    while (1)//这是个死循环，所有的细胞动态繁衍或死亡
    {
        show();
        updateWithoutInput();

    }
    return 0;
}


