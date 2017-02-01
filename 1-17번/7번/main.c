/*
����7. ��ġ�� ���� ã��.

��Ʈ �� �䱸����

a. ������������� Ǯ��� �ϸ�, 2���� �ð�ǥ ������ �ʿ��ϴ�.
b. �ð�ǥ ����(.txt)�� ����� ������ �Բ� ������ ���� ������ �����ϸ� �ȴ�.
c. ��¿��� ȭ��� ���� 2���� �ð�ǥ ���Ϸκ��� �ð�ǥ�� �о�� ����� ��, ��ġ�� ������ ������ָ� �ȴ�.
*/
#include <stdio.h>
#include <string.h>
enum DAY { MON = 1, TUE, WED, THU, FRI };
void main()
{
	enum DAY Day; /* ���Ͽ� ���� enum ���� */

	FILE * fp_my, /* mytime.txt ���� ���� ����ü ������ */
		*fp_fr; /* friendtime.txt ���� ���� ����ü ������ */

	int i, j; /* ���� ���� */
	long cur_pos_periodMY[7], /* mytime.txt ������ �� ���κ� ���� ��ġ�� ���� offset */
		cur_pos_periodFR[7]; /* friendtime.txt ������ �� ���κ� ���� ��ġ�� ���� offset */

	char str_bufMY[2], /* mytime.txt ���Ͽ��� ���ڿ� ������ ������ ���� ���� */
		str_bufFR[2], /* friendtime.txt ���Ͽ��� ���ڿ� ������ ������ ���� ���� */
		line_buf[100]; /* ���Ͽ��� ���ٴ����� ������ ���� ����  */


	fopen_s(&fp_my,"mytime.txt", "r");
	fopen_s(&fp_fr,"friendtime.txt", "r");


	printf(" [ ��ġ�� ���� ã���ִ� ���α׷� ]\n");
	printf(" cf) ������ \"-\"�� ������ \"o\"���� ǥ�� �˴ϴ�!\n");

	printf(" < My TimeTable > \n");
	// mytime.txt ���� ���
	for (i = 0; !feof(fp_my); i++)
	{
		cur_pos_periodMY[i] = ftell(fp_my); // ���κ� ������ġ ����
		fgets(line_buf, 255, fp_my);		// ���� �о ���ۿ� ���
		fputs(line_buf, stdout);			// ���� ������ ���
	}
	fseek(fp_my, 0, SEEK_SET);				// ��� ������ ���� ������ġ�� �� ����

	printf("\n < Friend's TimeTable > \n");
	// friendtime.txt ���
	for (i = 0; !feof(fp_fr); i++)
	{
		cur_pos_periodFR[i] = ftell(fp_fr);
		fgets(line_buf, 255, fp_fr);
		fputs(line_buf, stdout);
	}
	fseek(fp_fr, 0, SEEK_SET);



	printf("\n\n < ��ġ�� ���� > \n");
	// ������~�ݿ��� �� ���Ϻ���
	for (Day = MON; Day <= FRI; Day++)
	{
		// 1����~6���� �߿� ��ġ�� ���� ã��
		for (i = 1; i <= 6; i++)
		{
			// �����ص� ��ġ�� �̵�
			fseek(fp_my, cur_pos_periodMY[i], SEEK_SET);
			fseek(fp_fr, cur_pos_periodFR[i], SEEK_SET);

			// �ش� ���Ͽ� ���� ��(Column)���� �б� ���� ���� �ʵ� ����
			for (j = 1; j <= Day; j++)
			{
				fscanf(fp_my, "%*s");
				fscanf(fp_fr, "%*s");
			}

			fscanf(fp_my, "%s", str_bufMY);	// �� �ð�ǥ ���� �а�
			if (strcmp(str_bufMY, "-") == 0)	// �����̸�
			{
				fscanf(fp_fr, "%s", str_bufFR);		// ģ�� �ð�ǥ �о
				if (strcmp(str_bufMY, str_bufFR) == 0) // ģ���� �������� check
					switch (Day)
				{
					case MON:
						printf("������ : %d����\n", i);
						break;
					case TUE:
						printf("ȭ���� : %d����\n", i);
						break;
					case WED:
						printf("������ : %d����\n", i);
						break;
					case THU:
						printf("����� : %d����\n", i);
						break;
					case FRI:
						printf("�ݿ��� : %d����\n", i);
						break;
				}
			}
		}
	}


	fclose(fp_my);
	fclose(fp_fr);
}