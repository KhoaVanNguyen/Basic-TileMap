
#include "SceneMain.h"
#include <fstream>

int start = 0;
#include <fstream>
ofstream myfile("trace.txt");


int tileMap[10][48] = {
	0, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 0, 0, 0, 0, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 6, 5, 6, 7, 8,
	9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 0, 0, 0, 0, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 4, 11, 4, 11, 12, 8,
	13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 1, 2, 1, 2, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 8, 15, 16, 11, 16, 11, 17, 8,
	9, 10, 18, 19, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 18, 19, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 9, 10, 18, 19, 18, 19, 8, 4, 20, 21, 4, 11, 22, 8,
	13, 14, 23, 24, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 23, 24, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 13, 14, 23, 24, 23, 24, 8, 25, 26, 8, 16, 11, 7, 8,
	18, 19, 8, 8, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 8, 8, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 18, 19, 8, 8, 8, 8, 8, 4, 22, 8, 4, 11, 12, 8,
	23, 24, 27, 28, 23, 24, 23, 24, 23, 24, 23, 24, 23, 24, 23, 24, 23, 24, 27, 28, 23, 24, 23, 24, 23, 24, 23, 24, 23, 24, 23, 24, 23, 24, 23, 24, 27, 28, 8, 8, 8, 25, 7, 8, 16, 11, 17, 8,
	29, 30, 31, 32, 8, 8, 29, 30, 29, 30, 8, 8, 29, 30, 8, 8, 29, 30, 31, 32, 8, 8, 29, 30, 29, 30, 8, 8, 29, 30, 8, 8, 8, 8, 8, 8, 31, 32, 8, 8, 8, 25, 33, 8, 25, 34, 12, 8,
	35, 36, 37, 38, 39, 39, 35, 36, 35, 36, 39, 39, 35, 36, 39, 39, 35, 36, 37, 38, 39, 39, 35, 36, 35, 36, 39, 39, 35, 36, 39, 39, 39, 39, 40, 41, 37, 38, 42, 43, 44, 45, 46, 8, 46, 47, 17, 8,
	48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48, 48
};

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
	//d3ddv->StretchRect(
	//	Background,			// from 
	//	NULL,				// which portion?
	//	G_BackBuffer,		// to 
	//	NULL,				// which portion?
	//	D3DTEXF_NONE);

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	for (int row = 0; row<MAP_HEIGHT; row++)       // for each row of map
	{
		int y = (int)(row*TEXTURE_SIZE);
		for (int col = 0; col<MAP_WIDTH; col++)    // for each column of map
		{
			if (tileMap[row][col] > 0)          // if tile present
			{
			 // set tile X
				int x = ((int)(col*TEXTURE_SIZE));
				// if tile on screen
				if (x > -TEXTURE_SIZE && x < G_ScreenWidth)

					bg->sprite->DrawIndex(tileMap[row][col], x, y);
			}
		}
	}


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
	
	bg = new GameObject(0,0);
}
void SceneMain::OnKeyDown(int KeyCode)
{
}
SceneMain::~SceneMain(void)
{
}
