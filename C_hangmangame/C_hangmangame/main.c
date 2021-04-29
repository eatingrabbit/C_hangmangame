#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MY_DIC_SIZE 7
#define MY_WORD_LEN 20

char g_dic[MY_DIC_SIZE][MY_WORD_LEN]={

	"father",
	"mother",
	"sister",
	"brother",
	"beautiful",
	"wonderful",
	"important"
};

int g_step;


void IniGame(char *com,char *p)	//g_dic ���� ���� �ܾ� ����
{
	int index;
	int i;
	int len;

	srand(time(NULL));			//seed�� ���� �ð��� �̿��Ͽ� ����
	index=rand()%MY_DIC_SIZE;	//0~4�� ������

	strcpy(com,g_dic[index]);
	len=strlen(com);

	for(i=0;i<len;i++){
		p[i]='*';
	}
	p[i]='\0';
}

int InputChar(char com[],char p[])	//�Է� ���ڿ� �ܾ� �迭�� ���� ������ Ȯ��
{
	char key;
	int len;
	int check;
	int i;

	printf("Hint:%s\n",p);
	printf("input char:");
	scanf("%c",&key);
	getchar();	//EnterŰ(\n) �Է� ������(���ſ�)
	puts("\n");

	len=strlen(p);
	check=0;

	for(i=0;i<len;i++){
		if(com[i]==key && p[i]=='*'){

			p[i]=key;
			check=1;
		}
	}

	return check;
}

void GoNextStep()	//Ʋ���� g_step 1�� �߰�
{
	g_step++;
	printf("hang man step:%d\n",g_step);

}

void ShowHangman()	//hangman ���� ���� ���
{
	printf("\n");
	switch(g_step)
	{
		case 0:
			printf("   ��������\n");
			printf("      ��\n");
			printf("      ��\n");
			printf("      ��\n");
			printf("      ��\n");
			printf("      ��\n");
			break;

		case 1:
			printf("   ��������\n");
			printf("   �� ��\n");
			printf("      ��\n");
			printf("      ��\n");
			printf("      ��\n");
			printf("      ��\n");
			break;

		case 2:
			printf("   ��������\n");
			printf("   �� ��\n");
			printf("  ������ ��\n");
			printf("      ��\n");
			printf("      ��\n");
			printf("      ��\n");
			break;

		case 3:
			printf("   ��������\n");
			printf("   �� ��\n");
			printf("  ������ ��\n");
			printf("   ��  ��\n");
			printf("      ��\n");
			printf("      ��\n");
			break;

		case 4:
			printf("   ��������\n");
			printf("   �� ��\n");
			printf("  ������ ��\n");
			printf("   ��  ��\n");
			printf("  ������ ��\n");
			printf("      ��\n");
			break;
		default:
			break;
	}

}

int CheckGameOver(char *com, char*p)	//g_step�� 4���Ǿ� ������ ��������, Ȥ�� �ܾ ������� Ȯ��
{
	if(g_step==4){

		puts("You Lost!");
		return 1;
	}

	if(strcmp(com,p)==0){

		puts("You Win!");
		return 1;
	}

	return 0;
}

int main()
{
	char com[MY_WORD_LEN];
	char p[MY_WORD_LEN];

	puts("--Game Start--\n");

	IniGame(com,p);

	while(1){
		if(InputChar(com,p)==0){
			GoNextStep();
			ShowHangman();
		}

		if(CheckGameOver(com,p)==1){
			break;
		}

	}

	printf("--Game Over--\n");
	return 0;
} 