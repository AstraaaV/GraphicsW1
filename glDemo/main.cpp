
#include "core.h"
#include <cmath>
#include "MyShapes.h"


// global variables

// Window size
const unsigned int initWidth = 512;
const unsigned int initHeight = 512;

// Pi
const float M_PI = 3.14f;

float tankX = 0.0f, tankY = 0.0f; // Tanks' pos
float tankOri = 0.0f; // Tank orientation
float tankSpeed = 0.1f; // Tank movement speed
float rotSpeed = 5.0f; // Tank rotation speed

void renderScene();
void resizeWindow(GLFWwindow* window, int width, int height);
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
void updateScene();


int main() {

	//
	// 1. Initialisation
	//
	

	// Initialise glfw and setup window
	glfwInit();

	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GLFW_TRUE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);

	GLFWwindow* window = glfwCreateWindow(initWidth, initHeight, "Real-Time Computer Graphics", NULL, NULL);

	// Check window was created successfully
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	

	// Set callback functions to handle different events
	glfwSetFramebufferSizeCallback(window, resizeWindow); // resize window callback
	glfwSetKeyCallback(window, keyboardHandler); // Keyboard input callback


	// Initialise glew
	glewInit();

	
	// Setup window's initial size
	resizeWindow(window, initWidth, initHeight);

	// Initialise scene - geometry and shaders etc
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // setup background colour to be black


	//
	// 2. Main loop
	// 
	

	// Loop while program is not terminated.
	while (!glfwWindowShouldClose(window)) {

		updateScene();
		renderScene();						// Render into the current buffer
		glfwSwapBuffers(window);			// Displays what was just rendered (using double buffering).

		// Poll events (key presses, mouse events)
		// glfwWaitEvents();				// Use this if no animation.
		// glfwWaitEventsTimeout(1.0/60.0);	// Use this to animate at 60 frames/sec (timing is NOT reliable)
		glfwPollEvents();					// Use this version when animating as fast as possible
	}

	glfwTerminate();
	return 0;
}

// renderScene - function to render the current scene
void renderScene()
{
	// Clear the rendering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Render objects here...
	//drawPolygon(0.0f, 0.0f, 3, 0.5f); // Triangle
	//drawPolygon(-0.5, 0.5f, 4, 0.3f); // Square
	//drawPolygon(0.5f, -0.5f, 6, 0.4f); // Hexagon

	// Render Star
	//drawStar(0.0f, 0.0f, 0.2f, 0.5f, 5); // Five pointed star
	
	// Tank one
	//drawTank(tankX, tankY, tankOri, 1.0f, 0.0f, 0.0f);

	// Tank two
	//drawTank(-0.5f, -0.5f, 180.0f, 0.0f, 0.0f, 1.0f);

	//drawBlendedRectangles();

	MyShapes::drawSemiCircleStudio();

	glEnd();
}


// Function to call when window resized
void resizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);		// Draw into entire window

	glMatrixMode(GL_PROJECTION); // Switch to projection view
	glLoadIdentity(); // Reset previous projection
	glOrtho(-1, 1, -1, 1, -1, 1); // Sets coord system

	glMatrixMode(GL_MODELVIEW); // Switch back to model view
}


// Function to call to handle keyboard input
void keyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {

		// repeat is for continuous movement
		// check which key was pressed...
		switch (key)
		{
			case GLFW_KEY_W: // forward movement
				tankX += tankSpeed * cos(tankOri * M_PI / 180.0f);
				tankY += tankSpeed * sin(tankOri * M_PI / 180.0f);
				break;
			case GLFW_KEY_S: // backward movement
				tankX -= tankSpeed * cos(tankOri * M_PI / 180.0f);
				tankY -= tankSpeed * sin(tankOri * M_PI / 180.0f);
				break;
			case GLFW_KEY_A: // rotate left
				tankOri += rotSpeed;
				break;
			case GLFW_KEY_D: // rotate right
				tankOri -= rotSpeed;
				break;
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;

			default:
			{
			}
		}
	}
	else if (action == GLFW_RELEASE) {
		// handle key release events
	}
}


// Function called to animate elements in the scene
void updateScene() {
}

