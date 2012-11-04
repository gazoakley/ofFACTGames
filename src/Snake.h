#pragma once

#include "ofMain.h"

class Snake
{
	public:
		Snake(void);

		void update();
		void draw();
		void setDirection(int x, int y);
        void setPosition(int xpos, int ypos);
        bool isCollide(int xpos, int ypos);
        bool isHead(int xpos, int ypos);
        bool isBorder();
        void setGrow(int grow);

	private:
		int x[100];
		int y[100];

		int xV;
		int yV;

		int head;
		int tail;
		int grow;

};

