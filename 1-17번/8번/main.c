/*
문제 8. UP & Down.

힌트 및 요구사항

a. 난수 생성을 통해 0-50의 수 중 하나가 임의로 생성된다.
b. 생성된 임의의 수를 아래와 같이 사용자에게 수를 입력받아 맞추면 종료된다.
c. 시도 횟수(10번)이 초과되면 게임이 종료되도록 하고, 맞출 경우 시도 횟수를 표시한다.
d. 50을 초과한는 수 또는 음수가 입력되었을 경우 "유효하지 않은 수 입니다."가 출력되도록 하고
시도 횟수에는 포함시키지 않는다.
e. 입력값을 표시하고, 입력값이 정답보다 큰 수인지 작은 수인지 표시한다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int count = 0, /* 시도 횟수 */
		Rnd_Num, /* 생성된 난수 */
		Usr_Choice; /* 사용자 입력 수 */

	// 난수 생성
	srand(time(NULL));
	Rnd_Num = rand() % 51;
	//printf("생성된 난수 : %d\n", Rnd_Num);

	printf("0-50의 수 중 하나를 입력하여 정답을 찾아보세요.\n");
	printf("시도 가능 횟수는 10번입니다.\n");
	while (count < 10)
	{
		// 사용자 입력 - 범위 에러 처리 (o)
		while (1)
		{
			printf("0부터 50 사이의 수를 하나 입력해주세요 > ");
			fflush(stdin);
			scanf_s("%d", &Usr_Choice);
			if (Usr_Choice >= 0 && Usr_Choice <= 50)
				break;
			else
				printf("유효하지 않은 수 입니다.\n");
		}
		count++; /* 시도 횟수 증가 */

		printf("입력값 : %d", Usr_Choice);

		// 생성된 난수와 사용자 입력값 비교.
		if (Usr_Choice < Rnd_Num)
			printf(" <정답보다 작은 값이 입력되었습니다>\n");
		else if (Usr_Choice == Rnd_Num)
		{
			printf(" 정답입니다! (시도 횟수 = %d)\n", count);
			break;
		}
		else
			printf(" <정답보다 큰 값이 입력되었습니다>\n");
	}
}