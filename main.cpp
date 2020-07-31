#define _CRT_SECURE_NO_WARNINGS

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########
#include "DxLib.h"
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include <dos.h>
#include<math.h>
#include<stdlib.h>


//########## �}�N����` ##########
#define GAME_WIDTH	640		//��ʂ̉��̑傫��
#define GAME_HEIGHT	640		//��ʂ̏c�̑傫��
#define GAME_COLOR	32		//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_NAME	"Cliate Adventure"		//�E�B���h�E�̃^�C�g��
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE�F�E�B���h�E���[�h / FALSE�F�t���X�N���[��

#define SET_WINDOW_ST_MODE_DEFAULT			0	//�f�t�H���g
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//�^�C�g���o�[�Ȃ�
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//�^�C�g���o�[�ƃt���[���Ȃ�
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//�t���[���Ȃ�

#define FPS_SPEED    60

#define BACKIMAGE_1 "BACKIMAGE\\haikei1.png"

#define BACKIMAGE_SOUSA "BACKIMAGE\\haikei_setumei.png"

#define BACKIMAGE_OVER "BACKIMAGE\\haikei_over_kakou.png"

#define BACKIMAGE_CLEAR "BACKIMAGE\\haikei_clear_kakou.png"

#define BACKGROUND_TITLE "BACKIMAGE\\logo_3.png"

#define MOJI_GAME_OVER "BACKIMAGE\\GAME_OVER.png"

#define MAP_1   "MAPIMAGE\\map.png"

#define MAP_CSV_1    "MAPIMAGE\\map_54_64.csv"

#define PLAYER_IMAGE "CHARA\\syuzinkou.png"

#define SE_JUMP "MUSIC\\jump.mp3"

#define SE_GAME_OVER "MUSIC\\oti.mp3"

#define SE_GAME_CLEAR "MUSIC\\levelup_win02.mp3"

#define BGM_GAME_PLAY "MUSIC\\bgm11.mp3"

#define BGM_GAME_OP "MUSIC\\game_field11.mp3"

#define BGM_GAME_SOUSA "MUSIC\\sousa_harp.mp3"

#define SLIME_IMAGE "image\\Slime.png"
#define WOD_IMAGE "image\\Wod.png"
#define BEETLE_IMAGE "image\\Beetle.png"
#define LIZARD_IMAGE "image\\Lizard.png"
#define SCORPION_IMAGE "image\\Scorpion.png"
#define SPIDER_IMAGE "image\\Spider.png"
#define CAT_IMAGE "image\\Cat.png"
#define CHIKEN_IMAGE "image\\Chiken.png"
#define BONE_IMAGE "image\\Bone.png"
#define DRAGON_IMAGE "image\\Dragon.png"
#define KNIGHT_IMAGE "image\\Knght.png"
#define KERBEROS_IMAGE "image\\Kerberos.png"
#define BOSS_IMAGE "image\\Slime.png"

#define MAP_BUN_TATE_CNT    20
#define MAP_BUN_YOKO_CNT    8

#define MAP_YOKO  54
#define MAP_TATE  64

#define MAP_OneBlock_TATE_SIZE   32
#define MAP_OneBlock_YOKO_SIZE   32

#define CHARA_BUN_YOKO_CNT 3
#define CHARA_BUN_TATE_CNT 4

#define GAME_ENEMY_BUN_YOKO_CNT 12
#define GAME_ENEMY_BUN_TATE_CNT 8

#define CHARA_TATE_SIZE     32
#define CHARA_YOKO_SIZE     32

#define CHARA_MOTION_NUM    12

#define CHARA_KIND_YOKO    3
#define CHARA_KIND_TATE    4  

#define RANDOM_NUM  150

/* �}�b�v�ɂ��ړ��̐����� */
#define MAP_NOTDOWN_KIND    16
#define MAP_OKDOWN_KIND     16
#define MAP_NOTUP_KIND      16
#define MAP_NOTLEFT_KIND    16
#define MAP_NOTRIGHT_KIND   16
#define OFF_HIT 1
#define ON_HIT  1
#define GAME_MAP_GOAL_KIND      3  //�S�[���̎��

#define GAME_CHARA_SPEED      2//�L�����̃X�s�[�h

#define GRAVITY    9.8067 //�d�͉����x
#define CHARA_WEIGHT    60//�L�����̏d��

#define GAME_PLAYER_ZANKI_MAX  3

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//�^�C�g�����
	GAME_SCENE_SOUSA,
	GAME_SCENE_ENEMY_1,		//�o�g�����
	GAME_SCENE_ENEMY_2,		//�o�g�����
	GAME_SCENE_ENEMY_3,		//�o�g�����
	GAME_SCENE_ENEMY_4,		//�o�g�����
	GAME_SCENE_ENEMY_5,		//�o�g�����
	GAME_SCENE_ENEMY_6,		//�o�g�����
	GAME_SCENE_ENEMY_7,		//�o�g�����
	GAME_SCENE_ENEMY_8,		//�o�g�����
	GAME_SCENE_ENEMY_9,		//�o�g�����
	GAME_SCENE_ENEMY_10,	//�o�g�����
	GAME_SCENE_ENEMY_11,	//�o�g�����
	GAME_SCENE_ENEMY_12,	//�o�g�����
	GAME_SCENE_ENEMY_13,	//�o�g�����
	GAME_SCENE_PLAY,	//�v���C���
	GAME_SCENE_END		//�G���h���
};

enum MAP_IMAGE {
	M_N = -1,
	M_B = 19,
	M_G_T = 6,
	M_BLO = 67,
	M_ON = 125,
	M_OFF = 126,
	M_AM = 95,
	M_END = 399
};

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_END = 11
};

enum Block_No {
	first,
	second,
	third,
	fourth,
	not_use
};

enum GAME_END_KIND {
	END_KIND_CONTINUE,
	END_KIND_OVER,
	END_KIND_CLEAR
};

//############�\����##############
typedef struct STRUCT_GAZOU {
	int Handle;
	char FilePath[128];
	int X;
	int Y;
	int Width;
	int Height;
	int c_Width;
	int c_Height;
}GAZOU;

GAZOU BACKGROUND;
GAZOU BACK_TITLE;
GAZOU BACK_SOUSA;
GAZOU BACK_OVER;
GAZOU BACK_CLEAR;
GAZOU BACK_GAME_OVER;

typedef struct STRUCT_MAP
{
	char FilePath[128];
	int Handle[MAP_BUN_TATE_CNT*MAP_BUN_YOKO_CNT];
	int X[MAP_BUN_TATE_CNT*MAP_BUN_YOKO_CNT];
	int Y[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int Width[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int Height[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int C_Width[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int C_Height[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];

	BOOL charaStopFlag_x;
	BOOL charaStopFlag_y;

	BOOL GoalFlag;

	int EndKind;

	BOOL GoalEffect1;
}MAP;

typedef struct STRUCT_CHARACTOR
{
	char FilePath[128];
	int Handle[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int X[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int Y[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_YOKO_CNT];
	int Width[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int Height[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int C_Width[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int C_Height[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
}CHARA;

typedef struct STRUCT_PLAYER
{
	int Handle[CHARA_MOTION_NUM];
	int X;
	int Y;
	int Width;
	int Height;
	int C_Width;
	int C_Height;
	int NowHandleNum;
	int NowHandleCnt;
	int NowHandleCntMAX;

	int Speed;
	int MoveDist_x;
	int MoveDist_y;

	int Zanki;

	BOOL IsJumpNow;

	int JumpStartTime;
	int JumpNowTime;
	int JumpPrevY;
	int JumpValue;
	int Mass;
	int Weight;

	int JumpMaxTop;
	BOOL IsJumpTop;

	BOOL CanMoveLeft;
	BOOL CanMoveRight;

	BOOL CanMoveUp;
	BOOL CanMoveDown;

	int atariX;
	int atariY;
	int atariWidth;
	int atariHeight;

	RECT atariRect;

}PLAYER;

typedef struct STRUCT_MUSIC
{
	int Handle;
	char FilePath[128];
	int Playtype;
}MUSIC;

//########## �O���[�o���ϐ� ##########

//typedef STRUCT_GAZOU GAZOU;
//typedef STRUCT_CHARACTOR CHARA;
//typedef STRUCT_MAP MAP;
//typedef STRUCT_PLAYER PLAYER;

//�E�B���h�E�֌W
WNDPROC WndProc;						//�E�B���h�E�v���V�[�W���̃A�h���X
BOOL IsWM_CREATE = FALSE;				//WM_CREATE������ɓ��삵�������f����


//FPS�֘A
int StartTimeFps;						//����J�n����
int CountFps;							//�J�E���^
float CalcFps;							//�v�Z����
int SampleNumFps = FPS_SPEED;		//���ς����T���v����

//�L�[�{�[�h�֘A
char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����
int GameSceneNow = (int)GAME_SCENE_TITLE;

GAZOU BackImage[4];
int ScrollCntYoko;
int ScrollCntTate;

int ScrollDistPlusYoko = 1;

MAP MapImage;
int ScrollDistKeyPlusYoko = 2;

int G_Cnt = 0;

int charaCnt = 0;

int mapCnt = 0;

PLAYER p;

int blockCnt = 0;

int random;

MUSIC MUSIC_SE_JUMP;
MUSIC MUSIC_SE_GAME_OVER;
MUSIC MUSIC_BGM_PLAY;
MUSIC MUSIC_OP;
MUSIC MUSIC_SOUSA;
MUSIC MUSIC_SE_CLEAR;

int i = 0;
int tate = 0;
int yoko = 0;
int sum = 0;
int rCnt = 0;
int NotD_Cnt = 0;
int cnt = 0;
int mot = 0;

int num = 0;

int switch1 = 33;

int switch2 = 90;

long a, b;

int time_miri;
int time_miri_keisoku;

double Time = 0;
double Time1 = 0;
double Time2 = 0;

double Goal_Time = 0;

int message;

CHARA CharaImage;
PLAYER Myplayer;

int FONTHANDLE_TAMESHI = 0;

int on_x = 0;
int on_y = 0;

int blockX = 0;
int blockY = 0;

FILE *fp_map_csv;

int MapData[MAP_TATE][MAP_YOKO];//�}�b�v�̃f�[�^

int MapData_Init[MAP_TATE][MAP_YOKO];//�}�b�v�̃f�[�^�������p

int ZankiDrawCount = 0;
int ZankiDrawCountMax = 60;

int UntilZankiDrawCount = 0;
int UntilZankiDrawCountMax = 60;

BOOL tyakuti = FALSE;

int PlayerImageNum[CHARA_MOTION_NUM] = {
	0,  1,  2,
	3,  4,  5,
	6,  7,  8,
	9, 10, 11
};

int MapNotDownKind[MAP_NOTDOWN_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };
int MapNotUpKind[MAP_NOTUP_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };

int MapOKDownKind[MAP_OKDOWN_KIND] = { -1 };

int MapNotLeftKind[MAP_NOTLEFT_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };
int MapNotRightKind[MAP_NOTRIGHT_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };

int OffHit[OFF_HIT] = { 126 };
int OnHit[ON_HIT] = { 125 };

int MapGoalKind[GAME_MAP_GOAL_KIND] = { 204,224 };

RECT rectMap_DownNG[MAP_TATE][MAP_YOKO];
RECT rectMap_DownNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_DownOK[MAP_TATE][MAP_YOKO];
RECT rectMap_DownOK_First[MAP_TATE][MAP_YOKO];

RECT rectMap_LeftNG[MAP_TATE][MAP_YOKO];
RECT rectMap_LeftNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_RightNG[MAP_TATE][MAP_YOKO];
RECT rectMap_RightNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_UpNG[MAP_TATE][MAP_YOKO];
RECT rectMap_UpNG_First[MAP_TATE][MAP_YOKO];


//########## �v���g�^�C�v�錾 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//����E�B���h�E�v���V�[�W��

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�

VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����֐�
VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��֐�

VOID MY_GAME_TITLE(VOID);			//�^�C�g����ʂ̊֐�
VOID MY_GAME_SOUSA(VOID);           //���������ʂ̊֐�
VOID MY_GAME_PLAY(VOID);			//�v���C��ʂ̊֐�
VOID MY_GAME_END(VOID);				//�G���h��ʂ̊֐�

BOOL MY_GAZOU_LOAD(GAZOU *, int, int, const char *);

BOOL MY_PLAY_INIT(VOID);
VOID MY_PLAY_BACKIMAGE_DRAW(VOID);
VOID MY_PLAY_SCROLL(VOID);

BOOL MY_MAP_READ_CSV_NUM(FILE *, const char *);

BOOL MY_CHARA_LOAD_BUNKATSU(CHARA *, int, int, int, int, int, const char *);
BOOL MY_INIT_PLAYER(PLAYER *, CHARA, int *, int, int, int);

//VOID BLOCK_INDICATE(VOID);//	�u���b�N��\������֐�

VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂֐�
VOID MY_PLAY_PLAYER_DRAW(VOID);
VOID MY_PLAYER_OPERATION(VOID);

VOID MY_PLAY_MAP_DRAW(VOID);//�}�b�v��`�悷��֐�

VOID MY_PLAY_PLAYER_JUMP_PREV(VOID);//�W�����v�̑O�������s���֐�

BOOL MY_PLAY_CHECK_GAME_END(VOID);//�Q�[���G���h�����肷��֐�

VOID MY_DRAW_STRING_CENTER_CENTER(char[][128], int, char *, int);//��ʒ����ɕ�����`�悷��֐�
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL);//�������f�t�H���g�t�H���g�ɐݒ肷��֐�

VOID MY_BG_IMAGE_INIT(VOID);

/* �����蔻��̊֐� */
VOID MY_SET_PLAYER_ATARI(PLAYER *);
BOOL MY_CHECK_RECT_ATARI(RECT, RECT);
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP(RECT, RECT[MAP_TATE][MAP_YOKO]);
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[MAP_TATE][MAP_YOKO], int *, int *);

VOID MY_TITLE_BACKGROUND_DRAW(VOID);

VOID MY_OVER_BACKGROUND_DRAW(VOID);

VOID MY_CLEAR_BACKGROUND_DRAW(VOID);

VOID MY_SOUSA_BACKGROUND_DRAW(VOID);

VOID MY_GAME_OVER_BACKGROUND_DRAW(VOID);

BOOL BACKGROUND_LOAD(GAZOU *, int, int, const char *);

VOID MY_GAME_ZANKI(VOID);

VOID MY_FPS_DRAW(VOID);

BOOL MAP_INIT(MAP *, int, int, int, int, int, const char *);

VOID MY_TIMER(VOID);

BOOL MY_MUSIC_LOAD(MUSIC *, const char *);

VOID BATTLE_SLIME(VOID);
VOID BATTLE_WOD(VOID);
VOID BATTLE_BEETLE(VOID);
VOID BATTLE_SPIDER(VOID);
VOID BATTLE_LIZARD(VOID);
VOID BATTLE_SCOPION(VOID);
VOID BATTLE_CHIKEN(VOID);
VOID BATTLE_CAT(VOID);
VOID BATTLE_BONE(VOID);
VOID BATTLE_DRAGON(VOID);
VOID BATTLE_KERBEROS(VOID);
VOID BATTLE_KNIGHT(VOID);
VOID BATTLE_KNIGHT(VOID);
VOID BATTLE_BOSS(VOID);



//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������
	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);			//�^�C�g���o�[�Ȃ�
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) { return -1; }

	//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);

	MY_MUSIC_LOAD(&MUSIC_SE_JUMP, SE_JUMP);
	MY_MUSIC_LOAD(&MUSIC_SE_GAME_OVER, SE_GAME_OVER);
	MY_MUSIC_LOAD(&MUSIC_BGM_PLAY, BGM_GAME_PLAY);
	MY_MUSIC_LOAD(&MUSIC_OP, BGM_GAME_OP);
	MY_MUSIC_LOAD(&MUSIC_SOUSA, BGM_GAME_SOUSA);
	MY_MUSIC_LOAD(&MUSIC_SE_CLEAR, SE_GAME_CLEAR);

	/*if (!BACKGROUND_LOAD(&BACKGROUND, 0, 0, BACKIMAGE_1))
	{
		return -1;
	}
*/
	if (!BACKGROUND_LOAD(&BACK_TITLE, 0, 0, BACKGROUND_TITLE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_CLEAR, 0, 0, BACKIMAGE_CLEAR))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_SOUSA, 0, 0, BACKIMAGE_SOUSA))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_OVER, 0, 0, BACKIMAGE_OVER))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_GAME_OVER, 0, -100, MOJI_GAME_OVER))
	{
		return -1;
	}

	if (MAP_INIT(&MapImage, MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT, MAP_BUN_YOKO_CNT, MAP_BUN_TATE_CNT, 32, 32, MAP_1) == FALSE) { MessageBox(NULL, MAP_1, "NotFound", MB_OK); return -1; }

	if (MY_MAP_READ_CSV_NUM(fp_map_csv, MAP_CSV_1) == FALSE) { MessageBox(NULL, MAP_CSV_1, "NotFound", MB_OK); return -1; }

	if (MAP_INIT(&MapImage, 160, 8, 20, 32, 32, MAP_1) == FALSE) { return -1; }

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, CHARA_BUN_YOKO_CNT*CHARA_BUN_TATE_CNT, CHARA_BUN_YOKO_CNT, CHARA_BUN_TATE_CNT, CHARA_YOKO_SIZE, CHARA_TATE_SIZE, PLAYER_IMAGE) == FALSE) { MessageBox(NULL, PLAYER_IMAGE, "NotFound", MB_OK); return -1; }

	FONTHANDLE_TAMESHI = CreateFontToHandle(NULL, 40, 3);

	//�������[�v
	while (TRUE)
	{
		Time1 = GetNowCount();

		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		MY_ALL_KEYDOWN_UPDATE();				//�L�[�̏�Ԃ��擾

		//�V�[���I��
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

			MY_GAME_TITLE();	//�^�C�g����ʂ̏���

			break;	//�^�C�g����ʂ̏��������܂�


		case (int)GAME_SCENE_SOUSA:

			MY_GAME_SOUSA();

			break;

			//case (int)GAME_SCENE_ZANKI://�c�@�\����ʂ̏�����������

			//	MY_GAME_ZANKI();//�c�@�\����ʂ̏���

			//	break;

		case (int)GAME_SCENE_ENEMY_1:

			BATTLE_SLIME();

			break;

		case (int)GAME_SCENE_ENEMY_2:

			BATTLE_WOD();

			break;

		case (int)GAME_SCENE_ENEMY_3:

			BATTLE_BEETLE();

			break;

		case (int)GAME_SCENE_ENEMY_4:

			BATTLE_SPIDER();

			break;

		case (int)GAME_SCENE_ENEMY_5:

			BATTLE_LIZARD();

			break;


		case (int)GAME_SCENE_ENEMY_6:

			BATTLE_SCOPION();

			break;

		case (int)GAME_SCENE_ENEMY_7:

			BATTLE_CHIKEN();

			break;

		case (int)GAME_SCENE_ENEMY_8:

			BATTLE_CAT();

			break;

		case (int)GAME_SCENE_ENEMY_9:

			BATTLE_BONE();

			break;

		case (int)GAME_SCENE_ENEMY_10:

			BATTLE_DRAGON();

			break;

		case (int)GAME_SCENE_ENEMY_11:

			BATTLE_KERBEROS();

			break;

		case (int)GAME_SCENE_ENEMY_12:

			BATTLE_KNIGHT();

			break;

		case (int)GAME_SCENE_ENEMY_13:

			BATTLE_BOSS();

			break;
		case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

			MY_GAME_PLAY();		//�v���C��ʂ̏���

			break;	//�v���C��ʂ̏��������܂�

		case (int)GAME_SCENE_END:	//�G���h��ʂ̏�����������

			MY_GAME_END();		//�G���h��ʂ̏���

			break;	//�G���h��ʂ̏��������܂�

		default:

			break;
		}

		MY_FPS_UPDATE();						//FPS�̏���[�X�V]

		ScreenFlip();
		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
	}

	DeleteMusicMem(MUSIC_SE_JUMP.Handle);
	DeleteMusicMem(MUSIC_SE_GAME_OVER.Handle);
	DeleteMusicMem(MUSIC_BGM_PLAY.Handle);
	DeleteMusicMem(MUSIC_OP.Handle);
	DeleteMusicMem(MUSIC_SOUSA.Handle);
	DeleteMusicMem(MUSIC_SE_CLEAR.Handle);


	for (mapCnt = 0; mapCnt < MAP_YOKO*MAP_TATE; mapCnt++)
	{
		DeleteGraph(MapImage.Handle[mapCnt]);
	}

	for (charaCnt = 0; charaCnt < CHARA_BUN_YOKO_CNT*CHARA_BUN_TATE_CNT; charaCnt++)
	{
		DeleteGraph(CharaImage.Handle[charaCnt]);
	}

	DxLib_End();		//�c�w���C�u�����g�p�̏I������

	return 0;
}

