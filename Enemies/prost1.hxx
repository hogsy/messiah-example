/*
Actors:
Prost1
Hung
SubGirl1
SubGirl2
Layya
*/

///////////////////////
///////////////////////
///////////////////////
///////////////////////
///////////////////////
///////////////////////
///////////////////////

Actor(VictimFeMale)
{
		file(VictimFeMaleHeader);
		rank(_RankScum);

		startstate(statenormal);
		startaction(copidleNoGun);

		ActorFlag(_or,_AFlagNoAi);

		//BELOW : just in case the victim has to follow a path, here's the script. BUT DON 'T
		//UNCOMMENT IT OUT before talking to Msika first.
		
		/*
		if(vaicon!=0)
		{
			Direction(_clr,_DIRaiRemoveFlags);

			call(AIPickdest,10);
			if(vtrigger==_DIRtempflag)
			{
				call(PickNewNode);
			}
			CallSub(Sub_AI1WayAlignToPickDestAngle);
			if(VTrigger==_DIRleft)
			{
				turn(0,-40,0);
			}
			elseif(VTrigger==_DIRright)
			{
				turn(0,40,0);
			}
			if(vpickdestanglecorr>512 || vpickdestanglecorr<-512)	//might need bigger numbers
			{
				direction(_set,_DIRForward);
			}
			else
			{
				move(0,0,-10);
			}
		}
		*/
		callsub(BackGroundTriggerChecks);
}

Actor(prost1)
{
		file(ProstituteHeader);
		rank(_RankScum);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAClimb|_AIAJump|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(prost1Sit)
{
		file(prost1sitHeader);
		rank(_RankScum);

		startstate(statenormal);
		startaction(female1sitting);
		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnoai);
		ActorFlag(_or,_AFlagNoMove);
		ActorFlag(_or,_AFlagNoLinkUp);


		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAClimb|_AIAJump|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(hung)
{
		file(HungHeader);
		rank(_RankScum);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAClimb|_AIAJump|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(subgirl1)
{
		file(subgirl1Header);

		rank(_RankCommander);

		startstate(statenormal);
		//startaction(SubGirlIdleNoGun);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUAdvanceIfEnemyUnseen|_AIUAlwaysRun);
		float(_declare,AIAbility,_AIAJump|_AIANoCrouch|_AIANoCrawl|_AIANoBoneCollision);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		if(VActiveTime==0)
		{
			//call(AttachToActor,WeaponSubGirlRocketPack,2);
			call(AttachToActor,WeaponSubGirlMachineGun,7);
			direction(_or,_DIRhavegun);
		}

		#include	"messiahscripts\enemies\copgen.hxx"

		if(vtrigger!=_DIRwalking&&vtrigger==_DIRleft||vtrigger==_DIRright||vtrigger==_DIRforward||vtrigger==_DIRbackward||vtrigger==_DIRsideleft||vtrigger==_DIRsideright)
		{
			vector(_set,gactorine,0,1,0);
			spawnparticle(fx_subgirlthruster,18,emptyvector,gactorine,-1);
			spawnparticle(fx_subgirlthruster,22,emptyvector,gactorine,-1);
		}

		if(vtrigger==_DIRjump)
		{
			vector(_set,gactorine,0,2,0);
			spawnparticle(fx_subgirlthrusterjump,18,emptyvector,gactorine,-1);
			spawnparticle(fx_subgirlthrusterjump,22,emptyvector,gactorine,-1);
		}
}

Actor(subgirl2)
{
		file(subgirl2Header);

		rank(_RankCommander);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUAdvanceIfEnemyUnseen|_AIUAlwaysRun);
		float(_declare,AIAbility,_AIAJump|_AIANoCrouch|_AIANoCrawl|_AIANoBoneCollision);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		if(VActiveTime==0)
		{
			//call(AttachToActor,WeaponSubGirlPack,2);
			call(AttachToActor,WeaponSubGirlMachineGun,7);
			direction(_or,_DIRhavegun);
		}

		#include	"messiahscripts\enemies\copgen.hxx"

		if(vtrigger!=_DIRwalking&&vtrigger==_DIRleft||vtrigger==_DIRright||vtrigger==_DIRforward||vtrigger==_DIRbackward||vtrigger==_DIRsideleft||vtrigger==_DIRsideright)
		{
			vector(_set,gactorine,0,1,0);
			spawnparticle(fx_subgirlthruster,18,emptyvector,gactorine,-1);
			spawnparticle(fx_subgirlthruster,22,emptyvector,gactorine,-1);
		}

		if(vtrigger==_DIRjump)
		{
			vector(_set,gactorine,0,2,0);
			spawnparticle(fx_subgirlthrusterjump,18,emptyvector,gactorine,-1);
			spawnparticle(fx_subgirlthrusterjump,22,emptyvector,gactorine,-1);
		}
}

Actor(Layya)
{
		file(LayyaHeader);

		rank(_RankScum);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}


Actor(prost2)
{
		file(prozzyHeader);
		rank(_RankScum);

		startstate(statenormal);
		startaction(Prost1IdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAClimb|_AIAJump|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}


Actor(pimp)
{
		file(pimpHeader);

		rank(_RankScum);

		startstate(statenormal);
		startaction(CopIdleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatDefensive|_AIUSurrender|_AIUAttackIfUnseen);
		float(_declare,AIAbility,_AIAClimb|_AIAJump|_AIAHideWeapon|_AIAPickUpWeapon);
		float(_declare,AIManPowerThreshold,1);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);


		if(VAICon!=0)
		{
			if(VAIState==_AIstateWork)
			{
				if(VAction!=PimpConsole)
				{
					SpawnAction(PimpConsole);
				}
			}
		}


		#include	"messiahscripts\enemies\copgen.hxx"
}

