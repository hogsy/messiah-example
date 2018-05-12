/*
action(SatanPopCopLinkA):
Guy part of link action:
Head crush or neck break sound at frame #24 Scale down head. Guy needs to spray heavy blood froom neck bone Frames #25 to 85
Blood tapering off over frames #85 to #107
*/

SubRoutine(Sub_InitSatanGrab)
{
		if(VFrame==1 && VAICon==0)
		{
			if(VSniperMode!=0)
			{
				call(ChangeSniperMode,-2,0);
			}
			State(_or,StateThrown);
			ActorFlag(_or,_AFLAGNoDepossession);
			ActorFlag(_or,_AFLAGnotarget);
			ActorFlag(_or,_AFLAGnolinkup);
			call(PlayerInput,0);
		}
}

SubRoutine(Sub_DeInitSatanGrab)
{
		if(VAICon==0)
		{
			if(VDifficulty<_DifficultyHard)
			{
				ActorFlag(_clr,_AFLAGNoDepossession);
			}
			ActorFlag(_clr,_AFLAGnotarget);
			ActorFlag(_clr,_AFLAGnolinkup);
			call(PlayerInput,1);
		}
}


SubRoutine(Sub_SatanIntro0)
{
		if(VFrame==1)
		{
			sample(SFXsatanintro0,-1);
		}
}

SubRoutine(Sub_SatanIntro1)
{
		if(VFrame==1)
		{
			sample(SFXsatanintro1,-1);
		}
}

SubRoutine(Sub_SatanIntro3)
{
		if(VFrame==1)
		{
			sample(SFXsatanintro3,-1);
		}
}

SubRoutine(Sub_SatanIntro4)
{
		if(VFrame==1)
		{
			sample(SFXsatanintro4,-1);
		}
}

