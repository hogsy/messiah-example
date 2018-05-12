




/*
action(SubGirlJumpStart)			//short "tapped" jump, use light landing after
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_AllDir);
		nrintframes(3);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpUpwards);
}

action(SubGirlJumpUpwards)			//thrust upwards, hold last frame while going up..up..up
{
		file("pc\actors\Subgirl1\xxx\SgJmpB.ske",100,off,100);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlJumpDownwards);
}

action(SubGirlJumpDownwards)		//no more thrust, hold last until land
{
		file("pc\actors\Subgirl1\xxx\SgJmpC.ske",100,off,100);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlJumpLand);
}

action(SubGirlJumpLandInCombat)		//heavy landing in combat mode
{
		file("pc\actors\Subgirl1\xxx\SgJmpLn2.ske",100,off,100);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlIdle);
}

action(SubGirlJumpLand)				//heavy landing in noncombat mode
{
		file("pc\actors\Subgirl1\xxx\SgJmpLn3.ske",100,off,100);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlIdle);
}
*/









///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////





action(SubGirlSpread)	//Lead directly to next animation
{
		trigger(_DIRMove);
		nrintframes(-1);
		connections(SubGirlWalkDiagFL,SubGirlWalkDiagFR,SubGirlWalkDiagBL,SubGirlWalkDiagBR,SubGirlWalk,SubGirlWalkBack,SubGirlWalkL,SubGirlWalkR,SubGirlRunDiagFL,SubGirlRunDiagFR,SubGirlRunDiagBL,SubGirlRunDiagBR,SubGirlrun,SubGirlRunBack,SubGirlRunL,SubGirlRunR);
}

action(SubGirlCrouchWoundLight)
{
		file("pc\actors\Chot\xxx\MCrWnd1.ske",10,off);	//Head.    
		file("pc\actors\Chot\xxx\MCrWnd2.ske",100,off);	//Stomach/chest. 
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}
     
action(SubGirlCrouchDead)
{
		file("pc\actors\Chot\xxx\McrDeth1.ske",100,off);	//Throw back from chest hit. Die on back.  
		trigger(_allDIR);
		break(off);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		nrintframes(8);
}

