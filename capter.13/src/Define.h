#pragma once

class Define final {
public:
    const static int WIN_W;    //�E�B���h�E�T�C�Y��
    const static int WIN_H;    //�E�B���h�E�T�C�Y�c

    const static int OUT_W;//�O�g��
    const static int OUT_H;//�O�g����
    const static int IN_W;//���g��
    const static int IN_H;//���g����
    const static int CENTER_X;//������͈͂̒���X
    const static int CENTER_Y;//������͈͂̒���Y
    const static int IN_X;//���gX
    const static int IN_Y;//���gY

    const static float PI;    //�~����

    enum eStage {
        Stage1,
        Stage2,
        Stage3,
        Stage4,
        Stage5,
        StageEX,
        StageNum,
    };

    enum eLevel {
        Easy,
        Normal,
        LevelNum
    };

};
