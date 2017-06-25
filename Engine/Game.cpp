/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	// move reticle left
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{

		}
		else
		{
			vx = vx - 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}

	// move reticle right
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (inhibitRight)
		{

		}
		else
		{
			vx = vx + 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}

	// move reticle down
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{

		}
		else
		{
			vy = vy + 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}

	// move reticle up
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{

		}
		else
		{
			vy = vy - 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}

	x = x + vx;
	y = y + vy;

	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
}





int r, g, b = 255;

void Game::ComposeFrame()
{


	// draw the reticle
	if (!shapeIsChanged) 
	{
		// left
		gfx.PutPixel(-5 + x, y, r, g, b);
		gfx.PutPixel(-4 + x, y, r, g, b);
		gfx.PutPixel(-3 + x, y, r, g, b);

		// right
		gfx.PutPixel(3 + x, y, r, g, b);
		gfx.PutPixel(4 + x, y, r, g, b);
		gfx.PutPixel(5 + x, y, r, g, b);

		// down
		gfx.PutPixel(x, -5 + y, r, g, b);
		gfx.PutPixel(x, -4 + y, r, g, b);
		gfx.PutPixel(x, -3 + y, r, g, b);

		// up
		gfx.PutPixel(x, 3 + y, r, g, b);
		gfx.PutPixel(x, 4 + y, r, g, b);
		gfx.PutPixel(x, 5 + y, r, g, b);

	}

	else
	{

		// top left
		gfx.PutPixel(-5 + x, y - 5, r, g, b);
		gfx.PutPixel(-4 + x, y - 5, r, g, b);
		gfx.PutPixel(-3 + x, y - 5, r, g, b);

		// left top
		gfx.PutPixel(x - 5, y - 3, r, g, b);
		gfx.PutPixel(x - 5, y - 4, r, g, b);



		// top right
		gfx.PutPixel(5 + x, y - 5, r, g, b);
		gfx.PutPixel(4 + x, y - 5, r, g, b);
		gfx.PutPixel(3 + x, y - 5, r, g, b);

		// right top
		gfx.PutPixel(x + 5, y - 3, r, g, b);
		gfx.PutPixel(x + 5, y - 4, r, g, b);



		// bottom left
		gfx.PutPixel(-5 + x, y + 5, r, g, b);
		gfx.PutPixel(-4 + x, y + 5, r, g, b);
		gfx.PutPixel(-3 + x, y + 5, r, g, b);

		// left bottom
		gfx.PutPixel(x - 5, y + 3, r, g, b);
		gfx.PutPixel(x - 5, y + 4, r, g, b);



		// bottom right
		gfx.PutPixel(5 + x, y + 5, r, g, b);
		gfx.PutPixel(4 + x, y + 5, r, g, b);
		gfx.PutPixel(3 + x, y + 5, r, g, b);

		// right bottom
		gfx.PutPixel(x + 5, y + 3, r, g, b);
		gfx.PutPixel(x + 5, y + 4, r, g, b);

		
	}
}


