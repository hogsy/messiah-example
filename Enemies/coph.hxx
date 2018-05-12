
Actor(CopH)
{
		file(HeavyCopHeader);
		rank(_RankSergeantH);

		startstate(StateNormal);
		startaction(copidleNoGun);

		if(VTrigger==_DIRcombatmode)
		{
			vector(_set,GActorPos,0,0,-300);
			vector(_multiplywithtransmat,GActorPos,GActorPos);
			vector(_set,TmpVector,128,128,255);
			spawnlight(HeavyCopSearchLight,-1,Gactorpos,TmpVector,EmptyVector,500);

			if(VSniperMode==0)
			{
				if(vstate!=statedead)
				{
					vector(_set,Gactorpos,15,10,20);
					spawnparticle(fx_flare,4,gactorpos,emptyvector,fx_heavycoplaserflare);
					vector(_set,Gactorpos,-25,10,0);
					spawnparticle(fx_flare,4,gactorpos,emptyvector,fx_heavycoplaserflare);
				}
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

		#include	"messiahscripts\enemies\copgen.hxx"
}




Actor(CopR)
{
		file(RiotCopHeader);
		rank(_RankSergeantH);

		startstate(StateNormal);
		startaction(copidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUCrouchToDefend);	//_AIUAdvanceUsingPath|_AIUCrouchToDefend);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAFlashVisors|_AIAShield|_AIAUseHitWallCode);	//|_AIAFakeWeapon);
		float(_declare,AIManPowerThreshold,100);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);

		#include	"messiahscripts\enemies\copgen.hxx"
}




Actor(djkyd)
{
		file(djkydHeader);
		rank(_RankPrivate);
		startstate(StateNormal);
		startaction(copidleNoGun);

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




Actor(victimmale)
{
		file(VictimMaleHeader);
		rank(_RankSergeantH);

		startstate(StateNormal);
		startaction(VictimIdle);

		actorflag(_or,_AFLAGnobulletcollision);
		
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