//########## FPS�l���v���A�X�V����֐� ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS�l���v�����A�҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//������������
	int waitTime = CountFps * 1000 / FPS_SPEED - resultTime;	//�҂ׂ�����

	if (waitTime > 0)		//�w���FPS�l���������ꍇ
	{
		Sleep(waitTime);	//�҂�
	}
	return;
}

VOID MY_FPS_DRAW(VOID)
{
	DrawFormatString(0, GAME_HEIGHT - 30, GetColor(255, 255, 255), "FPS:%.1lf", CalcFps);

	return;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];

	GetHitKeyStateAll(TempKey);   //���ׂẴL�[���͏�Ԃ��擾����

	for (i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)
		{
			AllKeyState[i]++;    //������Ă���
		}
		else
		{
			AllKeyState[i] = 0;  //������Ă��Ȃ�
		}
	}
	return;
}

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{/*
	if (CheckSoundMem(MUSIC_OP.Handle) < 1 && CheckSoundMem(MUSIC_BGM_PLAY.Handle) == 0)
	{
		ChangeVolumeSoundMem(255, MUSIC_OP.Handle);
		PlaySoundMem(MUSIC_OP.Handle, DX_PLAYTYPE_LOOP);
	}*/

	if (CheckSoundMem(MUSIC_OP.Handle) == 0)
	{
		ChangeVolumeSoundMem(100, MUSIC_OP.Handle);
		PlaySoundMem(MUSIC_OP.Handle, DX_PLAYTYPE_LOOP);
	}
	MY_TITLE_BACKGROUND_DRAW();

	if (AllKeyState[KEY_INPUT_RETURN] != 0)
	{
		if (MY_PLAY_INIT() == TRUE)		//�v���C��ʏ�����
		{
			for (tate = 0; tate < MAP_TATE; tate++)
			{
				for (yoko = 0; yoko < MAP_YOKO; yoko++)
				{
					MapData[tate][yoko] = MapData_Init[tate][yoko];
				}
			}
		}
	}

	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		StopSoundMem(MUSIC_OP.Handle);
		GameSceneNow = (int)GAME_SCENE_SOUSA;	//�V�[���𑀍������ʂɂ���
	}

	//DrawString(310, 270, "�f�l�c", GetColor(255, 255, 255), SetFontSize(60));
	DrawString(140, 450, "�G���^�[�L�[�������Ă�������", GetColor(255, 255, 0), SetFontSize(30));

	return;
}

//##########����������##########
VOID MY_GAME_SOUSA(VOID)
{
	if (CheckSoundMem(MUSIC_SOUSA.Handle) == 0)
	{
		MUSIC_OP.Handle = 0;
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SOUSA.Handle);
		PlaySoundMem(MUSIC_SOUSA.Handle, DX_PLAYTYPE_BACK);
	}
	DrawBox(0, 0, 800, 640, GetColor(255, 255, 255), TRUE);
	MY_SOUSA_BACKGROUND_DRAW();
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{
		StopSoundMem(MUSIC_SOUSA.Handle);
		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		Time2 = Time1;

	}

	/*DrawString(60, 100, "�E�v���C���[�͍��E���L�[�ō��E�ړ�", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 130, "����L�[�ŃW�����v���܂��B", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(60, 170, "�E�r���ɂ���OFF�X�C�b�`�������ƃu���b�N��", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 200, "�o�Ă��āA�`�L�[�ō��ɁA�c�L�[�ŉE�ɂr�L�[��", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 230, "���Ɉړ����܂��B", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(60, 270, "���u���b�N�͕K���}�b�v�̂ǂ����u�����u���b�N��", GetColor(255, 0, 0), SetFontSize(30));
	DrawString(90, 300, "��ɐςݏグ�Ďg���܂��傤�I", GetColor(255, 0, 0), SetFontSize(30));
	DrawString(60, 340, "���u���b�N�͂S�܂ŏo�Ă��܂��B", GetColor(255, 0, 0), SetFontSize(30));*/

	DrawString(190, 600, "�X�y�[�X�L�[�������ƃX�^�[�g", GetColor(0, 0, 0), SetFontSize(30));
}

VOID BATTLE_SLIME(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}


VOID BATTLE_WOD(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_BEETLE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_SPIDER(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_LIZARD(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_SCOPION(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}


VOID BATTLE_CHIKEN(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_CAT(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_BONE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_DRAGON(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_KERBEROS(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_KNIGHT(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}



VOID BATTLE_BOSS(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}



//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	if (CheckSoundMem(MUSIC_BGM_PLAY.Handle) == 0)
	{
		MUSIC_OP.Handle = 0;
		ChangeVolumeSoundMem(255 * 80 / 200, MUSIC_BGM_PLAY.Handle);
		PlaySoundMem(MUSIC_BGM_PLAY.Handle, DX_PLAYTYPE_BACK);
	}
	Time = (GetNowCount() - Time1) / 1000;

	//DrawFormatStringToHandle(300, 64, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "%d", Myplayer.Y);
	/*DrawFormatString(300, 0, GetColor(255, 255, 255), "�N���A�^�C��%d�b", Time);*/

	/*time_miri_keisoku++;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�N���A�^�C��%d�b", Time);*/

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)
	//{
	//	//G ameSceneNow = (int)GAME_SCENE_END;
	//}
	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0)
		{

			if (Myplayer.CanMoveLeft == TRUE)//�v���C���[�����ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_x == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntYoko > 0)//�}�C�i�X�̃X�N���[�������Ȃ�
					{
						ScrollCntYoko -= Myplayer.Speed;//��ʂ����ɃX�N���[��
					}
				}
			}
		}
	}
	if (AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_RIGHT] != 0)
		{
			if (Myplayer.CanMoveRight == TRUE)//�v���C���[���E�ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_x == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntYoko < MAP_OneBlock_YOKO_SIZE * MAP_YOKO)//��ʊO�փX�N���[�������Ȃ�
					{
						ScrollCntYoko += Myplayer.Speed;//��ʂ��E�ɃX�N���[��
					}
				}
			}
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_UP] != 0)
		{
			if (Myplayer.CanMoveUp == TRUE)//�v���C���[����ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_y == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntTate > 0)//�}�C�i�X�̃X�N���[�������Ȃ�
					{
						ScrollCntTate -= Myplayer.Speed;//��ʂ����ɃX�N���[��
					}
				}
			}
		}
	}
	//if (AllKeyState[KEY_INPUT_UP] != 0)
	//{
	//		if (MapImage.charaStopFlag_y == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
	//		{
	//			if (Myplayer.Y == 0 || Myplayer.Y <= MAP_OneBlock_TATE_SIZE*10)
	//			{
	//					Myplayer.Y += Myplayer.Speed;
	//					ScrollCntTate -= Myplayer.Speed * 2;//��ʂ����ɃX�N���[��
	//			}
	//		}	
	//}
	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_DOWN] != 0)
		{
			if (Myplayer.CanMoveDown == TRUE)//�v���C���[�����ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_y == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntTate < MAP_OneBlock_TATE_SIZE * MAP_TATE)//��ʊO�փX�N���[�������Ȃ�
					{
						ScrollCntTate += Myplayer.Speed;//��ʂ���ɃX�N���[��
					}
				}
			}
		}
	}

	/*if (MY_PLAY_CHECK_GAME_END() == TRUE)
	{*/
	/*getch();*/
	//StopSoundMem(MUSIC_BGM_PLAY.Handle);
	//GameSceneNow = (int)GAME_SCENE_END;
/*}
else
{*/
	MY_PLAYER_OPERATION();	//�v���C���[�̑���
