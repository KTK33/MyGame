#pragma once
#include "../Math/Vector3.h"

//敵の移動共通処理
class EnemyMove
{
public:
	void Move(Vector3 & pos, Vector3 targetpos,float speed,bool & attack,float dis);
};