#include "IO.h"
#include "DxLib.h"

#define X 0
#define Y 1

void IO::Mouse_Initialize(bool *Mouse_Down, bool *oldMouse_Down, int *MousePos)
{
	if (Mouse_Down == nullptr || oldMouse_Down == nullptr || MousePos == nullptr) {
		return;
	}

	//�O�t���[���}�E�X����ۑ�
	*oldMouse_Down = *Mouse_Down;

	//�}�E�X����ۑ�
	MOUSE_INPUT_LEFT ? *Mouse_Down = true : *Mouse_Down = false;
	GetMousePoint(&MousePos[X], &MousePos[Y]);
}

void IO::key_Initialize(char *keys, char *oldkeys)
{
	if (keys == nullptr || oldkeys == nullptr) {
		return;
	}

	//�O�t���[���L�[����ۑ�
	for (int i = 0; i < 256; i++) {
		oldkeys[i] = keys[i];
	}
	GetHitKeyStateAll(keys);
}
