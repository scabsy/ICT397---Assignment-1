#ifndef INPUT_H
#define INPUT_H

/**
* Manages input from user
*/
class Input
{
private:
	int screenW;
	int screenH;

	bool wired;
	int oldx;
	int oldy;
public: 
	Input();
	void keys(unsigned char key, int x, int y);
	void mouseMove(int x, int y);
	void mouseClicks(int button, int state, int x, int y);
};

#endif
