#include "../utils/common.h"

// External scene variables
extern FILE *gpFile;
extern iTimeElapsed;
extern texture_sky_and_underwater;
extern texture_sun;
extern texture_water;
extern texture_fish_01;
extern texture_fish_02;
extern texture_fish_03;
extern texture_fish_04;
extern texture_fish_05;
extern texture_penguin;

void drawSkyAndUnderwater(void)
{
	// ------------- DRAW SKY AND UNDERWATER --------------
    glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(skyWaterPosX, skyWaterPosY, -9.0f);
		glBindTexture(GL_TEXTURE_2D, texture_sky_and_underwater);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(8.0f, 9.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-8.0f, 9.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-8.0f, -9.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(8.0f, -9.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW SUN --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(sunPosX, sunPosY, -8.9f);
		glScalef(0.5f, 0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture_sun);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW FISH 01 --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(fish_01_PosX, fish_01_PosY, -8.8f);
		glScalef(0.5f, 0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture_fish_01);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW FISH 02 --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(fish_02_PosX, fish_02_PosY, -8.8f);
		glScalef(0.5f, 0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture_fish_02);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW FISH 03 --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(fish_03_PosX, fish_03_PosY, -8.8f);
		glScalef(0.5f, 0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture_fish_03);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW FISH 04 --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(fish_04_PosX, fish_04_PosY, -8.8f);
		glScalef(0.5f, 0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture_fish_04);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW FISH 05 --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(fish_05_PosX, fish_05_PosY, -8.8f);
		glScalef(0.5f, 0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture_fish_05);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW PENGUIN --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(penguin_PosX, penguin_PosY, -8.8f);
		glScalef(0.5f, 0.5f, 0.5f);
		glBindTexture(GL_TEXTURE_2D, texture_penguin);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();

	// ------------- DRAW WATER OVERLAY --------------
    glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(waterOverlayPosX, waterOverlayPosY, -8.2f);
		glScalef(0.78f, 0.78f, 0.78f);
		glBindTexture(GL_TEXTURE_2D, texture_water);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(8.0f, 9.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-8.0f, 9.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-8.0f, -9.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(8.0f, -9.0f, 0.0f);
		glEnd();
		// Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();
}

void updateSkyAndUnderwater(void)
{
	// Update fish_01 here
	if (iTimeElapsed > 0 && iTimeElapsed < 500)
	{
		fish_01_PosX += fish_01_Speed;
		fish_02_PosX -= fish_02_Speed;
		fish_03_PosX += fish_03_Speed;
		fish_04_PosX += fish_04_Speed;
		fish_05_PosX -= fish_05_Speed;
		if (fish_01_PosX >= 10.0f)
		{
			fish_01_PosX = -10.0f;
		}
		if (fish_02_PosX <= -10.0f)
		{
			fish_02_PosX = 10.0f;
		}
		if (fish_03_PosX >= 10.0f)
		{
			fish_03_PosX = -10.0f;
		}
		if (fish_04_PosX >= 10.0f)
		{
			fish_04_PosX = -10.0f;
		}
		if (fish_05_PosX <= -10.0f)
		{
			fish_05_PosX = 10.0f;
		}
	}

	// Update penguin here
	if (iTimeElapsed > 200 && iTimeElapsed < 900)
	{
		penguin_PosX -= penguin_Speed;
		if (penguin_PosX <= -10.0f)
		{
			penguin_PosX = 10.0f;
		}
	}
}