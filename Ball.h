#ifndef BALL
#define BALL
#include <GL/glfw.h>

namespace NBall
{
    static unsigned int Width,Height;
    void SetScreen(unsigned int, unsigned int);
    class Ball
    {
        public:
            float x,y,vx,vy;
            Ball();
            void Draw();
            void Update(float);
    };
}

#endif
