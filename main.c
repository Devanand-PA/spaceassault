#include <raylib.h>
#include "utils/ui-elements.h"

int main() {
	int windowResolution[2] = { 800, 800 };
	InitWindow(windowResolution[0],windowResolution[1], "Hello Raylib!");
	typedef enum { STATE_MENU, STATE_PLAY, STATE_PAUSE  } GAMESTATE;

	SetTargetFPS(60);
	Color testcolor = (Color){200,0,0,255};
	GAMESTATE curr_Gamestate = STATE_MENU;
	bool STATE_RUNNING = true;
	while(!WindowShouldClose()) {

		Button btn1 = {
			.rect = {200, 150, 200, 60},
			.bg = BLUE, .border = DARKBLUE, .textColor = WHITE,
			.text = "Click me", .textSize = 20, .hovered = false, .pressed = false 
		};

		Button btn2 = { 
			.rect = {200, 230, 200, 60},
			.bg = GREEN, .border = DARKGREEN, .textColor = WHITE,
			.text = "Toggle", .textSize = 20, .hovered = false, .pressed = false 
		};

		bool toggled = false;


		while (STATE_RUNNING) {
			UpdateButton(&btn1);
			UpdateButton(&btn2);
			if (ButtonPressed(&btn2)) {
				toggled = !toggled;
				btn2.bg = toggled ? DARKGREEN : GREEN;
				}
			BeginDrawing();
			ClearBackground((Color){255,255,255,255})	;
//TODO: We'll put temporary code here and try to fix it later.
		//
			DrawRectangleLinesEx(
			(Rectangle){(float)(windowResolution[0]/10),(float)(windowResolution[1]/10),
			(float)(windowResolution[0]-(int)(windowResolution[0]/5)),
			(float)(windowResolution[1]- (int)(windowResolution[1]/5))},4,
			(Color){0,0,0,255}
			);

			DrawButton(&btn1);
			DrawButton(&btn2);	

//
			EndDrawing();
		}
	}
	CloseWindow();
	return 0;
}
