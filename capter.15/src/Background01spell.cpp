#include "Background01spell.h"
#include "Image.h"
#include "Define.h"
#include <DxLib.h>

using namespace std;

const static int   IMG_HEIGHT = 879;
const static float SCROLL_SPEED = 2.f;

Background01spell::Background01spell()
{
    _list[0] = make_shared<Quadrangle>(0, IMG_HEIGHT * 0, Image::getIns()->getBackSpell00());
    _list[1] = make_shared<Quadrangle>(0, IMG_HEIGHT * 1, Image::getIns()->getBackSpell01());
    _list[2] = make_shared<Quadrangle>(0, IMG_HEIGHT * 2, Image::getIns()->getBackSpell00());
    _list[3] = make_shared<Quadrangle>(0, IMG_HEIGHT * 3, Image::getIns()->getBackSpell01());
}

bool Background01spell::update()
{
    for (int i = 0; i < NUM; i++) {//�S�ď�ɃX�N���[��������
        _list[i]->y -= SCROLL_SPEED;
        if (_list[i]->y < -IMG_HEIGHT) {//��ɍs���؂�����
            _list[i]->y += IMG_HEIGHT * 4;//��ԉ��ɉ�����
        }
    }
    return true;
}

void Background01spell::draw() const
{
    SetDrawArea(0, 0, Define::OUT_W, Define::OUT_H);    //�G���A�O�͕`��ΏۊO�ɂ���
    for (int i = 0; i < NUM; i++) {
        DrawGraphF(_list[i]->x, _list[i]->y, _list[i]->img, FALSE);
    }
    SetDrawArea(0, 0, Define::WIN_W, Define::WIN_H);    //�`��͈͂����ɖ߂�
}
