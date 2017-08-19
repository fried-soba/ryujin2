#include "Player.h"
#include "Pad.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"

const static float SPEED = 9;

Player::Player() : 
    _x((float)Define::CENTER_X),
    _y((float)Define::OUT_H*0.8f)
{
}

bool Player::update()
{
    move();
    return true;
}

void Player::draw() const
{
    DrawRotaGraphF(_x, _y, 1.0, 0.0, Image::getIns()->getPlayer(), TRUE);
}

/*!
@brief �v���C���[�𓮂���
*/
void Player::move()
{
    float moveX = 0, moveY = 0;
    if (Pad::getIns()->get(ePad::left) > 0) {
        moveX -= SPEED;
    }
    if (Pad::getIns()->get(ePad::right) > 0) {
        moveX += SPEED;
    }
    if (Pad::getIns()->get(ePad::down) > 0) {
        moveY += SPEED;
    }
    if (Pad::getIns()->get(ePad::up) > 0) {
        moveY -= SPEED;
    }
    if (moveX && moveY) { //�΂߈ړ�
        moveX /= (float)sqrt(2.0);
        moveY /= (float)sqrt(2.0);
    }
    if (Pad::getIns()->get(ePad::slow) > 0) {//�ᑬ�ړ�
        moveX /= 3;
        moveY /= 3;
    }
    if (moveX + _x < Define::IN_X) {//���g��荶�Ȃ�
        _x = (float)Define::IN_X;   //���g�Ŏ~�߂�
    }
    else if (moveX + _x > Define::IN_X + Define::IN_W) {//�E�g���E�Ȃ�
        _x = (float)(Define::IN_X + Define::IN_W);      //�E�g�Ŏ~�߂�
    }
    else {//�g���Ȃ�
        _x += moveX;//���ʂɈړ�
    }
    if (moveY + _y < Define::IN_Y) {   //��g����Ȃ�
        _y = (float)Define::IN_Y;      //��g�Ŏ~�߂�
    }
    else if (moveY + _y > Define::IN_Y + Define::IN_H) {    //���g��艺�Ȃ�
        _y = (float)(Define::IN_Y + Define::IN_H);          //���g�Ŏ~�߂�
    }
    else {//�g���Ȃ�
        _y += moveY;//���ʂɈړ�
    }
}