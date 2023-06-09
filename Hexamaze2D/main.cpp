#include<Gl/glut.h>
#include<math.h>
#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include "wtypes.h"

#include "HGon.h"
#include "Door.cpp"
#include "Pearl.cpp"
#include "Key.h"
#include "Tunnel.h"
#include "Wheel.cpp"
#include "Mitra.cpp"

extern float hWidth;

void drawScoreboard();


int
	d0[6] = { -1,-1,0,-1,-1,-1 },
	d1[6] = { -1,-1,-1,1,-1,-1 },
	d2[6] = { -1,-1,2,-1,-1,0 },
	d3[6] = { -1,-1,-1,3,-1,-1 },
	d4[6] = { 1,-1,-1,6,-1,2 },
	d5[6] = { -1,-1,-1,7,4,-1 },
	d6[6] = { -1,-1,-1,-1,5,-1 },
	d7[6] = { 3,-1,9,-1,8,-1 },
	d8[6] = { -1,4,10,-1,-1,-1 },
	d9[6] = { -1,5,-1,-1,11,-1 },
	d10[6] = { 6,8,-1,-1,-1,-1 },
	d11[6] = { -1,-1,12,15,-1,9 },
	d12[6] = { 7,11,14,16,13,10 },
	d13[6] = { -1,-1,-1,17,-1,-1 },
	d14[6] = { -1,13,-1,20,-1,12 },
	d15[6] = { -1,-1,18,-1,14,-1 },
	d16[6] = { -1,-1,-1,-1,19,-1 },
	d17[6] = { 15,-1,-1,23,-1,-1 },
	d18[6] = { 16,-1,-1,24,-1,-1 },
	d19[6] = { 17,19,22,25,21,18 },
	d20[6] = { -1,-1,26,-1,-1,-1 },
	d21[6] = { 20,-1,-1,-1,-1,-1 },
	d22[6] = { -1,21,-1,-1,-1,-1 },
	d23[6] = { -1,-1,-1,-1,-1,22 },
	d24[6] = { 23,-1,-1,-1,-1,26 },
	d25[6] = { 24,-1,-1,-1,-1,-1 },
	d26[6] = { 25,-1,-1,-1,-1,-1 }
;
HGon hgons[27] = {
	HGon(-6,8,d0),
	HGon(-4,8,d1), HGon(-5,7,d2), HGon(-3,7,d3), HGon(-4,6,d4),
	HGon(0,6,d5), HGon(2,6,d6), HGon(-3,5,d7), HGon(-1,5,d8),
	HGon(1,5,d9), HGon(-4,4,d10), HGon(-2,4,d11), HGon(0,4,d12),
	HGon(2,4,d13), HGon(-1,3,d14), HGon(1,3,d15), HGon(3,3,d16),
	HGon(-2,2,d17), HGon(0,2,d18), HGon(2,2,d19), HGon(-3,1,d20),
	HGon(-1,1,d21), HGon(1,1,d22), HGon(3,1,d23), HGon(-2,0,d24),
	HGon(0,0,d25), HGon(2,0,d26)
};

Door doors[27] = {
	Door(-11,15,1,0,2),
	Door(-8,14,0,1,4), Door(-9,13,1,2,4), Door(-6,12,0,3,7), Door(-1,11,-1,5,8),
	Door(3,11,-1,6,9), Door(-8,10,0,4,10), Door(0,10,0,5,12), Door(-7,9,-1,7,10),
	Door(-5,9,1,7,11), Door(-1,9,1,8,12), Door(1,9,-1,9,12), Door(-3,7,1,11,14),
	Door(-1,7,-1,12,14), Door(1,7,1,12,15), Door(-4,6,0,11,17), Door(0,6,0,12,18),
	Door(4,6,0,13,19), Door(3,5,1,15,19), Door(5,5,-1,16,19), Door(-2,4,0,14,21),
	Door(3,3,-1,19,22), Door(5,3,1,19,23), Door(-4,2,0,17,24), Door(0,2,0,18,25),
	Door(4,2,0,19,26), Door(-5,1,1,20,24)
};


