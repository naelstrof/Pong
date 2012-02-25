#include "Ball.h"

using namespace NBall;

Ball::Ball()
{
    x = Width/2;
    y = Height/2;
    vx = 0;
    vy = 400;
}

void Ball::Draw()
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glBegin(GL_QUADS);
    glVertex2f(-20,-20);
    glVertex2f(20,-20);
    glVertex2f(20,20);
    glVertex2f(-20,20);
    glEnd();
    glPopMatrix();
}

void Ball::Update(float DeltaTime)
{
    if (x+20>Width)
    {
        x = Width-20;
        vx *= -1;
    } else if (x-20<0)
    {
        x = 20;
        vx *= -1;
    }
    x += vx*DeltaTime;
    y += vy*DeltaTime;
}

void NBall::SetScreen(unsigned int w, unsigned int h)
{
    Width = w;
    Height = h;
}
