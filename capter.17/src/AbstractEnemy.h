#pragma once

#include "Task.h"

class AbstractEnemy : public Task
{
public:
    AbstractEnemy(float x, float y);
    virtual ~AbstractEnemy() = default;
    void initialize();
    bool update() override;

protected:
    virtual void setSize() = 0;
    bool isInside() const;

    float _x, _y;//���W
    float _speed;//����
    float _angle;//�p�x

    int _counter;//�J�E���^
    int _width; //��
    int _height;//����
};

