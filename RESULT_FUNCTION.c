#include "main.h"

// ����� ���õ� �Լ��� 

void item_Change()													// ������ â�� ��� �������� �����ϴ� ������
{
	int i=0;
	for (i = 0; i < 3; i++) {
		item_see[i] += 3;											// �������� �������� ���� �ø���.
	}
}



void change_Status(int item_value)									// ĳ������ ������ �����ϴ� �Լ�
{
	int i;
	int item_type[2] = {											// ������ Ÿ���� �� �� �о��
		item_now[item_value].item_type[0],
		item_now[item_value].item_type[1]
	};
	for (i = 0; i < 2;i++) {										// ������ �ɼ��� �ΰ��̱� ������ �ι� �ݺ�
		switch (item_type[i])										
		{
		case 0:														// ������ Ÿ���� 0�̸� ������ ����
			cha.b_str += item_now[item_value].item_stat[i];			
			break;													
		case 1:														// ������ Ÿ���� 1�̸� ��ø���� ����
			cha.b_dex += item_now[item_value].item_stat[i];
			break;
		case 2:														// ������ Ÿ���� 2�̸� ���ɽ��� ����
			cha.b_int += item_now[item_value].item_stat[i];
			break;
		case 3:														// ������ Ÿ���� 3�̸� ��� ����
			cha.b_luck += item_now[item_value].item_stat[i];

		}
	}


}




void stage_Result(int stage_stat) {
	srand(time(NULL));												// �ð����� ���� �ʱ�ȭ
	
	int stage_value;
	int player_value;

	srand(time(NULL));
	switch (stage_stat) {

	case 0:
		stage_value = rand() % (STAGE_NUM[stage_cnt].di_str);
		player_value = rand() % cha.b_str;
		break;

	case 1:
		stage_value = rand() % (STAGE_NUM[stage_cnt].di_dex);
		player_value = rand() % cha.b_dex;

		break;

	case 2:
		stage_value = rand() % (STAGE_NUM[stage_cnt].di_int);
		player_value = rand() % cha.b_int;
		break;

	}

	system("cls");
	if (stage_value <= (player_value + cha.b_luck)) print_Result(TRUE);
	else print_Result(FALSE);
}

