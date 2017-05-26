/**
 * Project:		GameStateManager
 * File Name:	Input.c
 * Author:		����
 * Date:		2017-4-22
 * Purpose:		����ģ��
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

					  // ǩ��
					  //fprintf(fp,"Input:Handle\n");

	switch (msg)
	{
		//  ���ڴ���
	case WM_CREATE:
		break;

	case WM_LBUTTONDOWN:
		//GS_Running = 0;
		break;

	case WM_MOUSEMOVE:
		break;

		// �ػ�
	case WM_PAINT:
		BeginPaint(hWnd, &ps); //Ϊָ�����hwnd���ڽ��л滭׼������  
		EndPaint(hWnd, &ps);
		break;
		// ���ڹر�
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
		break;

		// ���ڷ����ƶ�
	case WM_MOVE:
		break;

		// ����Ĭ�ϴ��ڹ���
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


