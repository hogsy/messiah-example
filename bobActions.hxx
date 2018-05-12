//Bob turning
#define BobMaxTurnSpeed		72
#define BobMaxTurnSpeedAir	48

//Bob movespeed while in air
#define BobMaxRunSpeedFwdAir		-15
#define BobMaxRunSpeedBwdAir		10
#define BobMaxRunSpeedSideAir		12
#define BobMaxRunSpeedSideAirNeg	-12

#define BobMaxWalkSpeedFwdAir		-5
#define BobMaxWalkSpeedBwdAir		3
#define BobMaxWalkSpeedSideAir		4
#define BobMaxWalkSpeedSideAirNeg	-4

#define BobAccAir					2.0
#define BobDccAir					0.8
#define BobAccAirSide				1.5
#define BobDccAirBackFlip			0.95	//Friction

#define	BobHangMoveIn				-10

//Bob movespeed while on ground
#define BobMaxRunSpeedFwd			-12
#define BobNegMaxRunSpeedFwd		12
#define	BobDiagRunSpeed				8.4852
#define	BobNegDiagRunSpeed			-8.4852

#define BobMaxRunSpeedBwd			8		//9
#define BobDiagRunSpeedBwd			5.6568	//6.3639
#define BobNegDiagRunSpeedBwd		-5.6568	//-6.3639


#define	BobSideWalkSpeed			4
#define	BobDiagWalkSpeed			2.828
#define	BobNegSideWalkSpeed			-4
#define	BobNegDiagWalkSpeed			-2.828

//Bob Jumping and falling
#define BobMinHoldJumpAction		3
#define BobFlapPressThreshold		15

#define BobMaxFall					-1000	//Fall before he breaks his legs.
#define	DamageBobFall				500		//Maximum, depends on altitude you fall




action(BobBumpedGeneric)
{
		file("pc\actors\Bob\xxx\BShtStl1.ske",100,off,100);	// for dwarf chot
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassBobSkeleton);
		break(off);
		collision(on);
		nrintframes(2);
		connections(GenIdle);
}




SubRoutine(Sub_ForceExecuteAnim)
{
		state(_or,StateExecuteAnim);
}



Action(BobClimbAnims)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(BobClimbHang,BobClimbUp,BobShimmyLeft,BobShimmyLeft2,BobShimmyRight,BobShimmyRight2);
}



//		file("pc\actors\bob\xxx\brun90LS.ske",100,on,100);	//Possibility,Repeat[,Speed]
//		nrintframes(4);				//Interpolation frames
//		intforloop(Default=off);	//Interpolate for looping animation
//		break(Default=off);			//Break animation
//		Gravity(Default=on);
//		Ydeltafromzeroframe(default=on)	//Off=use y-pos from rootbone, not from ground (use for jumping and when anim is broken)


//	DRAGGING ACTIONS
//


action(DragByFeetStomachLink)
{
		file("pc\actors\MultiAnm\xxx\BDMBBStM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFBBStM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMBBStM.ske",100,off);
		break(off);
		connections(DragByFeetStomachLoop);
}

action(DragByFeetStomachLoop)
{
		file("pc\actors\MultiAnm\xxx\BDMBBLpM.ske",100,on,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFBBLpM.ske",100,on,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMBBLpM.ske",100,on);
		trigger(_DIRactionhold);
		break(on);
		connections(DragByFeetStomachLoop,DragByFeetStomachStop);
}

action(DragByFeetStomachStop)
{
		file("pc\actors\MultiAnm\xxx\BDMBBEnM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFBBEnM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMBBEnM.ske",100,off);
		break(off);
		connections(DragByFeetStomachStop);
}


action(DragByFeetLink)
{
		file("pc\actors\MultiAnm\xxx\BDMBFStM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFBFStM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMBFStM.ske",100,off);
		break(off);
		connections(DragByFeetLoop);
}

action(DragByFeetLoop)
{
		file("pc\actors\MultiAnm\xxx\BDMBFLpM.ske",100,on,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFBFLpM.ske",100,on,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMBFLpM.ske",100,on);
		trigger(_DIRactionhold);
		break(on);
		connections(DragByFeetLoop,DragByFeetStop);
}

action(DragByFeetStop)
{
		file("pc\actors\MultiAnm\xxx\BDMBFEnM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFBFEnM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMBFEnM.ske",100,off);
		break(off);
		connections(DragByFeetStop);
}

action(DragByHeadLink)
{
		file("pc\actors\MultiAnm\xxx\BDMHStrM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFHStrM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMHStrM.ske",100,off);
		break(off);
		connections(DragByHeadLoop);
}

action(DragByHeadLoop)
{
		file("pc\actors\MultiAnm\xxx\BDMHWkBM.ske",100,on,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFHWkBM.ske",100,on,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMHWkBM.ske",100,on);
		trigger(_DIRactionhold);
		break(on);
		connections(DragByHeadLoop,DragByHeadStop);
}

action(DragByHeadStop)
{
		file("pc\actors\MultiAnm\xxx\BDMHEndM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFHEndM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMHEndM.ske",100,off);
		break(off);
		connections(DragByHeadStop);
}

action(DragByHeadStomachLink)
{
		file("pc\actors\MultiAnm\xxx\BDMHFStM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFHFStM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMHFStM.ske",100,off);
		break(off);
		connections(DragByHeadStomachLoop);
}

action(DragByHeadStomachLoop)
{
		file("pc\actors\MultiAnm\xxx\BDMHFLpM.ske",100,on,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFHFLpM.ske",100,on,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMHFLpM.ske",100,on);
		trigger(_DIRactionhold);
		break(on);
		connections(DragByHeadStomachLoop,DragByHeadStomachStop);
}

action(DragByHeadStomachStop)
{
		file("pc\actors\MultiAnm\xxx\BDMHFEnM.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\BDFHFEnM.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\BDMHFEnM.ske",100,off);
		break(off);
		connections(DragByHeadStomachStop);
}

