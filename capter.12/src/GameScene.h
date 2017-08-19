#pragma once

#include "AbstractScene.h"
#include "Player.h"
#include <memory>

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
    std::shared_ptr<Player> _player;
};

