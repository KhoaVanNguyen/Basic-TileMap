
#include "SceneMain.h"
#include <fstream>
int start = 0;
#include <fstream>
ofstream myfile("trace.txt");


void KeepTrack(float value1, float value2) {

	if (myfile.is_open())
	{
		myfile << "normalx = " << value1 << "\n";
		myfile << "normaly = " << value2 << "\n";
		//myfile.close();
	}
	else {
		//MessageBox(hwnd, "Error initializing the mouse", "Error", MB_OK);
	}
}
void KeepTrack(float value1) {

	if (myfile.is_open())
	{
		myfile << "collisiontime = " << value1 << "\n";
		//myfile.close();
	}
	else {
		//MessageBox(hwnd, "Error initializing the mouse", "Error", MB_OK);
	}
}
void SceneMain::CountTime() {
		if (GetTickCount() - start > 1000) {
			
			start = GetTickCount();
		}
}
void DrawBackground(LPDIRECT3DDEVICE9 d3ddv) {
	LPDIRECT3DSURFACE9 background;
	background = CreateSurfaceFromFile(d3ddv, "background.jpg");
	d3ddv->StretchRect(background, NULL, G_BackBuffer, NULL, D3DTEXF_NONE);
}
void SceneMain::InitLabels() {
	
}
SceneMain::SceneMain(int _nCmdShow): CGame(_nCmdShow)
{

}
void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	d3ddv->StretchRect(
		Background,			// from 
		NULL,				// which portion?
		G_BackBuffer,		// to 
		NULL,				// which portion?
		D3DTEXF_NONE);

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	simon->Draw();

	G_SpriteHandler->End();
	
}
void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	

}
void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	srand((unsigned)time(NULL));

	D3DXCreateSprite(d3ddv, &G_SpriteHandler);

	Background = CreateSurfaceFromFile(d3ddv, "Resources/background.jpg");

	HRESULT res = D3DXCreateSprite(d3ddv, &G_SpriteHandler);

	simon = new GameObject(20, 40);
}
void SceneMain::OnKeyDown(int KeyCode)
{
}
SceneMain::~SceneMain(void)
{
}
