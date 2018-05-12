
Actor(CopM)
{
		file(MedCopHeader);
		rank(_RankSergeantM);

		startstate(StateNormal);
		startaction(CopidleNoGun);

		//AI variables. All characters using copgen.hxx needs these defined to work properly
		float(_declare,AIControl,0);
		float(_declare,AIHideControl,_AIHCInRoute);
		float(_declare,AIUsage,_AIUHideForRetreat|_AIUHideForAttack|_AIUHideAttackDefensive|_AIUHideRetreatOffensive|_AIUHideLeanOutRetreat|_AIUHideLeanOutAttack);
		float(_declare,AIAbility,_AIAJump|_AIAClimb|_AIAPickUpWeapon|_AIAUseHitWallCode);
		float(_declare,AIManPowerThreshold,100);
		float(_declare,AIPowerRatingThreshold,50);
		float(_declare,AIGrenadeThrowThreshold,10);


		float(_declare,laservisorstate,0);
		float(_declare,laservisoroffset,0);
		float(_declare,blendingmodesset,0);


		if(VTrigger==_DIRdepossesion || VOTrigger==_DIRdepossesion)
		{
			call(ClearBlendingModeChanges);
			float(_set,blendingmodesset,0);
		}


		#include	"messiahscripts\enemies\copgen.hxx"

		//only this dude has visor laser
		if(vstate==statedead)
		{
			float(_set,laservisorstate,0);
			float(_set,laservisoroffset,0);
			if(blendingmodesset==1)
			{
				call(ClearBlendingModeChanges);
				float(_set,blendingmodesset,0);
			}
		}

		//printi("Copm:  vsnipermode:   ",VSniperMode);

		if(VSniperMode==0)
		{
			if(laservisorstate==0 && vtrigger==_DIRcombatmode && vtrigger==_DIRhavegun)
			{
				sample(SFXLaserStart1,-1);

				float(_set,laservisorstate,32);
				float(_set,laservisoroffset,0);
			}
			elseif(laservisorstate>0)
			{
				if(vtrigger!=_DIRcombatmode)
				{
					//float(_sub,laservisorstate,1);

					float(_set,laservisorstate,0);
					float(_set,laservisoroffset,0);
					sample(SFXLaserOff1,-1);
				}

				vector(_set,Gactorpos,-24,10,0);
				spawnparticle(fx_flare,4,gactorpos,emptyvector,fx_coplaserflarered);
				float(_add,laservisoroffset,64);
				if(laservisoroffset>=1024)
				{
					float(_set,laservisoroffset,1024);
				}

				vector(_set,gactorine,0,0,0);
				float(_set,tmpfloat,-1024);
				vector(_setx,gactorine,tmpfloat);
				//float(_copy,tmpfloat,laservisoroffset);
				//float(_mul,tmpfloat,-1);
				//vector(_setx,gactorine,tmpfloat);
				float(_set,tmpfloat,192);
				vector(_sety,gactorine,tmpfloat);
				vector(_setz,gactorine,laservisoroffset);

				vector(_set,Gactorpos,-24,10,0);
				spawnparticle(fx_coplaser,4,gactorpos,gactorine,-1);

//				print("laser visor state:   ",laservisorstate);
//				print("laser visor offset:   ",laservisoroffset);

				call(wCheckViewCollision,4,gactorpos,gactorine,-1);

				if(laservisorstate==16)
				{
					sample(SFXLaserOff1,-1);
				}
				if(laservisorstate<=16)
				{
					float(_sub,laservisoroffset,128);
				}

			}
			if(VOSniperMode!=0)
			{
				call(ClearBlendingModeChanges);
				float(_set,blendingmodesset,0);
			}
		}
		else
		{
			//In sniper mode. Turn on xray vision
			call(XRayModeController);
			float(_set,blendingmodesset,1);
		}

}

Actor(DeadCopM)
{
	file(MedCopHeader);
	rank(_RankScum);

	float(_declare,laservisorstate,0);
	float(_declare,laservisoroffset,0);

	ActorFlag(_or,_AFLAGnopossesion);
	ActorFlag(_or,_AFLAGnotarget);

	startstate(StateDead);
	startaction(CopStartDead);

	if(VState!=StateDead)
	{
		Direction(_clr,_DIRalive);
		State(_or,StateDead);
	}
}




										 