#include <iostream>
using namespace std;
//�������
bool Diagonal(int length, int a[]) {
	for (int i_1 = 0; i_1 < length; i_1++) {
		for (int i_2 = i_1 + 1; i_2 < length && i_2 != i_1; i_2++) {
			if (a[i_1] - a[i_2] == i_1 - i_2) return false;
			if (a[i_1] - a[i_2] == i_2 - i_1) return false;
		}
	}
	return true;
}
void Perm(int start, int end, int a[]) {
	static int Counter = 0;
	if (start == end-1) {
		if (Diagonal(end, a) == false) return;
		Counter++;
		cout << Counter << "#" << endl;
		for (int i = 0; i < end; i++)
		{
			cout << "columun "<<i+1<<" row " << a[i] << endl;
		}
		return;
	}
	for (int i = start ; i < end; i++) {
		swap(a[start], a[i]);
		Perm(start + 1, end, a);
		swap(a[i], a[start]);
	}
}
int main()
{
	int Num;//�ʺ���ͷ
	cin >> Num;
	int* Row = new int[Num];//��
	for (int i = 0; i < Num; i++)
	{
		Row[i] = i + 1;
	}
	Perm(0, Num, Row);
}
