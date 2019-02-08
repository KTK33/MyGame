#pragma once

#include "../Actor.h"
#include "../../Collision/BoundingCapsule.h"
#include "../../Animation/AnimationMesh.h"
#include "EnemySystem.h"

class DummyEnemyState
{
public:
	enum  State
	{
		IDLE,   //待機    0
		PUNCH,  //パンチ  1
		ROAR,   //咆哮    2
		MOVE,   //移動    3
		DAMAGE, //被弾    4
		DEAD, //倒れる    5
	};
};

class DummyEnemy : public Actor,public EnemySystem {
public:
	DummyEnemy(int model, IWorld* world, const Vector3& position,const Matrix& rotation, const IBodyPtr& body = std::make_shared<BoundingCapsule>(Vector3{ 0.0f,5.0f,0.0f }, Matrix::Identity, 15.0f, 3.5f));

	void initialize();

	void update(float deltaTime);

	void draw() const;

	virtual void onCollide(Actor& other);

	virtual void receiveMessage(EventMessage message, void* param);

	//状態の更新
	void update_state(float deltaTime);

	void Idle();
	void Roar();
	void Move();
	void Punch();
	void Damage();
	void Dead();

	void hit_player(const Vector3& dir);

	void deadAction();

	//状態の変更
	void change_state(DummyEnemyState::State state, int motion);

	void Action(DummyEnemyState::State state);

	void Delay();

private:
	bool m_EneDead{ false };

	//アニメーションメッシュ
	AnimatedMesh mesh_;
	//モーション番号
	int motion_;
	//移動速度
	const float WalkSpeed{ 0.005f };
	//状態
	DummyEnemyState::State state_;
	//状態タイマ
	float state_timer_;

	int motionNum;

	Actor* player_;

	int invinciblyTime;
	bool invinciblyCheck;

	int maxHp;

	bool roarCheck;

	float AttackDis{ 10.0f };

};

//モーション番号
enum
{
	MotionDummyIdel = 0,
	MotionDummyPunch = 1,
	MotionDummyRoar = 2,
	MotionDummyMove = 3,
	MotionDummyDamage = 4,
	MotionDummyDead = 5,
};

