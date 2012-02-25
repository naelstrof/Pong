#include <iostream>
#include <GL/glfw.h>
#include "Ball.h"
#include "Paddle.h"

static unsigned int Width = 512;
static unsigned int Height = 512;

int main()
{
   if (!glfwInit())
   {
      std::cout << "GLFW failed to initialize!\n";
      return 1;
   }
   glfwOpenWindow(Width,Height,0,0,0,0,0,0,GLFW_WINDOW);
   glfwSetWindowTitle("Pong");
   glViewport(0,0,Width,Height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0,Width,Height,0,0,1);
   glMatrixMode(GL_MODELVIEW);
   glClearColor(0,0,1,1);

   NPad::SetScreen(Width,Height);
   NBall::SetScreen(Width,Height);
   NBall::Ball MyBall;
   NPad::SetCollisions(&MyBall);
   NPad::Paddle MyPaddle(Height-20,60);
   NPad::Paddle EnemyPaddle(20,60);
   MyPaddle.SetControl();
   float LastTime = glfwGetTime();
   while(true)
   {
       float DeltaTime = glfwGetTime()-LastTime;
       LastTime = glfwGetTime();
       if (!glfwGetWindowParam(GLFW_OPENED))
       {
           std::cout << "Window was closed! Exiting...\n";
           break;
       }
       MyBall.Update(DeltaTime);
       MyPaddle.Update(DeltaTime);
       EnemyPaddle.Update(DeltaTime);
       glClear(GL_COLOR_BUFFER_BIT);
       MyBall.Draw();
       MyPaddle.Draw();
       EnemyPaddle.Draw();
       glfwSwapBuffers();
   }
   return 0;
}