Action(BobDragFeet)
{
		file("pc\actors\MultiAnm\xxx\BDMHStrB.ske",100,off,100);

		flag(_SXAAonlydeadpeople|_SXAAalignmovingslave|_SXAAdisablecollision);

		//AlignXYZ(-2.605,-89.0424,0);
		AlignXYZ(-2.605,0,89.0424);

		TargetAngle(0);
		AttackHeight(40);
		DistanceSlack(150);
		AlignSlack(180);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		AttachAction(DragByFeetLink);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobDragHeadLoop);
}

Action(BobDragFeetStomach)
{
		file("pc\actors\MultiAnm\xxx\BDMHStrB.ske",100,off,100);

		flag(_SXAAonlydeadpeople|_SXAAalignmovingslave|_SXAAdisablecollision);

		//AlignXYZ(-2.605,-89.0424,0);
		AlignXYZ(-2.605,0,89.0424);

		TargetAngle(0);
		AttackHeight(40);
		DistanceSlack(150);
		AlignSlack(180);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		AttachAction(DragByFeetStomachLink);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobDragHeadLoop);
}

Action(BobDragHead)
{
		file("pc\actors\MultiAnm\xxx\BDMHStrB.ske",100,off,100);

		flag(_SXAAalignmovingslave|_SXAAonlydeadpeople|_SXAAdisablecollision);

		//AlignXYZ(-2.605,-89.0424,0);
		AlignXYZ(-2.605,0,89.0424);

		TargetAngle(0);
		AttackHeight(40);
		DistanceSlack(150);
		AlignSlack(180);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		AttachAction(DragByHeadLink);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobDragHeadLoop);
}

Action(BobDragHeadStomach)
{
		file("pc\actors\MultiAnm\xxx\BDMHStrB.ske",100,off,100);

		flag(_SXAAonlydeadpeople|_SXAAalignmovingslave|_SXAAdisablecollision);

		//AlignXYZ(-2.605,-89.0424,0);
		AlignXYZ(-2.605,0,89.0424);

		TargetAngle(0);
		AttackHeight(40);
		DistanceSlack(150);
		AlignSlack(180);	

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		AttachAction(DragByHeadStomachLink);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobDragHeadLoop);
}

Action(BobStomachRollLeft)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off);

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		AttachActionStartAtFrame(14);
		AttachAction(GENStomachRollLeft);

		ActionSubRoutine(Sub_BobRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobIdle);
}

Action(BobStomachRollRight)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off);

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		AttachActionStartAtFrame(14);
		AttachAction(GENStomachRollRight);

		ActionSubRoutine(Sub_BobRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobIdle);
}

Action(BobBackRollRight)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off);

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		ActionSubRoutine(Sub_BobRollSFX);

		AttachActionStartAtFrame(14);
		AttachAction(GENBackRollRight);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobIdle);
}

Action(BobBackRollLeft)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off);

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		AttachActionStartAtFrame(14);
		AttachAction(GENBackRollLeft);

		ActionSubRoutine(Sub_BobRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(BobIdle);
}

Action(BobDragHeadLoop)
{
		file("pc\actors\MultiAnm\xxx\BDMHWkBB.ske",100,on);
		trigger(_DIRactionhold);
		break(on);
		nrintframes(0);
		connections(BobDragHeadLoop,BobIdle);
}


//	DRAGGING END


Action(BobTeleportAction)
{
		file("pc\actors\Bob\xxx\BTeleHld.ske",100,off);		//teleportation
		trigger(_allDIR);
		break(off);
		gravity(off);
		nomove(true);
		nrintframes(70);
		connections(BobTeleportAction);
}

Action(BobDrown)
{
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,on);		//drowning
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		nomove(true);
		gravity(off);
		collision(off);
		nrintframes(3);
		connections(BobDrown);
}


//	other anims
//

Action(BobTaunt)
{
		file("pc\actors\Bob\xxx\BTaunt1.ske",100,on);

		trigger(_allDIR);
		nrintframes(5);
		intforloop(off);
		break(off);
		connections(bobidle);
}