//}

	if (random == 1)
	{
		GameSceneNow = (int)GAME_SCENE_ENEMY_1;
	}

	//MY_PLAYER_OPERATION();

	MY_PLAY_BACKIMAGE_DRAW();//�w�i��`��

	MY_PLAY_MAP_DRAW();  //�}�b�v��`��

	//DrawFormatStringToHandle(300, 64, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "%d", Myplayer.Y);

	//DrawBox(Myplayer.atariRect.left, Myplayer.atariRect.top, Myplayer.atariRect.right, Myplayer.atariRect.bottom, GetColor(255, 0, 0), TRUE);

	DrawFormatStringToHandle(260, 0, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "�o�ߎ���%0.2lf�b", (Time1 - Time2) / 1000);

	MY_PLAY_PLAYER_DRAW();

	//DrawString(0, 0, "�G���^�[�L�[�������ƈړ�", GetColor(255, 255, 255));
	//DrawFormatString(20, 20, GetColor(255, 255, 255), "%d", playerX);

	return;
}

//###########��ʒ����ɕ�����`�悷��֐�############
VOID MY_DRAW_STRING_CENTER_CENTER(char str[][128], int row, char *fontname, int size)
{
	ChangeFont(fontname, DX_CHARSET_DEFAULT);//�f�t�H���g�̃t�H���g��ύX����
	SetFontSize(size);                       //�f�t�H���g�̃t�H���g�T�C�Y��ς���
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g�����ꂢ�ɂ݂���

	int StrHeightSum = 0;
	for (sum = 0; sum < row; sum++)//�s�S�̂̍������W�v
	{
		StrHeightSum += GetFontSize();//�f�t�H���g�̃t�H���g�̍������擾
	}

	for (rCnt = 0; rCnt < row; rCnt++)//�t�H���g��`��
	{
		int StrWidth = GetDrawFormatStringWidth(&str[rCnt][0]);//�f�t�H���g�̃t�H���g�̉������擾
		int StrHeight = GetFontSize();

		DrawFormatString(
			GAME_WIDTH / 2 - StrWidth / 2,
			GAME_HEIGHT / 2 - StrHeightSum + StrHeight * rCnt,//��ʂ̒��S�@-�@�s�S�̂̕����̍����@+�@�P�s�̍���
			GetColor(255, 255, 255), &str[rCnt][0]);//�f�t�H���g�̃t�H���g�ŕ`��
	}

	MY_DRAW_SET_DEFAULT_FONT(TRUE);//�f�t�H���g�t�H���g�ɐݒ肷��
}

//########## �Q�[���G���h�����肷��֐� ##########
BOOL MY_PLAY_CHECK_GAME_END(VOID)
{
	//�v���C���[�̈ʒu�́A�v���C���[�̒��S
	int PlayerToMapNumY = (Myplayer.MoveDist_y + Myplayer.C_Height) / MAP_OneBlock_TATE_SIZE;
	int PlayerToMapNumX = (Myplayer.MoveDist_x + Myplayer.C_Width) / MAP_OneBlock_TATE_SIZE;


	//�v���C���[��ʊO�ɗ������Ƃ�
	if (Myplayer.Y > GAME_HEIGHT)
	{
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SE_GAME_OVER.Handle);
		PlaySoundMem(MUSIC_SE_GAME_OVER.Handle, DX_PLAYTYPE_BACK);
		//MapImage.EndKind = (int)END_KIND_CONTINUE;


		MapImage.EndKind = (int)END_KIND_OVER;

		//MapImage.GameEndKind = (int)END_KIND_OVER;
		return TRUE;
	}

	if (PlayerToMapNumX<0 || PlayerToMapNumX>MAP_YOKO) { return FALSE; }
	if (PlayerToMapNumY<0 || PlayerToMapNumY>MAP_TATE) { return FALSE; }

	for (G_Cnt = 0; G_Cnt < GAME_MAP_GOAL_KIND; G_Cnt++)
	{
		//�v���C���[���S�[���̂��̂ƐڐG�����Ƃ�
		if (MapData[PlayerToMapNumY][PlayerToMapNumX] == MapGoalKind[G_Cnt])
		{

			Goal_Time = (Time1 - Time2) / 1000;
			/*if (Myplayer.GetRedCoinNum == 5)
			{*/
			ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SE_CLEAR.Handle);
			PlaySoundMem(MUSIC_SE_CLEAR.Handle, DX_PLAYTYPE_BACK);
			MapImage.EndKind = (int)END_KIND_CLEAR;
			return TRUE;
			break;
			//}
		}
	}
	return FALSE;//�Q�[�����s
}

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
	}

	MapData[16][17] = (int)M_N;

	MapData[17][53] = (int)M_N;

	MapData[16][108] = (int)M_N;
	MapData[14][109] = (int)M_N;
	MapData[12][110] = (int)M_N;
	MapData[10][111] = (int)M_N;
	/*for (int o = first; o <= fourth; o++)

		if (PlayerToMapNumY - 1 == 17 && PlayerToMapNumX == 53)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 16 && PlayerToMapNumX == 108)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 14 && PlayerToMapNumX == 109)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 12 && PlayerToMapNumX == 110)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 10 && PlayerToMapNumX == 111)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	{*/

	if (MapImage.EndKind == (int)END_KIND_OVER)	//�Q�[���I�[�o�[�̂Ƃ�
	{
		MY_OVER_BACKGROUND_DRAW();
		char StrGameOver[2][128] = { "���߂�̂͂܂�����","" };
		char StrFontOver[128] = { "MS �S�V�b�N" };

		MY_DRAW_STRING_CENTER_CENTER(&StrGameOver[0], 2, StrFontOver, 40);

		MY_GAME_OVER_BACKGROUND_DRAW();
	}

	else if (MapImage.EndKind == (int)END_KIND_CLEAR)	//�Q�[���N���A�̂Ƃ�
	{
		MY_CLEAR_BACKGROUND_DRAW();

		DrawFormatStringToHandle(180, 0, GetColor(255, 255, 0), FONTHANDLE_TAMESHI, "���Ȃ��̋L�^��%0.2lf�b�ł�", Goal_Time);
		char StrGameClear[2][128] = { "GAME CLEAR","�ȒP���������ȁH" };
		DrawString(180, 400, "���ȃx�X�g�X�V��ڎw�����I�I", GetColor(0, 255, 0), SetFontSize(30));
		/*char StrGameClear_koushin[128] = { "���ȃx�X�g�X�V��ڎw�����I�I" };*/
		char StrFontClear[128] = { "MS �S�V�b�N" };

		MY_DRAW_STRING_CENTER_CENTER(&StrGameClear[0], 2, StrFontClear, 40);
		/*MY_DRAW_STRING_CENTER_CENTER(&StrGameClear_koushin[0], 2, StrFontClear, 80);*/

	}
	else if (MapImage.EndKind == (int)END_KIND_CONTINUE)	//�Q�[�����s�̂Ƃ�
	{
		if (UntilZankiDrawCount < UntilZankiDrawCountMax)
		{
			UntilZankiDrawCount++;
			//�����ɂ��鐔�l(0�����߂Ȃ��A255�����߂���)
			double ToukaPercent = UntilZankiDrawCount / (double)UntilZankiDrawCountMax;//���߁������߂�

			DrawBox(0, 0, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);//�^���Âȉ�ʂɂ���

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			if (MY_PLAY_INIT() == TRUE)	//�v���C���[�̈ʒu�Ȃǂ̏���������
			{

			}
		}
	}

	DrawString(45, 490, "�^�C�g���ɖ߂�ɂ̓o�b�N�X�y�[�X�L�[�������Ă�������", GetColor(255, 0, 0), SetFontSize(25));

	DrawString(130, 520, "�I���������ꍇ�͉E�N���b�N�����Ă�������", GetColor(255, 0, 0), SetFontSize(25));

	return;
}

//�������f�t�H���g�t�H���g�ɐݒ肷��֐�
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL anti)
{
	ChangeFont("MS �S�V�b�N", DX_CHARSET_DEFAULT);
	SetFontSize(16);

	if (anti)
	{
		ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	}
	return;
}

//########## �E�B���h�E�v���V�[�W���֐� ##########
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int closeMsgRet = 0;

	switch (msg)
	{
	case WM_CREATE:	//�E�B���h�E�̐�����������


		IsWM_CREATE = TRUE;	//WM_CREATE����I��
		return 0;

	case WM_CLOSE:		//����{�^�����������Ƃ�

		message = MessageBox(hwnd, TEXT("�Q�[�����I�����܂�"), TEXT("�I�����b�Z�[�W"), MB_OK/*YESNO*/);

		/*	if (message == IDYES)
			{
				return 0;
			}
			else
			{
				DefWindowProc(hwnd, msg, wp, lp);
			}*/

		break;

	case WM_RBUTTONDOWN:	//�}�E�X�̉E�{�^�����������Ƃ�

		closeMsgRet = MessageBox(hwnd, TEXT("�Q�[�����I�����܂���"), TEXT("�I�����b�Z�[�W"), MB_YESNO);

		if (closeMsgRet == IDYES)
		{
			SendMessage(hwnd, WM_CLOSE, 0, 0);		//WM_CLOSE���b�Z�[�W���L���[�ɒǉ�
		}
		else if (closeMsgRet == IDNO)
		{
			//break;
		}

		break;

	case WM_LBUTTONDOWN:	//�}�E�X�̍��{�^�����������Ƃ�

		//WM_NCLBUTTONDOWN(�^�C�g���o�[�Ń}�E�X�̍��{�^����������)���b�Z�[�W�������ɔ��s
		//PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);
		break;

	case WM_DESTROY:	//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		PostQuitMessage(0);		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�

		return 0;
	}
	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}

//�������̊֐�
BOOL MY_PLAY_INIT(VOID)
{
	if (MY_INIT_PLAYER(&Myplayer, CharaImage, &PlayerImageNum[0], MAP_OneBlock_YOKO_SIZE * 0, MAP_OneBlock_TATE_SIZE * 0, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	MapImage.GoalFlag = FALSE;//�S�[����Ԃ�������

	MapImage.EndKind = (int)END_KIND_CONTINUE;

	MapImage.GoalEffect1 = FALSE;

	//�v���C���[�̏�����

	MY_DRAW_SET_DEFAULT_FONT(TRUE);	//�f�t�H���g�t�H���g�ɐݒ肷��

	MY_BG_IMAGE_INIT();//�w�i�̈ʒu��������

	ScrollCntYoko = 0;    //�X�N���[���ʂ�������
	ScrollCntTate = 1408;    //�X�N���[���ʂ�������

	ZankiDrawCount = 0;//�c�@�\���J�E���^������
	UntilZankiDrawCount = 0;//�c�@�\���܂ł̃J�E���^������

	return TRUE;
}

VOID MY_BG_IMAGE_INIT(VOID)
{
	//�w�i�̈ʒu
	BackImage[0].X = 0;

	return;
}

//�v���C��ʂ̔w�i��`�悷��֐�
VOID MY_PLAY_BACKIMAGE_DRAW(VOID)
{
	DrawGraph(BACKGROUND.X, BACKGROUND.Y, BACKGROUND.Handle, TRUE);
}
//�^�C�g����ʂ̔w�i��`�悷��֐�
VOID MY_TITLE_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_TITLE.X, BACK_TITLE.Y, BACK_TITLE.Handle, TRUE);
}
//�Q�[���I�[�o�[��ʂ̔w�i��`�悷��֐�
VOID MY_OVER_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_OVER.X, BACK_OVER.Y, BACK_OVER.Handle, TRUE);
}
//�N���A��ʂ̔w�i��`�悷��֐�
VOID MY_CLEAR_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_CLEAR.X, BACK_CLEAR.Y, BACK_CLEAR.Handle, TRUE);
}
//���������ʂ̔w�i��`�悷��֐�
VOID MY_SOUSA_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_SOUSA.X, BACK_SOUSA.Y, BACK_SOUSA.Handle, TRUE);
}

VOID MY_GAME_OVER_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_GAME_OVER.X, BACK_GAME_OVER.Y, BACK_GAME_OVER.Handle, TRUE);
}

//�摜��ǂݍ��ސݒ������֐�
BOOL MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);
	g->Handle = LoadGraph(g->FilePath);

	if (g->Handle == -1) { return FALSE; }

	GetGraphSize(g->Handle, &g->Width, &g->Height);
	g->X = x;
	g->Y = y;
	g->c_Width = g->Width / 2;
	g->c_Height = g->Height / 2;

	return TRUE;
}

//�}�b�v�𕪊����ēǂݍ��ސݒ������֐�
BOOL MAP_INIT(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);

	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1)
	{
		return FALSE;
	}

	for (int count = 0; count < MAP_TATE*MAP_YOKO; count++)
	{
		GetGraphSize(
			m->Handle[cnt],
			&m->Width[cnt],
			&m->Height[cnt]
		);
		m->C_Width[cnt] = m->Width[cnt] / 2;
		m->C_Height[cnt] = m->Height[cnt] / 2;
	}

	m->charaStopFlag_x = FALSE;
	m->charaStopFlag_y = FALSE;

	return TRUE;
}

//##########�L�����𕪊����ēǂݍ��ފ֐�############
BOOL MY_CHARA_LOAD_BUNKATSU(CHARA *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(c->FilePath, path);

	ret = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);

	if (ret == -1) { return FALSE; }

	for (cnt = 0; cnt < MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT; cnt++)
	{
		GetGraphSize(
			c->Handle[cnt],
			&c->Width[cnt],
			&c->Height[cnt]
		);

		c->C_Width[cnt] = c->Width[cnt] / 2;
		c->C_Height[cnt] = c->Height[cnt] / 2;
	}
	return TRUE;
}

//�w�i��ǂݍ��ފ֐�
BOOL BACKGROUND_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);
	g->Handle = LoadGraph(g->FilePath);
	if (g->Handle == -1)
	{
		return FALSE;
	}
	GetGraphSize(g->Handle, &g->Width, &g->Height);
	g->X = x;
	g->Y = y;

	return TRUE;
}

//�v���C���[������������֐�
BOOL MY_INIT_PLAYER(PLAYER *p, CHARA c, int *num, int x, int y, int speed)
{
	for (mot = 0; mot < CHARA_MOTION_NUM; mot++)
	{
		p->Handle[mot] = c.Handle[*(num + mot)];
	}

	p->X = 320;
	p->Y = 320;
	p->Width = c.Width[*(num + 0)];
	p->Height = c.Height[*(num + 0)];
	p->C_Width = c.C_Width[*(num + 0)];
	p->C_Height = c.C_Height[*(num + 0)];

	p->Width = MAP_OneBlock_YOKO_SIZE;
	p->Height = MAP_OneBlock_TATE_SIZE;
	p->C_Width = MAP_OneBlock_YOKO_SIZE / 2;
	p->C_Height = MAP_OneBlock_TATE_SIZE / 2;

	p->NowHandleNum = 6;
	p->NowHandleCnt = 0;
	p->NowHandleCntMAX = 4;

	p->Speed = speed;

	p->MoveDist_x = 320;
	p->MoveDist_y = 320;

	p->IsJumpNow = FALSE;
	p->JumpStartTime = 0;
	p->JumpNowTime = 0;
	p->JumpPrevY = 0;
	p->JumpValue = 0;
	p->Mass = CHARA_WEIGHT;
	p->Weight = p->Mass*GRAVITY;

	p->CanMoveLeft = TRUE;
	p->CanMoveRight = TRUE;
	p->CanMoveUp = TRUE;
	p->CanMoveDown = TRUE;

	p->atariX = 4;
	p->atariY = 0;
	p->atariWidth = 25;
	p->atariHeight = 32;

	//MY_SET_PLAYER_ATARI(p);

	return TRUE;
}

