#include <vector>

class Sample
{
public:
	Sample();
	virtual ~Sample();
private:
	int* m_pIntArray;
	std::vector<int> m_intVector;
};

Sample::Sample()
{
	// 要素数10のint型の配列をnewし、先頭アドレスをm_pIntArrayに代入
	m_pIntArray = new int[10];

	// for文を用い、0～18の偶数をm_intVectorに詰める
	for(int i = 0; i < 10; i++)
	{
		m_intVector.push_back(i * 2);
	}
}

class Character
{
public:
	virtual void Attack() = 0;
};

class Enemy : public Character
{
};

class Queen : public Enemy
{
public:
	virtual void Attack()
	{
		// 攻撃の処理
	}
};

Sample::~Sample()
{
	// 必要な処理があればここに記述
	delete[] m_pIntArray;
}

int main()
{
	Queen character;
	return 0;
}
