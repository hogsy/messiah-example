//non-armored/fleshy normal beast/behemoth

#define BeastMaxTurnSpeed 75
#define BeastTurnAcc 7
#define BeastMaxTurnSpeedWounded 10
#define BeastTurnAccWounded 1

#define BeastJumpSpeed 32	//14
#define BeastJumpGravity 2	//0.9

#define BeastMaxTurnSpeedair 60
#define BeastTurnAccair 5
#define BeastAirSpeed 20
#define BeastAirBulb 0.05	//0.1=very soft, 1.0=get speed immediately

#define BeastMaxFall		-2000	//Fall before he breaks his legs.
#define	DamageBeastFall	500	//Maximum, depends on altitude you fall



// beast kicking a panel

action(BeastPressButton)
{
		file("pc\actors\Behemoth\xxx\BKikLow.ske",100,on,160);	
		trigger(_allDIR);
		AIClass(_AIClassBeastSkeleton);
		nrintframes(4);
		break(off);
		connections(GenIdle);
}

action(ABeastPressButton)
{
		file("pc\actors\Behemoth\xxx\BKikLow.ske",100,on,160);	
		trigger(_allDIR);
		AIClass(_AIClassABeastSkeleton);
		nrintframes(4);
		break(off);
		connections(GenIdle);
}


SubRoutine(Sub_BeastKickCrawling)
{
//		if(vframe==1)
//		{
			state(_or,StateExecuteAnim);
//			CallSub(Sub_RandomKickedSFX);
//		}

}

action(BeastKickCrawlingLink)
{
		file("pc\actors\chot\xxx\MCrlKikU.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);//Crouch stunned
		trigger(_allDIR);
		nrintframes(4);
		ActionSubRoutine(Sub_BeastKickCrawling);
		break(off);
		connections(CopCrawlIdle,GENIdle);
}


action(BeastKickCrawling)
{
		file("pc\actors\Behemoth\xxx\BKikLow.ske",100,off,150);	//
//		file("pc\actors\Chot\xxx\MFlStmp1.ske",100,on,100);	//flying double foot stomp kick. flip to feet
//		file("pc\actors\Chot\xxx\Mkipup.ske",100,on,100);	//flying double foot stomp kick. flip to feet

		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		//flag(_SXAAalignmovingslave);

		//AlignAngle(-1);
		TargetAngle(180);
		AttackHeight(1);
		AlignSlack(360);
		AlignDistance(105);
		DistanceSlack(50);
/*
		AlignAngle(1);
		TargetAngle(180);
		AttackHeight(1);
		AlignSlack(360);
		AlignDistance(105);
		DistanceSlack(50);
*/
		AlignStartFrame(22);
		AlignNrFrames(1);

		AttachActionStartAtFrame(22);
		DamageFrame(22);
		Power(30);

		//AttachAction(GENThrownBack);
		AttachAction(BeastKickCrawlingLink);

		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Kicking);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GENIdle);
}





SubRoutine(Sub_BeastCrushHead)
{
		if(VFrame==8)
		{
			state(_or,StateDead);
			direction(_clr,_DIRalive);
			callsub(Sub_Deposses);
			sample(SFXManNeckSnap,-1);
			//if(AIAbility&=_AIAPickUpWeapon)
			//{
				call(CheckAttached,_CADropWeaponAndShells);
			//}
			scalebonematrix(4,0.001,0.001,0.001,_SXBoneAttRelative);
		}
		if(VFrame>8&&VFrame<18)
		{
			if(vrnd<75)
			{
				if(vframe<13)
				{
					spawnparticle(fx_blood,4,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,4,emptyvector,emptyvector,-1);
				}
				spawnparticle(fx_bloodspray,4,emptyvector,emptyvector,-1);
			}
		}

		if(vframe==61)
		{
			sample(SFXManFallToGround,-1);
		}
}


action(BeastCrushHeadLink)
{
		file("pc\actors\Bob\xxx\BDeath2.ske",100,off,100,_AIClassAngel);
		file("pc\actors\MultiAnm\xxx\PopHedFM.ske",100,off);
		break(off);

		ActionSubRoutine(Sub_BeastCrushHead);
		trigger(_DIRNotEndOfAnim);
		connections(BeastCrushHeadLink);
}


action(BeastCrushHead)
{
		file("pc\actors\MultiAnm\xxx\PopHedFB.ske",100,off,100);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AlignAngle(0);	//348
		TargetAngle(0);
		AttackHeight(40);
		AlignDistance(150);
		DistanceSlack(60);
		AlignSlack(360);	

		AlignStartFrame(0);
		AlignNrFrames(5);

		AttachActionStartAtFrame(0);
		DamageFrame(344);
		Power(100);
		AttachAction(BeastCrushHeadLink);
		//MasterAIClass(_AIClassChot);
		//TargetAIClass(_AIclasscop);

		MasterAIClass(_AIclassbeast);
		TargetAIClass(_AIClassAllButAngel);

//		ActionSubRoutine(Sub_EatMaleSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(0);
		connections(GenIdle);
}

