//: C03:static_cast.cpp
void func(int) {}

int main() {
	int i = 0x7fff;		// ������������ ������������� �������� = 32767
	long l;
	float f;
	// (1) �������� �������������� ��������������:
	l = i;
	f = i;
	// ����� ����� ����������� ���������:
	l = static_cast<long>(i);
	f = static_cast<float>(i);
	
	// (2) �������������� � ������� ����������:
	i = l;	// �������� ������ ������
	i = f;	// �������� ������ ������
	// �������� "� ����, ��� �����", ��������� ��������������;
	i = static_cast<int>(l);
	i = static_cast<int>(f);
	char c = static_cast<char>(i);
	
	// (3) �������������� �������������� void*;
	void* vp = &i;
	// ������� ������ ������:
	float* fp = (float*)vp;
	
	// ����� ������ �� ����� ������:
	fp = static_cast<float*>(vp);
	
	// (4) ������� ���������� ����, ������ ����������� ������������:
	double d = 0.0;
	int x = d;	// �������������� ���������� ����
	x = static_cast<int>(d);	// ����� ���������� ����
	func(d);	// �������������� ���������� ����
	func(static_cast<int>(d));	// ����� ���������� ����
} ///:~