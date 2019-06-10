#include "AttackChoice.h"
#include "../Game/Define.h"
#include "../Math/Random.h"

int AttackChoice::AttackType(int BigHP)
{
	float HP3par = BigBossHPVal * 0.3f;
	float HP5par = BigBossHPVal * 0.5f;

	int type = Random::rand(0, 100);

	if (BigHP <= HP3par)//HPªRÈºÈç
	{
		//UÌm¦
		int AttackTypePar[4] = { 0,20,30,50 };

		return (Attack(type, AttackTypePar[0], AttackTypePar[1], AttackTypePar[2]));
	}
	else if(BigHP <= HP5par)//HPªTÈºÈç
	{
		//UÌm¦
		int AttackTypePar[4] = { 20,40,40,0 };

		return (Attack(type, AttackTypePar[0], AttackTypePar[1], AttackTypePar[2]));
	}
	else
	{
		//UÌm¦
		int AttackTypePar[4] = { 60,40,0,0 };

		return (Attack(type, AttackTypePar[0], AttackTypePar[1], AttackTypePar[2]));
	}
}

int AttackChoice::Attack(int type, int a1, int a2,int a3)
{
	//if (type <= a1)
	//{
	//	return 1;
	//}
	//else if (type <= a1 + a2)
	//{
	//	return 2;
	//}
	//else if(type <= a1 + a2 + a3)
	//{
	//	return 3;
	//}
	//else
	//{
	//	return 4;
	//}

	return 1;
}