SubRoutine(BeastKickingBobBSub)
{
		if(vframe==1)					//should maybe be ==0 ?
		{
			state(_or,StateThrown);
			move(0,0,-250);
			CallSub(Sub_RandomKickedSFX);
		}

}


action(BeastKickingBobBLink)
{
		file("pc\actors\Bob\xxx\BthrnFwA.ske",100,off);	//Forward hold frame
		trigger(_alldir);
		break(off);
		collision(on);
		nrintframes(0);

		ActionSubRoutine(BeastKickingBobBSub);

		connections(BobThrownForwardLand);
}


action(BeastKickingBobMiss)
{
		file("pc\actors\Behemoth\xxx\BKikLow2.ske",100,off,130);	//
		trigger(_alldir);
		break(off);
		nrintframes(0);
		connections(GENIdle);
}


action(BeastKickingBobB)
{
		file("pc\actors\Behemoth\xxx\BKikLow1.ske",100,off,160);	//

		//flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignSlack(190);
		AlignDistance(105);
		DistanceSlack(255);

		AlignStartFrame(22);
		AlignNrFrames(1);

		AttachActionStartAtFrame(22);
		//DamageFrame(25);
		//Power(10);
		//Power(10);
		AttachAction(GENIdle);
		TargetAIClass(_AIclassangel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(BeastKickingBobB2,BeastKickingBobMiss);
}

action(BeastKickingBobB2)
{
		file("pc\actors\Behemoth\xxx\BKikLow2.ske",100,off,130);	//

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignSlack(190);
		AlignDistance(105);
		DistanceSlack(255);

		AlignStartFrame(1);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		DamageFrame(3);
		Power(20);
		AttachAction(BeastKickingBobBLink);
		TargetAIClass(_AIclassangel);

		trigger(_alldir);
		break(off);
		nrintframes(0);
		connections(GenIdle);
}



SubRoutine(BeastKickingBobFSub)
{
		if(vframe==1)					//should maybe be ==0 ?
		{
			state(_or,StateThrown);
			move(0,0,300);
			CallSub(Sub_RandomKickedSFX);
		}

}


action(BeastKickingBobFLink)
{
		file("pc\actors\Bob\xxx\BthrnbkA.ske",100,off);	//Backwards hold frame
		trigger(_alldir);
		break(off);
		collision(on);
		nrintframes(0);

		ActionSubRoutine(BeastKickingBobFSub);

		connections(BobThrownBackLand);
}



action(BeastKickingBobF)
{
		file("pc\actors\Behemoth\xxx\BKikLow1.ske",100,off,160);	//

		//flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(20);
		AlignDistance(105);
		AlignSlack(190);
		DistanceSlack(255);

		AlignStartFrame(22);
		AlignNrFrames(1);

		AttachActionStartAtFrame(22);
		//DamageFrame(25);
		//Power(20);
		AttachAction(GENIdle);
		TargetAIClass(_AIclassangel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(BeastKickingBobF2,BeastKickingBobMiss);
}

action(BeastKickingBobF2)
{
		file("pc\actors\Behemoth\xxx\BKikLow2.ske",100,off,130);	//

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(20);
		AlignDistance(105);
		AlignSlack(190);
		DistanceSlack(200);

		AlignStartFrame(1);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		DamageFrame(3);
		Power(20);
		AttachAction(BeastKickingBobFLink);
		TargetAIClass(_AIclassangel);

		trigger(_AllDIR);
		break(off);
		nrintframes(0);
		connections(GenIdle);
}





action(BeastKickingB)
{
		file("pc\actors\Behemoth\xxx\BKikLow.ske",100,on,100);	//

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignDistance(100);
		AlignSlack(30);
		DistanceSlack(60);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(16);
		DamageFrame(16);
		Power(20);
		AttachAction(CopThrownForwardFromKick);
		TargetAIClass(_AIClassAllButAngel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}





action(ChotBehEatSlow)
{
		file("pc\actors\MultiAnm\xxx\2EatCpSB.ske",100,off,100);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AlignAngle(342);	//348
		TargetAngle(0);
		AttackHeight(40);
		AlignDistance(146);
		DistanceSlack(150);
		AlignSlack(180);	

		AlignStartFrame(21);
		AlignNrFrames(1);

		AttachActionStartAtFrame(21);
		DamageFrame(344);
		Power(100);
		AttachAction(CopEatenSlowLink);
		MasterAIClass(_AIClassChot);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_EatMaleSlowSFX);

		trigger(_DIRshoot);
//		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BeastIdle);
}

action(ChotBehEat)
{
		file("pc\actors\MultiAnm\xxx\2EatCpFB.ske",100,off,100);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AlignAngle(342);	//348
		TargetAngle(0);
		AttackHeight(40);
		AlignDistance(146);
		DistanceSlack(60);
		AlignSlack(180);	

		AlignStartFrame(21);
		AlignNrFrames(1);

		AttachActionStartAtFrame(21);
		DamageFrame(344);
		Power(100);
		AttachAction(CopEatenLink);
		MasterAIClass(_AIClassChot);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_EatMaleSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(0);
		connections(BeastIdle);
}

action(BouncerThrowCop)
{
		file("pc\actors\Bouncer\xxx\B_throw.ske",100,off,100);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AlignAngle(0);	//348
		TargetAngle(180);
		AttackHeight(40);
		AlignDistance(146);
		DistanceSlack(150);
		AlignSlack(180);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(50);
		Power(10);
		AttachAction(BouncerThrowCopLink);
		AIClass(_AIclassBouncer);
		TargetAIClass(_AIclasscop|_AIClasschot|_AIClassworker|_AIclassscientist|_AIclassdweller);

		ActionSubRoutine(Sub_EatMaleSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(0);
		connections(BeastIdle);
}

action(BouncerKissGirl)
{
		file("pc\actors\Bouncer\xxx\B_girl.ske",100,off,100);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AlignXYZ(-2,0,119);

		//AlignAngle(0);	//348
		TargetAngle(180);
		AttackHeight(40);
		//AlignDistance(146);
		DistanceSlack(150);
		AlignSlack(180);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(50);
		Power(0);
		AttachAction(BouncerKissGirlLink);
		MasterAIClass(_AIClassbeast);
		TargetAIClass(_AIclassfemale);

		ActionSubRoutine(Sub_EatMaleSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(0);
		connections(BeastIdle);
}


Action(BouncerBlockBar)
{
	file("pc\actors\Bouncer\xxx\B_bar1.ske",50,on);
	file("pc\actors\Bouncer\xxx\B_bar2.ske",100,on);
	
	break(off);
	trigger(_allDIR);
	nrintframes(12);
	intforloop(on);

	connections(BeastIdle);
}

Action(BouncerNoBlock)
{
	file("pc\actors\Bouncer\xxx\B_no1.ske",100,off);
	file("pc\actors\Bouncer\xxx\B_no2.ske",100,off);
	file("pc\actors\Bouncer\xxx\B_no3.ske",100,off);
	
	break(off);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(BeastIdle);
}

Action(BouncerReject)
{
	file("pc\actors\Bouncer\xxx\B_out.ske",100,off);
	
	break(off);
	trigger(_allDIR);
	nrintframes(12);
	intforloop(on);

	connections(BeastIdle);
}

Action(BouncerAngry)
{
	file("pc\actors\Bouncer\xxx\B_angry.ske",100,off);
	
	break(off);
	trigger(_allDIR);
	nrintframes(12);
	intforloop(on);

	connections(BeastIdle);
}

Action(BouncerAccept)
{
	file("pc\actors\Bouncer\xxx\B_in.ske",100,off);
	
	break(off);
	trigger(_allDIR);
	nrintframes(12);
	intforloop(on);

	connections(BeastIdle);
}




action(BeastCrouchDown)
{
		file("pc\actors\Behemoth\xxx\BCrchStr.ske",100,off);
			
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(BeastCrouchIdle);
}

action(BeastCrouchUp)
{
		file("pc\actors\Behemoth\xxx\BCrchEnd.ske",100,off);
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(BeastSpreadOut,BeastIdle);
}

action(BeastCrouchIdle)
{
		file("pc\actors\Behemoth\xxx\BCrchIdl.ske",100,on);
			
		trigger(_noDIR);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(BeastCrouchIdle,BeastSpreadOut);
}


/*
** Beast Action Animations
*/
/* *************   ******************* */



SubRoutine(Sub_BeastThrown)
{
//		move(0,-20,0);


	if(vframe==1)
	{
//		move(0,-200,0);
		state(_or,StateThrown);

		if(vaction==GenThrownBack)
		{
			move(0,0,160);
		}
		elseif(vaction==GenThrownForward)
		{
			move(0,0,-160);
		}
		elseif(vaction==GenThrownLeft)
		{
			move(160,0,0);
		}
		elseif(vaction==GenThrownRight)
		{
			move(-160,0,0);
		}
	} 
	elseif(vframe==39)
	{
		state(_clr,StateThrown);
	}


}

action(BeastThrownBack)
{
		file("pc\actors\Behemoth\xxx\BHitHrd.ske",100,off,110);
		trigger(_alldir);
		AIclass(_AIClassBeastSkeleton|_AIclassabeast);
		break(off);
		nrintframes(4);
		gravity(on);

		ActionSubRoutine(Sub_BeastThrown);

		connections(GenIdle);
}

action(BeastThrownForward)
{
		file("pc\actors\Behemoth\xxx\BHitHrd.ske",100,off,110);
		trigger(_alldir);
		AIclass(_AIClassBeastSkeleton|_AIclassabeast);
		break(off);
		nrintframes(4);
		gravity(on);

		ActionSubRoutine(Sub_BeastThrown);

		connections(GenIdle);
}

action(BeastThrownLeft)
{
		file("pc\actors\Behemoth\xxx\BHitHrd.ske",100,off,110);
		trigger(_alldir);
		AIclass(_AIClassBeastSkeleton|_AIclassabeast);
		break(off);
		nrintframes(4);
		gravity(on);

		ActionSubRoutine(Sub_BeastThrown);

		connections(GenIdle);
}

action(BeastThrownRight)
{
		file("pc\actors\Behemoth\xxx\BHitHrd.ske",100,off,110);
		trigger(_alldir);
		AIclass(_AIClassBeastSkeleton|_AIclassabeast);
		break(off);
		nrintframes(4);
		gravity(on);

		ActionSubRoutine(Sub_BeastThrown);

		connections(GenIdle);
}





action(BeastElectricShock0)
{
		file("pc\actors\Chot\xxx\aelectLP.ske",100,off,130);
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true)
		connections(GENElectricShock1);
		collision(on);
		gravity(off);
}

action(BeastElectricShock1)
{
		file("pc\actors\Chot\xxx\aelectHL.ske",100,off,130);
		move(0,0,20);
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		break(off);
		nrintframes(6);
		intforloop(off);
		nomove(true)
		connections(GENElectricShock1);
		gravity(off);
		collision(on);
}



action(BeastIdle)
{
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		nrintframes(-1);
		connections(BeastIdleCombat,BeastIdleNonCombat);
}


action(BeastIdleNonCombat)
{
		file("pc\actors\Bouncer\xxx\B_idle1.ske",50,on,100,_AIclassBouncer);
		file("pc\actors\Bouncer\xxx\B_idle2.ske",100,on,100,_AIclassBouncer);
		file("pc\actors\Behemoth\xxx\BIdle2Nc.ske",50,on);		//Noncombat, Looking Left and right
		file("pc\actors\Behemoth\xxx\BIdle1Nc.ske",100,on);	//Noncombat, Standing there and breathing
		trigger(_allDIR);


		AIclass(_AIClassBeastSkeleton);

		break(on);
		nrintframes(6);
		intforloop(on);
//		connections(BeastSpreadOut,BouncerKissGirl,BouncerThrowCop,BeastStandShoot,ChotBehEat,BeastTurnLeft,BeastTurnRight,BeastTurnLeftCombat,BeastTurnRightCombat,BeastIdle);

		//connections(BeastSpreadOut,BouncerKissGirl,BouncerThrowCop,ChotBehEat,BeastCrushHead,BeastTurnLeft,BeastTurnRight,BeastIdle);
		connections(BeastSpreadOut,BeastKickingBobF,BeastKickingBobB,BouncerKissGirl,BeastCrushHead,BeastKickCrawling,BeastKickingB,BouncerThrowCop,BeastTurnLeft,BeastTurnRight,BeastIdle);
}


action(BeastIdleCombat)
{
		file("pc\actors\Bouncer\xxx\B_idle1.ske",50,on,100,_AIclassBouncer);
		file("pc\actors\Bouncer\xxx\B_idle2.ske",100,on,100,_AIclassBouncer);
		file("pc\actors\Behemoth\xxx\BIdle1Cm.ske",100,on,100,-1,_DIRcombatmode);	//Combat, Standing there and breathing:
		trigger(_noDIR|_DIRcombatmode);

		AIclass(_AIClassBeastSkeleton);

		break(on);
		nrintframes(6);
		intforloop(on);
//		connections(BeastSpreadOut,BouncerKissGirl,BouncerThrowCop,BeastStandShoot,ChotBehEat,BeastTurnLeft,BeastTurnRight,BeastTurnLeftCombat,BeastTurnRightCombat,BeastIdle);

		//connections(BeastSpreadOut,BouncerKissGirl,BouncerThrowCop,ChotBehEat,BeastCrushHead,BeastTurnLeft,BeastTurnRight,BeastIdle);
		connections(BeastSpreadOut,BeastKickingBobF,BeastKickingBobB,BouncerKissGirl,BeastCrushHead,BeastKickCrawling,BeastKickingB,BouncerThrowCop,BeastTurnLeft,BeastTurnRight,BeastIdle);
}




Action(BeastAttentionIdle)
{
		file("pc\actors\Chot\xxx\Matnidlg.ske",100,on);
		break(on);
//		connections(BeastSpreadOut,BeastStandShoot,ChotBehEat,BeastTurnLeft,BeastTurnRight,BeastAttentionIdle);
		connections(BeastSpreadOut,BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastTurnLeft,BeastTurnRight,BeastAttentionIdle);
}

Action(BeastAttention)
{
		file("pc\actors\Chot\xxx\matnshng.ske",100,on);	//respond to attention command
		break(off);
		nrintframes(8);
		connections(BeastAttentionIdle);
}

action(BeastSpreadOut)	//Lead directly to next animation
{
		trigger(_DIRMove);
		AIclass(_AIClassBeastSkeleton);
		nrintframes(-1);
//		connections(BeastTurnLeftCombat,BeastTurnRightCombat,BeastTurnLeft,BeastTurnRight,BeastWalkDiagFL,BeastWalkDiagFR,BeastWalkDiagBL,BeastWalkDiagBR,BeastWalk,BeastWalkBack,BeastWalkL,BeastWalkR,BeastRunDiagFL,BeastRunDiagFR,BeastRunDiagBL,BeastRunDiagBR,BeastRun,BeastRunBack,BeastRunL,BeastRunR);
		connections(BeastWalkDiagFL,BeastWalkDiagFR,BeastWalkDiagBL,BeastWalkDiagBR,BeastWalk,BeastWalkBack,BeastWalkL,BeastWalkR,BeastRunDiagFL,BeastRunDiagFR,BeastRunDiagBL,BeastRunDiagBR,BeastRun,BeastRunBack,BeastRunL,BeastRunR);
}

action(BeastIdleLongTime)
{
		file("pc\actors\Chot\xxx\Macaren3.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassBeastSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
//		connections(BeastSpreadOut,BeastStandShoot,ChotBehEat,BeastTurnLeft,BeastTurnRight,BeastIdleLongTime,BeastIdle);
		connections(BeastSpreadOut,BeastCrushHead,BeastKickCrawling,BeastTurnLeft,BeastTurnRight,BeastIdleLongTime,BeastIdle);
}

action(BeastIdleHitWall)	//used just after you bounce into a wall
{
		file("pc\actors\Chot\xxx\Mneidl2p.xxx",2,on,-1,-1,Sub_RandomCopScratchesCrotch);	//ass scratch
		file("pc\actors\Chot\xxx\Mneidl3p.xxx",4,on,-1,-1,Sub_RandomCopScratchesCrotch);	//crotch scratch
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(BeastHitWallSpreadOut);
}
action(BeastHitWallSpreadOut)	//Lead directly to next animation
{
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		nrintframes(-1);
		connections(BeastHitWallStandShoot,BeastHitWallTurnLeft,BeastHitWallTurnRight,BeastIdleHitWall);
}

action(BeastIdleHitWallFront)	//used just after you bounce into a wall, face first
{
//MISSING Animation
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(BeastHitWallStandShoot,BeastHitWallTurnLeft,BeastHitWallTurnRight,BeastIdleHitWallFront);
}

action(BeastTurnLeftRightEnd)
{
		file("pc\actors\Behemoth\xxx\BTrStpCm.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BTrStpNc.ske",100,off,100);
		trigger(_DIRnotendofanim|_noDIR);
		break(on);
		nrintframes(4);
		intforloop(off);
		connections(BeastTurnRight,BeastTurnLeft,BeastIdle);
}

action(BeastTurnLeft)
{
//		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		file("pc\actors\Behemoth\xxx\BTrLStCm.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BTrLLpCm.ske",100,on,100,-1,_DIRcombatmode);

		file("pc\actors\Behemoth\xxx\BTrLStNc.ske",100,off);
		file("pc\actors\Behemoth\xxx\BTrLLpNc.ske",100,on);
//		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
//		connections(BeastSpreadOut,BeastStandShoot,ChotBehEat,BeastTurnLeft,BeastTurnRight,BeastTurnLeftRightEnd,BeastIdle);
		connections(BeastSpreadOut,BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastTurnLeft,BeastTurnRight,BeastTurnLeftRightEnd,BeastIdle);
}

action(BeastTurnRight)
{
//		file("pc\actors\Chot\xxx\mtrnrt2.ske",100,on);
		file("pc\actors\Behemoth\xxx\BTrRStCm.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BTrRLpCm.ske",100,on,100,-1,_DIRcombatmode);

		file("pc\actors\Behemoth\xxx\BTrRStNc.ske",100,off);
		file("pc\actors\Behemoth\xxx\BTrRLpNc.ske",100,on);
//		move(-2,0,0);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
//		connections(BeastSpreadOut,BeastStandShoot,ChotBehEat,BeastTurnLeft,BeastTurnRight,BeastIdle);
		connections(BeastSpreadOut,BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastTurnLeft,BeastTurnRight,BeastIdle);
}

action(BeastTurnLeftRightEndCombat)
{
		file("pc\actors\Behemoth\xxx\BTrStpCm.ske",100,off,100);
		trigger(_DIRnotendofanim|_noDIR);
		break(on);
		nrintframes(4);
		intforloop(off);
		connections(BeastTurnRightCombat,BeastTurnLeftCombat,BeastIdle);
}

action(BeastTurnLeftCombat)
{
//		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		file("pc\actors\Behemoth\xxx\BTrLStCm.ske",100,off);
		file("pc\actors\Behemoth\xxx\BTrLLpCm.ske",100,on);
//		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(BeastSpreadOut,BeastStandShoot,BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastTurnLeftCombat,BeastTurnRightCombat,BeastTurnLeftRightEndCombat,BeastIdle);
}

action(BeastTurnRightCombat)
{
//		file("pc\actors\Chot\xxx\mtrnrt2.ske",100,on);
		file("pc\actors\Behemoth\xxx\BTrRStCm.ske",100,off);
		file("pc\actors\Behemoth\xxx\BTrRLpCm.ske",100,on);
//		move(-2,0,0);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(BeastSpreadOut,BeastStandShoot,BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastTurnLeftCombat,BeastTurnRightCombat,BeastIdle);
}

action(BeastHitWallTurnLeft)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(BeastHitWallSpreadOut);
}

action(BeastHitWallTurnRight)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(-2,0,0)
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(BeastHitWallSpreadOut);
}


/* *************   Standard moves with gun ******************* */

/* *************   Standard moves without gun ******************* */


action(BeastWalk)
{
		file("pc\actors\Behemoth\xxx\BWlkFw.ske",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);

		nrintframes(8);
		intforloop(off);
		offset(36);
		connections(BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastSpreadOut,BeastIdle);
}

action(BeastWalkBack)
{
		file("pc\actors\Behemoth\xxx\BWlkb.ske",100,on);
		
		nrintframes(8);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(13);
		connections(BeastSpreadOut,BeastIdle);
}

action(BeastWalkL)
{
		file("pc\actors\Behemoth\xxx\BWlkL.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(36);
		connections(BeastSpreadOut,BeastIdle);
}

action(BeastWalkR)
{
		file("pc\actors\Behemoth\xxx\BWlkR.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(36);
		connections(BeastSpreadOut,BeastIdle);
}

action(BeastWalkDiagFL)
{
		file("pc\actors\Behemoth\xxx\BWlkFL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		offset(36)
		connections(BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastSpreadOut,BeastIdle);
}

action(BeastWalkDiagFR)
{
		file("pc\actors\Behemoth\xxx\BWlkFr.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		offset(36)
		connections(BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastSpreadOut,BeastIdle);
}

action(BeastWalkDiagBL)
{
		file("pc\actors\Behemoth\xxx\BWlkBL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(13);
		nrintframes(8);
		connections(BeastSpreadOut,BeastIdle);
}
action(BeastWalkDiagBR)
{
		file("pc\actors\Behemoth\xxx\BWlkBR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(13);
		nrintframes(8);
		connections(BeastSpreadOut,BeastIdle);
}


action(BeastRun)
{
		file("pc\actors\behemoth\xxx\brunf.ske",100,on);

		offset(16);
		nrintframes(8);
		intforloop(off);

		trigger(_DIRforward);
		break(on);
		connections(BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastSpreadOut,BeastIdle);
}
action(BeastRunBack)
{
		file("pc\actors\behemoth\xxx\brunb.ske",100,on);
		nrintframes(8);
		trigger(_DIRbackward);
		break(on);
		offset(8);
		connections(BeastSpreadOut,BeastIdle);
}

action(BeastRunL)
{
		file("pc\actors\behemoth\xxx\brunl.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideleft);
		break(on);
		offset(16)
		connections(BeastSpreadOut,BeastIdle);
}
action(BeastRunR)
{
		file("pc\actors\behemoth\xxx\brunr.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideright);
		break(on);
		offset(16)
		connections(BeastSpreadOut,BeastIdle);
}
action(BeastRunDiagFL)
{
		file("pc\actors\behemoth\xxx\brunfl.ske",100,on);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(16)
		nrintframes(8);
		connections(BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastSpreadOut,BeastIdle);
}
action(BeastRunDiagFR)
{
		file("pc\actors\behemoth\xxx\brunfr.ske",100,on);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(16)
		nrintframes(8);
		connections(BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastSpreadOut,BeastIdle);
}

action(BeastRunDiagBL)
{
		file("pc\actors\behemoth\xxx\brunbl.ske",100,on);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		nrintframes(8)
		offset(8)
		connections(BeastSpreadOut,BeastIdle);
}

action(BeastRunDiagBR)
{
		file("pc\actors\behemoth\xxx\brunbr.ske",100,on);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(8)
		nrintframes(8);
		connections(BeastSpreadOut,BeastIdle);
}

/* *************   Jump And Fall ******************* */



action(BeastJump)	//Lead directly to next animation
{
		trigger(_DIRjump);
		AIclass(_AIClassBeastSkeleton);
		nrintframes(-1);
		connections(BeastJumpBL,BeastJumpBR,BeastJumpBackwards,BeastJumpFL,BeastJumpL,BeastJumpFR,BeastJumpR,BeastJumpForward,BeastJumpInPlace);
}


action(BeastJumpInPlace)
{
		file("pc\actors\Behemoth\xxx\BJmpUSt.ske",100,off);
		trigger(_DIRjump);
		nrintframes(0);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BeastFallInplace);
}

action(BeastJumpForward)
{
		file("pc\actors\Behemoth\xxx\BJmpFSt.ske",100,off);
		trigger(_DIRforward);
		nrintframes(0);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BeastFallForward);
}

action(BeastJumpL)
{
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRsideleft);
		rotate(-90)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BeastFallL);
}

action(BeastJumpFL)
{
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRsideleft|_DIRforward);
		rotate(-45)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BeastFallFL);
}
action(BeastJumpR)
{
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRsideright);
		rotate(90)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BeastFallR);
}

action(BeastJumpFR)
{
		file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRsideright|_DIRforward);
		rotate(45)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BeastFallFR);
}

