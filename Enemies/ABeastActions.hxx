//Armored beast actions:

#define ABeastMaxTurnSpeed 75
#define ABeastTurnAcc 7
#define ABeastMaxTurnSpeedWounded 10
#define ABeastTurnAccWounded 1

#define ABeastJumpSpeed 14
#define ABeastJumpGravity 0.9

#define ABeastMaxTurnSpeedair 60
#define ABeastTurnAccair 5
#define ABeastAirSpeed 20
#define ABeastAirBulb 0.05	//0.1=very soft, 1.0=get speed immediately

#define ABeastMaxFall		-500	//Fall before he breaks his legs.
#define	DamageABeastFall	500	//Maximum, depends on altitude you fall

action(ABeastCrouchDown)
{
		file("pc\actors\Behemoth\xxx\BCrchStr.ske",100,off);
			
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(ABeastCrouchIdle);
}

action(ABeastCrouchUp)
{
		file("pc\actors\Behemoth\xxx\BCrchEnd.ske",100,off);
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastCrouchIdle)
{
		file("pc\actors\Behemoth\xxx\BCrchIdl.ske",100,on);
			
		trigger(_noDIR);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(ABeastCrouchIdle,ABeastSpreadOut);
}


action(ABeastAngry)
{
		file("pc\actors\Abeast\xxx\mspan13.ske",100,on);			//Roaring and beating chest
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(ABeastIdle);
}



/*
** ABeast Action Animations
*/
/* *************   ******************* */
action(ABeastElectricShock0)
{
		file("pc\actors\Chot\xxx\aelectLP.ske",100,off,130);
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true)
		connections(GENElectricShock1);
		collision(on);
		gravity(off);
}

action(ABeastElectricShock1)
{
		file("pc\actors\Chot\xxx\aelectHL.ske",100,on);
		move(0,0,20);
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		nrintframes(6);
		intforloop(off);
		nomove(true)
		connections(GENElectricShock1);
		gravity(off);
		collision(on);
}


SubRoutine(Sub_PowerUp)
{
	if(VFrame==1)						//powerup
	{
		Sample(SFXPAbeastPowerUp2D,-1);
	}
	elseif(VFrame==75)					//right foot down
	{
		Sample(SFXPAbeastStep2D,-1);
	}
	elseif(VFrame==90)					//left foot down
	{
		Sample(SFXPAbeastStep2D,-1);
	}
	elseif(VFrame==150)
	{
		Sample(SFXABeastStretch2D,-1);
	}
}

action(ABeastPowerUp)
{
		file("pc\actors\Abeast\xxx\AbPowrUp.ske",100,off,100,-1,-1,Sub_PowerUp);
		trigger(_allDIR);
		break(off);
		connections(ABeastIdle);
}


action(ABeastShutDown)
{
		file("pc\actors\Abeast\xxx\AbOffIdl.ske",100,on);			//Roaring and beating chest
		trigger(_allDIR);
		break(on);
		connections(ABeastShutDown);
}


action(ABeastIdle)
{
//		file("pc\actors\Abeast\xxx\mbeidl3g.ske",20,on);
//		file("pc\actors\Abeast\xxx\mbeidl1g.ske",50,on);
//		file("pc\actors\Abeast\xxx\mbeidl2g.ske",100,on);
		file("pc\actors\Abeast\xxx\AbIdle1.ske",80,on);//breathing anim, do this 80% of the time
		file("pc\actors\Abeast\xxx\AbIdle2.ske",100,on);//look right & left anim, do this 20% of the time
		trigger(_allDIR);
		AIclass(_AIClassAbeastSkeleton);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(ABeastSpreadOut,ABeastStandShoot,ABeastTurnLeft,ABeastTurnRight,ABeastIdle);
}

Action(ABeastAttentionIdle)
{
		file("pc\actors\Chot\xxx\Matnidlg.ske",100,on);
		break(on);
		connections(ABeastSpreadOut,ABeastStandShoot,ABeastTurnLeft,ABeastTurnRight,ABeastAttentionIdle);
}

