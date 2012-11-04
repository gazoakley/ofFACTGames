#include "testApp.h"
#include "ofAppGlutWindow.h"
#include "SnakeGame.h"

//--------------------------------------------------------------
int main(){
	ofAppGlutWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	ofSetupOpenGL(&window, 50, 50, OF_WINDOW);
	//ofRunApp(new testApp()); // start the app
	//ofRunApp(new TitleScreen()); // start the app
    ofRunApp(new SnakeGame()); // start the app
}
