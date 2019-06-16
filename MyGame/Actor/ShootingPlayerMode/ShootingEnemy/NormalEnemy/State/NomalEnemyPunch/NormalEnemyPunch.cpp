#include "NormalEnemyPunch.h"
#include "../World/IWorld.h"
#include "../Actor/Actor.h"
#include "../Actor/ShootingPlayerMode/ShootingEnemy/NormalEnemy/NormalEnemyMotionNum.h"
#include "../Actor/EnemyAttackCollison/EnemyAttackCollison.h"

NormalEnemyPunch::NormalEnemyPunch(IWorld * world, ActorParameters & parameter)
{
	world_ = world;
	parameters_ = &parameter;
}

void NormalEnemyPunch::Stateinitialize()
{
	mNextStateFlag = false;
	mNextStateID = ActorStateID::NormalEnemyDamage;
	parameters_->Set_Motion(NormalEnemyMotionNum::MotionNormalEnemyPunch);

}

void NormalEnemyPunch::StateUpdate(Vector3 & lposition, Matrix & lrotation, AnimatedMesh & lmesh)
{
	if (parameters_->Get_Statetimer() == 40.0f)
	{
		AttackCollision(lposition, lrotation, 15, 1, Vector3(0.0f, 13.0f, 0.0f), 1.5f, 2.5f);
	}

	//モーションの時間が終わったら
	if (parameters_->Get_Statetimer() > lmesh.motion_end_time() - 5)
	{
		mNextStateID = ActorStateID::NormalEnemyIdle;
		parameters_->Set_Attack(false);
		mNextStateFlag = true;
		return;
	}

	//HPが０になったら死亡
	if (parameters_->Get_HP() <= 0)
	{
		mNextStateID = ActorStateID::NormalEnemyDead;
		mNextStateFlag = true;
		return;
	}

	if (parameters_->Get_invincibly())
	{
		mNextStateID = ActorStateID::NormalEnemyDamage;
		mNextStateFlag = true;
		return;
	}
}

void NormalEnemyPunch::AttackCollision(Vector3 lposition, Matrix lrotation, int deadTime, int attackParam, Vector3 spot, float len, float rad)
{
	//攻撃当たり判定の生成
	auto AttackPunch = std::make_shared<EnemyAttackCollison>(world_, Vector3{ lposition + lrotation.Forward() * 10 },
		std::make_shared<BoundingCapsule>(spot, Matrix::Identity, len, rad));
	world_->add_actor(ActorGroup::EnemyBullet, AttackPunch);
	AttackPunch->SetParam(false, deadTime, attackParam);

}