action(SubGirlCrouchDown)
{
		file("pc\actors\prost1\xxx\FCrStart.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchIdle);
}

action(SubGirlCrouchUp)
{
		file("pc\actors\prost1\xxx\FCrEnd.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlSpread,SubGirlIdle);
}

action(SubGirlCrouchDownCombat)
{
		file("pc\actors\prost1\xxx\FCrStrCm.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchIdle);
}

action(SubGirlCrouchUpCombat)
{
		file("pc\actors\prost1\xxx\FCrEndCm.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlSpread,SubGirlIdle);
}

action(SubGirlCrouchGrenade)
{
		file("pc\actors\prost1\xxx\FCrTrGrn.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchIdle)
{
		file("pc\actors\prost1\xxx\FCrIdle.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchSpreadOut)
{
		file("pc\actors\prost1\xxx\FCrIdle.ske",100,on);
		trigger(_DIRmove);
		nrintframes(-1);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchForwardLeft,SubGirlCrouchForwardRight,SubGirlCrouchBackwardLeft,SubGirlCrouchBackwardRight,SubGirlCrouchForward,SubGirlCrouchBackward,SubGirlCrouchLeft,SubGirlCrouchRight,SubGirlCrouchRForwardLeft,SubGirlCrouchRForwardRight,SubGirlCrouchRBackwardLeft,SubGirlCrouchRBackwardRight,SubGirlCrouchRForward,SubGirlCrouchRBackward,SubGirlCrouchRLeft,SubGirlCrouchRRight);
}

action(SubGirlCrouchRForward)
{
		file("pc\actors\Chot\xxx\MCrRunF.ske",100,on,110);
		trigger(_DIRforward);
		break(on);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRBackward)
{
		file("pc\actors\Chot\xxx\MCrRunB.ske",100,on,110);
		trigger(_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRLeft)
{
		file("pc\actors\Chot\xxx\MCrRunL.ske",100,on,110);
		trigger(_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRRight)
{
		file("pc\actors\Chot\xxx\MCrRunR.ske",100,on,110);
		trigger(_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRForwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunFL.ske",100,on,110);
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRBackwardLeft)
{
		file("pc\actors\Chot\xxx\MCrRunBL.ske",100,on,110);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRForwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunFR.ske",100,on,110);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRBackwardRight)
{
		file("pc\actors\Chot\xxx\MCrRunBR.ske",100,on,110);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		soundlevel(100);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchForward)
{
		file("pc\actors\prost1\xxx\FCrWlkF.ske",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchBackward)
{
		file("pc\actors\prost1\xxx\FCrWlkB.ske",100,on);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}


action(SubGirlCrouchLeft)
{
		file("pc\actors\prost1\xxx\FCrWlkL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchRight)
{
		//file("pc\actors\Chot\xxx\MCrStfR.ske",100,on);
		file("pc\actors\prost1\xxx\FCrWlkR.ske",100,on);	//wait for gabe
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchForwardLeft)
{
		file("pc\actors\prost1\xxx\FCrWlkFL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchBackwardLeft)
{
		file("pc\actors\prost1\xxx\FCrWlkBL.ske",100,on);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchForwardRight)
{
		file("pc\actors\prost1\xxx\FCrWlkFR.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

action(SubGirlCrouchBackwardRight)
{
		file("pc\actors\prost1\xxx\FCrWlkBR.ske",100,on);	//wait for gabe
		//file("pc\actors\Chot\xxx\MCrStRB.ske",100,on);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		offset(12);
		nrintframes(4);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlCrouchSpreadOut,SubGirlCrouchIdle);
}

Action(SubGirlIdleCombatNoGun)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Cm.ske",100,on);
		trigger(_noDIR|_DIRcombatmode);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(SubGirlSpread,SubGirlTurnLeft,SubGirlTurnRight,SubGirlidle);
}

Action(SubGirlIdleNoGun)
{
		file("pc\actors\Subgirl1\xxx\SgIdl1Nc.ske",50,on);
		file("pc\actors\Subgirl1\xxx\SgIdl2Nc.ske",100,on);
		trigger(_allDIR);

		nrintframes(4);
		intforloop(on);
		break(on);
		connections(SubGirlSpread,SubGirlTurnLeft,SubGirlTurnRight,SubGirlidle);
}

Action(SubGirlIdle)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(SubGirlKickMale,SubGirlIdleCombatNoGun,SubGirlIdleNoGun);
}

action(SubGirlIdleLongTime)
{
		file("pc\actors\Chot\xxx\mspan11p.ske",33,on);
		file("pc\actors\Chot\xxx\mspan14p.ske",66,on);
		file("pc\actors\Chot\xxx\mspan12p.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		break(on);
		nrintframes(8);
		intforloop(on);
		connections(SubGirlSpread,SubGirlTurnLeft,SubGirlTurnRight,SubGirlIdleLongTime,SubGirlIdle);
}


action(SubGirlIdleHitWall)	//used just after you bounce into a wall
{
		file("pc\actors\Chot\xxx\Mneidl2p.xxx",20,on);	//ass scratch
		file("pc\actors\Chot\xxx\Mneidl3p.xxx",40,on);	//crotch scratch
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(SubGirlHitWallSpread);
}

action(SubGirlIdleHitWallFront)	//used just after you bounce into a wall, face first
{
//MISSING Animation
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);	//look around
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		nomove(true)
		connections(SubGirlHitWallTurnLeft,SubGirlHitWallTurnRight,SubGirlIdleHitWallFront);
}

action(SubGirlHitWallSpread)	//Lead directly to next animation
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(SubGirlIdleHitWall);
		connections(SubGirlHitWallTurnLeft,SubGirlHitWallTurnRight,SubGirlIdleHitWall);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	ELECTRICUTIONS

action(SubGirlElectricShock0)
{
		file("pc\actors\Chot\xxx\aelectLP.ske",100,off,130);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(off);
		nomove(true)
		connections(SubGirlElectricShock1);
		collision(on);
		gravity(off);
}

action(SubGirlElectricShock1)
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,off);
		move(0,0,20);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(off);
		nomove(true)
		connections(SubGirlElectricShock2);
		gravity(on);
		collision(on);
}

action(SubGirlelectricshock2)
{
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);
		move(0,0,4);
		trigger(_DIRhorcol);
		nrintframes(6);
		break(off);
		connections(SubGirlElectricShock3);
		collision(on);
}

action(SubGirlElectricShock3)
{
		file("pc\actors\chot\xxx\Mkipup.ske",30,off,80);
		file("pc\actors\chot\xxx\mstndfbk.ske",100,off,110);
		trigger(_allDIR);
		break(off);
		nrintframes(8);
		connections(SubGirlIdle);
		collision(on);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	DEAHTS
action(SubGirlFallDead)
{
		file("pc\actors\Chot\xxx\alndhard.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
}

action(SubGirlCrawlDead)
{
		file("pc\actors\Chot\xxx\mcrwlfal.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
}

action(SubGirlStandDead)
{
		file("pc\actors\Chot\xxx\mded1g.ske",20,off);	//Face down
		file("pc\actors\Chot\xxx\mded2g.ske",40,off);	//Face up
		file("pc\actors\Chot\xxx\mded3g.ske",60,off);	//Face up
		file("pc\actors\Chot\xxx\mded4g.ske",80,off);	//On side
		file("pc\actors\Chot\xxx\mded5g.ske",100,off);	//face down
//MISSING: This causes an error, because anim does not stop when it selects MDED1, 2, 3 or 4
		trigger(_allDIR);
		break(off);
		nrintframes(12);
}

action(SubGirlPoleDead)
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
action(SubGirlGettingBurned)	//When inside fire, moving head left and right
{
		file("pc\actors\chot\xxx\MBrnThrs.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(3);
		ydeltafromzeroframe(off);
		connections(SubGirlBlindForward,SubGirlBlindBackwards,SubGirlGettingBurned);
}
action(SubGirlBlindForward)		//Walk slowly forward both inside and outside fire
{
		file("pc\actors\chot\xxx\MBrnStgr.ske",100,on);
		trigger(_DIRforward);
		break(on);
		nrintframes(3);
		connections(SubGirlBlindForward,SubGirlBlindBackwards,SubGirlBurnedIdle);
}

action(SubGirlBlindBackwards)		//Walk slowly backwards both inside and outside fire
{
		file("pc\actors\chot\xxx\MBrnStbk.ske",100,on);
		trigger(_DIRbackward);
		break(on);
		nrintframes(3);
		connections(SubGirlBlindForward,SubGirlBlindBackwards,SubGirlBurnedIdle);
}

action(SubGirlBurnedIdle)	//Inside and Outside fire, idle
{
		file("pc\actors\chot\xxx\MBrnIdl.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(3);
		connections(SubGirlBlindForward,SubGirlBlindBackwards,SubGirlBurnedIdle);
}

action(SubGirlBurningRunInCircle)		//Running around in circle with the head on fire, then fall.
{
		file("pc\actors\chot\xxx\MBrnRnAr.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(SubGirlBurningRollOnFloor);
}

action(SubGirlBurningRollOnFloor)		//Roll on floor to extinguish fire
{
		file("pc\actors\chot\xxx\ABrnRoll.ske",100,on,80);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(SubGirlSlowGetUpFace);
}

action(SubGirlSlowGetUpFace)	//Get back up from the ground
{
		file("pc\actors\chot\xxx\Mstandf1.ske",100,on,100,-1,-1,Sub_GetUpClearThrown68);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(SubGirlBurnedIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	CRAWLING, BEING DRAGGED
action(SubGirlDragged)
{
		file("pc\actors\chot\xxx\MDrgFH_A.ske",100,off);
		file("pc\actors\chot\xxx\MDrgFH_B.ske",100,on);
		trigger(_allDIR);
		nrintframes(3);
		connections(SubGirlDragged);
}
action(SubGirlFallToCrawl)
{
		//file("pc\actors\chot\xxx\MBrn2Kns.ske",100,off);
		file("pc\actors\chot\xxx\MBrkleg.ske",100,off,50);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(SubGirlCrawlIdle);
}

action(SubGirlCrawlSpread)	//Lead directly to next animation
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(SubGirlCrawlForward,SubGirlCrawlBackwards,SubGirlCrawlTurnLeft,SubGirlCrawlTurnRight,SubGirlCrawlIdle);
}

action(SubGirlCrawlForward)
{
		file("pc\actors\chot\xxx\MCrwl2.ske",100,on);
		trigger(_DIRforward);
		break(on);
		nrintframes(8);
		connections(SubGirlCrawlSpread);
}

action(SubGirlCrawlBackwards)
{
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRbackward);
		break(on);
		nrintframes(8);
		connections(SubGirlCrawlSpread);
}

action(SubGirlCrawlTurnLeft)
{
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRright);
		trigger(_DIRleft);
		break(on);
		nomove(on);
		nrintframes(8);
		connections(SubGirlCrawlSpread);
}

action(SubGirlCrawlTurnRight)
{
		file("pc\actors\chot\xxx\MCrwlbk.ske",100,on);
		trigger(_DIRright);
		break(on);
		nomove(on);
		nrintframes(8);
		connections(SubGirlCrawlSpread);
}

action(SubGirlCrawlIdle)
{
		file("pc\actors\chot\xxx\MCrlidl3.ske",80,on);
		file("pc\actors\chot\xxx\MCrwlcl2.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		connections(SubGirlCrawlSpread);
}

action(SubGirlOnPole)
{
		file("pc\actors\Chot\xxx\mback.ske",20,off);
		file("pc\actors\Chot\xxx\PolTwch1.ske",50,on);
		file("pc\actors\Chot\xxx\PolTwch2.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);
		connections(SubGirlOnPole,SubGirlPoleDead);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	CLIMBING
Action(SubGirlclimbup)
{
		file("pc\actors\chot\xxx\MClmbWlS.ske",50,off,100);
		file("pc\actors\chot\xxx\MClmbWlF.ske",100,off,100);
		nrintframes(8);
		break(off);
		trigger(_allDIR);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlIdle);
}


action(SubGirlThrowGrenade)
{
		file("pc\actors\Domina\xxx\dmthgrc.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(0);
		ColSphereScale(50);
		ColSphereYOffsetScale(100);
		connections(SubGirlSpread,SubGirlIdle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	POSSESION
action(SubGirlPossesed)
{
		file("pc\actors\prost1\xxx\mposs1.xxx",100,off);
		trigger(_DIRvercol);
//		gravity(off);
//		collision(off);

		nrintframes(4);

		break(off);
		connections(SubGirlidle);
}

action(SubGirlDepossesed)
{
		file("pc\actors\chot\xxx\Mstun1g.ske",50,on);
		file("pc\actors\chot\xxx\Mstun2g.ske",100,on);
		trigger(_DIRactorbulletcol);
		nrintframes(4);
		break(off);
		connections(SubGirlidle);
}


/////////////////////////////////////////////////////////////////////////////////////////
//	WOUNDED
action(SubGirlWoundLight)
{
		file("pc\actors\Domina\xxx\dmwnd1c.ske",33,off,100,-1,_DIRcombatmode);
		file("pc\actors\Domina\xxx\dmwnd2c.ske",66,off,100,-1,_DIRcombatmode);
		file("pc\actors\Domina\xxx\dmwnd3c.ske",100,off,100,-1,_DIRcombatmode);

		file("pc\actors\prost1\xxx\fqkwund1.ske",25,off);
		file("pc\actors\prost1\xxx\fqkwund2.ske",50,off);
		file("pc\actors\prost1\xxx\fqkwund3.ske",75,off);
		file("pc\actors\prost1\xxx\fqkwund4.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		break(on);
		collision(on);
		nrintframes(4);
		connections(SubGirlSpread,SubGirlWoundLight,SubGirlTurnLeft,SubGirlTurnRight,SubGirlIdle);
}

action(SubGirlWoundLightNoBreak)	//Identical to the one above except for break
{
		file("pc\actors\Chot\xxx\FstWnd1.ske",10,off);
		file("pc\actors\Chot\xxx\FstWnd2.ske",100,off);
		//file("pc\actors\Chot\xxx\FstWnd3.ske",100,off);
		trigger(_DIRNotEndOfAnim);
		break(off);
		collision(on);
		nrintframes(4);
		connections(SubGirlSpread,SubGirlWoundLight,SubGirlTurnLeft,SubGirlTurnRight,SubGirlIdle);
}

action(SubGirlWoundFlyBack1)	//Hold frame
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,off);
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(SubGirlWoundFlyBack2);
}

action(SubGirlWoundFlyBack2)	//Hitting wall+hold frame
{
		file("pc\actors\Chot\xxx\ThBkhtwl.ske",100,off);
		trigger(_DIRVerCol);
		break(on);
		collision(on);
		nrintframes(4);
		connections(SubGirlWoundFlyBack3);
}
action(SubGirlWoundFlyBack3)	//Land on ground
{
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);
		trigger(_DIRHorCol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(SubGirlIdle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	STANDARD MOVES WITHOUT GUN

action(SubGirlRunBack)
{
		file("pc\actors\Subgirl1\xxx\SgRunB.ske",100,on);
		offset(9);
		nrintframes(4);
		trigger(_DIRbackward);
		break(on);
		connections(SubGirlSpread,SubGirlidle);
		move(0,0,16);
}

Action(SubGirlrun)
{
		file("pc\actors\Subgirl1\xxx\SgRunF.ske",100,on);
		break(on);
		nrintframes(4);
		offset(2);
		trigger(_DIRforward);
		connections(SubGirlSpread,SubGirlidle);
		move(0,0,-16);
}

action(SubGirlRunL)
{
		file("pc\actors\prost1\xxx\PRunL.ske",100,on);
		offset(2);
		nrintframes(8);
		trigger(_DIRsideleft);
		break(on);
		connections(SubGirlSpread,SubGirlidle);
}
action(SubGirlRunR)
{
		file("pc\actors\prost1\xxx\PRunR.ske",100,on);
		offset(2);
		nrintframes(8);
		trigger(_DIRsideright);
		break(on);
		connections(SubGirlSpread,SubGirlidle);
}

action(SubGirlRunDiagFL)
{
		file("pc\actors\prost1\xxx\PRunFL.ske",100,on);
		offset(2)
		trigger(_DIRsideleft|_DIRforward);
		break(on);
		nrintframes(8);
		connections(SubGirlSpread,SubGirlidle);
}
action(SubGirlRunDiagFR)
{
		file("pc\actors\prost1\xxx\PRunFR.ske",100,on);
		offset(2);
		trigger(_DIRsideright|_DIRforward);
		break(on);
		nrintframes(8);
		connections(SubGirlSpread,SubGirlidle);
}

action(SubGirlRunDiagBL)
{
		file("pc\actors\prost1\xxx\PRunBL.ske",100,on);
		offset(9);
		trigger(_DIRsideleft|_DIRbackward);
		break(on);
		nrintframes(4);
		connections(SubGirlSpread,SubGirlidle);
}

action(SubGirlRunDiagBR)
{
		file("pc\actors\prost1\xxx\PRunBR.ske",100,on);
		offset(9);
		trigger(_DIRsideright|_DIRbackward);
		break(on);
		nrintframes(4);
		connections(SubGirlSpread,SubGirlidle);
}

Action(SubGirlwalk)
{
		file("pc\actors\Subgirl1\xxx\SgWlkFNc.ske",100,on);
		
		offset(3);
		nrintframes(4);
		trigger(_DIRwalking|_DIRforward);
		//loopframes(10,20);										//loopstartframe,loopendframe
		break(on);

		connections(SubGirlSpread,SubGirlidle);
}

action(SubGirlWalkBack)
{
//		file("pc\actors\prost1\xxx\PWlkB.ske",100,on);
		file("pc\actors\Subgirl1\xxx\SgWlkBNc.ske",100,on);

		offset(18);
		nrintframes(4);
		trigger(_DIRwalking|_DIRbackward);
		break(on);
		connections(SubGirlSpread,SubGirlidle);
}


action(SubGirlWalkL)
{
		file("pc\actors\prost1\xxx\PWlkL.ske",100,on);

		offset(3);
		nrintframes(4);
		trigger(_DIRwalking|_DIRsideleft);
		break(on);
		connections(SubGirlSpread,SubGirlIdle);
}

action(SubGirlWalkR)
{
		file("pc\actors\prost1\xxx\PWlkR.ske",100,on);
		nrintframes(4);
		offset(3);
		trigger(_DIRwalking|_DIRsideright);
		break(on);
		connections(SubGirlSpread,SubGirlIdle);
}
action(SubGirlWalkDiagFL)
{
		file("pc\actors\prost1\xxx\PWlkFL.ske",100,on);
		nrintframes(4);
		offset(3);
		trigger(_DIRwalking|_DIRsideleft|_DIRforward);
		break(on);
		connections(SubGirlSpread,SubGirlIdle);
}

action(SubGirlWalkDiagFR)
{
		file("pc\actors\prost1\xxx\PWlkFR.ske",100,on);
		nrintframes(4);
		offset(3);
		trigger(_DIRwalking|_DIRsideright|_DIRforward);
		break(on);
		connections(SubGirlSpread,SubGirlIdle);
}

action(SubGirlWalkDiagBL)
{
		file("pc\actors\prost1\xxx\PWlkBL.ske",100,on);
		nrintframes(4);
		offset(18);
		trigger(_DIRwalking|_DIRsideleft|_DIRbackward);
		break(on);
		connections(SubGirlSpread,SubGirlIdle);
}

action(SubGirlWalkDiagBR)
{
		file("pc\actors\prost1\xxx\PWlkBR.ske",100,on);
		nrintframes(4);
		offset(18);
		trigger(_DIRwalking|_DIRsideright|_DIRbackward);
		break(on);
		connections(SubGirlSpread,SubGirlIdle);
}




action(SubGirlHitWall)
{
		//file("pc\actors\SubGirl\xxx\fwallg.xxx",100,off);
		file("pc\actors\Chot\xxx\mwundg.xxx",100,off);

		trigger(_DIRvercol);
		break(off);
		nrintframes(4);

//		gravity(off);
//		collision(off);
		connections(SubGirlidle);
}

/////////////////////////////////////////////////////////////////////////////////////////
//	TURNING

action(SubGirlTurnLeft)
{
		file("pc\actors\prost1\xxx\FTrnLeft.ske",100,on);
		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(SubGirlSpread,SubGirlTurnLeft,SubGirlTurnRight,SubGirlIdle);
}

action(SubGirlTurnRight)
{
		file("pc\actors\prost1\xxx\FTrnRigt.ske",100,on);
		move(-2,0,0);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(SubGirlSpread,SubGirlTurnLeft,SubGirlTurnRight,SubGirlIdle);
}

action(SubGirlHitWallTurnLeft)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(2,0,0);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		connections(SubGirlHitWallSpread);
}

action(SubGirlHitWallTurnRight)
{
		file("pc\actors\Chot\xxx\mtrnlft2.ske",100,on);
		move(-2,0,0)
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		connections(SubGirlHitWallSpread);
}

action(SubGirlKickMale)
{
		file("pc\actors\Subgirl1\xxx\SgKik1.ske",100,on,100);	//side kick
		file("pc\actors\Subgirl1\xxx\SgPnch1.ske",100,on,100);	//Big right cross/uppercut

		flag(_SXAAalignmovingslave);

		AlignAngle(0);
		TargetAngle(180);
		AttackHeight(50);
		AlignDistance(100);
		AlignSlack(20);	
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(12);
		DamageFrame(12);
		Power(10);
		AttachAction(CopThrownSpinLink);
		TargetAIClass(_AIclassmale);

		ActionSubRoutine(Sub_RandomPunchedSFX);

		trigger(_DIRshoot);
		break(off);
		nrintframes(4);
		connections(SubGirlIdle);
}



/////////////////////////////////////////////////////////////////////////////////////////
//	JUMP AND FALL
action(SubGirlJump) //Lead directly to next animation
{
		trigger(_DIRjump);
		AIClass(_AIclassSubgirl);
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
		connections(SubGirlFallInplace);
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
		connections(SubGirlJumpHigh,SubGirlFallInplace);
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
		connections(SubGirlFallR);
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
		connections(SubGirlJumpHighR,SubGirlFallR);
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
		connections(SubGirlFallL);
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
		connections(SubGirlJumpHighL,SubGirlFallL);
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
		connections(SubGirlFallFR);
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
		connections(SubGirlJumpHigh45R,SubGirlFallFR);
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
		connections(SubGirlFallFL);
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
		connections(SubGirlJumpHigh45L,SubGirlFallFL);
}

action(SubGirlJumpInPlace)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		//file("pc\actors\chot\xxx\mjinplc5.ske",100,off,100);
		move(0,SubGirlJumpSpeedLow,0);
		trigger(_DIRjump);
		nrintframes(4);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);

		connections(SubGirlJumpMedium,SubGirlFallInplace);
}

action(SubGirlJumpForward)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		//file("pc\actors\chot\xxx\Mjmp6Hg.ske",100,off,100);
		trigger(_DIRforward);
		nrintframes(3);
		move(0,SubGirlJumpSpeedLow,0);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium,SubGirlFallForward);
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
		connections(SubGirlJumpMediumL,SubGirlFallL);
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
		connections(SubGirlJumpMedium45L,SubGirlFallFL);
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
		connections(SubGirlJumpMediumR,SubGirlFallR);
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
		connections(SubGirlJumpMedium45R,SubGirlFallFR);
}

action(SubGirlJumpBackwards)
{
		file("pc\actors\Subgirl1\xxx\SgJmpA.ske",100,off,100);
		trigger(_DIRbackward);
		nrintframes(5);
		break(off);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlJumpMedium,SubGirlFallBackwards);
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
		connections(SubGirlJumpMedium45L,SubGirlFallBR);
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
		connections(SubGirlJumpMedium45R,SubGirlFallBL);
}


action(SubGirlfallForward)
{
		file("pc\actors\Subgirl1\xxx\SgJmpD.ske",100,off,100);
//		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlfallForward);
}

action(SubGirlfallFL)
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(SubGirlfallFL);
}
action(SubGirlfallFR)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(SubGirlfallFR);
}
action(SubGirlfallL)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-90)
		connections(SubGirlfallL);
}
action(SubGirlfallR)
{
		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
//		file("pc\actors\Chot\xxx\afallfst.ske",100,on,150);
//		file("pc\actors\Chot\xxx\MJmp4Lp.ske",100,on,150);
		trigger(_AllDir);
		nrintframes(4);
		ydeltafromzeroframe(off);
		break(on);
		rotate(90)
		connections(SubGirlfallR);
}

action(SubGirlfallInPlace)
{
		file("pc\actors\Subgirl1\xxx\SgJmpD.ske",100,off,100);
//		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlfallInPlace);
}

action(SubGirlfallBackwards)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlfallBackwards);
}
action(SubGirlfallBL)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(45)
		connections(SubGirlfallBL);
}
action(SubGirlfallBR)
{
		file("pc\actors\Chot\xxx\arnbkjml.ske",100,on,100);
		trigger(_AllDir);
		nrintframes(7);
		ydeltafromzeroframe(off);
		break(on);
		rotate(-45)
		connections(SubGirlfallBR);
}

action(SubGirlfall)	//Fall when falling from edge only
{
//		file("pc\actors\Subgirl1\xxx\SgJmpC.ske",100,off,100);
//		file("pc\actors\Chot\xxx\MJmp5Lp.ske",100,on,150);
		file("pc\actors\Subgirl1\xxx\SgJmpD.ske",100,off,100);
		trigger(_AllDir);
		nrintframes(7);
		offset(8);
		ydeltafromzeroframe(off);
		break(on);
		connections(SubGirlFall);
}

action(SubGirlTouchDown)
{
		//file("pc\actors\Chot\xxx\mjmp4mg.ske",30,on);	//only when falling from high places
		//file("pc\actors\Chot\xxx\mjmp4lg.ske",100,on);
		file("pc\actors\Subgirl1\xxx\SgJmpLn1.ske",100,on,100);
		trigger(_DIRNotEndOfAnim);
		nrintframes(5);
		break(on);
		connections(SubGirlSpread,SubGirlTouchDown,SubGirlIdle);
}

action(SubGirlTouchDownHard)
{
		file("pc\actors\Subgirl1\xxx\SgJmpLn1.ske",100,on,100);
//		file("pc\actors\Subgirl1\xxx\SgJmpLn2.ske",100,on,100,-1,_DIRcombatmode);	//combat
//		file("pc\actors\Subgirl1\xxx\SgJmpLn2.ske",100,on,100);	//non combat
		trigger(_DIRNotEndOfAnim);
		nrintframes(5);
		break(on);
		connections(SubGirlSpread,SubGirlTouchDown,SubGirlIdle);
}

action(SubGirlRunUpStairs)
{
		file("pc\actors\prost1\xxx\FRnStar2.ske",100,on);
		trigger(_DIRforward);
		break(off);
//		offset(4);
		nrintframes(8);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(SubGirlRunUpStairs);
}


//	SubGirl THROWN ACTIONS
//

action(SubGirlThrownBack)
{
		file("pc\actors\Chot\xxx\ThBkHld1.ske",100,on);	//Backwards hold frame
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(SubGirlThrownBackLand,SubGirlThrownBack);
}

action(SubGirlThrownBackLand)
{
		file("pc\actors\Chot\xxx\ThBklnd.ske",100,off);	//Backwards, land on back
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(SubGirlGetUpFromBack,SubGirlThrownBackLand);
}

action(SubGirlThrownForward)
{
		file("pc\actors\Chot\xxx\ThfwHld1.ske",100,on);	//Forward hold frame
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(SubGirlThrownForwardLand,SubGirlThrownForward);
}

action(SubGirlThrownForwardLand)
{
		file("pc\actors\Chot\xxx\ThFwLnd.ske",100,off);		//forward, land face down, and get up (gabe)
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(4);
		connections(SubGirlGetUpFromFrontFaceDown,SubGirlThrownForwardLand);
}

action(SubGirlThrownRight)
{
		file("pc\actors\Chot\xxx\ThrnHldR.ske",100,on);	//Right Hold frame #1
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(SubGirlThrownRightLand,SubGirlThrownRight);
}

action(SubGirlThrownRightLand)
{
		file("pc\actors\Chot\xxx\ThrnRite.ske",100,off);	//Right land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(0);
		connections(SubGirlGetUpFromRightFaceDown,SubGirlThrownRightLand);
}

action(SubGirlThrownLeft)
{
		file("pc\actors\Chot\xxx\ThrnHldL.ske",100,on);	//Left Hold frame #1
		trigger(_alldir);
		break(on);
		collision(on);
		nrintframes(4);
		connections(SubGirlThrownLeftLand,SubGirlThrownLeft);
}

action(SubGirlThrownLeftLand)
{
		file("pc\actors\Chot\xxx\Thrnleft.ske",100,off);	//Left land on face
		trigger(_DIRhorcol);
		break(off);
		collision(on);
		nrintframes(0);
		connections(SubGirlGetUpFromLeftFaceDown,SubGirlThrownLeftLand);
}

action(SubGirlGetUpFromBack)
{
		file("pc\actors\chot\xxx\mstndfbk.ske",100,off,110,-1,-1,Sub_GetUpClearThrown84);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(4);
		connections(SubGirlIdle);
}

action(SubGirlGetUpFromFrontFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		break(off);
		collision(on);
		nrintframes(0);
		connections(SubGirlIdle);
}

action(SubGirlGetUpFromBackFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(180);
		break(off);
		collision(on);
		nrintframes(0);
		connections(SubGirlIdle);
}

action(SubGirlGetUpFromRightFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(SubGirlIdle);
}

action(SubGirlGetUpFromLeftFaceDown)
{
		file("pc\actors\chot\xxx\MstandF1.ske",100,off,110,-1,-1,Sub_GetUpClearThrown68);
		trigger(_DIRalive);
		rotate(-90);
		break(off);
		collision(on);
		nrintframes(0);
		connections(SubGirlIdle);
}
