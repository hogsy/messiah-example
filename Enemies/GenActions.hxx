
/*

		AIClass(_AIClassCopSkeleton);

		AIClass(_AIClassProstSkeleton);

		AIClass(_AIClassBobSkeleton);

		AIclass(_AIClassBeastSkeleton);

		AIclass(_AIClassAbeastSkeleton);


beast:	Thrown

*/





Action(GENBumped)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobBumpedGeneric,CopBumpedSpread,Prost1BumpedGeneric,GENIdle);
}

Action(GENIdle)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobIdle,BeastIdle,CopIdle,Prost1Idle,ABeastIdle);
}

Action(GENIdleLongTime)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobIdleLongTime,BeastIdleLongTime,CopIdleLongTime,Prost1IdleLongTime,ABeastIdleLongTime);
}

//Action(GENDrown)
//{
//		trigger(_allDIR);
//		nrintframes(-1);
//		connections(BobDrown,CopDrown);
//}

Action(GENDrown)
{
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);		//angel drowning
		file("pc\actors\Bob\xxx\BBrnIdle.ske",100,off,100,_AIClassAngel);		//angel drowning
		file("pc\actors\Bob\xxx\BDeath2.ske",100,on,100,_AIClassAngel); //angel drowning
		file("pc\actors\chot\xxx\Mdrnd.ske",100,off);
		file("pc\actors\Chot\xxx\MFltDedL.ske",100,on);
		//file("pc\actors\Chot\xxx\MFltDed.ske",100,off);
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(8);
		connections(GENDrown);
}

Action(GENDrownLoop)
{
		file("pc\actors\Bob\xxx\BDeath2.ske",100,off,100,_AIClassAngel); //angel drowning
		file("pc\actors\Chot\xxx\MFltDedL.ske",100,on);
		trigger(_allDIR);
		break(off);
		//ydeltafromzeroframe(off);
		gravity(off);
		collision(off);
		nrintframes(8);
		connections(GENDrownLoop);
}


Action(CopDrownDeadLoop)
{
		trigger(_allDIR);
		break(off);
		gravity(off);
		collision(off);
		nrintframes(3);
		connections(CopDrownDeadLoop);
}



Action(GENPossesed)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobDepossesDaze,BeastPossesed,CopPossesed,Prost1Possesed,ABeastPossesed);
}

Action(GENDePossesed)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobDepossesDaze,BeastDepossesed,CopDePossesed,Prost1Depossesed,ABeastDepossesed);
}

action(GENCrouchPossession)//forward-flip, somersault
{
		file("pc\actors\chot\xxx\MCrStun.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);//Crouch stunned
		trigger(_allDIR);
		nrintframes(4);
		break(off);
		connections(CopCrouchIdle,Prost1CrouchIdle,GENIdle);
}

action(GENCrouchDepossession)
{
		file("pc\actors\chot\xxx\MCrStun.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);//Crouch Stunned

		trigger(_allDIR);
		nrintframes(4);
		break(off);
		connections(CopCrouchIdle,Prost1CrouchIdle,GENIdle);
}

action(GENCrawlPossession)
{
		file("pc\actors\chot\xxx\MCrlKikU.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);//Crouch stunned
		trigger(_allDIR);
		nrintframes(4);
		break(off);
		connections(CopCrawlIdle,GENIdle);
}

action(GENCrawlDepossession)
{
		file("pc\actors\chot\xxx\MCrlKikU.ske",100,on,100,-1,-1,Sub_ClrThrownFlag);//Crouch stunned

		trigger(_allDIR);
		nrintframes(4);
		break(off);
		connections(CopCrawlIdle,GENIdle);
}

action(GENCrouchIdle)//forward-flip, somersault
{
		nrintframes(-2);
		trigger(_allDIR);
		connections(CopCrouchIdle,Prost1CrouchIdle,GENIdle);
}

//------------------

Action(GENThrowGrenade)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(DwarfLaunch,CopThrowGrenade,Prost1ThrowGrenade,ABeastThrowGrenade);
}

Action(GENCrouchGrenade)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopCrouchGrenade,Prost1CrouchGrenade);
}

