#pragma once
#include "../Math/MathH.h"

//��{�X�̍U���̈ʒu�A�����A���Ԑݒ�N���X
class CollisionMove
{
public:
	//�����U��
	void Move1(Vector3 & pos, Matrix & rote, int time);

	//�͈�(��)�U��
	void Move2(Vector3 & pos, Matrix & rote, int time);

	//���ߍU��
	void Move3(Vector3 & pos, Matrix & rote, int time);

	//�͈�(��)�U��
	void Move4(Vector3 & pos, Matrix & rote, int time);

};