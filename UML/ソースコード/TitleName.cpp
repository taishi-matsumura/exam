#include "TitleName.h"
#include "TitleScene.h"

TitleName::TitleName(Library* pLibrary, LPDIRECT3DTEXTURE9 pTexture) :m_pLibrary(pLibrary), m_pTexture(pTexture)
{
	//�����ɗ���悤�ɏ����l�ݒ�
	m_Pos.x = TITLENAMEPOS_X;
	m_Pos.y = TITLENAMEPOS_Y;
}

TitleName::~TitleName()
{

}

void TitleName::Control()
{

}

void TitleName::Draw()
{
	CustomVertex titlename[4];

	m_pLibrary->m_pUVSetter->MakePosition(TITLE_NAME, &m_Pos);

	m_pLibrary->m_pUVSetter->MakeVertex(TITLE_NAME, titlename);
	m_pLibrary->m_pVertex->xySet(m_Pos, titlename);

	m_pLibrary->m_pVertex->Set_Draw_Tex(m_pTexture, titlename);
}