Pearl pearls[50] = {
	Pearl(hgons[18].location, 0, 18),Pearl(hgons[18].location, 1, 18),
	Pearl(hgons[8].location, 0, 8),Pearl(hgons[8].location, 2, 8),
	Pearl(hgons[5].location, 0, 5),Pearl(hgons[5].location, 1, 5), Pearl(hgons[5].location, 3, 5),
	Pearl(hgons[9].location, 5, 9),Pearl(hgons[9].location, 3, 9),
	Pearl(hgons[13].location, 0, 13),Pearl(hgons[13].location, 1,13),Pearl(hgons[13].location, 2, 13),Pearl(hgons[13].location, 3, 13), Pearl(hgons[13].location, 4, 13),
	Pearl(hgons[16].location, 0, 16),Pearl(hgons[16].location, 1, 16),Pearl(hgons[16].location, 2, 16),Pearl(hgons[16].location, 3, 16), Pearl(hgons[16].location, 4, 16),
	Pearl(hgons[23].location, 0, 23),Pearl(hgons[23].location, 1, 23),Pearl(hgons[23].location, 2, 23),Pearl(hgons[23].location, 3, 23), Pearl(hgons[23].location, 4, 23),
	Pearl(hgons[26].location, 0, 26),Pearl(hgons[26].location, 1, 26),Pearl(hgons[26].location, 2, 26),Pearl(hgons[26].location, 3, 26), Pearl(hgons[26].location, 4, 26),
	Pearl(hgons[22].location, 0, 22),Pearl(hgons[22].location, 1, 22),Pearl(hgons[22].location, 2, 22),Pearl(hgons[22].location, 3, 22), Pearl(hgons[22].location, 4, 22),
	Pearl(hgons[20].location, 0, 20),Pearl(hgons[20].location, 1, 20),Pearl(hgons[20].location, 2, 20),Pearl(hgons[20].location, 3, 20), Pearl(hgons[20].location, 4, 20),
	Pearl(hgons[10].location, 0, 10),Pearl(hgons[10].location, 1, 10),Pearl(hgons[10].location, 2, 10),
	Pearl(hgons[4].location, 0, 4),Pearl(hgons[4].location, 1, 4),Pearl(hgons[4].location, 2, 4),
	Pearl(hgons[11].location, 0, 11),Pearl(hgons[11].location, 1, 11),Pearl(hgons[11].location, 2, 11),
	Pearl(hgons[15].location, 0, 15),Pearl(hgons[15].location, 1, 15)
};

Tunnel tunnel = Tunnel(d7);

float smallKeyColor[3] = { 0.5f, 0.6f, 1.0f };
float bigKeyColor[3] = { 0.6f, 0.0f, 0.0f };
float scrollKeyColor[3] = { 0.5f, 0.3f, 0.6f };
Key smallKey = Key(21, hgons[21].location, 0.02f, smallKeyColor);
Key bigKey = Key(3, hgons[3].location, 0.03f, bigKeyColor);
Key scrollKey = Key(1, hgons[1].location, 0.02f, scrollKeyColor);

Wheel wheel = Wheel(hgons[6].location);

Mitra mitra = Mitra(hgons[0].location);

float playerRotation = 0.0f;
float playerSpeed = 0.02f;
float playerRotSpeed = 3.0f;
bool keyStates[256];
int currentHex = 25;
int currentDoor = -1;
int pearlsCollected = 0;
bool flashTextBegin = false;
std::string flashText;
int flashTextMsec = 0;
bool gameOver = false;
bool showInstructions = true;
int startTime = 0, minutes, seconds;
std::string strMin = "", strSec = "";

float playerPosition[2] = {
	hgons[currentHex].location[0],
	hgons[currentHex].location[1]
};

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
	glutFullScreen();
	hgons[currentHex].explored = true;
	doors[24].explored = true;
	doors[18].locked = true;
	doors[5].locked = true;
	doors[26].locked = true;
	doors[2].locked = true;
	tunnel.flipped = false;
	hgons[12].designFlag = 1;
	hgons[19].designFlag = 1;
}

float insLoc[2] = {0.0f, 0.0f};

