#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef void(*PFunc)(int*, int*);

// �R�[���o�b�N�֐�
void DispResult(int* s, int* kazu) {

	int kekka = rand() % 2;

	if (kekka == *kazu) {
		if (kekka == 0)
			printf("%d�Œ��i�����j�ł���!�哖����!!\n", kekka);
		else
			printf("%d�Ŕ��i��j�ł���!�哖����!!\n", kekka);
	}
	else {
		if (kekka == 0)
			printf("%d�Œ��i�����j�ł���!�c�O!!\n", kekka);
		else
			printf("%d�Ŕ��i��j�ł���!�c�O!!\n", kekka);
	}

}

// �R�[���o�b�N�֐����Ăяo��
void setTimeout(PFunc p, int second, int kazu) {

	puts("���Č��ʂ́c\n");

	for (int i = 0; i < second; i++) {
		Sleep(1000);
		printf("%d...\n", second - i);
	}

	p(&second, &kazu);
}


int main() {

	int kazu;

	srand(static_cast<unsigned int>(time(NULL)));

	printf("���i�����j�Ȃ�[���A���i��j�Ȃ�1����͂��Ă�������\n");
	scanf_s("%d", &kazu);

	if (kazu == 0) {
		puts("���Ȃ��͒��i�����j��I�т܂����ˁH");
	}
	else {
		puts("���Ȃ��͔��i��j��I�т܂����ˁH");
	}

	PFunc p;
	p = DispResult;
	setTimeout(p, 3, kazu);

	return 0;
}



