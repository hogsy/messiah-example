#define DomMaxTurnSpeed 75
#define DomTurnAcc 7
#define DomMaxTurnSpeedWounded 10
#define DomTurnAccWounded 1

#define DomJumpSpeed			14
#define DomJumpGravity		0.9
#define DomMinHoldJumpAction	3

#define DomMaxTurnSpeedair 60
#define DomTurnAccair 5
#define DomAirSpeed 20
#define DomAirBulb 0.05	//0.1=very soft, 1.0=get speed immediately

#define DomMaxFall		-500	//Fall before he breaks his legs.
#define	DamageDomFall	500	//Maximum, depends on altitude you fall



action(DomSpread)	//Lead directly to next animation
{
	trigger(_DIRMove);
	nrintframes(-1);
	connections(DomSpreadGun,DomWalkDiagFL,DomWalkDiagFR,DomWalkDiagBL,DomWalkDiagBR,DomWalk,DomWalkBack,DomWalkL,DomWalkR,DomRunDiagFL,DomRunDiagFR,DomRunDiagBL,DomRunDiagBR,Domrun,DomRunBack,DomRunL,DomRunR,DomTurnRight,DomTurnLeft);
}

action(DomSpreadGun)	//Lead directly to next animation
{
	trigger(_DIRMove|_DIRHaveGun);
	nrintframes(-1);
	connections(DomWalkDiagFLGun,DomWalkDiagFRGun,DomWalkDiagBLGun,DomWalkDiagBRGun,DomWalkGun,DomWalkBackGun,DomWalkLGun,DomWalkRGun,DomRunDiagFLGun,DomRunDiagFRGun,DomRunDiagBLGun,DomRunDiagBRGun,DomRunGun,DomRunBackGun,DomRunLGun,DomRunRGun,DomTurnRightCombat,DomTurnLeftCombat);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	IDLE ACTIONS

Action(DomTalk)
{
	file("pc\actors\domina\talk\jawflap.ske",100,on);

	nrintframes(4);
	intforloop(on);
	trigger(_allDIR);
	break(on);
	connections(DomKungFu,DomTalk);
}

Action(DomKungFu)
{
	file("pc\actors\domina\talk\kungfu.ske",100,on);

	nrintframes(4);
	intforloop(on);
	trigger(_DIRshoot);
	break(off);
	connections(DomTalk);
}


/* *************   Crouching moves ******************* */

action(DomCrouchWoundLight)
{
		file("pc\actors\Chot\xxx\MCrWnd1.ske",10,off);	//Head.    
		file("pc\actors\Chot\xxx\MCrWnd2.ske",100,off);	//Stomach/chest. 
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchShoot,DomCrouchSpreadOut,DomCrouchIdle);
}
     
action(DomCrouchDead)
{
		file("pc\actors\Chot\xxx\McrDeth1.ske",100,off);	//Throw back from chest hit. Die on back.  
		trigger(_allDIR);
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		nrintframes(8);
}

