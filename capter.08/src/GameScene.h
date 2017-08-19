#pragma once

#include "AbstractScene.h"

class GameScene : public AbstractScene
{
public:
    const static char* ParameterTagStage;//�p�����[�^�̃^�O�u�X�e�[�W�v
    const static char* ParameterTagLevel;//�p�����[�^�̃^�O�u���x���v

    GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~GameScene() = default;

    void update() override;
    void draw() const override;

private:
    int _level;
};

