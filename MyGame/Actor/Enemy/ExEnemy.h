#pragma once

#include "../Actor.h"
#include "../../Collision/BoundingCapsule.h"
#include "../../Animation/AnimationMesh.h"
#include "EnemySystem.h"

class ExEnemyState
{
public:
	enum  State
	{
		IDLE,
		WALK,
		RUN,
		PUNCH,
		DAMAGE,
		DEAD,
	};
};

class ExEnemy : public Actor, public EnemySystem {
public:
	ExEnemy(int model, IWorld* world, const Vector3& position, const IBodyPtr& body = std::make_shared<BoundingCapsule>(Vector3{ 0.0f,5.0f,0.0f }, Matrix::Identity, 15.0f, 4.0f));

	void initialize();

	void update(float deltaTime);

	void draw() const;

	virtual void onCollide(Actor& other);

	virtual void receiveMessage(EventMessage message, void* param);

	//��Ԃ̍X�V
	void update_state(float deltaTime);

	void Idle();
	void MoveWalk();
	void MoveRun();
	void Punch();
	void Damage();
	void Dead();

	//��Ԃ̕ύX
	void change_state(ExEnemyState::State state, int motion);

	void hit_player(const Vector3& dir);

	void deadAction();

	void Delay();

private:
	AnimatedMesh mesh_;

	//���[�V�����ԍ�
	int motion_;
	//�ړ����x
	const float WalkSpeed{ 0.005f };
	//���
	ExEnemyState::State state_;
	//��ԃ^�C�}
	float state_timer_;


	int invinciblyTime;
	bool invinciblyCheck;

	Actor* player_;

	float AttackDis{ 15.0f };

};


//���[�V�����ԍ�
//enum
//{
//	MotionBossIdel = 0,
//	MotionBossWalk = 1,
//	MotionBossRun = 2,
//	MotionBossPunch = 3,
//	MotionBossPunch2 = 4,
//	MotionBossDamage = 5,
//	MotionBossDead = 6,
//};