Action(ABeastAttention)
{
		file("pc\actors\Chot\xxx\matnshng.ske",100,on);	//respond to attention command
		break(off);
		nrintframes(8);
		connections(ABeastAttentionIdle);
}

action(ABeastSpreadOut)	//Lead directly to next animation
{
		trigger(_DIRMove);
		AIclass(_AIClassABeastSkeleton);
		nrintframes(-1);
		connections(ABeastStandShoot,ABeastWalkDiagFL,ABeastWalkDiagFR,ABeastWalkDiagBL,ABeastWalkDiagBR,ABeastWalk,ABeastWalkBack,ABeastWalkL,ABeastWalkR,ABeastRunDiagFL,ABeastRunDiagFR,ABeastRunDiagBL,ABeastRunDiagBR,ABeastRun,ABeastRunBack,ABeastRunL,ABeastRunR);
}

action(ABeastIdleLongTime)
{
		file("pc\actors\Chot\xxx\Macaren3.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassAbeastSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(ABeastSpreadOut,ABeastStandShoot,ABeastTurnLeft,ABeastTurnRight,ABeastIdleLongTime,ABeastIdle);
}

action(ABeastIdleHitWall)	//used just after you bounce into a wall
{
		file("pc\actors\Chot\xxx\Mneidl2p.xxx",2,on,-1,-1,Sub_RandomCopScratchesCrotch);	//ass scratch
		file("pc\actors\Chot\xxx\Mneidl3p.xxx",4,on,-1,-1,Sub_RandomCopScratchesCrotch);	//crotch scratch
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(ABeastHitWallSpreadOut);
}
action(ABeastHitWallSpreadOut)	//Lead directly to next animation
{
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		nrintframes(-1);
		connections(ABeastHitWallStandShoot,ABeastHitWallTurnLeft,ABeastHitWallTurnRight,ABeastIdleHitWall);
}

action(ABeastIdleHitWallFront)	//used just after you bounce into a wall, face first
{
//MISSING Animation
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(ABeastHitWallStandShoot,ABeastHitWallTurnLeft,ABeastHitWallTurnRight,ABeastIdleHitWallFront);
}

action(ABeastTurnLeftRightEnd)
{
		file("pc\actors\ABeast\xxx\AbTrStop.ske",100,off,100);
		trigger(_DIRnotendofanim|_noDIR);
		break(on);
		nrintframes(3);
		intforloop(off);
		connections(ABeastTurnRight,ABeastTurnLeft,ABeastIdle);
}

action(ABeastTurnLeft)
{
//		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		file("pc\actors\ABeast\xxx\AbTrLSt.ske",100,off,100);//start turn right
		file("pc\actors\ABeast\xxx\AbTrLLp.ske",100,on,100);//turn right loop
//		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(ABeastSpreadOut,ABeastStandShoot,ABeastTurnLeft,ABeastTurnRight,ABeastTurnLeftRightEnd,ABeastIdle);
}

action(ABeastTurnRight)
{
//		file("pc\actors\Chot\xxx\mtrnrt2.ske",100,on);
		file("pc\actors\ABeast\xxx\AbTrRSt.ske",100,off,100);//start turn right
		file("pc\actors\ABeast\xxx\AbTrRLp.ske",100,on,100);//turn right loop
//		move(-2,0,0);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(ABeastSpreadOut,ABeastStandShoot,ABeastTurnLeft,ABeastTurnRight,ABeastTurnLeftRightEnd,ABeastIdle);
}

action(ABeastHitWallTurnLeft)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(ABeastHitWallSpreadOut);
}

action(ABeastHitWallTurnRight)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(-2,0,0)
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(ABeastHitWallSpreadOut);
}



/* *************   Standard moves with gun ******************* */

/* *************   Standard moves without gun ******************* */


