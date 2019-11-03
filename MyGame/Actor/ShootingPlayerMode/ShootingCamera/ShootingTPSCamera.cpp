#include "ShootingTPSCamera.h"
#include "../Input/InputInfoInc.h"
#include "../Math/Vector2.h"

#include "../Actor/Camera/CameraSpring/CameraSpring.h"
#include "../Actor/Camera/TPSCamera.h"
#include "../Scene/GameData/GameDataManager.h"
#include "../Texture/Sprite.h"
#include "../Actor/ShootingPlayerMode/ShootingPlayer/ShootingPlayerActor/ShootingPlayerParam/ShootingPlayerParam.h"
#include "../Actor/ShootingPlayerMode/UIActor/PlaySceneUI/GameClearUIh.h"
#include "../Actor/ShootingPlayerMode/UIActor/PlaySceneUI/GameOverUI.h"


ShootingTPSCamera::ShootingTPSCamera(IWorld * world, std::weak_ptr<Actor> m_Player) :
	Actor(world, "ActionCamera", Vector3::Zero),
	m_player{ m_Player },
	player_{ nullptr },
	mOffset(-30.0f, 0.0f, 0.0f),
	mUp(Vector3::UnitY),
	mPitchSpeed(0.0f),
	mYawSpeed(0.0f),
	mForward{Vector3::Zero},
	mFinishCamera{ 20.0f,20.0f,20.0f },
	malreadyCreate{ false }
{}

void ShootingTPSCamera::update(float deltaTime)
{
	prevPosition_ = position_;
	//�v���C���[�̌���
	player_ = world_->find_actor(ActorGroup::Player, "Player").get();
	if (player_ == nullptr) return;

	if (GameDataManager::getInstance().GetDeadBossEnemy() ||
		GameDataManager::getInstance().GetPlayerDead())
	{
		//�Q�[���I�����ݒ�
		PlayerGameFinish();
	}
	else
	{
		PlayerInput(deltaTime);
	}
	//�΂�
	CameraSpring::move(position_, velocity_, prevPosition_, 1.0f, 0.2f, 0.8f);
}

void ShootingTPSCamera::draw() const {
	//�Ə��̕`��
	mSU.draw();

	//�J�����ɒl��ݒ�
	TPSCamera::GetInstance().SetRange(0.5f, 1000.0f);
	TPSCamera::GetInstance().Position.Set(position_);
	TPSCamera::GetInstance().Target.Set(target_);
	TPSCamera::GetInstance().Up.Set(mUp);
	TPSCamera::GetInstance().Update();
}

void ShootingTPSCamera::PlayerInput(float deltaTime)
{
	mYawSpeed = RightStick::GetInstance().GetAngle().x * GameDataManager::getInstance().GetAIMSPD();
	mPitchSpeed = -RightStick::GetInstance().GetAngle().y * GameDataManager::getInstance().GetAIMSPD();

	//�㉺�̏���̐���
	if (GetCameraAngleVRotate() >= 0.4f) {
		mPitchSpeed = -0.1f;
	}
	else if (GetCameraAngleVRotate() <= -0.4f) {
		mPitchSpeed = 0.1f;
	}

	//�|�[�Y���ƃA�C�e���{�b�N�X���J���Ă��鎞�ɂ̓J�����͓����Ȃ��Ȃ�
	if (world_->GetPauseCheck() || 
		ShootingPlayerParam::getInstance().Get_ItemBoxOpen()) return;

	//���[���h��������Ƃ��郈�[�̃N�H�[�^�j�I�����쐬
	const Quaternion yaw(Vector3::UnitY, mYawSpeed * deltaTime);
	//�J�����̃I�t�Z�b�g�Ə���x�N�g�������[�ŕϊ�
	mOffset = Quaternion::Transform(mOffset, yaw);
	mUp = Quaternion::Transform(mUp, yaw);

	//�J�����̑O��/�E�������v�Z
	mForward = -1.0f * mOffset;
	mForward.Normalize();
	Vector3 right = Vector3::Cross(mUp, mForward);
	right.Normalize();

	//�J�����E���������Ƃ���s�b�`�̃N�H�[�^�j�I�����쐬
	const Quaternion pitch(right, mPitchSpeed * deltaTime);
	//�J�����̃I�t�Z�b�g�Ə���x�N�g�����s�b�`�ŕϊ�
	mOffset = Quaternion::Transform(mOffset, pitch);
	mUp = Quaternion::Transform(mUp, pitch);

	target_ = player_->Getposition() + right * 5.0f;
	target_.y = target_.y + PlayerHeight;

	//�J�����ƃv���C���[�̋���
	float dis = 0.0f;

	//�v���C���[���G�C������
	if (ShootingPlayerParam::getInstance().Get_AimCheck()) {
		//�G�C����
		dis = MathHelper::Lerp(dis, 1.5f, 0.1f);
	}
	else {
		//�G�C���O
		dis = MathHelper::Lerp(dis, 8.0f, 0.1f);
	}

	position_ = target_ + mOffset * dis;

	//�Ə��̈ʒu���Z�b�g����
	Vector3 to_Target = position_ + mForward.Normalize();
	ShootingPlayerParam::getInstance().Set_AimPos(to_Target);

	//�v���C���[�ɃJ�����̑O������n��
	m_player.lock()->receiveMessage(EventMessage::SIGHT_ROTATION, reinterpret_cast<void*>(&mForward));

	mSU.SetAimPos(GetCameraTarget(), ShootingPlayerParam::getInstance().Get_AimCheck());
}

void ShootingTPSCamera::receiveMessage(EventMessage message, void * param)
{}

void ShootingTPSCamera::PlayerGameFinish()
{
	//�v���C���[�����S���Q�[���I�[�o�[�ցA�{�X���S���Q�[���N���A��
	if (GameDataManager::getInstance().GetPlayerDead() == true)
	{
		NextSceneType(0);
	}
	else if (GameDataManager::getInstance().GetDeadBossEnemy() == true)
	{
		NextSceneType(1);
	}

	//�J�����̃|�W�V�����̐ݒ�
	position_ = Vector3(
		player_->Getposition().x + mFinishCamera.x * player_->Getrotation().Forward().x + player_->Getrotation().Right().x,
		player_->Getposition().y + mFinishCamera.y,
		player_->Getposition().z + mFinishCamera.z * player_->Getrotation().Forward().z + player_->Getrotation().Right().z);

	//�J�����̃^�[�Q�b�g�̐ݒ�
	target_ = player_->Getposition() + 10 * player_->Getrotation().Forward();
}

void ShootingTPSCamera::NextSceneType(int type)
{
	//�J���������X�Ɉ����Ă����悤�ɂ���
	mFinishCamera += Vector3::One * 0.25f;

	//�J�����̈����͈͂̐���
	mFinishCamera = Vector3::Clamp(mFinishCamera, Vector3::Zero, Vector3(100, 100, 100));

	//��x�����Q�[���N���A�A�N�^�[�̐���
	if (!malreadyCreate)
	{
		if (type == 0)
		{
			world_->add_actor(ActorGroup::GameFinishUI, new_actor<GameOverUI>(world_));
		}
		else if (type == 1)
		{
			world_->add_actor(ActorGroup::GameFinishUI, new_actor<GameClearUI>(world_));
		}
		malreadyCreate = true;
	}
}