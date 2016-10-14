#ifndef _SCENEMAIN_H_
#define _SCENEMAIN_H_

#include "Game.h"
#include "Utils.h"
#include "Global.h"
#include "GUI.h"
#include "GameObject.h"


class SceneMain: public CGame
{
public: 	

	GameObject *simon;

	LPDIRECT3DSURFACE9 Background;
	SceneMain(int _nCmdShow);
	~SceneMain();	

	RECT rTimer;
	void InitLabels();
	void CountTime();
protected:	

	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

	virtual void OnKeyDown(int KeyCode);
};

#endif