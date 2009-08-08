/**
 * GameJam 2009 - GamePlay
 *
 * The main Input Class
 */
 
#include "CInput.h"

CInput::CInput()
{
	fMouseLeft = false;
	fMouseRight = false;
}

bool CInput::isMouseLeftClick()
{
	if (mouse_b & 1)
	{
		if (!fMouseLeft)
		{
			fMouseLeft = true;
			return true;
		}
	}
	else
	{
		fMouseLeft = false;
	}
}

bool CInput::isMouseRightClick()
{
	if (mouse_b & 1)
	{
		if (!fMouseRight)
		{
			fMouseRight = true;
			return true;
		}
	}
	else
	{
		fMouseRight = false;
	}
	
	return false;
}

void CInput::update()
{

}
 