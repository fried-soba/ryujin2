#include "GameScene.h"
#include <DxLib.h>
#include "Macro.h"

const char* GameScene::ParameterTagStage = "ParameterTagStage";//�p�����[�^�̃^�O�u�X�e�[�W�v
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//�p�����[�^�̃^�O�u���x���v

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) : AbstractScene(impl, parameter)
{
    _level = parameter.get(ParameterTagLevel);
    if (_level == Parameter::Error) {
        ERR("�n���ꂽ���x�����s���ł�");
    }
}

void GameScene::update()
{
}

void GameScene::draw() const
{
    DrawFormatString(100, 100, GetColor(255, 255, 255), "�Q�[�����x���� %d �ł�", _level);
}