action(Satanintro0)
{
		file("pc\actors\Satan\xxx\SStart0.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		ActionSubRoutine(Sub_SatanIntro0);
		connections(Satanintro1);
}

action(Satanintro1)
{
		file("pc\actors\Satan\xxx\SStart1.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		ActionSubRoutine(Sub_SatanIntro1);
		connections(Satanintro3);
}

action(Satanintro3)
{
		file("pc\actors\Satan\xxx\SStart3.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		ActionSubRoutine(Sub_SatanIntro3);
		connections(Satanintro4);
}

action(Satanintro4)
{
		file("pc\actors\Satan\xxx\SStart4.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		ActionSubRoutine(Sub_SatanIntro4);
		connections(SatanIdle);
}



action(SatanIdle)
{
		file("pc\actors\Satan\xxx\Bidle1.ske",50,on);
		file("pc\actors\Satan\xxx\ADrnkCy.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanIdle);
}

action(SatanIdle1)
{
		file("pc\actors\Satan\xxx\AIdl1_1.ske",20,on);
		file("pc\actors\Satan\xxx\AIdl1_2.ske",40,on);
		file("pc\actors\Satan\xxx\AIdl1_3.ske",50,on);
		file("pc\actors\Satan\xxx\ADrnkCy.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanIdle1);
}

action(SatanIdle2)
{
		file("pc\actors\Satan\xxx\AIdl2_1.ske",25,on);
		file("pc\actors\Satan\xxx\AIdl2_2.ske",50,on);
		file("pc\actors\Satan\xxx\ADrnkCy.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanIdle2);
}

action(SatanIdle3)
{
		file("pc\actors\Satan\xxx\AIdl3_1.ske",25,on);
		file("pc\actors\Satan\xxx\AIdl3_2.ske",50,on);
		file("pc\actors\Satan\xxx\ADrnkCy.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanIdle3);
}

action(SatanIdle4)
{
		file("pc\actors\Satan\xxx\AIdl4_1.ske",25,on);
		file("pc\actors\Satan\xxx\AIdl4_2.ske",50,on);
		file("pc\actors\Satan\xxx\ADrnkCy.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(6);
		intforloop(on);

		connections(SatanWound,SatanSpinCop,SatanGrabCop,SatanSwatBob,SatanWalk,SatanRun,SatanTurnLeft,SatanTurnRight,SatanIdle4);
//		connections(SatanWound,SatanPopCop,SatanSpinCop,SatanGrabCop,SatanWalk,SatanRun,SatanTurnLeft,SatanTurnRight,SatanIdle4);
}

action(SatanRun)
{
		file("pc\actors\Satan\xxx\Brun.ske",100,on);
		trigger(_DIRforward);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanRun,SatanGrabBob,SatanPopCop,SatanIdle4);
}

action(SatanWalk)
{
		file("pc\actors\Satan\xxx\Bwalk.ske",100,on);
		trigger(_DIRforward|_DIRwalking);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanWalk,SatanIdle4);
}

action(SatanPanting)
{
		file("pc\actors\Satan\xxx\BPufPuf.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		connections(SatanIdle4);
}



action(SatanTurnLeft)
{
		file("pc\actors\Satan\xxx\BHover.ske",100,on);
		trigger(_DIRleft);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanSpinCop,SatanGrabCop,SatanSwatBob,SatanTurnLeft,SatanIdle4);
}

action(SatanTurnRight)
{
		file("pc\actors\Satan\xxx\BHover.ske",100,on);
		trigger(_DIRright);
		break(on);
		nrintframes(6);
		intforloop(on);
		connections(SatanSpinCop,SatanGrabCop,SatanSwatBob,SatanTurnRight,SatanIdle4);
}

action(SatanWound)
{
		file("pc\actors\Satan\xxx\BWound.ske",100,on);
		trigger(_DIRactorbulletcol);
		break(off);
		nrintframes(6);
		intforloop(on);
		connections(SatanIdle4);
}

action(SatanDeath)
{
		file("pc\actors\Satan\xxx\SDeath.ske",100,off);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
}


action(SatanRingOfFire)
{
		file("pc\actors\Satan\xxx\BDrwPwr.ske",100,on);
		trigger(_allDIR);
		break(off);
		nrintframes(6);
		intforloop(on);
		connections(SatanIdle);
}


SubRoutine(Sub_MoveEvilBob)
{
		if(VFrame>=63)
		{
			move(0,0,-100);
		}
}

Subroutine(Sub_SpawnEvilBob)
{
		if(VFrame==23)
		{
			vector(_settoactorpos,Gactorpos);
			//vector(_set,TmpVector,0,100,0);
			//vector(_sub,GactorPos,TmpVector);
			vector(_set,Gactorangle,0,0,0);
			InitActor(evilbob,Gactorpos,Gactorangle,"Satan",FALSE,0);
		}
		elseif(VFrame==24)
		{
			call(AIcheckfortarget,0,true);
		}
}

action(SatanSpawningEvilBobLink)
{
		file("pc\actors\Satan\xxx\AChrb_C.ske",100,on,100);
		break(off);
		gravity(off);
		trigger(_allDIR);

		ActionSubRoutine(Sub_MoveEvilBob);

		connections(BobThrownForward);

}

action(SatanSpawningEvilBob0)
{
		file("pc\actors\Satan\xxx\AChrb_S1.ske",100,on,100);	//
		break(off);
		trigger(_allDIR);

		nrintframes(6);

		ActionSubRoutine(Sub_SpawnEvilBob);


		connections(SatanSpawningEvilBob);
}
action(SatanSpawningEvilBob)
{
		file("pc\actors\Satan\xxx\AChrb_S2.ske",100,on,100);	//

		flag(_SXAAalignmovingslave|_SXAAdisablecollision);

		AlignXYZ(20,0,139);
		//AlignAngle(0);
		//AlignDistance(69);
		TargetAngle(0);
		AttackHeight(0);
		AlignSlack(240);
		DistanceSlack(240);

		AlignStartFrame(0);
		AlignNrFrames(1);

		AttachActionStartAtFrame(0);
		DamageFrame(20);
		Power(0);
		AttachAction(SatanSpawningEvilBobLink);
		TargetAIClass(_AIclassangel);

		//ActionSubRoutine(Sub_RandomKickedSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(SatanIdle);
}



action(SatanGrabBoblink)
{
		file("pc\actors\Satan\xxx\BEat_B.ske",100,on,100);
		break(off);
		gravity(off);
		trigger(_allDIR);

		ActionSubRoutine(Sub_SetThrown);


		connections(BobThrownBack);
}


SubRoutine(Sub_SatanGrabBob)
{
		if(VFrame==24)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==67)
		{
			//	toss up
			//
		}
		elseif(VFrame==98)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==100)
		{
			//	Start chewing
			//
		}
		elseif(VFrame==148)
		{
			//	stop chewing
			//
		}
		elseif(VFrame==159)
		{
			//	Spit
			//
		}
}

action(SatanGrabBob)
{
		file("pc\actors\Satan\xxx\BEat_S.ske",100,on,100);	//

		//AlignXYZ(10,0,181.7);
		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAPlayerOneOnly);

		AlignXYZ(42,-100,266);
		//AlignAngle(0);
		//AlignDistance(133);
		TargetAngle(180);
		AttackHeight(20);
		AlignSlack(300);
		DistanceSlack(100);

		AlignStartFrame(27);
		AlignNrFrames(1);

		AttachActionStartAtFrame(27);
		DamageFrame(40);
		Power(10);
		AttachAction(SatanGrabBoblink);
		TargetAIClass(_AIclassangel);

		ActionSubRoutine(Sub_SatanGrabBob);

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(SatanIdle4);
}

// ########################################################
// Satan grab Bob, look at him then throw him away
action(SatanThrowBoblink)
{
		file("pc\actors\Satan\xxx\BLookT_B.ske",100,on,100);
		break(off);
		gravity(off);
		trigger(_allDIR);
		ActionSubRoutine(Sub_SetThrown);

		connections(BobThrownBack);
}

action(SatanThrowBob)
{
		file("pc\actors\Satan\xxx\BLookT_S.ske",100,on,100);	//

		//AlignXYZ(10,0,181.7);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAPlayerOneOnly);

		AlignXYZ(25,0,240);
//		AlignXYZ(35,0,280);
		//AlignAngle(0);
		//AlignDistance(133);
		TargetAngle(180);
		AttackHeight(0);
		AlignSlack(240);
		DistanceSlack(100);

		AlignStartFrame(29);
		AlignNrFrames(1);

		AttachActionStartAtFrame(29);
		DamageFrame(40);
		Power(10);
		AttachAction(SatanThrowBoblink);
		TargetAIClass(_AIclassangel);


		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(SatanIdle4);
}

// ########################################################
// Satan grab Bob, toss him up and swat him away with his tail

action(SatanSwatBoblink)
{
		file("pc\actors\Satan\xxx\BBall_B.ske",100,on,100);
		break(off);
		gravity(off);
		trigger(_allDIR);
		ActionSubRoutine(Sub_SetThrown);

		connections(BobThrownBack);
}

SubRoutine(Sub_SatanSwatBob)
{
		if(VFrame==24 || VFrame==104)
		{
			Sample(SFXManPunch,-1);
		}
}


action(SatanSwatBob)
{
		file("pc\actors\Satan\xxx\BBall_S.ske",100,on,100);	//

		AlignXYZ(10,0,181.7);

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAPlayerOneOnly);

		AlignXYZ(35,0,220);
//		AlignXYZ(35,0,280);
		//AlignAngle(0);
		//AlignDistance(133);
		TargetAngle(180);
		AttackHeight(0);
		AlignSlack(240);
		DistanceSlack(100);

		AlignStartFrame(27);
		AlignNrFrames(1);

		AttachActionStartAtFrame(27);
		DamageFrame(40);
		Power(10);
		AttachAction(SatanSwatBoblink);
		TargetAIClass(_AIclassangel);


		ActionSubRoutine(Sub_SatanSwatBob);

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(SatanIdle4);
}




action(SatanGrabCoplink)
{
		file("pc\actors\Satan\xxx\BMCut_M.ske",100,on,100);
		break(off);
		gravity(off);
		trigger(_allDIR);

		ActionSubRoutine(Sub_InitSatanGrab);

		connections(SatanPopCoplinkC);
}


SubRoutine(Sub_SatanGrabCop)
{
		if(VFrame==20 || VFrame==77 || VFrame==87 || VFrame==97)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==178)
		{
			//	Throw away sample
			//
		}
}


action(SatanGrabCop)
{
		file("pc\actors\Satan\xxx\BMCut_S.ske",100,on,100);	//

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAPlayerOneOnly);

		//AlignXYZ(2.7,0,504);
		//AlignXYZ(2.70,0,252);
		AlignXYZ(1.30,0,252);
		//AlignAngle(0);
		//AlignDistance(133);
		TargetAngle(180);
		AttackHeight(100);
		AlignSlack(240);
		DistanceSlack(100);
 
		AlignStartFrame(19);
		AlignNrFrames(1);

		AttachActionStartAtFrame(19);
		DamageFrame(40);
		Power(0);
		AttachAction(SatanGrabCoplink);
		TargetAIClass(_AIClassAllButAngel);

		ActionSubRoutine(Sub_SatanGrabCop);

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(SatanIdle4);
}


// ################################################################
// Snap head back and suck out bob? the spit out bob at frame #295


SubRoutine(Sub_SatanPopCoplinkC)
{
		if(Vstate!=StateDead)
		{
			state(_or,StateDead);
			direction(_clr,_DIRalive);
			callsub(Sub_Deposses);
			ActorFlag(_clr,_AFLAGpossesed);
			//if(AIAbility&=_AIAPickUpWeapon)
			//{
				call(CheckAttached,_CADropWeaponAndShells);
			//}
		}
		else
		{
			vector(_settoactorpos,tmpvector);
			callsub(sub_fxsmallexplosion);
			killactor();
		}
/*
		if(VFrame==31)
		{
			state(_or,StateCrawling);
			if(AIAbility&=_AIAPickUpWeapon)
			{
				call(CheckAttached,_CADropWeaponAndShells);
			}
		}
*/
}


SubRoutine(Sub_SatanPopCoplinkA)
{
		callsub(Sub_InitSatanGrab);

		if(VFrame==24)
		{
			//state(_or,StateDead);
			//direction(_clr,_DIRalive);
			//callsub(Sub_Deposses);
			//sample(SFXManNeckSnap,-1);
			//call(CheckAttached,_CADropWeaponAndShells);
			//scalebonematrix(3,0.001,0.001,0.001,_SXBoneAttRelative);
			scalebonematrix(4,0.001,0.001,0.001,_SXBoneAttAbsolute);
			//	scalebonematrix(13,0.001,0.001,0.001,_SXBoneAttAbsolute);
			//	scalebonematrix(14,0.001,0.001,0.001,_SXBoneAttAbsolute);
			//	scalebonematrix(15,0.001,0.001,0.001,_SXBoneAttAbsolute);
			//	scalebonematrix(16,0.001,0.001,0.001,_SXBoneAttAbsolute);
		}

		if(VFrame>24&&VFrame<107)
		{
			if(vrnd<75)
			{
				if(vframe<85)
				{
					spawnparticle(fx_blood,4,emptyvector,emptyvector,-1);
					spawnparticle(fx_blood,4,emptyvector,emptyvector,-1);
				}
				spawnparticle(fx_bloodspray,4,emptyvector,emptyvector,-1);
			}
		}

}


action(SatanPopCoplinkA)
{ 
		file("pc\actors\Satan\xxx\BPopMnMA.ske",100,on,100);
		break(off);
		gravity(off);
		trigger(_allDIR);

		ActionSubRoutine(Sub_SatanPopCoplinkA);

		connections(SatanPopCoplinkB);
}

action(SatanPopCoplinkB) 
{
		file("pc\actors\Satan\xxx\BPopMnMB.ske",100,on,100); // second half. fall w/ gravity turned on
		break(off);
		//gravity(off);
		trigger(_allDIR);
		Nomove(on);

		connections(SatanPopCoplinkC);
}

action(SatanPopCoplinkC) 
{
		file("pc\actors\Satan\xxx\BPopMnMC.ske",100,off,100); // second half. fall w/ gravity turned on
//		file("pc\actors\chot\xxx\mstndfbk.ske",100,off,110,-1,-1,Sub_GetUpClearThrown84);
//		file("pc\actors\Chot\xxx\MRSd2Crl.ske",100,on,100); // go to crawl from on back
		break(off);
		trigger(_allDIR);

		nrintframes(15);
		ActionSubRoutine(Sub_SatanPopCoplinkC);
//		connections(GENCrawlSpreadOut);
}


SubRoutine(Sub_SatanPopCop)
{
		if(VFrame==20)
		{
			Sample(SFXManPunch,-1);
		}
		elseif(VFrame==44)
		{
			Sample(SFXManNeckSnap,-1);
		}
		elseif(VFrame==84)
		{
			//	start drinking blood
			//
		}
		elseif(VFrame==120)
		{
			//	stop drinking blood
			//
		}
		elseif(VFrame==182)
		{
			//	throw guy
			//
		}
		elseif(VFrame==292)
		{
			Sample(SFXBehemothAngry,-1);
		}
}

action(SatanPopCop)
{
		file("pc\actors\Satan\xxx\BPopMnS.ske",100,on,100);	//

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAPlayerOneOnly);


		//AlignXYZ(2.7,0,504);
		//AlignXYZ(2.70,0,252);
		AlignXYZ(1.30,0,252);
		TargetAngle(180);
		AttackHeight(100);
		AlignSlack(240);
		DistanceSlack(120);

		AlignStartFrame(19);
		AlignNrFrames(1);

		AttachActionStartAtFrame(19);
		DamageFrame(20);
		Power(0);
		AttachAction(SatanPopCoplinkA);
		TargetAIClass(_AIClassAllButAngel);

		//ActionSubRoutine(Sub_RandomKickedSFX);

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(SatanIdle4);
}


