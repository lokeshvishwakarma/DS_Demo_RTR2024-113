// Win32 Header files
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>

// OpenGL related Header files
#include<gl/GL.h>
#include<gl/GLU.h>

// Custom Header file
#include "main.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../utils/stb_image.h"

#include "../utils/SceneRender.h"

// OpenGL related libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declaration
// variables related to fullscreen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// Active window related variables
BOOL gbActiveWindow = FALSE;

// Exit key press related
BOOL gbEscapeKeyIsPressed = FALSE; 

// variables related to FILE IO
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// OpenGL related global variables
HDC ghdc = NULL; // Handle device context
HGLRC ghrc = NULL; // Handle to graphics rendering context 

// timer realted variables
UINT_PTR timerId;
UINT iTimeElapsed = 0;
// time to update the update() function
UINT timeUpdate = 100; //	10 * timeUpdate = 1 sec

extern Scene* currentScene;

// Font related variable
GLuint base;

// Texture related variables
extern GLuint texture_intro = 0;
extern GLuint texture_sky_and_underwater = 0;
extern GLuint texture_sun = 0;
extern GLuint texture_water = 0;
extern GLuint texture_fish_01 = 0;
extern GLuint texture_fish_02 = 0;
extern GLuint texture_fish_03 = 0;
extern GLuint texture_fish_04 = 0;
extern GLuint texture_fish_05 = 0;

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// function declaration
	int initialize(void);
	void display(void);
	void update(void);
	void uninitialize(void);

	// variable declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");
	BOOL bDone = FALSE;

	int smX = GetSystemMetrics(SM_CXSCREEN);
	int smY = GetSystemMetrics(SM_CYSCREEN);

	int x = smX / 2 - WIN_WIDTH/2;
	int y = smY / 2 - WIN_HEIGHT/2;

	// code
	// Create log file
	gpFile = fopen(gszLogFileName, "w");
	if (gpFile == NULL)
	{
		MessageBox(hwnd, TEXT("Log file creation failed"), TEXT("FILE IO ERROR"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program started successfully\n");
	}
	
	// Window Class Initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// Registration of Window Class
	RegisterClassEx(&wndclass);

	// Create Window
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szAppName,
		TEXT("DS Demo Lokesh Vishwakarma"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		x,  // update as homework
		y,  // update as homework
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	
	ghwnd = hwnd;

	// Show Window
	ShowWindow(hwnd, iCmdShow);

	// Point Background & Window
	UpdateWindow(hwnd);
	
	// initialize
	int result = initialize();
	
	if (result != 0)
	{
		fprintf(gpFile, "Initialized function failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "Initialized function completed successfully\n");
	}

	// Set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
	

	// Game Loop
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);	
			}
		}
		else
		{
			if (gbActiveWindow == TRUE)
			{
				if (gbEscapeKeyIsPressed == TRUE)
				{
					bDone = TRUE;
				}
				// render
				display();

				// update
				update();
			}
		}
	}

	// uninitialize
	uninitialize();

	return((int)msg.wParam);
}

// Callback Function
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// function declarations
	void toggleFullScreen(void);
	void resize(int, int);
	void uninitialize(void);

	// code
	switch (iMsg)
	{
		case WM_CREATE:
			ZeroMemory((void*) &wpPrev, sizeof(WINDOWPLACEMENT));
			break;
		case WM_SETFOCUS:
			gbActiveWindow = TRUE;
			break;
		case WM_KILLFOCUS:
			gbActiveWindow = FALSE;
			break;
		case WM_ERASEBKGND:
			return(0);
		case WM_SIZE:
			resize(LOWORD(lParam), HIWORD(lParam));
			break;
		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_ESCAPE:
					gbEscapeKeyIsPressed = TRUE;
					break;
				
				default:
					break;
			}
			break;
		case WM_TIMER:
			iTimeElapsed++;
			fprintf(gpFile, "%d seconds\n", iTimeElapsed);
			break;
		case WM_CHAR:
			switch (wParam)
			{
				case 'F':
				case 'f':
					if (gbFullScreen == FALSE)
					{
						toggleFullScreen();
						gbFullScreen = TRUE;
					}
					else
					{
						toggleFullScreen();
						gbFullScreen = FALSE;
					}
					break;
				case 'S':
				case 's':
					// Scene skipping
					fprintf(gpFile, "Scene skipping requested\n");
					if (currentScene && currentScene->shouldTransition && currentScene->nextScene)
					{
						if (currentScene->shouldTransition(TRUE))
						{
							fprintf(gpFile, "Transitioning to next scene at time %d seconds\n", iTimeElapsed);
							currentScene = currentScene->nextScene;
						}
					}
					break;
				default:
					break;
			}
			break;
		case WM_CLOSE:
			uninitialize();
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			break;
	}

	return(DefWindowProc(hWnd, iMsg, wParam, lParam));
}

