#pragma once

enum class BGM_ID
{
	//シューティングモード用
	TITLE_BGM,
	PLAY_BGM,
	WIN_BGM,
	LOSE_BGM,

	//アクションモード用
	ACTION_PLAY_BGM,
};

enum class SE_ID
{
	//シューティングモード用
	SHOOT_SE,
	ATTACK_SE,
	DAMAGEENEMY_SE,
	ENEMYDOAR_SE,
	ITEMUSE_SE,
	TITLEKETTEI_SE,
	WALKSTEP_SE,
	PAUSEKETTEI_SE,
	PAUSECURSOR_SE,
	ITEMGET_SE,
	TYOHATU_SE,

	//アクションモード用
	ARROW,
	RED_SWARD,
	ACTION_SWARD,
	ACTION_STEP,
	ACTION_WIN,
	ACTION_LOSE,
	RED_START,
	RED_WIN,
	RED_LOSE,
};