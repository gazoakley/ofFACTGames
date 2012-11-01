#include "SnakeGame.h"

#include <math.h>

int xBite;
int yBite;
int score;

//--------------------------------------------------------------
void SnakeGame::setup(){
	super::setup();

	//old OF default is 96 - but this results in fonts looking larger than in other programs. 
	ofTrueTypeFont::setGlobalDpi(72);

	// Text font
	verdana14.loadFont("verdana.ttf", 14, true, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);

	// Framerate
	ofSetFrameRate(5);
    
    // Setup controller
	ofxGamepadHandler::get()->enableHotplug();
    
    //CHECK IF THERE EVEN IS A GAMEPAD CONNECTED
    if(ofxGamepadHandler::get()->getNumPads()>0)
    {
        cout << "Gamepad enabled!" << endl;
        ofxGamepad* pad = ofxGamepadHandler::get()->getGamepad(2);
        cout << "Using: " << pad->name << endl;
        ofAddListener(pad->onAxisChanged, this, &SnakeGame::axisChanged);
        ofAddListener(pad->onButtonPressed, this, &SnakeGame::buttonPressed);
        ofAddListener(pad->onButtonReleased, this, &SnakeGame::buttonReleased);
    }
    
    // Start game
    startGame();
}

void SnakeGame::startGame()
{
    // Position snake
    snake1.setPosition(18, 25);
    snake1.setDirection(0, -1);
    
    // Place bite down
    moveBite();
    
    isPlaying = true;
}

void SnakeGame::stopGame()
{
    isPlaying = false;
}

//--------------------------------------------------------------
void SnakeGame::update(){
	super::update();
    
    if (!isPlaying) return;

	// Update snakes
	snake1.update();
    //snake2.update();
    
    // Got bite?
    if (snake1.isHead(xBite, yBite))
    {
        snake1.setGrow(2);
        moveBite();
    }
    
    // Hit border?
    if (snake1.isBorder())
    {
        stopGame();
    }
}

void SnakeGame::moveBite()
{
    do
    {
        xBite = (rand() % 48) + 1;
        yBite = (rand() % 48) + 1;
    }
    while (snake1.isHead(xBite, yBite));
}

//--------------------------------------------------------------
void SnakeGame::draw(){
	super::draw();

	// Draw label
    ofEnableAlphaBlending();
    if (isPlaying) ofSetColor(255, 255, 255, 63);
	verdana14.drawString("snake", 4, 30);
    ofSetColor(255, 255, 255, 255);
    
    // Draw border
    ofNoFill();
    ofRect(0.5, 0.5, 49, 49);
    ofFill();
    
    if (isPlaying)
    {
        // Draw snakes
        snake1.draw();
        
        // Draw bite
        drawBite();
    }
    
    // Output
    TitleScreen::flush();
}

void SnakeGame::drawBite()
{
    ofRect(xBite, yBite, 1, 1);
}

//--------------------------------------------------------------
void SnakeGame::keyPressed(int key){
	cout << "keyPressed " << key << endl;
	switch (key)
	{
	case 356:
        cout << "1: Left";
		snake1.setDirection(-1, 0);
		break;
	case 357:
        cout << "1:Up";
		snake1.setDirection(0, -1);
		break;
	case 358:
        cout << "1: Right";
		snake1.setDirection(1, 0);
		break;
	case 359:
        cout << "1: Down";
		snake1.setDirection(0, 1);
		break;
    case 97:
        cout << "2: Left";
        snake2.setDirection(-1, 0);
        break;
    case 119:
        cout << "2: Up";
        snake2.setDirection(0, -1);
        break;
    case 100:
        cout << "2: Right";
        snake2.setDirection(1, 0);
        break;
    case 115:
        cout << "2: Down";
        snake2.setDirection(0, 1);
        break;
	}
}

void SnakeGame::axisChanged(ofxGamepadAxisEvent& e)
{
    cout << "AXIS " << e.axis << " VALUE " << ofToString(e.value) << endl;
}

void SnakeGame::buttonPressed(ofxGamepadButtonEvent& e)
{
    cout << "BUTTON " << e.button << " PRESSED" << endl;
}

void SnakeGame::buttonReleased(ofxGamepadButtonEvent& e)
{
    if (!isPlaying)
    {
        startGame();
        return;
    }
    switch (e.button)
    {
        case 0:
            cout << "1:Up";
            snake1.setDirection(0, -1);
            break;
        case 1:
            cout << "1: Down";
            snake1.setDirection(0, 1);
            break;
        case 2:
            cout << "1: Left";
            snake1.setDirection(-1, 0);
            break;
        case 3:
            cout << "1: Right";
            snake1.setDirection(1, 0);
            break;
    }
    cout << "BUTTON " << e.button << " RELEASED" << endl;
}

//--------------------------------------------------------------
void SnakeGame::keyReleased(int key){
	cout << "keyReleased " << key << endl;
}

//--------------------------------------------------------------
void SnakeGame::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void SnakeGame::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void SnakeGame::windowResized(int w, int h){

}

//--------------------------------------------------------------
void SnakeGame::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void SnakeGame::dragEvent(ofDragInfo dragInfo){ 

}