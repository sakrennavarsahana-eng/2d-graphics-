# Menu-Driven 2D Graphics Editor

## Mini Project

A menu-driven 2D Graphics Editor developed in C using a 2D character array as the drawing canvas.

The canvas is initialized with the underscore (_) character and graphical objects are drawn using the asterisk (*) character.

---

## Features

- Draw Rectangle
- Draw Line
- Draw Triangle
- Draw Circle
- Delete Rectangle
- Clear Canvas
- Display Canvas
- Menu Driven Interface

---

## Technologies Used

- C Programming Language
- GCC Compiler

---

## Data Structure Used

- 2D Character Array

```c
char canvas[25][60];
```

---

## Functions Implemented

### initializeCanvas()
Initializes the canvas with `_`.

### displayCanvas()
Displays the current drawing.

### drawRectangle()
Draws a rectangle.

### drawLine()
Draws a line using Bresenham's Algorithm.

### drawTriangle()
Draws a triangle.

### drawCircle()
Draws a circle.

### deleteRectangle()
Deletes a rectangular region.

### clearCanvas()
Resets the canvas.

---

## How to Compile

Linux / Mac:

```bash
gcc graphics_editor.c -o graphics_editor -lm
./graphics_editor
```

Windows:

```bash
gcc graphics_editor.c -o graphics_editor -lm
graphics_editor.exe
```

---

## Sample Menu

1. Draw Rectangle
2. Draw Line
3. Draw Triangle
4. Draw Circle
5. Delete Rectangle
6. Clear Canvas
7. Display Canvas
8. Exit

---

## Project Objective

To implement a menu-driven graphics editor using a 2D character array and basic computer graphics concepts in C.

---

## Submitted By

Name: Sahana Sakrennavar

SRN: R25EA198

Course: AIML D Mini Project

Guide: ______________________
