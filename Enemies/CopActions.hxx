

#define CopMaxTurnSpeed 75
#define CopTurnAcc 7
#define CopMaxTurnSpeedWounded 10
#define CopTurnAccWounded 1

#define CopHangMoveIn -30

#define CopJumpSpeed			29		//tonytweakins'
#define CopJumpGravity			3		//tonytweakins'
//#define CopJumpSpeed			14
//#define CopJumpGravity			0.9

#define CopMinHoldJumpAction	5
#define CopMaxTurnSpeedair 60
#define CopTurnAccair 5
#define CopAirSpeed 15	//20
#define CopAirBulb 0.05 //0.1=very soft, 1.0=get speed immediately

#define CopMaxFall		-750	//Fall before he breaks his legs.
#define	DamageCopFall	500	//Maximum, depends on altitude you fall


#define CopJumpSpeedHigh	0
#define CopJumpSpeedMiddle	1
#define CopJumpSpeedLow		9




Action(CopBumpedSpread)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopBumpedGeneric);
//		connections(CopBumpedRight,CopBumpedGeneric);
}




action(CopBumpedGeneric)
{
		file("pc\actors\Bob\xxx\BShtStl1.ske",100,off,100,_AIclassAngel);	// for dwarf chot
		file("pc\actors\Chot\xxx\ChBumpdG.ske",100,on,100,_AIclassChot);	// Quick Talk Gesture start!
		file("pc\actors\Chot\xxx\MBumpdG.ske",100,off);
		//file("pc\actors\Chot\xxx\MTk1Gst2.ske",100,on);	// Quick Talk Gesture
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassCopSkeleton);
		break(off);
		collision(on);
		nrintframes(2);
		connections(CopSpreadOut,CopBumpedGeneric,CopTurnLeft,CopTurnRight,CopIdle);
}

action(CopBumpedRight)
{
		file("pc\actors\Chot\xxx\MBumpdR.ske",100,off,130); //Bumped from right side

		flag(_SXAAalignmovingmaster);

		AIClass(_AIClassCopSkeleton);

		//AIClass(_AIclassMale|_AIclasscop);

		AlignAngle(90);
		TargetAngle(90);
		AttackHeight(50);
		AlignDistance(100);
		AlignSlack(60);	
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(0);

		AttachActionStartAtFrame(0);
		DamageFrame(2);
		Power(0);
//		AttachAction(CopBoxingLink);
		TargetAIClass(_AIClassAllButAngel);
//		TargetAIClass(_AIclassfriendly);


		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}



SubRoutine(Sub_SetThrown)
{

		if(vframe<=1 && VAIclass!=_AIclassbeast)					//should maybe be ==0 ?
		{
			state(_or,StateThrown);
			State(_clr,StateCrouching);
		}

		if(vactorflag==_AFLAGAttached)
		{
			CallSub(Sub_RandomKickedSFX);
		}
}



Action(CopKickGeneric)
{
	file("pc\actors\Chot\xxx\MWrKikLw.ske",100,off);
	AIClass(_AIClassAllButAngel);
	trigger(_allDIR);
	break(off);
	nrintframes(8);
	gravity(off);
	collision(off);
	connections(CopIdle);
}



//	AI specific reactions

Action(CopRepresent)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off,100,_AIclassAngel);

		//file("pc\actors\Chot\xxx\MTk1Gst2.ske",50);	//point at player (double-jab), use for 'hey-you!'
		//file("pc\actors\Chot\xxx\MTk1Gst3.ske",100);
		file("pc\actors\Abeast\xxx\AbIdle1.ske",100,on,100,_AIclassabeast);//breathing anim, do this 80% of the time

		file("pc\actors\Behemoth\xxx\BRcgnz.ske",100,on,100,_AIclassbeast);//lean forward cock head

		file("pc\actors\Pimp\xxx\Pspot.ske",50,on,100,_AIclasspimp);   //Throw sign then wave	
		file("pc\actors\Pimp\xxx\Pspot1.ske",100,on,100,_AIclasspimp);//Spotting bob the the first time

		file("pc\actors\prost1\xxx\Widle4.ske",100,on,100,_AIclassbarpeople); //Waitress flirt animation

		file("pc\actors\Prost1\xxx\Pwork1.ske",33,on,100,_AIclassprost);//
		file("pc\actors\Prost1\xxx\Pwork2.ske",66,on,100,_AIclassprost);//prostitute looking for a john
		file("pc\actors\Prost1\xxx\Pwork3.ske",100,on,100,_AIclassprost);//


		file("pc\actors\Domina\xxx\DmTlk1Nc.ske",100,on,100,_AIclassfemale);//
		file("pc\actors\Domina\xxx\DmTlk2Nc.ske",100,on,100,_AIclassfemale);//

		file("pc\actors\Chot\xxx\ChRcgnz1.ske",100,on,100,_AIclassChot);	// Quick Talk Gesture start!

//		file("pc\actors\Chot\xxx\MSalute.ske",100,on,100,_AIclasscop,_DIRhavegun);	// Salute

		file("pc\actors\Chot\xxx\MTk1strt.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture start!
		file("pc\actors\Chot\xxx\MTk1Gst2.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
		file("pc\actors\Chot\xxx\MTk1Gst3.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
		file("pc\actors\Chot\xxx\MTk1end.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture

		file("pc\actors\Chot\xxx\MTk1strt.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture start!
		file("pc\actors\Chot\xxx\MTk1Gst2.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
		file("pc\actors\Chot\xxx\MTk1Gst4.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
		file("pc\actors\Chot\xxx\MTk1end.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture

		file("pc\actors\Dwellr1\xxx\DwMidl4.ske",100,on,100);		//Throwing signs
		trigger(_noDIR);
		break(off);
		nrintframes(12);
		connections(CopRepresentIdle);
}

Action(CopRepresentShort)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off,100,_AIclassAngel);

		//file("pc\actors\Chot\xxx\MTk1Gst2.ske",50);	//point at player (double-jab), use for 'hey-you!'
		//file("pc\actors\Chot\xxx\MTk1Gst3.ske",100);
		file("pc\actors\Abeast\xxx\AbIdle1.ske",100,on,100,_AIclassabeast);//breathing anim, do this 80% of the time

		file("pc\actors\Behemoth\xxx\BRcgnz.ske",100,on,100,_AIclassbeast);//lean forward cock head
	
		file("pc\actors\Pimp\xxx\Pspot.ske",50,on,100,_AIclasspimp);   //Throw sign then wave	
		file("pc\actors\Pimp\xxx\Pspot1.ske",100,on,100,_AIclasspimp);//Spotting bob the the first time

		file("pc\actors\Prost1\xxx\Pwork1.ske",33,on,100,_AIclassprost);//
		file("pc\actors\Prost1\xxx\Pwork2.ske",66,on,100,_AIclassprost);//prostitute looking for a john
		file("pc\actors\Prost1\xxx\Pwork3.ske",100,on,100,_AIclassprost);//

		file("pc\actors\Domina\xxx\DmTlk1Nc.ske",50,on,100,_AIclassfemale);//
		file("pc\actors\Domina\xxx\DmTlk2Nc.ske",100,on,100,_AIclassfemale);//

		file("pc\actors\Chot\xxx\ChRcgnz1.ske",100,on,100,_AIclassChot);	// Quick Talk Gesture start!

//		file("pc\actors\Chot\xxx\MSalute.ske",100,on,100,_AIclasscop,_DIRhavegun);	// Salute

//		file("pc\actors\Chot\xxx\MTk1strt.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture start!
		file("pc\actors\Chot\xxx\MTk1Gst2.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
//		file("pc\actors\Chot\xxx\MTk1Gst3.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
//		file("pc\actors\Chot\xxx\MTk1end.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture

//		file("pc\actors\Chot\xxx\MTk1strt.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture start!
//		file("pc\actors\Chot\xxx\MTk1Gst2.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
		file("pc\actors\Chot\xxx\MTk1Gst4.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
//		file("pc\actors\Chot\xxx\MTk1end.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture

		file("pc\actors\Dwellr1\xxx\DwMidl4.ske",100,on,100);		//Throwing signs
		trigger(_noDIR);
		break(off);
		nrintframes(16);
		connections(CopRepresentIdle);
}

Action(CopRepresentSalute)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off,100,_AIclassAngel);

		//file("pc\actors\Chot\xxx\MTk1Gst2.ske",50);	//point at player (double-jab), use for 'hey-you!'
		//file("pc\actors\Chot\xxx\MTk1Gst3.ske",100);
		file("pc\actors\Pimp\xxx\Pspot.ske",50,on,100,_AIclasspimp);   //Throw sign then wave	
		file("pc\actors\Pimp\xxx\Pspot1.ske",100,on,100,_AIclasspimp);//Spotting bob the the first time

		file("pc\actors\Prost1\xxx\Pwork1.ske",33,on,100,_AIclassprost);//
		file("pc\actors\Prost1\xxx\Pwork2.ske",66,on,100,_AIclassprost);//prostitute looking for a john
		file("pc\actors\Prost1\xxx\Pwork3.ske",100,on,100,_AIclassprost);//

		file("pc\actors\Domina\xxx\DmTlk1Nc.ske",100,on,100,_AIclassfemale);//
		file("pc\actors\Domina\xxx\DmTlk2Nc.ske",100,on,100,_AIclassfemale);//

		file("pc\actors\Chot\xxx\MSalute.ske",100,on,100,_AIclasscop);	// Salute

//		file("pc\actors\Chot\xxx\MTk1strt.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture start!
//		file("pc\actors\Chot\xxx\MTk1Gst2.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
//		file("pc\actors\Chot\xxx\MTk1Gst3.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
//		file("pc\actors\Chot\xxx\MTk1end.ske",50,on,100,-1,_DIRhavegun);	// Quick Talk Gesture

//		file("pc\actors\Chot\xxx\MTk1strt.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture start!
//		file("pc\actors\Chot\xxx\MTk1Gst2.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
//		file("pc\actors\Chot\xxx\MTk1Gst4.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture
//		file("pc\actors\Chot\xxx\MTk1end.ske",100,on,100,-1,_DIRhavegun);	// Quick Talk Gesture

//		file("pc\actors\Chot\xxx\WrkGrvl.ske",100,on,100,_AIclassworker|_AIclassscientist|_AIclassmedic);	// grovel
		file("pc\actors\Chot\xxx\WrkGrvl.ske",100,on,100,_AIclassmedic);	// grovel
		file("pc\actors\Chot\xxx\WrkGrvl.ske",100,on,100,_AIclassscientist);	// grovel
		file("pc\actors\Chot\xxx\WrkGrvl.ske",100,on,100,_AIclassworker);	// grovel

		file("pc\actors\Dwellr1\xxx\DwMidl4.ske",100,on,100);		//Throwing signs
		trigger(_noDIR);
		break(off);
		nrintframes(12);
		connections(CopRepresentIdle);
}


action(WorkerRepresentKneel)
{
		file("pc\actors\Worker\xxx\WrkKnRec.ske",100,on);

		trigger(_noDIR);
		break(off);
		nrintframes(8);
		connections(WorkerRepresentKneel);
}
Action(CopRepresentSmoking)
{
		file("pc\actors\Chot\xxx\MSmkIdl3.ske",100,on,100);	// Quick Talk Gesture
		trigger(_noDIR);
		break(off);
		nrintframes(8);
		connections(CopRepresentSmokingIdle);
}

Action(CopRepresentSmokingIdle)
{
		file("pc\actors\Chot\xxx\MSmkIdl5.ske",100,on,100);	// Quick Talk Gesture
		trigger(_noDIR);
		break(off);
		nrintframes(8);
		connections(CopRepresentSmokingIdle,CopSpreadOut,CopIdle);
}


Action(CopRepresentIdle)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",100,on,100,_AIclassSubgirl);

		file("pc\actors\Prost1\xxx\PIdle1.ske",100,on,100,_AIclassprost);		//hip stance
		file("pc\actors\Dwellr1\xxx\DwMidl1.ske",100,on,100,_AIclassdweller);		//Breathing
		file("pc\actors\Chot\xxx\ChIdle1.ske",100,on,100,_AIclasschot);	//Breathing heavy:
		file("pc\actors\Pimp\xxx\Pidle2.ske",100,on,100,_AIclasspimp);	//grabbing crotch

		file("pc\actors\prost1\xxx\Widle1.ske",33,on,100,_AIclassbarpeople);
		file("pc\actors\prost1\xxx\Widle2.ske",66,on,100,_AIclassbarpeople); // Waitress Idle Animations
		file("pc\actors\prost1\xxx\Widle3.ske",100,on,100,_AIclassbarpeople);

		file("pc\actors\Domina\xxx\DmIdl1.ske",100,on,100,_AIclassfemale);//breathing
		file("pc\actors\Chot\xxx\Mneidl5p.ske",100,on,100,-1,_DIRhavegun);	//Heavy breathing w/ gun
		file("pc\actors\Chot\xxx\Mnidl4NG.ske",100,on);	//Heavy breathing

		trigger(_noDIR);
		break(off);
		nrintframes(8);
		connections(CopRepresentIdle,CopSpreadOut,CopIdle);
}

Action(CopCrush)
{
		file("pc\actors\Chot\xxx\mded5g.ske",100,off);	//face down
		//file("pc\actors\Chot\xxx\Mcrushed.ske",100,off);	//point at player
		trigger(_allDIR);
		collision(off);
		gravity(off);
		break(off);
		nrintframes(4);
}

Action(CopGesture1)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off,100,_AIclassAngel);
		file("pc\actors\Chot\xxx\MTk1Gst2.ske",50);	//point at player (double-jab), use for 'hey-you!'
		file("pc\actors\Chot\xxx\MTk1Gst3.ske",100);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(GENIdle);
}

Action(CopGesture2)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off,100,_AIclassAngel);
		file("pc\actors\Chot\xxx\MTk1Gst1.ske",100);	//point towards something
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(CopGesture1);
}

Action(CopDramaticGesture)
{
		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off,100,_AIclassAngel);
		file("pc\actors\chot\xxx\MGitGstr.ske",100);	//double point
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(GENIdle);
}

Action(BarmanGestures)
{
		file("pc\actors\Chot\xxx\MTk1Gst3.ske",25);
		file("pc\actors\Chot\xxx\MTk1Gst2.ske",50);	
		file("pc\actors\Chot\xxx\MTk1Gst3.ske",75);
		file("pc\actors\Chot\xxx\MTk1Gst4.ske",100);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(CopIdle);
}
	

Action(WorkerGetLost)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",100,on,100,_AIclassSubgirl);
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MShoo1.ske",35);	//respond to attention command
		file("pc\actors\chot\xxx\MShoo2.ske",70);	//respond to attention command
		file("pc\actors\chot\xxx\MShoo3.ske",100);	//respond to attention command
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(CopSpreadOut,CopIdle);
}

action(WorkerWhatThe)
{
		//file("pc\actors\Chot\xxx\Mwkbkngn.ske",100,on);
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\mdbltake.ske",100,on);						//normal
		//file("pc\actors\Chot\xxx\MwkLmpBk.ske",100,on,100,-1);					//limping
		nrintframes(8);
		trigger(_allDIR);
		break(off);
		connections(CopSpreadOut,CopIdle);
}

Action(PimpConsole)
{
		file("pc\actors\Pimp\xxx\Ppunch.ske",30,on,100,_AIclasspimp);		//Punching buttons on console
		file("pc\actors\Pimp\xxx\Psurvey.ske",60,on,100,_AIclasspimp);		//Angrily survey console
		file("pc\actors\Pimp\xxx\Psurvey2.ske",100,on,100,_AIclasspimp);	//Survey console
		nrintframes(8);
		trigger(_allDIR);
		break(off);
		connections(PimpConsole);
}

Action(CopDrown)
{
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);		//angel drowning
		file("pc\actors\chot\xxx\Mdrnd.ske",100,off);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(8);
		connections(CopDrownDead);
}

Action(CopDrownDead)
{
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);		//angel drowning
		file("pc\actors\Chot\xxx\MFltDed.ske",100,off);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(8);
		connections(CopDrownDeadLoop);
}

Action(CopDrownDeadLoop)
{
		file("pc\actors\Bob\xxx\BDeath2.ske",100,on,100,_AIClassAngel); //angel drowning
		file("pc\actors\Chot\xxx\MFltDedL.ske",100,on);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(3);
		connections(CopDrownDeadLoop);
}

//	SHOT BY SNIPER REACTIONS
//

