#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include <d3dx9.h>
class Library;
class Scene;
enum SCENE_NUM;

////////FileInfo
// 1　GameScene
// 2　LogoScene
// 3　TitleScene
// 4　ConnetingScene
// 5　ResultScene
// 6　OpeningScene
// 7
// 8
///////

class SceneManager
{
private:
	SCENE_NUM	m_NextScene;
	Library*	m_pLibrary;

public:
	SceneManager(Library* pLibrary);
	~SceneManager();
	bool Control();
	void Draw();
	Scene*		m_pScene;	
};

#endif