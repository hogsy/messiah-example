#define Prost1MaxTurnSpeed 75
#define Prost1TurnAcc 7
#define Prost1MaxTurnSpeedWounded 10
#define Prost1TurnAccWounded 1

#define Prost1JumpSpeed			14
#define Prost1JumpGravity		0.9
#define Prost1MinHoldJumpAction	3

#define Prost1RunAccel 2
#define Prost1RunAccelDiag 1

#define Prost1MaxTurnSpeedair 60
#define Prost1TurnAccair 5
#define Prost1AirSpeed 20
#define Prost1AirBulb 0.05	//0.1=very soft, 1.0=get speed immediately

#define Prost1MaxFall		-500	//Fall before he breaks his legs.
#define	DamageProst1Fall	500	//Maximum, depends on altitude you fall


#define SubGirlMaxTurnSpeed 75
#define SubGirlTurnAcc 7
#define SubGirlMaxTurnSpeedWounded 10
#define SubGirlTurnAccWounded 1

#define SubGirlJumpSpeed			14
#define SubGirlJumpGravity		0.9
#define SubGirlMinHoldJumpAction	3

#define SubGirlMaxTurnSpeedair 60
#define SubGirlTurnAccair 5
#define SubGirlAirSpeed 20
#define SubGirlAirBulb 0.05	//0.1=very soft, 1.0=get speed immediately

#define SubGirlMaxFall		-500	//Fall before he breaks his legs.
#define	DamageSubGirlFall	500	//Maximum, depends on altitude you fall



#define Prost1JumpSpeedHigh	0
#define Prost1JumpSpeedMiddle	1
#define Prost1JumpSpeedLow		9


#define SubGirlJumpSpeedHigh	8
#define SubGirlJumpSpeedMiddle	10
#define SubGirlJumpSpeedLow		12



action(Prost1BumpedGeneric)
{
		file("pc\actors\Prost1\xxx\FBumpdG.ske",100,off);
		//file("pc\actors\Chot\xxx\MTk1Gst2.ske",100,on);	// Quick Talk Gesture
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassProstSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
		connections(Prost1Spread,Prost1StandShoot,Prost1BumpedGeneric,Prost1TurnLeft,Prost1TurnRight,Prost1Idle);
}


action(Prost1BackwardStompKickF)
{
		file("pc\actors\Chot\xxx\MRBkSpnK.ske",100,on,100);	//flying spinning back heel kick


		flag(_SXAAalignmovingslave);

		AlignAngle(180);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(9);
		DamageFrame(9);
		Power(10);
		AttachAction(GENThrownBack);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Kicking);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}

action(Prost1BackwardStompKickB)
{
		file("pc\actors\Chot\xxx\MRBkSpnK.ske",100,on,100);	//flying spinning back heel kick

		flag(_SXAAalignmovingslave);

		AlignAngle(180);
		TargetAngle(180);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(9);
		DamageFrame(9);
		Power(10);
//		AttachAction(Prost1StompKickFLink);
		AttachAction(CopThrownForwardFromKick);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Kicking);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}



