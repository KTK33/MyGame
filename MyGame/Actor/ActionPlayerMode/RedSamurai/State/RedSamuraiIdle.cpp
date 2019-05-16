#include "RedSamuraiIdle.h"
#include "../World/IWorld.h"
#include "../Actor/Actor.h"
#include "../Actor/ActionPlayerMode/RedSamurai/RedSamuraiMotionNum.h"

RedSamuraiIdle::RedSamuraiIdle(IWorld * world, ActorParameters & parameter)
{
	world_ = world;
	parameters_ = &parameter;
}

void RedSamuraiIdle::Stateinitialize()
{
	mNextStateFlag = false;
	mNextStateID = ActorStateID::RedSamuraiIdel;
	parameters_->Set_Motion(RedSamuraiMotionNum::MotionRedSamuraiIdel);
}

void RedSamuraiIdle::StateUpdate(Vector3 & lposition, Matrix & lrotation, AnimatedMesh & lmesh)
{
	//プレイヤーの検索
	auto player_ = world_->find_actor(ActorGroup::Player, "Player").get();
	if (player_ == nullptr) return;

	//一定距離内に来たら移動状態へ
	if (Vector3::Distance(player_->Getposition(), lposition) <= 250.0f)
	{
		mNextStateID = ActorStateID::RedSamuraiWalk;
		mNextStateFlag = true;
		return;
	}

	//HPが０になったら死亡
	if (parameters_->Get_HP() <= 0)
	{
		mNextStateID = ActorStateID::RedSamuraiDead;
		mNextStateFlag = true;
		return;
	}
}