action(DomCrouchDown)
{
		file("pc\actors\Prost1\xxx\FCrStart.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchIdle);
}

action(DomCrouchUp)
{
		file("pc\actors\Prost1\xxx\FCrEnd.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomSpread,DomIdle);
}

action(DomCrouchDownCombat)
{
		file("pc\actors\Prost1\xxx\FCrStrCm.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchIdle);
}

action(DomCrouchUpCombat)
{
		file("pc\actors\Prost1\xxx\FCrEndCm.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomSpread,DomIdle);
}

action(DomCrouchShoot)
{
		file("pc\actors\Prost1\xxx\FCrHvFrH.ske",100,on);		//Fire heavy hold/Aim frame
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchShoot,DomCrouchIdle);
}

action(DomCrouchLightRecoil)
{
		file("pc\actors\Prost1\xxx\FCrHvFrP.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\Prost1\xxx\FCrLtFr.ske",100,on);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchShoot,DomCrouchIdle);
}

action(DomCrouchHeavyRecoil)
{
		file("pc\actors\Prost1\xxx\FCrHvFrP.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\Prost1\xxx\FCrHvFr.ske",100,on);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchShoot,DomCrouchIdle);
}

action(DomCrouchGrenade)
{
		file("pc\actors\Prost1\xxx\FCrTrGrn.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchIdle)
{
		file("pc\actors\Prost1\xxx\FCrIdle.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchShoot,DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchSpreadOut)
{
		file("pc\actors\Prost1\xxx\FCrIdle.ske",100,on);
		trigger(_DIRmove);
		nrintframes(-1);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchForwardLeft,DomCrouchForwardRight,DomCrouchBackwardLeft,DomCrouchBackwardRight,DomCrouchForward,DomCrouchBackward,DomCrouchLeft,DomCrouchRight,DomCrouchRForwardLeft,DomCrouchRForwardRight,DomCrouchRBackwardLeft,DomCrouchRBackwardRight,DomCrouchRForward,DomCrouchRBackward,DomCrouchRLeft,DomCrouchRRight);
}

action(DomCrouchRForward)
{
		file("pc\actors\Chot\xxx\MCrRunF.ske",100,on,110);
		trigger(_DIRforward);
		break(on);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRBackward)
{
		file("pc\actors\Chot\xxx\MCrRunB.ske",100,on,110);
		trigger(_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRLeft)
{
		file("pc\actors\Chot\xxx\MCrRunL.ske",100,on,110);
		trigger(_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRRight)
{
		file("pc\actors\Chot\xxx\MCrRunR.ske",100,on,110);
		trigger(_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRForwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunFL.ske",100,on,110);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRBackwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunBL.ske",100,on,110);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRForwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunFR.ske",100,on,110);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRBackwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunBR.ske",100,on,110);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchForward)
{
		file("pc\actors\Prost1\xxx\FCrWlkF.ske",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchBackward)
{
		file("pc\actors\Prost1\xxx\FCrWlkB.ske",100,on);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}


action(DomCrouchLeft)
{
		file("pc\actors\Prost1\xxx\FCrWlkL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchRight)
{
		//file("pc\actors\Chot\xxx\MCrStfR.ske",100,on);
		file("pc\actors\Prost1\xxx\FCrWlkR.ske",100,on);	//wait for gabe
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchForwardLeft)
{
		file("pc\actors\Prost1\xxx\FCrWlkFL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchBackwardLeft)
{
		file("pc\actors\Prost1\xxx\FCrWlkBL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchForwardRight)
{
		file("pc\actors\Prost1\xxx\FCrWlkFR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}

action(DomCrouchBackwardRight)
{
		file("pc\actors\Prost1\xxx\FCrWlkBR.ske",100,on);	//wait for gabe
		//file("pc\actors\Chot\xxx\MCrStRB.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomCrouchSpreadOut,DomCrouchIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	IDLE ACTIONS

Action(DomIdleCombatGun)
{
		file("pc\actors\Domina\xxx\DmCIdl1.ske",100,on);
		trigger(_noDIR|_DIRcombatmode|_DIRhavegun);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(DomSpread,DomStandShoot,DomTurnLeftCombat,DomTurnRightCombat,Domidle);
}

Action(DomIdleCombatNoGun)
{
		file("pc\actors\Domina\xxx\DmCIdl1.ske",100,on);
		trigger(_noDIR|_DIRcombatmode);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(DomSpread,DomStandShoot,DomTurnLeft,DomTurnRight,Domidle);
}

Action(DomIdleGun)
{
		file("pc\actors\Domina\xxx\DmIdl2.ske",30,on);//looking at fingernails
		file("pc\actors\Domina\xxx\DmIdl1.ske",65,on);//breathing
		file("pc\actors\Domina\xxx\DmIdl3.ske",100,on);//look left/right
		trigger(_noDIR|_DIRhavegun);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(DomSpread,DomStandShoot,DomTurnLeftCombat,DomTurnRightCombat,Domidle);
}

Action(DomIdleNoGun)
{
		file("pc\actors\Domina\xxx\DmIdl2.ske",30,on);//looking at fingernails
		file("pc\actors\Domina\xxx\DmIdl1.ske",65,on);//breathing
		file("pc\actors\Domina\xxx\DmIdl3.ske",100,on);//look left/right
		trigger(_allDIR);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(DomSpread,DomStandShoot,DomTurnLeft,DomTurnRight,Domidle);
}

Action(DomIdle)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(DomIdleCombatGun,DomIdleCombatNoGun,DomIdleGun,DomIdleNoGun);
}


action(DomIdleLongTime)
{
		file("pc\actors\Chot\xxx\mspan11p.ske",33,on);
		file("pc\actors\Chot\xxx\mspan14p.ske",66,on);
		file("pc\actors\Chot\xxx\mspan12p.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(DomSpread,DomStandShoot,DomTurnLeft,DomTurnRight,DomIdleLongTime,DomIdle);
}


action(DomIdleHitWall)	//used just after you bounce into a wall
{
		file("pc\actors\Chot\xxx\Mneidl2p.xxx",20,on);	//ass scratch
		file("pc\actors\Chot\xxx\Mneidl3p.xxx",40,on);	//crotch scratch
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(DomHitWallSpread);
}

action(DomIdleHitWallFront)	//used just after you bounce into a wall, face first
{
//MISSING Animation
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(DomHitWallStandShoot,DomHitWallTurnLeft,DomHitWallTurnRight,DomIdleHitWallFront);
}

action(DomHitWallStandShoot)
{
		file("pc\actors\chot\xxx\Mfire3h2.ske",100,on);
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		connections(DomHitWallSpreadOut);
}

action(DomHitWallSpread)	//Lead directly to next animation
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(DomIdleHitWall);
		connections(DomHitWallStandShoot,DomHitWallTurnLeft,DomHitWallTurnRight,DomIdleHitWall);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	ELECTRICUTIONS

action(DomElectricShock0)
{
		file("pc\actors\Chot\xxx\aelectLP.ske",100,off,130);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true)
		connections(DomElectricShock1);
		collision(on);
		gravity(off);
}

action(DomElectricShock1)
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,off);
		move(0,0,20);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(off);
		nomove(true)
		connections(DomElectricShock2);
		gravity(on);
		collision(on);
}

action(Domelectricshock2)
{
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);
		move(0,0,4);
		trigger(_DIRhorcol);
		nrintframes(6);
		break(off);
		connections(DomElectricShock3);
		collision(on);
}

action(DomElectricShock3)
{
		file("pc\actors\chot\xxx\Mkipup.ske",30,off,80);
		file("pc\actors\chot\xxx\mstndfbk.ske",100,off,110);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(DomIdle);
		collision(on);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	DEAHTS
action(DomFallDead)
{
		file("pc\actors\Chot\xxx\alndhard.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
}

action(DomCrawlDead)
{
		file("pc\actors\Chot\xxx\mcrwlfal.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
}

action(DomStandDead)
{
		file("pc\actors\Prost1\xxx\Fdeth1.ske",25,off);		//Sway fall on knees then to face:
		file("pc\actors\Prost1\xxx\Fdeth2.ske",50,off);		//Spin around and die on face:
		file("pc\actors\Prost1\xxx\Fdeth3.ske",75,off);		//Fall to knees and crawl a second before dying:
		file("pc\actors\Prost1\xxx\Fdeth4.ske",100,off);	//Collapse to knees and around to back:
		trigger(_allDIR);
		break(off);
		nrintframes(12);
}

action(DomPoleDead)
{
		file("pc\actors\Chot\xxx\Poldedlf.ske",50,off);
		file("pc\actors\Chot\xxx\Poldedlb.ske",100,off);
		//file("pc\actors\Chot\xxx\mbelly.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(31);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	BURNED, STEAMED AND BLIND
action(DomGettingBurned)	//When inside fire, moving head left and right
{
		file("pc\actors\chot\xxx\MBrnThrs.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(3);
		ydeltafromzeroframe(off);
		connections(DomBlindForward,DomBlindBackwards,DomGettingBurned);
}
action(DomBlindForward)		//Walk slowly forward both inside and outside fire
{
		file("pc\actors\chot\xxx\MBrnStgr.ske",100,on);
		trigger(_DIRforward);
		break(on);
		nrintframes(3);
		connections(DomBlindForward,DomBlindBackwards,DomBurnedIdle);
}

action(DomBlindBackwards)		//Walk slowly backwards both inside and outside fire
{
		file("pc\actors\chot\xxx\MBrnStbk.ske",100,on);
		trigger(_DIRbackward);
		break(on);
		nrintframes(3);
		connections(DomBlindForward,DomBlindBackwards,DomBurnedIdle);
}

action(DomBurnedIdle)	//Inside and Outside fire, idle
{
		file("pc\actors\chot\xxx\MBrnIdl.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(3);
		connections(DomBlindForward,DomBlindBackwards,DomBurnedIdle);
}

action(DomBurningRunInCircle)		//Running around in circle with the head on fire, then fall.
{
		file("pc\actors\chot\xxx\MBrnRnAr.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(DomBurningRollOnFloor);
}

action(DomBurningRollOnFloor)		//Roll on floor to extinguish fire
{
		file("pc\actors\chot\xxx\ABrnRoll.ske",100,on,80);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(DomSlowGetUpFace);
}

action(DomSlowGetUpFace)	//Get back up from the ground
{
		file("pc\actors\chot\xxx\Mstandf1.ske",100,on,100,-1,-1,Sub_GetUpClearThrown68);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(DomBurnedIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	CRAWLING, BEING DRAGGED
action(DomDragged)
{
		file("pc\actors\chot\xxx\MDrgFH_A.ske",100,off);
		file("pc\actors\chot\xxx\MDrgFH_B.ske",100,on);
		trigger(_allDIR);
		nrintframes(3);
		connections(DomDragged);
}
action(DomFallToCrawl)
{
		//file("pc\actors\chot\xxx\MBrn2Kns.ske",100,off);
		file("pc\actors\chot\xxx\MBrkleg.ske",100,off,50);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(DomCrawlIdle);
}

action(DomCrawlSpread)	//Lead directly to next animation
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(DomCrawlForward,DomCrawlBackwards,DomCrawlTurnLeft,DomCrawlTurnRight,DomCrawlIdle);
}

action(DomCrawlForward)
{
		file("pc\actors\chot\xxx\MCrwl2.ske",100,on);
		trigger(_DIRforward);
		break(on);
		nrintframes(8);
		connections(DomCrawlSpread);
}

action(DomCrawlBackwards)
{
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRbackward);
		break(on);
		nrintframes(8);
		connections(DomCrawlSpread);
}

action(DomCrawlTurnLeft)
{
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRright);
		trigger(_DIRleft);
		break(on);
		nomove(on);
		nrintframes(8);
		connections(DomCrawlSpread);
}

action(DomCrawlTurnRight)
{
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRright);
		break(on);
		nomove(on);
		nrintframes(8);
		connections(DomCrawlSpread);
}

action(DomCrawlIdle)
{
		file("pc\actors\chot\xxx\MCrlidl3.ske",80,on);
		file("pc\actors\chot\xxx\MCrwlcl2.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		connections(DomCrawlSpread);
}

action(DomOnPole)
{
		file("pc\actors\Chot\xxx\mback.ske",20,off);
		file("pc\actors\Chot\xxx\PolTwch1.ske",50,on);
		file("pc\actors\Chot\xxx\PolTwch2.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);
		connections(DomOnPole,DomPoleDead);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	CLIMBING
Action(Domclimbup)
{
		file("pc\actors\chot\xxx\MClmbWlS.ske",50,off,100);
		file("pc\actors\chot\xxx\MClmbWlF.ske",100,off,100);
		nrintframes(8);
		break(off);
		trigger(_allDIR);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomIdle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	RECOIL
action(DomHeavyRecoil)
{
		file("pc\actors\domina\xxx\dshpump.ske",100,on,100,_AIclassHipGun);
		file("pc\actors\domina\xxx\dshhevy.ske",100,on);

		trigger(_AllDIR);
		break(off);
		nrintframes(0);
		connections(DomSpreadGun,DomStandShoot,DomTurnLeftCombat,DomTurnRightCombat,DomIdle);
}

action(DomLightRecoil)	//Works as proxy because it has to be restarted if SpawnAction is called again
{
		trigger(_AllDIR);
		nrintframes(-1);
		connections(DomLightRecoil2);
}

action(DomLightRecoil2)
{
		//file("pc\actors\Prost1\xxx\dshoots.ske",100,on);

		file("pc\actors\domina\xxx\dshltr1.ske",25,on);
		file("pc\actors\domina\xxx\dshltr2.ske",50,on);
		file("pc\actors\domina\xxx\dshltr3.ske",75,on);
		file("pc\actors\domina\xxx\dshltr4.ske",100,on);

		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(0);
		connections(DomSpreadGun,DomLightRecoil2,DomStandShoot,DomTurnLeftCombat,DomTurnRightCombat,DomIdle);
}

action(DomThrowGrenade)
{
		file("pc\actors\Domina\xxx\dmthgrc.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(DomSpread,DomIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	POSSESION
action(DomPossesed)
{
		file("pc\actors\Prost1\xxx\mposs1.xxx",100,off);
		trigger(_DIRvercol);
//		gravity(off);
//		collision(off);

		nrintframes(4);

		break(off);
		connections(Domidle);
}

action(DomDepossesed)
{
		file("pc\actors\chot\xxx\Mstun1g.ske",50,on);
		file("pc\actors\chot\xxx\Mstun2g.ske",100,on);
		trigger(_DIRactorbulletcol);
		nrintframes(4);
		break(off);
		connections(Domidle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	SHOOTING

action(DomStandShoot)
{
		//file("pc\actors\Prost1\xxx\dshooth.ske",100,on);
		file("pc\actors\Domina\xxx\DmCIdl1.ske",100,on);
		trigger(_DIRshoot|_DIRHaveGun);
		break(on);
		nrintframes(4);
		connections(DomSpreadGun,DomStandShoot,DomTurnLeftCombat,DomTurnRightCombat,DomIdle);
}


action(DomRunShoot)
{
		file("pc\actors\Prost1\xxx\Frnshotg.xxx",100,on);
		trigger(_DIRshoot);
//		trigger(_DIRrunShoot);	//DOESNT EXIST
//		trigger(_allDIR);
		nrintframes(4);

		break(oN);
		connections(DomRunShoot,DomRun,DomStandShoot,Domidle);
}



/////////////////////////////////////////////////////////////////////////////////////////
// "TRON" MODE

Action(DominaGunInit)
{
		file("pc\actors\domina\xxx\GCStart.ske",100,off);
		trigger(_AllDIR);
		break(on);
		nrintframes(8);
		connections(DominaGunInit);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	WOUNDED
action(DomWoundLight)
{
		file("pc\actors\Domina\xxx\dmwnd1c.ske",33,off,100,-1,_DIRcombatmode);
		file("pc\actors\Domina\xxx\dmwnd2c.ske",66,off,100,-1,_DIRcombatmode);
		file("pc\actors\Domina\xxx\dmwnd3c.ske",100,off,100,-1,_DIRcombatmode);

		file("pc\actors\Prost1\xxx\fqkwund1.ske",25,off);
		file("pc\actors\Prost1\xxx\fqkwund2.ske",50,off);
		file("pc\actors\Prost1\xxx\fqkwund3.ske",75,off);
		file("pc\actors\Prost1\xxx\fqkwund4.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		break(on);
		collision(on);
		nrintframes(4);
		connections(DomSpread,DomStandShoot,DomWoundLight,DomTurnLeft,DomTurnRight,DomIdle);
}

action(DomWoundLightNoBreak)	//Identical to the one above except for break
{
		file("pc\actors\Chot\xxx\FstWnd1.ske",10,off);
		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
		//file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		break(off);
		collision(on);
		nrintframes(4);
		connections(DomSpread,DomStandShoot,DomWoundLight,DomTurnLeft,DomTurnRight,DomIdle);
}

action(DomWoundFlyBack1)	//Hold frame
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,off);
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(DomWoundFlyBack2);
}

action(DomWoundFlyBack2)	//Hitting wall+hold frame
{
		file("pc\actors\Chot\xxx\ThBkhtwl.ske",100,off);
		trigger(_DIRVerCol);
		break(on);
		collision(on);
		nrintframes(4);
		connections(DomWoundFlyBack3);
}
action(DomWoundFlyBack3)	//Land on ground
{
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);
		trigger(_DIRHorCol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(DomIdle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	STANDARD MOVES WITHOUT GUN

action(DomPickup)
{
		file("pc\actors\Prost1\xxx\FpickupG.ske",100,off);
		trigger(_DIRaction);
		nrintframes(4);
		break(off);
		connections(DomIdle);
}

action(DomPickupCrouch)
{
		file("pc\actors\Prost1\xxx\FCrPikUp.ske",100,off);
		trigger(_DIRaction);
		nrintframes(4);
		break(off);
		connections(Prost1CrouchIdle);
}


action(DomRunBack)
{
		file("pc\actors\domina\xxx\DmRnBNC.ske",100,on);
		offset(19);
		nrintframes(4);
		trigger(_DIRbackward);
		break(on);
//		gravity(off);
		connections(DomSpread,Domidle);
}

Action(Domrun)
{
		file("pc\actors\domina\xxx\DmRnFNC.ske",100,on);
		break(on);
		nrintframes(4);
		offset(2);

		trigger(_DIRforward);
		//loopframes(10,20);			//loopstartframe,loopendframe

		connections(DomSpread,Domidle);
}

action(DomRunL)
{
		file("pc\actors\domina\xxx\DmRnLNC.ske",100,on);
		offset(2);
		nrintframes(8);
		trigger(_DIRsideleft);
		break(on);
		connections(DomSpread,Domidle);
}
action(DomRunR)
{
		file("pc\actors\domina\xxx\DmRnRNC.ske",100,on);
		offset(2);
		nrintframes(8);
		trigger(_DIRsideright);
		break(on);
		connections(DomSpread,Domidle);
}

action(DomRunDiagFL)
{
		file("pc\actors\domina\xxx\DmRnFLNC.ske",100,on);
		offset(2)
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		connections(DomSpread,Domidle);
}
action(DomRunDiagFR)
{
		file("pc\actors\domina\xxx\DmRnFRNC.ske",100,on);
		offset(2);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		connections(DomSpread,Domidle);
}

action(DomRunDiagBL)
{
		file("pc\actors\domina\xxx\DmRnBLNC.ske",100,on);
		offset(19);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		nrintframes(4);
		connections(DomSpread,Domidle);
}

action(DomRunDiagBR)
{
		file("pc\actors\domina\xxx\DmRnBRNC.ske",100,on);
		offset(19);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		nrintframes(4);
		connections(DomSpread,Domidle);
}

Action(Domwalk)
{
		file("pc\actors\domina\xxx\dmwlkfn.ske",100,on);
		
		nrintframes(4);
		trigger(_DIRwalking|_DIRforward);
		//loopframes(10,20);										//loopstartframe,loopendframe
		break(on);

		connections(DomSpread,Domidle);
}

action(DomWalkBack)
{
		file("pc\actors\domina\xxx\dmwlkbn.ske",100,on);

		nrintframes(4);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		connections(DomSpread,Domidle);
}


action(DomWalkL)
{
		file("pc\actors\domina\xxx\dmwlkln.ske",100,on);

		nrintframes(4);
		rotate(-90);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		connections(DomSpread,DomIdle);
}

action(DomWalkR)
{
		file("pc\actors\domina\xxx\dmwlkrn.ske",100,on);
		nrintframes(4);
		rotate(90);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		connections(DomSpread,DomIdle);
}
action(DomWalkDiagFL)
{
		file("pc\actors\domina\xxx\dmwlkfln.ske",100,on);
		nrintframes(4);
		rotate(-45);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		connections(DomSpread,DomIdle);
}

action(DomWalkDiagFR)
{
		file("pc\actors\domina\xxx\dmwlkfrn.ske",100,on);
		nrintframes(4);
		rotate(45);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		connections(DomSpread,DomIdle);
}

action(DomWalkDiagBL)
{
		file("pc\actors\domina\xxx\dmwlkbln.ske",100,on);
		nrintframes(4);
		rotate(45)
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		connections(DomSpread,DomIdle);
}

action(DomWalkDiagBR)
{
		file("pc\actors\domina\xxx\dmwlkbrn.ske",100,on);
		nrintframes(4);
		rotate(-45)
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		connections(DomSpread,DomIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	STANDARD MOVES WITH GUN
action(DomWalkGun)
{
		file("pc\actors\domina\xxx\dmwlkfc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkfn.ske",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);
		offset(5);
		nrintframes(8);
		connections(DomSpreadGun,DomIdle);
}

action(DomWalkBackGun)
{
		file("pc\actors\domina\xxx\dmwlkbc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkbn.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(30);
		connections(DomSpreadGun,DomIdle);
}

action(DomWalkLGun)
{
		file("pc\actors\domina\xxx\dmwlklc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkln.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(14);
		connections(DomSpreadGun,DomIdle);
}

action(DomWalkRGun)
{
		file("pc\actors\domina\xxx\dmwlkrc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkrn.ske",100,on);
		nrintframes(8);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(0);
		connections(DomSpreadGun,DomIdle);
}

action(DomWalkDiagFLGun)
{
		file("pc\actors\domina\xxx\dmwlkflc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkfln.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		offset(15)
		connections(DomSpreadGun,DomIdle);
}

action(DomWalkDiagFRGun)
{
		file("pc\actors\domina\xxx\dmwlkfrc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkfrn.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		offset(30)
		connections(DomSpreadGun,DomIdle);
}

action(DomWalkDiagBLGun)
{
		file("pc\actors\domina\xxx\dmwlkblc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkbln.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(30)
		nrintframes(8);
		connections(DomSpreadGun,DomIdle);
}

action(DomWalkDiagBRGun)
{
		file("pc\actors\domina\xxx\dmwlkbrc.ske",100,on,100,-1,_DIRcombatmode);
		file("pc\actors\domina\xxx\dmwlkbrn.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(30)
		nrintframes(8);
		connections(DomSpreadGun,DomIdle);
}

action(DomRunGun)
{
		file("pc\actors\Prost1\xxx\frunsht.ske",100,on);
		trigger(_DIRforward);
		break(on);
		offset(8)
		nrintframes(8);
		connections(DomSpreadGun,DomIdle);
}

action(DomRunBackGun)
{
		file("pc\actors\Prost1\xxx\frunbfst.ske",100,on);
		nrintframes(8);
		trigger(_DIRbackward);
		break(on);
		offset(13)
		connections(DomSpreadGun,DomIdle);
}

action(DomRunLGun)
{
		file("pc\actors\Prost1\xxx\fshrn90l.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideleft);
		break(on);
		offset(10)
		connections(DomSpreadGun,DomIdle);
}

action(DomRunRGun)
{
		file("pc\actors\Prost1\xxx\fshrn90r.ske",100,on);
		nrintframes(8);
		trigger(_DIRsideright);
		break(on);
		offset(9)
		connections(DomSpreadGun,DomIdle);
}

action(DomRunDiagFLGun)
{
		file("pc\actors\Prost1\xxx\fshrn45l.ske",100,on);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(9)
		nrintframes(8);
		connections(DomSpreadGun,DomIdle);
}

action(DomRunDiagFRGun)
{
		file("pc\actors\Prost1\xxx\fshrn45r.ske",100,on);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(10)
		nrintframes(8);
		connections(DomSpreadGun,DomIdle);
}

action(DomRunDiagBLGun)
{
		file("pc\actors\Prost1\xxx\fsrnb45l.ske",100,on);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		nrintframes(8)
		offset(13)
		connections(DomSpreadGun,DomIdle);
}

action(DomRunDiagBRGun)
{
		file("pc\actors\Prost1\xxx\fsrnb45r.ske",100,on);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(13)
		nrintframes(8);
		connections(DomSpreadGun,DomIdle);
}


action(DomHitWall)
{
		//file("pc\actors\Prost1\xxx\fwallg.xxx",100,off);
		file("pc\actors\Chot\xxx\mwundg.xxx",100,off);

		trigger(_DIRvercol);
		break(off);
		nrintframes(4);

//		gravity(off);
//		collision(off);
		connections(Domidle);
}

action(DomDance)
{
		file("pc\actors\Prost1\xxx\vidle.xxx",100,off);
		nrintframes(4);
		trigger(_allDIR);
		connections(Domidle);
}

action(DomDance2)
{
		//file("pc\actors\Prost1\ske\Titwkcy.ske");
		file("pc\actors\Prost1\xxx\Fpcsp1p.xxx",100,off);
		nrintframes(4);
		trigger(_allDIR);
		connections(Domidle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	TURNING

action(DomTurnLeftCombat)
{
		file("pc\actors\Prost1\xxx\FTrLStCm.ske",100,off,100);//Dom start turn left
		file("pc\actors\Prost1\xxx\FTrLLpCm.ske",100,on,100);//Dom turn left loop
		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(4);
		connections(DomSpread,DomStandShoot,DomTurnLeftCombat,DomTurnRightCombat,DomIdle);
}

action(DomTurnRightCombat)
{
		file("pc\actors\Prost1\xxx\FTrRStCm.ske",100,off,100);//Dom start turn right
		file("pc\actors\Prost1\xxx\FTrRLpCm.ske",100,on,100);//Dom turn right loop
		move(-2,0,0);
		trigger(_DIRright);
		break(on);
		nrintframes(4);
		connections(DomSpread,DomStandShoot,DomTurnLeftCombat,DomTurnRightCombat,DomIdle);
}

action(DomTurnLeft) //NON-COMBAT
{
		file("pc\actors\Domina\xxx\DTrLStNc.ske",100,off,100);//Dom start turn left
		file("pc\actors\Domina\xxx\DTrLLpNc.ske",100,on,100);//Dom turn left loop
		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(4);
		connections(DomSpread,DomStandShoot,DomTurnLeft,DomTurnRight,DomIdle);
}

action(DomTurnRight) //NON-COMBAT
{
		file("pc\actors\Domina\xxx\DTrRStNc.ske",100,off,100);//Dom start turn right
		file("pc\actors\Domina\xxx\DTrRLpNc.ske",100,on,100);//Dom turn right loop
		move(-2,0,0);
		trigger(_DIRright);
		break(on);
		nrintframes(4);
		connections(DomSpread,DomStandShoot,DomTurnLeft,DomTurnRight,DomIdle);
}

action(DomHitWallTurnLeft)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(DomHitWallSpread);
}

action(DomHitWallTurnRight)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(-2,0,0)
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(DomHitWallSpread);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	JUMP AND FALL

action(DomJump) //Lead directly to next animation
{
	trigger(_DIRjump);
	nrintframes(-1);
	connections(DomJumpBL,DomJumpBR,DomJumpBackwards,DomJumpFL,DomJumpL,DomJumpFR,DomJumpR,DomJumpForward,DomJumpInPlace);
}

action(DomJumpInPlace)
{
		file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
//		file("pc\actors\chot\xxx\mjinpl4a.ske",100,off,100);
//		file("pc\actors\Chot\xxx\MJinPl4b.ske",100,off,100);		//Second Part
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomFallInplace);
}

action(DomJumpForward)
{
	file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
	trigger(_DIRforward);
	nrintframes(3);
	break(off);
	gravity(off);
	ydeltafromzeroframe(off);
	connections(DomFallForward);
}

action(DomJumpL)
{
		file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRsideleft);
		rotate(-90)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomFallL);
}

action(DomJumpFL)
{
		file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRsideleft|_DIRforward);
		rotate(-45)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomFallFL);
}
action(DomJumpR)
{
		file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRsideright);
		rotate(90)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomFallR);
}

action(DomJumpFR)
{
		file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRsideright|_DIRforward);
		rotate(45)
		nrintframes(5);
		offset(3)
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomFallFR);
}

action(DomJumpBackwards)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
//		file("pc\actors\chot\xxx\arnbkjmb.ske",100,off,100);
		trigger(_DIRbackward);
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomFallBackwards);
}

action(DomJumpBR)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
//		file("pc\actors\chot\xxx\arnbkjmb.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideright);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(-45)
		ydeltafromzeroframe(off);
		connections(DomFallBR);
}

action(DomJumpBL)
{
		file("pc\actors\chot\xxx\arnbkjms.ske",100,off,100);
//		file("pc\actors\chot\xxx\arnbkjmb.ske",100,off,100);
		trigger(_DIRbackward|_DIRsideleft);
		nrintframes(5);
		break(off);
		gravity(off);
		rotate(45)
		ydeltafromzeroframe(off);
		connections(DomFallBL);
}


action(DomfallForward)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		connections(DomfallForward);
}

action(DomfallFL)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(DomfallFL);
}
action(DomfallFR)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(DomfallFR);
}
action(DomfallL)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-90)
		connections(DomfallL);
}
action(DomfallR)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(90)
		connections(DomfallR);
}

action(DomfallInPlace)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJinPl4b.ske",100,off,100);
//		file("pc\actors\Chot\xxx\MJinPl4c.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(DomfallInPlace);
}

action(DomfallBackwards)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(DomfallBackwards);
}
action(DomfallBL)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(DomfallBL);
}
action(DomfallBR)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(DomfallBR);
}

action(Domfall)	//Fall when falling from edge only
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(7);
		offset(8);
		ydeltafromzeroframe(off);
		break(on);
		connections(DomFall);
}

action(DomTouchDown)
{
		file("pc\actors\Chot\xxx\mjmp4mg.ske",30,on);
		file("pc\actors\Chot\xxx\mjmp4lg.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		nrintframes(5);
		break(on);
		connections(DomSpread,DomStandShoot,DomTouchDown,DomIdle);
}

action(DomRunUpStairs)
{
		file("pc\actors\Prost1\xxx\FRnStar2.ske",100,on);
		trigger(_DIRforward);
		break(off);
//		offset(4);
		nrintframes(8);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(DomRunUpStairs);
}


action(DomPressGun)
{
	file("pc\actors\Prost1\xxx\FTchButn.ske",100,off);
	trigger(_DIRaction);
	nrintframes(4);
	connections(Domidle);
	nomove(true);
}

//	PROST THROWN ACTIONS
//

action(DomThrownBack)
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,on);	//Backwards hold frame
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(DomThrownBackLand,DomThrownBack);
}

action(DomThrownBackLand)
{
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);	//Backwards, land on back
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(DomGetUpFromBack,DomThrownBackLand);
}

action(DomThrownForward)
{
		file("pc\actors\Chot\xxx\ThfwHld1.ske",100,on);	//Forward hold frame
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(DomThrownForwardLand,DomThrownForward);
}

action(DomThrownForwardLand)
{
		file("pc\actors\Chot\xxx\ThFwLnd.ske",100,off);		//forward, land face down, and get up (gabe)
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(DomGetUpFromFrontFaceDown,DomThrownForwardLand);
}

action(DomThrownRight)
{
		file("pc\actors\Chot\xxx\ThrnHldR.ske",100,on);	//Right Hold frame #1
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(DomThrownRightLand,DomThrownRight);
}

action(DomThrownRightLand)
{
		file("pc\actors\Chot\xxx\ThrnRite.ske",100,off);	//Right land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(0);
		connections(DomGetUpFromRightFaceDown,DomThrownRightLand);
}

action(DomThrownLeft)
{
		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(DomThrownLeftLand,DomThrownLeft);
}

action(DomThrownLeftLand)
{
		file("pc\actors\Chot\xxx\Thrnleft.ske",100,off);	//Left land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(0);
		connections(DomGetUpFromLeftFaceDown,DomThrownLeftLand);
}

action(DomGetUpFromBack)
{
		file("pc\actors\chot\xxx\mstndfbk.ske",100,off,110,-1,-1,Sub_GetUpClearThrown84);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(4);
		connections(DomIdle);
}

action(DomGetUpFromFrontFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(0);
		connections(DomIdle);
}

action(DomGetUpFromBackFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(180);
		break(off);
		collision(on);
		nrintframes(0);
		connections(DomIdle);
}

action(DomGetUpFromRightFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(DomIdle);
}

action(DomGetUpFromLeftFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(-90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(DomIdle);
}
