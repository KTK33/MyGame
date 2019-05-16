#pragma once

#include "../Actor/ActorState/ActorStateBase.h"

class ActionPlayerAttack :public ActorStateBase
{
public:
	ActionPlayerAttack(IWorld* world, ActorParameters& parameter);
	virtual void Stateinitialize() override;
	virtual void StateUpdate(Vector3& lposition, Matrix& lrotation, AnimatedMesh & lmesh) override;

private:
	//攻撃
	void Attack();
	//攻撃の種類で当たり判定を変更
	void AttackOption(Vector3 lposition, Matrix lrotation);
	//攻撃の当たり判定生成
	void AttackCollision(Vector3 lposition, Matrix lrotation, int deadTime, int attackParam, Vector3 spot, float len, float rad);
	//入力情報
	void Input();
private:
	int mAttackCount;
};
