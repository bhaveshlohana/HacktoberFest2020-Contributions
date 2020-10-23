#include <cmath>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>
//#include <game.h>

// This is a 3D Bounce game
using std::cout;
using std::endl;

namespace
{

    float t = 0.05;

    const float PI = 3.1416f;

    const float GRAVITY = 15;

    const float INITIAL_VELOCITY = 20;

    //The radius of the ball
    const float RADIUS_OF_BALL = 1.0f;

    //speed of the moving ball
    float SPEED_OF_BALL = 0.1f;

    //The amount of time it takes for a ball to fade into play
    const float BALL_FADE_IN_TIME = 0.5f;
    //The amount of time it takes for a ball to fade out of play
    const float BALL_FADE_OUT_TIME = 0.5f;
} // namespace

Ball::Ball() : r(RADIUS_OF_BALL), pos(12, 1, -20), isCollided(false) {}

float Ball::radius()
{
    return r;
}

float Ball::x()
{
    float tempx = pos.v[0];
    return tempx;
}

float Ball::y()
{
    float tempy = pos.v[1];
    return tempy;
}

float Ball::z()
{
    float tempz = pos.v[2];
    return tempz;
}

float Ball::angle()
{
    return angle0;
}

void Ball::fadeOut()
{
    isFadingOut0 = true;
}

bool Ball::isFadingOut()
{
    return isFadingOut0;
}

void Ball::checkleftkey(float angle)
{
    float tangle = angle + 20;
    float tmpangle = tangle;
    if (tangle <= 180)
    {
        tmpangle = -tangle - 360 + 20;
    }
    else
    {
        tmpangle = -tangle;
    }
    if (detectCollision(pos))
    {
        pos.v[0] -= SPEED_OF_BALL * cos(tmpangle * PI / 180);
        pos.v[2] += SPEED_OF_BALL * sin(tmpangle * PI / 180);
    }
}
void Ball::checkrightkey(float angle)
{
    float tangle = angle + 20;
    float tmpangle = tangle;
    if (tangle <= 180)
        tmpangle = -360 - tangle + 20;
    else
        tmpangle = -tangle;
    if (detectCollision(pos))
    {
        pos.v[0] += SPEED_OF_BALL * cos(tmpangle * PI / 180);
        pos.v[2] -= SPEED_OF_BALL * sin(tmpangle * PI / 180);
    }
}
void Ball::checkupkey(float angle)
{
    float tangle = angle + 20;
    float tmpangle = tangle;
    pos.v[0] += SPEED_OF_BALL * sin(tmpangle * PI / 180);
    pos.v[2] -= SPEED_OF_BALL * cos(tmpangle * PI / 180);
    if (pos.v[2] < 0.0)
        pos.v[2] = pos.v[2];
}

void Ball::checkdownkey(float angle)
{
    float tangle = angle + 20;
    float tmpangle = tangle;
    pos.v[0] -= SPEED_OF_BALL * sin(tmpangle * PI / 180);
    pos.v[2] += SPEED_OF_BALL * cos(tmpangle * PI / 180);
    if (pos.v[2] > -1.0)
        pos.v[2] = -1.0;
}

//Bounce the ball by changing the y component using h = ut - 1/2gt^2
void Ball::stepup(bool &value)
{
    pos.v[1] = INITIAL_VELOCITY * t - 0.5 * (GRAVITY)*pow(t, 2);
    t = t + 0.025;
    if (t > 2.65)
    {
        pos.v[1] = 1;
        t = 0.05;
        value = false;
    }
}

bool Ball::detectCollision(Vec3f pos)
{
    if (pos.v[0] < 1.0)
    {
        ;
        return true;
    }
    if (pos.v[0] > 400)
        return true;
    if (pos.v[2] < -1.0)
        return true;
    if (pos.v[2] > 400)
        return true;
}