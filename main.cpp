#include<stdio.h>
#include<Windows.h>
#include <time.h>
#include <functional>


//�R�[���o�b�N�֐�
void DispResult(int* s, int* kye) {
	int dice = rand() % 2;

	if (dice == *kye) {
		if (dice == 0)
			printf("%d�Œ�(����)�ł����B������", dice);
		else
			printf("%d�Ŕ�(�)�ł����B������", dice);
	}
	else {
		if (dice == 1)
			printf("%d�Ŕ�(�)�ł����B�͂���", dice);
		else
			printf("%d�Œ�(����)�ł����B�͂���", dice);
	}

}

void setTimeout(std::function<void(int*, int*)>p, int second, int kye) {
	//�R�[���o�b�N�֐����Ăяo��
	for (int i = 0; i < second; i++) {
		Sleep(1000);
		printf("%d...\n", second - i);
	}


	p(&second, &kye);
}

int main() {

	int kye;

	srand(static_cast<unsigned int>(time(NULL)));
	printf("��(����)�Ȃ�0�A��(�)�Ȃ�1��ł�\n");
	scanf_s("%d", &kye);

	if (kye == 0) {
		puts("���Ȃ��͒�(����)��I�т܂���");
	}
	else {
		puts("���Ȃ��͔�(�)��I�т܂���");
	}

	std::function<void(int*, int*)> p = [](int* s, int* kye) {
		DispResult(s, kye);
		};
	return 0;
};

