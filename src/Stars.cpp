//
// Created by jsl on 2020/7/25.
//

#include "Stars.hpp"
#include <cmath>

Stars::Stars(GLfloat Radius,GLfloat Distance,GLfloat Speed,GLfloat SelfSpeed,
             Stars* Parent)
{
    radius = Radius;
    selfSpeed = SelfSpeed;
    parentStars = Parent;
    if (Speed > 0)
        speed = 360.0f/Speed;
    else
        speed = 0.0f;
    distance = Distance;
    for (int i = 0; i < 4; ++i) {
        rgbaColor[i] = 1.0f;
    }

}
Stars::~Stars(){}
//绘画星球
void Stars::DrawStar() {
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);


    glPushMatrix();
    {
        //公转处理
        if (parentStars != NULL && parentStars->distance > 0)
        {
            //绘制z轴
            glRotated(parentStars->alpha,0,0,1);
            //平移
            glTranslatef(parentStars->distance,0.0,0.0);
        }

        glBegin(GL_LINES);
        for (int i = 0; i < N; ++i) {
            glVertex2f(distance * cos(2 * M_PI *i / N),distance * sin(2 * M_PI *i / N));
        }
        glEnd();

        glRotatef(alpha,0,0,1);
        glTranslatef(distance,0.0,0.0);

        //自转
        glRotatef(alphaSelf,0,0,1);
        //绘制颜色
        glColor3f(rgbaColor[0],rgbaColor[1],rgbaColor[2]);
        glutSolidSphere(radius,40,32);

    }
    glPopMatrix();
}

void Stars::Draw() {
    DrawStar();
}
//更新
void Stars::update(long timeSpan) {
    alpha += timeSpan * speed;
    alphaSelf += selfSpeed;
}

Planet::Planet(GLfloat Radius,GLfloat Distance,GLfloat Speed,GLfloat SelfSpeed,
               Stars* Parent,GLfloat RgbaColor[])
               : Stars(Radius,Distance,Speed,SelfSpeed,Parent)
{
    for (int i = 0; i < 3; ++i) {
        rgbaColor[i] = RgbaColor[i];
    }
    rgbaColor[3] = 1.0f;
}
void Planet::Draw() {
    DrawPlanet();
    DrawStar();
}

void Planet::DrawPlanet() {
    GLfloat ambient[] = {0.0f,0.0f,0.5f,1.0f};
    GLfloat diffuse[] = {0.0f,0.0f,0.5f,1.0f};
    GLfloat specular[] = {0.0f,0.0f,1.0f,1.0f};
    GLfloat emission[] = {rgbaColor[0],rgbaColor[1],rgbaColor[2],rgbaColor[3]};
    GLfloat shiniess = 90.0f; //发光



    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialfv(GL_FRONT,GL_EMISSION,emission);
    glMaterialf(GL_FRONT,GL_SHININESS,shiniess);
}

LightPlanet::LightPlanet(GLfloat Radius,GLfloat Distance,GLfloat Speed,GLfloat SelfSpeed,
                         Stars* Parent,GLfloat RgbaColor[])
                         : Planet(Radius,Distance,Speed,SelfSpeed,Parent,RgbaColor)
{
}

void LightPlanet::Draw() {
    DrawLight();
    DrawPlanet();
    DrawStar();
}

void LightPlanet::DrawLight() {
    GLfloat position[] = {0.0f,0.0f,0.0f,1.0f};
    GLfloat ambient[] = {0.0f,0.0f,0.0f,1.0f};
    GLfloat diffuse[] = {1.0f,1.0f,1.0f,1.0f};
    GLfloat specular[] = {1.0f,1.0f,1.0f,1.0f};

    glLightfv(GL_LIGHT0,GL_POSITION,position);//光源位置
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);//光线强度
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);//漫反射
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular);//镜面放射
}