void drawText(std::string str, float pos[2]) {
	int len = str.length();
	glRasterPos2fv(pos);
	for (int i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
}

void drawCenteredText(std::string str, float y) {
	RECT desktop;

	const HWND hDesktop = GetDesktopWindow(); // Get a handle to the desktop window

	GetWindowRect(hDesktop, &desktop);  // Get the size of screen to the variable desktop
	int screenWidth = desktop.right;
	int len = str.length();
	int stringWidth = 0;
	for (int i = 0; i < len; i++) {
		stringWidth += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}

	float proportion = (float)stringWidth / (float)screenWidth;
	glRasterPos2f(proportion * -1.85f, y);
	for (int i = 0; i < str.length(); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	if (showInstructions) {
		glColor3f(1.0f, 1.0f, 1.0f);
		drawCenteredText("INSTRUCTIONS", 0.7f);
		glColor3f(0.0f, 1.0f, 1.0f);
		drawCenteredText("Collect precious stone Mitra to win the game.", 0.6f);
		glColor3f(0.0f, 0.0f, 1.0f);
		drawCenteredText("*********", 0.5f);
		glColor3f(1.0f, 0.0f, 0.0f);
		drawCenteredText("Press UP arrow key to move forword.", 0.4f);
		drawCenteredText("Press LEFT of RIGHT keys to rotate left or right.", 0.3f);
		drawCenteredText("Collect all 50 Magic Pearls to open door to Wheel Room.", 0.2f);
		glColor3f(0.0f, 0.0f, 1.0f);
		drawCenteredText("*********", 0.1f);
		glColor3f(0.0f, 1.0f, 0.0f);
		drawCenteredText("press 'ENTER' to continue...", 0.0f);
		drawCenteredText("press 'ESC' to quit the game...", -0.1f);
	}
	else {

		glClear(GL_COLOR_BUFFER_BIT);
		
		glPushMatrix();
		glRotatef(-playerRotation, 0.0f, 0.0f, 1.0f);
		glTranslatef(-playerPosition[0], -playerPosition[1], 0.0f);

		for (int hex = 0; hex < 27; hex++) {
			if (hgons[hex].explored && hex != 7) hgons[hex].draw();
		}

		for (int dr = 0; dr < 27; dr++) {
			if (doors[dr].explored) doors[dr].draw();
		}

		for (int pr = 0; pr < 50; pr++) {
			if (!pearls[pr].collected && hgons[pearls[pr].parentNum].explored) pearls[pr].draw();
		}

		if (smallKey.collected == false && hgons[smallKey.parentNum].explored) {
			smallKey.draw();
		}

		if (bigKey.collected == false && hgons[bigKey.parentNum].explored) {
			bigKey.draw();
		}

		if (scrollKey.collected == false && hgons[scrollKey.parentNum].explored) {
			scrollKey.draw();
		}

		if (tunnel.explored) tunnel.draw();

		if (hgons[6].explored) wheel.draw();

		if (hgons[0].explored && mitra.collected == false) mitra.draw();

		glPopMatrix();
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glColor4f(1.0f, 0.0f, 0.0f, 0.3f);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.06f);
		glVertex2f(0.0f, -0.03f);
		glVertex2f(-0.03f, -0.06f);
		glVertex2f(0.0f, 0.06f);
		glVertex2f(0.0f, -0.03f);
		glVertex2f(0.03f, -0.06f);
		glEnd();
		glDisable(GL_BLEND);
		glPointSize(6.0f);
		glBegin(GL_POINTS); //player 
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);
		glEnd();
		drawScoreboard();
		if (flashTextBegin) {

			RECT desktop;

			const HWND hDesktop = GetDesktopWindow(); // Get a handle to the desktop window

			GetWindowRect(hDesktop, &desktop);  // Get the size of screen to the variable desktop
			int screenWidth = desktop.right;
			int len = flashText.length();
			int stringWidth = 0;
			for (int i = 0; i < len; i++) {
				stringWidth += glutBitmapWidth(GLUT_BITMAP_9_BY_15, flashText[i]);
			}

			float proportion = (float)stringWidth / (float)screenWidth;
			glColor3f(0.024f, 0.302f, 0.133f);
			glRasterPos2f(proportion * -1.85f, -0.2f);
			for (int i = 0; i < flashText.length(); i++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, flashText[i]);
		}
	}
	glFlush();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else {
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
}

void Timer() {

	clock_t now = clock();
	while (clock() - now < 1000)
		display();
	flashTextBegin = false;

}

void gameTimer(int value) {
	flashText = "You have reach the time limit...Game Over. Better luck next time : (";
	flashTextBegin = true;
	Timer();

	// Cleanup and exit the application
	glutDestroyWindow(glutGetWindow());
	exit(0);
	//glutPostRedisplay();
}

clock_t now;

/* Callback handler for normal-key event */
void keyboard(unsigned char key, int x, int y) {
	if (key == 27) exit(0);
	if (showInstructions && key == 13) {
		now = clock();
		showInstructions = false;
		glutTimerFunc(12 * 1000 * 60, gameTimer, 0);
		display();
	}
}

void drawScoreboard() {
	glPushMatrix();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glColor4f(0.0f, 0.0f, 0.2f, 0.8f);
	glBegin(GL_QUADS);
	glVertex2f(-0.95f, 0.95f);
	glVertex2f(0.95f, 0.95f);
	glVertex2f(0.95f, 0.7f);
	glVertex2f(-0.95f, 0.7f);
	glEnd();
	glDisable(GL_BLEND);
	glColor3f(1.0f, 1.0f, 0.0f);
	float pos[2] = { -0.9f,0.9f };
	std::string w = "NUMBER OF PEARLS COLLECTED : ";
	w += std::to_string(pearlsCollected);
	drawText(w, pos);
	pos[0] = -0.9f; pos[1] = 0.85f;
	w = "TUNNEL DIRECTION : ";
	if (tunnel.flipped) w += "FLIPPED";
	else w += "NOT FLIPPED";
	drawText(w, pos);
	if (smallKey.collected) {
		pos[0] = 0.2f; pos[1] = 0.9f;
		w = "SMALL KEY-1 COLLECTED";
		drawText(w, pos);
	}
	if (scrollKey.collected) {
		pos[0] = 0.2f; pos[1] = 0.85f;
		w = "SMALL KEY-2 COLLECTED";
		drawText(w, pos);
	}
	if (bigKey.collected) {
		pos[0] = 0.2f; pos[1] = 0.8f;
		w = "BIG KEY COLLECTED";
		drawText(w, pos);
	}
	pos[0] = -0.9f; pos[1] = 0.75f;

	//int seconds = start
	drawText("TIME REMAINING: " + strMin + ":" + strSec, pos);
	glPopMatrix();
}

/* Callback handler for special keys */
void specialKeys(int key, int x, int y) {
	float rot = (90.0f - playerRotation) * 22.0f / 7.0f / 180.0f;
	float temp[2] = { playerPosition[0] - playerSpeed * cosf(rot),
		playerPosition[1] + playerSpeed * sinf(rot) };
	switch (key)
	{
	case GLUT_KEY_UP:
		if (!wheel.isInsideWheel(temp)) {
			wheel.playerInside = false;
		}
		for (int i = 0; i < 50; i++)
		{
			if (pearls[i].isInsidePearl(temp) && pearls[i].collected == false) {
				pearlsCollected++;
				pearls[i].collected = true;
				if (pearlsCollected == 50) {
					doors[5].locked = false;
					flashText = "50 PEARLS COLLECTED, NEW DOOR UNLOCKED";
					flashTextBegin = true;
					Timer();
				}
				break;
			}
		}
		if(wheel.isInsideWheel(temp) && wheel.playerInside == false) {
			tunnel.flipped = !tunnel.flipped;
			wheel.playerInside = true;
			flashText = "TUNNEL ROTATED";
			flashTextBegin = true;
			if (tunnel.flipped) {
				doors[8].explored = false;
				doors[3].explored = true;
			}
			else {
				doors[3].explored = false;
				doors[8].explored = true;
			}
			Timer();
			break;
		}
		if (smallKey.isInsideKey(temp) && smallKey.collected == false) {
			smallKey.collected = true;
			doors[18].locked = false;
			flashText = "SMALL KEY-1 COLLECTED";
			flashTextBegin = true;
			Timer();
			break;
		}
		if (bigKey.isInsideKey(temp) && bigKey.collected == false) {
			bigKey.collected = true;
			doors[2].locked = false;
			flashText = "BIG KEY COLLECTED";
			flashTextBegin = true;
			Timer();
			break;
		}
		if (scrollKey.isInsideKey(temp) && scrollKey.collected == false) {
			scrollKey.collected = true;
			doors[26].locked = false;
			flashText = "SMALL KEY-2 COLLECTED";
			flashTextBegin = true;
			Timer();
			break;
		}
		if (mitra.isInsideMitra(temp) && mitra.collected == false) {
			mitra.collected = true;
			flashText = "YOU WON, GAME OVER!!!";
			flashTextBegin = true;
			Timer();
			exit(0);
		}
		if (currentHex == 7) { // checks for tunnel hexagon i.e hexagon no = 7
			if (tunnel.isInsideTunnel(temp)) {
				doors[9].explored = true;
				if (tunnel.flipped) doors[3].explored = true;
				else doors[8].explored = true;
				playerPosition[0] -= playerSpeed * cos(rot);
				playerPosition[1] += playerSpeed * sin(rot);
				break;
			}
		}
		else if (currentHex != -1 && hgons[currentHex].isInsideHex(temp)) { // checks if player is inside a hex
			for (int dr : hgons[currentHex].doors) {
				doors[dr].explored = true;
			}
			playerPosition[0] -= playerSpeed * cos(rot);
			playerPosition[1] += playerSpeed * sin(rot);
			break;
		}
		if (currentHex != -1) { // checks if player is inside door
			for (int door : hgons[currentHex].doors) {
				if (door != -1 && !doors[door].locked && doors[door].isInsideDoor(temp)) {
					playerPosition[0] -= playerSpeed * cos(rot);
					playerPosition[1] += playerSpeed * sin(rot);
					currentDoor = door;
					doors[currentDoor].explored = true;
					currentHex = -1;
					break;
				}
			}
		}
		if (currentDoor != -1 && doors[currentDoor].isInsideDoor(temp)) {
			if (doors[currentDoor].hex1 != 7)
				hgons[doors[currentDoor].hex1].explored = true;
			else
				tunnel.explored = true;
			if (doors[currentDoor].hex2 != 7)
				hgons[doors[currentDoor].hex2].explored = true;
			else
				tunnel.explored = true;
			playerPosition[0] -= playerSpeed * cos(rot);
			playerPosition[1] += playerSpeed * sin(rot);
			break;
		}
		if (doors[currentDoor].hex1 == 7) {
			if (currentDoor != -1 && tunnel.isInsideTunnel(temp)) {
				playerPosition[0] -= playerSpeed * cos(rot);
				playerPosition[1] += playerSpeed * sin(rot);
				tunnel.explored = true;
				currentHex = 7;
				currentDoor = -1;
				break;
			}
		}
		else if (currentDoor != -1 && hgons[doors[currentDoor].hex1].isInsideHex(temp)) {
			playerPosition[0] -= playerSpeed * cos(rot);
			playerPosition[1] += playerSpeed * sin(rot);
			currentHex = doors[currentDoor].hex1;
			hgons[currentHex].explored = true;
			currentDoor = -1;
			break;
		}
		if (doors[currentDoor].hex2 == 7) {
			if (currentDoor != -1 && tunnel.isInsideTunnel(temp)) {
				playerPosition[0] -= playerSpeed * cos(rot);
				playerPosition[1] += playerSpeed * sin(rot);
				tunnel.explored = true;
				currentHex = 7;
				currentDoor = -1;
				break;
			}
		}
		else if (currentDoor != -1 && hgons[doors[currentDoor].hex2].isInsideHex(temp)) {
			playerPosition[0] -= playerSpeed * cos(rot);
			playerPosition[1] += playerSpeed * sin(rot);
			currentHex = doors[currentDoor].hex2;
			hgons[currentHex].explored = true;
			currentDoor = -1;
			break;
		}
		break;
	case GLUT_KEY_RIGHT:
		playerRotation -= playerRotSpeed;
		break;
	case GLUT_KEY_LEFT:
		playerRotation += playerRotSpeed;
		break;
	default:
		break;
	}
	glutPostRedisplay();

}

void specialKeysUp(int key, int x, int y) {
	keyStates[key] = false;
}

void idle() {
	startTime = 12*60 - (int)((clock() - now) * 0.001);
	minutes = startTime / 60;
	seconds = startTime - minutes * 60;
	char buffer[256]; sprintf_s(buffer, "%02d", minutes);
	strMin = buffer;
	sprintf_s(buffer, "%02d", seconds);
	strSec = buffer;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("hexaMaze 2D");
	initGL();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutSpecialFunc(specialKeys);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutMainLoop();
	return 0;
}