//�v���C���[�𑀍삷��֐�
VOID MY_PLAYER_OPERATION(VOID)
{
	BOOL IsKeyDown = FALSE;

	BOOL CanMoveLeft = TRUE;//���ɍs���邩
	BOOL CanMoveRight = TRUE;//�E�ɍs���邩
	BOOL CanMoveUp = TRUE;//�E�ɍs���邩
	BOOL CanMoveDown = TRUE;//���ɍs���邩

	//�v���C���[�̈ʒu���}�b�v�z��̂ǂ��ɂ��邩�ϊ�
	int PlayerToMapNumY;
	//�v���C���[�́y�ړ������ʒu�z���}�b�v�z��̂ǂ��ɂ��邩�ϊ�	���v���C���[�̈ʒu�́A�X�N���[�����A�ς��Ȃ�����
	//�L�����̈ʒu���A�P�}�b�v�̔����̈ʒu�ɂ���
	int PlayerToMapNumX;

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0)
		{
			IsKeyDown = TRUE;
			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum < 5)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 3;
				}
			}
			//�������ɁA�܂�������
			Myplayer.CanMoveLeft = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.left -= 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_LeftNG) == TRUE)
			{
				Myplayer.CanMoveLeft = FALSE;
			}

			if (Myplayer.CanMoveLeft == TRUE)//���Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_x == FALSE)
				{
					if (Myplayer.X > 0)
					{
						Myplayer.X -= Myplayer.Speed;//�v���C���[�����Ɉړ�

					}
				}

				if (Myplayer.MoveDist_x > 0)
				{
					Myplayer.MoveDist_x -= Myplayer.Speed;//�������������v�Z
				}
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_RIGHT] != 0)
		{

			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 6;
				}
			}
			Myplayer.CanMoveRight = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.right += 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_RightNG) == TRUE)
			{
				Myplayer.CanMoveRight = FALSE;
			}

			if (Myplayer.CanMoveRight == TRUE)//�E�Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_x == FALSE)
				{
					if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
					{
						Myplayer.X += Myplayer.Speed;//�v���C���[���E�Ɉړ�

					}
				}
				if (Myplayer.MoveDist_x < MAP_OneBlock_YOKO_SIZE * MAP_YOKO)
				{
					Myplayer.MoveDist_x += Myplayer.Speed;//�������������v�Z
				}
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_UP] != 0)
		{

			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 9 && Myplayer.NowHandleNum < 11)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 9;
				}
			}
			Myplayer.CanMoveUp = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.top -= 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_UpNG) == TRUE)
			{
				Myplayer.CanMoveUp = FALSE;
			}

			if (Myplayer.CanMoveUp == TRUE)//��Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_y == FALSE)
				{
					if (Myplayer.Y + Myplayer.Width < GAME_WIDTH)
					{
						Myplayer.Y -= Myplayer.Speed;//�v���C���[����Ɉړ�


					}
				}
				Myplayer.MoveDist_y += Myplayer.Speed;//�������������v�Z	
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_DOWN] != 0)
		{
			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 0;
				}
			}
			Myplayer.CanMoveDown = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.bottom += 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_DownNG) == TRUE)
			{
				Myplayer.CanMoveDown = FALSE;
			}

			if (Myplayer.CanMoveDown == TRUE)//���Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_y == FALSE)
				{
					if (Myplayer.Y + Myplayer.Height < GAME_HEIGHT)
					{
						Myplayer.Y += Myplayer.Speed;//�v���C���[�����Ɉړ�
					}
				}
				Myplayer.MoveDist_y -= Myplayer.Speed;//�������������v�Z	
			}
			random = rand() % RANDOM_NUM;
		}
	}
	//�}�b�v�̍����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_x > 0 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * 10)
	{
		MapImage.charaStopFlag_x = FALSE;
	}

	//�}�b�v�̏㑤�ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_y > 0 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_YOKO_SIZE * 10)
	{
		MapImage.charaStopFlag_y = FALSE;
	}

	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDist_x > MAP_OneBlock_YOKO_SIZE * 10 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * 53)
	{
		MapImage.charaStopFlag_x = TRUE;

	}
	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDist_y > MAP_OneBlock_TATE_SIZE * 10 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_TATE_SIZE * 63)
	{
		MapImage.charaStopFlag_y = TRUE;
	}

	//�}�b�v�̉����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_y > MAP_OneBlock_TATE_SIZE * 63 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_TATE_SIZE * MAP_TATE)
	{
		MapImage.charaStopFlag_y = FALSE;
	}

	//�}�b�v�̉E���ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_x > MAP_OneBlock_YOKO_SIZE * 53 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * MAP_YOKO)
	{
		MapImage.charaStopFlag_x = FALSE;
	}

	//�L�[��������Ă��Ȃ��Ƃ�
	if (IsKeyDown == FALSE)
	{
		if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum <= 8)
		{
			Myplayer.NowHandleNum = 6;
		}
		else if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum <= 5)
		{
			Myplayer.NowHandleNum = 3;
		}
		Myplayer.NowHandleCnt = Myplayer.NowHandleCntMAX - 1;	//�����摜��ς�����悤�ɂ���
	}

	//�}�b�v�̓����蔻����X�N���[��������
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			rectMap_DownNG[tate][yoko].left = rectMap_DownNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_DownNG[tate][yoko].right = rectMap_DownNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_DownOK[tate][yoko].left = rectMap_DownOK_First[tate][yoko].left - ScrollCntYoko;
			rectMap_DownOK[tate][yoko].right = rectMap_DownOK_First[tate][yoko].right - ScrollCntYoko;

			rectMap_LeftNG[tate][yoko].left = rectMap_LeftNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_LeftNG[tate][yoko].right = rectMap_LeftNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_RightNG[tate][yoko].left = rectMap_RightNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_RightNG[tate][yoko].right = rectMap_RightNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_UpNG[tate][yoko].left = rectMap_UpNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_UpNG[tate][yoko].right = rectMap_UpNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_DownNG[tate][yoko].top = rectMap_DownNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_DownNG[tate][yoko].bottom = rectMap_DownNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_DownOK[tate][yoko].top = rectMap_DownOK_First[tate][yoko].top - ScrollCntTate;
			rectMap_DownOK[tate][yoko].bottom = rectMap_DownOK_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_LeftNG[tate][yoko].top = rectMap_LeftNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_LeftNG[tate][yoko].bottom = rectMap_LeftNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_RightNG[tate][yoko].top = rectMap_RightNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_RightNG[tate][yoko].bottom = rectMap_RightNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_UpNG[tate][yoko].top = rectMap_UpNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_UpNG[tate][yoko].bottom = rectMap_UpNG_First[tate][yoko].bottom - ScrollCntTate;

		}
	}
	return;
	//}
}

//�W�����v�̑O�������s���֐�
VOID MY_PLAY_PLAYER_JUMP_PREV(VOID)
{
	Myplayer.IsJumpNow = TRUE;
	Myplayer.IsJumpTop = FALSE;

	Myplayer.JumpValue = CHARA_TATE_SIZE * 2;
	Myplayer.JumpMaxTop = Myplayer.Y - Myplayer.JumpValue;

	Myplayer.JumpPrevY = Myplayer.Y;
	Myplayer.JumpStartTime = GetNowCount();

	return;
}

//�v���C���[��\������֐�
VOID MY_PLAY_PLAYER_DRAW(VOID)
{
	DrawExtendGraph(
		Myplayer.X,
		Myplayer.Y,
		Myplayer.X + Myplayer.Width,
		Myplayer.Y + Myplayer.Height,
		Myplayer.Handle[Myplayer.NowHandleNum], TRUE);

	return;
}

//�}�b�v��\������֐�
VOID MY_PLAY_MAP_DRAW(VOID)
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			if ((yoko + 1)* MAP_OneBlock_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0)* MAP_OneBlock_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH)
			{
				DrawGraph(
					yoko * MAP_OneBlock_YOKO_SIZE - ScrollCntYoko,
					tate * MAP_OneBlock_TATE_SIZE - ScrollCntTate,
					MapImage.Handle[MapData[tate][yoko]], TRUE);
			}
		}
	}
}

//�Q�[����ʂ̃X�N���[�����s���֐�
VOID MY_PLAY_SCROLL(VOID)
{
	ScrollCntYoko += ScrollDistPlusYoko;
	ScrollCntTate += ScrollDistPlusYoko;
	DrawFormatString(0, 20, GetColor(255, 255, 255), "�X�N���[��������(��):%06d", ScrollCntYoko);

	return;
}

//�Q�[���}�b�v��CSV��ǂݍ��ފ֐�
BOOL MY_MAP_READ_CSV_NUM(FILE *fp, const char *path)
{
	if ((fp = fopen(path, "r")) == NULL)
	{
		return FALSE;
	}

	int result = 0;
	int LoopCnt = 0;
	while (result != EOF)
	{
		result = fscanf(fp, "%d,", &MapData[LoopCnt / MAP_YOKO][LoopCnt%MAP_YOKO]);

		MapData_Init[LoopCnt / MAP_YOKO][LoopCnt%MAP_YOKO] = MapData[LoopCnt / MAP_YOKO][LoopCnt%MAP_YOKO];//�l���R�s�[

		LoopCnt++;
	}

	fclose(fp);

	int cnt;

	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < MAP_NOTDOWN_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotDownKind[cnt])
				{
					rectMap_DownNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_DownNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_DownNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_DownNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_DownNG_First[tate][yoko] = rectMap_DownNG[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_OKDOWN_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapOKDownKind[cnt])
				{
					rectMap_DownOK[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_DownOK[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_DownOK[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_DownOK[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_DownOK_First[tate][yoko] = rectMap_DownOK[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_NOTLEFT_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotLeftKind[cnt])
				{
					rectMap_LeftNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_LeftNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_LeftNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_LeftNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_LeftNG_First[tate][yoko] = rectMap_LeftNG[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_NOTRIGHT_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotRightKind[cnt])
				{
					rectMap_RightNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_RightNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_RightNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_RightNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_RightNG_First[tate][yoko] = rectMap_RightNG[tate][yoko];
				}
			}
			for (cnt = 0; cnt < MAP_NOTUP_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotUpKind[cnt])
				{
					rectMap_RightNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_RightNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_RightNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_RightNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_RightNG_First[tate][yoko] = rectMap_RightNG[tate][yoko];
				}
			}
			for (cnt = 0; cnt < MAP_NOTUP_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotUpKind[cnt])
				{
					rectMap_UpNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_UpNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_UpNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_UpNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_UpNG_First[tate][yoko] = rectMap_UpNG[tate][yoko];
				}
			}
		}
	}
	return TRUE;
}
//�v���C���[�̓����蔻��̗̈��ݒ肷��֐�
VOID MY_SET_PLAYER_ATARI(PLAYER *p)
{
	p->atariRect.left = p->X + p->atariX + 1;
	p->atariRect.top = p->Y + p->atariY + 1;
	p->atariRect.right = p->X + p->atariX + p->atariWidth - 1;
	p->atariRect.bottom = p->Y + p->atariY + p->atariHeight - 1;

	return;
}

//##########���@�̂����蔻�������֐�##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top)
	{
		return TRUE;
	}

	return FALSE;
}

//�v���C���[�ƃ}�b�v�̓����蔻�������֐�
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP(RECT chara, RECT map[MAP_TATE][MAP_YOKO])
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

/*  */
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[MAP_TATE][MAP_YOKO], int *atariX, int *atariY)
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko)
		{
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;
				*atariX = yoko;

				return TRUE;
			}
		}
	}
	return FALSE;
}

