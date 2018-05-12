



Actor(CopLSit)
{
		file(CopLSitHeader);
		rank(_RankSergeantL);

		startstate(StateNormal);
		startaction(Dweller1Sitting);

		ActorFlag(_or,_AFLAGnopossesion);
		ActorFlag(_or,_AFLAGnoai);
		ActorFlag(_or,_AFlagNoMove);
		ActorFlag(_or,_AFlagNoLinkUp);


		if(VSniperMode==0)
		{
			if(vstate!=statedead)
			{
				vector(_set,Gactorpos,15,10,20);
				spawnparticle(fx_flare,4,gactorpos,emptyvector,fx_coplaserflareblue);

			}
		}

			
		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatOffensive|_AIUHideLeanOutRetreat|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAFlashVisors|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,100);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		scalebonematrix(4, 5, 5, 5, _SXBoneAttRelative);

		#include	"messiahscripts\enemies\copgen.hxx"
}

Actor(DeadCopL)
{
	file(LightCopHeader);
	rank(_RankScum);

	ActorFlag(_or,_AFLAGnopossesion);
	ActorFlag(_or,_AFLAGnotarget);
	ActorFlag(_or,_AFLAGnocollision);

	startstate(StateDead);
	startaction(CopStartDead);

	if(VState!=StateDead)
	{
		Direction(_clr,_DIRalive);
		State(_or,StateDead);
	}
}




Actor(CopL)
{
		file(LightCopHeader);
		rank(_RankSergeantL);

		startstate(StateNormal);
		startaction(CopidleNoGun);

		if(VSniperMode==0)
		{
			if(vstate!=statedead)
			{
				vector(_set,Gactorpos,15,10,20);
				spawnparticle(fx_flare,4,gactorpos,emptyvector,fx_coplaserflareblue);

			}
		}

			
		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatOffensive|_AIUHideLeanOutRetreat|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,100);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		scalebonematrix(4, 5, 5, 5, _SXBoneAttRelative);

		#include	"messiahscripts\enemies\copgen.hxx"
}