action(GENPickup)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopPickup,Prost1Pickup);
}

action(GENPickupChest)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopPickupChest,Prost1PickupChest);
}

action(GENPickupCrouch)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopPickupCrouch,Prost1PickupCrouch);
}



action(GENPressGun)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobConsole,CopPressGun,Prost1PressGun,BeastPressButton,ABeastPressButton,GENidle);
}

action(GENPressGunCrawl)
{
		file("pc\actors\Chot\xxx\MCrwlPBt.ske",100,off);
		trigger(_allDIR);
		nrintframes(4);
		break(off);
		connections(GENCrawlSpreadOut);
}

subroutine(Sub_GENShotInRLeg)
{
		if(vframe==23)
		{
			sample(SFXManFallToGround,-1);
		}
}
Action(GENShotInRLeg)
{
		//file("pc\actors\chot\xxx\MSnpLeg1.ske",50,off,100,-1,_DIRcombatmode);
		file("pc\actors\chot\xxx\MSnpLeg2.ske",100,off,100,-1,_DIRcombatmode);
		file("pc\actors\chot\xxx\MSnpLeg3.ske",100,off,100,-1);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(BobWoundLight,CopCrawlIdle);

		ActionSubRoutine(Sub_GENShotInRLeg);
}

subroutine(Sub_GENShotInLLeg)
{
		if(vframe==13)
		{
			sample(SFXManFallToGround,-1);
		}
}
Action(GENShotInLLeg)
{
		file("pc\actors\chot\xxx\MSnpLeg4.ske",100,off,100,-1);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(BobWoundLight,CopCrawlIdle);

		ActionSubRoutine(Sub_GENShotInLLeg);
}

Action(GENShotInRFoot)
{
		//file("pc\actors\chot\xxx\MSnpLeg1.ske",50,off,100,-1,_DIRcombatmode);
		file("pc\actors\chot\xxx\MSnpRFut.ske",100,off,100,-1);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GenIdle);
}

Action(GENShotInLFoot)
{
		//file("pc\actors\chot\xxx\MSnpLeg1.ske",50,off,100,-1,_DIRcombatmode);
		file("pc\actors\chot\xxx\MSnpLFut.ske",100,off,100,-1);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GenIdle);
}

//-------------  NOT DONE

action(GENFallToCrawl)
{
		//file("pc\actors\chot\xxx\MBrn2Kns.ske",100,off);
		file("pc\actors\Bob\xxx\BShtDed1.ske",100,off,100,_AIClassAngel);
		file("pc\actors\chot\xxx\MBrkleg.ske",100,off,50);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(CopCrawlIdle);
}

action(GENCrawlSpreadOut)	//Lead directly to next animation
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(CopCrawlForward,CopCrawlBackwards,CopCrawlTurnLeft,CopCrawlTurnRight,CopCrawlIdle);
}

action(GENThrownForward)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BeastThrownForward,BobThrownForward,CopThrownForward,Prost1ThrownForward,GenIdle);
}

action(GENThrownBack)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BeastThrownBack,BobThrownBack,CopThrownBack,Prost1ThrownBack);
}

action(GENThrownLeft)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BeastThrownLeft,BobThrownBack,CopThrownLeft,Prost1ThrownLeft);
}

action(GENThrownRight)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BeastThrownRight,BobThrownBack,CopThrownRight,Prost1ThrownRight);
}

//-------------  'TILL HERE

action(GENWoundLight)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,BeastWoundLight,CopWoundLight,Prost1WoundLight,ABeastWoundLight);
}

action(GENWoundLightRun)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLightRun,BeastWoundLight,CopWoundLight,Prost1WoundLight,ABeastWoundLight);
}

action(GENWoundLightNoBreak)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,BeastWoundLightNoBreak,CopWoundLightNoBreak,Prost1WoundLightNoBreak,ABeastWoundLightNoBreak);
}

