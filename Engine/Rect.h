#pragma once
#include "Graphics.h"
#include "Colors.h"

class Rect
{
public:
	Rect(int sX, int sY, int sHW, int sH, Color sC)
		:
		x(sX),
		y(sY),
		halfWidth(sHW),
		height(sH),
		col(sC)
	{}
	Rect() = default;

	void InitRect(const Rect& sRect)
	{
		Rect(sRect.x, sRect.y, sRect.halfWidth, sRect.height, sRect.col);
	}

	void Draw(Graphics& gfx) const
	{
		for (int i = y - height; i < y; i++)
		{
			for (int j = x - halfWidth; j < x + halfWidth; j++)
			{
				gfx.PutPixel(j, i, Colors::LightGray);
			}
		}
		for (int i = y - height + 1; i < y - 1; i++)
		{
			for (int j = x - halfWidth + 1; j < x + halfWidth - 1; j++)
			{
				gfx.PutPixel(j, i, col);
			}
		}
	}
public:
	int x;
	int y;
	int halfWidth;
	int height;
	Color col;
};

class BackG : public Rect
{
public:
	BackG(Color sC)
		:
		Rect(Graphics::ScreenWidth / 2, Graphics::ScreenHeight, Graphics::ScreenWidth / 2, Graphics::ScreenHeight, sC)
	{}
	void Draw(Graphics& gfx) const
	{
		for (int i = y - height; i < y; i++)
		{
			for (int j = x - halfWidth; j < x + halfWidth; j++)
			{
				gfx.PutPixel(j, i, col);
			}
		}
	}
};