action(BobBangHead)
{
		//file("pc\actors\Bob\xxx\bhithed1.ske",50,off);
		//file("pc\actors\Bob\xxx\bhithed2.ske",100,off);
		file("pc\actors\Bob\xxx\BHBoink1.ske",50,off);
		file("pc\actors\Bob\xxx\BHBoink2.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(BobIdle);
}

action(BobConsole)
{
//		file("pc\actors\Bob\xxx\Bkbdsl1.ske",50,off);
//		file("pc\actors\Bob\xxx\Bkbdsl2.ske",100,off);
//		file("pc\actors\Bob\xxx\Bkbdsl3.ske",100,off);
		file("pc\actors\Bob\xxx\Bkbdsl4.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		nrintframes(6);
		connections(GenIdle);
}

action(BobElectricShock0)
{
		file("pc\actors\bob\xxx\BElectro.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true);
		connections(GENElectricShock1);
		collision(on);
		gravity(off);
}

action(BobElectricShock1)
{
		file("pc\actors\bob\xxx\BElectro.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		//nomove(true);
		break(off);
		gravity(off);
		connections(GENElectricShock1);
}

Action(BobRunJumpPosses)
{
	file("pc\actors\Bob\xxx\BJmpBPos.ske",100,on,100);
	trigger(_AllDIR);
	nrintframes(3);
	gravity(off);
	ydeltafromzeroframe(off);
	break(off);
	connections(bobidle);
}

Action(BobJumpPosses)
{
	file("pc\actors\Bob\xxx\BJmpBPs2.ske",100,on,100);
	trigger(_AllDIR);
	nrintframes(3);
	gravity(off);
	ydeltafromzeroframe(off);
	break(off);
	connections(bobidle);
}


Action(bobshoot)
{
//		file("pc\actors\Bob\xxx\bshtfing.ske",100,on,140);
		AIClass(_AIclassMale|_AIclassSpecial);

		trigger(_DIRshoot);
		nrintframes(-1);
		connections(bobshoot2);
}


Action(bobshoot2)
{
		file("pc\actors\Bob\xxx\bshtfing.ske",100,on,140);

		trigger(_DIRNotEndOfAnim);
		nrintframes(5);
		//nomove(true);
		intforloop(off);
		break(on);
		connections(BobSpreadOut,bobshoot2,bobidle);
}


//			THROWN ANIMATIONS
//
action(BobThrownBack)
{
		file("pc\actors\Bob\xxx\BthrnbkA.ske",100,off);	//Backwards hold frame
		trigger(_alldir);
		AIClass(_AIClassBobSkeleton);
 		break(on);
		collision(on);
		nrintframes(4);

		ActionSubRoutine(Sub_RandomKickedSFX);

		connections(BobThrownBackLand);
}

action(BobThrownBackHit)
{
		file("pc\actors\Bob\xxx\BthrnbkA.ske",100,off);	//Backwards hold frame
		trigger(_alldir);
		break(off);
		AIClass(_AIClassBobSkeleton);
		move(0,0,5);
		collision(on);
		nrintframes(4);
		connections(BobThrownBackLand);
}

action(BobDieOnBack)
{
		file("pc\actors\Bob\xxx\BthrnbkD.ske",100,off);	//Backwards, land on back
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
		connections(BobDieOnBack);
}

action(BobDieOnFace)
{
		file("pc\actors\Bob\xxx\BDeath2.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
		connections(BobDieOnBack);
}


action(BobThrownBackLand)
{
		file("pc\actors\Bob\xxx\BthrnbkB.ske",100,off,120);	//Backwards, land on back
		//file("pc\actors\Bob\xxx\BthrbkB2.ske",100,off);	//Backwards, land on back
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
		connections(BobGetUpFromBack,BobDieOnBack);
}



action(BobThrownForward)
{
		file("pc\actors\Bob\xxx\BthrnFwA.ske",100,off);	//Forward hold frame
		trigger(_alldir);
		AIClass(_AIClassBobSkeleton);
		break(on);
		collision(on);
		nrintframes(4);
		connections(BobThrownForwardLand);
}

action(BobThrownForwardLand)
{
		file("pc\actors\Bob\xxx\BthrnFwB.ske",100,off,120);		//forward, land face down (gabe)
		AIClass(_AIClassBobSkeleton);
		trigger(_allDIR);
		break(off);
		collision(on);
		nrintframes(4);
		connections(BobGetUpFromFrontFaceDown,BobDieOnFace,BobThrownForwardLand);
}

action(BobThrownForwardLandAttached)
{
		file("pc\actors\Bob\xxx\BthrnFwB.ske",100,off,120);		//forward, land face down, and get up (gabe)
		AIClass(_AIClassBobSkeleton);
		trigger(_allDIR);
		break(off);
		collision(on);
		nrintframes(4);
		move(0,0,-5);
		ActionSubRoutine(Sub_RandomKickedSFX);
		connections(BobGetUpFromFrontFaceDown,BobThrownForwardLandAttached);
}

action(BobGetUpFromBack)
{
		file("pc\actors\bob\xxx\BthrnbkC.ske",100,off,120,-1,-1,Sub_GetUpClearThrown15);

		//file("pc\actors\bob\xxx\bStndUBF.ske",50,off);
		//file("pc\actors\bob\xxx\bStnupB2.ske",100,off);
		AIClass(_AIClassBobSkeleton);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(4);
		connections(BobIdle);
}

action(BobGetUpFromFrontFaceDown)
{
		file("pc\actors\Bob\xxx\bStrl2.ske",100,off,120,-1,-1,Sub_GetUpClearThrown35);
		trigger(_DIRalive);
		AIClass(_AIClassBobSkeleton);
		break(off);
		collision(on);
		nrintframes(0);
		move(0,0,-2);
		connections(GenIdle);
}



//**************** Idle + variations
Action(bobidle)
{
		//file("pc\actors\Bob\xxx\byawn.ske",10,on);

		//file("pc\actors\Bob\xxx\BTaunt1.ske",2,on);
		file("pc\actors\Bob\xxx\bidle1g.xxx",25,on,80);			//look side to side
		file("pc\actors\Bob\xxx\bobnidl2.ske",80,on);
		file("pc\actors\Bob\xxx\bobnidl1.ske",100,on);

//		file("pc\actors\Bob\xxx\bidle0g.xxx",66,on);
//		file("pc\actors\Bob\xxx\bidl0n.ske",100,on);
		//file("pc\actors\Bob\xxx\BBrnIdle.ske",100,on);		//burn idle test
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(5);
		//nomove(true);
		intforloop(on);
		break(on);
		connections(EvilBobAttack,DwarfClawAttack,bobshoot,BobSpreadOut,BobTurnLeft,BobTurnRight,bobidle);
}
action(BobSpreadOut)	//Lead directly to next animation
{
		trigger(_DIRMove);
		AIClass(_AIClassBobSkeleton);
		nrintframes(-1);
		connections(EvilBobAttack,DwarfClawAttack,bobshoot,BobSlowDiagBL,BobSlowDiagBR,BobSlowDiagFL,BobSlowDiagFR,BobslowR,BobslowL,BobWalkBack,bobwalk,BobFastDiagBL,BobFastDiagBR,BobFastDiagFL,BobFastDiagFR,BobFastR,BobFastL,bobrun,bobrunback);
		//connections(BobSlowDiagBL,BobSlowDiagBR,BobFastDiagBL,BobFastDiagBR,BobSlowDiagFL,BobSlowDiagFR,BobFastDiagFL,BobFastDiagFR,BobslowR,BobFastR,BobslowL,BobFastL,bobrun,bobrunback,BobWalkBack,bobwalk);
}

action(BobIdleLongTime)
{
//MISSING: Extra idle funny animations
		file("pc\actors\Bob\xxx\byawn.ske",33,on);
		file("pc\actors\Bob\xxx\bcel2.xxx",100,on);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassBobSkeleton);
		nrintframes(5);
		intforloop(on);
		break(on);
		connections(BobSpreadOut,BobTurnLeft,BobTurnRight,BobIdleLongTime,BobIdle);
}

action(BobDanceCool)
{
		file("pc\actors\Bob\xxx\bcel2.xxx",100,on);
		trigger(_DIRNotEndOfAnim);
		nrintframes(5);
		intforloop(on);
		break(on);
		connections(BobDanceCool,BobIdle);
}

Action(bobidleHitWall)			//After hitting into wall
{
//		file("pc\actors\Bob\xxx\bidle1g.xxx",33,on);
//		file("pc\actors\Bob\xxx\bidle0g.xxx",66,on);
//		file("pc\actors\Bob\xxx\bidl0n.ske",100,on);

		file("pc\actors\Bob\xxx\bidle1g.xxx",25,on,80);			//look side to side
		file("pc\actors\Bob\xxx\bobnidl2.ske",80,on);
		file("pc\actors\Bob\xxx\bobnidl1.ske",100,on);

		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(5);
		intforloop(on);
		nomove(true);
		break(on);
		connections(BobHitWallSpreadOut);
}

action(BobHitWallSpreadOut)	//Lead directly to next animation
{
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(-1);
		connections(BobHitWallTurnLeft,BobHitWallTurnRight,BobIdleHitWall);
}

Action(bobidleHitWallFront)	//Hitting wall face first, special animation.
{
//MISSING Animation (right now he just mainly looks over his shoulders
//		file("pc\actors\Bob\xxx\bidle1g.xxx",33,on);
//		file("pc\actors\Bob\xxx\bidle0g.xxx",66,on);
		file("pc\actors\Bob\xxx\bidl0n.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(5);
		intforloop(on);
		nomove(true);
		break(on);
		connections(BobHitWallTurnLeft,BobHitWallTurnRight,bobidleHitWallFront);
}


Action(BobTurnLeft)
{
		file("pc\actors\Bob\xxx\btrnlft.ske",100,on);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(BobSpreadOut,BobTurnLeft,BobTurnRight,BobIdle);
}

Action(BobTurnRight)
{
		file("pc\actors\Bob\xxx\Btrnrt.ske",100,on);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(BobSpreadOut,BobTurnLeft,BobTurnRight,BobIdle);
}

Action(BobHitWallTurnLeft)
{
		file("pc\actors\Bob\xxx\btrnlft.ske",100,on);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(BobHitWallSpreadOut);
}

Action(BobHitWallTurnRight)
{
		file("pc\actors\Bob\xxx\Btrnrt.ske",100,on);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(BobHitWallSpreadOut);
}




/* *************   Standard moves ******************* */
Action(bobrun)
{
		//file("pc\actors\bob\xxx\brunNoFr.ske",100,on,100);
		//file("pc\actors\Bob\xxx\BNuRunF2.ske",100,on);
		//file("pc\actors\Bob\xxx\BNuRunF3.ske",100,on);
		file("pc\actors\Bob\xxx\BNuRn4F.ske",100,on);
		nrintframes(4);
		trigger(_DIRforward);
		break(on);
		//offset(1);
		offset(11);
		move(0,0,BobMaxRunSpeedFwd);
		soundlevel(100);
		//connections(BobSpreadOut,BobIdle);
		connections(BobSpreadOut,BobTouchDown);		//touchdown used as a placeholder for end of run anim
}

Action(bobfastR)
{
		//file("pc\actors\bob\xxx\brunNoFr.ske",100,on,100);
		file("pc\actors\bob\xxx\BNuRn4R.ske",100,on,100);
		//rotate(90)
		nrintframes(4);
		move(BobMaxRunSpeedFwd,0,0);
		//move(0,0,BobMaxRunSpeedFwd);
		trigger(_DIRsideright);
		break(on);
		//offset(1);
		offset(11);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}

Action(bobfastL)
{
		//file("pc\actors\bob\xxx\brunNoFr.ske",100,on,100);
		file("pc\actors\bob\xxx\BNuRn4L.ske",100,on,100);
		//rotate(-90)
		nrintframes(4);
		//move(0,0,BobMaxRunSpeedFwd);
		move(BobNegMaxRunSpeedFwd,0,0);
		trigger(_DIRsideleft);
		break(on);
		//offset(1);
		offset(11);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}

Action(bobfastDiagFL)
{
		//file("pc\actors\bob\xxx\brunNoFr.ske",100,on,100);
		file("pc\actors\bob\xxx\BNuRn4FL.ske",100,on,100);
		//rotate(-45)
		nrintframes(4);
		move(BobDiagRunSpeed,0,BobNegDiagRunSpeed);
		//move(0,0,BobMaxRunSpeedFwd);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		//offset(1);
		offset(11);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}

Action(bobfastDiagFR)
{
		//file("pc\actors\bob\xxx\brunNoFr.ske",100,on,100);
		file("pc\actors\bob\xxx\BNuRn4FR.ske",100,on,100);
		//rotate(45)
		nrintframes(4);
		//move(0,0,BobMaxRunSpeedFwd);
		move(BobNegDiagRunSpeed,0,BobNegDiagRunSpeed);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		//offset(1);
		offset(11);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}
     
Action(bobrunback)
{
		//file("pc\actors\bob\xxx\BRnBNoMv.ske",100,on,125);
		file("pc\actors\bob\xxx\BNuRn4B.ske",100,on,125);
		nrintframes(4);
		break(on);
		//offset(1);
		offset(10);
		trigger(_DIRbackward);
		move(0,0,BobMaxRunSpeedBwd);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}

Action(bobfastDiagBL)
{
//		file("pc\actors\bob\xxx\BRnBNoMv.ske",100,on,125);
		file("pc\actors\bob\xxx\BNuRn4BL.ske",100,on,125);
//		rotate(45);
		nrintframes(4);
		//move(0,0,BobMaxRunSpeedBwd);
		move(BobDiagRunSpeedBwd,0,BobDiagRunSpeedBwd);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		//offset(1);
		offset(10);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}

Action(bobfastDiagBR)
{
		//file("pc\actors\bob\xxx\BRnBNoMv.ske",100,on,125);
		file("pc\actors\bob\xxx\BNuRn4BR.ske",100,on,125);
		//rotate(-45);
		nrintframes(4);
		//move(0,0,BobMaxRunSpeedBwd);
		move(BobNegDiagRunSpeedBwd,0,BobDiagRunSpeedBwd);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		//offset(1);
		offset(10);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}

Action(bobwalk)
{
		file("pc\actors\Bob\xxx\Bwkcyc1p.xxx",100,on,150);
		nrintframes(4);
		break(on);
		offset(1);
		trigger(_DIRforward|_DIRwalking);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}

Action(bobslowR)
{
		file("pc\actors\Bob\xxx\Bwkcyc1p.xxx",100,on,150);
		rotate(90);
		nrintframes(4);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(1);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}

Action(bobslowL)
{
		file("pc\actors\Bob\xxx\Bwkcyc1p.xxx",100,on,150);
		rotate(-90);
		nrintframes(4);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(1);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}

Action(bobslowDiagFL)
{
		file("pc\actors\Bob\xxx\Bwkcyc1p.xxx",100,on,150);
		rotate(-45);
		nrintframes(4);
		trigger(_DIRsideleft|_DIRforward|_DIRwalking);
		break(on);
		offset(1);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}
Action(bobslowDiagFR)
{
		file("pc\actors\Bob\xxx\Bwkcyc1p.xxx",100,on,150);
		rotate(45);
		nrintframes(4);
		trigger(_DIRsideright|_DIRforward|_DIRwalking);
		break(on);
		offset(1);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}


action(BobWalkBack)
{
		file("pc\actors\Bob\xxx\Bwkbkcyg.xxx",100,on,150);
		trigger(_DIRwalking|_DIRbackward);
		nrintframes(4);
		break(on);
		offset(1);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}

Action(bobslowDiagBL)
{
		file("pc\actors\Bob\xxx\Bwkbkcyg.xxx",100,on,150);
		rotate(45);
		nrintframes(4);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(1);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}
Action(bobslowDiagBR)
{
		file("pc\actors\Bob\xxx\Bwkbkcyg.xxx",100,on,150);
		rotate(-45);
		nrintframes(4);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(1);
		soundlevel(0);
		connections(BobSpreadOut,bobidle);
}

/* *************   Other moves ******************* */

action(BobBalanceSpreadOut)	//Lead directly to next animation
{
		trigger(_DIRMove);
		nrintframes(-1);
		connections(BobBalanceSideR,BobBalanceSideL,BobBalanceBack,BobBalanceWalk);
}

Action(BobBalanceIdle)
{
		file("pc\actors\Bob\xxx\bobnidl1.ske",100,on);
		trigger(_allDIR);
		nrintframes(5);
		intforloop(on);
		break(on);
		connections(BobBalanceSpreadOut,BobBalanceTurnLeft,BobBalanceTurnRight,BobBalanceIdle);
}

Action(BobBalanceTurnLeft)
{
		file("pc\actors\Bob\xxx\btrnlft.ske",100,on);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(BobBalanceSpreadOut,BobBalanceTurnLeft,BobBalanceTurnRight,BobBalanceIdle);
}

Action(BobBalanceTurnRight)
{
		file("pc\actors\Bob\xxx\Btrnrt.ske",100,on);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(BobBalanceSpreadOut,BobBalanceTurnLeft,BobBalanceTurnRight,BobBalanceIdle);
}

Action(BobBalanceWalk)
{
		file("pc\actors\Bob\xxx\BWkBlnc.ske",100,on,100);
		nrintframes(4);
		break(on);
		offset(1);
		trigger(_DIRforward);
		soundlevel(100);
		connections(BobBalanceSpreadOut,BobBalanceIdle);
}

action(BobBalanceBack)
{
		file("pc\actors\Bob\xxx\Bwkbkcyg.xxx",100,on,100);
		trigger(_DIRbackward);
		nrintframes(4);
		break(on);
		offset(1);
		connections(BobBalanceSpreadOut,BobBalanceIdle);
}

Action(BobBalanceSideR)
{
		file("pc\actors\Bob\xxx\Bwkcyc1p.xxx",100,on,100);
		rotate(90);
		nrintframes(4);
		trigger(_DIRsideright);
		break(on);
		offset(1);
		connections(BobBalanceSpreadOut,BobBalanceIdle);
}

Action(BobBalanceSideL)
{
		file("pc\actors\Bob\xxx\Bwkcyc1p.xxx",100,on,100);
		rotate(-90);
		nrintframes(4);
		trigger(_DIRsideleft);
		break(on);
		offset(1);
		connections(BobBalanceSpreadOut,BobBalanceIdle);
}


/* *************   Other moves ******************* */

action(BobDragLift)		//Start grabbing a character
{
		file("pc\actors\Bob\xxx\BDragA.ske",100,off);
		trigger(_DIRbackward);
		nrintframes(1);
		connections(BobDragIdle);
}

action(BobDragIdle)
{
		file("pc\actors\Bob\xxx\BDrgHold.ske",100,on);
		trigger(_allDIR);
		nrintframes(1);
		break(on);
		connections(BobDrag,BobDragIdle);
}

action(BobDrag)
{
		file("pc\actors\Bob\xxx\BDragB.ske",100,on);
		trigger(_DIRbackward);
		nrintframes(1);
		break(on);
		connections(BobDrag,BobDragIdle);
}


action(Bobjump)
{

		file("pc\actors\Bob\xxx\testflap.xxx",100,on);

		trigger(_DIRjump);
		AIClass(_AIClassBobSkeleton);
		nrintframes(4);
		intforloop(on);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);	//XXX
		connections(BobJump);
}

SubRoutine(Sub_MoveDwarfUp)
{
		if(VFrame<3)
		{
			move(0,60,0);
		}
}

action(BobJumpWithGravity)
{
		file("pc\actors\ChotDwarf\xxx\DcJmpA.ske",100,off,100,_AIClassChot,-1,Sub_MoveDwarfUp);
		file("pc\actors\ChotDwarf\xxx\DcJmpB.ske",100,off,100,_AIClassChot,-1,Sub_MoveDwarfUp);
		file("pc\actors\ChotDwarf\xxx\DcJmpC.ske",100,off,100,_AIClassChot,-1,Sub_MoveDwarfUp);
		file("pc\actors\ChotDwarf\xxx\DcJmpD.ske",100,on,100,_AIClassChot,-1,Sub_MoveDwarfUp);
		file("pc\actors\Bob\xxx\testflap.xxx",100,on);
//		file("pc\actors\Bob\xxx\BJmpFlex.ske",100,off);
		trigger(_DIRjump);
		AIClass(_AIClassBobSkeleton);
		nrintframes(4);
		intforloop(on);
		break(off);
		gravity(on);
		ydeltafromzeroframe(off);	//XXX
		connections(BobFall);
}

action(BobFlyDead)
{
		//Bob gets hit, turns upside down (like a shot bird), and starts to fall..
		file("pc\actors\Bob\xxx\BShtDed1.ske",100,off);
		trigger(_allDIR);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobFlyDeadFall);
}

action(BobFlyDeadFall)
{
		//Bob falls
		file("pc\actors\Bob\xxx\BShtDed2.ske",100,on);
		trigger(_allDIR);
		break(off);
		gravity(on);
		ydeltafromzeroframe(off);
		connections(BobFlyDeadFall);
}

action(BobFlyDeadLand)
{
		file("pc\actors\Bob\xxx\BShtDed3.ske",100,off);
		trigger(_allDIR);
		break(off);
		gravity(on);
//		ydeltafromzeroframe(off);
		connections(BobFlyDeadLand);
}


SubRoutine(Sub_castWhiteLight)
{
	if(VFrame>=1)
	{
		vector(_set,TmpVector,200,200,200);
		spawnlight(HeavyCopSearchLight,4,Emptyvector,TmpVector,EmptyVector,300);
	}
}
action(BobWorshipsGod)
{
		file("pc\actors\Bob\xxx\BCutPray.ske",100,off);
		trigger(_allDIR);
		nrintframes(8);
		gravity(on);
		ActionSubRoutine(Sub_castWhiteLight);
		intforloop(off);
		break(off);
	//	connections(BobWorshipsGod);
}

action(BobTalksToGod)
{
		file("pc\actors\Bob\xxx\BTlk2God.ske",100,off);
		trigger(_allDIR);
		nrintframes(8);
		gravity(on);
		intforloop(off);
		break(off);
		connections(BobTalksToGodLoop);
}

action(BobTalksToGodLoop)
{
		file("pc\actors\Bob\xxx\BTlk2Gdh.ske",100,on);
		trigger(_allDIR);
		//nrintframes(8);
		gravity(on);
		intforloop(off);
		break(off);
		connections(BobTalksToGodLoop);
}

action(bobGlide)
{
		file("pc\actors\Bob\xxx\testgli2.xxx",100,on);
		trigger(_allDIR);
		nrintframes(4);
		gravity(off);
		break(on);
		ydeltafromzeroframe(off);
		connections(BobGlide);
}

action(BobFlap)
{
		//file("pc\actors\Bob\xxx\testflp2.ske",100,on);
		//file("pc\actors\Bob\xxx\testflap.xxx",100,on);
		file("pc\actors\Bob\xxx\bflap5g.ske",100,on);

		nrintframes(4);
		trigger(_DIRjump);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobFlap);
		break(on);
}


action(Bobfall)
{
		file("pc\actors\Bob\xxx\bflylnd5.ske",100,on);
		trigger(_AllDir);
		AIClass(_AIClassBobSkeleton);
		nrintframes(4);
		intforloop(on);
		gravity(on);
		ydeltafromzeroframe(off);
		break(on);
		connections(BobFall);
}

action(BobSlide)
{
		file("pc\actors\Bob\xxx\BSlide1.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(4);
		intforloop(on);
		gravity(on);
		ydeltafromzeroframe(off);
		break(on);
		connections(BobSlide);
}


action(BobFlyBackFlip)
{
		file("pc\actors\Bob\xxx\bflyflp2.ske",100,on,150);
		trigger(_AllDIR);
		nrintframes(3);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobIdle);
		break(on);
}

action(BobFlySmackWall)
{
		file("pc\actors\Bob\xxx\BWlSmack.ske",100,off,130);
		trigger(_AllDIR);
		nrintframes(3);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobFlyFromSmackWall);
}

action(BobFlySmackWallHold)
{
		file("pc\actors\Bob\xxx\BWlSmStl.ske",100,on,130);
		trigger(_AllDIR);
		nrintframes(3);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobFlySmackWallHold);
}