action(GENCrouchWoundLight)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopCrouchWoundLight,Prost1CrouchWoundLight);
}


action(GENShotInLeg)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,CopShotInLeg,Prost1ShotInLeg);
}

action(GENShotFrHead)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobFallDead,CopShotFrHead,Prost1ShotFrHead);
}

action(GENShotFrTorso)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,CopShotFrTorso,Prost1ShotFrTorso);
}

action(GENShotFrRShoulder)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,CopShotFrRShoulder,Prost1ShotFrRShoulder);
}

action(GENShotFrLShoulder)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,CopShotFrLShoulder,Prost1ShotFrLShoulder);
}

action(GENShotGeneric)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,CopShotGeneric,Prost1ShotGeneric);
}

action(GENShotBkHead)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobFallDead,CopShotBkHead,Prost1ShotBkHead);
}

action(GENShotBkBack)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobWoundLight,CopShotBkBack,Prost1ShotBkBack);
}


action(GENElectricShock0)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobElectricShock0,BeastElectricShock0,CopElectricShock0,Prost1ElectricShock0,ABeastElectricShock0);
}

action(GENElectricShock1)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobElectricShock1,BeastElectricShock1,CopElectricShock1,Prost1ElectricShock1,ABeastElectricShock1);
}


action(GENTouchDown)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobTouchDown,BeastTouchDown,CopTouchDown,Prost1TouchDown,ABeastTouchDown);
}

action(GENFallDead)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobFallDead,BeastFallDead,CopFallDead,Prost1FallDead,ABeastFallDead);
}

action(GENFallInPlace)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobFallDead,BeastFallInPlace,CopFallInPlace,Prost1FallInPlace,ABeastFallInPlace);
}


//-------------  NOT DONE

action(GENPoleDead)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\Poldedlf.ske",50,off);
		file("pc\actors\Chot\xxx\Poldedlb.ske",100,off);
		//file("pc\actors\Chot\xxx\mbelly.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(31);
		shadow(off);
}

action(GENOnPole)
{
		file("pc\actors\Chot\xxx\mback.ske",20,off);
		file("pc\actors\Chot\xxx\PolTwch1.ske",50,on);
		file("pc\actors\Chot\xxx\PolTwch2.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		intforloop(on);
		connections(GENOnPole,GENPoleDead);
}

/* *************   harpooned animations ******************* */

action(GENHarpoonFrontHold)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpedH.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonFrontHold);
}

action(GENHarpoonFrontHitWall)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpedSt.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonFrontIdle);
}

action(GENHarpoonFrontIdle)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpedI1.ske",10,on);
		file("pc\actors\Chot\xxx\AHrpedI2.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonFrontIdle);
}

action(GENHarpoonFrontBeg)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpedI3.ske",50,off);
		file("pc\actors\Chot\xxx\AHrpedI4.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonFrontIdle);
}

action(GENHarpoonFrontBurn)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpedI1.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonFrontBurn);
}

action(GENHarpoonBackHold)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpedHB.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonBackHold);
}

action(GENHarpoonBackHitWall)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpedSB.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonBackIdle);
}

action(GENHarpoonBackIdle)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpdI1B.ske",10,on);
		file("pc\actors\Chot\xxx\AHrpdI2B.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonBackIdle);
}

action(GENHarpoonBackBurn)
{
		file("pc\actors\Bob\xxx\BHrpoond.ske",100,on,100,_AIclassangel);
		file("pc\actors\Chot\xxx\AHrpdI1B.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		shadow(off);
		connections(GENHarpoonBackBurn);
}

Action(GENCrawlDead)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobDead,CopCrawlDead,Prost1CrawlDead);
}

Action(GENStandDead)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobDead,BeastStandDead,CopStandDead,Prost1StandDead,ABeastStandDead);
}

Action(GENCrouchDead)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobDead,CopCrouchDead,Prost1CrouchDead);
}

