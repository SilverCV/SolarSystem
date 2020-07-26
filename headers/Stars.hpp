//
// Created by jsl on 2020/7/25.
//

#ifndef SOLARSYSTEM_STARS_HPP
#define SOLARSYSTEM_STARS_HPP
#include <GL/glut.h>
#define N 1440

class Stars {
public:
    Stars(GLfloat Radius,GLfloat Distance,GLfloat Speed,GLfloat SelfSpeed,
               Stars* Parent);
    virtual ~Stars();
    void DrawStar();
    virtual void Draw();
    virtual void update(long timeSpan);


protected:
    GLfloat alphaSelf,alpha;
    GLfloat selfSpeed;  //自转速度
    GLfloat speed;//星球公转速度
    GLfloat radius; //半径
    GLfloat rgbaColor[4]; //星球颜色
    GLfloat distance;
    Stars* parentStars;

};
class Planet : public Stars{
public:
    Planet(GLfloat Radius,GLfloat Distance,GLfloat Speed,GLfloat SelfSpeed,
           Stars* Parent,GLfloat RgbaColor[]);
    void DrawPlanet();
    virtual void Draw();
};
class LightPlanet : public Planet{
public:
    LightPlanet(GLfloat Radius,GLfloat Distance,GLfloat Speed,GLfloat SelfSpeed,
            Stars* Parent,GLfloat rgbColor[]);
    void DrawLight();
    virtual void Draw();
};
#endif //SOLARSYSTEM_STARS_HPP
