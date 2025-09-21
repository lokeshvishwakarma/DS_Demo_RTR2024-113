// Win32 Header files
#include<Windows.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
// OpenGL related Header files
#include<gl/GL.h>
#include<gl/GLU.h>

// Global External Variables
extern float sunPosX;
extern float sunPosY;
extern float sunSpeed;
extern BOOL isSunReached;
extern float skyWaterPosX;
extern float skyWaterPosY;
extern float skyWaterSpeed;
extern float waterOverlayPosX;
extern float waterOverlayPosY;
extern float waterOverlaySpeed;
extern float intro_PosX;
extern float intro_PosY;
extern float intro_Speed;
extern float fish_01_PosX;
extern float fish_01_PosY;
extern float fish_01_Speed;
extern float fish_02_PosX;
extern float fish_02_PosY;
extern float fish_02_Speed;
extern float fish_03_PosX;
extern float fish_03_PosY;
extern float fish_03_Speed;
extern float fish_04_PosX;
extern float fish_04_PosY;
extern float fish_04_Speed;
extern float fish_05_PosX;
extern float fish_05_PosY;
extern float fish_05_Speed;

// wave related variables
extern int x, y;
extern float float_x, float_y, float_xb, float_yb; 
extern float points[45][45][3];
extern float wiggleCount;