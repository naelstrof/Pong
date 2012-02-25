#ifndef PADDLE
#define PADDLE
#include <GL/glfw.h>
#include "Ball.h"

namespace NPad
{
    static unsigned int Width,Height;
    void SetScreen(unsigned int, unsigned int);
    static NBall::Ball* CollisionBall;
    void SetCollisions(NBall::Ball*);
    class Paddle
    {
        public:
            bool IsControlled;
            float x,vx,y,w;
            void SetControl();
            Paddle(float, float);
            void Draw();
            void Update(float);
    };
}

#endif
