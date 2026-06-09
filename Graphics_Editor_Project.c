#include <stdio.h>
#include <stdlib.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_SHAPES 50

// Shape Types
enum ShapeType { RECTANGLE, LINE, CIRCLE, TRIANGLE };

// Structure to hold shape data
typedef struct {
    int active; // 1 if exists, 0 if deleted
    int id;
    enum ShapeType type;
    int x, y;       // Starting coordinates or center
    int w, h;       // For rectangles
    int radius;     // For circles
    // Add more properties for lines/triangles (like x2, y2)
} Shape;

Shape objects[MAX_SHAPES];
int shape_count = 0;
char canvas[HEIGHT][WIDTH];

// 1. Wipe the canvas clean
void clear_canvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}

// 2. Shape-drawing algorithms (To be completed)
void draw_rectangle_to_canvas(Shape s) {
    for (int i = s.y; i < s.y + s.h && i < HEIGHT; i++) {
        for (int j = s.x; j < s.x + s.w && j < WIDTH; j++) {
            // Draw only the borders
            if (i == s.y || i == s.y + s.h - 1 || j == s.x || j == s.x + s.w - 1) {
                canvas[i][j] = '*';
            }
        }
    }
}

// 3. Render all active objects onto the canvas
void render() {
    clear_canvas();
    for (int i = 0; i < shape_count; i++) {
        if (objects[i].active) {
            if (objects[i].type == RECTANGLE) {
                draw_rectangle_to_canvas(objects[i]);
            }
            // Add conditions for LINE, CIRCLE, TRIANGLE here
        }
    }
}

// 4. Print to terminal
void display() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example: Adding a rectangle
    objects[shape_count].active = 1;
    objects[shape_count].id = shape_count;
    objects[shape_count].type = RECTANGLE;
    objects[shape_count].x = 5;
    objects[shape_count].y = 5;
    objects[shape_count].w = 10;
    objects[shape_count].h = 5;
    shape_count++;

    render();
    display();

    return 0;
}