#include "TitleTimeManager.h"
#include "TitleScene.h"

TitleTimeManager::TitleTimeManager(Library* pLibrary, LPDIRECT3DTEXTURE9 pTexture) :m_pLibrary(pLibrary), m_pTexture(pTexture)
{
	//�����ʒu�ɐݒ�
	m_Pos.x = TITLEBLACKOUT_X;
	m_Pos.y = TITLEBLACKOUT_Y;

	//�傫�����ݒ�
	m_Pos.w = TITLEBLACKOUT_W;
	m_Pos.h = TITLEBLACKOUT_H;
}

TitleTimeManager::~TitleTimeManager()
{

}

bool TitleTimeManager::Control()
{
	m_TitleSceneTime++;

	//�t�F�[�h�A�E�g����Ȃ��ă|�P�����t���b�V���̂ق����ʔ���

	//alpha�͏����l��255
	//20�b�ȉ���alpha��0����Ȃ��Ƃ���alpha�������Ă��񂾂񖾂邭����B
	if (m_TitleSceneTime > 1200)//20�b�Ńt�F�[�h�A�E�g(���Ԃ�x��)
	{
		m_alpha++;
		if (m_alpha == COLORMAX)
		{
			return true;
		}
	}
	else if (m_alpha != 0)
	{
		m_alpha--;
	}

	return false;
}

void TitleTimeManager::Draw()
{
	CustomVertex blackout[4];


	m_pLibrary->m_pUVSetter->MakeVertex(TITLE_BLACK, blackout);
	m_pLibrary->m_pVertex->xySet(m_Pos, blackout);

	for (int i = 0; i < 4; i++)
	{
		blackout[i].color = D3DCOLOR_ARGB(m_alpha, COLORMAX, COLORMAX, COLORMAX);
	}

	m_pLibrary->m_pVertex->Set_Draw_Tex(m_pTexture, blackout);
}