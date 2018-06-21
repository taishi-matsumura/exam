#include <iostream>

template<typename T>
class TemplateSample
{
public:
	void Swap_Ptr(T* pX, T* pY);
};

// using宣言を用い、「std::」と書かなくて済むようにする
// ※usingディレクティブは使用しないこと
using std::cout;
using std::endl;

// ポインタ型の引数を２つ受ける
template<typename T> void Swap_Ptr(T* pX, T* pY)
{
	T temp = *pX;
	*pX = *pY;
	*pY = temp;
}

// 参照型の引数を２つ受ける
template<typename T> void Swap_Ref(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

// 受け取った２つの引数の値を、std::coutを用いて表示する
template<typename T> void Display(T x, T y, const char* pName1, const char* pName2)
{
	cout << pName1 << "=" << x << "、" << pName2 << "=" << y << endl;
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

	// a、bの値を表示する
	Display(a, b, "a", "b");

	// Swap_Ref()を用いてaとbの値を入れ替える
	Swap_Ref(a, b);

	// a、bの値を表示する
	Display(a, b, "a", "b");


	// Swap_Ptr()を用いてaとbの値を入れ替える
	Swap_Ptr(&a, &b);

	// a、bの値を表示する
	Display(a, b, "a", "b");



	float c = 1.23f;
	float d = 4.56f;

	// c、dの値を表示する
	Display(c, d, "c", "d");
	

		// Swap_Ref()を用いてcとdの値を入れ替える
		Swap_Ref(c, d);

	// c、dの値を表示する
		Display(c, d, "c", "d");


		// Swap_Ptr()を用いてcとdの値を入れ替える
		Swap_Ptr(&c, &d);

	// c、dの値を表示する
		Display(c, d, "c", "d");

		LPDIRECT3D9 pD3d = NULL;
		SafeRelease<LPDIRECT3D9>(pD3d);

		SAFE_RELEASE(pD3d);
		SAFE_RELEASE(&c);

		return 0;
}