//---------- 'TILL HERE

Action(GENCrouchDown)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobCrouchDown,BeastCrouchDown,CopCrouchDown,Prost1CrouchDown,ABeastCrouchDown);
}

Action(GENCrouchUp)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobCrouchUp,BeastCrouchUp,CopCrouchUp,Prost1CrouchUp,ABeastCrouchUp);
}


Action(GENRunUpStairs)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobRunUpStairs,CopRunUpStairs,Prost1RunUpStairs);
}



Action(GENCrushed)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobCrush,CopCrush,Prost1Crush,BeastFallDead,ABeastFallDead);
}


Action(GENJump)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobJumpWithGravity,BeastJump,CopJump,SubGirlJump,Prost1Jump,ABeastJump);
}

Action(GENFall)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobFall,Beastfall,CopFall,Prost1Fall,ABeastfall);
}

action(GENSlideAction)
{
		file("pc\actors\Chot\xxx\mslyde1.ske",100,on);
		trigger(_allDIR);
		nrintframes(4);
		intforloop(on);
		gravity(on);
		ydeltafromzeroframe(off);
		break(on);
		connections(GENSlide);
}

action(GENSlide)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(BobSlide,GENSlideAction);
}

//------------------------------------

action(GENBurningRollOnFloor)		//Roll on floor to extinguish fire
{
		file("pc\actors\Bob\xxx\BCrwIdle.ske",100,on,100,_AIClassAngel);
		file("pc\actors\chot\xxx\ABrnRoll.ske",100,on,80);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENSlowGetUpFace);
}


Action(GENBurnedIdle)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopBurnedIdle,Prost1BurnedIdle);
}

Action(GENGettingBurned)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopGettingBurned,Prost1GettingBurned);
}

Action(GENBlindForward)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopBlindForward,Prost1BlindForward);
}

Action(GENBlindBackwards)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopBlindBackwards,Prost1BlindBackwards);
}

Action(GENBurningRunInCircle)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopBurningRunInCircle,Prost1BurningRunInCircle);
}

Action(GENSlowGetUpFace)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopSlowGetUpFace,Prost1SlowGetUpFace);
}

Action(GENGetUpFromBack)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopGetUpFromBack,Prost1GetUpFromBack);
}

Action(GENReload)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopReload,Prost1Reload);
}

Action(GENReloadCrouch)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopReloadCrouch,Prost1ReloadCrouch);
}

Action(GENHeavyRecoil)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopHeavyRecoil,Prost1HeavyRecoil);
}

Action(GENLightRecoil)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(CopLightRecoil,Prost1LightRecoil);
}

Action(GENCrouchHeavyRecoil)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopCrouchHeavyRecoil,Prost1CrouchHeavyRecoil);
}

Action(GENCrouchLightRecoil)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopCrouchLightRecoil,Prost1CrouchLightRecoil);
}



//----------------------------

action(GENBackRollRight)
{
		file("pc\actors\bob\xxx\BR_B2F_L.ske",100,off,100,_AIclassangel);
		file("pc\actors\chot\xxx\MR_B2F_L.ske",100,off);
		break(off);
		connections(GENBackRollRight);
}

action(GENBackRollLeft)
{
		file("pc\actors\bob\xxx\BR_F2B_R.ske",100,off,100,_AIclassangel);
		file("pc\actors\chot\xxx\MR_F2B_R.ske",100,off);
		break(off);
		connections(GENBackRollLeft);
}

action(GENStomachRollRight)
{
		file("pc\actors\bob\xxx\BR_F2B_L.ske",100,off,100,_AIclassangel);
		file("pc\actors\chot\xxx\MR_F2B_L.ske",100,off);
		break(off);
		connections(GENStomachRollRight);
}

action(GENStomachRollLeft)
{
		file("pc\actors\bob\xxx\BR_B2F_R.ske",100,off,100,_AIclassangel);
		file("pc\actors\chot\xxx\MR_B2F_R.ske",100,off);
		break(off);
		connections(GENStomachRollLeft);
}