Action(CopShotInLeg)
{
		file("pc\actors\chot\xxx\MSnpLeg2.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\chot\xxx\MSnpLeg3.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopCrawlIdle);
}

subroutine(Sub_CopShotFrHead)
{
		if(vframe==18)
		{
			sample(SFXManFallToGround,-1);
		}
}
Action(CopShotFrHead)
{
		file("pc\actors\chot\xxx\mded6g.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopShotFrHead);
		ActionSubRoutine(Sub_CopShotFrHead);
}

Action(CopShotFrTorso)
{
		file("pc\actors\chot\xxx\mded1.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopShotFrTorso);
}
Action(CopShotFrRShoulder)
{
		file("pc\actors\chot\xxx\mded2.ske",100,off);
		//file("pc\actors\chot\xxx\Fstwnd2.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		ActionSubRoutine(Sub_SetThrown);
		connections(CopGetUpFromBackFaceDown);
}
Action(CopShotFrLShoulder)
{
		file("pc\actors\chot\xxx\Fstwnd2.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopIdle);
}
Action(CopShotGeneric)
{
		file("pc\actors\chot\xxx\Mwund3.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopIdle);
}
Action(CopShotCrawl)
{
		file("pc\actors\chot\xxx\MCrlKikU.ske",100,off);
		trigger(_allDIR);
		nrintframes(4);
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		AIClass(_AIClassCopSkeleton);
		connections(CopCrawlIdle,GENIdle);
}
Action(CopShotBkHead)
{
		file("pc\actors\chot\xxx\mded4g.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopShotBkHead);
}
Action(CopShotBkBack)
{
		file("pc\actors\chot\xxx\MWundg2.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopIdle);
}


//---------


Action(NukeBatteryDrop)
{
		file("pc\actors\Scientst\xxx\SciDropB.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(CopIdle);
}

Action(NukeBatteryPick)
{
		file("pc\actors\Scientst\xxx\SciGetBt.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(CopIdle);
}

action(MedicWorking)
{
		//if you change the order or add any more anims here, you gotta tell TONY :)
		file("pc\actors\Chot\xxx\MedWld2.ske",30,on);	//Loop working/sewing on crushed guy animation. Lots of blood:
		file("pc\actors\Chot\xxx\MedWld3.ske",60,on);	//Look at flesh in right hand, then toss it over shoulder at frame #73:
		file("pc\actors\Chot\xxx\MedWld4.ske",100,on);	//Tossing something in left hand over shoulder frame #20:
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		//nomove(true);
		connections(MedicWorking);
}

action(WorkerWeldingOnBench)
{
		file("pc\actors\worker\xxx\sweld7.ske",30,on);
		file("pc\actors\worker\xxx\sweld1.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		gravity(off);
		collision(off);
		shadow(off);
		connections(WorkerWeldingOnBench);
}

action(WorkerWeldingKneel)
{
		file("pc\actors\Worker\xxx\WrkKnWI.ske",90,on);
		file("pc\actors\Worker\xxx\WrkKnWI2.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		shadow(off);
		connections(WorkerWeldingKneel,CopIdle);
}


action(WorkerKneelCrush)
{
		file("pc\actors\Worker\xxx\WrkKnWD.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		nomove(true);
		gravity(off);
		collision(off);
		shadow(off);
}

action(ScientistPressButtons)
{
		file("pc\actors\scientst\xxx\sci_idl4.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		connections(ScientistPressButtons,CopIdle);
}

action(ScientistCrush)
{
		file("pc\actors\Scientst\xxx\SciCrsh.ske",100,off);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(8);
		connections(ScientistCrushEnd);
}

action(ScientistCrushEnd)
{
		file("pc\actors\Chot\xxx\MCrCower.ske",100,off);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(8);
		intforloop(off);
}

action(WorkerKneelDead)
{
		file("pc\actors\Worker\xxx\WrkKnWH.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		nomove(true);
		collision(off);
		shadow(off);
}

action(WorkerShotOnBench)
{
		file("pc\actors\chot\xxx\swelDed.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		gravity(off);
		collision(off);
		shadow(off);
		connections(WorkerDeadOnBench);
}

action(WorkerDeadOnBench)
{
		file("pc\actors\chot\xxx\swelDedH.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		gravity(off);
		collision(off);
		shadow(off);
}

action(WorkerCowerOnBench)
{
		file("pc\actors\chot\xxx\SwelCowr.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		gravity(off);
		collision(off);
		shadow(off);
		connections(WorkerCowerOnBench);
}


action(WorkerCrushedOnBench)
{
		file("pc\actors\worker\xxx\sweld6.ske",100,off);
		file("pc\actors\worker\xxx\sweld4.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		gravity(off);
		collision(off);
		shadow(off);
		connections(WorkerCrushedOnBench);
}


action(WorkerWelding)
{
		file("pc\actors\worker\xxx\wrkweld.ske",70,on);
		file("pc\actors\worker\xxx\wrkweld2.ske",90,on);
		file("pc\actors\worker\xxx\wrkweldm.ske",100,on);
		trigger(_DIRshoot);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(WorkerWelding,CopIdle);
}







/*
** Cop Action Animations
*/
/* *************   ******************* */

/* *************   Wounded ******************* */

action(CopWoundLight)
{
		file("pc\actors\Chot\xxx\FstWnd1.ske",50,off);
		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
//		file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassCopSkeleton);
//		ActionSubroutine(Sub_ActionDebugBreak);
		break(on);
		collision(on);
		nrintframes(0);
//		nrintframes(4);
		connections(CopSpreadOut,CopStandShoot,CopWoundLight,CopTurnLeft,CopTurnRight,CopIdle);
}

action(CopWoundLightRun)
{
		file("pc\actors\Chot\xxx\FstWnd1.ske",50,off);
		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
//		file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
//		trigger(_alldir);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassCopSkeleton);
		break(on);
		collision(on);
		nrintframes(4);
		connections(CopSpreadOut,CopIdle);
}

action(CopWoundLightNoBreak)	//Identical to the one above except for break
{
		file("pc\actors\Chot\xxx\FstWnd1.ske",50,off);
		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
//		file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
		trigger(_DIRNotEndOfAnim);
//		ActionSubroutine(Sub_ActionDebugBreak);
		AIClass(_AIClassCopSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
		connections(CopSpreadOut,CopStandShoot,CopWoundLightNoBreak,CopTurnLeft,CopTurnRight,CopIdle);
}

action(CopThrownSpin)
{
		file("pc\actors\Chot\xxx\thrnspin.ske",100,off);
		trigger(_allDIR);
		break(off);
		collision(on);
		ActionSubRoutine(Sub_SetThrown);
		nrintframes(4);
		connections(CopThrownSpin);
}


SubRoutine(Sub_AlertAll)
{
		if(VAICon!=0 && VAIState!=_AIstateAttack && VAIState!=_AIstateHide && VAIState!=_AIstateGuard)
		{
			if(VActorFlag==_AFLAGattached)//for 2-man animation, changes guy who punches him in the face into an enemy
			{
				call(AIcheckattachactionorigin);
				call(AIchangefriendtoenemy);
			}

			call(AIalert,Sub_AISetAttack);
			CallSub(Sub_AISetAttack);
		}
}

SubRoutine(Sub_SetAttackerToEnemyAndHandleThrown)
{
		if(VActorFlag==_AFLAGattached && VAICon!=0)
		{
			callsub(Sub_AlertAll);
		}

		if(VAIclass!=_AIclassbeast)					//should maybe be ==0 ?
		{
			callsub(Sub_SetThrown);
		}
}


SubRoutine(Sub_ChangeMeToEnemy)
{
		if(VAICon==0)
		{
			call(AIchangemetoenemy);
		}
}

SubRoutine(Sub_AlertAllAfterCough)
{
		if(VAIState!=_AIstateAttack && VAIState!=_AIstateHide && VAIState!=_AIstateGuard)
		{
			if(VFrame==90)
			{
				call(AIsetlockedonactortotarget);
				call(AIchangetargettoenemy);
				CallSub(Sub_AlertAll);
				sample(SFXCoughReact,-1);
			}
		}
}

SubRoutine(Sub_RemoveGun)
{
		if(vframe==19)
		{
			if(VAICon!=0)
			{
				sample(SFXKickedReact,-1);
			}
			else
			{
				sample(SFXShotReact,-1);
			}

			//if(AIAbility&=_AIAPickUpWeapon)
			//{
				call(CheckAttached,_CADropWeaponAndShells);
			//}
			state(_or,StateThrown);
		}
		CallSub(Sub_AlertAll);
}

SubRoutine(Sub_RemoveGunPunch)
{
		if(vframe==19)
		{
			sample(SFXManPunch,-1);
		}
}

action(CopThrownBack)
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,on);	//Backwards hold frame
		trigger(_alldir);
		AIClass(_AIClassCopSkeleton);
		break(on);
		collision(on);
		nrintframes(4);

		//ActionSubRoutine(Sub_SetThrown);
		ActionSubRoutine(Sub_SetAttackerToEnemyAndHandleThrown);

		connections(CopThrownBackLand,CopThrownBack);
}

action(CopThrownBackLand)
{
		file("pc\actors\Chot\xxx\ThBklndP.ske",100,off,100,-1,_DIRnotai|_DIRalive);	//Possessed shorter landing. and alive
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);	//Backwards, land on back
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(CopGetUpFromBackRollBack,CopGetUpFromBackKipForward,CopGetUpFromBack,CopThrownBackLand);
}


action(CopThrownForward)
{
		file("pc\actors\Chot\xxx\ThfwHld1.ske",100,on);	//Forward hold frame
		trigger(_alldir);
		AIClass(_AIClassCopSkeleton);
		break(on);
		collision(on);
		nrintframes(4);

		ActionSubRoutine(Sub_SetThrown);

		connections(CopThrownForwardLand,CopThrownForward);
}

action(CopThrownForwardFromKick)
{
		file("pc\actors\Chot\xxx\ThfwHld1.ske",100,on);	//Forward hold frame
		trigger(_alldir);
		//AIClass(_AIClassCopSkeleton);
		AIClass(_AIClassAllButAngel);
		break(on);
		collision(on);
		nrintframes(4);

		ActionSubRoutine(Sub_SetAttackerToEnemyAndHandleThrown);

		connections(GENThrownForward);
		//connections(CopThrownForwardLand,CopThrownForward);
}

action(CopThrownForwardLand)
{
		file("pc\actors\Chot\xxx\ThFwLnd.ske",100,off);		//forward, land face down, and get up (gabe)
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(CopGetUpFromFrontForwardKip,CopGetUpFromFrontFaceDown,CopThrownForwardLand);
}

action(CopThrownRight)
{
		file("pc\actors\Chot\xxx\ThrnHldR.ske",100,on);	//Right Hold frame #1
		trigger(_alldir);
		AIClass(_AIClassCopSkeleton);
		break(on);
		ActionSubroutine(Sub_SetThrown);
		collision(on);
		nrintframes(4);
		connections(CopThrownRightLand,CopThrownRight);
}

action(CopThrownRightLand)
{
		file("pc\actors\Chot\xxx\ThrnRLnd.ske",100,off);	//Right land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(8);
		connections(CopGetUpFromRightFaceDownForwardKip,CopGetUpFromRightFaceDownPossessed,CopGetUpFromRightFaceDown,CopThrownRightLand);
}

action(CopThrownLeft)
{
		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		trigger(_alldir);
		AIClass(_AIClassCopSkeleton);
		break(on);
		ActionSubroutine(Sub_SetThrown);
		collision(on);
		nrintframes(4);
		connections(CopThrownLeftLand,CopThrownLeft);
}

action(CopThrownLeftLand)
{
		file("pc\actors\Chot\xxx\ThrnLLnd.ske",100,off);	//Left land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(8);
		connections(CopGetUpFromLeftFaceDownForwardKip,CopGetUpFromLeftFaceDownPossessed,CopGetUpFromLeftFaceDown,CopThrownLeftLand);
}

action(CopGetUpFromBack)
{
		file("pc\actors\chot\xxx\MSpinKip.ske",5,off,100,-1,_DIRnotai,Sub_GetUpClearThrown64); //Male stand from back, possessed. Kip up.
		file("pc\actors\chot\xxx\MRolUpFP.ske",100,off,100,-1,_DIRnotai,Sub_GetUpClearThrown38); //Male stand from back, possessed. Kip up.
		file("pc\actors\chot\xxx\mstndfbk.ske",100,off,110,-1,-1,Sub_GetUpClearThrown84);
		trigger(_DIRalive);
		AIClass(_AIClassCopSkeleton);
		break(off);
		collision(on);
		nrintframes(8);
		connections(GENIdle);
}

action(CopGetUpFromBackRollBack)
{
		file("pc\actors\chot\xxx\MSRlBkBp.ske",100,off,100,-1,-1,Sub_GetUpClearThrown36); //Male stand from back, possessed. Kip up.
		trigger(_DIRalive|_DIRbackward|_DIRnotai);
		AIClass(_AIClassCopSkeleton);
		break(off);
		collision(on);
		nrintframes(8);
		connections(GENIdle);
}

action(CopGetUpFromBackKipForward)
{
		file("pc\actors\chot\xxx\MStndFBP.ske",100,off,100,-1,-1,Sub_GetUpClearThrown36); //Male stand from back, possessed. Kip up.
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		AIClass(_AIClassCopSkeleton);
		break(off);
		collision(on);
		nrintframes(8);
		connections(GENIdle);
}


action(CopGetUpFromFrontFaceDown)
{
		file("pc\actors\chot\xxx\MstandF2.ske",100,off,80,-1,_DIRnotai,Sub_GetUpClearThrown24); //Male stand from front, possessed. faster.
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(4);
		connections(GENIdle);
}

action(CopGetUpFromFrontForwardKip)
{
		file("pc\actors\chot\xxx\MCw2StFw.ske",100,off,155,-1,-1,Sub_GetUpClearThrown55);
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		break(off);
		collision(on);
		nrintframes(18);
		connections(GENIdle);
}


action(CopGetUpFromBackFaceDown)
{
		file("pc\actors\chot\xxx\MstandF2.ske",100,off,80,-1,_DIRnotai,Sub_GetUpClearThrown24); //Male stand from front, possessed. faster.
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(180);
		break(off);
		collision(on);
		nrintframes(4);
		connections(GENIdle);
}

action(CopGetUpFromRightFaceDown)
{
		file("pc\actors\Chot\xxx\ThrnRStn.ske",100,off,110,-1,-1,Sub_GetUpClearThrown38);
		trigger(_DIRalive);
		//rotate(90);
		break(off);
		collision(on);
		nrintframes(4);
		connections(GENIdle);
}

action(CopGetUpFromRightFaceDownPossessed)
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

action(CopGetUpFromLeftFaceDownPossessed)
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

action(CopGetUpFromRightFaceDownForwardKip)
{
		file("pc\actors\chot\xxx\MCw2StFw.ske",100,off,155,-1,-1,Sub_GetUpClearThrown55);
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		break(off);
		collision(on);
		rotate(90);
		//nrintframes(18);
		connections(GENIdle);
}

action(CopGetUpFromLeftFaceDownForwardKip)
{
		file("pc\actors\chot\xxx\MCw2StFw.ske",100,off,155,-1,-1,Sub_GetUpClearThrown55);
		trigger(_DIRalive|_DIRforward|_DIRnotai);
		break(off);
		collision(on);
		rotate(-90);
		//nrintframes(18);
		connections(GENIdle);
}


action(CopGetUpFromLeftFaceDown)
{
		file("pc\actors\Chot\xxx\ThrnLStS.ske",100,off,200,-1,_DIRnotai,Sub_GetUpClearThrown68);
 		file("pc\actors\Chot\xxx\ThrnLStS.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
 		trigger(_DIRalive);
		//rotate(-90);
		break(off);
		collision(on);
		nrintframes(4);
		connections(GENIdle);
}

/*
THROWN, bounce back anims (not put in yet)
backwards, bounce off wall hold last frame:	Chot\xxx\ThBkHtWA.ske
Land on face after bounce off wall:			Chot\xxx\ThBkHtWB.ske
forward, hit walls bounce to back:			Chot\xxx\ThFwHtWl.ske
Right hit wall land on back:				Chot\xxx\ThrnRHWl.ske
Left hit wall land on back:					Chot\xxx\ThrnLHWl.ske
*/





action(CopOpenDoorCombat)
{
		file("pc\actors\Chot\xxx\MWrOpnDr.ske",100,off);		//opening door in combat mode
		trigger(_DIRhavegun|_DIRcombatmode);
		break(on);
		connections(CopSpreadOut);
}


action(CopElectricShock0)
{
		file("pc\actors\Chot\xxx\aelectLP.ske",100,off,130);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true)
		connections(GenElectricShock1);
		collision(on);
		gravity(off);
}

action(CopElectricShock1)
{
		file("pc\actors\Chot\xxx\aelectHL.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true)
		connections(GenElectricShock1);
		collision(on);
		gravity(off);
}

action(CopIdleCombatGun)
{
		file("pc\actors\chot\xxx\MWryId1P.ske",100,on,100,_AIclassRiotCop);
		file("pc\actors\chot\xxx\MWryId2P.ske",10,on,100,_AIclassHipGun);
		file("pc\actors\chot\xxx\MWryId1P.ske",100,on,100,_AIclassHipGun);

		file("pc\actors\Chot\xxx\MWryIdl2.ske",10,on);	//Look left and right
		file("pc\actors\Chot\xxx\MWryIdl1.ske",100,on);	//Heavy Breathing
		trigger(_noDIR|_DIRcombatmode|_DIRhavegun);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(false)
		connections(CopSpreadOutGun,CopStandShoot,CopTurnLeftCombat,CopTurnRightCombat,CopIdle);
}

action(CopIdleCombatNoGun)
{
		file("pc\actors\Chot\xxx\Chidl1Cm.ske",100,on,100,_AIclasschot);	//Chot Combat Idle
		//file("pc\actors\Chot\xxx\MBxIdle.ske",100,on);	//boxing idle
		file("pc\actors\CopRiot\xxx\RCmIdl1.ske",100,on);	//Riot Cop Idle
		//file("pc\actors\Chot\xxx\MBxcrapi.ske",100,on);	//boxing for cop no gun
		trigger(_noDIR|_DIRcombatmode);
		break(on);
		nrintframes(8);
		intforloop(off);
		nomove(false)
		connections(CopSpreadOutGun,ChotShoulderThrow,RiotArmSlamBob,RiotArmSlamF,CopKickingBobF,CopKickingBobB,CopStripGunBob,CopStripGun,CopBoxing,CopChokeWorker,CopChoking,CopKickingB,CopKickingF,CopKicking,CopTurnLeftCombat,CopTurnRightCombat,CopIdle);

}

action(CopIdleGun)
{
		file("pc\actors\Dwellr1\xxx\DwMidl1.ske",3,on,100,_AIclassdweller);		//Breathing
		file("pc\actors\Dwellr1\xxx\DwMidl2.ske",25,on,100,_AIclassdweller);		//Looking left and right
		file("pc\actors\Dwellr1\xxx\DwMidl4.ske",30,on,100,_AIclassdweller);		//Throwing signs
		file("pc\actors\Dwellr1\xxx\DwMidl3.ske",100,on,100,_AIclassdweller);		//Shifting weight one foot to the next

		file("pc\actors\Chot\xxx\ChIdle1.ske",75,on,100,_AIclasschot);	//Breathing heavy:
		file("pc\actors\Chot\xxx\ChIdle2.ske",80,on,100,_AIclasschot);	//Looking intently forward right:
		file("pc\actors\Chot\xxx\ChIdle3.ske",95,on,100,_AIclasschot);	//Looking around paranoid. As if he just heard something:
		file("pc\actors\Chot\xxx\ChIdle4.ske",100,on,100,_AIclasschot,-1,Sub_RandomCopScratchesCrotch);	//Scratching armpit:
	
//		file("pc\actors\Chot\xxx\Mneidl2p.xxx",1,on);	//ass scratch
//		file("pc\actors\Chot\xxx\Mneidl3p.xxx",2,on);	//crotch scratch
//		file("pc\actors\Chot\xxx\Mneidl1p.xxx",65,on);	//look around
//		file("pc\actors\Chot\xxx\Mneidl5p.ske",100,on);	//Stand still

	file("pc\actors\scientst\xxx\sci_wipe.ske",10,on,160,_AIclassscientist);	//wipe brow
	file("pc\actors\Chot\xxx\Mneidl5p.ske",67,on,100,_AIclassscientist);	//Heavy breathing
	file("pc\actors\Chot\xxx\Mneidl2p.ske",68,on,100,_AIclassscientist,-1,Sub_RandomCopScratchesCrotch);	//Scratch ass
	file("pc\actors\Chot\xxx\Mneidl1g.ske",100,on,100,_AIclassscientist,-1,Sub_SFXCop_BackgroundChatter);	//Look left and right


	file("pc\actors\Chot\xxx\Mneidl5p.ske",63,on);	//Heavy breathing
	file("pc\actors\Chot\xxx\Mneidl2p.ske",64,on,100,-1,-1,Sub_RandomCopScratchesCrotch);	//Scratch ass
	file("pc\actors\Chot\xxx\Mneidl3p.ske",65,on,100,-1,-1,Sub_RandomCopScratchesCrotch);	//scratch crotch
	file("pc\actors\Chot\xxx\Mneidl1g.ske",100,on,100,-1,-1,Sub_SFXCop_BackgroundChatter);	//Look left and right

		trigger(_noDIR|_DIRhavegun);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(false)
		connections(CopSpreadOutGun,CopStandShoot,CopTurnLeft,CopTurnRight,CopIdle);
}

action(CopIdleNoGun)
{

		file("pc\actors\Dwellr1\xxx\DwMidl1.ske",3,on,100,_AIclassdweller);		//Breathing
		file("pc\actors\Dwellr1\xxx\DwMidl2.ske",25,on,100,_AIclassdweller);		//Looking left and right
		file("pc\actors\Dwellr1\xxx\DwMidl4.ske",30,on,100,_AIclassdweller);		//Throwing signs
		file("pc\actors\Dwellr1\xxx\DwMidl3.ske",100,on,100,_AIclassdweller);		//Shifting weight one foot to the next
		
		file("pc\actors\Pimp\xxx\Pidle.ske",20,on,100,_AIclasspimp);		//throwing signs w left arm
		file("pc\actors\Pimp\xxx\Pidle1.ske",70,on,100,_AIclasspimp);		//look left and right
		file("pc\actors\Pimp\xxx\Pidle2.ske",80,on,100,_AIclasspimp);	//grabbing crotch
		file("pc\actors\Pimp\xxx\Pspot1.ske",100,on,100,_AIclasspimp);		//Spotting bob the the first time
//		file("pc\actors\Pimp\xxx\Phit.ske",44,on,100,_AIclasspimp);		//backhand slap
//		file("pc\actors\Pimp\xxx\Pspot.ske",55,on,100,_AIclasspimp);   //Throwing signs 2. throw then wave
//		file("pc\actors\Pimp\xxx\Psurvey.ske",88,on,100,_AIclasspimp);		//Angrily survey console
//		file("pc\actors\Pimp\xxx\Psurvey2.ske",100,on,100,_AIclasspimp);	//Survey console
//		file("pc\actors\Pimp\xxx\Ppunch.ske",66,on,100,_AIclasspimp);		//Punching buttons on console

		file("pc\actors\Chot\xxx\ChIdle1.ske",75,on,100,_AIclasschot);	//Breathing heavy:
		file("pc\actors\Chot\xxx\ChIdle2.ske",80,on,100,_AIclasschot);	//Looking intently forward right:
		file("pc\actors\Chot\xxx\ChIdle3.ske",95,on,100,_AIclasschot);	//Looking around paranoid. As if he just heard something:
		file("pc\actors\Chot\xxx\ChIdle4.ske",100,on,100,_AIclasschot,-1,Sub_RandomCopScratchesCrotch);	//Scratching armpit:


		file("pc\actors\Scientst\xxx\sci_idl6.ske",56,on,100,_AIclassscientist);	//breathing
		file("pc\actors\Scientst\xxx\sci_idl2.ske",60,on,100,_AIclassscientist);	//cross arms
		file("pc\actors\Scientst\xxx\sci_idl1.ske",61,on,100,_AIclassscientist);	//use keypad
		file("pc\actors\Scientst\xxx\sci_idl3.ske",80,on,100,_AIclassscientist);	//looking
		file("pc\actors\Scientst\xxx\sci_idl5.ske",100,on,100,_AIclassscientist);	//looks over shoulder
	
//		file("pc\actors\Chot\xxx\Mnidl2NG.ske",1,on);	//Scratch ass
//		file("pc\actors\Chot\xxx\Mnidl3NG.ske",2,on);	//scratch crotch
//		file("pc\actors\Chot\xxx\Mnidl1NG.ske",65,on);	//Look left and right
//		file("pc\actors\Chot\xxx\Mnidl4NG.ske",100,on);	//Heavy breathing
		file("pc\actors\Chot\xxx\Mnidl4NG.ske",63,on);	//Heavy breathing
		file("pc\actors\Chot\xxx\Mnidl2NG.ske",64,on,100,-1,-1,Sub_RandomCopScratchesCrotch);	//Scratch ass
		file("pc\actors\Chot\xxx\Mnidl3NG.ske",65,on,100,-1,-1,Sub_RandomCopScratchesCrotch);	//scratch crotch
		file("pc\actors\Chot\xxx\Mnidl1NG.ske",100,on,100,-1,-1,Sub_SFXCop_BackgroundChatter);	//Look left and right

		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(false)
		connections(CopSpreadOut,CopStandShoot,CopTurnLeft,CopTurnRight,CopIdle);
}

Action(CopIdle)
{
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(-1);
		connections(CopIdleCombatGun,CopIdleCombatNoGun,CopIdleGun,CopIdleNoGun);
}

Action(CopAttentionIdle)
{
		file("pc\actors\Chot\xxx\Matnidlg.ske",100,on);
		break(on);
		connections(CopSpreadOut,CopStandShoot,CopTurnLeft,CopTurnRight,CopAttentionIdle);
}

Action(CopAttention)
{
		file("pc\actors\Chot\xxx\matnshng.ske",100,on);	//respond to attention command
		break(off);
		nrintframes(8);
		connections(CopAttentionIdle);
}

Action(CopWalkie)
{
		file("pc\actors\Chot\xxx\MWlkieC.ske",100,on);	//respond to attention command
		break(off);
		nrintframes(8);
		connections(CopSpreadOut);
}

action(SmokeBong)
{
		file("pc\actors\chot\xxx\smokshit.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		connections(CopIdle);
}

action(CopBongSmoke)
{
		file("pc\actors\Chot\xxx\smokshit.ske",100,on);		//
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		connections(CopIdle);
}


action(CopWatchTVActive)
{
		file("pc\actors\chot\xxx\MBrIdle3.ske",30,on); // point towards the TV (look to his right)
		file("pc\actors\chot\xxx\MBrIdle2.ske",100,on);	// watch TV, shift balance.
		trigger(_noDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(CopWatchTVActive,CopIdle);
}

action(CopWatchTVIdle)
{
		file("pc\actors\chot\xxx\MBrIdle1.ske",100,on);	// cross arms and watch tv
		trigger(_noDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(CopWatchTVIdle,CopIdle);
}

Subroutine(Sub_PushUpGrunt)
{
	if(vframe==95 && VActionIndex==0)
	{
		sample(SFXManFallToGround,-1);
	}
	elseif(vframe==25 && VActionIndex==1)
	{
		sample(SFXGrunt,-1);
	}
}

action(CopPushUpsLoop)
{
		file("pc\actors\chot\xxx\MBrIdle5.ske",10,on);	//collapse to the ground
		file("pc\actors\chot\xxx\MBrIdle4.ske",100,on);	
		trigger(_allDIR);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		ActionSubRoutine(Sub_PushUpGrunt);
		connections(CopPushUpsLoop);
}

action(CopShadowBoxingIdle)
{
		file("pc\actors\Chot\xxx\MBxIdle.ske",100,on);  //Bosing idle
		trigger(_allDIR);
		nrintframes(8);
		intforloop(on);
		nomove(true);
		connections(CopShadowBoxingIdle);
}

action(CopShadowBoxingPunch)
{
		file("pc\actors\Chot\xxx\MBxLjab.ske",45,on);	//Left Jab
		file("pc\actors\Chot\xxx\MBxRjab.ske",90,on);	//Right Jab
		file("pc\actors\Chot\xxx\MBxRUcut.ske",100,on);	//Uppercut
		trigger(_allDIR);
		nrintframes(8);
		intforloop(on);
		nomove(true);

		ActionSubRoutine(Sub_RandomPunchedSFX);

		connections(CopShadowBoxingIdle);
}

action(ChotPunchingBagIdle)
{
		file("pc\actors\Chot\xxx\ChBagHng.ske",100,on);	
		trigger(_allDIR);
		gravity(off);
		nrintframes(0);
		intforloop(off);
//		nomove(true);
		connections(ChotPunchingBagIdle);
}

action(ChotPunchingBagPunched)
{
		file("pc\actors\Chot\xxx\ChBagHit.ske",100,on);	
		trigger(_allDIR);
		gravity(off);
		nrintframes(0);
//		intforloop(on);
//		nomove(true);
		connections(ChotPunchingBagIdle);
}

action(ChotPunchingBagShot)
{
		file("pc\actors\Chot\xxx\ChBagDth.ske",100,on);	
		trigger(_allDIR);
		gravity(off);
		nrintframes(0);
//		intforloop(on);
//		nomove(true);
		connections(ChotPunchingBagIdle);
}



action(CopLightSmoke)
{
		file("pc\actors\Chot\xxx\MSmkIdl6.ske",100,off);
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(CopSpreadOut,CopSmoke);
}

action(CopSmoke)
{
		//file("pc\actors\Chot\xxx\MSmkIdl5.ske",50,on);		//stand
		file("pc\actors\Chot\xxx\MSmkIdl2.ske",80,on);		//drag
		//file("pc\actors\Chot\xxx\MSmkIdl3.ske",90,on);		//flick
		file("pc\actors\Chot\xxx\MSmkIdl1.ske",100,on);		//look
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(CopSpreadOut,CopSmoke);
}

action(CopStopSmoke)
{
		file("pc\actors\Chot\xxx\MSmkIdl4.ske",100,off);		//
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(CopSpreadOut,CopStandShoot,CopIdle);
}

action(CopSpreadOut)	//Lead directly to next animation
{
		trigger(_DIRMove);
		AIClass(_AIClassCopSkeleton);
		nrintframes(-1);
		//connections(CopSpreadOutGun,CopRunDiagFL,CopRunDiagFR,CopRunDiagBL,CopRunDiagBR,CopRun,CopRunBack,CopRunL,CopRunR,CopWalkDiagFL,CopWalkDiagFR,CopWalkDiagBL,CopWalkDiagBR,CopWalk,CopWalkBack,CopWalkL,CopWalkR);
		connections(CopSpreadOutGun,CopWalkDiagFL,CopWalkDiagFR,CopWalkDiagBL,CopWalkDiagBR,CopWalk,CopWalkBack,CopWalkL,CopWalkR,CopRunDiagFL,CopRunDiagFR,CopRunDiagBL,CopRunDiagBR,CopRun,CopRunBack,CopRunL,CopRunR);
}
action(CopSpreadOutGun)	//Lead directly to next animation
{
		trigger(_DIRMove|_DIRcombatmode);	// _DIRhavegun taken off so he can walk with his fists raised in combat with no gun
		AIClass(_AIClassCopSkeleton);
		nrintframes(-1);
		//connections(CopRunDiagFLGun,CopRunDiagFRGun,CopRunDiagBLGun,CopRunDiagBRGun,CopRunGun,CopRunBackGun,CopRunLGun,CopRunRGun,CopWalkDiagFLGun,CopWalkDiagFRGun,CopWalkDiagBLGun,CopWalkDiagBRGun,CopWalkGun,CopWalkBackGun,CopWalkLGun,CopWalkRGun);
		connections(CopWalkDiagFLGun,CopWalkDiagFRGun,CopWalkDiagBLGun,CopWalkDiagBRGun,CopWalkGun,CopWalkBackGun,CopWalkLGun,CopWalkRGun,CopRunDiagFLGun,CopRunDiagFRGun,CopRunDiagBLGun,CopRunDiagBRGun,CopRunGun,CopRunBackGun,CopRunLGun,CopRunRGun);
}


action(CopIdleLongTime)//these are really celebrations after killing Bob
{
		//file("pc\actors\Chot\xxx\Macaren2.ske",11,on);	//macarena
		file("pc\actors\Chot\xxx\mspan11p.ske",33,on);//celebration after killing Bob
		file("pc\actors\Chot\xxx\mspan14p.ske",66,on);//celebration 'flip-him-off' after killing Bob
		file("pc\actors\Chot\xxx\mspan12p.ske",100,on);//celebration dance after killing Bob
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(CopSpreadOut,CopStandShoot,CopTurnLeft,CopTurnRight,CopIdleLongTime,CopIdle);
}

action(CopDance)
{
		file("pc\actors\Chot\xxx\ChMnky1.ske",100,on);
//		file("pc\actors\Chot\xxx\Macaren3.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(CopDance,CopIdle);
}

action(CopIdleHitWall)	//used just after you bounce into a wall
{
		file("pc\actors\chot\xxx\MWryId2P.ske",10,on,100,_AIclassHipGun,_DIRcombatmode|_DIRhavegun);
		file("pc\actors\chot\xxx\MWryId1P.ske",100,on,100,_AIclassHipGun,_DIRcombatmode|_DIRhavegun);

		file("pc\actors\Chot\xxx\MWryIdl2.ske",10,on,100,-1,_DIRcombatmode|_DIRhavegun);	//Look left and right
		file("pc\actors\Chot\xxx\MWryIdl1.ske",100,on,100,-1,_DIRcombatmode|_DIRhavegun);	//Heavy Breathing

//		file("pc\actors\Chot\xxx\Mneidl2p.xxx",1,on);	//ass scratch
//		file("pc\actors\Chot\xxx\Mneidl3p.xxx",2,on);	//crotch scratch
//		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around

		file("pc\actors\Chot\xxx\Chidl1Cm.ske",100,on,100,_AIclasschot,_DIRcombatmode);	//Chot Combat Idle
		file("pc\actors\CopRiot\xxx\RCmIdl1.ske",100,on,100,-1,_DIRcombatmode);	//Riot Cop Idle
		
		file("pc\actors\Chot\xxx\Mneidl2p.ske",1,on,100,-1,-1,Sub_RandomCopScratchesCrotch);	//Scratch ass
		file("pc\actors\Chot\xxx\Mneidl3p.ske",2,on,100,-1,-1,Sub_RandomCopScratchesCrotch);	//scratch crotch
		file("pc\actors\Chot\xxx\Mneidl1g.ske",100,on,100,-1,-1,Sub_SFXCop_BackgroundChatter);	//Look left and right

		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(GENHitWallSpreadOut);
}

action(CopHitWallSpreadOut)	//Lead directly to next animation
{
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(-1);
		connections(CopHitWallStandShoot,CopHitWallTurnLeft,CopHitWallTurnRight,GENIdleHitWall);
}

action(CopIdleHitWallSpread)	//Lead directly to next animation
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(CopIdleHitWall,GENIdleHitWallFront);
}

action(CopIdleHitWallFront)	//used just after you bounce into a wall, face first
{
		file("pc\actors\chot\xxx\MWryId1P.ske",100,on,100,_AIclassHipGun,_DIRcombatmode|_DIRhavegun);
		file("pc\actors\Chot\xxx\MWryIdl1.ske",100,on,100,-1,_DIRcombatmode|_DIRhavegun);
		file("pc\actors\Chot\xxx\Mneidl1g.ske",100,on);	//look around
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(GENIdleHitWallFront);
		//connections(CopHitWallStandShoot,CopHitWallTurnLeft,CopHitWallTurnRight,CopIdleHitWallFront);
}

action(CopTurnLeft)
{
	//	file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
	
		file("pc\actors\Pimp\xxx\PmTrLSt.ske",100,off,100,_AIClassPimp);//pimp
		file("pc\actors\Pimp\xxx\PmTrLLp.ske",100,on,100,_AIClassPimp);//pimp

		file("pc\actors\Chot\xxx\CTrLStNc.ske",100,off,100,_AIclasschot);
		file("pc\actors\Chot\xxx\CTrLLpNc.ske",100,on,100,_AIclasschot);

		file("pc\actors\Chot\xxx\MTrLStNc.ske",100,off,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MTrLLpNc.ske",100,on,100,-1,_DIRhavegun);

		file("pc\actors\Dwellr1\xxx\DwTrLSt.ske",100,off,100); //,_AIclassdweller);//Dweller turns work for cop no gun
		file("pc\actors\Dwellr1\xxx\DwTrLLp.ske",100,on,100); //,_AIclassdweller);//Dweller turns  work for cop no gun

		//file("pc\actors\Chot\xxx\MTrLStNc.ske",100,off,100);
		//file("pc\actors\Chot\xxx\MTrLLpNc.ske",100,on,100);

		

		trigger(_DIRleft);
		break(on);
		nrintframes(2);
		intforloop(on);
		connections(CopSpreadOut,CopStandShoot,CopTurnLeft,CopTurnRight,CopIdle);
}

action(CopTurnLeftCombat)
{
	//	file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		file("pc\actors\Chot\xxx\MTrLStC.ske",100,off,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MTrLLpC.ske",100,on,100,-1,_DIRhavegun);

		file("pc\actors\CopRiot\xxx\RTrLStC.ske",100,off,100);
		file("pc\actors\CopRiot\xxx\RTrLLpC.ske",100,on,100);

		
		trigger(_DIRleft);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(CopSpreadOut,CopStandShoot,CopTurnLeftCombat,CopTurnRightCombat,CopTurnLeftRightCombatEnd);
}

action(CopTurnLeftRightCombatEnd)
{
	//	file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		file("pc\actors\Chot\xxx\MTrnStpC.ske",100,off,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\Chidl1Cm.ske",100,on,100,_AIclasschot);	//Chot Combat Idle no gun

		file("pc\actors\CopRiot\xxx\RCmIdl1.ske",100,on);	//Riot Cop Idle
	//	file("pc\actors\Chot\xxx\MTrnStpC.ske",100,off,100);
		trigger(_DIRnotendofanim|_noDIR);
		break(on);
		nrintframes(6);
		intforloop(off);
		connections(CopSpreadOut,CopStandShoot,CopTurnLeftCombat,CopTurnRightCombat,CopTurnLeftRightCombatEnd,CopIdle);
}

action(CopTurnRight)
{
		file("pc\actors\Pimp\xxx\PmTrRSt.ske",100,off,100,_AIClassPimp);//pimp
		file("pc\actors\Pimp\xxx\PmTrRLp.ske",100,on,100,_AIClassPimp);//pimp

		file("pc\actors\Chot\xxx\CTrRStNc.ske",100,off,100,_AIclasschot);
		file("pc\actors\Chot\xxx\CTrRLpNc.ske",100,on,100,_AIclasschot);

		file("pc\actors\Chot\xxx\MTrRStNc.ske",100,off,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MTrRLpNc.ske",100,on,100,-1,_DIRhavegun);


		file("pc\actors\Dwellr1\xxx\DwTrRSt.ske",100,off,100); //,_AIclassdweller);//Dweller turns work for cop no gun
		file("pc\actors\Dwellr1\xxx\DwTrRLp.ske",100,on,100); //,_AIclassdweller);//Dweller turns work for cop no gun


		
		trigger(_DIRright);
		break(on);
		nrintframes(2);
		intforloop(on);
		connections(CopSpreadOut,CopStandShoot,CopTurnLeft,CopTurnRight,CopIdle);
}

action(CopTurnRightCombat)
{
		//file("pc\actors\Chot\xxx\mtrnrt2.ske",100,on);
		file("pc\actors\Chot\xxx\MTrRStC.ske",100,off,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MTrRLpC.ske",100,on,100,-1,_DIRhavegun);

		file("pc\actors\CopRiot\xxx\RTrRStC.ske",100,off,100);
		file("pc\actors\CopRiot\xxx\RTrRLpC.ske",100,on,100);
		trigger(_DIRright);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(CopSpreadOut,CopStandShoot,CopTurnLeftCombat,CopTurnRightCombat,CopTurnLeftRightCombatEnd,CopIdle);
}

action(CopCrouchTurnLeftRightEnd)
{
		file("pc\actors\Chot\xxx\MCrTrStp.ske",100,off,100);
		trigger(_DIRnotendofanim|_noDIR);
		break(on);
		nrintframes(4);
		intforloop(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchIdle);
}

action(CopCrouchTurnRight)
{
		file("pc\actors\Chot\xxx\MCrTrRSt.ske",100,off,100);//crouch start turn right
		file("pc\actors\Chot\xxx\MCrTrRLp.ske",100,on,100);//crouch turn right loop
		trigger(_DIRRight);
		break(on);
		nrintframes(2);
		intforloop(on);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchTurnLeftRightEnd);
}

action(CopCrouchTurnLeft)
{
		file("pc\actors\Chot\xxx\MCrTrLSt.ske",100,off,100);//crouch start turn left
		file("pc\actors\Chot\xxx\MCrTrLLp.ske",100,on,100);//crouch turn left loop
		trigger(_DIRleft);
		break(on);
		nrintframes(2);
		intforloop(on);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchTurnLeft,CopCrouchTurnRight,CopCrouchTurnLeftRightEnd);
}

action(CopHitWallTurnLeft)
{


		file("pc\actors\Chot\xxx\MTrLStC.ske",100,off,100,-1,_DIRhavegun|_DIRcombatmode);
		file("pc\actors\Chot\xxx\MTrLLpC.ske",100,on,100,-1,_DIRhavegun|_DIRcombatmode);

		file("pc\actors\CopRiot\xxx\RTrLStC.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\CopRiot\xxx\RTrLLpC.ske",100,on,100,-1,_DIRcombatmode);

		file("pc\actors\Pimp\xxx\PmTrLSt.ske",100,off,100,_AIClassPimp);//pimp
		file("pc\actors\Pimp\xxx\PmTrLLp.ske",100,on,100,_AIClassPimp);//pimp

		file("pc\actors\Chot\xxx\CTrLStNc.ske",100,off,100,_AIclasschot);
		file("pc\actors\Chot\xxx\CTrLLpNc.ske",100,on,100,_AIclasschot);

		file("pc\actors\Chot\xxx\MTrLStNc.ske",100,off,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MTrLLpNc.ske",100,on,100,-1,_DIRhavegun);

		file("pc\actors\Dwellr1\xxx\DwTrLSt.ske",100,off,100); //,_AIclassdweller);//Dweller turns work for cop no gun
		file("pc\actors\Dwellr1\xxx\DwTrLLp.ske",100,on,100); //,_AIclassdweller);//Dweller turns  work for cop no gun

//		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
//		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(CopHitWallSpreadOut);
}

action(CopHitWallTurnRight)
{
		file("pc\actors\Chot\xxx\MTrRStC.ske",100,off,100,-1,_DIRhavegun|_DIRcombatmode);
		file("pc\actors\Chot\xxx\MTrRLpC.ske",100,on,100,-1,_DIRhavegun|_DIRcombatmode);

		file("pc\actors\CopRiot\xxx\RTrRStC.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\CopRiot\xxx\RTrRLpC.ske",100,on,100,-1,_DIRcombatmode);

		file("pc\actors\Pimp\xxx\PmTrRSt.ske",100,off,100,_AIClassPimp);//pimp
		file("pc\actors\Pimp\xxx\PmTrRLp.ske",100,on,100,_AIClassPimp);//pimp

		file("pc\actors\Chot\xxx\CTrRStNc.ske",100,off,100,_AIclasschot);
		file("pc\actors\Chot\xxx\CTrRLpNc.ske",100,on,100,_AIclasschot);

		file("pc\actors\Chot\xxx\MTrRStNc.ske",100,off,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MTrRLpNc.ske",100,on,100,-1,_DIRhavegun);


		file("pc\actors\Dwellr1\xxx\DwTrRSt.ske",100,off,100); //,_AIclassdweller);//Dweller turns work for cop no gun
		file("pc\actors\Dwellr1\xxx\DwTrRLp.ske",100,on,100); //,_AIclassdweller);//Dweller turns work for cop no gun

//		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
//		move(-2,0,0)
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(CopHitWallSpreadOut);
}

action(CopRunUpStairs)
{
		file("pc\actors\Chot\xxx\runstar7.ske",100,on,140);
		trigger(_DIRforward);
		AIClass(_AIClassCopSkeleton);
		break(off);
//		offset(4);
		nrintframes(8);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopRunUpStairs);
}


/*						//not used
Action(CopClimbHang)
{
//		file("pc\actors\chot\xxx\MClmbWlF.ske",100,off,100);
		nrintframes(4);
		trigger(_allDIR);
		gravity(off);
		ydeltafromzeroframe(off);	//Default=on
		connections(CopClimbHang);
}
*/


/* *************   Standard combat moves without gun ******************* */

SubRoutine(Sub_EatenSlowCode)
{
		State(_or,StateDead);
		Direction(_clr,_DIRalive);

		if(VFrame==1)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==252)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==262)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==272)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==329)
		{
			Sample(SFXManFallToGround,-1);
		}

		if(VFrame>=265 && VFrame<=310 && VRnd<50)
		{
			call(SetParticleSetID);
			spawnparticle(fx_bloodspurt,1,emptyvector,emptyvector,-1);		//1 is lower torso
			spawnparticle(fx_bloodspray,1,emptyvector,emptyvector,-1);
			spawnparticle(fx_blood,1,emptyvector,emptyvector,fx_darkbloood);
			spawnparticle(fx_blood,1,emptyvector,emptyvector,fx_darkbloood);
			spawnparticle(fx_bloodlesser,1,emptyvector,emptyvector,fx_darkbloood);
			spawnparticle(fx_bloodlesser,1,emptyvector,emptyvector,fx_darkbloood);
		}

		if(vframe==339)
		{
			sample(SFXManFallToGround,-1);
		}
}

SubRoutine(Sub_EatenCode)
{
		State(_or,StateDead);
		Direction(_clr,_DIRalive);

		if(VFrame>=130 && VFrame<=175 && VRnd<50)
		{
			call(SetParticleSetID);
			spawnparticle(fx_bloodspurt,1,emptyvector,emptyvector,-1);		//1 is lower torso
			spawnparticle(fx_bloodspray,1,emptyvector,emptyvector,-1);
			spawnparticle(fx_blood,1,emptyvector,emptyvector,fx_darkbloood);
			spawnparticle(fx_blood,1,emptyvector,emptyvector,fx_darkbloood);
			spawnparticle(fx_bloodlesser,1,emptyvector,emptyvector,fx_darkbloood);
			spawnparticle(fx_bloodlesser,1,emptyvector,emptyvector,fx_darkbloood);
		}

		if(vframe==194)
		{
			sample(SFXManFallToGround,-1);
		}
}


action(CopEatenSlowLink)
{
		file("pc\actors\MultiAnm\xxx\2EatCpSC.ske",100,off);
		break(off);
		trigger(_DIRNotEndOfAnim);
		ActionSubRoutine(Sub_EatenSlowCode);
}

action(CopEatenLink)
{
		file("pc\actors\MultiAnm\xxx\2EatCpFC.ske",100,off);
		break(off);
		trigger(_DIRNotEndOfAnim);

		ActionSubRoutine(Sub_EatenCode);
}


action(CopThrownSpinLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\thrnspin.ske",100,off);
		break(off);
		ActionSubRoutine(Sub_SetThrown);
		trigger(_DIRalive);
		connections(BeastIdle,CopThrownSpinLink);
}

action(BouncerThrowCopLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Bouncer\xxx\Man_thro.ske",100,off);
		break(off);
		connections(BeastIdle,CopThrownBack);
}

action(CopBoxingLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\MCpHitRt.ske",30,on);
		file("pc\actors\Chot\xxx\MCpHitLf.ske",60,on);
		file("pc\actors\Chot\xxx\MCpHitUp.ske",100,on);
		ActionSubRoutine(Sub_RandomPunchedSFX);
		break(off);
		connections(BeastIdle,GenIdle);
}

action(CopBoxing)
{
		file("pc\actors\chot\xxx\MBxLjab.ske",100,on,100);	//Throw left jab
		file("pc\actors\chot\xxx\MBxRjab.ske",60,on,100);	//Throw right jab
		file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,100);	//Throw right uppercut

		flag(_SXAAalignmovingslave|_SXAAStandingOnly);

		AIClass(_AIClassCopSkeleton);

		//AIClass(_AIclassMale|_AIclasscop);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(60);
		AlignDistance(100);
		AlignSlack(70);
		DistanceSlack(50);


		AlignStartFrame(10);
		AlignNrFrames(10);

		AttachActionStartAtFrame(10);
		DamageFrame(15);
		Power(10);
		AttachAction(CopBoxingLink);
		TargetAIClass(_AIClassAllButAngel);


		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopChokingLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\CpChStrS.ske",100,on,100);
		break(off);

		ActionSubRoutine(Sub_RandomStrangledSFX);

		connections(BeastIdle,CopChokingCough,GenIdle);
}
action(CopChokingLoopLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\CpChHl1S.ske",100,on,100);
		break(off);

		ActionSubRoutine(Sub_RandomStrangledSFX);

		connections(BeastIdle,CopChokingCough,GenIdle);
		//connections(CopChokingLoopLink,CopIdle);
}

action(VictimStrangle)
{
		file("pc\actors\Chot\xxx\CpChHl1S.ske",100,on,100);
		trigger(_allDIR);	
		break(off);
		nrintframes(5);
		intforloop(on);
		connections(VictimStrangle);
		//connections(CopChokingLoopLink,CopIdle);
}

SubRoutine(Sub_KillActor)
{
		if(VFrame==10)
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

		if(vframe==57)
		
			sample(SFXManFallToGround,-1);
		}
}

action(CopChokingDeathLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\CpChDedS.ske",100,off,100);
		break(off);

		ActionSubRoutine(Sub_KillActor);

		connections(BeastIdle,CopChokingDeathLink);
		//connections(CopChokingLoopLink,CopIdle);
}



action(CopChokingDeath)
{
		file("pc\actors\Chot\xxx\CpChDedM.ske",100,on,100);

		flag(_SXAAdisablecollision|_SXAAdisablerotation);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(65);
		DistanceSlack(150);
		AlignSlack(20);	

		AlignStartFrame(0);
		AlignNrFrames(0);

		AttachActionStartAtFrame(0);
		DamageFrame(0);
		Power(0);
		AttachAction(CopChokingDeathLink);
		TargetAIClass(_AIClassAllButAngel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopChokingDeath,CopIdle);
}

SubRoutine(Sub_CheckForNearDeath)
{
		//if(VEndOfAnim!=0)
		if(VFrame==42)
		{
			if(VAttachActorHealth<2010)
			{
				call(ClrAFlagAttached);
				SpawnAction(CopChokingDeath);
			}
		}
		if(VAICon==0)
		{
			call(AIchangemetoenemy);
		}
}


action(CopChokingCough)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\CpChEndS.ske",100,on);
		trigger(_DIRalive);
		break(off);
		nrintframes(6);

		ActionSubRoutine(Sub_AlertAllAfterCough);

		connections(GenIdle);
}

/*
action(CopChokingDie)
{
//		file("pc\actors\Chot\xxx\CpChDedS.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(6);

		connections(CopIdle);
}
*/


action(CopChokingLoop)
{
		file("pc\actors\Chot\xxx\CpChHl1M.ske",100,on,100);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(65);
		DistanceSlack(150);
		AlignSlack(20);	

		AlignStartFrame(0);
		AlignNrFrames(0);

		AttachActionStartAtFrame(0);
		DamageFrame(43);
		Power(20);			//don't change this without changing Sub_CheckForNearDeath...
		AttachAction(CopChokingLoopLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_CheckForNearDeath);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopChokingLoop,CopIdle);
}

action(CopChoking)
{
		file("pc\actors\Chot\xxx\CpChStrM.ske",100,on,100);	//
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(105);
		DistanceSlack(150);
		AlignSlack(20);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(15);
		Power(0);
		AttachAction(CopChokingLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopChokingLoop,CopIdle);
}




SubRoutine(Sub_CopChokeWorkerLink)
{

		if(vframe==37)
		{
			sample(SFXManStrangled,-1);
		}

		if(vframe==64)
		{
			sample(SFXGrunt,-1);
		}

}


SubRoutine(Sub_AlertAllAfterChokeCounter)
{
		if(VAIState!=_AIstateAttack && VAIState!=_AIstateHide && VAIState!=_AIstateGuard)
		{
			if(VFrame==100)
			{
				call(AIsetlockedonactortotarget);
				call(AIchangetargettoenemy);
				CallSub(Sub_AlertAll);
				CallSub(Sub_RandomPunchedSFX);
			}
		}

		if(vframe==97) //body hit ground
		{
			sample(SFXManFallToGround,-1);
		}


}


action(CopChokeWorkerLink)
{
		file("pc\actors\Chot\xxx\CpChStrS.ske",100,on,100);	//Start Choke
		file("pc\actors\Chot\xxx\CpChThrS.ske",100,on,110);	//thrown from choke
		break(off);

		ActionSubRoutine(Sub_CopChokeWorkerLink);
		//ActionSubRoutine(Sub_KillActorKickSnapNeck);

		connections(Genidle);
}
// Cop Choking Worker and failing
action(CopChokeWorker)
{
		file("pc\actors\Chot\xxx\CpChStrM.ske",100,on,100);	//Start Choke
		file("pc\actors\Chot\xxx\CpChThrM.ske",100,on,110);	//Throw Choke


		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIclassmale|_AIclasscop);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(105);
		DistanceSlack(150);
		AlignSlack(20);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(15);
		Power(5);
		AttachAction(CopChokeWorkerLink);
		TargetAIClass(_AIclassriotcop);

		ActionSubRoutine(Sub_AlertAllAfterChokeCounter);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GENGetUpFromBack);
}

action(CopKickingLink)
{
		file("pc\actors\Chot\xxx\MCrlKikU.ske",100,on,100);
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);

		ActionSubRoutine(Sub_RandomKickedSFX);

		connections(GENCrawlSpreadOut);
}

action(CopKicking)
{
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(-1);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(20);
		DistanceSlack(50);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(15);
		DamageFrame(16);
		Power(10);
		AttachAction(CopKickingLink);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}



action(CopKickingBLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\MkckdAss.ske",100,on,100);	//
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);

		ActionSubRoutine(Sub_RandomKickedSFX);

		connections(GENCrawlSpreadOut);
}

action(CopKickingB)
{
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(30);
		DistanceSlack(55);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(16);
		DamageFrame(16);
		Power(10);
		AttachAction(CopKickingBLink);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);


		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopKickingFLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\MkckdHed.ske",100,on,100);	//
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);

		ActionSubRoutine(Sub_RandomKickedSFX);

		connections(BeastIdle,GENCrawlSpreadOut);
}

action(CopKickingF)
{
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(40);
		DistanceSlack(53);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(16);
		DamageFrame(16);
		Power(10);
		AttachAction(CopKickingFLink);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopKickingBobMiss)
{
		file("pc\actors\Chot\xxx\MWrKikL2.ske",100,off,130);	//
		trigger(_alldir);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopKickingBobF)
{
		file("pc\actors\Chot\xxx\MWrKikL1.ske",100,off,150);	//

		//flag(_SXAAalignmovingslave);
		//flag(_SXAAalignmovingmaster);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(55);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		//DamageFrame(20);
		//Power(10);
		AttachAction(GENIdle);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopKickingBobF2,CopKickingBobMiss);
}

action(CopKickingBobF2)
{
		file("pc\actors\Chot\xxx\MWrKikL2.ske",100,off,130);	//
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		//flag(_SXAAalignmovingslave);
		//flag(_SXAAalignmovingmaster);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(55);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		DamageFrame(5);
		Power(10);
		AttachAction(BobThrownBack);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

		trigger(_alldir);
//		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopKickingBobB)
{
		file("pc\actors\Chot\xxx\MWrKikL1.ske",100,off,150);	//

		//flag(_SXAAalignmovingslave);
		//flag(_SXAAalignmovingmaster);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(55);

//		AlignAngle(0);
//		TargetAngle(0);
//		AttackHeight(20);
//		AlignDistance(60);
//		AlignSlack(70);
//		DistanceSlack(120);


		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
//		DamageFrame(20);
//		Power(10);
		AttachAction(GENIdle);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopKickingBobB2,CopKickingBobMiss);
}

action(CopKickingBobB2)
{
		file("pc\actors\Chot\xxx\MWrKikL2.ske",100,off,130);	//
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		//flag(_SXAAalignmovingslave);
		//flag(_SXAAalignmovingmaster);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(20);
		AlignDistance(80);
		AlignSlack(70);
		DistanceSlack(60);


		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(1);
		DamageFrame(3);
		Power(10);
		AttachAction(BobThrownForwardLandAttached);
		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIclassangel);

		trigger(_alldir);
		break(off);
		nrintframes(0);
		connections(GENIdle);
}

action(ChotRunSlamFLink)
{
//		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\MultiAnm\xxx\ChRnSlmL.ske",100,off);	//Left land on face
		trigger(_alldir);
		break(off);
		nrintframes(4);
		//Move(5,0,0);
		ActionSubRoutine(Sub_SetThrown);
		connections(BeastIdle,CopThrownLeftLand);
}

action(ChotRunSlamF)
{
		file("pc\actors\MultiAnm\xxx\ChRnSlm.ske",100,on,100);	//flying double foot stomp kick. flip to feet

		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AIClass(_AIclassmale|_AIclasschot);

		AlignAngle(20);
		TargetAngle(180);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(4);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(5);
		Power(25);
//		AttachAction(GENThrownLeft);
		AttachAction(ChotRunSlamFLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Punching);

		trigger(_DIRshoot);
		break(off);
		nrintframes(2);
		connections(CopIdle);
}

action(ChotRunSlamBLink)
{
//		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\MultiAnm\xxx\ChRnSlmR.ske",100,off);	//Left land on face
		trigger(_alldir);
		break(off);
		nrintframes(4);
		//Move(5,0,0);
		ActionSubRoutine(Sub_SetThrown);
		connections(BeastIdle,CopThrownRightLand);
}

action(ChotRunSlamB)
{
		file("pc\actors\MultiAnm\xxx\ChRnSlm.ske",100,on,100);	//flying double foot stomp kick. flip to feet

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AIClass(_AIclassmale|_AIclasschot);

		AlignAngle(20);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(4);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(5);
		Power(25);
		AttachAction(ChotRunSlamBLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Punching);

		trigger(_DIRshoot);
		break(off);
		nrintframes(2);
		connections(CopIdle);
}

action(ChotRunSlamBobLink)
{
//		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
//		file("pc\actors\MultiAnm\xxx\ChRnSlmL.ske",100,off);	//Left land on face
//		trigger(_alldir);
//		break(off);
		nrintframes(-1);
		Move(500,0,0);
		ActionSubRoutine(Sub_SetThrown);
//		connections(CopThrownLeftLand);
		AttachAction(GENThrownLeft);

}

action(ChotRunSlamBob)
{
		file("pc\actors\MultiAnm\xxx\ChRnSlm.ske",100,on,100);	//slam sideways w/ gun

		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIclassmale|_AIclasschot);

		AlignAngle(20);
		TargetAngle(90);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(360);
		DistanceSlack(50);

		AlignStartFrame(4);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(5);
		Power(15);
		//Power(1);
		//AttachAction(ChotRunSlamBobLink);
		TargetAIClass(_AIClassAngel);
		//ActionSubRoutine(Sub_ChangeMeToEnemy);
		AttachAction(GENThrownLeft);

		trigger(_DIRshoot);
		break(off);
		nrintframes(2);
		connections(CopIdle);
}



action(CopBackwardStompKickF)
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
		connections(CopIdle);
}

action(CopBackwardStompKickB)
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
		AttachAction(CopThrownForwardFromKick);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Kicking);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopStompKickF)
{
		file("pc\actors\Chot\xxx\MFlStmp2.ske",50,on,100);	//flying double foot stomp kick. flip to feet
		file("pc\actors\Chot\xxx\MSpinKk2.ske",100,on,100);	//flying spinning back heel kick
//		file("pc\actors\Chot\xxx\MFlStmp1.ske",100,on,100);	//flying double foot stomp kick. flip to feet
//		file("pc\actors\Chot\xxx\Mkipup.ske",100,on,100);	//flying double foot stomp kick. flip to feet

		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(00);
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
		connections(CopIdle);
}

action(CopStompKickB)
{
		file("pc\actors\Chot\xxx\MFlStmp2.ske",50,on,100);	//flying double foot stomp kick. flip to feet
		file("pc\actors\Chot\xxx\MSpinKk2.ske",100,on,100);	//Spinning flying kick
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(50);
		AlignDistance(110);
		AlignSlack(50);
		DistanceSlack(50);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(9);
		DamageFrame(9);
		Power(10);
		AttachAction(CopThrownForwardFromKick);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_Kicking);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}


