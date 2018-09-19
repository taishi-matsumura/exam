#include "TitleBackGround.h"
#include "TitleScene.h"

TitleBackGround::TitleBackGround(Library* pLibrary, LPDIRECT3DTEXTURE9 pTexture) :m_pLibrary(pLibrary),m_pTexture(pTexture)
{
	//’†‰›‚É—ˆ‚é‚æ‚¤‚É‰Šú’lÝ’è
	m_Pos.x = TITLEBACKGROUNDPOS_X;
	m_Pos.y = TITLEBACKGROUNDPOS_Y;
}

TitleBackGround::~TitleBackGround()
{

}

void TitleBackGround::Control()
{

}

void TitleBackGround::Draw()
{
	CustomVertex background[4];

	m_pLibrary->m_pUVSetter->MakePosition(TITLE_BACKGROUND, &m_Pos);

	m_pLibrary->m_pUVSetter->MakeVertex(TITLE_BACKGROUND, background);
	m_pLibrary->m_pVertex->xySet(m_Pos, background);

	m_pLibrary->m_pVertex->Set_Draw_Tex(m_pTexture, background);

}