//########## ����ǂݍ��ސݒ������֐� ##########
//���@���F���\���́@	:�ݒ肷�鉹�\���̂̕ϐ�
//���@���Fconst char *	:�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL			:TRUE:���� / FALSE:�ُ�
BOOL MY_MUSIC_LOAD(MUSIC *m, const char *path)
{
	//����ǂݍ���
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1)
	{
		return FALSE;
	}

	return TRUE;
} GAME_WINDOW_NAME	"Cliate Adventure"		//�E�B���h�E�̃^�C�g��
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE�F�E�B���h�E���[�h / FALSE�F�t���X�N���[��

#define SET_WINDOW_ST_MODE_DEFAULT			0	//�f�t�H���g
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//�^�C�g���o�[�Ȃ�
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//�^�C�g���o�[�ƃt���[���Ȃ�
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//�t���[���Ȃ�

#define FPS_SPEED    60

#define BACKIMAGE_1 "BACKIMAGE\\haikei1.png"

#define BACKIMAGE_SOUSA "BACKIMAGE\\haikei_setumei.png"

#define BACKIMAGE_OVER "BACKIMAGE\\haikei_over_kakou.png"

#define BACKIMAGE_CLEAR "BACKIMAGE\\haikei_clear_kakou.png"

#define BACKGROUND_TITLE "BACKIMAGE\\logo_3.png"

#define MOJI_GAME_OVER "BACKIMAGE\\GAME_OVER.png"

#define MAP_1   "MAPIMAGE\\map.png"

#define MAP_CSV_1    "MAPIMAGE\\map_54_64.csv"

#define PLAYER_IMAGE "CHARA\\syuzinkou.png"

#define SE_JUMP "MUSIC\\jump.mp3"

#define SE_GAME_OVER "MUSIC\\oti.mp3"

#define SE_GAME_CLEAR "MUSIC\\levelup_win02.mp3"

#define BGM_GAME_PLAY "MUSIC\\bgm11.mp3"

#define BGM_GAME_OP "MUSIC\\game_field11.mp3"

#define BGM_GAME_SOUSA "MUSIC\\sousa_harp.mp3"

#define SLIME_IMAGE "image\\Slime.png"
#define WOD_IMAGE "image\\Wod.png"
#define BEETLE_IMAGE "image\\Beetle.png"
#define LIZARD_IMAGE "image\\Lizard.png"
#define SCORPION_IMAGE "image\\Scorpion.png"
#define SPIDER_IMAGE "image\\Spider.png"
#define CAT_IMAGE "image\\Cat.png"
#define CHIKEN_IMAGE "image\\Chiken.png"
#define BONE_IMAGE "image\\Bone.png"
#define DRAGON_IMAGE "image\\Dragon.png"
#define KNIGHT_IMAGE "image\\Knght.png"
#define KERBEROS_IMAGE "image\\Kerberos.png"
#define BOSS_IMAGE "image\\Slime.png"

#define MAP_BUN_TATE_CNT    20
#define MAP_BUN_YOKO_CNT    8

#define MAP_YOKO  54
#define MAP_TATE  64

#define MAP_OneBlock_TATE_SIZE   32
#define MAP_OneBlock_YOKO_SIZE   32

#define CHARA_BUN_YOKO_CNT 3
#define CHARA_BUN_TATE_CNT 4

#define GAME_ENEMY_BUN_YOKO_CNT 12
#define GAME_ENEMY_BUN_TATE_CNT 8

#define CHARA_TATE_SIZE     32
#define CHARA_YOKO_SIZE     32

#define CHARA_MOTION_NUM    12

#define CHARA_KIND_YOKO    3
#define CHARA_KIND_TATE    4  

#define RANDOM_NUM  150

/* �}�b�v�ɂ��ړ��̐����� */
#define MAP_NOTDOWN_KIND    16
#define MAP_OKDOWN_KIND     16
#define MAP_NOTUP_KIND      16
#define MAP_NOTLEFT_KIND    16
#define MAP_NOTRIGHT_KIND   16
#define OFF_HIT 1
#define ON_HIT  1
#define GAME_MAP_GOAL_KIND      3  //�S�[���̎��

#define GAME_CHARA_SPEED      2//�L�����̃X�s�[�h

#define GRAVITY    9.8067 //�d�͉����x
#define CHARA_WEIGHT    60//�L�����̏d��

#define GAME_PLAYER_ZANKI_MAX  3

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,	//�^�C�g�����
	GAME_SCENE_SOUSA,
	GAME_SCENE_ENEMY_1,		//�o�g�����
	GAME_SCENE_ENEMY_2,		//�o�g�����
	GAME_SCENE_ENEMY_3,		//�o�g�����
	GAME_SCENE_ENEMY_4,		//�o�g�����
	GAME_SCENE_ENEMY_5,		//�o�g�����
	GAME_SCENE_ENEMY_6,		//�o�g�����
	GAME_SCENE_ENEMY_7,		//�o�g�����
	GAME_SCENE_ENEMY_8,		//�o�g�����
	GAME_SCENE_ENEMY_9,		//�o�g�����
	GAME_SCENE_ENEMY_10,	//�o�g�����
	GAME_SCENE_ENEMY_11,	//�o�g�����
	GAME_SCENE_ENEMY_12,	//�o�g�����
	GAME_SCENE_ENEMY_13,	//�o�g�����
	GAME_SCENE_PLAY,	//�v���C���
	GAME_SCENE_END		//�G���h���
};

enum MAP_IMAGE {
	M_N = -1,
	M_B = 19,
	M_G_T = 6,
	M_BLO = 67,
	M_ON = 125,
	M_OFF = 126,
	M_AM = 95,
	M_END = 399
};

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_END = 11
};

enum Block_No {
	first,
	second,
	third,
	fourth,
	not_use
};

enum GAME_END_KIND {
	END_KIND_CONTINUE,
	END_KIND_OVER,
	END_KIND_CLEAR
};

//############�\����##############
typedef struct STRUCT_GAZOU {
	int Handle;
	char FilePath[128];
	int X;
	int Y;
	int Width;
	int Height;
	int c_Width;
	int c_Height;
}GAZOU;

GAZOU BACKGROUND;
GAZOU BACK_TITLE;
GAZOU BACK_SOUSA;
GAZOU BACK_OVER;
GAZOU BACK_CLEAR;
GAZOU BACK_GAME_OVER;

typedef struct STRUCT_MAP
{
	char FilePath[128];
	int Handle[MAP_BUN_TATE_CNT*MAP_BUN_YOKO_CNT];
	int X[MAP_BUN_TATE_CNT*MAP_BUN_YOKO_CNT];
	int Y[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int Width[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int Height[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int C_Width[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];
	int C_Height[MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT];

	BOOL charaStopFlag_x;
	BOOL charaStopFlag_y;

	BOOL GoalFlag;

	int EndKind;

	BOOL GoalEffect1;
}MAP;

typedef struct STRUCT_CHARACTOR
{
	char FilePath[128];
	int Handle[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int X[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int Y[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_YOKO_CNT];
	int Width[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int Height[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int C_Width[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
	int C_Height[GAME_ENEMY_BUN_YOKO_CNT*GAME_ENEMY_BUN_TATE_CNT];
}CHARA;

typedef struct STRUCT_PLAYER
{
	int Handle[CHARA_MOTION_NUM];
	int X;
	int Y;
	int Width;
	int Height;
	int C_Width;
	int C_Height;
	int NowHandleNum;
	int NowHandleCnt;
	int NowHandleCntMAX;

	int Speed;
	int MoveDist_x;
	int MoveDist_y;

	int Zanki;

	BOOL IsJumpNow;

	int JumpStartTime;
	int JumpNowTime;
	int JumpPrevY;
	int JumpValue;
	int Mass;
	int Weight;

	int JumpMaxTop;
	BOOL IsJumpTop;

	BOOL CanMoveLeft;
	BOOL CanMoveRight;

	BOOL CanMoveUp;
	BOOL CanMoveDown;

	int atariX;
	int atariY;
	int atariWidth;
	int atariHeight;

	RECT atariRect;

}PLAYER;

typedef struct STRUCT_MUSIC
{
	int Handle;
	char FilePath[128];
	int Playtype;
}MUSIC;

//########## �O���[�o���ϐ� ##########

//typedef STRUCT_GAZOU GAZOU;
//typedef STRUCT_CHARACTOR CHARA;
//typedef STRUCT_MAP MAP;
//typedef STRUCT_PLAYER PLAYER;

//�E�B���h�E�֌W
WNDPROC WndProc;						//�E�B���h�E�v���V�[�W���̃A�h���X
BOOL IsWM_CREATE = FALSE;				//WM_CREATE������ɓ��삵�������f����


//FPS�֘A
int StartTimeFps;						//����J�n����
int CountFps;							//�J�E���^
float CalcFps;							//�v�Z����
int SampleNumFps = FPS_SPEED;		//���ς����T���v����

//�L�[�{�[�h�֘A
char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����
int GameSceneNow = (int)GAME_SCENE_TITLE;

GAZOU BackImage[4];
int ScrollCntYoko;
int ScrollCntTate;

int ScrollDistPlusYoko = 1;

MAP MapImage;
int ScrollDistKeyPlusYoko = 2;

int G_Cnt = 0;

int charaCnt = 0;

int mapCnt = 0;

PLAYER p;

int blockCnt = 0;

int random;

MUSIC MUSIC_SE_JUMP;
MUSIC MUSIC_SE_GAME_OVER;
MUSIC MUSIC_BGM_PLAY;
MUSIC MUSIC_OP;
MUSIC MUSIC_SOUSA;
MUSIC MUSIC_SE_CLEAR;

int i = 0;
int tate = 0;
int yoko = 0;
int sum = 0;
int rCnt = 0;
int NotD_Cnt = 0;
int cnt = 0;
int mot = 0;

int num = 0;

int switch1 = 33;

int switch2 = 90;

long a, b;

int time_miri;
int time_miri_keisoku;

double Time = 0;
double Time1 = 0;
double Time2 = 0;

double Goal_Time = 0;

int message;

CHARA CharaImage;
PLAYER Myplayer;

int FONTHANDLE_TAMESHI = 0;

int on_x = 0;
int on_y = 0;

int blockX = 0;
int blockY = 0;

FILE *fp_map_csv;

int MapData[MAP_TATE][MAP_YOKO];//�}�b�v�̃f�[�^

int MapData_Init[MAP_TATE][MAP_YOKO];//�}�b�v�̃f�[�^�������p

int ZankiDrawCount = 0;
int ZankiDrawCountMax = 60;

int UntilZankiDrawCount = 0;
int UntilZankiDrawCountMax = 60;

BOOL tyakuti = FALSE;

int PlayerImageNum[CHARA_MOTION_NUM] = {
	0,  1,  2,
	3,  4,  5,
	6,  7,  8,
	9, 10, 11
};

int MapNotDownKind[MAP_NOTDOWN_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };
int MapNotUpKind[MAP_NOTUP_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };

int MapOKDownKind[MAP_OKDOWN_KIND] = { -1 };

int MapNotLeftKind[MAP_NOTLEFT_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };
int MapNotRightKind[MAP_NOTRIGHT_KIND] = { 8,9,10,11,12,14,20,90,102,103,109,110, 117,121,126,139 };

int OffHit[OFF_HIT] = { 126 };
int OnHit[ON_HIT] = { 125 };

int MapGoalKind[GAME_MAP_GOAL_KIND] = { 204,224 };

RECT rectMap_DownNG[MAP_TATE][MAP_YOKO];
RECT rectMap_DownNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_DownOK[MAP_TATE][MAP_YOKO];
RECT rectMap_DownOK_First[MAP_TATE][MAP_YOKO];

RECT rectMap_LeftNG[MAP_TATE][MAP_YOKO];
RECT rectMap_LeftNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_RightNG[MAP_TATE][MAP_YOKO];
RECT rectMap_RightNG_First[MAP_TATE][MAP_YOKO];

RECT rectMap_UpNG[MAP_TATE][MAP_YOKO];
RECT rectMap_UpNG_First[MAP_TATE][MAP_YOKO];


//########## �v���g�^�C�v�錾 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM);	//����E�B���h�E�v���V�[�W��

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�

VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����֐�
VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��֐�

VOID MY_GAME_TITLE(VOID);			//�^�C�g����ʂ̊֐�
VOID MY_GAME_SOUSA(VOID);           //���������ʂ̊֐�
VOID MY_GAME_PLAY(VOID);			//�v���C��ʂ̊֐�
VOID MY_GAME_END(VOID);				//�G���h��ʂ̊֐�

BOOL MY_GAZOU_LOAD(GAZOU *, int, int, const char *);

BOOL MY_PLAY_INIT(VOID);
VOID MY_PLAY_BACKIMAGE_DRAW(VOID);
VOID MY_PLAY_SCROLL(VOID);

BOOL MY_MAP_READ_CSV_NUM(FILE *, const char *);

BOOL MY_CHARA_LOAD_BUNKATSU(CHARA *, int, int, int, int, int, const char *);
BOOL MY_INIT_PLAYER(PLAYER *, CHARA, int *, int, int, int);

//VOID BLOCK_INDICATE(VOID);//	�u���b�N��\������֐�

VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂֐�
VOID MY_PLAY_PLAYER_DRAW(VOID);
VOID MY_PLAYER_OPERATION(VOID);

VOID MY_PLAY_MAP_DRAW(VOID);//�}�b�v��`�悷��֐�

VOID MY_PLAY_PLAYER_JUMP_PREV(VOID);//�W�����v�̑O�������s���֐�

BOOL MY_PLAY_CHECK_GAME_END(VOID);//�Q�[���G���h�����肷��֐�

VOID MY_DRAW_STRING_CENTER_CENTER(char[][128], int, char *, int);//��ʒ����ɕ�����`�悷��֐�
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL);//�������f�t�H���g�t�H���g�ɐݒ肷��֐�

VOID MY_BG_IMAGE_INIT(VOID);

/* �����蔻��̊֐� */
VOID MY_SET_PLAYER_ATARI(PLAYER *);
BOOL MY_CHECK_RECT_ATARI(RECT, RECT);
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP(RECT, RECT[MAP_TATE][MAP_YOKO]);
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[MAP_TATE][MAP_YOKO], int *, int *);

VOID MY_TITLE_BACKGROUND_DRAW(VOID);

VOID MY_OVER_BACKGROUND_DRAW(VOID);

VOID MY_CLEAR_BACKGROUND_DRAW(VOID);

VOID MY_SOUSA_BACKGROUND_DRAW(VOID);

VOID MY_GAME_OVER_BACKGROUND_DRAW(VOID);

BOOL BACKGROUND_LOAD(GAZOU *, int, int, const char *);

VOID MY_GAME_ZANKI(VOID);

VOID MY_FPS_DRAW(VOID);

BOOL MAP_INIT(MAP *, int, int, int, int, int, const char *);

VOID MY_TIMER(VOID);

BOOL MY_MUSIC_LOAD(MUSIC *, const char *);

VOID BATTLE_SLIME(VOID);
VOID BATTLE_WOD(VOID);
VOID BATTLE_BEETLE(VOID);
VOID BATTLE_SPIDER(VOID);
VOID BATTLE_LIZARD(VOID);
VOID BATTLE_SCOPION(VOID);
VOID BATTLE_CHIKEN(VOID);
VOID BATTLE_CAT(VOID);
VOID BATTLE_BONE(VOID);
VOID BATTLE_DRAGON(VOID);
VOID BATTLE_KERBEROS(VOID);
VOID BATTLE_KNIGHT(VOID);
VOID BATTLE_KNIGHT(VOID);
VOID BATTLE_BOSS(VOID);



//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������
	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);			//�^�C�g���o�[�Ȃ�
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) { return -1; }

	//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);

	MY_MUSIC_LOAD(&MUSIC_SE_JUMP, SE_JUMP);
	MY_MUSIC_LOAD(&MUSIC_SE_GAME_OVER, SE_GAME_OVER);
	MY_MUSIC_LOAD(&MUSIC_BGM_PLAY, BGM_GAME_PLAY);
	MY_MUSIC_LOAD(&MUSIC_OP, BGM_GAME_OP);
	MY_MUSIC_LOAD(&MUSIC_SOUSA, BGM_GAME_SOUSA);
	MY_MUSIC_LOAD(&MUSIC_SE_CLEAR, SE_GAME_CLEAR);

	/*if (!BACKGROUND_LOAD(&BACKGROUND, 0, 0, BACKIMAGE_1))
	{
		return -1;
	}
*/
	if (!BACKGROUND_LOAD(&BACK_TITLE, 0, 0, BACKGROUND_TITLE))
	{
		return -1;
	}

	if (!BACKGROUND_LOAD(&BACK_CLEAR, 0, 0, BACKIMAGE_CLEAR))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_SOUSA, 0, 0, BACKIMAGE_SOUSA))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_OVER, 0, 0, BACKIMAGE_OVER))
	{
		return -1;
	}
	if (!BACKGROUND_LOAD(&BACK_GAME_OVER, 0, -100, MOJI_GAME_OVER))
	{
		return -1;
	}

	if (MAP_INIT(&MapImage, MAP_BUN_YOKO_CNT * MAP_BUN_TATE_CNT, MAP_BUN_YOKO_CNT, MAP_BUN_TATE_CNT, 32, 32, MAP_1) == FALSE) { MessageBox(NULL, MAP_1, "NotFound", MB_OK); return -1; }

	if (MY_MAP_READ_CSV_NUM(fp_map_csv, MAP_CSV_1) == FALSE) { MessageBox(NULL, MAP_CSV_1, "NotFound", MB_OK); return -1; }

	if (MAP_INIT(&MapImage, 160, 8, 20, 32, 32, MAP_1) == FALSE) { return -1; }

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, CHARA_BUN_YOKO_CNT*CHARA_BUN_TATE_CNT, CHARA_BUN_YOKO_CNT, CHARA_BUN_TATE_CNT, CHARA_YOKO_SIZE, CHARA_TATE_SIZE, PLAYER_IMAGE) == FALSE) { MessageBox(NULL, PLAYER_IMAGE, "NotFound", MB_OK); return -1; }

	FONTHANDLE_TAMESHI = CreateFontToHandle(NULL, 40, 3);

	//�������[�v
	while (TRUE)
	{
		Time1 = GetNowCount();

		if (ProcessMessage() != 0) { break; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

		if (ClearDrawScreen() != 0) { break; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

		MY_ALL_KEYDOWN_UPDATE();				//�L�[�̏�Ԃ��擾

		//�V�[���I��
		switch (GameSceneNow)
		{
		case (int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

			MY_GAME_TITLE();	//�^�C�g����ʂ̏���

			break;	//�^�C�g����ʂ̏��������܂�


		case (int)GAME_SCENE_SOUSA:

			MY_GAME_SOUSA();

			break;

			//case (int)GAME_SCENE_ZANKI://�c�@�\����ʂ̏�����������

			//	MY_GAME_ZANKI();//�c�@�\����ʂ̏���

			//	break;

		case (int)GAME_SCENE_ENEMY_1:

			BATTLE_SLIME();

			break;

		case (int)GAME_SCENE_ENEMY_2:

			BATTLE_WOD();

			break;

		case (int)GAME_SCENE_ENEMY_3:

			BATTLE_BEETLE();

			break;

		case (int)GAME_SCENE_ENEMY_4:

			BATTLE_SPIDER();

			break;

		case (int)GAME_SCENE_ENEMY_5:

			BATTLE_LIZARD();

			break;


		case (int)GAME_SCENE_ENEMY_6:

			BATTLE_SCOPION();

			break;

		case (int)GAME_SCENE_ENEMY_7:

			BATTLE_CHIKEN();

			break;

		case (int)GAME_SCENE_ENEMY_8:

			BATTLE_CAT();

			break;

		case (int)GAME_SCENE_ENEMY_9:

			BATTLE_BONE();

			break;

		case (int)GAME_SCENE_ENEMY_10:

			BATTLE_DRAGON();

			break;

		case (int)GAME_SCENE_ENEMY_11:

			BATTLE_KERBEROS();

			break;

		case (int)GAME_SCENE_ENEMY_12:

			BATTLE_KNIGHT();

			break;

		case (int)GAME_SCENE_ENEMY_13:

			BATTLE_BOSS();

			break;
		case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

			MY_GAME_PLAY();		//�v���C��ʂ̏���

			break;	//�v���C��ʂ̏��������܂�

		case (int)GAME_SCENE_END:	//�G���h��ʂ̏�����������

			MY_GAME_END();		//�G���h��ʂ̏���

			break;	//�G���h��ʂ̏��������܂�

		default:

			break;
		}

		MY_FPS_UPDATE();						//FPS�̏���[�X�V]

		ScreenFlip();
		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();		//FPS�̏���[�҂�]
	}

	DeleteMusicMem(MUSIC_SE_JUMP.Handle);
	DeleteMusicMem(MUSIC_SE_GAME_OVER.Handle);
	DeleteMusicMem(MUSIC_BGM_PLAY.Handle);
	DeleteMusicMem(MUSIC_OP.Handle);
	DeleteMusicMem(MUSIC_SOUSA.Handle);
	DeleteMusicMem(MUSIC_SE_CLEAR.Handle);


	for (mapCnt = 0; mapCnt < MAP_YOKO*MAP_TATE; mapCnt++)
	{
		DeleteGraph(MapImage.Handle[mapCnt]);
	}

	for (charaCnt = 0; charaCnt < CHARA_BUN_YOKO_CNT*CHARA_BUN_TATE_CNT; charaCnt++)
	{
		DeleteGraph(CharaImage.Handle[charaCnt]);
	}

	DxLib_End();		//�c�w���C�u�����g�p�̏I������

	return 0;
}

//########## FPS�l���v���A�X�V����֐� ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS�l���v�����A�҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//������������
	int waitTime = CountFps * 1000 / FPS_SPEED - resultTime;	//�҂ׂ�����

	if (waitTime > 0)		//�w���FPS�l���������ꍇ
	{
		Sleep(waitTime);	//�҂�
	}
	return;
}

VOID MY_FPS_DRAW(VOID)
{
	DrawFormatString(0, GAME_HEIGHT - 30, GetColor(255, 255, 255), "FPS:%.1lf", CalcFps);

	return;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];

	GetHitKeyStateAll(TempKey);   //���ׂẴL�[���͏�Ԃ��擾����

	for (i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)
		{
			AllKeyState[i]++;    //������Ă���
		}
		else
		{
			AllKeyState[i] = 0;  //������Ă��Ȃ�
		}
	}
	return;
}

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{/*
	if (CheckSoundMem(MUSIC_OP.Handle) < 1 && CheckSoundMem(MUSIC_BGM_PLAY.Handle) == 0)
	{
		ChangeVolumeSoundMem(255, MUSIC_OP.Handle);
		PlaySoundMem(MUSIC_OP.Handle, DX_PLAYTYPE_LOOP);
	}*/

	if (CheckSoundMem(MUSIC_OP.Handle) == 0)
	{
		ChangeVolumeSoundMem(100, MUSIC_OP.Handle);
		PlaySoundMem(MUSIC_OP.Handle, DX_PLAYTYPE_LOOP);
	}
	MY_TITLE_BACKGROUND_DRAW();

	if (AllKeyState[KEY_INPUT_RETURN] != 0)
	{
		if (MY_PLAY_INIT() == TRUE)		//�v���C��ʏ�����
		{
			for (tate = 0; tate < MAP_TATE; tate++)
			{
				for (yoko = 0; yoko < MAP_YOKO; yoko++)
				{
					MapData[tate][yoko] = MapData_Init[tate][yoko];
				}
			}
		}
	}

	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		StopSoundMem(MUSIC_OP.Handle);
		GameSceneNow = (int)GAME_SCENE_SOUSA;	//�V�[���𑀍������ʂɂ���
	}

	//DrawString(310, 270, "�f�l�c", GetColor(255, 255, 255), SetFontSize(60));
	DrawString(140, 450, "�G���^�[�L�[�������Ă�������", GetColor(255, 255, 0), SetFontSize(30));

	return;
}

