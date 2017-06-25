/**
 * Project:		GeometryRun
 * File Name:	Input.c
 * Author:		王晶
 * Date:		2017-4-22
 * Purpose:		输入模块
 */

#include "System.h"
#include "Input.h"
#include "GameStateList.h"

int KeyPressed[KeyNUM];

POINT mousPos;
int posType;

LRESULT CALLBACK Input_Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC dc;
	PAINTSTRUCT ps;

	switch (msg)
	{
		//  窗口创建
	case WM_CREATE:
		break;
	case WM_MOUSEMOVE:
		break;

		// 重绘
	case WM_PAINT:
		BeginPaint(hWnd, &ps); //为指定句柄hwnd窗口进行绘画准备工作  
		EndPaint(hWnd, &ps);
		break;
		// 窗口关闭
	case WM_DESTROY:
		KeyPressed[KeyESC] = TRUE;
		// 最终版取消控制台printf("Input:Forcing Shut Down\n");
		break;
	case WM_LBUTTONDOWN:
		KeyPressed[KeyLButton] = TRUE;
		GetCursorPos(&mousPos);
		ScreenToClient(hWnd, &mousPos);
		// 最终版取消控制台printf("MousePos: %d, %d\n", mousPos.x, mousPos.y);
		break;
	case WM_LBUTTONUP:
		KeyPressed[KeyLButton] = FALSE;
		break;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			KeyPressed[KeyESC] = TRUE;
			// 最终版取消控制台printf("Input:ESC\n");
		}
		if (wParam == 'R')
		{
			KeyPressed[KeyR] = TRUE;
			// 最终版取消控制台printf("Input:R\n");
		}
		if (wParam == 'M')
		{
			KeyPressed[KeyM] = TRUE;
			// 最终版取消控制台printf("Input:M\n");
		}
		if (wParam == '0')
		{
			KeyPressed[Key0] = TRUE;
			// 最终版取消控制台printf("Input:0\n");
		}
		if (wParam == '1')
		{
			KeyPressed[Key1] = TRUE;
			// 最终版取消控制台printf("Input:1\n");
		}
		if (wParam == '2')
		{
			KeyPressed[Key2] = TRUE;
			// 最终版取消控制台printf("Input:2\n");
		}
		if (wParam == '3')
		{
			KeyPressed[Key3] = TRUE;
			// 最终版取消控制台printf("Input:3\n");
		}
		if (wParam == '4')
		{
			KeyPressed[Key4] = TRUE;
			// 最终版取消控制台printf("Input:4\n");
		}
		if (wParam == '6')
			KeyPressed[Key6] = TRUE;
		if (wParam == '7')
			KeyPressed[Key7] = TRUE;
		if (wParam == '8')
			KeyPressed[Key8] = TRUE;
		if (wParam == VK_UP)
			KeyPressed[KeyUp] = TRUE;
		if (wParam == VK_DOWN)
			KeyPressed[KeyDown] = TRUE;
		if (wParam == VK_SPACE)
		{
			KeyPressed[KeySpace] = TRUE;
			// 最终版取消控制台printf("Input:Space\n");
		}
		if (wParam == 'W')
		{
			KeyPressed[KeyW] = TRUE;
			// 最终版取消控制台printf("Input:W\n");
		}
		if (wParam == 'S')
		{
			KeyPressed[KeyS] = TRUE;
			// 最终版取消控制台printf("Input:S\n");
		}
		if (wParam == 'J')
		{
			KeyPressed[KeyJ] = TRUE;
			// 最终版取消控制台printf("Input:J\n");
		}
		if (wParam == 'P')
		{
			KeyPressed[KeyP] = TRUE;
			// 最终版取消控制台printf("Input:P\n");
		}
		if (wParam == 'K')
		{
			KeyPressed[KeyK] = TRUE;
			// 最终版取消控制台printf("Input:K\n");
		}
		if (wParam == 'B')
		{
			KeyPressed[KeyB] = TRUE;
			// 最终版取消控制台printf("Input:B\n");
		}
		if (wParam == VK_F1)
		{
			KeyPressed[KeyVolumeStop] = TRUE;
			// 最终版取消控制台printf("Input:=\n");
		}
		if (wParam == VK_F2)
		{
			KeyPressed[KeyVolumeDown] = TRUE;
			// 最终版取消控制台printf("Input:-\n");
		}
		if (wParam == VK_F3)
		{
			KeyPressed[KeyVolumeUp] = TRUE;
			// 最终版取消控制台printf("Input:+\n");
		}
		break;

		// 窗口发生移动
	case WM_MOVE:
		break;

		// 调用默认窗口过程
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}

void Input_Initialize()
{
	int i;
	for (i = 0; i<KeyNUM; i++)
	{
		KeyPressed[i] = FALSE;
	}
}