// ########################################################3
// Grab guy by ankles, light him on fire, and throw him at bob


SubRoutine(Sub_SetPlayerOnFire)
{
		callsub(Sub_InitSatanGrab);
		if(vframe>30&&vframe<140)
		{
			fxflag(_or,_fxFLAGFire);
		}
		elseif(VFrame==145)
		{
			callsub(Sub_DeInitSatanGrab);
		}
}


action(SatanSpinCoplink)
{
		file("pc\actors\Satan\xxx\BMFir_M.ske",100,on,100);
		break(off);
		gravity(off);
		trigger(_allDIR);

		ActionSubRoutine(Sub_SetPlayerOnFire);

		connections(CopThrownBack);
}


SubRoutine(Sub_SatanSpinCop)
{
		if(VFrame==9)
		{
			Sample(SFXManPunch,-1);
		}
}

action(SatanSpinCop)
{
		file("pc\actors\Satan\xxx\BMFir_S.ske",100,on,100);	//

		flag(_SXAAalignmovingslave|_SXAAdisablecollision|_SXAAdisablerotation|_SXAAPlayerOneOnly);

		//AlignXYZ(2.7,0,504);
		//AlignXYZ(10,0,181.7);
		AlignXYZ(-35,0,80);
		//AlignAngle(0);
		//AlignDistance(133);
		TargetAngle(180);
		AttackHeight(0);
		AlignSlack(240);
		DistanceSlack(200);

		AlignStartFrame(0);
		AlignNrFrames(10);

		AttachActionStartAtFrame(0);
		DamageFrame(100);
		Power(0);
		AttachAction(SatanSpinCoplink);
		TargetAIClass(_AIClassAllButAngel);


		ActionSubroutine(Sub_SatanSpinCop);

		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(SatanIdle4);
}