//##########����������##########
VOID MY_GAME_SOUSA(VOID)
{
	if (CheckSoundMem(MUSIC_SOUSA.Handle) == 0)
	{
		MUSIC_OP.Handle = 0;
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SOUSA.Handle);
		PlaySoundMem(MUSIC_SOUSA.Handle, DX_PLAYTYPE_BACK);
	}
	DrawBox(0, 0, 800, 640, GetColor(255, 255, 255), TRUE);
	MY_SOUSA_BACKGROUND_DRAW();
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{
		StopSoundMem(MUSIC_SOUSA.Handle);
		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		Time2 = Time1;

	}

	/*DrawString(60, 100, "�E�v���C���[�͍��E���L�[�ō��E�ړ�", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 130, "����L�[�ŃW�����v���܂��B", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(60, 170, "�E�r���ɂ���OFF�X�C�b�`�������ƃu���b�N��", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 200, "�o�Ă��āA�`�L�[�ō��ɁA�c�L�[�ŉE�ɂr�L�[��", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(90, 230, "���Ɉړ����܂��B", GetColor(0, 0, 0), SetFontSize(30));
	DrawString(60, 270, "���u���b�N�͕K���}�b�v�̂ǂ����u�����u���b�N��", GetColor(255, 0, 0), SetFontSize(30));
	DrawString(90, 300, "��ɐςݏグ�Ďg���܂��傤�I", GetColor(255, 0, 0), SetFontSize(30));
	DrawString(60, 340, "���u���b�N�͂S�܂ŏo�Ă��܂��B", GetColor(255, 0, 0), SetFontSize(30));*/

	DrawString(190, 600, "�X�y�[�X�L�[�������ƃX�^�[�g", GetColor(0, 0, 0), SetFontSize(30));
}

VOID BATTLE_SLIME(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}


VOID BATTLE_WOD(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_BEETLE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_SPIDER(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_LIZARD(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_SCOPION(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}


VOID BATTLE_CHIKEN(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_CAT(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_BONE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_DRAGON(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_KERBEROS(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}

VOID BATTLE_KNIGHT(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}



VOID BATTLE_BOSS(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{

		GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		random = 0;

	}
}



//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	if (CheckSoundMem(MUSIC_BGM_PLAY.Handle) == 0)
	{
		MUSIC_OP.Handle = 0;
		ChangeVolumeSoundMem(255 * 80 / 200, MUSIC_BGM_PLAY.Handle);
		PlaySoundMem(MUSIC_BGM_PLAY.Handle, DX_PLAYTYPE_BACK);
	}
	Time = (GetNowCount() - Time1) / 1000;

	//DrawFormatStringToHandle(300, 64, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "%d", Myplayer.Y);
	/*DrawFormatString(300, 0, GetColor(255, 255, 255), "�N���A�^�C��%d�b", Time);*/

	/*time_miri_keisoku++;
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�N���A�^�C��%d�b", Time);*/

	//if (AllKeyState[KEY_INPUT_SPACE] != 0)
	//{
	//	//G ameSceneNow = (int)GAME_SCENE_END;
	//}
	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0)
		{

			if (Myplayer.CanMoveLeft == TRUE)//�v���C���[�����ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_x == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntYoko > 0)//�}�C�i�X�̃X�N���[�������Ȃ�
					{
						ScrollCntYoko -= Myplayer.Speed;//��ʂ����ɃX�N���[��
					}
				}
			}
		}
	}
	if (AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_RIGHT] != 0)
		{
			if (Myplayer.CanMoveRight == TRUE)//�v���C���[���E�ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_x == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntYoko < MAP_OneBlock_YOKO_SIZE * MAP_YOKO)//��ʊO�փX�N���[�������Ȃ�
					{
						ScrollCntYoko += Myplayer.Speed;//��ʂ��E�ɃX�N���[��
					}
				}
			}
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_UP] != 0)
		{
			if (Myplayer.CanMoveUp == TRUE)//�v���C���[����ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_y == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntTate > 0)//�}�C�i�X�̃X�N���[�������Ȃ�
					{
						ScrollCntTate -= Myplayer.Speed;//��ʂ����ɃX�N���[��
					}
				}
			}
		}
	}
	//if (AllKeyState[KEY_INPUT_UP] != 0)
	//{
	//		if (MapImage.charaStopFlag_y == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
	//		{
	//			if (Myplayer.Y == 0 || Myplayer.Y <= MAP_OneBlock_TATE_SIZE*10)
	//			{
	//					Myplayer.Y += Myplayer.Speed;
	//					ScrollCntTate -= Myplayer.Speed * 2;//��ʂ����ɃX�N���[��
	//			}
	//		}	
	//}
	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_DOWN] != 0)
		{
			if (Myplayer.CanMoveDown == TRUE)//�v���C���[�����ɓ�����Ƃ�
			{
				if (MapImage.charaStopFlag_y == TRUE)//�v���C���[�𓮂����Ȃ��Ȃ��
				{
					if (ScrollCntTate < MAP_OneBlock_TATE_SIZE * MAP_TATE)//��ʊO�փX�N���[�������Ȃ�
					{
						ScrollCntTate += Myplayer.Speed;//��ʂ���ɃX�N���[��
					}
				}
			}
		}
	}

	/*if (MY_PLAY_CHECK_GAME_END() == TRUE)
	{*/
	/*getch();*/
	//StopSoundMem(MUSIC_BGM_PLAY.Handle);
	//GameSceneNow = (int)GAME_SCENE_END;
/*}
else
{*/
	MY_PLAYER_OPERATION();	//�v���C���[�̑���
//}

	if (random == 1)
	{
		GameSceneNow = (int)GAME_SCENE_ENEMY_1;
	}

	//MY_PLAYER_OPERATION();

	MY_PLAY_BACKIMAGE_DRAW();//�w�i��`��

	MY_PLAY_MAP_DRAW();  //�}�b�v��`��

	//DrawFormatStringToHandle(300, 64, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "%d", Myplayer.Y);

	//DrawBox(Myplayer.atariRect.left, Myplayer.atariRect.top, Myplayer.atariRect.right, Myplayer.atariRect.bottom, GetColor(255, 0, 0), TRUE);

	DrawFormatStringToHandle(260, 0, GetColor(255, 255, 255), FONTHANDLE_TAMESHI, "�o�ߎ���%0.2lf�b", (Time1 - Time2) / 1000);

	MY_PLAY_PLAYER_DRAW();

	//DrawString(0, 0, "�G���^�[�L�[�������ƈړ�", GetColor(255, 255, 255));
	//DrawFormatString(20, 20, GetColor(255, 255, 255), "%d", playerX);

	return;
}

