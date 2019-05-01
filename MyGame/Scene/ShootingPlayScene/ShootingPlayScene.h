#pragma once
#include"../Scene.h"
#include"../World/World.h"
#include "../Menu.h"

//���\�[�X�ǂݍ��ݐ�p�V�[��
class ShootingPlayScene :public Scene,public Menu{
public:

	ShootingPlayScene();

	void start()override;
	void update(float deltaTime) override;
	void draw()const override;
	void end()override;

private:
	World world_;

	bool BossArleady;
};