#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define High 25
#define Width 50 //��Ϸ����ߴ�

//ȫ�ֱ���
int cells[High][Width];

void gotoxy(int x , int y )//������Ƶ�xyλ��
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle ,pos);
}

void startup()//���ݳ�ʼ��
{
    int i , j;
    for(i = 0;i<High;i++)
        for(j=0;j<Width;j++)
        {
            cells[i][j] = rand()%2;
        }
}

void show()//��ʾ����
{
    gotoxy(0,0);
    int i , j;
    for (i = 0;i<=High;i++)
    {
        for(j=0;j<Width;j++)
        {
            if(cells[i][j] == 1)
                printf("*");//������ϸ��
            else
                printf(" ");//����ո�
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
    while (1)//���Ǹ���ѭ�������е�ϸ����̬���ܻ�����
    {
        show();
        updateWithoutInput();

    }
    return 0;
}


