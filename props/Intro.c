#include "../utils/common.h"

// External scene variables
extern FILE *gpFile;
extern iTimeElapsed;
extern texture_sky_and_underwater;
extern texture_sun;
extern texture_water;
extern texture_pre_intro;
extern texture_intro;

void drawIntro(void)
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

	// ------------- DRAW PRE INTRO --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(0.0f, preIntro_PosY, -8.8f);
		glScalef(1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, texture_pre_intro);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2.5f, 1.5f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-2.5f, 1.5f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-2.5f, -1.5f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2.5f, -1.5f, 0.0f);
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

	// ------------- DRAW INTRO TITLE --------------
	glLoadIdentity();
	glPushMatrix();
	{
		glTranslatef(0.0f, intro_PosY, -8.8f);
		glScalef(1.0f, 1.0f, 1.0f);
		glBindTexture(GL_TEXTURE_2D, texture_intro);
		
		// Draw quad here
		glBegin(GL_QUADS);
		// Front face
		// Top Right
		glTexCoord2f(1.0f, 1.0f);
		glColor4f(1.0f, 1.0f, 1.0f, alpha);
		glVertex3f(1.5f, 1.0f, 0.0f);
		// Top Left
		glTexCoord2f(0.0f, 1.0f);
		glColor4f(1.0f, 1.0f, 1.0f, alpha);
		glVertex3f(-1.5f, 1.0f, 0.0f);
		// Bottom Left
		glTexCoord2f(0.0f, 0.0f);
		glColor4f(1.0f, 1.0f, 1.0f, alpha);
		glVertex3f(-1.5f, -1.0f, 0.0f);
		// Bottom Right
		glTexCoord2f(1.0f, 0.0f);
		glColor4f(1.0f, 1.0f, 1.0f, alpha);
		glVertex3f(1.5f, -1.0f, 0.0f);
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
		glScalef(0.76f, 0.76f, 0.76f);
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

void updateIntro(void)
{
	// Update pre intro here
	if (iTimeElapsed > 0 && iTimeElapsed < 70)
	{
		preIntro_PosY += preIntro_Speed;
		if (preIntro_PosY >= 10.0f)
		{
			preIntro_PosY = 10.0f;
		}
	}

	// Update intro here
	if (iTimeElapsed > 30 && iTimeElapsed < 100)
	{
		// alpha -= 0.0001f;
		intro_PosY += intro_Speed;
		if (intro_PosY >= 10.0f)
		{
			intro_PosY = 10.0f;
		}
	}

	if (iTimeElapsed > 70 && iTimeElapsed < 120)
	{
		sunPosX += sunSpeed;
		sunPosY += sunSpeed;
		if (sunPosX >= 2.0f || sunPosY >= 2.0f)
		{
			sunPosX = 2.0f;
			sunPosY = 2.0f;
			isSunReached = TRUE;
		}
	}

	// Move to under ocean
	if (iTimeElapsed > 120 && iTimeElapsed < 250)
	{
		sunPosY += sunSpeed;
		skyWaterPosY += skyWaterSpeed;
		waterOverlayPosY += waterOverlaySpeed;
		if (sunPosY >= 10.0f)
		{
			sunPosY = 10.f;
		}
		if (skyWaterPosY >= 4.5f)
		{
			skyWaterPosY = 4.5f;
		}
		if (waterOverlayPosY >= -1.5f)
		{
			waterOverlayPosY = -1.5f;
		}	
	}
}