#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
struct IndexEntry
{
    char fileName[100];
    int indexBlock;
};
struct Block
{
    int content[100];
};
struct IndexEntry entry[100];
struct Block block[100];

void defaultContent()
{
    int i;
    int j=0;
    for(i=0;i<100;i++){
        j=0;
        while(j<6){
            block[i].content[j++]=rand()%100;
        }
    }

}
int main()
{

    srand(time(NULL));
    char tempName[100];
    int i,j;
    defaultContent();
    strcpy(entry[0].fileName,"file1");
    entry[0].indexBlock=20;
    for(j=0;j<6;j++)
        block[entry[0].indexBlock].content[j]=(10*j+(j+1)*2);

    strcpy(entry[1].fileName,"file2");
    entry[1].indexBlock=30;
    for(j=0;j<6;j++)
        block[entry[1].indexBlock].content[j]=(10*j+(j+1)*3);

    strcpy(entry[2].fileName,"file3");
    entry[2].indexBlock=50;
    for(j=0;j<6;j++)
        block[entry[2].indexBlock].content[j]=(10*j+(j+1)*4);

    while(1){
    printf("\nEnter the file name :");
    scanf("%s",tempName);
    for(i=0;i<3;i++){
        if(strcmp(tempName,entry[i].fileName)==0){
            break;
        }
    }
    if(i==3)
    {
        printf("No Index entry found for the file named %s",tempName);
        return 0;
    }

    int k;
    //printf("%d",i);
    for(j=0;j<6;j++){
        printf("\nBlock Number %d :",block[entry[i].indexBlock].content[j]);
        printf("\nContent:");
        for(k=0;k<6;k++){
            printf(" %d",block[block[entry[i].indexBlock].content[j]].content[k]);
        }
        printf("\n");

    }
    }
    return 0;
}