action(BobFlyFromSmackWall)
{
		file("pc\actors\Bob\xxx\BWSmckRt.ske",100,off,130);
		trigger(_AllDIR);
		nrintframes(3);
		gravity(off);
		break(off);
		ydeltafromzeroframe(off);
		connections(BobFlap,Bobfall);
}

action(BobDeposses)
{
		file("pc\actors\Bob\xxx\bflyflp2.ske",100,on,150);
		trigger(_AllDIR);
		nrintframes(3);
		gravity(on);
		ydeltafromzeroframe(off);
		connections(BobDeposses);
		break(on);
}


action(BobDepossesDaze)
{
		file("pc\actors\Bob\xxx\BDeposs1.ske",100,off,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_AllDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(3);
		gravity(on);
		break(on);
		connections(BobSpreadOut,bobidle);
}

action(BobTouchDown)
{
		file("pc\actors\bob\xxx\Brnend2p.xxx",100,off);
		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassBobSkeleton);
		nrintframes(5);
		break(on);
		nomove(true);
		//connections(BobSpreadOut,bobidle);
		connections(EvilBobAttack,DwarfClawAttack,bobshoot,BobSpreadOut,bobtouchdown,bobidle);
}

action(BobRunUpStairs)
{
		//file("pc\actors\bob\xxx\brnstair.ske",100,on);
		file("pc\actors\bob\xxx\brnstar3.ske",100,on,125);
		trigger(_DIRforward);
		AIClass(_AIClassBobSkeleton);
		offset(1);
		nrintframes(0);	//MISSING: Doesnt work with 4 (Rootbone interpolation bug again)
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobRunUpStairs);
}


