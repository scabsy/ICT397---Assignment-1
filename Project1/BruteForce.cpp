#include "BruteForce.h"



void BruteForce::Render(void)
{
	unsigned char hcolor; //color of the height
	float texLeft, texBot, texTop,height;
	flatten = 4;

	if (textureMapping)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	for (int z = 0; z<getSize() - 1; z++) 
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (int x = 0; x<getSize(); x++) 
		{
			texLeft = (float)x / getSize();
			texBot = (float)z / getSize();
			texTop = (float)(z+1) / getSize();
			height = getHeight(x, z) / flatten;

			//create the the first point in the triangle strip
			hcolor = getHeightColor(x, z);
			glColor3ub(hcolor, hcolor, hcolor);
			glTexCoord2f(texLeft, texBot);
			glVertex3f((float)x*scaleX, height, (float)z*scaleZ);

			height = getHeight(x, z+1) / flatten; 
			//create the next point in the triangle strip
			hcolor = getHeightColor(x, z + 1);
			glColor3ub(hcolor, hcolor, hcolor);
			glTexCoord2f(texLeft, texTop);
			glVertex3f((float)x*scaleX, height, (float)(z + 1)*scaleZ);
				
		}
		glEnd();
	}
}
