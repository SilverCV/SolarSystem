#include <GL/glut.h>
#include "Solar.hpp"
#define HIEGHT 700
#define WIDTH 700
#define X_POS 70
#define Y_POS 70
Solar solar;
void onDisplay()
{
    solar.onDisplay();
}
void onUpdate()
{
    solar.onUpdate();
}
void onKeyboard(u_char key,int x,int y){
    solar.onKeyboard(key,x,y);
}
int main(int argc,char* argv[])
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutInitWindowPosition(X_POS,Y_POS);
    glutCreateWindow("SolarSystem");

    glutDisplayFunc(onDisplay);
    glutIdleFunc(onUpdate);
    glutKeyboardFunc(onKeyboard);
    glutMainLoop();
    return 0;
}