Action(BobClimbUp)
{
		file("pc\actors\bob\xxx\BNClmb2a.ske",50,off);
		file("pc\actors\bob\xxx\BNClmb02.ske",100,off);
		//file("pc\actors\bob\xxx\bclmbeg3.ske",100,off);	//rolls through the floor right now
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(4);
		gravity(off);
		ydeltafromzeroframe(off);	//Default=on
		connections(bobidle);
}

Action(BobClimbHang)
{
		file("pc\actors\bob\xxx\bhngidl3.ske",10,on);
		file("pc\actors\bob\xxx\bhngidl1.ske",60,on);
		file("pc\actors\bob\xxx\bhngidl2.ske",100,on);
		nrintframes(4);
		trigger(_allDIR);
		break(on);
		gravity(off);
		ydeltafromzeroframe(off);	//Default=on
		connections(BobShimmyLeft2,BobShimmyRight2,BobShimmyLeft,BobShimmyRight,BobClimbHang);
}

Action(BobShimmyLeft)
{
		file("pc\actors\bob\xxx\BShmyLft.ske",100,on);
		nrintframes(4);
		trigger(_DIRleft);
		break(on);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobShimmyLeft2,BobShimmyRight2,BobShimmyLeft,BobShimmyRight,BobClimbHang);
}