action(BeastJumpBackwards)
{
		file("pc\actors\Behemoth\xxx\BJmpBSt.ske",100,off);
		trigger(_DIRbackward);
		nrintframes(0);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BeastFallBackwards);
}

action(BeastJumpBR)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideright);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(-45)
		ydeltafromzeroframe(off);
		connections(BeastFallBR);
}

action(BeastJumpBL)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideleft);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(45)
		ydeltafromzeroframe(off);
		connections(BeastFallBL);
}

action(BeastfallForward)
{
		file("pc\actors\Behemoth\xxx\BJmpFLCm.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BJmpFLNc.ske",100,off);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(off);
		connections(BeastfallForward);
}

action(BeastfallFL)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(BeastfallFL);
}
action(BeastfallFR)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(BeastfallFR);
}
action(BeastfallL)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-90)
		connections(BeastfallL);
}
action(BeastfallR)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(90)
		connections(BeastfallR);
}

action(BeastfallInPlace)
{
		file("pc\actors\Behemoth\xxx\BJmpULCm.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BJmpULNc.ske",100,on);

		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(off);
		connections(BeastfallInPlace);
}

action(BeastfallBackwards)
{
		file("pc\actors\Behemoth\xxx\BJmpLBCm.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BJmpLBNc.ske",100,on);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(BeastfallBackwards);
}
action(BeastfallBL)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(BeastfallBL);
}
action(BeastfallBR)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(BeastfallBR);
}