action(ABeastWalk)
{
		file("pc\actors\Abeast\xxx\Mblwkcyp.xxx",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);

		nrintframes(4);
		intforloop(off);
		offset(4);
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastWalkBack)
{
		//file("pc\actors\Chot\xxx\Mwkbkngn.ske",100,on);
		file("pc\actors\Abeast\xxx\MblwkBcy.ske",100,on);
		
		nrintframes(8);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(4);
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastWalkL)
{
		file("pc\actors\Behemoth\xxx\BWlkL.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(36);
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastWalkR)
{
		file("pc\actors\Behemoth\xxx\BWlkR.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(36);
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastWalkDiagFL)
{
		file("pc\actors\Behemoth\xxx\BWlkFL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		offset(36)
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastWalkDiagFR)
{
		file("pc\actors\Behemoth\xxx\BWlkFr.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		offset(36)
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastWalkDiagBL)
{
		file("pc\actors\Behemoth\xxx\BWlkBL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(13);
		nrintframes(8);
		connections(ABeastSpreadOut,ABeastIdle);
}
action(ABeastWalkDiagBR)
{
		file("pc\actors\Behemoth\xxx\BWlkBR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(13);
		nrintframes(8);
		connections(ABeastSpreadOut,ABeastIdle);
}



action(ABeastRun)
{
	//	file("pc\actors\Abeast\xxx\Mblrncyp.xxx",100,on);
		file("pc\actors\Abeast\xxx\MblrnFg.ske",100,on);

		offset(16);
		nrintframes(4);
		intforloop(off);

		trigger(_DIRforward);
		break(on);
		connections(ABeastSpreadOut,ABeastIdle);
}
action(ABeastRunBack)
{
	//	file("pc\actors\Abeast\xxx\MblrnBcy.ske",100,on);
		file("pc\actors\Abeast\xxx\MblrnBg.ske",100,on);
		nrintframes(8);
		trigger(_DIRbackward);
		break(on);
		offset(8);
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastRunL)
{
		file("pc\actors\Abeast\xxx\MblrnLg.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideleft);
		break(on);
		offset(16)
		connections(ABeastSpreadOut,ABeastIdle);
}
action(ABeastRunR)
{
		file("pc\actors\Abeast\xxx\MblrnRg.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideright);
		break(on);
		offset(16)
		connections(ABeastSpreadOut,ABeastIdle);
}
action(ABeastRunDiagFL)
{
		file("pc\actors\Abeast\xxx\MblrnFLg.ske",100,on);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(16)
		nrintframes(8);
		connections(ABeastSpreadOut,ABeastIdle);
}
action(ABeastRunDiagFR)
{
		file("pc\actors\Abeast\xxx\MblrnFRg.ske",100,on);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(16)
		nrintframes(8);
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastRunDiagBL)
{
		file("pc\actors\Abeast\xxx\MblrnBLg.ske",100,on);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		nrintframes(8)
		offset(8)
		connections(ABeastSpreadOut,ABeastIdle);
}

action(ABeastRunDiagBR)
{
		file("pc\actors\Abeast\xxx\MblrnBRg.ske",100,on);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(8)
		nrintframes(8);
		connections(ABeastSpreadOut,ABeastIdle);
}

/* *************   Jump And Fall ******************* */



action(ABeastJump)	//Lead directly to next animation
{
		trigger(_DIRjump);
		AIclass(_AIClassABeastSkeleton);
		nrintframes(-1);
		connections(ABeastJumpBL,ABeastJumpBR,ABeastJumpBackwards,ABeastJumpFL,ABeastJumpL,ABeastJumpFR,ABeastJumpR,ABeastJumpForward,ABeastJumpInPlace);
}


action(ABeastJumpInPlace)
{
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(ABeastFallInplace);
}

action(ABeastJumpForward)
{
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRforward);
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(ABeastFallForward);
}

action(ABeastJumpL)
{
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRsideleft);
		rotate(-90)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(ABeastFallL);
}

action(ABeastJumpFL)
{
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRsideleft|_DIRforward);
		rotate(-45)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(ABeastFallFL);
}
action(ABeastJumpR)
{
		file("pc\actors\Abeast\xxx\AbJmpS.ske",100,off,100);
		trigger(_DIRsideright);
		rotate(90)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(ABeastFallR);
}

action(ABeastJumpFR)
{
		file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRsideright|_DIRforward);
		rotate(45)
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(ABeastFallFR);
}

action(ABeastJumpBackwards)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
		trigger(_DIRbackward);
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(ABeastFallBackwards);
}

action(ABeastJumpBR)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideright);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(-45)
		ydeltafromzeroframe(off);
		connections(ABeastFallBR);
}

action(ABeastJumpBL)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideleft);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(45)
		ydeltafromzeroframe(off);
		connections(ABeastFallBL);
}

