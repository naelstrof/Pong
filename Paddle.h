#ifndef PADDLE
#define PADDLE
#include <GL/glfw.h>

namespace NPad
{
    static unsigned int Width,Height;
    void SetScreen(unsigned int, unsigned int);
    class Paddle
    {
        public:
            float x,vx,w;
            Paddle(float);
            void Draw();
            void Update(float);
    };
}

#endif
