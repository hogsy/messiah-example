/*
Actors:

Chot
Chot2sp
Chot3ct
chot4ot
chotmot	(Mask and open trench)
ChotOT
ChotCT
*/




//*******************************************************************8
// WALK CYCLES

Action(Chotwalk)
{
		file("pc\actors\Chot\xxx\Mwkshtcy.xxx",100,on);
		trigger(_DIRwalking|_DIRforward);
		break(on);
//		offset(on);
//		offsetstartframe(5);
//		gravity(off);
		connections(Chotwalk,ChotRun,ChotStandShoot,Chotidle);
}


//*******************************************************************8
//RUN CYCLES
action(ChotRun)
{

		file("pc\actors\Chot\xxx\Mrun1p.xxx",100,on);
		trigger(_DIRforward);
		break(on);
//		offset(on);
//		offsetstartframe(9);
		connections(ChotRun,ChotRunJump,Chotwalk,ChotIdle);
}

action(ChotRunRight90)
{
		file("pc\actors\Chot\xxx\mrnshtl.ske",100,on);
		nrintframes(4);
		trigger(_DIRsideRight);
		break(on);
		connections(ChotRunRight90,ChotRun,Chotwalk,ChotStandShoot,ChotIdle);
}

action(ChotRunLeft90)
{
		file("pc\actors\Chot\xxx\mrnshtr.ske",100,on);
		nrintframes(4);
		trigger(_DIRsideleft);
		break(on);
		connections(ChotRunLeft90,ChotRun,Chotwalk,ChotStandShoot,ChotIdle);
}

action(ChotRunRight45)
{
		file("pc\actors\Chot\xxx\mrnSh45L.ske",100,on);
		nrintframes(4);
		trigger(_DIRsideRight);
		break(on);
		connections(ChotRunRight45,ChotRun,Chotwalk,ChotStandShoot,ChotIdle);
}

action(ChotRunLeft45)
{
		file("pc\actors\Chot\xxx\mrnSh45R.ske",100,on);
		nrintframes(4);
		trigger(_DIRsideLeft);
		break(on);
		connections(ChotRunLeft45,ChotRun,Chotwalk,ChotStandShoot,ChotIdle);
}



//***************************Run Backwards******************************

action(ChotRunBack)
{

//		file("pc\actors\Chot\xxx\Mrnbkstp.xxx",100,off);
		file("pc\actors\Chot\xxx\Mrnbkcyp.ske",100,on);
		trigger(_DIRbackward);
		break(on);
//		offset(on);
//		offsetstartframe(9);
//		gravity(off);
		connections(ChotRunBackJump,ChotRunBack,ChotIdle);
}

action(ChotRunJump)
{

		file("pc\actors\Chot\xxx\Mjmp3p.xxx",100,off);
		trigger(_DIRjump);
//		offset(off);
//		offsetstartframe(1);
//		gravity(off);
		connections(ChotRun,Chotidle);

}

action(ChotRunBackJump)
{

		file("pc\actors\Chot\xxx\Mjmpbkp.xxx",100,off);
		trigger(_DIRjump);
		break(off);
//		offset(off);
//		offsetstartframe(1);
//		gravity(off);
		connections(ChotRunback,ChotIdle);

}


action(ChotPushBack)
{
		file("pc\actors\Chot\xxx\Mpshbk6p.xxx",100,off);
		trigger(_DIRjump);
		connections(Chotidle);
}


action(ChotPossesed)
{
		//file("pc\actors\Chot\xxx\mblprosp.xxx",100,off);
		//file("pc\actors\Chot\xxx\mwundg.xxx",100,off);
		file("pc\actors\prost1\xxx\mposs1.xxx",100,off);

		trigger(_DIRactorbulletcol);
		break(off);
		connections(Chotidle);
}

action(ChotShot)
{
		file("pc\actors\Chot\xxx\mwundg.xxx",100,off);
		trigger(_DIRactorbulletcol);
//		gravity(off);
//		collision(off);
		connections(Chotidle);
}

Action(Chotpickup)
{
		file("pc\actors\chot\xxx\Mneidl4p.xxx",100,off);
		trigger(_DIRaction);
		connections(Chotidle);
}