SubRoutine(Sub_ChotShoulderThrowSounds)
{

//		If(vframe==13)
//		{
//			CallSub(Sub_Random edSFX);
//		}

		if(vframe==30)
		{
			CallSub(Sub_RandomPunchedSFX);
		}
}


action(ChotShoulderThrowLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\MultiAnm\xxx\MSlmThwS.ske",100,on,100);	//Cop Gun Strip Slave
		break(off);
	//	ColSphereScale(50);
	//	ColSphereYOffsetScale(100);
		ActionSubRoutine(Sub_ChotShoulderThrowSounds);
		connections(BeastIdle,GENGetUpFromBack);
}

action(ChotShoulderThrow)
{
		file("pc\actors\MultiAnm\xxx\MSlmThwM.ske",100,on,100);	//Chot slam throw guy over head and backwards. 

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIclassmale|_AIclasschot|_SXAAStandingOnly);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(70);
		AlignDistance(135);
		AlignSlack(40);
		DistanceSlack(60);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(30);
		Power(25);
		AttachAction(ChotShoulderThrowLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}




action(CopStripGunLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\CpGnStrS.ske",100,on,115);	//Cop Gun Strip Slave
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);

		ActionSubRoutine(Sub_RemoveGun);

		connections(BeastIdle,GENGetUpFromBack);
}

