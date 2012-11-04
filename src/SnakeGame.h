#pragma once

#include "ofMain.h"
#include "ofTrueTypeFont.h"
//#include "ofxGamepadHandler.h"

#include "TitleScreen.h"
#include "Snake.h"

class SnakeGame : public TitleScreen
{

	public:
		typedef TitleScreen super;

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        //void axisChanged(ofxGamepadAxisEvent &e);
        //void buttonPressed(ofxGamepadButtonEvent &e);
        //void buttonReleased(ofxGamepadButtonEvent &e);

	private:
		ofTrueTypeFont verdana14;
		Snake snake1;
        Snake snake2;
        bool isPlaying;
        void moveBite();
        void drawBite();
        void startGame();
        void stopGame();
};
