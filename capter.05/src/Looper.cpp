#include "Looper.h"
#include "TitleScene.h"
#include "Error.h"
#include "GameScene.h"

using namespace std;

Looper::Looper()
{
    Parameter parameter;
    _sceneStack.push(make_shared<TitleScene>(this, parameter)); //�^�C�g����ʃV�[���������push
}
/*!
@brief �X�^�b�N�̃g�b�v�̃V�[���̏���������
*/
bool Looper::loop() const
{
    _sceneStack.top()->update();    //�X�^�b�N�̃g�b�v�̃V�[�����X�V
    _sceneStack.top()->draw();      //�X�^�b�N�̃g�b�v�̃V�[����`��
    return true;
}

/*!
@brief �V�[���ύX(�e�V�[������R�[���o�b�N�����)
@param scene �ύX����V�[����enum
@param parameter �O�̃V�[����������p���p�����[�^
@param stackClear ���݂̃V�[���̃X�^�b�N���N���A���邩
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
    if (stackClear) {//�X�^�b�N�N���A�Ȃ�
        while (!_sceneStack.empty()) {//�X�^�b�N��S���|�b�v����(�X�^�b�N����ɂ���)
            _sceneStack.pop();
        }
    }
    switch (scene) {
    case Title:
        _sceneStack.push(make_shared<TitleScene>(this, parameter));
        break;
    case Game:
        _sceneStack.push(make_shared<GameScene>(this, parameter));
        break;
    default:
        //�ǂ����悤���Ȃ��G���[����
        break;
    }
}
