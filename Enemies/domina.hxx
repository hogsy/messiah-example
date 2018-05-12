/*
Actors:
Domina
*/


///////////////////////
///////////////////////
///////////////////////
///////////////////////
///////////////////////
///////////////////////
///////////////////////

Actor(Domina)
{
		file(DominaHeader);

		rank(_RankCommander);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,100);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(Candy)
{
		file(CandyHeader);

		rank(_RankCommander);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}



Actor(FemTest)
{
		file(FemTestHeader);

		rank(_RankCommander);

		startstate(StateNormal);
		startaction(Prost1Talk);

//		callsub(Sub_InitPossesion,Prost1Possesed);

		if(vtrigger==_DIRshoot)
		{
			state(_or,StateExecuteAnim);
			spawnaction(Prost1KungFu);
			Direction(_clr,_DIRshoot)
		}

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(GunCommander)
{
		file(guncommandHeader);

		rank(_RankCommander);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,100);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(Nun)
{
		file(nunHeader);

		rank(_RankScum);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}


Actor(dancer1)
{
		file(dancer1Header);

		rank(_RankPrivate);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(dancer2)
{
		file(dancer2Header);

		rank(_RankPrivate);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,300);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

