#pragma once

//モーション番号
class ShootingPlayerMotionNum
{
public:
	enum  Motion
	{
		MotionPlayerIdle = 0,
		MotionPlayerStopGun,
		MotionPlayerForwardGun,
		MotionPlayerRightGun,
		MotionPlayerLeftGun,
		MotionPlayerBackGun,
		MotionPlayerReload,
		MotionPlayerIdleToAim,
		MotionPlayerAimToIdle,
		MotionPlayerIdle2,
		MotionPlayerDamageGun,
		MotionPlayerDead,
		MotionPlayerGunPunch,
		MotionPlayerRun,
		MotionPlayerIdleAiming,
		MotionPlayerDamage,
		MotionPlayerTyohatu,
		MotionPlayerWalk,
		MotionPlayerJump,
		MotionPlayerRunJump,
		MotionPlayerGuard,
		MotionPlayerItemUse,
		MotionPlayerTitle,
	};
};
