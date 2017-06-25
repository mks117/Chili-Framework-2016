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
}


int x = 50;
int y = 50;

int r, g, b = 255;

void Game::ComposeFrame()
{

	// move reticle left
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x = x - 10;
	}

	// move reticle right
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x = x + 10;
	}

	// move reticle down
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y = y + 10;
	}

	// move reticle up
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y = y - 10;
	}


	// draw the reticle
	
	// left
	gfx.PutPixel( -5 + x,      y, r, g, b);
	gfx.PutPixel( -4 + x,      y, r, g, b);
	gfx.PutPixel( -3 + x,      y, r, g, b);

	// right
	gfx.PutPixel( 3 + x,      y, r, g, b);
	gfx.PutPixel( 4 + x,      y, r, g, b);
	gfx.PutPixel( 5 + x,      y, r, g, b);

	// down
	gfx.PutPixel(     x, -5 + y, r, g, b);
	gfx.PutPixel(     x, -4 + y, r, g, b);
	gfx.PutPixel(     x, -3 + y, r, g, b);

	// up
	gfx.PutPixel(     x,  3 + y, r, g, b);
	gfx.PutPixel(     x,  4 + y, r, g, b);
	gfx.PutPixel(     x,  5 + y, r, g, b);
}


