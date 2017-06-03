/**
 * Project:		GameStateManager
 * File Name:	Input.c
 * Author:		王晶
 * Date:		2017-4-22
 * Purpose:		输入模块
 */

#include "System.h"
#include "Input.h"
#include "GameStateList.h"

 //------------------------------------------------------------------------------
 // Private Consts:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Private Structures:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Variables:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Private Variables:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Private Function Declarations:
 //------------------------------------------------------------------------------

 //------------------------------------------------------------------------------
 // Public Functions:
 //------------------------------------------------------------------------------

LRESULT CALLBACK Input_Handle(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC dc;
	PAINTSTRUCT ps;

					  // 签到
					  //fprintf(fp,"Input:Handle\n");

	switch (msg)
	{
		//  窗口创建
	case WM_CREATE:
		break;

	case WM_LBUTTONDOWN:
		//GS_Running = 0;
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
		fprintf(fp, "Input:Forcing Shut Down\n");
		printf("Input:Forcing Shut Down\n");
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			KeyPressed[KeyESC] = TRUE;
			fprintf(fp, "Input:ESC\n");
			printf("Input:ESC\n");
		}
		if (wParam == 'R')
		{
			KeyPressed[KeyR] = TRUE;
			fprintf(fp, "Input:R\n");
			printf("Input:R\n");
		}
		if (wParam == '1')
		{
			KeyPressed[Key1] = TRUE;
			fprintf(fp, "Input:1\n");
			printf("Input:1\n");
		}
		if (wParam == '2')
		{
			KeyPressed[Key2] = TRUE;
			fprintf(fp, "Input:2\n");
			printf("Input:2\n");
		}
		if (wParam == VK_UP)
			KeyPressed[KeyUp] = TRUE;
		if (wParam == VK_DOWN)
			KeyPressed[KeyDown] = TRUE;
		if (wParam == VK_LEFT)
			KeyPressed[KeyLeft] = TRUE;
		if (wParam == VK_RIGHT)
			KeyPressed[KeyRight] = TRUE;
		if (wParam == VK_SPACE)
		{
			KeyPressed[KeySpace] = TRUE;
			fprintf(fp, "Input:Space\n");
			printf("Input:Space\n");
		}
		if (wParam == 'W')
		{
			KeyPressed[KeyW] = TRUE;
			fprintf(fp, "Input:W\n");
			printf("Input:W\n");
		}
		if (wParam == 'S')
		{
			KeyPressed[KeyS] = TRUE;
			fprintf(fp, "Input:S\n");
			printf("Input:S\n");
		}
		if (wParam == 'J')
		{
			KeyPressed[KeyJ] = TRUE;
			fprintf(fp, "Input:J\n");
			printf("Input:J\n");
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

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------