action(ABeastfallForward)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(off);
		connections(ABeastfallForward);
}

action(ABeastfallFL)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(ABeastfallFL);
}
action(ABeastfallFR)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(ABeastfallFR);
}
action(ABeastfallL)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-90)
		connections(ABeastfallL);
}
action(ABeastfallR)
{
		file("pc\actors\Abeast\xxx\AbJmpH.ske",100,off,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(90)
		connections(ABeastfallR);
}

action(ABeastfallInPlace)
{
		file("pc\actors\Abeast\xxx\AbJmpL.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(off);
		connections(ABeastfallInPlace);
}

action(ABeastfallBackwards)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(ABeastfallBackwards);
}
action(ABeastfallBL)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(ABeastfallBL);
}
action(ABeastfallBR)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(ABeastfallBR);
}

action(ABeastfall)	//Fall when falling from edge only
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
		trigger(_AllDir);
		AIclass(_AIClassABeastSkeleton);
		nrintframes(7);
		offset(8);
		ydeltafromzeroframe(off);
		break(off);
		connections(ABeastFall);
}

action(ABeastTouchDown)
{
		file("pc\actors\Abeast\xxx\AbJmpL.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassABeastSkeleton);
		nrintframes(5);
		break(on);

		ActionSubRoutine(Sub_HeavyLand);

		connections(ABeastSpreadOut,ABeastStandShoot,ABeastTouchDown,ABeastIdle);
}

/* *************   Other Moves ******************* */

action(AbeastStomp)
{
		file("pc\actors\abeast\xxx\Mbestmp2.ske",100,off);
		trigger(_DIRjump);
		break(off);
		connections(Abeastidle);
}


action(AbeastShot)
{
		file("pc\actors\abeast\xxx\mspan13.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(off);
		//connections(AbeastShot);
		connections(Abeastidle);
}

action(ABeastTearDoorOpen)
{
		file("pc\actors\Behemoth\xxx\BTearDr.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(off);
		connections(GENidle);
}

action(AbeastPunch)
{
		file("pc\actors\abeast\xxx\Mbegrnd.ske",100,off);
		trigger(_allDIR);
		connections(Abeastidle);
}

action(ABeastStandShoot)
{
		//file("pc\actors\abeast\xxx\mspan13.xxx",100,on);
		file("pc\actors\Abeast\xxx\MbFrM1.ske",33,on);
		file("pc\actors\Abeast\xxx\MbFrM2.ske",66,on);
		file("pc\actors\Abeast\xxx\MbFrM3.ske",100,on);
		trigger(_DIRshoot);
		break(off);
		connections(ABeastStandShoot,ABeastTurnLeft,ABeastTurnRight,ABeastIdle);
}

action(ABeastHitWallStandShoot)
{
		file("pc\actors\chot\xxx\Mfire3h2.ske",100,on);
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		connections(ABeastHitWallSpreadOut);
}
action(ABeastPossesed)
{
		file("pc\actors\Abeast\xxx\mblprosp.ske",100,off,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_allDIR);
		AIclass(_AIClassAbeastSkeleton);
		break(off);
		connections(ABeastidle);
}

action(ABeastDepossesed)
{
		file("pc\actors\chot\xxx\Mstun1g.ske",50,on,100,-1,-1,Sub_ClrThrownFlag);
		file("pc\actors\chot\xxx\Mstun2g.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);
		trigger(_allDIR);
		AIclass(_AIClassAbeastSkeleton);
		nrintframes(4);
		break(off);
		connections(ABeastidle);
}

action(ABeastThrowGrenade)
{
		//file("pc\actors\chot\xxx\MthrwgrA.ske",100,on);
		//file("pc\actors\Abeast\xxx\MbFrGrH.ske",100,on);
		file("pc\actors\Abeast\xxx\MbFrGrL.ske",100,on);
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		nrintframes(8);
		connections(ABeastThrowGrenade2);
}

action(ABeastThrowGrenade2)
{
		file("pc\actors\Abeast\xxx\MbFrGrSn.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(0);
		connections(ABeastSpreadOut,ABeastThrowGrenade2,ABeastidle);
}

/* *************   Wounded ******************* */

action(ABeastWoundLight)
{	
//		file("pc\actors\Abeast\xxx\MbWund1.ske",50,off);
//		file("pc\actors\Abeast\xxx\MbWund2.ske",100,off);
		file("pc\actors\Abeast\xxx\AbWnd1.ske",25,off);
		file("pc\actors\Abeast\xxx\AbWnd2.ske",50,off);
		file("pc\actors\Abeast\xxx\AbWnd3.ske",75,off);
		file("pc\actors\Abeast\xxx\AbWnd4.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassABeastSkeleton);
		break(on);
		collision(on);
		nrintframes(1);
		connections(ABeastSpreadOut,ABeastStandShoot,ABeastWoundLight,ABeastTurnLeft,ABeastTurnRight,ABeastIdle);
}

action(ABeastWoundLightNoBreak)	//Identical to the one above except for break
{
//		file("pc\actors\Chot\xxx\FstWnd1.ske",10,off);
//		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
//		//file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
		file("pc\actors\Abeast\xxx\AbWnd1.ske",25,off);
		file("pc\actors\Abeast\xxx\AbWnd2.ske",50,off);
		file("pc\actors\Abeast\xxx\AbWnd3.ske",75,off);
		file("pc\actors\Abeast\xxx\AbWnd4.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		collision(on);
		nrintframes(1);
		connections(ABeastSpreadOut,ABeastStandShoot,ABeastWoundLight,ABeastTurnLeft,ABeastTurnRight,ABeastIdle);
}
/*
action(ABeastWoundFlyBack1)	//Hold frame
{
//		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,off);
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(ABeastWoundFlyBack2);
}

action(ABeastWoundFlyBack2)	//Hitting wall+hold frame
{
//		file("pc\actors\Chot\xxx\ThBkhtwl.ske",100,off);
		trigger(_DIRVerCol);
		break(on);
		collision(on);
		nrintframes(4);
		connections(ABeastWoundFlyBack3);
}
action(ABeastWoundFlyBack3)	//Land on ground
{
//		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);
		trigger(_DIRHorCol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(ABeastIdle);
}
*/
/* *************   Burned, steamed and blind ******************* */



/* *************   Crawling+Being Dragged+Other deaths ******************* */


subroutine(Sub_ABeastStandDead)
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
action(ABeastStandDead)
{
		file("pc\actors\Abeast\xxx\MbDeath1.ske",50,off);//70=slower anim speed (fall-down slower) default is 100
		file("pc\actors\Abeast\xxx\MbDeath2.ske",100,off);
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		nrintframes(12);

		ActionSubRoutine(Sub_ABeastStandDead);
}


action(ABeastFallDead)
{
		file("pc\actors\Abeast\xxx\MbDeath1.ske",50,off);//70=slower anim speed (fall-down slower) default is 100
		file("pc\actors\Abeast\xxx\MbDeath2.ske",100,off);
		trigger(_allDIR);
		AIclass(_AIClassABeastSkeleton);
		break(off);
		nrintframes(12);

		ActionSubRoutine(Sub_ABeastStandDead);
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


