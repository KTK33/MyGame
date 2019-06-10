#include "ActionPlayerIdle.h"
#include "../Input/InputInfoInc.h"
#include "../Scene/GameData/GameDataManager.h"

ActionPlayerIdle::ActionPlayerIdle(IWorld * world, ActorParameters & parameter)
{
	world_ = world;
	parameters_ = &parameter;
}

void ActionPlayerIdle::Stateinitialize()
{
	mNextStateFlag = false;
	mNextStateID = ActorStateID::ActionPlayerIdle;
}

void ActionPlayerIdle::StateUpdate(Vector3 & lposition, Matrix & lrotation, AnimatedMesh & lmesh)
{
	//入力情報
	Input();

	//HPが０になったら死亡
	if (parameters_->Get_HP() <= 0)
	{
		mNextStateID = ActorStateID::ActionPlayerDead;
		mNextStateFlag = true;
		return;
	}
}

void ActionPlayerIdle::Input()
{
	if (GameDataManager::getInstance().GetDeadBossEnemy()) return;

	//攻撃
	if(ButtonB::GetInstance().TriggerDown())
	{
		mNextStateID = ActorStateID::ActionPlayerAttack;
		mNextStateFlag = true;
		return;
	}

	//ステップ
	if(ButtonA::GetInstance().TriggerDown() && LeftStick::GetInstance().KnockCheck())
	{
		mNextStateID = ActorStateID::ActionPlayerAvoidance;
		mNextStateFlag = true;
		return;
	}
}