//###########��ʒ����ɕ�����`�悷��֐�############
VOID MY_DRAW_STRING_CENTER_CENTER(char str[][128], int row, char *fontname, int size)
{
	ChangeFont(fontname, DX_CHARSET_DEFAULT);//�f�t�H���g�̃t�H���g��ύX����
	SetFontSize(size);                       //�f�t�H���g�̃t�H���g�T�C�Y��ς���
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE);//�t�H���g�����ꂢ�ɂ݂���

	int StrHeightSum = 0;
	for (sum = 0; sum < row; sum++)//�s�S�̂̍������W�v
	{
		StrHeightSum += GetFontSize();//�f�t�H���g�̃t�H���g�̍������擾
	}

	for (rCnt = 0; rCnt < row; rCnt++)//�t�H���g��`��
	{
		int StrWidth = GetDrawFormatStringWidth(&str[rCnt][0]);//�f�t�H���g�̃t�H���g�̉������擾
		int StrHeight = GetFontSize();

		DrawFormatString(
			GAME_WIDTH / 2 - StrWidth / 2,
			GAME_HEIGHT / 2 - StrHeightSum + StrHeight * rCnt,//��ʂ̒��S�@-�@�s�S�̂̕����̍����@+�@�P�s�̍���
			GetColor(255, 255, 255), &str[rCnt][0]);//�f�t�H���g�̃t�H���g�ŕ`��
	}

	MY_DRAW_SET_DEFAULT_FONT(TRUE);//�f�t�H���g�t�H���g�ɐݒ肷��
}

//########## �Q�[���G���h�����肷��֐� ##########
BOOL MY_PLAY_CHECK_GAME_END(VOID)
{
	//�v���C���[�̈ʒu�́A�v���C���[�̒��S
	int PlayerToMapNumY = (Myplayer.MoveDist_y + Myplayer.C_Height) / MAP_OneBlock_TATE_SIZE;
	int PlayerToMapNumX = (Myplayer.MoveDist_x + Myplayer.C_Width) / MAP_OneBlock_TATE_SIZE;


	//�v���C���[��ʊO�ɗ������Ƃ�
	if (Myplayer.Y > GAME_HEIGHT)
	{
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SE_GAME_OVER.Handle);
		PlaySoundMem(MUSIC_SE_GAME_OVER.Handle, DX_PLAYTYPE_BACK);
		//MapImage.EndKind = (int)END_KIND_CONTINUE;


		MapImage.EndKind = (int)END_KIND_OVER;

		//MapImage.GameEndKind = (int)END_KIND_OVER;
		return TRUE;
	}

	if (PlayerToMapNumX<0 || PlayerToMapNumX>MAP_YOKO) { return FALSE; }
	if (PlayerToMapNumY<0 || PlayerToMapNumY>MAP_TATE) { return FALSE; }

	for (G_Cnt = 0; G_Cnt < GAME_MAP_GOAL_KIND; G_Cnt++)
	{
		//�v���C���[���S�[���̂��̂ƐڐG�����Ƃ�
		if (MapData[PlayerToMapNumY][PlayerToMapNumX] == MapGoalKind[G_Cnt])
		{

			Goal_Time = (Time1 - Time2) / 1000;
			/*if (Myplayer.GetRedCoinNum == 5)
			{*/
			ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_SE_CLEAR.Handle);
			PlaySoundMem(MUSIC_SE_CLEAR.Handle, DX_PLAYTYPE_BACK);
			MapImage.EndKind = (int)END_KIND_CLEAR;
			return TRUE;
			break;
			//}
		}
	}
	return FALSE;//�Q�[�����s
}

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)	//�o�b�N�X�y�[�X�[�L�[��������Ă�����
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
	}

	MapData[16][17] = (int)M_N;

	MapData[17][53] = (int)M_N;

	MapData[16][108] = (int)M_N;
	MapData[14][109] = (int)M_N;
	MapData[12][110] = (int)M_N;
	MapData[10][111] = (int)M_N;
	/*for (int o = first; o <= fourth; o++)

		if (PlayerToMapNumY - 1 == 17 && PlayerToMapNumX == 53)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 16 && PlayerToMapNumX == 108)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 14 && PlayerToMapNumX == 109)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 12 && PlayerToMapNumX == 110)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	}

	if (PlayerToMapNumY - 1 == 10 && PlayerToMapNumX == 111)
	{
		MapData[PlayerToMapNumY - 1][PlayerToMapNumX] = (int)M_BLO;
	{*/

	if (MapImage.EndKind == (int)END_KIND_OVER)	//�Q�[���I�[�o�[�̂Ƃ�
	{
		MY_OVER_BACKGROUND_DRAW();
		char StrGameOver[2][128] = { "���߂�̂͂܂�����","" };
		char StrFontOver[128] = { "MS �S�V�b�N" };

		MY_DRAW_STRING_CENTER_CENTER(&StrGameOver[0], 2, StrFontOver, 40);

		MY_GAME_OVER_BACKGROUND_DRAW();
	}

	else if (MapImage.EndKind == (int)END_KIND_CLEAR)	//�Q�[���N���A�̂Ƃ�
	{
		MY_CLEAR_BACKGROUND_DRAW();

		DrawFormatStringToHandle(180, 0, GetColor(255, 255, 0), FONTHANDLE_TAMESHI, "���Ȃ��̋L�^��%0.2lf�b�ł�", Goal_Time);
		char StrGameClear[2][128] = { "GAME CLEAR","�ȒP���������ȁH" };
		DrawString(180, 400, "���ȃx�X�g�X�V��ڎw�����I�I", GetColor(0, 255, 0), SetFontSize(30));
		/*char StrGameClear_koushin[128] = { "���ȃx�X�g�X�V��ڎw�����I�I" };*/
		char StrFontClear[128] = { "MS �S�V�b�N" };

		MY_DRAW_STRING_CENTER_CENTER(&StrGameClear[0], 2, StrFontClear, 40);
		/*MY_DRAW_STRING_CENTER_CENTER(&StrGameClear_koushin[0], 2, StrFontClear, 80);*/

	}
	else if (MapImage.EndKind == (int)END_KIND_CONTINUE)	//�Q�[�����s�̂Ƃ�
	{
		if (UntilZankiDrawCount < UntilZankiDrawCountMax)
		{
			UntilZankiDrawCount++;
			//�����ɂ��鐔�l(0�����߂Ȃ��A255�����߂���)
			double ToukaPercent = UntilZankiDrawCount / (double)UntilZankiDrawCountMax;//���߁������߂�

			DrawBox(0, 0, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);//�^���Âȉ�ʂɂ���

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			if (MY_PLAY_INIT() == TRUE)	//�v���C���[�̈ʒu�Ȃǂ̏���������
			{

			}
		}
	}

	DrawString(45, 490, "�^�C�g���ɖ߂�ɂ̓o�b�N�X�y�[�X�L�[�������Ă�������", GetColor(255, 0, 0), SetFontSize(25));

	DrawString(130, 520, "�I���������ꍇ�͉E�N���b�N�����Ă�������", GetColor(255, 0, 0), SetFontSize(25));

	return;
}

//�������f�t�H���g�t�H���g�ɐݒ肷��֐�
VOID MY_DRAW_SET_DEFAULT_FONT(BOOL anti)
{
	ChangeFont("MS �S�V�b�N", DX_CHARSET_DEFAULT);
	SetFontSize(16);

	if (anti)
	{
		ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	}
	return;
}

//########## �E�B���h�E�v���V�[�W���֐� ##########
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int closeMsgRet = 0;

	switch (msg)
	{
	case WM_CREATE:	//�E�B���h�E�̐�����������


		IsWM_CREATE = TRUE;	//WM_CREATE����I��
		return 0;

	case WM_CLOSE:		//����{�^�����������Ƃ�

		message = MessageBox(hwnd, TEXT("�Q�[�����I�����܂�"), TEXT("�I�����b�Z�[�W"), MB_OK/*YESNO*/);

		/*	if (message == IDYES)
			{
				return 0;
			}
			else
			{
				DefWindowProc(hwnd, msg, wp, lp);
			}*/

		break;

	case WM_RBUTTONDOWN:	//�}�E�X�̉E�{�^�����������Ƃ�

		closeMsgRet = MessageBox(hwnd, TEXT("�Q�[�����I�����܂���"), TEXT("�I�����b�Z�[�W"), MB_YESNO);

		if (closeMsgRet == IDYES)
		{
			SendMessage(hwnd, WM_CLOSE, 0, 0);		//WM_CLOSE���b�Z�[�W���L���[�ɒǉ�
		}
		else if (closeMsgRet == IDNO)
		{
			//break;
		}

		break;

	case WM_LBUTTONDOWN:	//�}�E�X�̍��{�^�����������Ƃ�

		//WM_NCLBUTTONDOWN(�^�C�g���o�[�Ń}�E�X�̍��{�^����������)���b�Z�[�W�������ɔ��s
		//PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);
		break;

	case WM_DESTROY:	//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		PostQuitMessage(0);		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�

		return 0;
	}
	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}

//�������̊֐�
BOOL MY_PLAY_INIT(VOID)
{
	if (MY_INIT_PLAYER(&Myplayer, CharaImage, &PlayerImageNum[0], MAP_OneBlock_YOKO_SIZE * 0, MAP_OneBlock_TATE_SIZE * 0, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	MapImage.GoalFlag = FALSE;//�S�[����Ԃ�������

	MapImage.EndKind = (int)END_KIND_CONTINUE;

	MapImage.GoalEffect1 = FALSE;

	//�v���C���[�̏�����

	MY_DRAW_SET_DEFAULT_FONT(TRUE);	//�f�t�H���g�t�H���g�ɐݒ肷��

	MY_BG_IMAGE_INIT();//�w�i�̈ʒu��������

	ScrollCntYoko = 0;    //�X�N���[���ʂ�������
	ScrollCntTate = 1408;    //�X�N���[���ʂ�������

	ZankiDrawCount = 0;//�c�@�\���J�E���^������
	UntilZankiDrawCount = 0;//�c�@�\���܂ł̃J�E���^������

	return TRUE;
}

VOID MY_BG_IMAGE_INIT(VOID)
{
	//�w�i�̈ʒu
	BackImage[0].X = 0;

	return;
}

//�v���C��ʂ̔w�i��`�悷��֐�
VOID MY_PLAY_BACKIMAGE_DRAW(VOID)
{
	DrawGraph(BACKGROUND.X, BACKGROUND.Y, BACKGROUND.Handle, TRUE);
}
//�^�C�g����ʂ̔w�i��`�悷��֐�
VOID MY_TITLE_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_TITLE.X, BACK_TITLE.Y, BACK_TITLE.Handle, TRUE);
}
//�Q�[���I�[�o�[��ʂ̔w�i��`�悷��֐�
VOID MY_OVER_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_OVER.X, BACK_OVER.Y, BACK_OVER.Handle, TRUE);
}
//�N���A��ʂ̔w�i��`�悷��֐�
VOID MY_CLEAR_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_CLEAR.X, BACK_CLEAR.Y, BACK_CLEAR.Handle, TRUE);
}
//���������ʂ̔w�i��`�悷��֐�
VOID MY_SOUSA_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_SOUSA.X, BACK_SOUSA.Y, BACK_SOUSA.Handle, TRUE);
}

VOID MY_GAME_OVER_BACKGROUND_DRAW(VOID)
{
	DrawGraph(BACK_GAME_OVER.X, BACK_GAME_OVER.Y, BACK_GAME_OVER.Handle, TRUE);
}

//�摜��ǂݍ��ސݒ������֐�
BOOL MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);
	g->Handle = LoadGraph(g->FilePath);

	if (g->Handle == -1) { return FALSE; }

	GetGraphSize(g->Handle, &g->Width, &g->Height);
	g->X = x;
	g->Y = y;
	g->c_Width = g->Width / 2;
	g->c_Height = g->Height / 2;

	return TRUE;
}

//�}�b�v�𕪊����ēǂݍ��ސݒ������֐�
BOOL MAP_INIT(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);

	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1)
	{
		return FALSE;
	}

	for (int count = 0; count < MAP_TATE*MAP_YOKO; count++)
	{
		GetGraphSize(
			m->Handle[cnt],
			&m->Width[cnt],
			&m->Height[cnt]
		);
		m->C_Width[cnt] = m->Width[cnt] / 2;
		m->C_Height[cnt] = m->Height[cnt] / 2;
	}

	m->charaStopFlag_x = FALSE;
	m->charaStopFlag_y = FALSE;

	return TRUE;
}

//##########�L�����𕪊����ēǂݍ��ފ֐�############
BOOL MY_CHARA_LOAD_BUNKATSU(CHARA *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(c->FilePath, path);

	ret = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);

	if (ret == -1) { return FALSE; }

	for (cnt = 0; cnt < MAP_BUN_YOKO_CNT*MAP_BUN_TATE_CNT; cnt++)
	{
		GetGraphSize(
			c->Handle[cnt],
			&c->Width[cnt],
			&c->Height[cnt]
		);

		c->C_Width[cnt] = c->Width[cnt] / 2;
		c->C_Height[cnt] = c->Height[cnt] / 2;
	}
	return TRUE;
}

//�w�i��ǂݍ��ފ֐�
BOOL BACKGROUND_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);
	g->Handle = LoadGraph(g->FilePath);
	if (g->Handle == -1)
	{
		return FALSE;
	}
	GetGraphSize(g->Handle, &g->Width, &g->Height);
	g->X = x;
	g->Y = y;

	return TRUE;
}

//�v���C���[������������֐�
BOOL MY_INIT_PLAYER(PLAYER *p, CHARA c, int *num, int x, int y, int speed)
{
	for (mot = 0; mot < CHARA_MOTION_NUM; mot++)
	{
		p->Handle[mot] = c.Handle[*(num + mot)];
	}

	p->X = 320;
	p->Y = 320;
	p->Width = c.Width[*(num + 0)];
	p->Height = c.Height[*(num + 0)];
	p->C_Width = c.C_Width[*(num + 0)];
	p->C_Height = c.C_Height[*(num + 0)];

	p->Width = MAP_OneBlock_YOKO_SIZE;
	p->Height = MAP_OneBlock_TATE_SIZE;
	p->C_Width = MAP_OneBlock_YOKO_SIZE / 2;
	p->C_Height = MAP_OneBlock_TATE_SIZE / 2;

	p->NowHandleNum = 6;
	p->NowHandleCnt = 0;
	p->NowHandleCntMAX = 4;

	p->Speed = speed;

	p->MoveDist_x = 320;
	p->MoveDist_y = 320;

	p->IsJumpNow = FALSE;
	p->JumpStartTime = 0;
	p->JumpNowTime = 0;
	p->JumpPrevY = 0;
	p->JumpValue = 0;
	p->Mass = CHARA_WEIGHT;
	p->Weight = p->Mass*GRAVITY;

	p->CanMoveLeft = TRUE;
	p->CanMoveRight = TRUE;
	p->CanMoveUp = TRUE;
	p->CanMoveDown = TRUE;

	p->atariX = 4;
	p->atariY = 0;
	p->atariWidth = 25;
	p->atariHeight = 32;

	//MY_SET_PLAYER_ATARI(p);

	return TRUE;
}

