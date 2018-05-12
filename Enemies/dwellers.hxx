

Actor(Dweller1) 
{
		file(Dweller1Header);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(Dweller1Sit) 
{
		file(Dweller1SitHeader);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(Dweller1Sitting);
		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnoai);
		ActorFlag(_or,_AFlagNoMove);
		ActorFlag(_or,_AFlagNoLinkUp);



		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

//		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(Dweller2) 
{
		file(Dweller2Header);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(Dweller2Sit) 
{
		file(Dweller2SitHeader);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(Dweller2Sitting);
		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnoai);
		ActorFlag(_or,_AFlagNoMove);
		ActorFlag(_or,_AFlagNoLinkUp);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

//		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(Dweller3) 
{
		file(Dweller3Header);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(Dweller3Sit) 
{
		file(Dweller3SitHeader);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(Dweller3Sitting);
		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnoai);
		ActorFlag(_or,_AFlagNoMove);
		ActorFlag(_or,_AFlagNoLinkUp);


		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

//		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(FemDweller1) 
{
		file(FemDweller1Header);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(FemDweller2) 
{
		file(FemDweller2Header);
		rank(_RankPrivate);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAHideWeapon|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}