//	COP KICKALONG ACTION



Action(GENKickLeftFD)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		AttachActionStartAtFrame(14);
		AttachAction(GENStomachRollLeft);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);


		ActionSubRoutine(Sub_RandomKickRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(GENIdle);
}

Action(GENKickRightFD)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		AttachActionStartAtFrame(14);
		AttachAction(GENStomachRollRight);

		ActionSubRoutine(Sub_RandomKickRollSFX);


		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(GENIdle);
}

Action(GENKickRightFU)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		AttachActionStartAtFrame(14);
		AttachAction(GENBackRollRight);

		ActionSubRoutine(Sub_RandomKickRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(GENIdle);
}

Action(GENKickLeftFU)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAonlydeadpeople|_SXAAdisablecollision|_SXAAdisablerotation);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AttackHeight(40);
		AlignDistance(100);
		DistanceSlack(150);
		AlignSlack(180);	

		AttachActionStartAtFrame(14);
		AttachAction(GENBackRollLeft);

		ActionSubRoutine(Sub_RandomKickRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(0);
		connections(GENIdle);
}


Action(GENKickedCrotchFD)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(GENKickedCrotchFD2);
}


Action(GENKickedCrotchFD2)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\MultiAnm\xxx\MKkdCrFd.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\FKkdCrFd.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\MKkdCrFd.ske",100,off);
		trigger(_allDIR);
		connections(GENKickedCrotchFD2);
}

Action(GENKickedCrotchFU)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(GENKickedCrotchFU2);
}

Action(GENKickedCrotchFU2)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\MultiAnm\xxx\MKkdCrFu.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\FKkdCrFu.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\MKkdCrFu.ske",100,off);
		trigger(_allDIR);
		connections(GENKickedCrotchFU2);
}

Action(GENKickedHeadFD)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(GENKickedHeadFD2);
}

Action(GENKickedHeadFD2)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\MultiAnm\xxx\MKkdHdFd.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\FKkdHdFd.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\MKkdHdFd.ske",100,off);
		trigger(_allDIR);
		connections(GENKickedHeadFD2);
}

Action(GENKickedHeadFU)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(GENKickedHeadFU2);
}

Action(GENKickedHeadFU2)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\MultiAnm\xxx\MKkdHdFu.ske",100,off,100,_AIclassmale);
		file("pc\actors\MultiAnm\xxx\FKkdHdFu.ske",100,off,100,_AIclassfemale);
		file("pc\actors\MultiAnm\xxx\MKkdHdFu.ske",100,off);
		trigger(_allDIR);
		connections(GENKickedHeadFU2);
}


Action(GENKickHeadFD)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//male right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAalignmovingslave|_SXAAonlydeadpeople|_SXAAdisablecollision);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AlignAngle(0);
		TargetAngle(-1);
		AttackHeight(50);
		AlignDistance(100);
		AlignSlack(20);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(15);
		AttachAction(GENKickedHeadFD);

		ActionSubRoutine(Sub_RandomKickRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENIdle);
}

Action(GENKickHeadFU)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//male right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAalignmovingslave|_SXAAonlydeadpeople|_SXAAdisablecollision);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AlignAngle(0);
		TargetAngle(-1);
		AttackHeight(50);
		AlignDistance(100);
		AlignSlack(20);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(15);
		AttachAction(GENKickedHeadFU);

		ActionSubRoutine(Sub_RandomKickRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENIdle);
}

Action(GENKickCrotchFD)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//male right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAalignmovingslave|_SXAAonlydeadpeople|_SXAAdisablecollision);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AlignAngle(0);
		TargetAngle(-1);
		AttackHeight(50);
		AlignDistance(100);
		AlignSlack(20);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(15);
		AttachAction(GENKickedCrotchFD);

		ActionSubRoutine(Sub_RandomKickRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENIdle);
}

