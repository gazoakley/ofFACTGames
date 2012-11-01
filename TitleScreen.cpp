#include "TitleScreen.h"


//--------------------------------------------------------------
void TitleScreen::setup()
{
    screen.setIpServer("192.168.0.200");
    screen.setupSend();
}

//--------------------------------------------------------------
void TitleScreen::update()
{
}

//--------------------------------------------------------------
void TitleScreen::draw()
{
	float hue = fmod(ofGetElapsedTimef() * 10, 360);
	float red; float green; float blue;
	hsl2rgb(hue, 100, 25, red, green, blue);
	ofBackground(red, green, blue, 255);

}

void TitleScreen::flush()
{
    screen.captureScreen(0, 0);
}

void TitleScreen::hsl2rgb(float h, float s, float l, float& r, float& g, float& b)
{
	float L = ((float)l)/100;
	float S = ((float)s)/100;
	float H = ((float)h)/360;

	if(s == 0)
	{
		r = l;
		g = l;
		b = l;
	}
	else
	{
		float temp1 = 0;
		if(L < .50)
		{
			temp1 = L*(1 + S);
		}
		else
		{
			temp1 = L + S - (L*S);
		}

		float temp2 = 2*L - temp1;

		float temp3 = 0;
		for(int i = 0 ; i < 3 ; i++)
		{
			switch(i)
			{
			case 0: // red
				{
					temp3 = H + .33333f;
					if(temp3 > 1)
						temp3 -= 1;
					hue2rgb(r,temp1,temp2,temp3);
					break;
				}
			case 1: // green
				{
					temp3 = H;
					hue2rgb(g,temp1,temp2,temp3);
					break;
				}
			case 2: // blue
				{
					temp3 = H - .33333f;
					if(temp3 < 0)
						temp3 += 1;
					hue2rgb(b,temp1,temp2,temp3);
					break;
				}
			default:
				{

				}
			}
		}
	}
	r = (((float)r)/100)*255;
	g = (((float)g)/100)*255;
	b = (((float)b)/100)*255;
}

void TitleScreen::hue2rgb(float& c, const float& temp1, const float& temp2, const float& temp3)
{
	if((temp3 * 6) < 1)
		c = (temp2 + (temp1 - temp2)*6*temp3)*100;
	else
		if((temp3 * 2) < 1)
			c = temp1 * 100;
		else
			if((temp3 * 3) < 2)
				c = (temp2 + (temp1 - temp2)*(.66666 - temp3)*6)*100;
			else
				c = temp2 * 100;
	return;
}