action(CopStripGun)
{
		file("pc\actors\Chot\xxx\CpGnStrM.ske",25,on,115);	//Cop Gun Strip Elbow 
		file("pc\actors\Chot\xxx\CpGnStKM.ske",35,on,115);	//Cop Gun Strip Side Kick
		file("pc\actors\Chot\xxx\CpGnSK2M.ske",65,on,115);	//Cop Gun Strip Front Stomp Kick
		file("pc\actors\Chot\xxx\CpGnSK3M.ske",100,on,115);	//Cop Gun Strip jumping spinning back heel kick

		flag(_SXAAalignmovingslave|_SXAAStandingOnly);

		AIClass(_AIclassMale|_AIclasscop);


		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(60);
		AlignDistance(100);
		AlignSlack(70);
		DistanceSlack(55);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(0);
		DamageFrame(16);
		Power(10);
		AttachAction(CopStripGunLink);
		TargetAIClass(_AIClassAllButAngel);

		AttachActionDelay(150);

		ActionSubRoutine(Sub_RemoveGunPunch);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopStripGunBob)
{
//		file("pc\actors\Chot\xxx\CpGnStrM.ske",25,on,115);	//Cop Gun Strip Elbow 
		file("pc\actors\Chot\xxx\CpGnStKM.ske",50,on,115);	//Cop Gun Strip Side Kick
//		file("pc\actors\Chot\xxx\CpGnSK2M.ske",65,on,115);	//Cop Gun Strip Front Stomp Kick
		file("pc\actors\Chot\xxx\CpGnSK3M.ske",100,on,115);	//Cop Gun Strip jumping spinning back heel kick

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(60);
		AlignDistance(100);
		AlignSlack(70);
		DistanceSlack(56);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(16);
		DamageFrame(16);
		Power(10);
		AttachAction(BobThrownBack);
		TargetAIClass(_AIclassangel);


		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}


