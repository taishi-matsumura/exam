#include <iostream>

template<typename T>
class TemplateSample
{
public:
	void Swap_Ptr(T* pX, T* pY);
};

// using�錾��p���A�ustd::�v�Ə����Ȃ��čςނ悤�ɂ���
// ��using�f�B���N�e�B�u�͎g�p���Ȃ�����
using std::cout;
using std::endl;

// �|�C���^�^�̈������Q�󂯂�
template<typename T> void Swap_Ptr(T* pX, T* pY)
{
	T temp = *pX;
	*pX = *pY;
	*pY = temp;
}

// �Q�ƌ^�̈������Q�󂯂�
template<typename T> void Swap_Ref(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

// �󂯎�����Q�̈����̒l���Astd::cout��p���ĕ\������
template<typename T> void Display(T x, T y, const char* pName1, const char* pName2)
{
	cout << pName1 << "=" << x << "�A" << pName2 << "=" << y << endl;
}

#include <Windows.h>
#include <d3dx9.h>

template<class T> void SafeRelease(T _pObj)
{
	if(_pObj) _pObj->Release();
	_pObj = NULL;
}

#define SAFE_RELEASE(p) {if(p) {(p)->Release(); (p)=NULL;}}

int main()
{
	int a = 5;
	int b = 10;

	// a�Ab�̒l��\������
	Display(a, b, "a", "b");

	// Swap_Ref()��p����a��b�̒l�����ւ���
	Swap_Ref(a, b);

	// a�Ab�̒l��\������
	Display(a, b, "a", "b");


	// Swap_Ptr()��p����a��b�̒l�����ւ���
	Swap_Ptr(&a, &b);

	// a�Ab�̒l��\������
	Display(a, b, "a", "b");



	float c = 1.23f;
	float d = 4.56f;

	// c�Ad�̒l��\������
	Display(c, d, "c", "d");
	

		// Swap_Ref()��p����c��d�̒l�����ւ���
		Swap_Ref(c, d);

	// c�Ad�̒l��\������
		Display(c, d, "c", "d");


		// Swap_Ptr()��p����c��d�̒l�����ւ���
		Swap_Ptr(&c, &d);

	// c�Ad�̒l��\������
		Display(c, d, "c", "d");

		LPDIRECT3D9 pD3d = NULL;
		SafeRelease<LPDIRECT3D9>(pD3d);

		SAFE_RELEASE(pD3d);
		SAFE_RELEASE(&c);

		return 0;
}
