#include "Paddle.h"

using namespace NPad;

Paddle::Paddle(float W)
{
    x = Width/2;
    vx = 0;
    w = W;
}

void Paddle::Draw()
{
    glPushMatrix();
    glTranslatef(x,Height-20,0);
    glBegin(GL_QUADS);
    glVertex2f(-w,-20);
    glVertex2f(w,-20);
    glVertex2f(w,20);
    glVertex2f(-w,20);
    glEnd();
    glPopMatrix();
}

void Paddle::Update(float DeltaTime)
{
    if (glfwGetKey(GLFW_KEY_LEFT))
    {
        vx -= 2000*DeltaTime;
    } else if (glfwGetKey(GLFW_KEY_RIGHT))
    {
        vx += 2000*DeltaTime;
    }
    x += vx*DeltaTime;
    vx *= 1-(5*DeltaTime);
    if (x+w>Width)
    {
        x = Width-w;
        vx = 0;
    } else if (x-w<0)
    {
        x = w;
        vx = 0;
    }
}

void NPad::SetScreen(unsigned int w, unsigned int h)
{
    Width = w;
    Height = h;
}