action(CopGunButFLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\MStgrBk1.ske",100,on,100);
		break(off);
		ColSphereScale(50);
		ActionSubRoutine(Sub_RandomPunchedSFX);
		ColSphereYOffsetScale(100);
		connections(BeastIdle,GenIdle);
}

subroutine(Sub_CopGunButBLink)
{
		//CallSub(Sub_RandomPunchedSFX);
		//CallSub(Sub_SetThrown);
		CallSub(Sub_SetAttackerToEnemyAndHandleThrown);

		if(vframe==17)
		{
			sample(SFXManFallToGround,-1);
		}
}
action(CopGunButBLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\chot\xxx\ThrnSpnB.ske",100,off,150,-1,_DIRnotai);
		file("pc\actors\Chot\xxx\ThrnSpnB.ske",100,off,100);
		break(off);
		ColSphereScale(50);
		ActionSubRoutine(Sub_CopGunButBLink);
		ColSphereYOffsetScale(100);
		connections(BeastIdle,CopGetUpFromFrontForwardKip,CopGetUpFromGunButB);
}


action(CopGetUpFromGunButB)
{
//		file("pc\actors\chot\xxx\thrspbst.ske",100,off,185,-1,_DIRnotai,Sub_GetUpClearThrown68);
		file("pc\actors\chot\xxx\MstandF2.ske",100,off,80,-1,_DIRnotai,Sub_GetUpClearThrown24); //Male stand from front, possessed. faster.
		file("pc\actors\chot\xxx\thrspbst.ske",100,off,100,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(16);
		connections(BeastIdle,GenIdle);
}


action(CopCloseRange)
{
		file("pc\actors\chot\xxx\MShPmph.ske",100,on,100,_AIclassCloseRange);

		AIClass(_AIclassCloseRange|_AIclassMale|_AIclassFemale);

		trigger(_DIRshoot|_DIRHaveGun|_DIRcombatmode);
		break(on);
		nrintframes(0);


		connections(CopSpreadOutGun,CopCloseRange,CopIdle);
}

action(CopGunButF)
{
		file("pc\actors\Chot\xxx\MWrPsBk2.ske",100,on,100);	//Throw left jab
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(60);
		AlignDistance(100);
		AlignSlack(70);
		DistanceSlack(55);


		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(15);
		AttachAction(CopGunButFLink);
		TargetAIClass(_AIClassAllButAngel);
		ActionSubRoutine(Sub_ChangeMeToEnemy);

		AttachActionDelay(300);

		trigger(_DIRshoot|_DIRhavegun);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}

action(CopGunButB)
{
		file("pc\actors\Chot\xxx\MWrPsBk2.ske",100,on,100);	//Throw left jab
		//file("pc\actors\chot\xxx\MBxRjab.ske",60,on,150);	//Throw right jab
		//file("pc\actors\chot\xxx\MBxRUcut.ske",100,on,150);	//Throw right uppercut

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);


		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(60);
		AlignDistance(100);
		AlignSlack(70);
		DistanceSlack(55);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(15);
		AttachAction(CopGunButBLink);
		TargetAIClass(_AIClassAllButAngel);
		ActionSubroutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}


action(CopGunButBob)
{
		file("pc\actors\Chot\xxx\MWrPsBk2.ske",100,on,100);	//push back bob

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(70);
		AlignDistance(90);
		AlignSlack(40);
		DistanceSlack(30);

		AlignStartFrame(11);
		AlignNrFrames(1);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(2);
		AttachAction(BobThrownBack);
		TargetAIClass(_AIclassangel);

		AttachActionRandomness(10,30,50);		//easy,medium,hard


		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(GenIdle);
}



SubRoutine(Sub_riotLinkUp)
{
		State(_clr,StateCrouching);
		ActorFlag(_clr,_AFLAGshieldon);
}


action(RiotArmSlamFLink)
{
		file("pc\actors\Behemoth\xxx\BWnd4Cm.ske",100,off,100,_AIclassbeast,_DIRcombatmode);
		file("pc\actors\Behemoth\xxx\BWnd4Nc.ske",100,off,100,_AIclassbeast);
		file("pc\actors\Chot\xxx\MStgrBk1.ske",100,on,100);
		//file("pc\actors\chot\xxx\Mstun1g.ske",100,on);//sway around stunned

		ActionSubroutine(Sub_RandomPunchedSFX);

		break(off);
		//ColSphereScale(50);
		//ColSphereYOffsetScale(100);
		//connections(GenIdle);
		connections(BeastIdle,RiotArmSlamFLinkStunned);

}

action(RiotArmSlamFLinkStunned)
{
		file("pc\actors\chot\xxx\Mstun2g.ske",100,on);//sway around stunned

		nrintframes(21);

		ActionSubRoutine(Sub_ClrCombatMode);

		break(off);
		connections(Genidle);

}

action(RiotArmSlamF)
{
		file("pc\actors\CopRiot\xxx\RCmSlm2.ske",40,on,100);	//double fist slam
		file("pc\actors\CopRiot\xxx\RCmclub.ske",100,on,100);	//whack with baton

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAStandingOnly);

		AIClass(_AIclassRiotCop|_AIclassMale);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(70);
		AlignDistance(100);
		AlignSlack(160);
		DistanceSlack(140);

		AlignStartFrame(00);
		AlignNrFrames(10);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(30);
		AttachAction(RiotArmSlamFLink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_RiotLinkUp);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}



action(RiotArmSlamBobLink)
{
		file("pc\actors\Bob\xxx\BthrnFwA.ske",100,off);	//Forward hold frame
		ActionSubroutine(Sub_RandomPunchedSFX);
		move(0,0,-10);
		nrintframes(1);
		connections(BobThrownForwardLand);
		//connections(GENThrownForward);
}

action(RiotArmSlamBob)
{
		file("pc\actors\CopRiot\xxx\RCmSlm2.ske",40,on,100);	//double fist slam
		file("pc\actors\CopRiot\xxx\RCmclub.ske",100,on,100);	//whack with baton

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIclassRiotCop|_AIclassMale);

		AlignAngle(0);
		TargetAngle(0);
		AttackHeight(70);
		AlignDistance(100);
		AlignSlack(360);
		DistanceSlack(140);

		AlignStartFrame(10);
		AlignNrFrames(1);

		AttachActionStartAtFrame(11);
		DamageFrame(11);
		Power(30);
		//AttachAction(RiotArmSlamFLink);
		AttachAction(RiotArmSlamBobLink);
		TargetAIClass(_AIClassAngel);

		//ActionSubRoutine(Sub_RiotLinkUp);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(CopIdle);
}



/* *************   Standard moves with gun ******************* */

action(CopWalkGun)
{
		file("pc\actors\Chot\xxx\Mwkshtcg.ske",100,on,100,-1,_DIRhavegun);			//walkshoot
		file("pc\actors\Chot\xxx\MWkCNGFw.ske",100,on,100);			//combat without gun
		//file("pc\actors\Chot\xxx\Mwkfwwg2.ske",100,on);		//patrol
		trigger(_DIRwalking|_DIRforward);
		break(on);
		offset(5);
		nrintframes(8);
		connections(CopKickingBobF,CopKickingBobB,RiotArmSlamBob,RiotArmSlamF,CopGunButBob,CopGunButF,CopGunButB,CopBoxing,CopSpreadOutGun,CopIdle);
}

action(CopWalkBackGun)
{
		file("pc\actors\Chot\xxx\Mwkbk.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MWkCNGB.ske",100,on,100);			//combat without gun
		nrintframes(8);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(30);
		connections(CopSpreadOutGun,CopIdle);
}
action(CopWalkLGun)
{
		file("pc\actors\Chot\xxx\mshwk90l.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MWkCNGL.ske",100,on,100);			//combat without gun
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(14);
		connections(CopSpreadOutGun,CopIdle);
}
action(CopWalkRGun)
{
		file("pc\actors\Chot\xxx\mshwk90r.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MWkCNGR.ske",100,on,100);			//combat without gun
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(0);
		connections(CopSpreadOutGun,CopIdle);
}
action(CopWalkDiagFLGun)
{
		file("pc\actors\chot\xxx\mshwk45l.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MWkCNGFL.ske",100,on,100);			//combat without gun
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		offset(15)
		connections(CopKickingBobF,CopKickingBobB,RiotArmSlamBob,RiotArmSlamF,CopGunButBob,CopGunButF,CopGunButB,CopBoxing,CopSpreadOutGun,CopIdle);
}
action(CopWalkDiagFRGun)
{
		file("pc\actors\chot\xxx\mshwk45r.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MWkCNGFR.ske",100,on,100);			//combat without gun
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		offset(30)
		connections(CopKickingBobF,CopKickingBobB,RiotArmSlamBob,RiotArmSlamF,CopGunButBob,CopGunButF,CopGunButB,CopBoxing,CopSpreadOutGun,CopIdle);
}


action(CopWalkDiagBLGun)
{
		file("pc\actors\chot\xxx\mwkbk45l.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MWkCNGBL.ske",100,on,100);			//combat without gun
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(30)
		nrintframes(8);
		connections(CopSpreadOutGun,CopIdle);
}
action(CopWalkDiagBRGun)
{
		file("pc\actors\chot\xxx\mwkbk45r.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MWkCNGBR.ske",100,on,100);			//combat without gun
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(30)
		nrintframes(8);
		connections(CopSpreadOutGun,CopIdle);
}


