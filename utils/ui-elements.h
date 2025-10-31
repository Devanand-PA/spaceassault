
#include <raylib.h>
#include <stdbool.h>
typedef struct {
    Rectangle rect;
    Color bg;
    Color border;
    Color textColor;
    const char *text;
    int textSize;
    bool hovered;
    bool pressed;
} Button;

void DrawButton(const Button *b);
void UpdateButton(Button *b) ;
bool ButtonPressed(const Button *b) ;
