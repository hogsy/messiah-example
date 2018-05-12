
Actor(chot)
{
		file(chotHeader);
		rank(_RankSergeantM);

		startstate(statenormal);
//		startaction(chotidle);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);


		//XXXMsika, all this stuff should go into copai.hxx, so the states are treated the same for all classes
		if(VAIState==_AIstateChotEat && VAICon!=0)
		{
			if(Vaction!=ChotStandUpFromEat && Vaction!=ChotWalk)
			{
				spawnaction(ChotEatCop);
			}
			if(Vaction==ChotEatCop)
			{
				if(VFrame>=25 && VFrame<=28 && VRnd<50)
				{
					spawnparticle(fx_bloodspurt,3,emptyvector,emptyvector,-1);		//3 is throat
					spawnparticle(fx_bloodspray,3,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,3,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,3,emptyvector,emptyvector,-1);
				}
			}
		}

		#include	"messiahscripts\enemies\copgen.hxx"
}


Actor(chot2sp)
{
		file(chotHeader);
		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(copidleNoGun);
		//startaction(chotidle);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(chot3ct)
{
		file(chotHeader);
		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}
Actor(chot4ot)
{
		file(chotHeader);

		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}



Actor(chotMOT) // Chot w/ mask and open trench
{
		file(ChotMOTHeader);

		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(chotCT) // chot w/ closed trench
{
		file(ChotCTHeader);

		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}



Actor(chot2)
{
		file(Chot2Header);

		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(chot5)
{
		file(Chot5Header);

		rank(_RankSergeantM);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,110);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}


Actor(chotdead)
{
		file(chotHeader);
		rank(_RankSergeantM);

		startstate(statedead);
//		startaction(chotidle);
		startaction(CopStartDead);

		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnotarget);
		ActorFlag(_or,_AFLAGnocollision);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
//		float(_declare,AIControl,0);
//		float(_declare,AIHideControl,_AIHCInRoute);
//		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackOffensive|_AIUHideRetreatDefensive|_AIUHideLeanOutAttack);
//		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
//		float(_declare,AIManPowerThreshold,110);
//		float(_declare,AIPowerRatingThreshold,50);
//		float(_declare,AIGrenadeThrowThreshold,10);

		//#include	"messiahscripts\enemies\copgen.hxx"

		if(VState!=StateDead)
		{
			Direction(_clr,_DIRalive);
			State(_or,StateDead);
		}
}