// functions which don't have body are called as stub functions
void toggleFullScreen(void)
{
	// Variable declarations
	MONITORINFO mi;
	if(gbFullScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if(dwStyle & WS_OVERLAPPEDWINDOW)
		{
			ZeroMemory((void*) &mi, sizeof(MONITORINFO));
			mi.cbSize = sizeof(MONITORINFO);

			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				int monitorWidth = mi.rcMonitor.right - mi.rcMonitor.left;
				int monitorHeight = mi.rcMonitor.bottom - mi.rcMonitor.top;
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, monitorWidth, monitorHeight, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
	}
	ShowCursor(TRUE);
}

int initialize(void)
{
	// function declaration
	void resize(int, int);
	void buildFont(void);
	BOOL LoadPNGTexture(GLuint*, char*);

	// local variable declaration
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

    // code
	// PixelFormatDescriptor initialization
	ZeroMemory((void*) &pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

	// Get DC
	ghdc = GetDC(ghwnd);

	if (ghdc == NULL)
	{
		fprintf(gpFile, "Get DC function failed!\n");
		return(-1);
	}

	// Get matching pixel format index using hdc and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "Choose pixel format failed!\n");
		return(-2);
	}
	
	// Select the pixel format of found index
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "Set pixel format function failed!\n");
		return(-3);
	}
	
	// Create rendering context using hdc, pfd and chosen pixel format index
	ghrc = wglCreateContext(ghdc);	// function from Bridging API
	if (ghdc == NULL)
	{
		fprintf(gpFile, "wglCreateContext function failed!\n");
		return(-4);
	}

	// Make this rendering context as current context
	if (wglMakeCurrent(ghdc,ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent function failed!\n");
		return(-5);
	}
	
	// Depth related code
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// Build font here
	buildFont();

	// Load Textures here
	stbi_set_flip_vertically_on_load(TRUE);

	if (LoadPNGTexture(&texture_intro, "../assets/Title.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_intro failed\n");
		return(-6);
	}
	
	if (LoadPNGTexture(&texture_sky_and_underwater, "../assets/SkyAndUnderWaterBG.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_sky failed\n");
		return(-7);
	}

	if (LoadPNGTexture(&texture_sun, "../assets/Sun.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_sun failed\n");
		return(-8);
	}

	if (LoadPNGTexture(&texture_water, "../assets/Water_64.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_Water_64 failed\n");
		return(-9);
	}

	if (LoadPNGTexture(&texture_fish_01, "../assets/Fish_01.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_Fish_01 failed\n");
		return(-10);
	}

	if (LoadPNGTexture(&texture_fish_02, "../assets/Fish_02.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_Fish_02 failed\n");
		return(-11);
	}

	if (LoadPNGTexture(&texture_fish_03, "../assets/Fish_03.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_Fish_03 failed\n");
		return(-12);
	}

	if (LoadPNGTexture(&texture_fish_04, "../assets/Fish_04.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_Fish_04 failed\n");
		return(-13);
	}

	if (LoadPNGTexture(&texture_fish_05, "../assets/Fish_05.png") == FALSE)
	{
		fprintf(gpFile, "LoadPNGTexture() for texture_Fish_05 failed\n");
		return(-14);
	}

	// enabling texture
	glEnable(GL_TEXTURE_2D);

	// From here OpenGL Code starts
	// Tell OpenGL to choose the color to clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// checkout https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-settimer
	timerId = SetTimer(ghwnd, 1, timeUpdate, (TIMERPROC)NULL);

	if (timerId == 0)
	{
		// Handle timer creation error
		fprintf(gpFile, "SetTimer failed\n");
		return -1;
	}

	// Initialize the scene chain
	initScenes();

	// warm up resize
	resize(WIN_WIDTH, WIN_HEIGHT);

    return(0);
}