Action(BobShimmyRight)
{
		file("pc\actors\bob\xxx\BShmyRgt.ske",100,on);
		nrintframes(4);
		trigger(_DIRright);
		break(on);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobShimmyLeft2,BobShimmyRight2,BobShimmyRight,BobShimmyLeft,BobClimbHang);
}

Action(BobShimmyLeft2)
{
		file("pc\actors\bob\xxx\BShmyLft.ske",100,on);
		nrintframes(4);
		trigger(_DIRsideleft);
		break(on);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobShimmyLeft2,BobShimmyRight2,BobShimmyLeft,BobShimmyRight,BobClimbHang);
}

Action(BobShimmyRight2)
{
		file("pc\actors\bob\xxx\BShmyRgt.ske",100,on);
		nrintframes(4);
		trigger(_DIRsideright);
		break(on);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobShimmyLeft2,BobShimmyRight2,BobShimmyRight,BobShimmyLeft,BobClimbHang);
}

/* *************   Crouching moves ******************* */


action(BobCrouchDiagFL)
{
		file("pc\actors\Bob\xxx\BCrWkFL.ske",100,on);
		trigger(_DIRforward|_DIRsideleft);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchL)
{
		file("pc\actors\Bob\xxx\BCrWkL.ske",100,on);
		trigger(_DIRsideleft);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchDiagFR)
{
		file("pc\actors\Bob\xxx\BCrWkFR.ske",100,on);
		trigger(_DIRforward|_DIRsideright);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchR)
{
		file("pc\actors\Bob\xxx\BCrWkR.ske",100,on);
		trigger(_DIRsideright);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchDiagFR)
{
		file("pc\actors\Bob\xxx\BCrWkFR.ske",100,on);
		trigger(_DIRforward|_DIRsideright);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchDiagBL)
{
		file("pc\actors\Bob\xxx\BCrWkBL.ske",100,on);
		trigger(_DIRbackward|_DIRsideleft);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchDiagBR)
{
		file("pc\actors\Bob\xxx\BCrWkBR.ske",100,on);
		trigger(_DIRbackward|_DIRsideright);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchSpreadOut)
{
		trigger(_DIRMove);
		nrintframes(-1);
		connections(BobCrouchForwardLeft,BobCrouchForwardRight,BobCrouchDiagFL,BobCrouchDiagFR,BobCrouchDiagBL,BobCrouchDiagBR,BobCrouchForward,BobCrouchBackward,BobCrouchL,BobCrouchR,BobCrouchTurnLeft,BobCrouchTurnRight);
}

	

