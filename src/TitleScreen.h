#pragma once

#include "ofMain.h"
#include "ofxFACTLiverpoolScreen.h"

class TitleScreen : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();
        void flush();

	private:
		void hsl2rgb(float hue, float saturation, float luminance, float& red, float& green, float& blue);
		void hue2rgb(float& c, const float& temp1, const float& temp2, const float& temp3);
    
        ofxFACTLiverpoolScreen screen;
};