/*

Satan grab possessed man, snap head backwards and suck bob into his mouth through ruptured neck After dropping the man, he spits out bob at frame #295. bob throw forward at spawn frame:
		Attach at frame #21.  X=1.3621, Y=252.8029, Z=52.37

	Satan part:
		Satan\xxx\BPopMnS.3ds

	Possessed Man Part:
		Satan\xxx\BPopMnM.3ds





Satan grab bob chew on him then spit him out:
	Attach at frame #28: X=21.9104, Y=133.1549, Z=21.6098:

	Satan part:
		Satan\xxx\BEat_S.ske

	Bob part:
		Satan\xxx\BEat_B.ske




	Satan intro to the two man:
		Satan\xxx\AChrb_S1.ske

	Satan pulling cherub out of chest:X=10.3543, Y=69.5551, Z=-2.0068
		Satan\xxx\AChrb_S2.ske

	Evil Cherub half. gets thrown forward on last frame:
		Satan\xxx\AChrb_C.ske

---------------

Idle 1:
	Satan\xxx\Bidle1.ske

Wound when hit w/ huge anti Satan blast:
	Satan\xxx\Bwound.ske

Run Forward:
	Satan\xxx\Brun.3ds

Fly forward a few steps.  Randomize into the satan run:
	Satan\xxx\Bfly.ske

Satan Walk cycle:
	Satan\xxx\Bwalk.ske
*/