action(BobCrouchDown)
{
		file("pc\actors\Bob\xxx\BSt2Crwl.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		nrintframes(4);
		connections(BobCrouchIdle);
}

action(BobCrouchUp)
{
		file("pc\actors\Bob\xxx\BCrwl2St.ske",100,on);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		nrintframes(4);
		connections(BobSpreadOut,BobIdle);
}

action(BobCrouchTurnLeft)
{
		file("pc\actors\Bob\xxx\BCrStTLf.ske",100,on);
		trigger(_DIRleft);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchTurnRight)
{
		file("pc\actors\Bob\xxx\BCrStTRg.ske",100,on);
		trigger(_DIRright);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchForwardLeft)
{
		file("pc\actors\Bob\xxx\BCrFwLft.ske",100,on);
		trigger(_DIRforward|_DIRleft);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchForwardRight)
{
		file("pc\actors\Bob\xxx\BCrFwRgt.ske",100,on);
		trigger(_DIRforward|_DIRright);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchForward)
{
		file("pc\actors\Bob\xxx\BCrWkF.ske",100,on);
		trigger(_DIRforward);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchBackward)
{
		file("pc\actors\Bob\xxx\BCrWkBw.ske",100,on);
		trigger(_DIRbackward);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}

action(BobCrouchIdle)
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		connections(BobCrouchSpreadOut,BobCrouchIdle);
}


// *******************************************************************8
// Hurt and dead

action(BobDead)
{
		//file("pc\actors\Bob\xxx\Bdeath2g.xxx",100,off);
		file("pc\actors\Bob\xxx\bdiebkwd.ske",25,off);
		file("pc\actors\Bob\xxx\bdieleft.ske",50,off);
		file("pc\actors\Bob\xxx\bdierght.ske",75,off);
		file("pc\actors\Bob\xxx\BDeath2.ske",100,off);
		AIClass(_AIClassBobSkeleton);
		trigger(_allDIR);
		nrintframes(4);
		break(off);
		//connections(BobDead);
}

