#include<stdio.h>
struct Block
{
    char name;
    int startAddress;
};
struct Block appartment[4];
int main()
{
    int i;
    appartment[0].name='A';
    appartment[1].name='B';
    appartment[2].name='C';
    appartment[3].name='D';
    for(i=0;i<4;i++)
        appartment[i].startAddress=500*i;
    int floorNo,pos;
    char name;
    printf("enter block name, floor no, room position in floor :");
    scanf("%c%d%d",&name,&floorNo,&pos);
    for(i=0;i<4;i++){
        if(appartment[i].name==name)
            break;
    }
    printf(" room no - %d",appartment[i].startAddress+floorNo*100+pos);
    return 0;
}
