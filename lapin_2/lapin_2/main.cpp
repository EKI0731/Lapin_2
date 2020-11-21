#include "DxLib.h"
#include "Color.h"
#include "Initialize_conponent.h"
#include "Scene_Start.h"
#include "Scene_Build.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//������
	Initialize_conponent Init;
	Init.Initialize();
	if (DxLib_Init() == -1) { return -1; }
	SetDrawScreen(DX_SCREEN_BACK);

	//�^�C�g��
	Scene_Start *start = new Scene_Start;
	start->Start_Window();
	delete start;

	//�X�e�[�W����V�[��
	Scene_Build *Build = new Scene_Build;
	Build->Build_Window();
	delete Build;

	//�X�e�[�W���s�V�[��


	//�I������
	DxLib_End();
	return 0;
}