action(BobCrush)
{
		//file("pc\actors\Bob\xxx\Bdeath2g.xxx",100,off);
		file("pc\actors\Bob\xxx\BDeath1.ske",100,off);
		AIClass(_AIClassBobSkeleton);
		collision(off);
		gravity(off);
		trigger(_allDIR);	
		nrintframes(4);
		break(off);
}

action(BobFallDead)
{
		//file("pc\actors\Bob\xxx\Bdeath2g.xxx",100,off);
		file("pc\actors\Bob\xxx\BDeath1.ske",100,off);
		trigger(_allDIR);	
		AIClass(_AIClassBobSkeleton);
		nrintframes(4);
		break(off);
		connections(BobFallDead);
}

action(BobFlapWoundLight)
{
//		file("pc\actors\Bob\xxx\BFlapSht1.ske",100,on);
//		//file("pc\actors\Bob\xxx\bwund2g.ske",100,off);

		file("pc\actors\Bob\xxx\BFlapSht1.ske",50,on);
		file("pc\actors\Bob\xxx\bwund2g.ske",100,off);

		trigger(_DIRNotEndOfAnim);
		break(on);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(BobFlap);
}

action(BobWoundLight)
{
//		file("pc\actors\Bob\xxx\BShtStl2.ske",25,off);
//		file("pc\actors\Bob\xxx\BShtStl1.ske",100,off);
//		//file("pc\actors\Bob\xxx\bwund2g.ske",100,off);

		file("pc\actors\Bob\xxx\BShtStl2.ske",25,off);
		file("pc\actors\Bob\xxx\bwund2g.ske",66,off);
		file("pc\actors\Bob\xxx\BShtStl1.ske",100,off);

		trigger(_DIRNotEndOfAnim);
		AIClass(_AIClassBobSkeleton);
		break(on);
		collision(on);
		nrintframes(4);
		connections(BobSpreadOut,BobWoundLight,BobTurnLeft,BobTurnRight,BobIdle);
}

action(BobWoundLightRun)
{
		file("pc\actors\Bob\xxx\BNRnHrt1.ske",100,off);
		//trigger(_DIRNotEndOfAnim);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		nrintframes(4);
		break(off);
		move(0,0,BobMaxRunSpeedFwd);
		soundlevel(100);
		connections(BobSpreadOut,bobidle);
}

action(BobShieldExplosion)
{
		file("pc\actors\Bob\xxx\BRctExp1.ske",100,off);
		trigger(_allDIR);
		break(off);
		collision(on);
		nrintframes(4);
		connections(BobSpreadOut,BobIdle);
		//connections(BobSpreadOut,BobTurnLeft,BobTurnRight,BobIdle);
}



//***************   CHOT DWARF ANIMATIONS

SubRoutine(Sub_LaunchDwarf)
{
		if(VFrame==22)
		{
			vector(_settoactorpos,tmpvector);
			vector(_set,gactorpos,0,-50,0);
			vector(_add,tmpvector,gactorpos);
			callsub(sub_fxsmallexplosion);

			sample(SFXBooster,-1);
			call(ScreenShake,4,4,4,0.04);

			move(0,500,-800);
			State(_or,StateJump|StateThrown);
		}
}


action(DwarfLaunch)
{
		file("pc\actors\ChotDwarf\xxx\DcLnchSt.ske",100,off);
		trigger(_allDIR);
		AIClass(_AIClassBobSkeleton);
		break(off);
		collision(on);
		nrintframes(4);
		gravity(off);

		ActionSubRoutine(Sub_LaunchDwarf);

		connections(DwarfInAir);
}

action(DwarfInAir)
{
		file("pc\actors\ChotDwarf\xxx\DcLnchLp.ske",100,off);
		//file("pc\actors\ChotDwarf\xxx\DcLnchL2.ske",100,off);
		trigger(_allDIR);
		break(on);
		collision(on);
		nrintframes(4);

		move(0,0,-20);

		connections(DwarfTouchDown,DwarfHitWall,DwarfInAir);
}

action(DwarfTouchDown)
{
		file("pc\actors\ChotDwarf\xxx\DcLncLn1.ske",50,on);
		file("pc\actors\ChotDwarf\xxx\DcLncLn2.ske",100,on);
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);

		ActionSubRoutine(Sub_GetUpClearThrown19);

		connections(BobIdle);
}

action(DwarfHitWall)
{
		file("pc\actors\Bob\xxx\BTrFwWal.ske",100,on);
		trigger(_DIRvercol);
		break(off);
		collision(on);
		nrintframes(4);

		ActionSubRoutine(Sub_ClrThrownFlag);

		connections(BobIdle);
}

Action(DwarfClawAttack)
{
		file("pc\actors\ChotDwarf\xxx\DcSlash.ske",100,on);
		AIClass(_AIClassChot|_AIClassMale);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	
		Power(10);

		AttachActionStartAtFrame(10);
		AttachAction(GENWoundLight);

		ActionSubRoutine(Sub_clawblood);
		//ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		nrintframes(5);
		//nomove(true);
		intforloop(off);
		break(off);
		connections(bobidle);
}

Action(EvilBobAttack)
{
		file("pc\actors\Bob\xxx\EbJmpGor.ske",100,on);
		AIClass(_AIclassEvil|_AIClassMale);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	
		Power(10);

		AttachActionStartAtFrame(10);
		AttachAction(GENWoundLight);

		ActionSubRoutine(Sub_clawblood);
		//ActionSubRoutine(Sub_ChangeMeToEnemy);

		trigger(_DIRshoot);
		nrintframes(5);
		//nomove(true);
		intforloop(off);
		break(off);
		connections(bobidle);
}


action(DwarfWorship)
{
		file("pc\actors\Chotdwarf\xxx\dcworshp.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(DwarfWorship,BobIdle);
}



////////////////////////////////////
//////  E V I L    B O B   /////////
////////////////////////////////////

action(EBobTapDance)
{
		file("pc\actors\Bob\xxx\bcel2.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		connections(EBobHeelTap);
}

action(EBobHeelTap)
{
		file("pc\actors\Bob\xxx\bcel4g.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		connections(BobIdle);
}