action(Prost1GunButBob)
{
		file("pc\actors\MultiAnm\xxx\DmGunBut.ske",100,on,100);	//Female Gun Butt

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(70);
		AlignDistance(100);
		AlignSlack(40);
		DistanceSlack(40);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(2);
		AttachAction(BobThrownBack);
		TargetAIClass(_AIclassangel);

//		ActionSubRoutine(Sub_RandomPunchedSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}

action(Prost1KickingBobMiss)
{
		file("pc\actors\Chot\xxx\MWrKikL2.ske",100,off,130);	//
		trigger(_alldir);
		break(off);
		nrintframes(0);
		connections(GENIdle);
}

action(Prost1KickingBobF)
{
		file("pc\actors\Chot\xxx\MWrKikL1.ske",100,off,150);	//

		//flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		//DamageFrame(20);
		//Power(10);
		AttachAction(GENIdle);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

//		ActionSubRoutine(Sub_RandomKickedSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(Prost1KickingBobF2,Prost1KickingBobMiss);
}

action(Prost1KickingBobF2)
{
		file("pc\actors\Chot\xxx\MWrKikL2.ske",100,off,130);	//

		//flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		DamageFrame(5);
		Power(10);
		AttachAction(BobThrownBack);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

//		ActionSubRoutine(Sub_RandomKickedSFX);

		trigger(_alldir);
		break(off);
		nrintframes(0);
		connections(Prost1Idle);
}

action(Prost1KickingBobB)
{
		file("pc\actors\Chot\xxx\MWrKikL1.ske",100,off,150);	//

		//flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		//DamageFrame(20);
		//Power(10);
		AttachAction(GENIdle);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

//		ActionSubRoutine(Sub_RandomKickedSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(Prost1KickingBobB2,Prost1KickingBobMiss);
}

action(Prost1KickingBobB2)
{
		file("pc\actors\Chot\xxx\MWrKikL2.ske",100,off,130);	//

		//flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(50);


		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		DamageFrame(5);
		Power(10);
		AttachAction(BobThrownForwardLandAttached);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

//		ActionSubRoutine(Sub_RandomKickedSFX);

		trigger(_AllDIR);
		break(off);
		nrintframes(0);
		connections(Prost1Idle);
}


action(Prost1Kicking)
{
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//Kicking Crawling Guy

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(-1);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(50);


		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(15);
		DamageFrame(16);
		Power(10);
		AttachAction(CopKickingLink);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

//		ActionSubRoutine(Sub_RandomKickedSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(Prost1Idle);
}

action(Prost1StompKickFLink)
{
//		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Bob\xxx\BthrnbkA.ske",100,off,100,_AIclassangel);	//Backwards hold frame
		file("pc\actors\MultiAnm\xxx\ChRnSlmL.ske",100,off,180);	//Left land on face
		trigger(_alldir);
		break(off);
		nrintframes(4);
		ActionSubRoutine(Sub_SetAttackerToEnemyAndHandleThrown);

		//Move(5,0,0);
		//ActionSubRoutine(Sub_SetThrown);
		connections(BeastIdle,GENThrownLeft);
}

action(Prost1StompKickF)
{
		file("pc\actors\Chot\xxx\MSpinKk2.ske",100,on,100);	//flying spinning back heel kick


		AIClass(_AIclassfemale|_AIclasscop|_AIclassdweller);
		
		flag(_SXAAalignmovingslave|_SXAAStandingOnly);

		AlignAngle(30);
		TargetAngle(180);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(8);
		AlignNrFrames(1);

		AttachActionStartAtFrame(4);
		DamageFrame(9);
		Power(10);
		AttachAction(Prost1StompKickFLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Kicking);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(Prost1Idle);
}


action(Prost1StompKickBLink)
{
//		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Bob\xxx\BthrnbkA.ske",100,off,100,_AIclassangel);	//Backwards hold frame
		file("pc\actors\MultiAnm\xxx\ChRnSlmR.ske",100,off,180);	//Left land on face
		trigger(_alldir);
		ActionSubRoutine(Sub_SetAttackerToEnemyAndHandleThrown);
		break(off);
		nrintframes(4);
		connections(BeastIdle,GENThrownRight);
}


action(Prost1StompKickB)
{
		file("pc\actors\Chot\xxx\MSpinKk2.ske",100,on,100);	//Spinning flying kick

		AIClass(_AIclassfemale|_AIclasscop|_AIclassdweller);

		flag(_SXAAalignmovingslave|_SXAAStandingOnly);

		AlignAngle(30);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(8);
		AlignNrFrames(1);

		AttachActionStartAtFrame(4);
		DamageFrame(9);
		Power(10);
		AttachAction(Prost1StompKickBLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Kicking);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(Prost1Idle);
}

action(Prost1GunButF)
{
		file("pc\actors\MultiAnm\xxx\DmGunBut.ske",100,on,100);	//Female Gun Butt

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(70);
		AlignDistance(100);
		AlignSlack(40);
		DistanceSlack(50);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(15);
		AttachAction(CopGunButFLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);
//		ActionSubRoutine(Sub_RandomPunchedSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(Prost1Idle);
}

action(Prost1GunButB)
{
		file("pc\actors\MultiAnm\xxx\DmGunBut.ske",100,on,100);	//Female Gun Butt

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(70);
		AlignDistance(100);
		AlignSlack(40);
		DistanceSlack(50);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(15);
		AttachAction(CopGunButBLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(Prost1Idle);
}


SubRoutine(Sub_Prost1KneeFrontLink)
{

		if(VAIclass!=_AIclassbeast)					//should maybe be ==0 ?
		{

			if(vframe<=1)						//should maybe be ==0 ?
			{
				state(_or,StateThrown);
				State(_clr,StateCrouching);
			}

			if(vframe==15)
			{
				sample(SFXKickedReact,-1);
				sample(SFXManPunch,-1);
			}

			if(vframe==70)
			{
				sample(SFXManFallToGround,-1);
			}
		}
}
action(Prost1KneeFrontLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\MultiAnm\xxx\DmKneeM.ske",100,on,100);	//Fem knee in crotch and push onto back

		ActionSubRoutine(Sub_Prost1KneeFrontLink);

		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		break(off);
		connections(BeastIdle,GENGetUpFromBack);
}

action(Prost1KneeFront)
{
		file("pc\actors\MultiAnm\xxx\DmKneeF.ske",100,on,100);	//Fem knee in crotch and push onto back

		AIClass(_AIclassfemale|_AIclasscop|_AIclassdweller|_AIclassprost);
		
		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(70);
		AlignDistance(90);
		AlignSlack(40);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(8);

		AttachActionStartAtFrame(0);
		DamageFrame(12);
		Power(10);
		AttachAction(Prost1KneeFrontLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}

action(Prost1RunKneeFront)
{
		file("pc\actors\MultiAnm\xxx\DmKneeF.ske",100,on,100);	//Fem knee in crotch and push onto back

		AIClass(_AIclassfemale|_AIclassprost);
		
		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(70);
		AlignDistance(90);
		AlignSlack(40);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(8);

		AttachActionStartAtFrame(0);
		DamageFrame(12);
		Power(10);
		AttachAction(Prost1KneeFrontLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}


SubRoutine(Sub_KillActorKickSnapNeck)
{
		CallSub(Sub_RandomKickedSFX);


	if(VAIclass!=_AIclassbeast)					//should maybe be ==0 ?
	{

		if(VFrame==48)
		{
			state(_or,StateDead);
			direction(_clr,_DIRalive);
			callsub(Sub_Deposses);
			vector(_settoactorpos,gactorpos);
			sample(SFXManNeckSnap,gactorpos);
			//if(AIAbility&=_AIAPickUpWeapon)
			//{
				call(CheckAttached,_CADropWeaponAndShells);
			//}
		}

		if(vframe==86)
		{
			sample(SFXManFallToGround,-1);
		}
	}
}


action(Prost1KickSnapNeckLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\MultiAnm\xxx\DmBrkNkM.ske",100,off,100);
		break(off);

		//ActionSubRoutine(Sub_RandomStrangledSFX);
		ActionSubRoutine(Sub_KillActorKickSnapNeck);

		connections(BeastIdle,Prost1KickSnapNeckLink);
}

action(Prost1KickSnapNeck)
{
		file("pc\actors\MultiAnm\xxx\DmBrkNkF.ske",100,on,100);	// kick in crotch and snap neck. Domina Only

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AIClass(_AIclassfemale|_AIclasscop);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(105);
		DistanceSlack(150);
		AlignSlack(20);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(10);
		DamageFrame(15);
		Power(1);
		AttachAction(Prost1KickSnapNeckLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}


SubRoutine(Sub_Prost1TapSuckerPunchLink)
{

		if(vframe<=1 && VAIclass!=_AIclassbeast)					//should maybe be ==0 ?
		{
			state(_or,StateThrown);
			State(_clr,StateCrouching);
		}
	
		if(Vframe==49)
		{
			sample(SFXManPunch,-1);
		}


		if(vframe==67) //body hit ground
		{
			sample(SFXManFallToGround,-1);
		}
}


action(Prost1TapSuckerPunchLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\MultiAnm\xxx\FTPnchM.ske",100,off,100);
		break(off);

		ActionSubRoutine(Sub_Prost1TapSuckerPunchLink);

		connections(BeastIdle,CopGetUpFromGunButB);
}


action(Prost1TapSuckerPunch)
{
		file("pc\actors\MultiAnm\xxx\FTPnchF.ske",100,on,100);	// Fem tap male on shoulder then sucker punch

		flag(_SXAAalignmovingmaster|_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);
		//flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIclassfemale|_AIclassprost|_AIclassdweller|_SXAAStandingOnly);

		AlignAngle(-10);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(85);
		DistanceSlack(70);
		AlignSlack(30);	

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(0);
		DamageFrame(15);
		Power(10);
		AttachAction(Prost1TapSuckerPunchLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}





SubRoutine(Sub_KissingTransfer)
{
		if(VAICon==0 && vframe==150 && VActorFlag==_AFLAGpossesed)
		{
			call(TransferPlayerToAttachActor);
			Direction(_set,_DIRdepossesion);
			call(CheckAttached,_CANormal);
		}
}

SubRoutine(Sub_StartPossesionWhoble)
{
		if(VAICon!=0)
		{
			if(vframe==90)
			{
				call(MatrixCallback,_SXEXPActorMatrixBulb,0.1,60);
			}

			//	Don't spawn halo, if the kisser isn't doing her animation anymore
			//
			if(vframe==149 && VParenAttachActor!=0)		//160
			{
				spawnactor(Halo,0,0,0);
				call(CheckForPickup,4,_ClassPickup);
			}
		}
}

action(BouncerKissGirlLink)
{
		file("pc\actors\Bouncer\xxx\B_GirlUp.ske",100,on);
		break(off);

		connections(GenIdle);
}

action(ProstKissingLink)
{
		file("pc\actors\MultiAnm\xxx\KisPosM.ske",100,on);
		break(off);

		ActionSubRoutine(Sub_StartPossesionWhoble);

		connections(GenIdle);
}

action(ProstKissing)
{
		file("pc\actors\MultiAnm\xxx\KisPosF.ske",100,on,100);	//Throw left jab

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AIClass(_AIclassfemale|_AIclassprost);

		AlignXYZ(0.0692,0,68.2822);
	//	AlignAngle(0);
		TargetAngle(180);
		AttackHeight(50);
	//	AlignDistance(100);
		AlignSlack(20);	
		DistanceSlack(150);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(15);
		Power(0);
		AttachAction(ProstKissingLink);
		TargetAIClass(_AIclassdweller|_AIclasscop|_AIclasschot);

		ActionSubRoutine(Sub_KissingTransfer);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(ProstKissingGetUp1);
}

action(ProstKissingGetUp1)
{
		file("pc\actors\MultiAnm\xxx\KisPosFB.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(off);
		connections(ProstKissingGetUp2);
}

action(ProstKissingGetUp2)
{
		file("pc\actors\MultiAnm\xxx\KisPosFS.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(off);
		connections(Prost1Idle);
}

action(Prost1Spread)	//Lead directly to next animation
{
		trigger(_DIRMove);
		AIClass(_AIClassProstSkeleton);
		nrintframes(-1);
		connections(Prost1SpreadGun,Prost1WalkDiagFL,Prost1WalkDiagFR,Prost1WalkDiagBL,Prost1WalkDiagBR,Prost1Walk,Prost1WalkBack,Prost1WalkL,Prost1WalkR,Prost1RunDiagFL,Prost1RunDiagFR,Prost1RunDiagBL,Prost1RunDiagBR,prost1run,prost1RunBack,Prost1RunL,Prost1RunR,Prost1TurnRight,Prost1TurnLeft);
}

action(Prost1SpreadGun)	//Lead directly to next animation
{
		trigger(_DIRMove|_DIRHaveGun);
		AIClass(_AIClassProstSkeleton);
		nrintframes(-1);
		connections(Prost1WalkDiagFLGun,Prost1WalkDiagFRGun,Prost1WalkDiagBLGun,Prost1WalkDiagBRGun,Prost1WalkGun,Prost1WalkBackGun,Prost1WalkLGun,Prost1WalkRGun,Prost1RunDiagFLGun,Prost1RunDiagFRGun,Prost1RunDiagBLGun,Prost1RunDiagBRGun,Prost1RunGun,Prost1RunBackGun,Prost1RunLGun,Prost1RunRGun,Prost1TurnRightCombat,Prost1TurnLeftCombat);
}

action(Prost1CloseRange)
{
		file("pc\actors\chot\xxx\MShPmph.ske",100,on,100,_AIclassCloseRange);

		AIClass(_AIclassCloseRange|_AIclassMale|_AIclassFemale);

		trigger(_DIRshoot|_DIRHaveGun|_DIRcombatmode);
		break(on);
		nrintframes(0);


		connections(Prost1SpreadGun,Prost1CloseRange,Prost1Idle);
}



/////////////////////////////////////////////////////////////////////////////////////////
//	IDLE ACTIONS

Action(Prost1Talk)
{
	file("pc\actors\domina\talk\jawflap.ske",100,on);

	nrintframes(4);
	intforloop(on);
	trigger(_allDIR);
	break(on);
	connections(Prost1KungFu,Prost1Talk);
}

Action(Prost1KungFu)
{
	file("pc\actors\domina\talk\kungfu.ske",100,on);

	nrintframes(4);
	intforloop(on);
	trigger(_DIRshoot);
	break(off);
	connections(Prost1Talk);
}


/* *************   Crouching moves ******************* */

action(Prost1CrouchTurnLeftRightEnd)
{
		file("pc\actors\Prost1\xxx\FCrTrStp.ske",100,off,100);
		trigger(_DIRnotendofanim|_noDIR);
		break(on);
		nrintframes(3);
		intforloop(off);
		connections(Prost1CrouchTurnRight,Prost1CrouchTurnLeft,Prost1CrouchIdle);
}

action(Prost1CrouchTurnRight)
{
		file("pc\actors\Prost1\xxx\FCrTrRSt.ske",100,off,100);//crouch start turn right
		file("pc\actors\Prost1\xxx\FCrTrRLp.ske",100,on,100);//crouch turn right loop
		trigger(_DIRRight);
		break(on);
		nrintframes(3);
		intforloop(on);
		connections(Prost1CrouchTurnRight,Prost1CrouchTurnLeft,Prost1CrouchTurnLeftRightEnd);
}

action(Prost1CrouchTurnLeft)
{
		file("pc\actors\Prost1\xxx\FCrTrLSt.ske",100,off,100);//crouch start turn left
		file("pc\actors\Prost1\xxx\FCrTrLLp.ske",100,on,100);//crouch turn left loop
		trigger(_DIRleft);
		break(on);
		nrintframes(3);
		intforloop(on);
		connections(Prost1CrouchTurnRight,Prost1CrouchTurnLeft,Prost1CrouchTurnLeftRightEnd);
}

action(Prost1CrouchWoundLight)
{
		file("pc\actors\Chot\xxx\MCrWnd1.ske",10,off);	//Head.    
		file("pc\actors\Chot\xxx\MCrWnd2.ske",100,off);	//Stomach/chest. 
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchShoot,Prost1CrouchSpreadOut,Prost1CrouchIdle);
}
     
action(Prost1CrouchDead)
{
		file("pc\actors\Chot\xxx\McrDeth1.ske",50,off);	//Collapse backwards dead
		file("pc\actors\Chot\xxx\McrDeth2.ske",100,off);	//Crawl forward dead
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		nrintframes(8);
}

action(Prost1CrouchDown)
{
		file("pc\actors\Prost1\xxx\FCrStrCm.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Prost1\xxx\FCrStart.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchIdle);
}

action(Prost1CrouchUp)
{
		file("pc\actors\Prost1\xxx\FCrEndCm.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Prost1\xxx\FCrEnd.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1Spread,Prost1Idle);
}

action(Prost1CrouchShoot)
{
		file("pc\actors\Prost1\xxx\FCrHvFrH.ske",100,on);		//Fire heavy hold/Aim frame
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchShoot,Prost1CrouchIdle);
}

action(Prost1CrouchShootLight)
{
		file("pc\actors\Prost1\xxx\FCrIdle.ske",100,on);
//		file("pc\actors\Prost1\xxx\FCrHvFrH.ske",100,on);		//Fire heavy hold/Aim frame
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchShootLight,Prost1CrouchIdle);
}

action(Prost1CrouchLightRecoil)
{
//		file("pc\actors\Prost1\xxx\FCrHvFrP.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\Prost1\xxx\FCrLtFr.ske",100,on);

//		ActionSubroutine(Sub_ActionDebugBreak);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchShootLight,Prost1CrouchIdle);
}

action(Prost1CrouchHeavyRecoil)
{
		file("pc\actors\Prost1\xxx\Fcrhvfr.ske",100,on);

		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchShoot,Prost1CrouchIdle);
}

action(Prost1CrouchGrenade)
{
		file("pc\actors\Prost1\xxx\FCrTrGrn.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchIdle)
{
		file("pc\actors\Prost1\xxx\FCrIdle.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchShoot,Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchSpreadOut)
{
		file("pc\actors\Prost1\xxx\FCrIdle.ske",100,on);
		trigger(_DIRmove);
		nrintframes(-1);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchForwardLeft,Prost1CrouchForwardRight,Prost1CrouchBackwardLeft,Prost1CrouchBackwardRight,Prost1CrouchForward,Prost1CrouchBackward,Prost1CrouchLeft,Prost1CrouchRight,Prost1CrouchRForwardLeft,Prost1CrouchRForwardRight,Prost1CrouchRBackwardLeft,Prost1CrouchRBackwardRight,Prost1CrouchRForward,Prost1CrouchRBackward,Prost1CrouchRLeft,Prost1CrouchRRight,Prost1CrouchTurnRight,Prost1CrouchTurnLeft);
}

action(Prost1CrouchRForward)
{
		file("pc\actors\Chot\xxx\MCrRunF.ske",100,on,120);
		trigger(_DIRforward);
		break(on);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRBackward)
{
		file("pc\actors\Chot\xxx\MCrRunB.ske",100,on,120);
		trigger(_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRLeft)
{
		file("pc\actors\Chot\xxx\MCrRunL.ske",100,on,120);
		trigger(_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRRight)
{
		file("pc\actors\Chot\xxx\MCrRunR.ske",100,on,120);
		trigger(_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRForwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunFL.ske",100,on,120);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRBackwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunBL.ske",100,on,120);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRForwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunFR.ske",100,on,120);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRBackwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunBR.ske",100,on,120);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchForward)
{
		file("pc\actors\Prost1\xxx\FCrWlkF.ske",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchBackward)
{
		file("pc\actors\Prost1\xxx\FCrWlkB.ske",100,on);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}


action(Prost1CrouchLeft)
{
		file("pc\actors\Prost1\xxx\FCrWlkL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchRight)
{
		//file("pc\actors\Chot\xxx\MCrStfR.ske",100,on);
		file("pc\actors\Prost1\xxx\FCrWlkR.ske",100,on);	//wait for gabe
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchForwardLeft)
{
		file("pc\actors\Prost1\xxx\FCrWlkFL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchBackwardLeft)
{
		file("pc\actors\Prost1\xxx\FCrWlkBL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchForwardRight)
{
		file("pc\actors\Prost1\xxx\FCrWlkFR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}

action(Prost1CrouchBackwardRight)
{
		file("pc\actors\Prost1\xxx\FCrWlkBR.ske",100,on);	//wait for gabe
		//file("pc\actors\Chot\xxx\MCrStRB.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1CrouchSpreadOut,Prost1CrouchIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	IDLE ACTIONS

Action(Prost1IdleCombatGun)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Cm.ske",100,on,100,_AIclassSubgirl,_DIRcombatmode);
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",95,on,100,_AIclassSubgirl);
		file("pc\actors\Subgirl1\xxx\SgIdl2Nc.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Domina\xxx\DmCIdl1.ske",100,on);
		trigger(_noDIR|_DIRcombatmode|_DIRhavegun);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(Prost1Spread,prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,prost1idle);
}

Action(Prost1IdleCombatNoGun)
{
		file("pc\actors\Prost1\xxx\PCmNgId1.ske",100,on,100,_AIclassprost);
		file("pc\actors\domina\xxx\DmCmNgI1.ske",100,on);
		trigger(_noDIR|_DIRcombatmode);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(ProstKissing,Prost1Spread,Prost1KickingBobF,Prost1KickingBobB,Prost1KickSnapNeck,Prost1TapSuckerPunch,Prost1KneeFront,Prost1Kicking,prost1StandShoot,Prost1TurnLeft,Prost1TurnRight,prost1idle);
}

Action(Prost1IdleGun)
{
//		file("pc\actors\Domina\xxx\DmIdl2.ske",30,on);//looking at fingernails
//		file("pc\actors\Domina\xxx\DmIdl1.ske",100,on);//breathing

		file("pc\actors\Subgirl1\xxx\SgIdl1Cm.ske",100,on,100,_AIclassSubgirl,_DIRcombatmode);
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",95,on,100,_AIclassSubgirl);
		file("pc\actors\Subgirl1\xxx\SgIdl2Nc.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Domina\xxx\DmIdl2.ske",30,on);//looking at fingernails
		file("pc\actors\Domina\xxx\DmIdl1.ske",65,on);//breathing
		file("pc\actors\Domina\xxx\DmIdl3.ske",100,on);//look left/right
		trigger(_noDIR|_DIRhavegun);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(Prost1Spread,prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,prost1idle);
}

Action(Prost1IdleNoGun)
{
		//file("pc\actors\Domina\xxx\DmIdl2.ske",30,on,100,_AIclasscop);//Idles arm down. looking at fingernails 
		//file("pc\actors\Domina\xxx\DmIdl1.ske",65,on,100,_AIclasscop);//breathing
		//file("pc\actors\Domina\xxx\DmIdl3.ske",100,on,100,_AIclasscop);//look left/right

		//file("pc\actors\prost1\xxx\Widle1.ske",33,on,100,_AIclassbarpeople);
		//file("pc\actors\prost1\xxx\Widle2.ske",66,on,100,_AIclassbarpeople); // Waitress Idle Animations
		//file("pc\actors\prost1\xxx\Widle3.ske",100,on,100,_AIclassbarpeople);

		file("pc\actors\Subgirl1\xxx\SgIdl1Cm.ske",100,on,100,_AIclassSubgirl,_DIRcombatmode);
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",95,on,100,_AIclassSubgirl);
		file("pc\actors\Subgirl1\xxx\SgIdl2Nc.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Prost1\xxx\PIdle2.ske",25,on);		//look at fingernails
		file("pc\actors\Prost1\xxx\PIdle1.ske",100,on);		//hip stance
		trigger(_allDIR);

		nrintframes(8);
		intforloop(on);
		break(on);
		connections(ProstKissing,Prost1Spread,prost1StandShoot,Prost1TurnLeft,Prost1TurnRight,prost1idle);
}

Action(Prost1Idle)
{
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(-1);
		connections(Prost1IdleCombatGun,Prost1IdleCombatNoGun,Prost1IdleGun,Prost1IdleNoGun);
}


action(Prost1IdleLongTime)
{
		file("pc\actors\Chot\xxx\mspan11p.ske",33,on);//celebrations, not hitting these
		file("pc\actors\Chot\xxx\mspan14p.ske",66,on);
		file("pc\actors\Chot\xxx\mspan12p.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(Prost1Spread,Prost1StandShoot,Prost1TurnLeft,Prost1TurnRight,Prost1IdleLongTime,Prost1Idle);
}


action(Prost1IdleHitWall)	//used just after you bounce into a wall
{
//		file("pc\actors\Chot\xxx\Mneidl2p.xxx",20,on);	//ass scratch
//		file("pc\actors\Chot\xxx\Mneidl3p.xxx",40,on);	//crotch scratch
//		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		file("pc\actors\Domina\xxx\DmIdl2.ske",30,on);//looking at fingernails
		file("pc\actors\Domina\xxx\DmIdl1.ske",65,on);//breathing
		file("pc\actors\Domina\xxx\DmIdl3.ske",100,on);//look left/right

		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(GENHitWallSpreadOut);
}

action(Prost1IdleHitWallFront)	//used just after you bounce into a wall, face first
{
//MISSING Animation
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(GENIdleHitWallFront);
}

action(Prost1HitWallSpread)	//Lead directly to next animation
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(Prost1HitWallTurnLeft,Prost1HitWallTurnRight,Prost1IdleHitWall,GENIdleHitWallFront);
}

action(Prost1HitWallSpreadOut)	//Lead directly to next animation
{
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(-1);
		connections(Prost1HitWallTurnLeft,Prost1HitWallTurnRight,Prost1IdleHitWall,GENIdleHitWall);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	ELECTRICUTIONS

action(Prost1ElectricShock0)
{
		file("pc\actors\Chot\xxx\aelectLP.ske",100,off,130);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true)
		connections(GENElectricShock1);
		collision(on);
		gravity(off);
}

action(Prost1ElectricShock1)
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,off);
		move(0,0,20);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(6);
		intforloop(off);
		nomove(true)
		connections(GENElectricShock1);
		gravity(off);
		collision(on);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	DEAHTS
action(Prost1FallDead)
{
		file("pc\actors\Chot\xxx\alndhard.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(12);
}

action(Prost1CrawlDead)
{
		file("pc\actors\Chot\xxx\mcrwlfal.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(12);
}


Action(Prost1Crush)
{
		file("pc\actors\Chot\xxx\mded5g.ske",100,off);	//face down
		//file("pc\actors\Chot\xxx\Mcrushed.ske",100,off);	//point at player
		trigger(_allDIR);
		collision(off);
		gravity(off);
		break(off);
		nrintframes(4);
}


subroutine(Sub_Prost1StandDead)
{
		if(vframe==56&&VActionIndex==6)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==26&&VActionIndex==3)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==149&&VActionIndex==4)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==49&&VActionIndex==5)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==77&&VActionIndex==0)
		{
			sample(SFXManFallToGround,-1);
		}
}
action(Prost1StandDead)
{
		file("pc\actors\behemoth\xxx\bdeth1.ske",100,off,200,_AIclassAbeast);	//face down

		file("pc\actors\Prost1\xxx\Fdeth1.ske",50,off,100,_AIclasssubgirl);		//Sway fall on knees then to face:
		//file("pc\actors\Prost1\xxx\Fdeth2.ske",66,off,100,_AIclasssubgirl);		//Spin around and die on face:
		file("pc\actors\Prost1\xxx\Fdeth4.ske",100,off,100,_AIclasssubgirl);	//Collapse to knees and around to back:

		file("pc\actors\Prost1\xxx\Fdeth1.ske",25,off);		//Sway fall on knees then to face:
		file("pc\actors\Prost1\xxx\Fdeth2.ske",50,off);		//Spin around and die on face:
		file("pc\actors\Prost1\xxx\Fdeth3.ske",75,off);		//Fall to knees and crawl a second before dying:
		file("pc\actors\Prost1\xxx\Fdeth4.ske",100,off);	//Collapse to knees and around to back:
	
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(12);

		ActionSubRoutine(Sub_Prost1StandDead);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	BURNED, STEAMED AND BLIND
action(Prost1GettingBurned)	//When inside fire, moving head left and right
{
		file("pc\actors\chot\xxx\MBrnThrs.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(3);
		ydeltafromzeroframe(off);
		connections(Prost1BlindForward,Prost1BlindBackwards,Prost1GettingBurned);
}
action(Prost1BlindForward)		//Walk slowly forward both inside and outside fire
{
	//	file("pc\actors\chot\xxx\MBrnStgr.ske",100,on);
		file("pc\actors\prost1\xxx\FBrnStgr.ske",100,on);
		trigger(_DIRforward);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(3);
		connections(GENBlindForward,GENBlindBackwards,GENBurnedIdle);
}

action(Prost1BlindBackwards)		//Walk slowly backwards both inside and outside fire
{
	//	file("pc\actors\chot\xxx\MBrnStbk.ske",100,on);
		file("pc\actors\prost1\xxx\FBrnStBk.ske",100,on);
		trigger(_DIRbackward);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(3);
		connections(GENBlindForward,GENBlindBackwards,GENBurnedIdle);
}

action(Prost1BurnedIdle)	//Inside and Outside fire, idle
{
	//	file("pc\actors\chot\xxx\MBrnIdl.ske",100,on);
		file("pc\actors\prost1\xxx\FBrnIdl.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(on);
		nrintframes(3);
		connections(GENBlindForward,GENBlindBackwards,GENBurnedIdle);
}

action(Prost1BurningRunInCircle)		//Running around in circle with the head on fire, then fall.
{
	//	file("pc\actors\chot\xxx\MBrnRnAr.ske",100,on);
		file("pc\actors\prost1\xxx\FBrnRnAr.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(GENBurningRollOnFloor);
}


action(Prost1SlowGetUpFace)	//Get back up from the ground
{
		file("pc\actors\chot\xxx\Mstandf1.ske",100,on,100,-1,-1,Sub_GetUpClearThrown68);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(Prost1BurnedIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	CRAWLING, BEING DRAGGED
action(Prost1Dragged)
{
		file("pc\actors\chot\xxx\MDrgFH_A.ske",100,off);
		file("pc\actors\chot\xxx\MDrgFH_B.ske",100,on);
		trigger(_allDIR);
		nrintframes(3);
		connections(Prost1Dragged);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	CLIMBING
Action(Prost1climbup)
{
		file("pc\actors\chot\xxx\MClmbWlS.ske",50,off,100);
		file("pc\actors\chot\xxx\MClmbWlF.ske",100,off,100);
		nrintframes(8);
		break(off);
		trigger(_allDIR);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1Idle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	RECOIL
action(Prost1HeavyRecoil)
{
		file("pc\actors\domina\xxx\dshpump.ske",100,on,100,_AIclassHipGun|_AIClassCop);
		file("pc\actors\domina\xxx\dshhevy.ske",100,on,100,_AIClassCop);
		file("pc\actors\domina\xxx\dshhevy.ske",100,on,100);

		//file("pc\actors\Prost1\xxx\FShHvy.ske",100,on);

		trigger(_AllDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(0);
		connections(Prost1SpreadGun,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}

action(Prost1LightRecoil)	//Works as proxy because it has to be restarted if SpawnAction is called again
{
		trigger(_AllDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(-1);
		connections(Prost1LightRecoil2);
}


action(Prost1LightRecoil2)
{
		//file("pc\actors\prost1\xxx\dshoots.ske",100,on);

		file("pc\actors\domina\xxx\dshltr1.ske",25,on);
		file("pc\actors\domina\xxx\dshltr2.ske",50,on);
		file("pc\actors\domina\xxx\dshltr3.ske",75,on);
		file("pc\actors\domina\xxx\dshltr4.ske",100,on);

		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(0);
		connections(Prost1SpreadGun,Prost1LightRecoil2,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}

//for the subgirls right hand

action(SubGirlMachineFireRight)
{
		file("pc\actors\subgirl1\xxx\SgfireR1.ske",33,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireR2.ske",67,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireR3.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Prost1\xxx\FShLtStr.ske",100,off);
		file("pc\actors\Prost1\xxx\FShLtLp.ske",100,on);

		trigger(_DIRshoot|_DIRcombatmode);//|_DIRnotendofanim);
		break(on);
		nrintframes(0);
		connections(SubGirlMachineFireRight,Prost1SpreadGun,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}

action(SubGirlMachineFireLeft)
{
		file("pc\actors\subgirl1\xxx\SgfireL1.ske",33,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireL2.ske",67,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireL3.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Prost1\xxx\FShLtStr.ske",100,off);
		file("pc\actors\Prost1\xxx\FShLtLp.ske",100,on);

		trigger(_DIRshoot|_DIRcombatmode);//|_DIRnotendofanim);
		break(on);
		nrintframes(0);
		connections(SubGirlMachineFireLeft,Prost1SpreadGun,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}
/*
action(Prost1MachineGunFire2)
{
		file("pc\actors\subgirl1\xxx\SgfireR1.ske",33,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireR2.ske",67,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireR3.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Prost1\xxx\FShLtStr.ske",100,off);
		file("pc\actors\Prost1\xxx\FShLtLp.ske",100,on);

		trigger(_DIRshoot|_DIRnotendofanim);
		break(on);
		nrintframes(0);
		connections(Prost1MachineGunFire2,Prost1SpreadGun,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}

action(Prost1MachineGunFire)
{
		file("pc\actors\subgirl1\xxx\SgfireL1.ske",33,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireL2.ske",67,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireL3.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Prost1\xxx\FShLtStr.ske",100,off);
		file("pc\actors\Prost1\xxx\FShLtLp.ske",100,on);

		trigger(_DIRshoot|_DIRnotendofanim);
		break(on);
		nrintframes(0);
		connections(Prost1MachineGunFire,Prost1SpreadGun,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}
*/

action(Prost1ThrowGrenade)
{
		file("pc\actors\subgirl1\xxx\SgfireR1.ske",33,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireR2.ske",67,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireR3.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\Domina\xxx\dmthgrc.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(Prost1Spread,Prost1Idle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	POSSESION
//action(prost1Possesed)
//{
//		file("pc\actors\prost1\xxx\mposs1.xxx",100,off,100,-1,-1,Sub_ClrThrownFlag);
//		trigger(_allDIR);
//		AIClass(_AIClassProstSkeleton);
//		nrintframes(4);
//		break(off);
//		connections(prost1idle);
//}


action(prost1Possesed)
{
		file("pc\actors\chot\xxx\MPoss3A.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(4);//number of interpolation frames
		break(off);//unbreakable by any means
		soundlevel(0);
		connections(prost1Possesed2);//with break(off) will not check connections until end of anim
}

action(prost1Possesed2)
{
		file("pc\actors\Chot\xxx\MPoss3B.ske",100,on);//if number after 'on' (100,on,"100") this number will control animation speed in percent
		trigger(_DIRNotEndOfAnim);
		break(on);//AI can break out, with break(on) it checks connection
		soundlevel(0);
		connections(Prost1Spread,Prost1StandShoot,prost1Possesed2,prost1idle);
}




action(Prost1Depossesed)
{
		file("pc\actors\chot\xxx\Mstun1g.ske",50,on,100,-1,-1,Sub_ClrThrownFlag);
		file("pc\actors\chot\xxx\Mstun2g.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(4);
		break(off);
		connections(Prost1idle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	SHOOTING

action(Prost1StandShoot)
{
		trigger(_DIRshoot|_DIRHaveGun|_DIRcombatmode);
		break(on);
		nrintframes(-1);
		connections(Prost1CloseRange,Prost1GunButBob,Prost1GunButF,Prost1GunButB,Prost1StandShootAnims);
}

action(Prost1StandShootAnims)
{
//		file("pc\actors\subgirl1\xxx\SgfireL1.ske",33,on,100,_AIclassSubgirl);
//		file("pc\actors\subgirl1\xxx\SgfireL2.ske",66,on,100,_AIclassSubgirl);
		file("pc\actors\subgirl1\xxx\SgfireL3.ske",100,on,100,_AIclassSubgirl);
		//file("pc\actors\subgirl1\xxx\SgfireR1.ske",33,on,100,_AIclassSubgirl);
		//file("pc\actors\subgirl1\xxx\SgfireR2.ske",66,on,100,_AIclassSubgirl);
		//file("pc\actors\subgirl1\xxx\SgfireR3.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Domina\xxx\DmCIdl1.ske",100,on,100,-1,_DIRHaveGun);

		file("pc\actors\Prost1\xxx\PCmNgJgl.ske",100,on,100,_AIclassprost);
		file("pc\actors\domina\xxx\DmCmNgI1.ske",100,on);
		trigger(_DIRshoot|_DIRcombatmode);
		break(on);
//		nrintframes(0);
		connections(Prost1Spread,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}


//XXX is not used
action(prost1RunShoot)
{
		file("pc\actors\prost1\xxx\Frnshotg.xxx",100,on);
		trigger(_DIRshoot);
//		trigger(_DIRrunShoot);	//DOESNT EXIST
//		trigger(_allDIR);
		nrintframes(4);

		break(oN);
		connections(prost1RunShoot,prost1Run,prost1StandShoot,prost1idle);
}


//	SHOT BY SNIPER REACTIONS
//

Action(Prost1ShotInLeg)
{
		file("pc\actors\chot\xxx\MSnpLeg2.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\chot\xxx\MSnpLeg3.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(GENCrawlSpreadOut);
}

Action(Prost1ShotFrHead)
{
		file("pc\actors\chot\xxx\mded6g.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(Prost1ShotFrHead);
}
Action(Prost1ShotFrTorso)
{
		file("pc\actors\chot\xxx\mded1.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(Prost1ShotFrTorso);
}
Action(Prost1ShotFrRShoulder)
{
		file("pc\actors\chot\xxx\mded2.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		ActionSubRoutine(Sub_SetThrown);
		connections(Prost1GetUpFromBackFaceDown);
}
Action(Prost1ShotFrLShoulder)
{
		file("pc\actors\chot\xxx\Fstwnd2.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(Prost1Idle);
}
Action(Prost1ShotGeneric)
{
		file("pc\actors\chot\xxx\Mwund3.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(Prost1Idle);
}
Action(Prost1ShotBkHead)
{
		file("pc\actors\chot\xxx\mded4g.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(Prost1ShotBkHead);
}
Action(Prost1ShotBkBack)
{
		file("pc\actors\chot\xxx\MWundg2.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(3);
		connections(Prost1Idle);
}


//---------

/////////////////////////////////////////////////////////////////////////////////////////
//	WOUNDED
action(Prost1WoundLight)
{
		file("pc\actors\Domina\xxx\dmwnd1c.ske",33,off,100,-1,_DIRcombatmode);
		file("pc\actors\Domina\xxx\dmwnd2c.ske",66,off,100,-1,_DIRcombatmode);		//right
		file("pc\actors\Domina\xxx\dmwnd3c.ske",100,off,100,-1,_DIRcombatmode);		//left
		file("pc\actors\Domina\xxx\dmwnd4c.ske",100,off,100,-1,_DIRcombatmode);		//back

//		file("pc\actors\Prost1\xxx\fqkwund1.ske",25,off);
//		file("pc\actors\Prost1\xxx\fqkwund2.ske",50,off);
//		file("pc\actors\Prost1\xxx\fqkwund3.ske",75,off);
//		file("pc\actors\Prost1\xxx\fqkwund4.ske",100,off);

		file("pc\actors\Prost1\xxx\PWnd1Nc.ske",25,off);
		file("pc\actors\Prost1\xxx\PWnd2Nc.ske",50,off);
		file("pc\actors\Prost1\xxx\PWnd3Nc.ske",75,off);
		file("pc\actors\Prost1\xxx\PWnd4Nc.ske",100,off);

		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassProstSkeleton);
		break(on);
		collision(on);
		nrintframes(4);
		connections(Prost1Spread,Prost1StandShoot,Prost1WoundLight,Prost1TurnLeft,Prost1TurnRight,Prost1Idle);
}

action(Prost1WoundLightNoBreak)	//Identical to the one above except for break
{
		file("pc\actors\Prost1\xxx\fqkwund1.ske",25,off);
		file("pc\actors\Prost1\xxx\fqkwund2.ske",50,off);							//left
		file("pc\actors\Prost1\xxx\fqkwund3.ske",75,off);							//in back
		file("pc\actors\Prost1\xxx\fqkwund4.ske",100,off);							//right

//		file("pc\actors\Chot\xxx\FstWnd1.ske",10,off);
//		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
		//file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassProstSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
		connections(Prost1Spread,Prost1StandShoot,Prost1WoundLight,Prost1TurnLeft,Prost1TurnRight,Prost1Idle);
}

action(Prost1WoundFlyBack1)	//Hold frame
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,off);
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(Prost1WoundFlyBack2);
}

action(Prost1WoundFlyBack2)	//Hitting wall+hold frame
{
		file("pc\actors\Chot\xxx\ThBkhtwl.ske",100,off);
		trigger(_DIRVerCol);
		break(on);
		collision(on);
		nrintframes(4);
		connections(Prost1WoundFlyBack3);
}
action(Prost1WoundFlyBack3)	//Land on ground
{
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);
		trigger(_DIRHorCol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(Prost1Idle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	STANDARD MOVES WITHOUT GUN

action(Prost1Pickup)
{
		file("pc\actors\Prost1\xxx\FpickupG.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(4);
		break(off);
		connections(Prost1Idle);
}

action(Prost1PickupChest)
{
		file("pc\actors\Prost1\xxx\FpickupF.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(4);
		break(off);
		connections(Prost1Idle);
}

action(Prost1PickupCrouch)
{
		file("pc\actors\Prost1\xxx\FCrPikUp.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		AIClass(_AIClassProstSkeleton);
		nrintframes(4);
		break(off);
		connections(Prost1CrouchIdle);
}

action(prost1RunBack)
{
		file("pc\actors\domina\xxx\DmRnBNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnBNC.ske",100,on,100,_AIclassCop);
		file("pc\actors\Prost1\xxx\PRunB.ske",100,on);
		offset(9);
		nrintframes(4);
		trigger(_DIRbackward);
		break(on);
		move(0,0,7);
		connections(Prost1BackwardStompKickB,Prost1BackwardStompKickF,Prost1Spread,prost1idle);
}

Action(prost1run)
{
		file("pc\actors\domina\xxx\DmRnFNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnFNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\prost1\xxx\Prunf.ske",100,on);
		break(on);
		nrintframes(4);
		offset(2);
		move(0,0,-7);

		trigger(_DIRforward);

		connections(Prost1KickingBobF,Prost1KickingBobB,Prost1RunKneeFront,Prost1StompKickF,Prost1StompKickB,prost1Spread,prost1idle);
}

action(Prost1RunL)
{
		file("pc\actors\domina\xxx\DmRnLNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnLNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunL.ske",100,on);
		offset(2);
		nrintframes(8);
		trigger(_DIRsideleft);
		move(7,0,0);
		break(on);
		connections(Prost1Spread,prost1idle);
}
action(Prost1RunR)
{
		file("pc\actors\domina\xxx\DmRnRNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnRNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunR.ske",100,on);
		offset(2);
		nrintframes(8);
		trigger(_DIRsideright);
		move(-7,0,0);
		break(on);
		connections(Prost1Spread,prost1idle);
}

action(Prost1RunDiagFL)
{
		file("pc\actors\domina\xxx\DmRnFLNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnFLNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunFL.ske",100,on);
		offset(2)
		trigger(_DIRsideleft|_DIRforward);
		move(3.5,0,-3.5);
		break(on);
		nrintframes(8);
		connections(Prost1Spread,prost1idle);
}
action(Prost1RunDiagFR)
{
		file("pc\actors\domina\xxx\DmRnFRNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnFRNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunFR.ske",100,on);
		offset(2);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		move(-3.5,0,-3.5);
		nrintframes(8);
		connections(Prost1Spread,prost1idle);
}

action(Prost1RunDiagBL)
{
		file("pc\actors\domina\xxx\DmRnBLNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnBLNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunBL.ske",100,on);
		offset(9);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		move(3.5,0,3.5);
		nrintframes(4);
		connections(Prost1BackwardStompKickB,Prost1BackwardStompKickF,Prost1Spread,prost1idle);
}

action(Prost1RunDiagBR)
{
		file("pc\actors\domina\xxx\DmRnBRNC.ske",100,on,100,_AIclassdweller);
		file("pc\actors\domina\xxx\DmRnBRNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunBR.ske",100,on);
		offset(9);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		move(-3.5,0,3.5);
		nrintframes(4);
		connections(Prost1BackwardStompKickB,Prost1BackwardStompKickF,Prost1Spread,prost1idle);
}

Action(prost1walk)
{
		file("pc\actors\Subgirl1\xxx\SgWlkFNc.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWF.ske",100,on,100,-1,_DIRcombatmode);// Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkfn.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkfn.ske",100,on,100,_AIclassdweller);
		//file("pc\actors\Prost1\xxx\WwalkTF.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkF.ske",100,on,100); //,_AIclassprost);

		offset(3);
		nrintframes(4);
		trigger(_DIRwalking|_DIRforward);
		//loopframes(10,20);										//loopstartframe,loopendframe
		break(on);

		connections(Prost1KickingBobF,Prost1KickingBobB,Prost1RunKneeFront,Prost1GunButBob,Prost1GunButF,Prost1GunButB,Prost1Spread,prost1idle);
}

Action(waitresswalk)
{
		file("pc\actors\Prost1\xxx\WwalkTF.ske",100,on,100,_AIclassbarpeople);

		offset(3);
		nrintframes(4);
		trigger(_DIRwalking|_DIRforward);
		//loopframes(10,20);										//loopstartframe,loopendframe
		break(on);

		connections(waitresswalk);
}

action(prost1WalkBack)
{
		file("pc\actors\Subgirl1\xxx\SgWlkBNc.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWB.ske",100,on,100,-1,_DIRcombatmode);// Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkbn.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkbn.ske",100,on,100,_AIclassdweller);
		file("pc\actors\Prost1\xxx\WwalkTB.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkB.ske",100,on);


		offset(18);
		nrintframes(4);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		connections(Prost1Spread,prost1idle);
}


action(prost1WalkL)
{
		file("pc\actors\Subgirl1\xxx\SgWlkL.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWL.ske",100,on,100,-1,_DIRcombatmode);// Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkln.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkln.ske",100,on,100,_AIclassdweller);
		file("pc\actors\Prost1\xxx\WwalkTL.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkL.ske",100,on);

		offset(3);
		nrintframes(4);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		connections(Prost1Spread,Prost1Idle);
}

action(prost1WalkR)
{
		file("pc\actors\Subgirl1\xxx\SgWlkR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWR.ske",100,on,100,-1,_DIRcombatmode);// Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkrn.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkrn.ske",100,on,100,_AIclassdweller);
		file("pc\actors\Prost1\xxx\WwalkTR.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkR.ske",100,on);
		nrintframes(4);
		offset(3);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		connections(Prost1Spread,Prost1Idle);
}
action(prost1WalkDiagFL)
{
		file("pc\actors\Subgirl1\xxx\SgWlkFL.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWFL.ske",100,on,100,-1,_DIRcombatmode);// Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkfln.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkfln.ske",100,on,100,_AIclassdweller);
		file("pc\actors\Prost1\xxx\WwalkTFL.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkFL.ske",100,on);
		nrintframes(4);
		offset(3);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		connections(Prost1KickingBobF,Prost1KickingBobB,Prost1RunKneeFront,Prost1GunButBob,Prost1GunButF,Prost1GunButB,Prost1Spread,Prost1Idle);
}

action(prost1WalkDiagFR)
{
		file("pc\actors\Subgirl1\xxx\SgWlkFR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWFR.ske",100,on,100,-1,_DIRcombatmode);// Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkfrn.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkfrn.ske",100,on,100,_AIclassdweller);
		file("pc\actors\Prost1\xxx\WwalkTFR.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkFR.ske",100,on);
		nrintframes(4);
		offset(3);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		connections(Prost1KickingBobF,Prost1KickingBobB,Prost1RunKneeFront,Prost1GunButBob,Prost1GunButF,Prost1GunButB,Prost1Spread,Prost1Idle);
}

action(prost1WalkDiagBL)
{
		file("pc\actors\Subgirl1\xxx\SgWlkBL.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWBL.ske",100,on,100,-1,_DIRcombatmode); // Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkbln.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkbln.ske",100,on,100,_AIclassdweller);
		file("pc\actors\Prost1\xxx\WwalkTBL.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkBL.ske",100,on);
		nrintframes(4);
		offset(18);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		connections(Prost1Spread,Prost1Idle);
}

action(prost1WalkDiagBR)
{
		file("pc\actors\Subgirl1\xxx\SgWlkBR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\DmCNgWBR.ske",100,on,100,-1,_DIRcombatmode); // Walk Combat no gun
		file("pc\actors\domina\xxx\dmwlkbrn.ske",100,on,100,_AIclassCop);
		file("pc\actors\domina\xxx\dfwlkbrn.ske",100,on,100,_AIclassdweller);
		file("pc\actors\Prost1\xxx\WwalkTBR.ske",100,on,100,_AIclassbarpeople);
		file("pc\actors\Prost1\xxx\PWlkBR.ske",100,on);
		nrintframes(4);
		offset(18);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		connections(Prost1Spread,Prost1Idle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	STANDARD MOVES WITH GUN
action(Prost1WalkGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkFNc.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlkfc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkfn.ske",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);
		offset(5);
		nrintframes(8);
		connections(Prost1KickingBobF,Prost1KickingBobB,Prost1RunKneeFront,Prost1GunButBob,Prost1GunButF,Prost1GunButB,Prost1SpreadGun,Prost1Idle);
}



action(Prost1WalkBackGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkBNc.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlkbc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkbn.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(30);
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1WalkLGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkL.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlklc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkln.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(14);
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1WalkRGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlkrc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkrn.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(0);
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1WalkDiagFLGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkFL.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlkflc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkfln.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		offset(15)
		connections(Prost1RunKneeFront,Prost1GunButBob,Prost1GunButF,Prost1GunButB,Prost1SpreadGun,Prost1Idle);
}

action(Prost1WalkDiagFRGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkFR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlkfrc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkfrn.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		offset(30)
		connections(Prost1RunKneeFront,Prost1GunButBob,Prost1GunButF,Prost1GunButB,Prost1SpreadGun,Prost1Idle);
}

action(Prost1WalkDiagBLGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkBL.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlkblc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkbln.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(30)
		nrintframes(8);
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1WalkDiagBRGun)
{
		file("pc\actors\Subgirl1\xxx\SgWlkBR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\domina\xxx\dmwlkbrc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkbrn.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(30)
		nrintframes(8);
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunF.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\frunsht.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnFNC.ske",100,on);
		trigger(_DIRforward);
		break(on);
		offset(8)
		move(0,0,-7);
		nrintframes(8);
		connections(Prost1RunKneeFront,Prost1StompKickF,Prost1StompKickB,Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunBackGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunB.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\frunbfst.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnBNC.ske",100,on);
		nrintframes(8);
		trigger(_DIRbackward);
		move(0,0,7);
		break(on);
		offset(13)
		connections(Prost1BackwardStompKickB,Prost1BackwardStompKickF,Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunLGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunl.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\fshrn90l.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnLNC.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideleft);
		move(7,0,0);
		break(on);
		offset(10)
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunRGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\fshrn90r.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnRNC.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideright);
		move(-7,0,0);
		break(on);
		offset(9)
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunDiagFLGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunFl.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\fshrn45l.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnFLNC.ske",100,on);
		trigger(_DIRsideleft|_DIRforward);
		move(3.5,0,-3.5);
		break(on);
		offset(9)
		nrintframes(8);
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunDiagFRGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunFr.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\fshrn45r.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnFRNC.ske",100,on);
		trigger(_DIRsideright|_DIRforward);
		move(-3.5,0,-3.5);
		break(on);
		offset(10)
		nrintframes(8);
		connections(Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunDiagBLGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunBL.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\fsrnb45l.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnBLNC.ske",100,on);
		trigger(_DIRsideleft|_DIRbackward);
		move(3.5,0,3.5);
		break(on);
		nrintframes(8)
		offset(13)
		connections(Prost1BackwardStompKickB,Prost1BackwardStompKickF,Prost1SpreadGun,Prost1Idle);
}

action(Prost1RunDiagBRGun)
{
		file("pc\actors\Subgirl1\xxx\SgRunBR.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\prost1\xxx\fsrnb45r.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\DmRnBRNC.ske",100,on);
		trigger(_DIRsideright|_DIRbackward);
		move(-3.5,0,3.5);
		break(on);
		offset(13)
		nrintframes(8);
		connections(Prost1BackwardStompKickB,Prost1BackwardStompKickF,Prost1SpreadGun,Prost1Idle);
}


action(prost1HitWall)
{
		//file("pc\actors\prost1\xxx\fwallg.xxx",100,off);
		file("pc\actors\Chot\xxx\mwundg.xxx",100,off);

		trigger(_DIRvercol);
		break(off);
		nrintframes(4);

//		gravity(off);
//		collision(off);
		connections(prost1idle);
}

action(Prost1Dance)
{
		file("pc\actors\prost1\xxx\vidle.xxx",100,off);
		nrintframes(4);
		trigger(_allDIR);
		connections(prost1idle);
}

action(Prost1Dance2)
{
		//file("pc\actors\prost1\ske\Titwkcy.ske");
		file("pc\actors\prost1\xxx\Fpcsp1p.xxx",100,off);
		nrintframes(4);
		trigger(_allDIR);
		connections(prost1idle);
}

action(Female1Sleeping)
{
	file("pc\actors\Prost1\xxx\FemDrnk1.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);

	connections(Female1Sleeping);
}

action(Female1Sitting)
{
	file("pc\actors\Prost1\xxx\FemDrnk2.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);

	connections(Female1Sitting);
}

action(Female2Sitting)
{
	file("pc\actors\Prost1\xxx\FemDrnk3.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);
	

	connections(Female2Sitting);
}

action(Female1BarIdle)
{
	file("pc\actors\Prost1\xxx\FemDrnk4.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);

	connections(Female1BarIdle);
}

action(PreDance)
{
	file("pc\actors\Prost1\xxx\Pwork1.ske",100,off);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);

	connections(DanceRight);
}

action(DanceIdle)
{
	file("pc\actors\Prost1\xxx\DnceCIdl.ske",100,off);
	trigger(_allDIR);
	break(on);
	nrintframes(4);
	intforloop(on);
	connections(DanceIdle);
}

action(DanceRight)
{
	file("pc\actors\Prost1\xxx\DnceCR1.ske",100,off);
	trigger(_allDIR);
	break(off);
	nrintframes(4);
	connections(DanceIdle);
}

action(DanceLeft)
{
	file("pc\actors\Prost1\xxx\DnceCL2.ske",50,off);
	file("pc\actors\Prost1\xxx\DnceCL1.ske",100,off);
	trigger(_allDIR);
	break(off);
	nrintframes(4);
	connections(DanceIdle);
}

action(DanceUp)
{
	file("pc\actors\Prost1\xxx\DnceCF1.ske",100,off);
	trigger(_allDIR);
	break(off);
	nrintframes(4);
	connections(DanceIdle);
}

action(DanceDown)
{
	file("pc\actors\Prost1\xxx\DnceCB1.ske",100,off);
	trigger(_allDIR);
	break(off);
	nrintframes(4);
	connections(DanceIdle);
}

action(EndDance)
{
	file("pc\actors\prost1\xxx\DanceRtn.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(off);
	nomove(on);
	connections(GenIdle);	
}


/////////////////////////////////////////////////////////////////////////////////////////
//	TURNING
/*
action(Prost1TurnLeftRightEnd)
{
	//	file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
//		file("pc\actors\Chot\xxx\MTrnStpC.ske",100,off,100);
		trigger(_DIRnotendofanim|_noDIR);
		break(on);
		nrintframes(6);
		intforloop(off);
		connections(Prost1TurnLeftRightEnd,Prost1Spread,Prost1StandShoot,Prost1TurnLeft,Prost1TurnRight,Prost1Idle);
}*/

action(Prost1TurnLeftCombat)
{
//		file("pc\actors\Prost1\xxx\FTrnLeft.ske",100,on);

		file("pc\actors\Subgirl1\xxx\SbTrLSt.ske",100,off,100,_AIclassSubgirl);// Subgirl start turn left
		file("pc\actors\Subgirl1\xxx\SbTrLLp.ske",100,on,100,_AIclassSubgirl);//Subgirl turn left loop
	
		file("pc\actors\Prost1\xxx\FTrLStCm.ske",100,off,100,-1,_DIRcombatmode);//combat start turn left
		file("pc\actors\Prost1\xxx\FTrLLpCm.ske",100,on,100,-1,_DIRcombatmode);//combat turn left loop

		file("pc\actors\Domina\xxx\DTrLStNc.ske",100,off,100);//Domina start turn left non combat w/ gun
		file("pc\actors\Domina\xxx\DTrLLpNc.ske",100,on,100);//Domina turn left loop non combat w/gun

		trigger(_DIRleft);
		break(on);
		nrintframes(4);
		connections(Prost1Spread,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}

action(Prost1TurnRightCombat)
{
//		file("pc\actors\Prost1\xxx\FTrnRigt.ske",100,on);
		file("pc\actors\Subgirl1\xxx\SbTrRSt.ske",100,off,100,_AIclassSubgirl);// Subgirl start turn left
		file("pc\actors\Subgirl1\xxx\SbTrRLp.ske",100,on,100,_AIclassSubgirl);//Subgirl turn left loop

		file("pc\actors\Prost1\xxx\FTrRStCm.ske",100,off,100,-1,_DIRcombatmode);//Combat start turn right
		file("pc\actors\Prost1\xxx\FTrRLpCm.ske",100,on,100,-1,_DIRcombatmode);//Combat turn right loop

		file("pc\actors\Domina\xxx\DTrRStNc.ske",100,off,100);//Domina start turn right non combat w/ gun
		file("pc\actors\Domina\xxx\DTrRLpNc.ske",100,on,100);//Domina turn right loop non combat w/ gun

		trigger(_DIRright);
		break(on);
		nrintframes(4);
		connections(Prost1Spread,Prost1StandShoot,Prost1TurnLeftCombat,Prost1TurnRightCombat,Prost1Idle);
}

action(Prost1TurnLeft)
{
//		file("pc\actors\Prost1\xxx\PTrLStNc.ske",100,off,100,_AIclassprost);//Prost start turn left
//		file("pc\actors\Prost1\xxx\PTrLLpNc.ske",100,on,100,_AIclassprost);//Prost turn left loop
//		file("pc\actors\Domina\xxx\DTrLStNc.ske",100,off,100);//Domina start turn left
//		file("pc\actors\Domina\xxx\DTrLLpNc.ske",100,on,100);//Domina turn left loop
		file("pc\actors\Subgirl1\xxx\SbTrLSt.ske",100,off,100,_AIclassSubgirl);// Subgirl start turn left
		file("pc\actors\Subgirl1\xxx\SbTrLLp.ske",100,on,100,_AIclassSubgirl);//Subgirl turn left loop

		file("pc\actors\Prost1\xxx\FTLNgCmS.ske",100,off,100,-1,_DIRcombatmode);//Fem start turn left No Gun Combat
		file("pc\actors\Prost1\xxx\FTLNgCmL.ske",100,on,100,-1,_DIRcombatmode);//Fem turn left No Gun Combat

		file("pc\actors\Prost1\xxx\PTrLStNc.ske",100,off,100);//Prost start turn left
		file("pc\actors\Prost1\xxx\PTrLLpNc.ske",100,on,100);//Prost turn left loop



		trigger(_DIRleft);
		break(on);
		nrintframes(4);
		connections(Prost1Spread,Prost1StandShoot,Prost1TurnLeft,Prost1TurnRight,Prost1Idle);
}

action(Prost1TurnRight)
{
//		file("pc\actors\Prost1\xxx\PTrRStNc.ske",100,off,100,_AIclassprost);//prost start turn right
//		file("pc\actors\Prost1\xxx\PTrRLpNc.ske",100,on,100,_AIclassprost);//prost turn right loop
//		file("pc\actors\Domina\xxx\DTrRStNc.ske",100,off,100);//Domina start turn left
//		file("pc\actors\Domina\xxx\DTrRLpNc.ske",100,on,100);//Domina turn left loop
		file("pc\actors\Subgirl1\xxx\SbTrRSt.ske",100,off,100,_AIclassSubgirl);// Subgirl start turn left
		file("pc\actors\Subgirl1\xxx\SbTrRLp.ske",100,on,100,_AIclassSubgirl);//Subgirl turn left loop

		file("pc\actors\Prost1\xxx\FTRNgCmS.ske",100,off,100,-1,_DIRcombatmode);//Fem start turn left No Gun Combat
		file("pc\actors\Prost1\xxx\FTRNgCmL.ske",100,on,100,-1,_DIRcombatmode);//Fem turn left No Gun Combat

		file("pc\actors\Prost1\xxx\PTrRStNc.ske",100,off,100);//prost start turn right
		file("pc\actors\Prost1\xxx\PTrRLpNc.ske",100,on,100);//prost turn right loop

		trigger(_DIRright);
		break(on);
		nrintframes(4);
		connections(Prost1Spread,Prost1StandShoot,Prost1TurnLeft,Prost1TurnRight,Prost1Idle);
}

action(Prost1HitWallTurnLeft)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(Prost1HitWallSpread);
}

action(Prost1HitWallTurnRight)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(Prost1HitWallSpread);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	JUMP AND FALL


/////////////////////////////////////////////////////////////
////////////NEW JUMPING CODE/////////////////////////////////
/////////////////////////////////////////////////////////////
//

action(Prost1Jump)	//Lead directly to next animation
{
		trigger(_DIRjump);
		AIClass(_AIClassProstSkeleton);
		nrintframes(-1);
		connections(Prost1JumpBL,Prost1JumpBR,Prost1JumpBackwards,Prost1JumpFL,Prost1JumpL,Prost1JumpFR,Prost1JumpR,Prost1JumpForward,Prost1JumpInPlace);
}


action(Prost1JumpHigh)
{
		file("pc\actors\Prost1\xxx\FJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallInplace);
}

action(Prost1JumpMedium)
{
		file("pc\actors\Prost1\xxx\FJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHigh,Prost1FallInplace);
}


action(Prost1JumpHighB)
{
		file("pc\actors\Prost1\xxx\FRBJmpC.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallInplace);
}

action(Prost1JumpMediumB)
{
		file("pc\actors\Prost1\xxx\FRBJmpB.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHighB,Prost1FallInplace);
}

action(Prost1JumpHighR)
{
		file("pc\actors\Prost1\xxx\FRnJmpC.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(90);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallR);
}

action(Prost1JumpMediumR)
{
		file("pc\actors\Prost1\xxx\FRnJmpB.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHighR,Prost1FallR);
}

action(Prost1JumpHighL)
{
		file("pc\actors\Prost1\xxx\FRnJmpC.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-90);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallL);
}

action(Prost1JumpMediumL)
{
		file("pc\actors\Prost1\xxx\FRnJmpB.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHighL,Prost1FallL);
}

action(Prost1JumpHigh45R)
{
		file("pc\actors\Prost1\xxx\FRnJmpC.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallFR);
}

action(Prost1JumpMedium45R)
{
		file("pc\actors\Prost1\xxx\FRnJmpB.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHigh45R,Prost1FallFR);
}

action(Prost1JumpHigh45L)
{
		file("pc\actors\Prost1\xxx\FRBJmpC.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallFL);
}

action(Prost1JumpMedium45L)
{
		file("pc\actors\Prost1\xxx\FRnJmpB.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHigh45L,Prost1FallFL);
}

action(Prost1JumpHighB45R)
{
		file("pc\actors\Prost1\xxx\FRBJmpC.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallBR);
}

action(Prost1JumpMediumB45R)
{
		file("pc\actors\Prost1\xxx\FRBJmpB.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHighB45R,Prost1FallBR);
}

action(Prost1JumpHighB45L)
{
		file("pc\actors\Prost1\xxx\FRnJmpC.ske",100,off,100);
		move(0,Prost1JumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallBL);
}

action(Prost1JumpMediumB45L)
{
		file("pc\actors\Prost1\xxx\FRBJmpB.ske",100,off,100);
		move(0,Prost1JumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpHighB45L,Prost1FallBL);
}


action(Prost1JumpInPlace)
{
		file("pc\actors\Prost1\xxx\FJmpA.ske",100,off,100);
		move(0,Prost1JumpSpeedLow,0);
		trigger(_DIRjump);
		nrintframes(1);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);

		connections(Prost1JumpMedium,Prost1FallInplace);
}

action(Prost1JumpForward)
{
//		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		file("pc\actors\Prost1\xxx\FRnJmpA.ske",100,off,100);
		trigger(_DIRforward);
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,0);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpMedium,Prost1FallForward);
}

action(Prost1JumpL)
{
		file("pc\actors\Prost1\xxx\FRnJmpA.ske",100,off,100);
//		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		trigger(_DIRsideleft);
		rotate(-90)
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpMediumL,Prost1FallL);
}

action(Prost1JumpFL)
{
//		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		file("pc\actors\Prost1\xxx\FRnJmpA.ske",100,off,100);
		trigger(_DIRsideleft|_DIRforward);
		rotate(-45)
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpMedium45L,Prost1FallFL);
}
action(Prost1JumpR)
{
//		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		file("pc\actors\Prost1\xxx\FRnJmpA.ske",100,off,100);
		trigger(_DIRsideright);
		rotate(90)
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpMediumR,Prost1FallR);
}

action(Prost1JumpFR)
{
//		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		file("pc\actors\Prost1\xxx\FRnJmpA.ske",100,off,100);
		trigger(_DIRsideright|_DIRforward);
		rotate(45)
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpMedium45R,Prost1FallFR);
}

action(Prost1JumpBackwards)
{
		file("pc\actors\Prost1\xxx\FRBJmpA.ske",100,off,100);
		trigger(_DIRbackward);
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1JumpMediumB,Prost1FallBackwards);
}

action(Prost1JumpBR)
{
		file("pc\actors\Prost1\xxx\FRBJmpA.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideright);
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,0);
		break(off);
		gravity(off);
		rotate(-45)
		ydeltafromzeroframe(off);
		connections(Prost1JumpMedium45L,Prost1FallBR);
}

action(Prost1JumpBL)
{
		file("pc\actors\Prost1\xxx\FRBJmpA.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideleft);
		nrintframes(1);
		move(0,Prost1JumpSpeedLow,0);
		break(off);
		gravity(off);
		rotate(45)
		ydeltafromzeroframe(off);
		connections(Prost1JumpMedium45R,Prost1FallBL);
}


action(Prost1fallForward)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 

		trigger(_AllDir);
		nrintframes(0);
		ydeltafromzeroframe(off);
		break(off);
		connections(Prost1fallForward);
}

action(Prost1fallFL)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(Prost1fallFL);
}
action(Prost1fallFR)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);

		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(Prost1fallFR);
}
action(Prost1fallL)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);

		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-90)
		connections(Prost1fallL);
}
action(Prost1fallR)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);

		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(90)
		connections(Prost1fallR);
}

action(Prost1fallInPlace)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		trigger(_AllDir);
		AIClass(_AIClassProstSkeleton);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(Prost1fallInPlace);
}

action(Prost1fallBackwards)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(Prost1fallBackwards);
}
action(Prost1fallBL)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(Prost1fallBL);
}
action(Prost1fallBR)
{
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(Prost1fallBR);
}

action(Prost1fall)	//Fall when falling from edge only
{
		file("pc\actors\Subgirl1\xxx\SgJmpD.ske",100,off,100,_AIclassSubgirl);
		file("pc\actors\Prost1\xxx\FJmpFall.ske",100,on);					//Male jump falling loop. 
		trigger(_AllDir);
		AIClass(_AIClassProstSkeleton);
		nrintframes(7);
		offset(8);
		ydeltafromzeroframe(off);
		break(on);
		connections(Prost1Fall);
}

action(Prost1TouchDown)
{
		file("pc\actors\Subgirl1\xxx\SgJmpLn1.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\Chot\xxx\mjmp4lg.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassProstSkeleton);
		nrintframes(5);
		break(on);
		connections(Prost1spread,Prost1StandShoot,Prost1TouchDown,Prost1Idle);
}






//------------------------------------------subgirl jump

/////////////////////////////////////////////////////////////////////////////////////////
//	JUMP AND FALL
action(SubGirlJump) //Lead directly to next animation
{
		trigger(_DIRjump);
		AIClass(_AIclassSubgirl|_AIclassFemale);
		nrintframes(-1);
		connections(SubGirlJumpBL,SubGirlJumpBR,SubGirlJumpBackwards,SubGirlJumpFL,SubGirlJumpL,SubGirlJumpFR,SubGirlJumpR,SubGirlJumpForward,SubGirlJumpInPlace);
}

action(SubGirlJumpHigh)
{
		file("pc\actors\Subgirl1\xxx\SgJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallInplace);
}

action(SubGirlJumpMedium)
{
		file("pc\actors\Subgirl1\xxx\SgJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpHigh,Prost1FallInplace);
}


action(SubGirlJumpHighR)
{
		file("pc\actors\Subgirl1\xxx\SgJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallR);
}

action(SubGirlJumpMediumR)
{
		file("pc\actors\Subgirl1\xxx\SgJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpHighR,Prost1FallR);
}

action(SubGirlJumpHighL)
{
		file("pc\actors\Subgirl1\xxx\SgJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallL);
}

action(SubGirlJumpMediumL)
{
		file("pc\actors\Subgirl1\xxx\SgJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpHighL,Prost1FallL);
}

action(SubGirlJumpHigh45R)
{
		file("pc\actors\Subgirl1\xxx\SgJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallFR);
}

action(SubGirlJumpMedium45R)
{
		file("pc\actors\Subgirl1\xxx\SgJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpHigh45R,Prost1FallFR);
}

action(SubGirlJumpHigh45L)
{
		file("pc\actors\Subgirl1\xxx\SgJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1FallFL);
}

action(SubGirlJumpMedium45L)
{
		file("pc\actors\Subgirl1\xxx\SgJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		rotate(-45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpHigh45L,Prost1FallFL);
}


action(SubGirlJumpInPlace)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedLow,0);
		trigger(_DIRjump);
		nrintframes(3);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium,Prost1FallInplace);
}

action(SubGirlJumpForward)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		//file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRforward);
		nrintframes(5);
		move(0,SubGirlJumpSpeedLow,0);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium,Prost1FallForward);
}

action(SubGirlJumpL)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRsideleft);
		rotate(-90)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMediumL,Prost1FallL);
}

action(SubGirlJumpFL)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRsideleft|_DIRforward);
		rotate(-45)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium45L,Prost1FallFL);
}
action(SubGirlJumpR)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRsideright);
		rotate(90)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMediumR,Prost1FallR);
}

action(SubGirlJumpFR)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRsideright|_DIRforward);
		rotate(45)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium45R,Prost1FallFR);
}

action(SubGirlJumpBackwards)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRbackward);
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium,Prost1FallBackwards);
}

action(SubGirlJumpBR)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideright);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(-45)
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium45L,Prost1FallBR);
}

action(SubGirlJumpBL)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideleft);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(45)
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium45R,Prost1FallBL);
}

//*****************************************************************************************************************************************************



//-------------------end subgirl jump







action(Prost1RunUpStairs)
{
		file("pc\actors\Prost1\xxx\FRnStar2.ske",100,on);
		trigger(_DIRforward);
		AIClass(_AIClassProstSkeleton);
		break(off);
//		offset(4);
		nrintframes(8);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(Prost1RunUpStairs);
}


action(Prost1PressGun)
{
		file("pc\actors\prost1\xxx\FTchBtnC.ske",100,off,100,-1,_DIRcombatmode);
	    file("pc\actors\prost1\xxx\FTchButn.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		nrintframes(4);
		break(off);
		connections(prost1idle);
}


//	PROST THROWN ACTIONS
//

action(Prost1ThrownBack)
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,on);	//Backwards hold frame
		trigger(_alldir);
		AIClass(_AIClassProstSkeleton);
		break(on);
		collision(on);
		nrintframes(4);
		ActionSubRoutine(Sub_SetAttackerToEnemyAndHandleThrown);
		connections(Prost1ThrownBackLand,Prost1ThrownBack);
}

action(Prost1ThrownBackLand)
{
		file("pc\actors\Chot\xxx\ThBklndP.ske",100,off,100,-1,_DIRnotai|_DIRalive);	//Possessed shorter landing. and alive
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);	//Backwards, land on back
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(Prost1GetUpFromBackRollBack,Prost1GetUpFromBackKipForward,Prost1GetUpFromBack,Prost1ThrownBackLand);
}

action(Prost1ThrownForward)
{
		file("pc\actors\Chot\xxx\ThfwHld1.ske",100,on);	//Forward hold frame
		trigger(_alldir);
		AIClass(_AIClassProstSkeleton);
		break(on);
		collision(on);
		nrintframes(4);
		ActionSubRoutine(Sub_SetThrown);
		connections(Prost1ThrownForwardLand,Prost1ThrownForward);
}

action(Prost1ThrownForwardLand)
{
		file("pc\actors\Chot\xxx\ThFwLnd.ske",100,off);		//forward, land face down, and get up (gabe)
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(Prost1GetUpFromFrontForwardKip,Prost1GetUpFromFrontFaceDown,Prost1ThrownForwardLand);
}

action(Prost1ThrownRight)
{
		file("pc\actors\Chot\xxx\ThrnHldR.ske",100,on);	//Right Hold frame #1
		trigger(_alldir);
		AIClass(_AIClassProstSkeleton);
		break(on);
		collision(on);
		ActionSubRoutine(Sub_SetThrown);
		nrintframes(4);
		connections(Prost1ThrownRightLand,Prost1ThrownRight);
}

action(Prost1ThrownRightLand)
{
		file("pc\actors\Chot\xxx\ThrnRite.ske",100,off);	//Right land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(0);
		connections(Prost1GetUpFromRightFaceDownForwardKip,Prost1GetUpFromRightFaceDownPossessed,Prost1GetUpFromRightFaceDown,Prost1ThrownRightLand);
}

action(Prost1ThrownLeft)
{
		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		trigger(_alldir);
		AIClass(_AIClassProstSkeleton);
		break(on);
		ActionSubRoutine(Sub_SetThrown);
		collision(on);
		nrintframes(4);
		connections(Prost1ThrownLeftLand,Prost1ThrownLeft);
}

action(Prost1ThrownLeftLand)
{
		file("pc\actors\Chot\xxx\Thrnleft.ske",100,off);	//Left land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(0);
		connections(Prost1GetUpFromLeftFaceDownForwardKip,Prost1GetUpFromLeftFaceDownPossessed,Prost1GetUpFromLeftFaceDown,Prost1ThrownLeftLand);
}

action(Prost1GetUpFromBack)
{
		file("pc\actors\chot\xxx\MSpinKip.ske",5,off,100,-1,_DIRnotai,Sub_GetUpClearThrown64); //Male stand from back, possessed. Kip up.
		file("pc\actors\chot\xxx\MRolUpFP.ske",100,off,100,-1,_DIRnotai,Sub_GetUpClearThrown38); //Male stand from back, possessed. Kip up.
		file("pc\actors\chot\xxx\mstndfbk.ske",100,off,110,-1,-1,Sub_GetUpClearThrown84);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(4);
		connections(GenIdle);
}

action(Prost1GetUpFromBackRollBack)
{
		file("pc\actors\chot\xxx\MSRlBkBp.ske",100,off,100,-1,-1,Sub_GetUpClearThrown36); //Male stand from back, possessed. Kip up.
		trigger(_DIRalive|_DIRbackward|_DIRnotai);
		AIClass(_AIClassProstSkeleton);
		break(off);
		collision(on);
		nrintframes(8);
		connections(GENIdle);
}

action(Prost1GetUpFromBackKipForward)
{
		file("pc\actors\chot\xxx\MStndFBP.ske",100,off,100,-1,-1,Sub_GetUpClearThrown36); //Male stand from back, possessed. Kip up.
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		AIClass(_AIClassProstSkeleton);
		break(off);
		collision(on);
		nrintframes(8);
		connections(GENIdle);
}

action(Prost1GetUpFromFrontFaceDown)
{
		file("pc\actors\chot\xxx\MstandF2.ske",100,off,80,-1,_DIRnotai,Sub_GetUpClearThrown24); //Male stand from front, possessed. faster.
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(0);
		connections(Prost1Idle);
}

action(Prost1GetUpFromFrontForwardKip)
{
		file("pc\actors\chot\xxx\MCw2StFw.ske",100,off,155,-1,-1,Sub_GetUpClearThrown55);
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		break(off);
		collision(on);
		nrintframes(18);
		connections(GENIdle);
}


action(Prost1GetUpFromBackFaceDown)
{
		file("pc\actors\chot\xxx\MstandF2.ske",100,off,80,-1,_DIRnotai,Sub_GetUpClearThrown24); //Male stand from front, possessed. faster.
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(180);
		break(off);
		collision(on);
		nrintframes(0);
		connections(Prost1Idle);
}

action(Prost1GetUpFromRightFaceDown)
{
		file("pc\actors\Chot\xxx\ThrnRStn.ske",100,off,110,-1,-1,Sub_GetUpClearThrown38);
		trigger(_DIRalive);
		//rotate(90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(Prost1Idle);
}

action(Prost1GetUpFromLeftFaceDown)
{
		file("pc\actors\Chot\xxx\ThrnLStS.ske",100,off,200,-1,_DIRnotai,Sub_GetUpClearThrown68);
 		file("pc\actors\Chot\xxx\ThrnLStS.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		//rotate(-90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(Prost1Idle);
}

action(Prost1GetUpFromRightFaceDownPossessed)
{
		file("pc\actors\chot\xxx\MstandF2.ske",100,off,80,-1,-1,Sub_GetUpClearThrown24); //Male stand from front, possessed. faster.
		//file("pc\actors\Chot\xxx\ThrnRStn.ske",100,off,110,-1,-1,Sub_GetUpClearThrown38);
		trigger(_DIRalive|_DIRnotai);
		rotate(90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(GENIdle);
}

action(Prost1GetUpFromLeftFaceDownPossessed)
{
		file("pc\actors\chot\xxx\MstandF2.ske",100,off,80,-1,-1,Sub_GetUpClearThrown24); //Male stand from front, possessed. faster.
		//file("pc\actors\Chot\xxx\ThrnRStn.ske",100,off,110,-1,-1,Sub_GetUpClearThrown38);
		trigger(_DIRalive|_DIRnotai);
		rotate(-90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(GENIdle);
}

action(Prost1GetUpFromRightFaceDownForwardKip)
{
		file("pc\actors\chot\xxx\MCw2StFw.ske",100,off,155,-1,-1,Sub_GetUpClearThrown55);
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		break(off);
		collision(on);
		rotate(90);
		//nrintframes(18);
		connections(GENIdle);
}

action(Prost1GetUpFromLeftFaceDownForwardKip)
{
		file("pc\actors\chot\xxx\MCw2StFw.ske",100,off,155,-1,-1,Sub_GetUpClearThrown55);
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		break(off);
		collision(on);
		rotate(-90);
		//nrintframes(18);
		connections(GENIdle);
}



action(Prost1Reload)		//Reloading weapon
{
		file("pc\actors\Prost1\xxx\FReload.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(4);
		intforloop(on);
		connections(Prost1Idle);
}

action(Prost1ReloadCrouch)		//Reloading weapon
{
		file("pc\actors\Prost1\xxx\FCrRelod.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassProstSkeleton);
		break(off);
		nrintframes(4);
		intforloop(on);
		connections(Prost1CrouchIdle);
}

//==========================================
//==	D O M I N A     A C T I O N		  ==
//==========================================

/*

Action(DomIdleNoGun)
{
	//	file("pc\actors\Domina\xxx\DmIdl2.ske",30,on);//looking at fingernails
//		file("pc\actors\Domina\xxx\DmIdl1.ske",65,on);//breathing
//		file("pc\actors\Domina\xxx\DmIdl3.ske",100,on);//look left/right
		trigger(_allDIR);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(DomSpread,DomStandShoot,DomTurnLeft,DomTurnRight,Domidle);
}

*/



//==========================================
//==	D A N C E R     A C T I O N		  ==
//==========================================
Action(FemDance)
{
	file("pc\actors\prost1\xxx\D_Dance1.ske",25,on);
	file("pc\actors\prost1\xxx\D_Dance2.ske",50,on);
	file("pc\actors\prost1\xxx\D_Dance3.ske",75,on);
	file("pc\actors\prost1\xxx\D_Dance4.ske",100,on);
	
	break(off);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(GenIdle);
}



//==============================================
//==	W A I T R E S S     A C T I O N       ==
//==============================================
Action(WaitressIdle)
{
	file("pc\actors\prost1\xxx\Widle1.ske",33,on);
	file("pc\actors\prost1\xxx\Widle2.ske",66,on);
	file("pc\actors\prost1\xxx\Widle3.ske",100,on);
	
	break(on);
	trigger(_allDIR);
	nrintframes(10);
	intforloop(on);

	connections(WaitressIdle);
} 

Action(WaitressFlirt)
{
	file("pc\actors\prost1\xxx\Widle4.ske",100,on);
	
	break(off);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(Prost1Idle);
}

Action(WaitressSpill)
{
	file("pc\actors\prost1\xxx\Wbumped2.ske",100,off);
	
	break(off);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(Prost1Idle);
}

Action(WaitressClean)
{
	file("pc\actors\prost1\xxx\Wclean.ske",100,off);
	
	break(off);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(Prost1Idle);
}

Action(WaitressPrimp1)
{
	file("pc\actors\prost1\xxx\Wmakeup.ske",100,on);
	
	break(on);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(Prost1Idle);
}

Action(WaitressPrimp2)
{
	file("pc\actors\prost1\xxx\Wbeauty.ske",100,on);
	
	break(on);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(Prost1Idle);
}



//////////////////
// "TRON" MODE  //
//////////////////

Action(DominaGunInit)
{
		file("pc\actors\domina\xxx\GCStart.ske",100,off);
		trigger(_AllDIR);
		break(on);
		nrintframes(8);
		connections(DominaGunInit);
}


