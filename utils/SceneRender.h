#include "../utils/common.h"

// #include "../props/Scene1.h"
/*************************************/ 
/* TYPE DEFINITIONS AND DECLARATIONS */
/*************************************/ 

// Scene structure definition for Chain of Responsibility pattern
typedef struct SceneStruct {
    void (*render)(void);        // Function to render the scene
    void (*update)(void);        // Function to update the scene
    BOOL (*shouldTransition)(BOOL iSkipped);  // Function to check if transition to next scene is needed
    struct SceneStruct* nextScene;     // Pointer to next scene in the chain
} Scene;

// Scene management functions declarations
void initScenes(void);
void updateCurrentScene(UINT iTimeElapsed);
void renderCurrentScene(void);
void logSceneTransition(UINT iTimeElapsed);

/*******************************/ 
/* SCENE FUNCTION DECLARATIONS */
/******************************/

// Forward declarations for scene functions
void introRender(void);
void introUpdate(void);
BOOL introShouldTransition(BOOL iSkipped);
void scene1Render(void);
void scene1Update(void);
BOOL scene1ShouldTransition(BOOL iSkipped);
void scene2Render(void);
void scene2Update(void);
BOOL scene2ShouldTransition(BOOL iSkipped);
void scene3Render(void);
void scene3Update(void);
BOOL scene3ShouldTransition(BOOL iSkipped);
void scene4Render(void);
void scene4Update(void);
BOOL scene4ShouldTransition(BOOL iSkipped);
void scene5Render(void);
void scene5Update(void);
BOOL scene5ShouldTransition(BOOL iSkipped);
void outroRender(void);
void outroUpdate(void);
BOOL outroShouldTransition(BOOL iSkipped);
