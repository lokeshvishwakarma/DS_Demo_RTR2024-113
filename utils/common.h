// Win32 Header files
#include<Windows.h>
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
// OpenGL related Header files
#include<gl/GL.h>
#include<gl/GLU.h>

#include <time.h>
#include <mmsystem.h>

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
extern float preIntro_PosX;
extern float preIntro_PosY;
extern float preIntro_Speed;
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
extern float penguin_PosX;
extern float penguin_PosY;
extern float penguin_Speed;
extern float tech_stack_PosX;
extern float tech_stack_PosY;
extern float tech_stack_Speed;
extern float credits_PosY;
extern float credits_Speed;
extern float post_credits_PosY;
extern float post_credits_Speed;

// Alpha related variables
extern float alpha;

// wave related variables
extern int x, y;
extern float float_x, float_y, float_xb, float_yb; 
extern float points[45][45][3];
extern float wiggleCount;