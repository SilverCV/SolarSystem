//
// Created by jsl on 2020/7/25.
//

#include "Solar.hpp"
Solar::Solar()
{
    //定义视角
    viewX = 0;
    viewY = REST_Y;
    viewZ = REST_Z;
    centerX = 0;
    centerY = 0;
    centerZ = 0;
    upX = 0;
    upY = 0;
    upZ = 1;
    GLfloat rgbcolor[3] = {1.0f,0.0f,0.0f};
    stars[SUN] = new LightPlanet(SUN_RADIUS,0,0,SELFROTATE,0,rgbcolor);

    SET_VALUE_3(rgbcolor,.2,.2,.5);
    stars[MERCURY] = new Planet(MER_RADIUS,MER_DIS,MER_SPEED,SELFROTATE,stars[SUN],rgbcolor);

    SET_VALUE_3(rgbcolor,1,.7,0);
    stars[VENUS] = new Planet(VEN_RADIUS,VEN_DIS,VEN_SPEED,SELFROTATE,stars[SUN],rgbcolor);

    SET_VALUE_3(rgbcolor,0,1,0);
    stars[EARTH] = new Planet(EAR_RADIUS,EAR_DIS,EAR_SPEED,SELFROTATE,stars[SUN],rgbcolor);

    SET_VALUE_3(rgbcolor,1,1,0);
    stars[MOON] = new Planet(MOO_RADIUS,MOO_DIS,MOO_SPEED,SELFROTATE,stars[EARTH],rgbcolor);

    SET_VALUE_3(rgbcolor,1,.5,.5);
    stars[MARS] = new Planet(MAR_RADIUS,MAR_DIS,MAR_SPEED,SELFROTATE,stars[SUN],rgbcolor);

    SET_VALUE_3(rgbcolor,1,1,.5);
    stars[JUPITER] = new Planet(JUP_RADIUS,JUP_DIS,JUP_SPEED,SELFROTATE,stars[SUN],rgbcolor);

    SET_VALUE_3(rgbcolor,.5,1,.5);
    stars[SATURN] = new Planet(SAT_RADIUS,SAT_DIS,SAT_SPEED,SELFROTATE,stars[SUN],rgbcolor);

    SET_VALUE_3(rgbcolor,.4,.4,.4);
    stars[URANUS] = new Planet(URA_RADIUS,URA_DIS,URA_SPEED,SELFROTATE,stars[SUN],rgbcolor);

    SET_VALUE_3(rgbcolor,.5,.5,1);
    stars[NEPTUNE] = new Planet(NEP_RADIUS,NEP_DIS,NEP_SPEED,SELFROTATE,stars[SUN],rgbcolor);
}
Solar::~Solar() {
    for (int i = 0; i < STARS_NUM; ++i) {
        delete stars[i];
    }
}
void Solar::onDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(.7f,.7f,.7f,.1f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(75.0f,1.0f,1.0f,40000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(viewX,viewY,viewZ,centerX,centerY,centerZ,upX,upY,upZ);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    //实际绘制
    for (int i = 0; i < STARS_NUM; ++i) {
        stars[i]->Draw();
    }

    glutSwapBuffers();
}
//w +y
//x -y
//a -x
//d +z
//s +z
//S -z
void Solar::onKeyboard(u_char key, int x, int y) {
    switch (key)
    {
        case 'w': viewY += OFFSET;break;
        case 'x': viewY -= OFFSET;break;
        case 'a': viewX -= OFFSET;break;
        case 'd': viewX += OFFSET;break;
        case 's': viewZ += OFFSET;break;
        case 'S': viewZ -= OFFSET;break;
        case 27: exit(0);break;
        default: break;
    }
}
void Solar::onUpdate() {
    for (int i = 0; i < STARS_NUM; ++i) {
        stars[i]->update(TEMPAST);
    }
    onDisplay();
}