void resize(int width, int height)
{
    // code
	// if height by accident becomes 0 then make height 1
	if (height <= 0)
	{
		height = 1;
	}

	// Set the viewport
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	// set matrix projection mode
	glMatrixMode(GL_PROJECTION);

	// set to identity matrix
	glLoadIdentity();

	// do perspective projection
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void display(void)
{
    // code
	// clear OpenGL buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set Matrix to Model View mode
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Set it to identity matrix
	glLoadIdentity();

	// Render current scene
	renderCurrentScene();

	SwapBuffers(ghdc);
}

void update(void)
{
	// code
	// Update current scene with the current time
	updateCurrentScene(iTimeElapsed);
}

void buildFont(void)
{
	HFONT font;
	HFONT oldFont;

	base = glGenLists(96);

	font = CreateFont(
		-40, -40, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, \
		ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, \
		ANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH, "matrix"
	);

	oldFont = (HFONT)SelectObject(ghdc, font);
	wglUseFontBitmaps(ghdc, 32, 96, base);
	SelectObject(ghdc, oldFont);
	DeleteObject(font);
}

GLvoid killFont(GLvoid)
{
	glDeleteLists(base, 96);
}

GLvoid glPrint(const char* fmt, ...)
{
	// variable declaration
	char text[256];
	va_list ap;

	// code
	if(fmt == NULL)
	{
		return;
	}

	va_start(ap, fmt);
	vsprintf(text, fmt, ap);

	glPushAttrib(GL_LIST_BIT);
	{
		glListBase(base - 32);
		glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
	}
	glPopAttrib();
}

BOOL LoadPNGTexture(GLuint *texture, char *file)
{
	// variable declaration
	int w, h;
	int channels_in_file;
	BOOL bResult = FALSE;

	// Load the image using the stbi library
	unsigned char *image = stbi_load(file, &w, &h, &channels_in_file, STBI_rgb_alpha);

	// code
	if (image)
	{
		bResult = TRUE;
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
		glGenTextures(1, texture);
		glBindTexture(GL_TEXTURE_2D, *texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		// create texture
		if (channels_in_file == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
			fprintf(gpFile, "Loading a non transparent image !!!\n");
		}
		else if(channels_in_file == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			fprintf(gpFile, "Loading a transparent image !!!\n");

		}
		
		// unbind
		glBindTexture(GL_TEXTURE_2D, 0);

		// free the image
		stbi_image_free(image);
	}
	else
	{
		fprintf(gpFile, "\n %s - %s", file, stbi_failure_reason());
	}

	return bResult;
}

void uninitialize(void) {
	// function declarations
	void toggleFullScreen(void);

    // code
	// If user is exiting in fullscreen then return fullscreen back to normal
	if(gbFullScreen == TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}

	killFont();

	if (texture_sky_and_underwater)
	{
		glDeleteTextures(1, &texture_sky_and_underwater);
		texture_sky_and_underwater = 0;
	}

	if (texture_sun)
	{
		glDeleteTextures(1, &texture_sun);
		texture_sun = 0;
	}

	// Make hdc as current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	// kill timer
	if (timerId != 0)
	{
		KillTimer(ghwnd, timerId);
	}
	
	// Delete the rendering context
	if(ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// Release DC
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
	}

	// Destroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}
	
	
	// Close the file
	if (gpFile)
	{
		fprintf(gpFile, "Program terminated successfully\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}