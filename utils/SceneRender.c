#include "SceneRender.h"

// External scene variables
Scene* currentScene = NULL;

/*******************************/ 
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
Scene intro = {introRender, introUpdate, introShouldTransition, NULL};
Scene scene1 = {scene1Render, scene1Update, scene1ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};
Scene scene3 = {scene3Render, scene3Update, scene3ShouldTransition, NULL};
Scene scene4 = {scene4Render, scene4Update, scene4ShouldTransition, NULL};
Scene scene5 = {scene5Render, scene5Update, scene5ShouldTransition, NULL};
Scene outro = {outroRender, outroUpdate, outroShouldTransition, NULL};

// External global variables from main.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

/*******************************/ 
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

// Initialize the scene chain
void initScenes(void) {
    // function declarations
    void introRender(void);
    void introUpdate(void);
    BOOL introShouldTransition(BOOL);

    currentScene = (Scene*) malloc(sizeof(Scene));
    intro = (Scene) { introRender, introUpdate, introShouldTransition, NULL };

    intro.nextScene = &scene1;
    scene1.nextScene = &scene2;
    scene2.nextScene = &scene3;
    scene3.nextScene = &scene4;
    scene4.nextScene = &scene5;
    scene5.nextScene = &outro;
    outro.nextScene = NULL;
    currentScene = &intro;   // Start with intro

    FILE *fp = fopen("../assets/MasoliCheGaane.wav", "r");
    BOOL is_exist = FALSE;
    if (fp != NULL)
    {
        is_exist = TRUE;
        fprintf(gpFile, "Audio loaded successfully!\n");
        fclose(fp); // close the file
    }
    if (is_exist == TRUE)
    {
        fprintf(gpFile, "Playing sound!\n");
        PlaySound("../assets/MasoliCheGaane.wav", NULL, SND_ASYNC | SND_FILENAME);
    }

}

// Update the current scene
void updateCurrentScene(UINT timeElapsed) {
    if (currentScene) {
        // Call the current scene's update function
        if (currentScene->update) {
            currentScene->update();
        }
        
        if (currentScene->shouldTransition && currentScene->shouldTransition(FALSE)) {
            if (currentScene->nextScene) {
                logSceneTransition(timeElapsed);
                currentScene = currentScene->nextScene;
            }
        }
    }
}

// Render the current scene
void renderCurrentScene(void) 
{
    if (currentScene && currentScene->render) {
        // fprintf(gpFile, "Current madi aalo\n");
        currentScene->render();
    }
}

// Log scene transition
void logSceneTransition(UINT timeElapsed) {
    if (gpFile) {
        fprintf(gpFile, "Transitioning to next scene at time %d seconds\n", timeElapsed);
    }
}

/*******************************/ 
/* INTRO IMPLEMENTATION */
/******************************/
void introRender(void)
{
    // Draw Intro scene
    drawIntro();
}

void introUpdate(void)
{
    // Update Intro scene
    updateIntro();

}

BOOL introShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 200;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if(flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/ 
/* SCENE 1 IMPLEMENTATION */
/******************************/
void scene1Render(void)
{
    // Draw scene 1
    drawSkyAndUnderwater();
}


void scene1Update(void)
{
    // Update scene 1
    updateSkyAndUnderwater();
}

BOOL scene1ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 500;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if(flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/ 
/* SCENE 2 IMPLEMENTATION */
/******************************/

void scene2Render(void)
{
    // Draw scene 2

}

void scene2Update(void)
{
    // Update scene 2
}

BOOL scene2ShouldTransition(BOOL iSkipped)
{
    // 20 Sec is Temporarily set for testing
    int iThresholdTime = 460;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 3 IMPLEMENTATION */
/******************************/

void scene3Render(void)
{
    // Draw scene 3
}

void scene3Update(void)
{
    // Update scene 3
}

BOOL scene3ShouldTransition(BOOL iSkipped)
{
    // 20 Sec is Temporarily set for testing
    int iThresholdTime = 520;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 4 IMPLEMENTATION */
/******************************/

void scene4Render(void)
{
    // Draw scene 4
}

void scene4Update(void)
{
    // Scene 4 update
}

BOOL scene4ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 950;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 1 min 35 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 5 IMPLEMENTATION */
/******************************/

void scene5Render(void)
{
    // Draw scene 5
}

void scene5Update(void)
{
    // Scene 5 update
}

BOOL scene5ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 950;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 1 min 35 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/ 
/* OUTRO IMPLEMENTATION */
/******************************/
void outroRender(void)
{
    // Draw outro

}

void outroUpdate(void)
{
    // Update outro
}

BOOL outroShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 200;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if(flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}