Action(GENKickCrotchFU)
{
		file("pc\actors\Bob\xxx\BRolBdy.ske",100,off,100,_AIclassangel);
		file("pc\actors\Chot\xxx\MWrKikLw.ske",100,on,100);	//male right leg kick, holding gun

		flag(_SXAAAlignTransToY|_SXAAalignmovingslave|_SXAAonlydeadpeople|_SXAAdisablecollision);

		AIClass(_AIClassAllButAngel);
		TargetAIClass(_AIClassAllButAngel);

		AlignAngle(0);
		TargetAngle(-1);
		AttackHeight(50);
		AlignDistance(100);
		AlignSlack(20);
		DistanceSlack(50);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(15);
		AttachAction(GENKickedCrotchFU);

		ActionSubRoutine(Sub_RandomKickRollSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENIdle);
}

Action(GENclimbupAction)
{
//		file("pc\actors\chot\xxx\MClmbWlS.ske",50,off,100);
		file("pc\actors\chot\xxx\MClmbWlF.ske",100,off,100);
		nrintframes(8);
		break(off);
		trigger(_allDIR);
		gravity(off);
		ydeltafromzeroframe(off);
		connections(GENIdle);
}
Action(GENclimbup)
{
		nrintframes(-2);
		trigger(_allDIR);
		connections(BobClimbUp,GENclimbupAction,GENidle);
}

Action(GENIdleHitWall)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(bobidleHitWall,BeastIdleHitWall,CopIdleHitWall,Prost1IdleHitWall,ABeastIdleHitWall);
}

Action(GENIdleHitWallFront)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(bobidleHitWallFront,BeastIdleHitWallFront,CopIdleHitWallFront,Prost1IdleHitWallFront,ABeastIdleHitWallFront);
}

Action(GENHitWallSpreadOut)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(BobHitWallSpreadOut,BeastHitWallSpreadOut,CopHitWallSpreadOut,Prost1HitWallSpreadOut,ABeastHitWallSpreadOut);
}

Action(GENSpreadOut)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(BobSpreadOut,BeastSpreadOut,CopSpreadOut,Prost1Spread,ABeastSpreadOut);
}

Action(GENSpreadOutGun)
{
		trigger(_allDIR);
		nrintframes(-1);
		connections(BobSpreadOut,BeastSpreadOut,CopSpreadOutGun,Prost1SpreadGun,ABeastSpreadOut);
}

Action(GENHolsterGun)
{
		file("pc\actors\Dwellr1\xxx\DwMHlstG.ske",100,off,100,_AIclassmale);
		file("pc\actors\Dwelfem1\xxx\DwFHlstG.ske",100,off,80,_AIclassfemale);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENidle);
}

Action(GENUnHolsterGun)
{
		file("pc\actors\Dwellr1\xxx\DwMDrawG.ske",100,off,100,_AIclassmale);
		file("pc\actors\Dwelfem1\xxx\DwFDrawG.ske",100,off,100,_AIclassfemale);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENidle);
}

Action(GENSurrender)
{
		file("pc\actors\Dwellr1\xxx\DwMSurSt.ske",100,off,100,_AIclassmale);
		file("pc\actors\Dwellr1\xxx\DwMSurLp.ske",100,on,100,_AIclassmale);
		file("pc\actors\Dwelfem1\xxx\DwFSurSt.ske",100,off,100,_AIclassfemale);
		file("pc\actors\Dwelfem1\xxx\DwFSurLp.ske",100,on,100,_AIclassfemale);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENSurrender);
}

Action(GENCrouchSurrender)
{
		file("pc\actors\Chot\xxx\MCwr2Sur.ske",100,off,100,_AIclassmale);
		file("pc\actors\Prost1\xxx\FCwr2Sur.ske",100,off,100,_AIclassfemale);
		trigger(_allDIR);
		break(off);
		nrintframes(3);
		connections(GENCrouchSurrender);
}

Action(GENTurn180)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(Cop180);
}