action(ChotIdle)
{
		file("pc\actors\Chot\xxx\Mneidl2p.xxx",2,on,-1,-1,Sub_RandomCopScratchesCrotch); //ass scratch
		file("pc\actors\Chot\xxx\Mneidl3p.xxx",4,on,-1,-1,Sub_RandomCopScratchesCrotch);//crotch scratch
		file("pc\actors\Chot\xxx\Mneidl1p.xxx",100,on);//look around

		trigger(_allDIR);
		break(on);
//		collision(on);
		connections(GeneralThrownBack,ChotStandShoot,ChotRun,ChotRunBack,ChotWalk,Chotpickup,ChotPushback,ChotIdle);
}



//*********************Special Chot Actions (eat, ritual, etc) **************


action(ChotEatCop)
{
		file("pc\actors\Chot\xxx\ChEat2.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		//nomove(true)
		connections(ChotEatCop);
}

action(ChotEatCop2)
{
		file("pc\actors\Chot\xxx\ChEat1.ske",50,on);
		file("pc\actors\Chot\xxx\ChEat2.ske",100,on);
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		intforloop(on);
		//nomove(true)
		connections(ChotEatCop2);
}


action(ChotStandUpFromEat)
{
		file("pc\actors\Chot\xxx\ChEatSt2.ske",100,off);
		trigger(_allDIR);
		break(on);
		nrintframes(8);
		connections(ChotStandUpFromEat);
}	

//*************************** Shoot! ******************* 
action(ChotStandShoot)
{
//		file("pc\actors\chot\xxx\Mfir2stp.xxx",100,off);
//		file("pc\actors\chot\xxx\Mfir2cyG.xxx",100,on);
//		file("pc\actors\chot\xxx\Mfir2ndp.xxx",100,off);
		file("pc\actors\chot\xxx\Mfir2cyp.ske",100,on);
		trigger(_DIRshoot);
		break(on);
		connections(ChotRunBack,Chotwalk,ChotRun,ChotStandShoot,Chotidle);
}



action(GeneralThrownBack)
{
		file("pc\actors\Chot\xxx\mwundg.xxx",100,off);
		//file("pc\actors\prost1\xxx\shotstrt.xxx",100,on);
		trigger(_DIRactorbulletcol);
		break(on);
		connections(GeneralThrownBackEnd);

}

action(GeneralThrownBackEnd)
{
		file("pc\actors\prost1\xxx\shotstrt.xxx",100,off);
		trigger(_DIRallcol);
		break(off);
		connections(GeneralThrownBackEnd2);

}


action(GeneralThrownBackEnd2)
{
		file("pc\actors\prost1\xxx\shotend.ske",100,on);
		trigger(_alldir);
		break(off);
		connections(GeneralThrownBackEnd);
}


Action(ChotThrowgrenade)
{
		file("pc\actors\copm\xxx\Mthrwgrp.xxx",100,on);
		trigger(_allDir);
		break(off);
		connections(Chotidle);
}


action(ChotAboutFace)
{
		file("pc\actors\copm\xxx\mspnp.xxx",100,off);
		trigger(_allDIR);
		break(off);
		connections(Chotidle);
}


action(ChotJump)
{
		file("pc\actors\prost1\xxx\jump2.ske",100,off);
		nrintframes(3);
		trigger(_allDIR);
		connections(ChotJump);
}


action(ChotWound1)
{
		//file("pc\actors\copm\xxx\Mthrwfrg.xxx",100,off);
		file("pc\actors\chot\xxx\Mthrwfg2.ske",100,off);
		trigger(_DIRactorbulletcol);
		break(off);
		gravity(off);
		collision(off);
		move(0,0.1,0);
		//nrintframes(4);
		connections(ChotIdle);
}

action(ChotWound2)
{
		file("pc\actors\chot\xxx\mwundg2.ske",100,off);
		trigger(_DIRactorbulletcol);
		gravity(off);
		collision(off);
		move(0,0.1,0);
		break(off);
		nrintframes(4);
		connections(ChotWound2b);
}
action(ChotWound2b)
{
		file("pc\actors\copm\xxx\Mstun2p.xxx",100,off);
		//trigger(_allDir);
		gravity(off);
		collision(off);
		move(0,0.1,0);
		trigger(_allDIR);
		break(off);
		nrintframes(4);
		connections(ChotIdle);
}
