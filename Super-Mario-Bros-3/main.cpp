#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include <Game.h> 
#include <Debug.h>

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

#define WINDOW_CLASS_NAME L"Super Mario Bros 3" 
#define WINDOW_TITLE L"Super Mario Bros 3" 
#define WINDOW_ICON_PATH L"mario.ico"
#define MAIN_WINDOW_TITLE L'Super Mario Bros 3"

#define D3DCOLOR_WHITE D3DCOLOR_XRGB(255, 255, 255)
#define BACKGROUND_COLOR D3DCOLOR_XRGB(0,0,0) 


#define WINDOW_WIDTH 640 
#define wiNDOW_HEIGHT 480


HWND hWnd = 0; 

Game* game; 

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

//void Update(DWORD dt) {
//	Game::GetInstance()->Update(dt); 
//}

//void Render() {
//
//	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
//	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
//	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();
//
//	if (d3ddv->BeginScene())
//	{
//		// Clear back buffer with a color
//		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
//
//		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
//
//		Game::GetInstance()->Render();
//
//		spriteHandler->End();
//		d3ddv->EndScene();
//	}
//
//	// Display back buffer content to the screen
//	d3ddv->Present(NULL, NULL, NULL, NULL);
//}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight) {
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, WINDOW_ICON_PATH, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);


	//if (!hWnd)
	//{
	//	DWORD ErrCode = GetLastError();
	//	DebugOut(L"[ERROR] CreateWindow failed! ErrCode: %d\nAt: %s %d \n", ErrCode, _W(__FILE__), __LINE__);
	//	return 0;
	//}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//SetDebugWindow(hWnd);

	return hWnd;


}

void Run() {

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

}

void LoadResources() {

}