//�v���C���[�𑀍삷��֐�
VOID MY_PLAYER_OPERATION(VOID)
{
	BOOL IsKeyDown = FALSE;

	BOOL CanMoveLeft = TRUE;//���ɍs���邩
	BOOL CanMoveRight = TRUE;//�E�ɍs���邩
	BOOL CanMoveUp = TRUE;//�E�ɍs���邩
	BOOL CanMoveDown = TRUE;//���ɍs���邩

	//�v���C���[�̈ʒu���}�b�v�z��̂ǂ��ɂ��邩�ϊ�
	int PlayerToMapNumY;
	//�v���C���[�́y�ړ������ʒu�z���}�b�v�z��̂ǂ��ɂ��邩�ϊ�	���v���C���[�̈ʒu�́A�X�N���[�����A�ς��Ȃ�����
	//�L�����̈ʒu���A�P�}�b�v�̔����̈ʒu�ɂ���
	int PlayerToMapNumX;

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_UP] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0)
		{
			IsKeyDown = TRUE;
			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum < 5)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 3;
				}
			}
			//�������ɁA�܂�������
			Myplayer.CanMoveLeft = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.left -= 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_LeftNG) == TRUE)
			{
				Myplayer.CanMoveLeft = FALSE;
			}

			if (Myplayer.CanMoveLeft == TRUE)//���Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_x == FALSE)
				{
					if (Myplayer.X > 0)
					{
						Myplayer.X -= Myplayer.Speed;//�v���C���[�����Ɉړ�

					}
				}

				if (Myplayer.MoveDist_x > 0)
				{
					Myplayer.MoveDist_x -= Myplayer.Speed;//�������������v�Z
				}
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_RIGHT] != 0)
		{

			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 6;
				}
			}
			Myplayer.CanMoveRight = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.right += 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_RightNG) == TRUE)
			{
				Myplayer.CanMoveRight = FALSE;
			}

			if (Myplayer.CanMoveRight == TRUE)//�E�Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_x == FALSE)
				{
					if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
					{
						Myplayer.X += Myplayer.Speed;//�v���C���[���E�Ɉړ�

					}
				}
				if (Myplayer.MoveDist_x < MAP_OneBlock_YOKO_SIZE * MAP_YOKO)
				{
					Myplayer.MoveDist_x += Myplayer.Speed;//�������������v�Z
				}
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_DOWN] == 0)
	{
		if (AllKeyState[KEY_INPUT_UP] != 0)
		{

			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 9 && Myplayer.NowHandleNum < 11)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 9;
				}
			}
			Myplayer.CanMoveUp = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.top -= 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_UpNG) == TRUE)
			{
				Myplayer.CanMoveUp = FALSE;
			}

			if (Myplayer.CanMoveUp == TRUE)//��Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_y == FALSE)
				{
					if (Myplayer.Y + Myplayer.Width < GAME_WIDTH)
					{
						Myplayer.Y -= Myplayer.Speed;//�v���C���[����Ɉړ�


					}
				}
				Myplayer.MoveDist_y += Myplayer.Speed;//�������������v�Z	
			}
			random = rand() % RANDOM_NUM;
		}
	}

	if (AllKeyState[KEY_INPUT_RIGHT] == 0 && AllKeyState[KEY_INPUT_LEFT] == 0 && AllKeyState[KEY_INPUT_UP] == 0)
	{
		if (AllKeyState[KEY_INPUT_DOWN] != 0)
		{
			IsKeyDown = TRUE;

			if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
			{
				Myplayer.NowHandleCnt++;
			}
			else
			{
				Myplayer.NowHandleCnt = 0;

				if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
				{
					Myplayer.NowHandleNum++;
				}
				else
				{
					Myplayer.NowHandleNum = 0;
				}
			}
			Myplayer.CanMoveDown = TRUE;

			MY_SET_PLAYER_ATARI(&Myplayer);
			Myplayer.atariRect.bottom += 4;

			if (MY_CHECK_RECT_ATARI_CHARA_MAP(Myplayer.atariRect, rectMap_DownNG) == TRUE)
			{
				Myplayer.CanMoveDown = FALSE;
			}

			if (Myplayer.CanMoveDown == TRUE)//���Ɉړ��ł���Ƃ�
			{
				if (MapImage.charaStopFlag_y == FALSE)
				{
					if (Myplayer.Y + Myplayer.Height < GAME_HEIGHT)
					{
						Myplayer.Y += Myplayer.Speed;//�v���C���[�����Ɉړ�
					}
				}
				Myplayer.MoveDist_y -= Myplayer.Speed;//�������������v�Z	
			}
			random = rand() % RANDOM_NUM;
		}
	}
	//�}�b�v�̍����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_x > 0 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * 10)
	{
		MapImage.charaStopFlag_x = FALSE;
	}

	//�}�b�v�̏㑤�ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_y > 0 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_YOKO_SIZE * 10)
	{
		MapImage.charaStopFlag_y = FALSE;
	}

	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDist_x > MAP_OneBlock_YOKO_SIZE * 10 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * 53)
	{
		MapImage.charaStopFlag_x = TRUE;

	}
	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDist_y > MAP_OneBlock_TATE_SIZE * 10 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_TATE_SIZE * 63)
	{
		MapImage.charaStopFlag_y = TRUE;
	}

	//�}�b�v�̉����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_y > MAP_OneBlock_TATE_SIZE * 63 &&
		Myplayer.MoveDist_y <= MAP_OneBlock_TATE_SIZE * MAP_TATE)
	{
		MapImage.charaStopFlag_y = FALSE;
	}

	//�}�b�v�̉E���ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDist_x > MAP_OneBlock_YOKO_SIZE * 53 &&
		Myplayer.MoveDist_x <= MAP_OneBlock_YOKO_SIZE * MAP_YOKO)
	{
		MapImage.charaStopFlag_x = FALSE;
	}

	//�L�[��������Ă��Ȃ��Ƃ�
	if (IsKeyDown == FALSE)
	{
		if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum <= 8)
		{
			Myplayer.NowHandleNum = 6;
		}
		else if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum <= 5)
		{
			Myplayer.NowHandleNum = 3;
		}
		Myplayer.NowHandleCnt = Myplayer.NowHandleCntMAX - 1;	//�����摜��ς�����悤�ɂ���
	}

	//�}�b�v�̓����蔻����X�N���[��������
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			rectMap_DownNG[tate][yoko].left = rectMap_DownNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_DownNG[tate][yoko].right = rectMap_DownNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_DownOK[tate][yoko].left = rectMap_DownOK_First[tate][yoko].left - ScrollCntYoko;
			rectMap_DownOK[tate][yoko].right = rectMap_DownOK_First[tate][yoko].right - ScrollCntYoko;

			rectMap_LeftNG[tate][yoko].left = rectMap_LeftNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_LeftNG[tate][yoko].right = rectMap_LeftNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_RightNG[tate][yoko].left = rectMap_RightNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_RightNG[tate][yoko].right = rectMap_RightNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_UpNG[tate][yoko].left = rectMap_UpNG_First[tate][yoko].left - ScrollCntYoko;
			rectMap_UpNG[tate][yoko].right = rectMap_UpNG_First[tate][yoko].right - ScrollCntYoko;

			rectMap_DownNG[tate][yoko].top = rectMap_DownNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_DownNG[tate][yoko].bottom = rectMap_DownNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_DownOK[tate][yoko].top = rectMap_DownOK_First[tate][yoko].top - ScrollCntTate;
			rectMap_DownOK[tate][yoko].bottom = rectMap_DownOK_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_LeftNG[tate][yoko].top = rectMap_LeftNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_LeftNG[tate][yoko].bottom = rectMap_LeftNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_RightNG[tate][yoko].top = rectMap_RightNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_RightNG[tate][yoko].bottom = rectMap_RightNG_First[tate][yoko].bottom - ScrollCntTate;

			rectMap_UpNG[tate][yoko].top = rectMap_UpNG_First[tate][yoko].top - ScrollCntTate;
			rectMap_UpNG[tate][yoko].bottom = rectMap_UpNG_First[tate][yoko].bottom - ScrollCntTate;

		}
	}
	return;
	//}
}

//�W�����v�̑O�������s���֐�
VOID MY_PLAY_PLAYER_JUMP_PREV(VOID)
{
	Myplayer.IsJumpNow = TRUE;
	Myplayer.IsJumpTop = FALSE;

	Myplayer.JumpValue = CHARA_TATE_SIZE * 2;
	Myplayer.JumpMaxTop = Myplayer.Y - Myplayer.JumpValue;

	Myplayer.JumpPrevY = Myplayer.Y;
	Myplayer.JumpStartTime = GetNowCount();

	return;
}

//�v���C���[��\������֐�
VOID MY_PLAY_PLAYER_DRAW(VOID)
{
	DrawExtendGraph(
		Myplayer.X,
		Myplayer.Y,
		Myplayer.X + Myplayer.Width,
		Myplayer.Y + Myplayer.Height,
		Myplayer.Handle[Myplayer.NowHandleNum], TRUE);

	return;
}

//�}�b�v��\������֐�
VOID MY_PLAY_MAP_DRAW(VOID)
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			if ((yoko + 1)* MAP_OneBlock_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0)* MAP_OneBlock_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH)
			{
				DrawGraph(
					yoko * MAP_OneBlock_YOKO_SIZE - ScrollCntYoko,
					tate * MAP_OneBlock_TATE_SIZE - ScrollCntTate,
					MapImage.Handle[MapData[tate][yoko]], TRUE);
			}
		}
	}
}

//�Q�[����ʂ̃X�N���[�����s���֐�
VOID MY_PLAY_SCROLL(VOID)
{
	ScrollCntYoko += ScrollDistPlusYoko;
	ScrollCntTate += ScrollDistPlusYoko;
	DrawFormatString(0, 20, GetColor(255, 255, 255), "�X�N���[��������(��):%06d", ScrollCntYoko);

	return;
}

//�Q�[���}�b�v��CSV��ǂݍ��ފ֐�
BOOL MY_MAP_READ_CSV_NUM(FILE *fp, const char *path)
{
	if ((fp = fopen(path, "r")) == NULL)
	{
		return FALSE;
	}

	int result = 0;
	int LoopCnt = 0;
	while (result != EOF)
	{
		result = fscanf(fp, "%d,", &MapData[LoopCnt / MAP_YOKO][LoopCnt%MAP_YOKO]);

		MapData_Init[LoopCnt / MAP_YOKO][LoopCnt%MAP_YOKO] = MapData[LoopCnt / MAP_YOKO][LoopCnt%MAP_YOKO];//�l���R�s�[

		LoopCnt++;
	}

	fclose(fp);

	int cnt;

	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < MAP_NOTDOWN_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotDownKind[cnt])
				{
					rectMap_DownNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_DownNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_DownNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_DownNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_DownNG_First[tate][yoko] = rectMap_DownNG[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_OKDOWN_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapOKDownKind[cnt])
				{
					rectMap_DownOK[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_DownOK[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_DownOK[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_DownOK[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_DownOK_First[tate][yoko] = rectMap_DownOK[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_NOTLEFT_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotLeftKind[cnt])
				{
					rectMap_LeftNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_LeftNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_LeftNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_LeftNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_LeftNG_First[tate][yoko] = rectMap_LeftNG[tate][yoko];
				}
			}

			for (cnt = 0; cnt < MAP_NOTRIGHT_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotRightKind[cnt])
				{
					rectMap_RightNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_RightNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_RightNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_RightNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_RightNG_First[tate][yoko] = rectMap_RightNG[tate][yoko];
				}
			}
			for (cnt = 0; cnt < MAP_NOTUP_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotUpKind[cnt])
				{
					rectMap_RightNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_RightNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_RightNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_RightNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_RightNG_First[tate][yoko] = rectMap_RightNG[tate][yoko];
				}
			}
			for (cnt = 0; cnt < MAP_NOTUP_KIND; cnt++)
			{
				if (MapData[tate][yoko] == MapNotUpKind[cnt])
				{
					rectMap_UpNG[tate][yoko].left = yoko * MAP_OneBlock_YOKO_SIZE + 1;
					rectMap_UpNG[tate][yoko].top = tate * MAP_OneBlock_TATE_SIZE + 1;
					rectMap_UpNG[tate][yoko].right = (yoko + 1)*MAP_OneBlock_YOKO_SIZE - 1;
					rectMap_UpNG[tate][yoko].bottom = (tate + 1)*MAP_OneBlock_TATE_SIZE - 1;

					rectMap_UpNG_First[tate][yoko] = rectMap_UpNG[tate][yoko];
				}
			}
		}
	}
	return TRUE;
}
//�v���C���[�̓����蔻��̗̈��ݒ肷��֐�
VOID MY_SET_PLAYER_ATARI(PLAYER *p)
{
	p->atariRect.left = p->X + p->atariX + 1;
	p->atariRect.top = p->Y + p->atariY + 1;
	p->atariRect.right = p->X + p->atariX + p->atariWidth - 1;
	p->atariRect.bottom = p->Y + p->atariY + p->atariHeight - 1;

	return;
}

//##########���@�̂����蔻�������֐�##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top)
	{
		return TRUE;
	}

	return FALSE;
}

//�v���C���[�ƃ}�b�v�̓����蔻�������֐�
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP(RECT chara, RECT map[MAP_TATE][MAP_YOKO])
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko++)
		{
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

/*  */
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[MAP_TATE][MAP_YOKO], int *atariX, int *atariY)
{
	for (tate = 0; tate < MAP_TATE; tate++)
	{
		for (yoko = 0; yoko < MAP_YOKO; yoko)
		{
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;
				*atariX = yoko;

				return TRUE;
			}
		}
	}
	return FALSE;
}

//########## ����ǂݍ��ސݒ������֐� ##########
//���@���F���\���́@	:�ݒ肷�鉹�\���̂̕ϐ�
//���@���Fconst char *	:�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL			:TRUE:���� / FALSE:�ُ�
BOOL MY_MUSIC_LOAD(MUSIC *m, const char *path)
{
	//����ǂݍ���
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1)
	{
		return FALSE;
	}

	return TRUE;
}