
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 25
#define COLS 60

char canvas[ROWS][COLS];

void initializeCanvas() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas() {
    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height) {
    for(int i = y; i < y + height && i < ROWS; i++) {
        for(int j = x; j < x + width && j < COLS; j++) {
            canvas[i][j] = '*';
        }
    }
}

void drawLine(int x1, int y1, int x2, int y2) {

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while(1) {
        if(x1 >= 0 && x1 < COLS && y1 >= 0 && y1 < ROWS)
            canvas[y1][x1] = '*';

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawTriangle(int x, int y, int height) {

    for(int i = 0; i < height; i++) {

        for(int j = -i; j <= i; j++) {

            if(y + i < ROWS &&
               x + j >= 0 &&
               x + j < COLS) {

                canvas[y + i][x + j] = '*';
            }
        }
    }
}

void drawCircle(int cx, int cy, int radius) {

    for(int y = 0; y < ROWS; y++) {

        for(int x = 0; x < COLS; x++) {

            int dx = x - cx;
            int dy = y - cy;

            if(dx * dx + dy * dy <= radius * radius) {
                canvas[y][x] = '*';
            }
        }
    }
}

void deleteRectangle(int x, int y, int width, int height) {

    for(int i = y; i < y + height && i < ROWS; i++) {

        for(int j = x; j < x + width && j < COLS; j++) {

            canvas[i][j] = '_';
        }
    }
}

void clearCanvas() {

    initializeCanvas();

    printf("\nCanvas Cleared Successfully!\n");
}

int main() {

    int choice;

    initializeCanvas();

    do {

        printf("\n=================================");
        printf("\n MENU DRIVEN 2D GRAPHICS EDITOR");
        printf("\n=================================");
        printf("\n1. Draw Rectangle");
        printf("\n2. Draw Line");
        printf("\n3. Draw Triangle");
        printf("\n4. Draw Circle");
        printf("\n5. Delete Rectangle");
        printf("\n6. Clear Canvas");
        printf("\n7. Display Canvas");
        printf("\n8. Exit");
        printf("\nEnter Choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1: {
                int x, y, w, h;

                printf("Enter x y width height: ");
                scanf("%d %d %d %d", &x, &y, &w, &h);

                drawRectangle(x, y, w, h);

                printf("Rectangle Drawn Successfully!\n");
                break;
            }

            case 2: {
                int x1, y1, x2, y2;

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d %d %d %d",
                      &x1, &y1, &x2, &y2);

                drawLine(x1, y1, x2, y2);

                printf("Line Drawn Successfully!\n");
                break;
            }

            case 3: {
                int x, y, h;

                printf("Enter center_x start_y height: ");
                scanf("%d %d %d", &x, &y, &h);

                drawTriangle(x, y, h);

                printf("Triangle Drawn Successfully!\n");
                break;
            }

            case 4: {
                int cx, cy, r;

                printf("Enter center_x center_y radius: ");
                scanf("%d %d %d", &cx, &cy, &r);

                drawCircle(cx, cy, r);

                printf("Circle Drawn Successfully!\n");
                break;
            }

            case 5: {
                int x, y, w, h;

                printf("Enter x y width height to delete: ");
                scanf("%d %d %d %d",
                      &x, &y, &w, &h);

                deleteRectangle(x, y, w, h);

                printf("Deleted Successfully!\n");
                break;
            }

            case 6:
                clearCanvas();
                break;

            case 7:
                displayCanvas();
                break;

            case 8:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 8);

    return 0;
}
