/*
���� 16. ���� ���ھ� ����ϱ�
��Ʈ �� ���ǻ���
a) ���� ���� �� 10���� ���� ����Ѵ�. ���� �� ���� 10���� ���������� �̷������. �׸��� ��� ������ �� �������� ������ �ջ��� ���̴�.
b) ������ �������� �����ϸ� �� �����Ӹ��� �ִ� 2ȸ���� ������ �� �� �ִµ�, ��Ʈ����ũ�� ��쿡�� 1ȸ�� �����Ѵ�.
c) ù ȸ�� ��Ʈ����ũ�� ���� ���� ��쿡�� �� �� �� ������ �� ��ȸ�� �ִµ�, �� ��° �������� ������ ���� ��� �����߸��� ������ �ϰ� �׷��� ���� ��츦 �̽���� �Ѵ�.
d) ���� �� 10 ���������� ����ǰ�, ��Ⱑ ��� ������ ���� �� �����Ӻ� ������ �ջ��Ѵ�.
* �����Ӻ� ���� ��� ����� ÷�ε� PDF ������ �����ϼ���.
���� ���� )
5       //�� 5���� ���
18      //18������ �����߸� �ɼ�
5 5 8 0 10 7 2 10 10 7 3 9 1 9 1 10 5 5
12      //12������ ����Ʈ�� �ɼ�
10 10 10 10 10 10 10 10 10 10 10 10
11      //11������ ����Ʈ�� �ɼ�
10 10 10 10 10 10 10 10 10 9 0
12      //12������ ����Ʈ�� �ɼ�
10 10 10 10 10 10 10 10 10 0 10 8
12      //12������ ����Ʈ�� �ɼ�
8 8 10 10 10 10 10 10 10 10 10 10
*/
#include <stdio.h>
#include <malloc.h>
void main()
{
	FILE * fp;		// input.txt�� ���� ���� ����ü ������
	int game_num,	// �Է¹��� ���� Ƚ��(input.txt ���� ù��)
		try_num,	// �� ���Ӵ�(10������) �õ��� Ƚ��
		game_idx,	// �� ���ӿ� ���� index
		frame_idx,	// �� �����ӿ� ���� index
		*score,	// �� ���Ӵ� 'try_num'�� ��ŭ ����� �������� ����
		** frame_score,	// score �迭�� �����Ӻ��� ����� �������� ����
		sum = 0,	// �� ���Ӵ� ����
		i, j;		// ���� ����

	// ���� ����
	if (fopen_s(&fp, "input.txt", "r") != 0){
		printf("file open error!!\n");
		return;
	}

	// ù �࿡�� ���� Ƚ�� �о��
	fscanf_s(fp, "%d", &game_num);

	// �������迭�� ���� �����Ҵ� (int�� * ����Ƚ�� * �����Ӽ�)
	frame_score = (int **)malloc(sizeof(int *)*game_num);
	for (i = 0; i < game_num; i++)
		frame_score[i] = (int *)malloc(sizeof(int)* 10);

	// ������ �迭 �ʱ�ȭ
	/*for (i = 0; i < game_num; i++)
	for (j = 0; j < 10; j++)
	frame_score[i][j] = 0;*/

	// ���Ͽ� �Էµ� ������ �о�� �� ���Ӻ� ������ ����Ѵ�.
	for (game_idx = frame_idx = 0; game_idx < game_num; game_idx++)
	{
		fscanf_s(fp, "%d", &try_num);				// �� ��⿡�� ������ Ƚ�� �о�ͼ�
		score = (int *)malloc(sizeof(int)*try_num);	// �� ũ�� ��ŭ�� ������ �����Ҵ� ��
		for (i = 0; i < try_num; i++)				// �� ������ �� ������ ������ ������ ���´�.
			fscanf_s(fp, "%d", &score[i]);
		/* ���Ͽ��� ������ �о�� �迭�� ������ ���� : �迭�� index�� �̿��� ��ȸ�� ���ϰ� �Ϸ���... */

		// ��Ʈ����ũ, ���о�, �̽� �϶��� �����Ӻ� ���� ����
		for (i = 0; i < try_num && frame_idx < 10;)
		{
			// ��Ʈ����ũ
			if (score[i] == 10){
				frame_score[game_idx][frame_idx++] = score[i] + score[i + 1] + score[i + 2];
				i += 1;
			}
			else if (score[i] < 10)
			{
				// ���о�
				if (score[i] + score[i + 1] == 10){
					frame_score[game_idx][frame_idx++] = score[i] + score[i + 1] + score[i + 2];
					i += 2;
				}
				// �̽�
				else if (score[i] + score[i + 1] < 10){
					frame_score[game_idx][frame_idx++] = score[i] + score[i + 1];
					i += 2;
				}
				// ����
				else if (score[i] + score[i + 1] > 10) { sum = -1;	break; }
			}
			else { sum = -1;	break; }
		}// End of (Inner) for

		if (sum != -1)
		{
			// �� ���� ȸ���� ���� ���ϱ�
			for (j = 0; j < 10; j++)
				sum += frame_score[game_idx][j];
			printf("%d\n", sum);
		}
		else
			printf("error\n");

		// �����Ҵ� ����
		free(score);
		// ����� ���� �ʱ�ȭ
		frame_idx = sum = 0;
	}// End of (Outer) for


	// �����Ҵ� ����
	for (i = 0; i < game_num; i++)
		free(frame_score[i]);
	free(frame_score);

	// ���� �ݱ�
	fclose(fp);
}