#include "Snake.h"

Snake::Snake(void)
{
	x[0] = 25;
	y[0] = 25;

	xV = -1;
	yV = 0;

	head = 0;
	tail = 0;
	grow = 5;
}

void Snake::update()
{
	// Update head
	int newhead = (head + 1) % 100;
	x[newhead] = x[head] + xV;
	y[newhead] = y[head] + yV;

	// Move head/tail
	head = newhead;
	if (grow > 0)
    {
        grow--;
    }
	else
    {
        tail = (tail + 1) % 100;
    }
}

void Snake::draw()
{
	// Draw snake
	ofSetColor(255);
	int length = ((head - tail) + 100) % 100;
	//cout << "Length: " << length << endl;

	for (int i = 0; i < length; i++)
	{
		int pos = (tail + i) % 100;
        //cout << "Position: " << pos << "\tX: " << x[pos] << "\tY: " << y[pos] << endl;
		ofRect(x[pos], y[pos], 1, 1);
	}
    
    //cout << "--------" << endl;
}

void Snake::setDirection(int x, int y)
{
    if (abs(xV) != abs(x)) xV = x;
	if (abs(yV) != abs(y)) yV = y;
}

void Snake::setPosition(int xpos, int ypos)
{
    x[head] = xpos;
    y[head] = ypos;
}

bool Snake::isCollide(int xpos, int ypos)
{
	int length = ((head - tail) + 100) % 100;
    
	for (int i = 0; i < length; i++)
	{
		int pos = (tail + i) % 100;
        if ((x[pos] == xpos) & (y[pos] == ypos)) return true;
	}
    
    return false;
}

bool Snake::isHead(int xpos, int ypos)
{
    return (x[head] == xpos) & (y[head] == ypos);
}

bool Snake::isBorder()
{
    int xpos = x[head];
    int ypos = y[head];
    return (xpos <= 0) | (xpos >= 49) | (ypos <= 0) | (ypos >= 49);
}

void Snake::setGrow(int growAmount)
{
    grow = growAmount;
}