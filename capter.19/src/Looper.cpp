#include "Looper.h"
#include "TitleScene.h"
#include "Error.h"
#include "GameScene.h"
#include "Macro.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Image.h"

using namespace std;

Looper::Looper()
{
    Image::getIns()->load();

    Parameter parameter;
    _sceneStack.push(make_shared<GameScene>(this, parameter)); //�Q�[����ʃV�[���������push
}

/*!
@brief �X�^�b�N�̃g�b�v�̃V�[���̏���������
*/
bool Looper::loop() 
{
    Keyboard::getIns()->update();   //�L�[�{�[�h�̍X�V
    Pad::getIns()->update();        //�W���C�p�b�h�̍X�V
    _sceneStack.top()->update();    //�X�^�b�N�̃g�b�v�̃V�[�����X�V
    _sceneStack.top()->draw();      //�X�^�b�N�̃g�b�v�̃V�[����`��
    _fps.draw();                    //FPS�̕\��
    _fps.wait();                    //�ݒ肵��FPS�ɂȂ�悤�ɑҋ@
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
        ERR("����͂��̂Ȃ��V�[�����Ă΂�܂���");
        break;
    }
}
