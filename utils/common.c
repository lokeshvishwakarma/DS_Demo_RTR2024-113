#include "common.h"

// Initialization
float sunPosX = -8.5f;
float sunPosY = -8.5f;
float sunSpeed = 0.001f;
BOOL isSunReached = FALSE;
float skyWaterPosX = 0.0f;
float skyWaterPosY = -4.5f;
float skyWaterSpeed = 0.001f;
float waterOverlayPosX = 0.0f;
float waterOverlayPosY = -10.5f;
float waterOverlaySpeed = 0.001f;
float preIntro_PosX = 0.0f;
float preIntro_PosY = -10.0f;
float preIntro_Speed = 0.001f;
float intro_PosX = 0.0f;
float intro_PosY = -10.0f;
float intro_Speed = 0.001f;
float fish_01_PosX = -8.0f;
float fish_01_PosY = 0.0f;
float fish_01_Speed = 0.001f;
float fish_02_PosX = 9.0f;
float fish_02_PosY = 0.5f;
float fish_02_Speed = 0.001f;
float fish_03_PosX = -8.5f;
float fish_03_PosY = -1.0f;
float fish_03_Speed = 0.001f;
float fish_04_PosX = -10.0f;
float fish_04_PosY = -1.8f;
float fish_04_Speed = 0.001f;
float fish_05_PosX = 8.0f;
float fish_05_PosY = 1.7f;
float fish_05_Speed = 0.001f;
float penguin_PosX = 8.0f;
float penguin_PosY = 1.0f;
float penguin_Speed = 0.001f;
float turtle_PosX = 8.0f;
float turtle_PosY = -2.0f;
float turtle_Speed = 0.001f;
float tech_stack_PosX = 0.0f;
float tech_stack_PosY = -10.0f;
float tech_stack_Speed = 0.001f;
float credits_PosY = -10.0f;
float credits_Speed = 0.001f;
float post_credits_PosY = -10.0f;
float post_credits_Speed = 0.001f;

// Alpha related variables
float alpha = 1.0f;

// wave related variables
int x, y;
float float_x, float_y, float_xb, float_yb; 
float points[45][45][3];
float wiggleCount = 0.0f;
