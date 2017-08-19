#include "Image.h"
#include <DxLib.h>

Image::Image()
{
    _player = myLoadGraph("../dat/image/player/body/seishi0.png");
}

/*!
@brief ���܂Ń��[�h�����摜���������
*/
void Image::release() 
{
    const int size = _images.size();
    for (int i = 0; i < size; i++) {
        DeleteGraph(_images[i]);
    }
    _images.clear();
}

/*!
@brief �v���C���[�̉摜���擾����
*/
int Image::getPlayer() const
{
    return _player;
}

/*!
@brief LoadGraph�����āA�����̃n���h���������o�ϐ��ɒǉ�����
*/
int Image::myLoadGraph(char *fileName)
{
    int ret = LoadGraph(fileName);
    _images.push_back(ret);
    return ret;
}

/*!
@brief LoadDivGraph�����āA�����̃n���h���������o�ϐ��ɒǉ�����
*/
int Image::myLoadDivGraph(char *fileName, int n, int xn, int yn, int w, int h, int* buf)
{
    int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
    for (int i = 0; i < n; i++) {
        _images.push_back(buf[i]);
    }
    return ret;
}