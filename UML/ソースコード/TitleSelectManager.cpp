#include "TitleSelectManager.h"
#include "TitleScene.h"

TitleSelectManager::TitleSelectManager(Library* pLibrary, LPDIRECT3DTEXTURE9 pTexture, bool* pPadState, bool* pPadOldState) 
	:m_pLibrary(pLibrary), m_pTexture(pTexture), m_PadState(pPadState), m_PadOldState(pPadOldState), m_CurrentSelect(GAME_START)
{
	m_StartPos.x = STARTPOS_X;
	m_StartPos.y = STARTPOS_Y;
	m_StaffPos.x = STAFFPOS_X;
	m_StaffPos.y = STAFFPOS_Y;
	m_EndPos.x = ENDPOS_X;
	m_EndPos.y = ENDPOS_Y;
	m_CursolPos.w = 100;
	m_CursolPos.h = 130;

	m_pLibrary->m_pUVSetter->InitAnima(CURSOL_ANIMA);
}

TitleSelectManager::~TitleSelectManager()
{

}

TITLESELECT_ID TitleSelectManager::Control()
{

	//�R���g���[���[�̓��͂ŏ�Ԃ�ύX����
	//�J�[�\���ʒu�Ȃ񂩂��ς��悤�ɂ��Ă���
	if (m_PadState[PAD_UP] == true && m_PadOldState[PAD_UP] == false)
	{
		switch (m_CurrentSelect)
		{
		case GAME_START:
			m_CurrentSelect = GAME_STAFF;

			break;
		case GAME_STAFF:
			m_CurrentSelect = GAME_START;

			break;
		default:

			break;
		}
	}
	else if (m_PadState[PAD_DOWN] == true && m_PadOldState[PAD_DOWN] == false)
	{
		switch (m_CurrentSelect)
		{
		case GAME_START:
			m_CurrentSelect = GAME_STAFF;

			break;
		case GAME_STAFF:
			m_CurrentSelect = GAME_START;

			break;
		default:

			break;
		}
	}
	else if (m_PadState[PAD_LEFT] == true && m_PadOldState[PAD_LEFT] == false)
	{
		switch (m_CurrentSelect)
		{
		case GAME_START:
			m_CurrentSelect = GAME_END;

			break;
		case GAME_STAFF:
			m_CurrentSelect = GAME_END;

			break;
		default:

			break;
		}
	}
	else if (m_PadState[PAD_RIGHT] == true && m_PadOldState[PAD_RIGHT] == false)
	{
		switch (m_CurrentSelect)
		{
		case GAME_END:
			m_CurrentSelect = GAME_START;

			break;
		default:

			break;
		}
	}


	//�{�^���������ꂽ�猻�ݎw���Ă���I�����ڂ�Ԃ�
	if (m_pLibrary->m_pXInput->m_game_pad_state[GAMEPAD_A] == PAD_PUSH)
	{
		return m_CurrentSelect;
	}

	//�{�^����������Ȃ����TitleSelectNone��Ԃ�
	return TITLESELECT_NONE;
}

void TitleSelectManager::Draw()
{
	CustomVertex Start[4];
	CustomVertex Staff[4];
	CustomVertex End[4];
	CustomVertex Cursol[4];

	//�J�[�\���̈ʒu�ݒ�
	switch (m_CurrentSelect)
	{
	case GAME_START:
		m_CursolPos.x = STARTPOS_X - 350;
		m_CursolPos.y = STARTPOS_Y - 10;

		break;
	case GAME_STAFF:
		m_CursolPos.x = STAFFPOS_X - 350;
		m_CursolPos.y = STAFFPOS_Y - 10;

		break;
	case GAME_END:
		m_CursolPos.x = ENDPOS_X - 100;
		m_CursolPos.y = ENDPOS_Y - 100;

		break;
	}

	//�J�[�\���̃A�j���[�V����
	int CursolId;
	CursolId = m_pLibrary->m_pUVSetter->AnimaControl(m_CursolCurrentAnima);


	//position�̕������ݒ�
	m_pLibrary->m_pUVSetter->MakePosition(TITLE_START, &m_StartPos);
	m_pLibrary->m_pUVSetter->MakePosition(TITLE_STAFF, &m_StaffPos);
	m_pLibrary->m_pUVSetter->MakePosition(TITLE_END, &m_EndPos);



	//tu�@tv�̐ݒ�
	m_pLibrary->m_pUVSetter->MakeVertex(TITLE_START, Start);
	m_pLibrary->m_pUVSetter->MakeVertex(TITLE_STAFF, Staff);
	m_pLibrary->m_pUVSetter->MakeVertex(TITLE_END, End);
	m_pLibrary->m_pUVSetter->MakeVertex(CursolId, Cursol);



	//X y�̐ݒ�
	m_pLibrary->m_pVertex->xySet(m_StartPos, Start);
	m_pLibrary->m_pVertex->xySet(m_StaffPos, Staff);
	m_pLibrary->m_pVertex->xySet(m_EndPos, End);
	m_pLibrary->m_pVertex->xySet(m_CursolPos, Cursol);


	if (m_isSelectFadeout == true)
	{
		m_alpha--;
		if (m_alpha <= 200)
		{
			m_isSelectFadeout = false;
		}
	}
	else
	{
		m_alpha++;
		if (m_alpha >= 255)
		{
			m_isSelectFadeout = true;
		}
	}
	

	switch (m_CurrentSelect)
	{
	case GAME_START:
		for (int i = 0; i < 4; i++)
		{
			Start[i].color = D3DCOLOR_ARGB(m_alpha, COLORMAX, COLORMAX, COLORMAX);
		}

		break;
	case GAME_STAFF:
		for (int i = 0; i < 4; i++)
		{
			Staff[i].color = D3DCOLOR_ARGB(m_alpha, COLORMAX, COLORMAX, COLORMAX);
		}

		break;
	case GAME_END:
		for (int i = 0; i < 4; i++)
		{
			End[i].color = D3DCOLOR_ARGB(m_alpha, COLORMAX, COLORMAX, COLORMAX);
		}


		break;
	}

	//�`��
	m_pLibrary->m_pVertex->Set_Draw_Tex(m_pTexture, Start);
	m_pLibrary->m_pVertex->Set_Draw_Tex(m_pTexture, Staff);
	m_pLibrary->m_pVertex->Set_Draw_Tex(m_pTexture, End);
	m_pLibrary->m_pVertex->Set_Draw_Tex(m_pTexture, Cursol);


}

