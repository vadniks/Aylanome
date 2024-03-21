
#include <stdlib.h>
//#include <GLES3/gl3.h>
//#include <GLFW/glfw3.h>
#include <GL/glew.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//#include <GL/glext.h>
#include <SDL.h>

int main(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) exit(1);

    SDL_version version;
    SDL_GetVersion(&version);
    if (version.major != 2) abort();

    SDL_Window* mainWindow;
    SDL_GLContext mainContext;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    mainWindow = SDL_CreateWindow(
        "title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        512,
        512,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );
    if (!mainWindow) abort();

    mainContext = SDL_GL_CreateContext(mainWindow);
    SDL_GL_SetSwapInterval(1); // This makes our buffer swap syncronized with the monitor's vertical refresh

    SDL_Delay(50);

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Clear our buffer with a red background
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(mainWindow); // Swap our back buffer to the front
    SDL_Delay(2000); // Wait 2 seconds

    SDL_GL_DeleteContext(mainContext);
    SDL_DestroyWindow(mainWindow);

    SDL_Quit();
    if (SDL_GetNumAllocations() != 0) abort();

    return 0;
}
