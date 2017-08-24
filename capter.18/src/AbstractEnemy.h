#pragma once

#include "Task.h"
#include "EnemyMover.h"

class EnemyMover;

class AbstractEnemy : public Task
{
public:
    AbstractEnemy(float x, float y);
    virtual ~AbstractEnemy() = default;
    void initialize();
    bool update() override;

    float getX() { return _x; }
    void  setX(float x) { _x = x; }
    float getY() { return _y; }
    void  setY(float y) { _y = y; }
    int   getCounter() { return _counter; }
    void  setSpeed(float speed) { _speed = speed; }
    float getSpeed() { return _speed; }
    void  setAngle(float angle) { _angle = angle; }
    float getAngle() { return _angle; }
    int   getMovePatternID() { return _movePatternID;  }

protected:
    virtual void setSize() = 0;
    bool isInside() const;

    EnemyMover _mover;

    float _x, _y;//���W
    float _speed;//����
    float _angle;//�p�x

    int _counter;//�J�E���^
    int _width; //��
    int _height;//����

    int _movePatternID;//�ړ��p�^�[��
};

