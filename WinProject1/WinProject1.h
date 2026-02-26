#pragma once

#include "resource.h"


typedef enum {
	RECTANGLE, CIRCLE, LINE, FREE
} DRAW_MODE;


void ShowHello(HWND hWnd, HDC hdc);
void ShowRectangle(HWND hWnd, HDC hdc);
void ShowMouseLocation(HWND hWnd, int xPos, int yPos);

void CreateGlobalMemDC(HWND hWnd);
void DestroyGlobalMemDC();