action(CopRunGun)
{
		file("pc\actors\Chot\xxx\MRnSht4.ske",100,on,100,-1,_DIRhavegun);
//		file("pc\actors\Chot\xxx\MRnSht3.ske",100,on);
		file("pc\actors\Chot\xxx\Mrun1f.ske",100,on);

		trigger(_DIRforward);
		break(on);
		offset(8);
		nrintframes(8);
		soundlevel(100);
		connections(ChotRunSlamBob,CopKickingBobF,CopKickingBobB,ChotRunSlamF,RiotArmSlamBob,RiotArmSlamF,ChotRunSlamB,CopStompKickF,CopStompKickB,CopSpreadOutGun,CopIdle);
}
action(CopRunBackGun)
{
		file("pc\actors\Chot\xxx\MrnBkcyv.ske",30,on);//variation: look back over left shoulder
		file("pc\actors\Chot\xxx\Mrnbkcyp.ske",100,on);
		nrintframes(8);
		trigger(_DIRbackward);
		break(on);
		offset(13)
		soundlevel(100);
		connections(CopBackwardStompKickF,CopBackwardStompKickB,CopSpreadOutGun,CopIdle);
}
action(CopRunLGun)
{
		file("pc\actors\Chot\xxx\mrnshtr.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\Mrun1l.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideleft);
		break(on);
		offset(10)
		soundlevel(100);
		connections(CopSpreadOutGun,CopIdle);
}
action(CopRunRGun)
{
		file("pc\actors\Chot\xxx\mrnshtl.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\Mrun1r.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideright);
		break(on);
		offset(9)
		soundlevel(100);
		connections(CopSpreadOutGun,CopIdle);
}
action(CopRunDiagFLGun)
{
		file("pc\actors\chot\xxx\mrnsh45r.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\Mrun1fl.ske",100,on);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(9)
		nrintframes(8);
		soundlevel(100);
		connections(ChotRunSlamBob,CopKickingBobF,CopKickingBobB,ChotRunSlamF,RiotArmSlamBob,RiotArmSlamF,ChotRunSlamB,CopStompKickF,CopStompKickB,CopSpreadOutGun,CopIdle);
}
action(CopRunDiagFRGun)
{
		file("pc\actors\chot\xxx\mrnsh45l.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\Mrun1fr.ske",100,on);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(10)
		nrintframes(8);
		soundlevel(100);
		connections(ChotRunSlamBob,CopKickingBobF,CopKickingBobB,ChotRunSlamF,RiotArmSlamBob,RiotArmSlamF,ChotRunSlamB,CopStompKickF,CopStompKickB,CopSpreadOutGun,CopIdle);
}


action(CopRunDiagBLGun)
{
		file("pc\actors\chot\xxx\mrnbk45l.ske",100,on);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		nrintframes(8)
		offset(13)
		soundlevel(100);
		connections(CopBackwardStompKickF,CopBackwardStompKickB,CopSpreadOutGun,CopIdle);
}
action(CopRunDiagBRGun)
{
		file("pc\actors\chot\xxx\mrnbk45r.ske",100,on);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(13)
		nrintframes(8);
		soundlevel(100);
		connections(CopBackwardStompKickF,CopBackwardStompKickB,CopSpreadOutGun,CopIdle);
}
/* *************   Standard moves without gun ******************* */

action(CopWalk)
{
		file("pc\actors\Chot\xxx\ChWlkF.ske",100,on,100,_AIclasschot,_DIRhavegun);		//Chot shambling walk forward WITH GUN:
		file("pc\actors\Chot\xxx\ChWlkFN.ske",100,on,100,_AIclasschot);		//Chot shambling walk forward NO GUN:
		file("pc\actors\pimp\xxx\pwalk.ske",100,on,100,_AIclasspimp);
		file("pc\actors\worker\xxx\wrkwlkf.ske",100,on,100,_AIclassworker);
		//file("pc\actors\Chot\xxx\Mwkbk.ske",100,on,100,-1,_DIRhavegun);				//with gun non combat
		file("pc\actors\Chot\xxx\MWkNcGFw.ske",100,on,100,-1,_DIRhavegun);				//carrying gun non combat
		file("pc\actors\Chot\xxx\MWkFNGF.ske",100,on,100,-1);				//normal
		
		trigger(_DIRwalking|_DIRforward);
		break(on);
		offset(35);
		nrintframes(8);
		connections(CopSpreadOut,CopIdle);
}

action(CopWalkBack)
{
		file("pc\actors\Chot\xxx\ChWlkB.ske",100,on,100,_AIclasschot);		//Chot shambling walk backward
		file("pc\actors\pimp\xxx\pwalkbck.ske",100,on,100,_AIclasspimp);
		file("pc\actors\worker\xxx\wrkwlkb.ske",100,on,100,_AIclassworker);						//normal
//		file("pc\actors\Chot\xxx\MWkBkv.ske",30,on);//variation: look back over left shoulder
		file("pc\actors\Chot\xxx\Mwkbngb.ske",100,on,100,-1);
		//file("pc\actors\Chot\xxx\MwkLmpBk.ske",100,on,100,-1);					//limping
		nrintframes(8);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(1);
		connections(CopSpreadOut,CopIdle);
}

action(CopWalkL)
{
		file("pc\actors\Chot\xxx\ChWlkL.ske",100,on,100,_AIclasschot,_DIRhavegun);		//Chot shambling walk WITH GUN:
		file("pc\actors\Chot\xxx\ChWlkLN.ske",100,on,100,_AIclasschot);		//Chot shambling walk left
		file("pc\actors\worker\xxx\wrkwlkl.ske",100,on,100,_AIclassworker);
		file("pc\actors\Chot\xxx\MWkNcGL.ske",100,on,100,-1,_DIRhavegun);				//carrying gun non combt
		file("pc\actors\Chot\xxx\MWkFNGL.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(35);
		connections(CopSpreadOut,CopIdle);
}

action(CopWalkR)
{
		file("pc\actors\Chot\xxx\ChWlkR.ske",100,on,100,_AIclasschot,_DIRhavegun);		//Chot shambling walk WITH GUN:
		file("pc\actors\Chot\xxx\ChWlkRN.ske",100,on,100,_AIclasschot);		//Chot shambling walk right
		file("pc\actors\worker\xxx\wrkwlkr.ske",100,on,100,_AIclassworker);
		file("pc\actors\Chot\xxx\MWkNcGR.ske",100,on,100,-1,_DIRhavegun);				//carrying gun non combat
		file("pc\actors\Chot\xxx\MWkFNGR.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(35);
		connections(CopSpreadOut,CopIdle);
}

action(CopWalkDiagFL)
{
		file("pc\actors\Chot\xxx\ChWlkFL.ske",100,on,100,_AIclasschot,_DIRhavegun);		//Chot shambling walk WITH GUN:
		file("pc\actors\Chot\xxx\ChWlkFLN.ske",100,on,100,_AIclasschot);		//Chot shambling walk forward left
		file("pc\actors\worker\xxx\wrkwlkfl.ske",100,on,100,_AIclassworker);
		file("pc\actors\Chot\xxx\MWkNcGFL.ske",100,on,100,-1,_DIRhavegun);				//carrying gun non combat
		file("pc\actors\Chot\xxx\MWkFNGFL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		offset(35)
		connections(CopSpreadOut,CopIdle);
}

action(CopWalkDiagFR)
{
		file("pc\actors\Chot\xxx\ChWlkFR.ske",100,on,100,_AIclasschot,_DIRhavegun);		//Chot shambling walk WITH GUN:
		file("pc\actors\Chot\xxx\ChWlkFRN.ske",100,on,100,_AIclasschot);		//Chot shambling walk forward right
		file("pc\actors\worker\xxx\wrkwlkfr.ske",100,on,100,_AIclassworker);
		file("pc\actors\Chot\xxx\MWkNcGFR.ske",100,on,100,-1,_DIRhavegun);				//carrying gun non combat
		file("pc\actors\Chot\xxx\MWkFNGFR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		offset(35)
		connections(CopSpreadOut,CopIdle);
}

action(CopWalkDiagBL)
{
		file("pc\actors\Chot\xxx\ChWlkBL.ske",100,on,100,_AIclasschot);		//Chot shambling walk backward left
		file("pc\actors\worker\xxx\wrkwlkbl.ske",100,on,100,_AIclassworker);
		file("pc\actors\Chot\xxx\MwkbngbL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(1)
		nrintframes(8);
		connections(CopSpreadOut,CopIdle);
}

action(CopWalkDiagBR)
{
		file("pc\actors\Chot\xxx\ChWlkBR.ske",100,on,100,_AIclasschot);		//Chot shambling walk backward right
		file("pc\actors\worker\xxx\wrkwlkbr.ske",100,on,100,_AIclassworker);
		file("pc\actors\Chot\xxx\MwkbngbR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(1)
		nrintframes(8);
		connections(CopSpreadOut,CopIdle);
}


action(CopRun)
{
		file("pc\actors\pimp\xxx\prun.ske",100,on,115,_AIclasspimp);
		file("pc\actors\Chot\xxx\Mrun1f.ske",100,on);
		trigger(_DIRforward);
		break(on);
		offset(7)
		nrintframes(8);
		connections(ChotRunSlamBob,ChotRunSlamF,ChotRunSlamB,CopStompKickF,CopStompKickB,CopSpreadOut,CopIdle);
}
action(CopRunBack)
{
		file("pc\actors\pimp\xxx\prunback.ske",100,on,100,_AIclasspimp);
		file("pc\actors\Chot\xxx\Mrun1bv.ske",30,on);//variation: look back over left shoulder
		file("pc\actors\Chot\xxx\Mrun1b.ske",100,on);
//		intforloop(on);
		nrintframes(8);
		trigger(_DIRbackward);
		break(on);
		offset(16)
		connections(CopBackwardStompKickF,CopBackwardStompKickB,CopSpreadOut,CopIdle);
}
action(CopRunL)
{
		file("pc\actors\Chot\xxx\Mrun1l.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideleft);
		break(on);
		offset(7)
		connections(CopSpreadOut,CopIdle);
}
action(CopRunR)
{
		file("pc\actors\Chot\xxx\Mrun1r.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideright);
		break(on);
		offset(7)
		connections(CopSpreadOut,CopIdle);
}
action(CopRunDiagFL)
{
		file("pc\actors\Chot\xxx\Mrun1fl.ske",100,on);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(7)
		nrintframes(8);
		connections(ChotRunSlamBob,ChotRunSlamF,ChotRunSlamB,CopStompKickF,CopStompKickB,CopSpreadOut,CopIdle);
}
action(CopRunDiagFR)
{
		file("pc\actors\Chot\xxx\Mrun1fr.ske",100,on);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(7)
		nrintframes(8);
		connections(ChotRunSlamBob,ChotRunSlamF,ChotRunSlamB,CopStompKickF,CopStompKickB,CopSpreadOut,CopIdle);
}


action(CopRunDiagBL)
{
		file("pc\actors\Chot\xxx\Mrun1bl.ske",100,on);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		nrintframes(8)
		offset(16)
		connections(CopBackwardStompKickF,CopBackwardStompKickB,CopSpreadOut,CopIdle);
}
action(CopRunDiagBR)
{
		file("pc\actors\Chot\xxx\Mrun1br.ske",100,on);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(16)
		nrintframes(8);
		connections(CopBackwardStompKickF,CopBackwardStompKickB,CopSpreadOut,CopIdle);
}

/* *************   Hide moves ******************* */

action(CopHideLeanLeftS)
{
		file("pc\actors\Chot\xxx\WTrnLS.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(CopHideLeanLeftI);
}
action(CopHideLeanLeftI)
{
		file("pc\actors\Chot\xxx\WTrnLIdl.ske",70,on);
		file("pc\actors\Chot\xxx\WTrnLluk.ske",100,on);

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(CopHideLeanLeftShoot,CopHideLeanLeftGrenade,CopHideLeanLeftI);
}

action(CopHideLeanLeftE)
{
		file("pc\actors\Chot\xxx\WTrnLE.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(GENIdle);
}

action(CopHideLeanLeftShoot)
{
		file("pc\actors\chot\xxx\WTrnLFL.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\chot\xxx\WTrnLFPm.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\chot\xxx\WTrnLFL.ske",100,on,100,_AIclasslightgun);
		file("pc\actors\chot\xxx\WTrnLFHv.ske",100,on,100,-1);					//heavy recoil?

		trigger(_DIRshoot|_DIRHaveGun);
		break(off);
		nrintframes(1);
		connections(CopHideLeanLeftI);
}

action(CopHideLeanLeftGrenade)
{
		file("pc\actors\chot\xxx\WTrnLThg.ske",100,off);

		trigger(_DIRGrenade);
		break(off);
		nrintframes(1);
		connections(CopHideLeanLeftI);
}

//---

action(CopHideLeanRightS)
{
		file("pc\actors\Chot\xxx\WTrnRS2.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(CopHideLeanRightI);
}

action(CopHideLeanRightI)
{
		//XXX Tmp copy from CopIdle
		file("pc\actors\chot\xxx\MWryId2P.ske",10,on,100,_AIclassHipGun);
		file("pc\actors\chot\xxx\MWryId1P.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\Chot\xxx\MWryIdl2.ske",10,on);	//Look left and right
		file("pc\actors\Chot\xxx\MWryIdl1.ske",100,on);	//Heavy Breathing

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(CopStandShoot,GENThrowGrenade,CopHideLeanRightI);
}


action(CopHideLeanRightE)
{
		file("pc\actors\Chot\xxx\WTrnRE2.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(GENIdle);
}


action(CopHideRoll)
{
		file("pc\actors\Chot\xxx\MDivNRol.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(GENIdle);
}

action(Cop180)
{
		file("pc\actors\Chot\xxx\MWryTrAr.ske",100,on);
		trigger(_allDIR);
		break(off);
		offset(12);
		nrintframes(4);
		ApplyRotationToRootInEnd(180);
		connections(CopSpreadOut,CopIdle);
}

//----

action(CopHideCrouchLeanLeftS)
{
		file("pc\actors\Chot\xxx\WCrLfSt.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopHideCrouchLeanLeftI,CopCrouchTurnRight,CopCrouchTurnLeft);
}
action(CopHideCrouchLeanLeftI)
{
		file("pc\actors\Chot\xxx\WCrLfIdl.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopHideCrouchLeanLeftG,CopHideCrouchLeanLeftI,CopCrouchTurnRight,CopCrouchTurnLeft);
}

action(CopHideCrouchLeanLeftE)
{
		file("pc\actors\Chot\xxx\WCrLfEnd.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchIdle);
}

action(CopHideCrouchLeanLeftG)
{
		file("pc\actors\Chot\xxx\WCrLfGrn.ske",100,off);
		trigger(_DIRgrenade);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopHideCrouchLeanLeftE,CopCrouchTurnRight,CopCrouchTurnLeft);
}

//-----

action(CopHideCrouchLeanRightS)
{
		file("pc\actors\Chot\xxx\WCrRtSt.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopHideCrouchLeanRightI,CopCrouchTurnRight,CopCrouchTurnLeft);
}

action(CopHideCrouchLeanRightI)
{
		//XXX Tmp copy from CopCrouchIdle
		file("pc\actors\Chot\xxx\MCrIdle.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchShoot,CopHideCrouchLeanRightG,CopHideCrouchLeanRightI,CopCrouchTurnRight,CopCrouchTurnLeft);
}


action(CopHideCrouchLeanRightE)
{
		file("pc\actors\Chot\xxx\WCrRtEnd.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopHideCrouchLeanRightG,CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchIdle);
}

action(CopHideCrouchLeanRightG)
{
		file("pc\actors\Chot\xxx\MCrThrwG.ske",100,off);
		trigger(_DIRgrenade);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopHideCrouchLeanRightE,CopCrouchTurnRight,CopCrouchTurnLeft);
}


action(CopHideCrouchRoll)
{
		file("pc\actors\Chot\xxx\MCrRF294.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopHideCrouchLeanRightI,CopCrouchTurnRight,CopCrouchTurnLeft);
}

action(CopCrouch180)
{
		file("pc\actors\Chot\xxx\MCrWTrA2.ske",100,off,100);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ApplyRotationToRootInEnd(180);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchForward2,CopCrouchTurnRight,CopCrouchTurnLeft);
}

action(CopCrouchForward2)
{
		file("pc\actors\Chot\xxx\MCrWlkF.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchIdle);
}

/* *************   Crouching moves ******************* */

action(CopCrouchWoundLight)
{
		file("pc\actors\Chot\xxx\MCrWnd1.ske",10,off);	//Head.    
		file("pc\actors\Chot\xxx\MCrWnd2.ske",100,off);	//Stomach/chest. 
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchShoot,CopCrouchSpreadOut,CopCrouchIdle);
}

subroutine(Sub_CopCrouchDead)
{
		if(vframe==14&&VActionIndex==0)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==125 && VActionIndex==1)
		{
			sample(SFXManFallToGround,-1);
		}
}
action(CopCrouchDead)
{
		file("pc\actors\Chot\xxx\McrDeth1.ske",50,off);	//collapse backward death
		file("pc\actors\Chot\xxx\McrDeth2.ske",100,off);	//crawl death
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		nrintframes(8);
		ActionSubRoutine(Sub_CopCrouchDead);
}

action(CopCrouchDown)
{
		file("pc\actors\chot\xxx\MCrStrtW.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Chot\xxx\MCrStart.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchIdle);
}

action(CopCrouchUp)
{
		file("pc\actors\chot\xxx\MCrEndW.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\Chot\xxx\MCrEnd.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopSpreadOut,CopIdle);
}

action(CopCrouchShoot)
{
		file("pc\actors\Chot\xxx\mcrhvfrh.ske",100,on);		//knee down, heavy hold
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchShoot,CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchIdle);
}

action(CopCrouchLightRecoil)
{
		file("pc\actors\Chot\xxx\mcrltfr.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchShoot,CopCrouchIdle);
}

action(CopCrouchGrenade)
{
		file("pc\actors\Chot\xxx\mcrthrwg.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchHeavyRecoil)
{
		file("pc\actors\Chot\xxx\mcrhvfrp.ske",100,on,140,_AIclassHipGun);
		file("pc\actors\Chot\xxx\mcrhvfr.ske",100,on,140,-1);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchShoot,CopCrouchIdle);
}

action(CopCrouchIdle)
{
		file("pc\actors\CopRiot\xxx\RCrShldS.ske",100,off,100,_AIclassRiotCop);
		file("pc\actors\CopRiot\xxx\RCrShldL.ske",100,on,100,_AIclassRiotCop);
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MCrIdle.ske",100,on,100,-1,_DIRhavegun);
		file("pc\actors\Chot\xxx\MCrIdNGL.ske",20,on);
		file("pc\actors\Chot\xxx\MCrIdNG.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(7);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(RiotArmSlamBob,RiotArmSlamF,CopCrouchShoot,CopCrouchTurnRight,CopCrouchTurnLeft,CopCrouchSpreadOut,CopCrouchIdle);
}


action(CopCrouchSpreadOut)
{
		file("pc\actors\Chot\xxx\MCrIdle.ske",100,on);
		trigger(_DIRmove);
		nrintframes(-1);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(RiotArmSlamBob,RiotArmSlamF,CopCrouchForwardLeft,CopCrouchForwardRight,CopCrouchBackwardLeft,CopCrouchBackwardRight,CopCrouchForward,CopCrouchBackward,CopCrouchLeft,CopCrouchRight,CopCrouchRForwardLeft,CopCrouchRForwardRight,CopCrouchRBackwardLeft,CopCrouchRBackwardRight,CopCrouchRForward,CopCrouchRBackward,CopCrouchRLeft,CopCrouchRRight,CopCrouchTurnRight,CopCrouchTurnLeft);
}


action(CopCrouchRForward)
{
		file("pc\actors\Chot\xxx\MCrRunF.ske",100,on,110);
		trigger(_DIRforward);
		break(on);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}
action(CopCrouchRBackward)
{
		file("pc\actors\Chot\xxx\MCrRunB.ske",100,on,110);
		trigger(_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchRLeft)
{
		file("pc\actors\Chot\xxx\MCrRunL.ske",100,on,110);
		trigger(_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchRRight)
{
		file("pc\actors\Chot\xxx\MCrRunR.ske",100,on,110);
		trigger(_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchRForwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunFL.ske",100,on,110);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchRBackwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunBL.ske",100,on,110);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchRForwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunFR.ske",100,on,110);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchRBackwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunBR.ske",100,on,110);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchForward)
{
		file("pc\actors\Chot\xxx\MCrWlkF.ske",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}
action(CopCrouchBackward)
{
		file("pc\actors\Chot\xxx\MCrWlkB.ske",100,on);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchLeft)
{
		file("pc\actors\Chot\xxx\MCrStfL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchRight)
{
		file("pc\actors\Chot\xxx\MCrStfR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchForwardLeft)
{
		file("pc\actors\Chot\xxx\MCrStLF.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchBackwardLeft)
{
		file("pc\actors\Chot\xxx\MCrStLB.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchForwardRight)
{
		file("pc\actors\Chot\xxx\MCrStRF.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(CopCrouchBackwardRight)
{
		file("pc\actors\Chot\xxx\MCrStRB.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrouchSpreadOut,CopCrouchIdle);
}

action(ScientistWork)
{
		file("pc\actors\Scientst\xxx\sci_idl1.ske",100,on);	//use keypad
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(false)
		connections(CopSpreadOut,CopStandShoot,CopTurnLeft,CopTurnRight,CopIdle);
}

/* *************   Jump And Fall ******************* */

/*
New jumping animations for the male characters. For run forward, run back and Jump in place.
Run jump forward start:
	Chot\xxx\MRnJmpA.ske

Run jump forward middle:
	Chot\xxx\MRnJmpB.ske

Run jump forward peak. Go into jump fall:
	Chot\xxx\MRnJmpC.ske


Run jump Backward start:
	Chot\xxx\MRBJmpA.ske

Run jump Backward middle:
	Chot\xxx\MRBJmpB.ske

Run jump Backward peak. Go into jump fall:
	Chot\xxx\MRBJmpC.ske

*/

/////////////////////////////////////////////////////////////
////////////NEW JUMPING CODE/////////////////////////////////
/////////////////////////////////////////////////////////////
//
action(CopJump)	//Lead directly to next animation
{
		trigger(_DIRjump);
		AIClass(_AIClassCopSkeleton);
		nrintframes(-1);
		connections(CopJumpBL,CopJumpBR,CopJumpBackwards,CopJumpFL,CopJumpL,CopJumpFR,CopJumpR,CopJumpForward,CopJumpInPlace);
}


action(CopJumpHigh)
{
		file("pc\actors\Chot\xxx\MJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallInplace);
}

action(CopJumpMedium)
{
		file("pc\actors\Chot\xxx\MJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHigh,CopFallInplace);
}


action(CopJumpHighB)
{
		file("pc\actors\Chot\xxx\MRBJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallInplace);
}

action(CopJumpMediumB)
{
		file("pc\actors\Chot\xxx\MRBJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHighB,CopFallInplace);
}

action(CopJumpHighR)
{
		file("pc\actors\Chot\xxx\MRnJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
//		rotate(90);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallR);
}

action(CopJumpMediumR)
{
		file("pc\actors\Chot\xxx\MRnJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
//		rotate(90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHighR,CopFallR);
}

action(CopJumpHighL)
{
		file("pc\actors\Chot\xxx\MRnJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(-90);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallL);
}

action(CopJumpMediumL)
{
		file("pc\actors\Chot\xxx\MRnJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(-90);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHighL,CopFallL);
}

action(CopJumpHigh45R)
{
		file("pc\actors\Chot\xxx\MRnJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallFR);
}

action(CopJumpMedium45R)
{
		file("pc\actors\Chot\xxx\MRnJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHigh45R,CopFallFR);
}

action(CopJumpHigh45L)
{
		file("pc\actors\Chot\xxx\MRBJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(-45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallFL);
}

action(CopJumpMedium45L)
{
		file("pc\actors\Chot\xxx\MRnJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(-45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHigh45L,CopFallFL);
}

action(CopJumpHighB45R)
{
		file("pc\actors\Chot\xxx\MRBJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(-45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallBR);
}

action(CopJumpMediumB45R)
{
		file("pc\actors\Chot\xxx\MRBJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(-45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHighB45R,CopFallBR);
}

action(CopJumpHighB45L)
{
		file("pc\actors\Chot\xxx\MRnJmpC.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedHigh,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(45);
		break(off);
//		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopFallBL);
}

action(CopJumpMediumB45L)
{
		file("pc\actors\Chot\xxx\MRBJmpB.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedMiddle,0);
		trigger(_DIRjump);
		nrintframes(4);
		//rotate(45);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpHighB45L,CopFallBL);
}


action(CopJumpInPlace)
{
		file("pc\actors\Chot\xxx\MJmpA.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,CopJumpSpeedLow,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);

		connections(CopJumpMedium,CopFallInplace);
}

action(CopJumpForward)
{
		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		//file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRforward);
		nrintframes(3);
		move(0,CopJumpSpeedLow,0);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpMedium,CopFallForward);
}

action(CopJumpL)
{
		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		trigger(_DIRsideleft);
		//rotate(-90)
		nrintframes(5);
		move(0,CopJumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpMediumL,CopFallL);
}

action(CopJumpFL)
{
		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		trigger(_DIRsideleft|_DIRforward);
		//rotate(-45)
		nrintframes(5);
		move(0,CopJumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpMedium45L,CopFallFL);
}
action(CopJumpR)
{
		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		trigger(_DIRsideright);
//		rotate(90)
		nrintframes(5);
		move(0,CopJumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpMediumR,CopFallR);
}

action(CopJumpFR)
{
		file("pc\actors\Chot\xxx\MRnJmpA.ske",100,off,100);
		trigger(_DIRsideright|_DIRforward);
		//rotate(45)
		nrintframes(5);
		move(0,CopJumpSpeedLow,0);
		//offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpMedium45R,CopFallFR);
}

action(CopJumpBackwards)
{
		file("pc\actors\Chot\xxx\MRBJmpA.ske",100,off,100);
		trigger(_DIRbackward);
		nrintframes(5);
		move(0,CopJumpSpeedLow,5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(CopJumpMediumB,CopFallBackwards);
}

action(CopJumpBR)
{
		file("pc\actors\Chot\xxx\MRBJmpA.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideright);
		nrintframes(5);
		move(0,CopJumpSpeedLow,0);
		break(off);
		gravity(off);
		//rotate(-45)
		ydeltafromzeroframe(off);
		connections(CopJumpMedium45L,CopFallBR);
}

action(CopJumpBL)
{
		file("pc\actors\Chot\xxx\MRBJmpA.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideleft);
		nrintframes(5);
		move(0,CopJumpSpeedLow,0);
		break(off);
		gravity(off);
		//rotate(45)
		ydeltafromzeroframe(off);
		connections(CopJumpMedium45R,CopFallBL);
}

action(CopfallForward)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);

		trigger(_AllDir);
		nrintframes(0);
		ydeltafromzeroframe(off);
		break(off);
		connections(CopfallForward);
}

action(CopfallFL)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		//rotate(-45)
		connections(CopfallFL);
}
action(CopfallFR)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);

		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		//rotate(45)
		connections(CopfallFR);
}
action(CopfallL)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);

		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		//rotate(-90)
		connections(CopfallL);
}
action(CopfallR)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\tjumph.ske",100,on,100,-1,_DIRhavegun);
		//file("pc\actors\Chot\xxx\tjumphng.ske",100,on);

		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		//rotate(90);
		connections(CopfallR);
}

action(CopfallInPlace)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
//		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJinPl4b.ske",100,off,100);
//		file("pc\actors\Chot\xxx\MJinPl4c.ske",100,on,100);
		trigger(_AllDir);
		AIClass(_AIClassCopSkeleton);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(CopfallInPlace);
}

action(CopfallBackwards)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(CopfallBackwards);
}
action(CopfallBL)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		//rotate(45)
		connections(CopfallBL);
}
action(CopfallBR)
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
		//file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		//rotate(-45)
		connections(CopfallBR);
}

action(Copfall)	//Fall when falling from edge only
{
		file("pc\actors\Chot\xxx\MJmpFall.ske",100,on);					//Male jump falling loop. 
//		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
		trigger(_AllDir);
		AIClass(_AIClassCopSkeleton);
		nrintframes(7);
		//offset(8);
		ydeltafromzeroframe(off);
		break(on);
		connections(CopFall);
}

action(CopTouchDown)
{
//		file("pc\actors\Chot\xxx\mjmp4mg.ske",30,on);	//this is when falling from higher places
//		file("pc\actors\Chot\xxx\mjmp4lg.ske",100,on);
		file("pc\actors\Chot\xxx\mjmp5lg.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassCopSkeleton);
		nrintframes(5);
		break(on);
		connections(CopSpreadOut,CopStandShoot,CopTouchDown,CopIdle);
}

/* *************   Other Moves ******************* */

//hold frame
action(CopStandShoot)
{
		trigger(_DIRshoot|_DIRHaveGun|_DIRcombatmode);
		break(on);
		nrintframes(-1);
		connections(CopCloseRange,CopGunButBob,CopGunButF,CopGunButB,CopBoxing,CopKickingBobF,CopKickingBobB,CopStandShootAnims);
}

action(CopStandShootAnims)
{
		file("pc\actors\chot\xxx\MShPmph.ske",100,on,100,_AIclassHipGun);
		//file("pc\actors\chot\xxx\mfrshtgh.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\chot\xxx\MShLtH.ske",100,on,100,_AIclasslightgun);
		file("pc\actors\chot\xxx\Mfire3h2.ske",100,on,100,-1);

		trigger(_DIRshoot|_DIRHaveGun|_DIRcombatmode);
		break(on);
		nrintframes(0);
		connections(CopSpreadOutGun,CopStandShoot,CopTurnLeftCombat,CopTurnRightCombat,CopIdle);
}



action(CopHitWallStandShoot)
{
		file("pc\actors\chot\xxx\Mfire3h2.ske",100,on);
		trigger(_DIRshoot|_DIRHaveGun|_DIRcombatmode);
		break(on);
		nrintframes(0);
		connections(CopHitWallSpreadOut);
}

action(CopHeavyRecoil)
{
		file("pc\actors\chot\xxx\MShPmp.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\chot\xxx\mfire3.ske",100,on,100,-1);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(4);
		//connections(CopSpreadOutGun,CopTurnLeftCombat,CopTurnRightCombat,CopHeavyRecoil,CopStandShoot,CopIdle);
		connections(CopSpreadOutGun,CopTurnLeftCombat,CopTurnRightCombat,CopHeavyRecoil,CopStandShoot,CopIdle);
}

action(CopLightRecoil)	//Works as proxy because it has to be restarted if SpawnAction is called again
{
		trigger(_AllDIR);
		nrintframes(-1);
		AIClass(_AIClassCopSkeleton);
		connections(CopLightRecoil2);
}
action(CopLightRecoil2)
{
		//file("pc\actors\chot\xxx\Mfire3s2.ske",100,off);
		//file("pc\actors\Chot\xxx\MShLtS.ske",100,on);
		file("pc\actors\Chot\xxx\MShLRmb1.ske",25,on);
		file("pc\actors\Chot\xxx\MShLRmb2.ske",50,on);
		file("pc\actors\Chot\xxx\MShLRmb3.ske",75,on);
		file("pc\actors\Chot\xxx\MShLRmb4.ske",100,on);

		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(0);
		connections(CopSpreadOutGun,CopLightRecoil2,CopStandShoot,CopTurnLeftCombat,CopTurnRightCombat,CopIdle);
}

action(CopPressGun)
{
//		file("pc\actors\Scientst\xxx\sci_idl4.ske",100,on,100,_AIclassscientist); //only the classscientist can operate console, operating console
		file("pc\actors\chot\xxx\MWrPshBt.ske",100,off,100,-1,_DIRcombatmode);//-1 means non-class specific, if in combat mode and you press action, use this anim
		file("pc\actors\chot\xxx\ATchButn.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(4);
		break(off);
		connections(CopIdle);
}

action(CopPickup)
{
		file("pc\actors\chot\xxx\Mpickupg.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(4);
		break(off);
		connections(CopIdle);
}

action(CopPickupChest)
{
		file("pc\actors\chot\xxx\MpickupF.ske",100,off,130);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(4);
		break(off);
		connections(CopIdle);
}

action(CopPickupCrouch)
{
		file("pc\actors\Chot\xxx\MCrPikUp.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(4);
		break(off);
		connections(CopCrouchIdle);
}



action(CopPossesed)
{
		file("pc\actors\chot\xxx\MPoss3A.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(4);//number of interpolation frames
		break(off);//unbreakable by any means
		soundlevel(0);
		connections(CopPossesed2);//with break(off) will not check connections until end of anim
}

action(CopPossesed2)
{
		file("pc\actors\Chot\xxx\MPoss3B.ske",100,on);//if number after 'on' (100,on,"100") this number will control animation speed in percent
		trigger(_DIRNotEndOfAnim);
		break(on);//AI can break out, with break(on) it checks connection
		soundlevel(0);
		connections(CopSpreadOut,CopStandShoot,CopPossesed2,CopIdle);
}


action(CopDepossesed)
{
		file("pc\actors\chot\xxx\Mstun1g.ske",50,on,100,-1,-1,Sub_ClrThrownFlag);//this anim occurs 50% of the time, smaller number occur first
		file("pc\actors\chot\xxx\Mstun2g.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);//the rest of the time
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		nrintframes(4);
		break(off);
		soundlevel(100);
		connections(CopIdle);
}

action(CopThrowGrenade)
{
		file("pc\actors\chot\xxx\MthrwgrA.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(4);
		connections(CopThrowGrenade2);
}

action(CopThrowGrenade2)
{
		file("pc\actors\chot\xxx\MthrwgrB.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(0);
		connections(CopSpreadOut,CopStandShoot,CopThrowGrenade2,CopIdle);
}

/* *************   Burned, steamed and blind ******************* */

action(CopGettingBurned)	//When inside fire, moving head left and right
{
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MBrnThrs.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(3);
		ydeltafromzeroframe(off);
		connections(CopBlindForward,CopBlindBackwards,CopGettingBurned);
}
action(CopBlindForward)		//Walk slowly forward both inside and outside fire
{
		file("pc\actors\Bob\xxx\BCrWkF.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MBrnStgr.ske",100,on);
		trigger(_DIRforward);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(3);
		connections(GENBlindForward,GENBlindBackwards,GENBurnedIdle);
}

action(CopBlindBackwards)		//Walk slowly backwards both inside and outside fire
{
		file("pc\actors\Bob\xxx\BCrWkBw.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MBrnStbk.ske",100,on);
		trigger(_DIRbackward);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(3);
		connections(GENBlindForward,GENBlindBackwards,GENBurnedIdle);
}

action(CopBurnedIdle)	//Inside and Outside fire, idle
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MBrnIdl.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(on);
		nrintframes(3);
		connections(GENBlindForward,GENBlindBackwards,GENBurnedIdle);
}

SubRoutine(Sub_SpawnSFXManFallToGroundOnBurnFall)
{
		if(VFrame==149)
		{
			sample(SFXManFallToGround,-1);
		}
}

action(CopBurningRunInCircle)		//Running around in circle with the head on fire, then fall.
{
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,on,100,_AIClassAngel);

//		file("pc\actors\bob\xxx\BRunBurn.ske",100,on,100,_AIclassangel);
		file("pc\actors\chot\xxx\MBrnRnAr.ske",100,on);

		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		ActionSubRoutine(Sub_SpawnSFXManFallToGroundOnBurnFall)
		connections(GENBurningRollOnFloor);
}

action(CopBurningRunInCircle)		//Running around in circle with the head on fire, then fall.
{
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);
		file("pc\actors\Bob\xxx\BDeath2.ske",100,off,100,_AIClassAngel);
//		file("pc\actors\bob\xxx\BRunBurn.ske",100,on,100,_AIclassangel);
		file("pc\actors\chot\xxx\MBrnRnAr.ske",100,on);

		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		ActionSubRoutine(Sub_SpawnSFXManFallToGroundOnBurnFall)
		connections(GENBurningRollOnFloor);
}



action(CopSlowGetUpFace)	//Get back up from the ground
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\Mstandf1.ske",100,on,100,-1,-1,Sub_GetUpClearThrown68);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(3);
		connections(CopBurnedIdle);
}


///////////////////////////
// ANIM FOR GAME INTRO  ///
///////////////////////////


Subroutine(CopDialogue)
{
	if(VFrame==1)
	{
		sample(SFXElectric5,-1);
	}
	if(VFrame>=1)
	{
		call(SetParticleSetID);
		if(vrnd<20)
		{
			vector(_set,Gactorpos,15,10,20);
			float(_rnd,TmpFloat,5);
			vector(_addx,Gactorpos,TmpFloat);
			float(_rnd,TmpFloat,5);
			vector(_addz,Gactorpos,TmpFloat);
			float(_rnd,TmpFloat,10);
			vector(_addy,Gactorpos,TmpFloat);
			spawnparticle(fx_sparks,4,gactorpos,Emptyvector,-1);
			spawnparticle(fx_impactsparks,4,gactorpos,Emptyvector,-1);
		}
	}
	if(VFrame==606)
	{
		CutScene("intro2");
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
	}
	elseif(VFrame==776)
	{
		float(_clr,AirLock,Help14);
	}
}

// COP #1 : going back up on his feet. Non possessed
action(CopIntroAnimCop)
{
		file("pc\actors\MultiAnm\xxx\IntroCop.ske",100,on);
		trigger(_allDIR);
		break(off);
		ActionSubRoutine(CopDialogue);
		nrintframes(8);
		connections(CopIdle);
}

// COP #2 : cop possessed by Bob
action(CopIntroAnimBob)
{
		file("pc\actors\MultiAnm\xxx\IntroBob.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(CopIdle);
}

action(TeleportAction)
{
		file("pc\actors\Chot\xxx\MTeleHld.ske",100,off);
		trigger(_allDIR);
		gravity(off);
		nrintframes(80);
		connections(TeleportAction);
}


/* *************   Crawling+Being Dragged+Other deaths ******************* */


action(CopDragged)
{
		file("pc\actors\chot\xxx\MDrgFH_A.ske",100,off);
		file("pc\actors\chot\xxx\MDrgFH_B.ske",100,on);
		trigger(_allDIR);
		nrintframes(3);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopDragged);
}
action(CopFallToCrawl)
{
		file("pc\actors\Bob\xxx\BShtDed1.ske",100,off,100,_AIClassAngel);
		//file("pc\actors\chot\xxx\MBrn2Kns.ske",100,off);
		file("pc\actors\chot\xxx\MBrkleg.ske",50,off,50);
		file("pc\actors\chot\xxx\MBrkleg2.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(CopCrawlIdle);
}

action(CopCrawlForward)
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MCrwl2.ske",100,on);
		trigger(_DIRforward);
		break(on);
		nrintframes(8);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(GENCrawlSpreadOut);
}
action(CopCrawlBackwards)
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRbackward);
		break(on);
		nrintframes(8);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(GENCrawlSpreadOut);
}
action(CopCrawlTurnLeft)
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRright);
		trigger(_DIRleft);
		break(on);
		nomove(on);
		nrintframes(8);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(GENCrawlSpreadOut);
}
action(CopCrawlTurnRight)
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRright);
		break(on);
		nomove(on);
		nrintframes(8);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(GENCrawlSpreadOut);
}


SubRoutine(Sub_Crawlcheck)
{
		if(Vstate==StateDead)
		{
			SpawnAction(GENCrawlDead);
		}
		elseif(Vstate!=StateCrawling)
		{
			SpawnAction(CopGetUpFromFrontFaceDown);
		}
}

action(CopCrawlIdle)
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MCrlidl3.ske",80,on);
		file("pc\actors\chot\xxx\MCrwlcl2.ske",100,on);
		trigger(_allDIR);
		break(on);
		ActionSubRoutine(Sub_Crawlcheck);
		nrintframes(8);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(GENCrawlSpreadOut);
}


action(CopCrawlDead)
{
		file("pc\actors\Bob\xxx\BShtDed1.ske",100,off,100,_AIClassAngel);
		file("pc\actors\Chot\xxx\mcrwlfal.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(12);
}

action(CopHeadBlownOffDead)
{
		file("pc\actors\Chot\xxx\MSnpHed.ske",100,off);	//head blown clean off (scale down at frame 1, blood till frame 75)
		trigger(_allDIR);
		break(off);
		nrintframes(12);
}

subroutine(Sub_CopStandDead)
{
		if(vframe==25&&VActionIndex==6)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==55&&VActionIndex==2)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==49&&VActionIndex==3)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==148&&VActionIndex==4)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==67&&VActionIndex==5)
		{
			sample(SFXManFallToGround,-1);
		}
		elseif(vframe==78&&VActionIndex==0)
		{
			sample(SFXManFallToGround,-1);
		}
}
action(CopStandDead)
{
		file("pc\actors\behemoth\xxx\bdeth1.ske",100,off,200,_AIclassAbeast);	//face down
		file("pc\actors\Bob\xxx\BShtDed1.ske",100,off,100,_AIClassAngel);

		file("pc\actors\Chot\xxx\mded1g.ske",20,off);	//Face down
		file("pc\actors\Chot\xxx\mded2g.ske",40,off);	//Face up
		file("pc\actors\Chot\xxx\mded3g.ske",60,off);	//Face up
		file("pc\actors\Chot\xxx\mded4g.ske",80,off);	//On side
		file("pc\actors\Chot\xxx\mded5g.ske",100,off);	//face down

//MISSING: This causes an error, because anim does not stop when it selects MDED1, 2, 3 or 4
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(12);

		ActionSubRoutine(Sub_CopStandDead);
}
action(CopFallDead)
{
		file("pc\actors\Bob\xxx\BShtDed1.ske",100,off,100,_AIClassAngel);
		file("pc\actors\Chot\xxx\alndhard.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(12);
}

action(CopStartDead)
{
		file("pc\actors\Chot\xxx\ALndHrdH.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(12);
}

action(CopStartDeadInMonitor)
{
		file("pc\actors\Chot\xxx\DedMon.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(12);
}


action(ChotEatPeople)
{
		file("pc\actors\Chot\xxx\MedWld2.ske",80,on);	
		file("pc\actors\Chot\xxx\MedWld3.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		//nomove(true);
		connections(MedicWorking);
}




action(CopDizzy)
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\Mstun2g.ske",50,on);
		file("pc\actors\chot\xxx\Mstun1g.ske",100,on);
	//	file("pc\actors\chot\xxx\DrnkStgr.ske",100,off);
		trigger(_allDIR);
		break(off);
		intforloop(on);
		nrintframes(8);
		connections(CopDizzy);
}


action(CopMessageFromGod)
{
		//file("pc\actors\chot\xxx\Mstun2g.ske",100,on);
		file("pc\actors\chot\xxx\MsgFGod.ske",100,off);
		file("pc\actors\chot\xxx\MsgFGodL.ske",100,on);
		trigger(_allDIR);
		break(off);
		intforloop(on);
		nrintframes(8);
		connections(CopMessageFromGod);
}


action(CopReload)		//Reloading weapon
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\Mneidl4p.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(4);
		intforloop(on);
		connections(CopIdle);
}

action(CopReloadCrouch)		//Reloading weapon
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MCrRelod.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(4);
		intforloop(on);
		connections(CopCrouchIdle);
}

SubRoutine(Sub_YankMyNoodle)
{
		if(VTrigger==_DIRjump)
		{
			move(0,40,0);
		}
}

action(CopPakWeaponDrift)		//drifting down with pak weapon
{
		file("pc\actors\Chot\xxx\ChCptrFl.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(10);
		intforloop(on);

		ActionSubRoutine(Sub_YankMyNoodle);

		connections(CopIdle);
}

/////////////////////////////////
///////		B E A S T	/////////
/////////////////////////////////

subroutine(Sub_beheseqFX)
{
		vector(_set,tmpvector2,9,9,9);
		float(_rnd,tmpfloat,4096);
		vector(_vectorfromangle,tmpvector,tmpfloat,16);
		vector(_copy,tmpvector3,tmpvector);
		vector(_normalize,tmpvector);
		vector(_mul,tmpvector,tmpvector2);
		SpawnParticle(fx_shockwave,18,tmpvector3,tmpvector,fx_heavyland);
		SpawnParticle(fx_shockwave,22,tmpvector3,tmpvector,fx_heavyland);
}

SubRoutine(Sub_BeheSequence)
{
	if(vframe<=1)					
	{
		state(_or,StateThrown);
	}
	if(vframe==13)
	{
		sample(SFXBehemothChest,-1);
		sample(SFXBehemothScream,-1);
		//beating chest and roar sample
	}
	if(vframe==190)
	{
		sample(SFXBehemothAngry,-1);
		//behemoth takes damage
	}
	if(vframe>190 && vframe<221)
	{
		call(SetParticleSetID);
		vector(_set,Gactorine,0,-4,0);
		spawnparticle(fx_steam,18,emptyvector,gactorine,fx_doorsteam);
		spawnparticle(fx_steam,22,emptyvector,gactorine,fx_doorsteam);

	}
		//behemoth slides back. smoke required
	if(vframe==282)
	{
		CutScene("fourth");
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
	}
	if(vframe==316)
	{
		sample(SFXBehemothLeaps,-1);
	}
	if(vframe>=316 && vframe<=332)
	{
		call(SetParticleSetID);

		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);
		callsub(Sub_beheseqFX);

		//behemoth jumps
	}
	if(vframe>=341&&vframe<=350)
	{
		if(vframe==341)
		{
			call(ScreenShake,0,24,0,0.5);
			sample(SFXBehemothLandSpecial,-1);
		}

		if(vframe==342||vframe==346||vframe==350)
		{
			vector(_set,fxvector,0,-200,0);
			call(SetParticleSetID);
			callsub(sub_shockwave,BulletShockWave,0);
		}

		//behemoth lands
	}
	if(vframe==365)
	{
		CutScene("fifth");
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
		sample(SFXCreepy02,-1);
	}
	elseif(vframe==417)
	{
		sample(SFXBehemothScream,-1);
		sample(SFXBehemothAngerScream,-1);
		//tackles the priest
	}
	elseif(vframe==480)
	{
		CutScene("sixth");
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTnosmooth);
		call(ChangeCutScene,_SXCUTflag,_or,_SXCUTdontreset);
	}
	elseif(vframe==700)
	{
		sample(SFXSatanByMyWill,-1);
	}
	elseif(vframe==960)
	{
		sample(SFXManNeckSnap02,-1)
		//neck snap
	}
	elseif(vframe==1045)
	{
		call(ScreenShake,0,24,0,0.5);
		sample(SFXManFallToGround,-1);
	}
	elseif(vframe==1088)
	{
		state(_clr,StateThrown);
		direction(_clr,_DIRalive);
		callsub(Sub_Deposses);
		State(_or,StateDead);
	}
}

action(BeastAttackSequence)
{
		file("pc\actors\MultiAnm\xxx\PrstBosB.ske",100,on);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(12);
		ActionSubRoutine(Sub_BeheSequence);
		connections(BeastAttackSequenceH);
}

action(BeastAttackSequenceH)
{
		file("pc\actors\MultiAnm\xxx\PrstBsBH.ske",100,on);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		ActionSubRoutine(Sub_BeheSequence);
		connections(BeastAttackSequenceH);
}

/////////////////////////////////////
///////		D J  -  K Y D	/////////
/////////////////////////////////////
action(DJPuke)
{
		file("pc\actors\DJ\xxx\Dj_booo.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);	
}

action(DJChillyChill1)
{
		file("pc\actors\DJ\xxx\Dj_idle.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);	
}

action(DJChillyChill2)
{
		file("pc\actors\DJ\xxx\Dj_sign1.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);	
}

action(DJChillyChill3)
{
		file("pc\actors\DJ\xxx\Dj_sign2.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);	
}

action(DJSpinRekids)
{
		file("pc\actors\DJ\xxx\Dj_spin.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);	
}

/////////////////////////////////////
///////		D W E L L E R	/////////
/////////////////////////////////////

//Dweller Nervous. Caught sneaking up Reation:
action(DwellerCaughtSneakingUp)
{
		file("pc\actors\Dwellr1\xxx\DwNervs.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);
		connections(GenIdle);
}
	
action(DwellerBarIdle1)
{
		file("pc\actors\Chot\xxx\MKkIdl01.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);
}


action(Dweller1Sitting)
{
	file("pc\actors\Chot\xxx\MDrnkSt1.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);

	connections(Dweller1Sitting);
}

action(DwellerBarIdle2)
{
		file("pc\actors\Chot\xxx\MKkIdl02.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);
}

action(Dweller2Sitting)
{
	file("pc\actors\Chot\xxx\MDrnkSt2.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);

	connections(Dweller2Sitting);
}

action(DwellerBarIdle3)
{
		file("pc\actors\Chot\xxx\MKkIdl03.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);
}

action(Dweller3Sitting)
{
	file("pc\actors\Chot\xxx\MDrnkSt3.ske",100,on);
	trigger(_allDIR);
	break(off);
	nrintframes(12);
	intforloop(on);

	connections(Dweller3Sitting);
}


action(DwellerBarIdle4)
{
		file("pc\actors\Chot\xxx\MKkIdl04.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);

		connections(GenIdle);
}

action(ManDance)
{
	file("pc\actors\Chot\xxx\M_dance1.ske",25,on);
	file("pc\actors\Chot\xxx\M_dance2.ske",50,on);
	file("pc\actors\Chot\xxx\M_dance3.ske",75,on);
	file("pc\actors\Chot\xxx\M_dance4.ske",100,on);
	
	break(off);
	trigger(_allDIR);
	nrintframes(4);
	intforloop(on);

	connections(GenIdle);
}


/////////////////////////////////////
///////		B A R M A N		/////////
/////////////////////////////////////

action(BarmanStaggers)		
{
		file("pc\actors\barman\xxx\BMEvlBob.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);
		connections(CopRun);
}



action(CopReactionToAttack)
{
		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off,100,_AIclassAngel);
		file("pc\actors\Chot\xxx\Mshockd1.ske",50,off);
		file("pc\actors\Chot\xxx\Mshockd2.ske",100,off);
//		file("pc\actors\Chot\xxx\Mshockd3.ske",100,off);
		trigger(_allDIR);
		//AIClass(_AIClassCopSkeleton);
		break(off);
		nrintframes(0);
		connections(GenIdle);
}


action(VictimIdle)
{

		file("pc\actors\Dwellr1\xxx\DwMidl1.ske",100,on);		//Breathing

		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(VictimIdle);
}




// ######################################################################################
// ######################################################################################
// Priest Boss Actions for priest boss sequence


Action(PriestIdle)
{
		file("pc\actors\priest\xxx\PsIdle1.ske",100,on);	//floating idles
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);

		AIClass(_AIclasspriest);
		connections(PriestAttack,PriestIdle);
//		connections(PriestAttack,PriestRunDiagFL,PriestRunDiagFR,PriestRunDiagBL,PriestRunDiagBR,Priestrun,PriestRunBack,PriestRunL,PriestRunR,PriestIdle);
}

Action(PriestPrayingIdle)
{
		file("pc\actors\priest\xxx\PsIdle2.ske",100,on);	//floating idles
		trigger(_allDIR);
		break(on);
		nrintframes(10);
		intforloop(on);
		collision(off);
		gravity(off);
		AIClass(_AIclasspriest);
		connections(PriestPrayingIdle);
}

Action(PriestAttackSequence)
{
		file("pc\actors\MultiAnm\xxx\PrstBosP.ske",100,on);	//floating idles
		trigger(_allDIR);
		break(off);
		collision(off);
		gravity(off);
		shadow(off);
		nrintframes(8);
		connections(PriestAttackSequenceH);
}


Action(PriestAttackSequenceH)
{
		file("pc\actors\MultiAnm\xxx\PrstBsPh.ske",100,on);	//floating idles
		trigger(_allDIR);
		break(off);
		collision(off);
		gravity(off);
		nrintframes(0);
		connections(PriestAttackSequenceH);
}

Action(PriestAttack)
{
		file("pc\actors\priest\xxx\PsHeven.ske",100,on);	//floating idles
//		file("pc\actors\priest\xxx\PsAttk.ske",100,on);	//floating idles
		trigger(_DIRshoot);
		break(off);
		nrintframes(8);

		connections(PriestIdle);
}



Action(Priestrun)
{
		file("pc\actors\priest\xxx\PsFlyF.ske",100,on);	//floating idles
		break(on);
		nrintframes(4);
		offset(2);
		move(0,0,-4);
		offset(9);

		trigger(_DIRforward);

		connections(Priestidle);
}

action(PriestRunBack)
{
		file("pc\actors\priest\xxx\PsFlyB.ske",100,on);	//floating idles
		offset(9);
		nrintframes(4);
		trigger(_DIRbackward);
		break(on);
		move(0,0,4);
		connections(Priestidle);
}

action(PriestRunL)
{
		file("pc\actors\domina\xxx\DmRnLNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunL.ske",100,on);
		offset(9);
		nrintframes(8);
		trigger(_DIRsideleft);
		move(4,0,0);
		break(on);
		connections(Priestidle);
}
action(PriestRunR)
{
		file("pc\actors\domina\xxx\DmRnRNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunR.ske",100,on);
		offset(9);
		nrintframes(8);
		trigger(_DIRsideright);
		move(-4,0,0);
		break(on);
		connections(Priestidle);
}

action(PriestRunDiagFL)
{
		file("pc\actors\domina\xxx\DmRnFLNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunFL.ske",100,on);
		offset(9);
		trigger(_DIRsideleft|_DIRforward);
		move(2,0,-2);
		break(on);
		nrintframes(8);
		connections(Priestidle);
}
action(PriestRunDiagFR)
{
		file("pc\actors\domina\xxx\DmRnFRNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunFR.ske",100,on);
		offset(9);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		move(-2,0,-2);
		nrintframes(8);
		connections(Priestidle);
}

action(PriestRunDiagBL)
{
		file("pc\actors\domina\xxx\DmRnBLNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunBL.ske",100,on);
		offset(9);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		move(2,0,2);
		nrintframes(4);
		connections(Priestidle);
}

action(PriestRunDiagBR)
{
		file("pc\actors\domina\xxx\DmRnBRNC.ske",100,on,100,_AIClassCop);
		file("pc\actors\Prost1\xxx\PRunBR.ske",100,on);
		offset(9);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		move(-2,0,2);
		nrintframes(4);
		connections(Priestidle);
}