Action(GENCrouchTurn180)
{
		trigger(_allDIR);
		nrintframes(-2);
		connections(CopCrouch180);
}


action(GENCoweringLoop)
{
		file("pc\actors\Prost1\xxx\FCrCowrL.ske",30,on,100,_AIclassFemale);
		file("pc\actors\Prost1\xxx\FCrCowrI.ske",100,on,100,_AIclassFemale);
		file("pc\actors\Chot\xxx\MCrCowe2.ske",30,on);
		file("pc\actors\Chot\xxx\MCrCower.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(12);
		connections(GENCoweringLoop);
}


action(GENEndCower)
{
		file("pc\actors\Prost1\xxx\FEndCwr.ske",50,on,100,_AIclassFemale);
		file("pc\actors\Prost1\xxx\FEndCwr2.ske",100,on,100,_AIclassFemale);
		file("pc\actors\Chot\xxx\MEndCwr.ske",50,on);
		file("pc\actors\Chot\xxx\MEndCwr2.ske",100,on);
		trigger(_DIRNotEndOfAnim);
		break(off);
		//ActionSubroutine(Sub_ActionDebugBreak);
		nrintframes(5);
		connections(GENEndCower,GENIdle);
}



action(GENShotInRightHand)
{
//		file("pc\actors\Copm\xxx\mposs4p.xxx",50,on);
//		file("pc\actors\chot\xxx\mspan7p.ske",100,on);
		file("pc\actors\chot\xxx\MsnpRHnd.ske",100,on);
		trigger(_allDIR);

		break(off);
		nrintframes(2);
		connections(GENIdle);
}


action(GENShotInAss)
{
//		file("pc\actors\Copm\xxx\mposs4p.xxx",50,on);
//		file("pc\actors\chot\xxx\mspan7p.ske",100,on);
		file("pc\actors\chot\xxx\MsnpdAss.ske",100,on);
		trigger(_allDIR);

		break(off);
		nrintframes(2);
		connections(GENIdle);
}


subroutine(Sub_GENShotInNeckFront)
{
//	If(Vframe==1)
//	{
		//state(_or,StateDead);
		//callsub(Sub_Deposses);
		//if(AIAbility&=_AIAPickUpWeapon)
		//{
		//	call(CheckAttached,_CADropWeaponAndShells);
		//}
//	}


	if(vrnd<50)
	{
		if(vframe<30)
		{
			spawnparticle(fx_blood,3,emptyvector,emptyvector,-1);
			spawnparticle(fx_blood,3,emptyvector,emptyvector,-1);
		}
	}

	If(Vframe<105)
	{
		spawnparticle(fx_bloodspray,3,emptyvector,emptyvector,-1);
	}

}

action(GENShotInNeckFront)
{
		file("pc\actors\chot\xxx\MsnpdNkF.ske",100,off);
		trigger(_allDIR);
		ActionSubRoutine(Sub_GENShotInNeckFront);
		break(off);
		nrintframes(2);
}


subroutine(Sub_GENShotInNeckBack)
{
/*
	If(Vframe==1)
	{
		state(_or,StateDead);
		direction(_clr,_DIRalive);
		callsub(Sub_Deposses);
		//if(AIAbility&=_AIAPickUpWeapon)
		//{
			call(CheckAttached,_CADropWeaponAndShells);
		//}
	}
*/
	if(vrnd<50)
	{
		if(vframe<30)
		{
			spawnparticle(fx_blood,3,emptyvector,emptyvector,-1);
			spawnparticle(fx_blood,3,emptyvector,emptyvector,-1);
		}
	}

	If(Vframe<175)
	{
		spawnparticle(fx_bloodspray,3,emptyvector,emptyvector,-1);
	}
}


action(GENShotInNeckBack)
{
		file("pc\actors\chot\xxx\MsnpdNkB.ske",100,off);
		trigger(_allDIR);
		ActionSubRoutine(Sub_GENShotInNeckBack);
		break(off);
		nrintframes(2);
}



