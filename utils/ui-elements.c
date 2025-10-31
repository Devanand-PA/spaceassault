#include <raylib.h>
#include <stdbool.h>
#include "ui-elements.h"
// Buttons
//========================


void DrawButton(const Button *b) {
    Color fill = b->bg;
    if (b->pressed) fill = Fade(b->bg, 0.7f);
    else if (b->hovered) fill = Fade(b->bg, 0.9f);

    DrawRectangleRec(b->rect, fill);
    DrawRectangleLinesEx(b->rect, 2, b->border);

    int textWidth = MeasureText(b->text, b->textSize);
    Vector2 pos = { b->rect.x + (b->rect.width - textWidth) / 2.0f,
                    b->rect.y + (b->rect.height - b->textSize) / 2.0f };
    DrawText(b->text, (int)pos.x, (int)pos.y, b->textSize, b->textColor);
}

void UpdateButton(Button *b) {
    Vector2 mouse = GetMousePosition();
    b->hovered = CheckCollisionPointRec(mouse, b->rect);
    b->pressed = b->hovered && IsMouseButtonDown(MOUSE_LEFT_BUTTON);
}

bool ButtonPressed(const Button *b) {
    // returns true when left mouse button was released while hovering
    return b->hovered && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
}
