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
	// �v�f��10��int�^�̔z���new���A�擪�A�h���X��m_pIntArray�ɑ��
	m_pIntArray = new int[10];

	// for����p���A0�`18�̋�����m_intVector�ɋl�߂�
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
		// �U���̏���
	}
};

Sample::~Sample()
{
	// �K�v�ȏ���������΂����ɋL�q
	delete[] m_pIntArray;
}

int main()
{
	Queen character;
	return 0;
}
