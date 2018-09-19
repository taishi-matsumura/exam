#include "TitleScene.h"
#include "Library.h"
#include "TitleBackGround.h"
#include "TitleName.h"
#include "TitleTimeManager.h"
#include "TitleSelectManager.h"

TitleScene::TitleScene(Library* pLibrary) :m_pLibrary(pLibrary), m_NextScene(SCENE_NONE)
{
	m_pLibrary->m_pUVSetter->FileInfo_Set("file.csv", FILE_INFO);
	m_pLibrary->m_pUVSetter->VertexInfo_Set("TitleTex.csv", TITLE_VERTEXINFO_MAX);
	m_pLibrary->m_pUVSetter->AnimaInfo_Set("TitleAnimation.csv", TITLEANIMA_ID_MAX);
	m_pLibrary->m_pTexture->Tex_Load_EX("TitleScene.png", &m_pTexture, 255, 0, 255, 0);


	m_pTitleBackGround = new TitleBackGround(m_pLibrary, m_pTexture);
	m_pTitleName = new TitleName(m_pLibrary, m_pTexture);
	m_pTitleSelectManager = new TitleSelectManager(m_pLibrary, m_pTexture,m_PadState,m_PadOldState);
	m_pTitleTimeManager = new TitleTimeManager(m_pLibrary,m_pTexture);
}

TitleScene::~TitleScene()
{
	delete m_pTitleTimeManager;
	delete m_pTitleName;
	delete m_pTitleSelectManager;
	delete m_pTitleBackGround;

	m_pTexture->Release();
	m_pLibrary->m_pUVSetter->AnimaInfo_Release();
	m_pLibrary->m_pUVSetter->VertexInfo_Release();
	m_pLibrary->m_pUVSetter->FileInfo_Release();

}

void TitleScene::PadCheck()
{
	m_PadOldState[PAD_LEFT] = m_PadState[PAD_LEFT];
	m_PadOldState[PAD_RIGHT] = m_PadState[PAD_RIGHT];
	m_PadOldState[PAD_DOWN] = m_PadState[PAD_DOWN];
	m_PadOldState[PAD_UP] = m_PadState[PAD_UP];

	m_PadState[PAD_LEFT] = m_pLibrary->m_pXInput->L_Analog_Left();
	m_PadState[PAD_RIGHT] = m_pLibrary->m_pXInput->L_Analog_Right();
	m_PadState[PAD_DOWN] = m_pLibrary->m_pXInput->L_Analog_Down();
	m_PadState[PAD_UP] = m_pLibrary->m_pXInput->L_Analog_Up();

	m_pLibrary->m_pXInput->Check(XINPUT_GAMEPAD_A, GAMEPAD_A);
}


SCENE_NUM TitleScene::Control()
{
	//�w�i�ƃ^�C�g�����̃R���g���[���͍��̂Ƃ���s�v


	//TitleManager�̃R���g���[��
	//��莞�Ԍo�߂Ńt�F�[�h�A�E�g����������true��Ԃ��Ă���B
	if (m_pTitleTimeManager->Control())
	{
		m_NextScene = LOGO_SCENE;
	}
	else
	{
		//�Ԃ��Ă����Ԃ�l�ɂ�莟�̃V�[���𔻒f����
		switch (m_pTitleSelectManager->Control())
		{
		case GAME_START:
			m_NextScene = GAME_SCENE;

			break;
		case GAME_END:
			m_NextScene = END_SCENE;

			break;
		case GAME_STAFF:
			m_NextScene = STAFF_SCENE;

			break;
		case TITLESELECT_NONE:
			m_NextScene = SCENE_NONE;

			break;
		}
	}
	

	return m_NextScene;
}

void TitleScene::Draw()
{
	m_pTitleBackGround->Draw();
	m_pTitleName->Draw();
	m_pTitleSelectManager->Draw();
	m_pTitleTimeManager->Draw();
}