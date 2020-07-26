//
// Created by jsl on 2020/7/25.
//

#ifndef SOLARSYSTEM_SOLAR_HPP
#define SOLARSYSTEM_SOLAR_HPP
#include <GL/glut.h>
#include "Stars.hpp"
#define STARS_NUM 10
#define OFFSET 20
class Solar {
public:
    Solar();
    ~Solar();

    void onDisplay();
    void onUpdate();
    void onKeyboard(u_char key,int x,int y);

private:
    Stars* stars[STARS_NUM];

    GLdouble  viewX,viewY,viewZ;
    GLdouble centerX,centerY,centerZ;
    GLdouble  upX,upY,upZ;
};
//星球的半径
#define SUN_RADIUS 48.74
#define MER_RADIUS 7.32
#define VEN_RADIUS 18.15
#define EAR_RADIUS 19.13
#define MOO_RADIUS 6.15
#define MAR_RADIUS 10.19
#define JUP_RADIUS 42.90
#define SAT_RADIUS 36.16
#define URA_RADIUS 25.56
#define NEP_RADIUS 24.78

#define MER_DIS 62.06
#define VEN_DIS 115.56
#define EAR_DIS 168.00
#define MOO_DIS 26.01
#define MAR_DIS 228.00
#define JUP_DIS 333.40
#define SAT_DIS 428.10
#define URA_DIS 848.00
#define NEP_DIS 949.10

#define MER_SPEED 87.0
#define VEN_SPEED 225.0
#define EAR_SPEED 365.0
#define MOO_SPEED 30.0
#define MAR_SPEED 687.0
#define JUP_SPEED 1298.4
#define SAT_SPEED 3225.6
#define URA_SPEED 3066.4
#define NEP_SPEED 6014.8

#define SELFROTATE 3
enum STARS{
    SUN, //太阳
    MERCURY,//水星
    VENUS,//金星
    EARTH,//地球
    MOON,//月球
    MARS,//火星
    JUPITER,//木星
    SATURN,//土星
    URANUS,//天王星
    NEPTUNE //海王星
};

#define SET_VALUE_3(name,value0,value1,value2) \
                    ((name)[0] = (value0),(name)[1] = (value1),(name)[2] = (value2))

#define REST 700
#define REST_Y (-REST)
#define  REST_Z (REST)

#define TEMPAST 1

#endif //SOLARSYSTEM_SOLAR_HPP