action(Beastfall)	//Fall when falling from edge only
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
		trigger(_AllDir);
		AIclass(_AIClassBeastSkeleton);
		nrintframes(7);
		offset(8);
		ydeltafromzeroframe(off);
		break(off);
		connections(BeastFall);
}

action(BeastTouchDown)
{
		file("pc\actors\Abeast\xxx\AbJmpL.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassBeastSkeleton);
		nrintframes(5);
		break(on);

		ActionSubRoutine(Sub_HeavyLand);

		connections(BeastSpreadOut,BeastTouchDown,BeastIdle);
}

/* *************   Other Moves ******************* */

action(BeastStomp)
{
		file("pc\actors\abeast\xxx\Mbestmp2.ske",100,off);
		trigger(_DIRjump);
		break(off);
		connections(Beastidle);
}


action(BeastShot)
{
		file("pc\actors\abeast\xxx\mspan13.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(off);
		//connections(BeastShot);
		connections(Beastidle);
}


action(BeastPunch)
{
		file("pc\actors\abeast\xxx\Mbegrnd.ske",100,off);
		trigger(_allDIR);
		connections(Beastidle);
}

action(BeastStandShoot)
{
		//file("pc\actors\abeast\xxx\mspan13.xxx",100,on);
		file("pc\actors\Abeast\xxx\MbFrM1.ske",33,on);
		file("pc\actors\Abeast\xxx\MbFrM2.ske",66,on);
		file("pc\actors\Abeast\xxx\MbFrM3.ske",100,on);
		trigger(_DIRshoot|_DIRhavegun);
		break(off);
		connections(BeastStandShoot,BeastKickingBobF,BeastKickingBobB,BeastCrushHead,BeastKickCrawling,BeastTurnLeft,BeastTurnRight,BeastTurnLeftCombat,BeastTurnRightCombat,BeastIdle);
}

action(BeastHitWallStandShoot)
{
		file("pc\actors\chot\xxx\Mfire3h2.ske",100,on);
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		connections(BeastHitWallSpreadOut);
}

action(BeastPossesed)
{
		file("pc\actors\Abeast\xxx\mblprosp.ske",100,off,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		break(off);
		connections(Beastidle);
}
action(BeastDepossesed)
{
		file("pc\actors\chot\xxx\Mstun1g.ske",50,on,100,-1,-1,Sub_ClrThrownFlag);
		file("pc\actors\chot\xxx\Mstun2g.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);
		nrintframes(4);
		break(off);
		connections(Beastidle);
}


/* *************   Wounded ******************* */

action(BeastWoundLight)
{
		file("pc\actors\Behemoth\xxx\BWnd1Cm.ske",25,off,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd2Cm.ske",50,off,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd3Cm.ske",75,off,100,-1,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,-1,_DIRcombatmode);

		file("pc\actors\Behemoth\xxx\BWnd1Nc.ske",25,off);
		file("pc\actors\Behemoth\xxx\BWnd2Nc.ske",50,off);
		file("pc\actors\Behemoth\xxx\BWnd3Nc.ske",75,off);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off);

		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassBeastSkeleton);
		break(on);
		collision(on);
		nrintframes(4);
//		connections(BeastSpreadOut,BeastStandShoot,ChotBehEat,BeastWoundLight,BeastTurnLeft,BeastTurnRight,BeastIdle);
		connections(BeastSpreadOut,BeastKickingBobF,BeastKickingBobB,BeastWoundLight,BeastTurnLeft,BeastTurnRight,BeastIdle);
}

action(BeastWoundLightNoBreak)	//Identical to the one above except for break
{
		file("pc\actors\Chot\xxx\FstWnd1.ske",10,off);
		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
		//file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassBeastSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
//		connections(BeastSpreadOut,BeastStandShoot,BeastWoundLight,BeastTurnLeft,BeastTurnRight,BeastIdle);
		connections(BeastSpreadOut,BeastKickingBobF,BeastKickingBobB,BeastWoundLight,BeastTurnLeft,BeastTurnRight,BeastIdle);
}

/* *************   Burned, steamed and blind ******************* */


subroutine(Sub_BeastStandDead)
{
		if(vframe==50&&VActionIndex==0)
		{
			sample(SFXManFallToGround,-1);
			call(ScreenShake,0,16,0,0.5);
		}
		elseif(vframe==77&&VActionIndex==1)
		{
			sample(SFXManFallToGround,-1);
			call(ScreenShake,0,16,0,0.5);
		}
}

action(BeastStandDead)
{
		file("pc\actors\Behemoth\xxx\Bdeth2.ske",50,off);	//Sway and fall to back
		file("pc\actors\Behemoth\xxx\Bdeth1.ske",100,off);	//Sway and fall to face
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);

		ActionSubRoutine(Sub_BeastStandDead);
		
		break(off);
		nrintframes(12);
}
action(BeastFallDead)
{
		file("pc\actors\Behemoth\xxx\Bdeth2.ske",50,off);	//Sway and fall to back
		file("pc\actors\Behemoth\xxx\Bdeth1.ske",100,off);	//Sway and fall to face
		trigger(_allDIR);
		AIclass(_AIClassBeastSkeleton);

		ActionSubRoutine(Sub_BeastStandDead);
		
		break(off);
		nrintframes(12);
}

/*
	Abeast Fire machine gun:
		Fires 6 bullets a second, one every 5th frame. 
		The animations should be played randomly:
			Abeast\prj\Handanim\MbFrM1.3ds
			Abeast\xxx\MbFrM1.ske

			Abeast\prj\Handanim\MbFrM2.3ds
			Abeast\xxx\MbFrM2.ske

			Abeast\prj\Handanim\MbFrM3.3ds
			Abeast\xxx\MbFrM3.ske

		Hold frame:
			Abeast\prj\Handanim\MbFrM0.3ds
			Abeast\xxx\MbFrM0.ske
*/

