
/*
	All commands are now dynamic with the exception of:
	file(),spawn(),rnd(),rndmask(),polystrip(),spawnfromstart(),h/vFunc()
*/



/*
	call(pFlipUV,true,false,false,false);
	call(pScale,10,10,false);
	call(pRotate,0,0,128,false);
	call(pAngle,0,0,0);
	call(pColor,255,255,255,255);
	call(pTrans,0,0);
	call(pFlicControl,true,0,1,0);
	call(pFader,0,0,0,0);
	call(pWeight,1,1,1);
	call(pScalar,false,2,2);
	call(pSinusx,true,0,0,0);
	call(pSinusy,true,0,0,0);
	
	call(pLifespan,24);
	call(pCollision,true);
	call(pRebound,1);
	call(pColdeath,true);
	call(pRotatewithdir,false);
	call(pTridi,false);
	call(pKillwithactor,false);
	call(pSpawnFromStart,true);		//????
*/


actor(fx_NewParticleTestSub)
{
	//these should be controlled purely by lifespan!!!
	//as this routine is shared by spawned particles!!
	//ie: you should not use globals for a counter

		float(_declare,FreqCounter,0);
		float(_add,FreqCounter,0.1);

		if(FreqCounter>=1.0)
		{
			float(_set,FreqCounter,0);
		}
}

//rndcontrol for +,-,+- rnd values
//spawnFreq DYNAMIC???
//use_inertia_as_dpos ???


//	call(pFlicControl,false,0,1,0);

actor(fx_Subgirl)
{
		if(vactivetime==0)
		{
			call(pColor,255,255,255,128);
		}
}

actor(fx_Satanstriph)
{
		if(vactivetime==0)
		{
			call(pAngle,0,0,0);
		}
}

actor(fx_Satanstripv)
{
		if(vactivetime==0)
		{
			call(pAngle,1024,0,0);
		}
}

actor(fx_Satanstripd1)
{
		if(vactivetime==0)
		{
			call(pAngle,512,0,0);
		}
}

actor(fx_Satanstriphd2)
{
		if(vactivetime==0)
		{
			call(pAngle,-512,0,0);
		}
}




actor(fx_maserstriph)
{
		if(vactivetime==0)
		{
			call(pAngle,0,0,0);
		}
}

actor(fx_maserstripv)
{
		if(vactivetime==0)
		{
			call(pAngle,1024,0,0);
		}
}

actor(fx_maserstripd1)
{
		if(vactivetime==0)
		{
			call(pAngle,512,0,0);
		}
}

actor(fx_maserstriphd2)
{
		if(vactivetime==0)
		{
			call(pAngle,-512,0,0);
		}
}



actor(fx_chain2)
{
		if(vactivetime==0)
		{
			call(pAngle,0,1024,0);
		}
}

actor(fx_scalesatanblood)
{
		if(vactivetime==0)
		{
			call(pScale,40,40,false);
			call(pScalar,0,20,20);
		}
}

actor(fx_scale200)
{
		if(vactivetime==0)
		{
			call(pScale,200,200,false);
		}
}

actor(fx_scale100)
{
		if(vactivetime==0)
		{
			call(pScale,125,125,false);
		}
}


actor(fx_scale50)
{
		if(vactivetime==0)
		{
			call(pScale,50,50,false);
		}
}

actor(fx_mturret)
{
		if(vactivetime==0)
		{
			call(pColor,255,255,255,255);
			call(pScale,5,5,false);
		}
}

actor(fx_maserflare)
{
		if(vactivetime==0)
		{
			call(pColor,16,255,64,255);
			call(pScale,5,5,false);
		}
}

actor(fx_plasmawallhitzplane)
{
		if(vactivetime==0)
		{
			call(pAngle,0,1024,0);
			call(pFlipUV,false,false,true,true);
			call(pColor,255,255,255,128);
			call(pTridi,true,true);
		}
}
actor(fx_plasmawallstillzplane)
{
		if(vactivetime==0)
		{
			call(pAngle,0,1024,0);
			call(pFlipUV,true,false,true,false);
			call(pColor,255,255,255,255);
		}
}


actor(fx_plasmawallhitxplane)
{
		if(vactivetime==0)
		{
			call(pAngle,0,0,0);
			call(pFlipUV,false,false,true,true);
			call(pColor,255,255,255,128);
			call(pTridi,true,false);
		}
}
actor(fx_plasmawallstillxplane)
{
		if(vactivetime==0)
		{
			call(pAngle,0,0,0);
			call(pFlipUV,true,false,true,false);
			call(pColor,255,255,255,255);
		}
}




actor(fx_riotshlda1hit)
{
		if(vactivetime==0)
		{
			call(pAngle,0,486,0);
			call(pFlipUV,false,false,true,true);
		}
}
actor(fx_riotshlda2hit)
{
		if(vactivetime==0)
		{
			call(pAngle,0,324,0);
			call(pFlipUV,false,false,true,true);
		}
}
actor(fx_riotshlda3hit)
{
		if(vactivetime==0)
		{
			call(pAngle,0,162,0);
			call(pFlipUV,false,false,true,true);
		}
}
actor(fx_riotshlda4hit)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-162,0);
			call(pFlipUV,false,false,true,true);
		}
}
actor(fx_riotshlda5hit)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-324,0);
			call(pFlipUV,false,false,true,true);
		}
}
actor(fx_riotshlda6hit)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-486,0);
			call(pFlipUV,false,false,true,true);
		}
}


actor(fx_riotshlda1off)
{
		if(vactivetime==0)
		{
			call(pAngle,0,486,0);
			call(pFlipUV,false,true,true,false);
		}
}
actor(fx_riotshlda2off)
{
		if(vactivetime==0)
		{
			call(pAngle,0,324,0);
			call(pFlipUV,false,true,true,false);
		}
}
actor(fx_riotshlda3off)
{
		if(vactivetime==0)
		{
			call(pAngle,0,162,0);
			call(pFlipUV,false,true,true,false);
		}
}
actor(fx_riotshlda4off)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-162,0);
			call(pFlipUV,false,true,true,false);
		}
}
actor(fx_riotshlda5off)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-324,0);
			call(pFlipUV,false,true,true,false);
		}
}
actor(fx_riotshlda6off)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-486,0);
			call(pFlipUV,false,true,true,false);
		}
}

actor(fx_riotshlda1on)
{
		if(vactivetime==0)
		{
			call(pAngle,0,486,0);
			call(pFlipUV,true,false,true,false);
		}
}
actor(fx_riotshlda2on)
{
		if(vactivetime==0)
		{
			call(pAngle,0,324,0);
			call(pFlipUV,true,false,true,false);
		}
}
actor(fx_riotshlda3on)
{
		if(vactivetime==0)
		{
			call(pAngle,0,162,0);
			call(pFlipUV,true,false,true,false);
		}
}
actor(fx_riotshlda4on)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-162,0);
			call(pFlipUV,true,false,true,false);
		}
}
actor(fx_riotshlda5on)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-324,0);
			call(pFlipUV,true,false,true,false);
		}
}
actor(fx_riotshlda6on)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-486,0);
			call(pFlipUV,true,false,true,false);
		}
}



actor(fx_riotshlda1)
{
		if(vactivetime==0)
		{
			call(pAngle,0,486,0);
		}
}
actor(fx_riotshlda2)
{
		if(vactivetime==0)
		{
			call(pAngle,0,324,0);
		}
}
actor(fx_riotshlda3)
{
		if(vactivetime==0)
		{
			call(pAngle,0,162,0);
		}
}
actor(fx_riotshlda4)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-162,0);
		}
}
actor(fx_riotshlda5)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-324,0);
		}
}
actor(fx_riotshlda6)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-486,0);
		}
}


actor(fx_tracerac)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-1024,0);
		}
}

actor(fx_gunflashnorm)
{
		if(vactivetime==0)
		{
			call(pAngle,0,0,0);
		}
}


actor(fx_gunflashvert)
{
		if(vactivetime==0)
		{
			call(pAngle,1024,0,-1024);
		}
}

actor(fx_gunflashdiag1)
{
		if(vactivetime==0)
		{
			call(pAngle,512,0,-1024);
		}
}

actor(fx_gunflashdiag2)
{
		if(vactivetime==0)
		{
			call(pAngle,-512,0,-1024);
		}
}

actor(fx_gunstroberot)
{
		if(vactivetime==0)
		{
			float(_add,muzzflashang,567);
			float(_and,muzzflashang,4095);
			call(pAngle,0,0,muzzflashang);
			call(pAngle,1024,muzzflashang,0);
		}
}

actor(fx_scale35)
{
		if(vactivetime==0)
		{
			call(pScale,35,35,false);
		}
}

actor(fx_scale10)
{
		if(vactivetime==0)
		{
			call(pScale,10,10,false);
		}
}

actor(fx_scale5)
{
		if(vactivetime==0)
		{
			call(pScale,5,5,false);
		}
}

actor(fx_tracersmall)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-1024,0);
			call(pScale,5,5,false);
			//call(pColor,192,255,255);
		}
}

actor(fx_gunstrobesmall)
{
		if(vactivetime==0)
		{
			float(_add,muzzflashang,567);
			float(_and,muzzflashang,4095);
			call(pAngle,0,0,muzzflashang);
			call(pScale,6,6,false);
			//call(pColor,192,255,255);
		}
}

actor(fx_gunflashhorizsmall)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-1024,0);
			call(pScale,5,5,false);
			//call(pColor,192,255,255);
		}
}

actor(fx_gunflashvertsmall)
{
		if(vactivetime==0)
		{
			call(pAngle,1024,-1024,0);
			call(pScale,5,5,false);
			//call(pColor,192,255,255);
		}
}

actor(fx_gunflashdiag1small)
{
		if(vactivetime==0)
		{
			call(pAngle,512,-1024,0);
			call(pScale,5,5,false);
			//call(pColor,192,255,255);
		}
}

actor(fx_gunflashdiag2small)
{
		if(vactivetime==0)
		{
			call(pAngle,-512,-1024,0);
			call(pScale,5,5,false);
			//call(pColor,192,255,255);
		}
}


actor(fx_gunstrobeac)
{
		if(vactivetime==0)
		{
			float(_add,muzzflashang,567);
			float(_and,muzzflashang,4095);
			call(pAngle,0,0,muzzflashang);
		}
}

actor(fx_gunflashhorizac)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-1024,0);
		}
}

actor(fx_gunflashvertac)
{
		if(vactivetime==0)
		{
			call(pAngle,1024,-1024,0);
		}
}

actor(fx_gunflashdiag1ac)
{
		if(vactivetime==0)
		{
			call(pAngle,512,-1024,0);
		}
}

actor(fx_gunflashdiag2ac)
{
		if(vactivetime==0)
		{
			call(pAngle,-512,-1024,0);
		}
}





actor(fx_gunbulhorizac)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-1024,0);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
		}
}

actor(fx_gunbulvertac)
{
		if(vactivetime==0)
		{
			call(pAngle,1024,-1024,0);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
		}
}

actor(fx_gunbuldiag1ac)
{
		if(vactivetime==0)
		{
			call(pAngle,512,-1024,0);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
		}
}

actor(fx_gunbuldiag2ac)
{
		if(vactivetime==0)
		{
			call(pAngle,-512,-1024,0);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
		}
}


actor(fx_subgirltracer)
{
		if(vactivetime==0)
		{
			call(pColor,128,255,255,255);
		}
}

actor(fx_droidtracer)
{
		if(vactivetime==0)
		{
			call(pAngle,0,0,0);
			call(pScale,5,5,false);
			call(pColor,128,128,255,255);
		}
}

actor(fx_droidtraceronZ)
{
		if(vactivetime==0)
		{
			call(pAngle,0,-1024,0);
			call(pScale,5,5,false);
			call(pColor,128,128,255,255);
		}
}



actor(fx_gunbulhorizbeast)
{
		if(vactivetime==0)
		{
			call(pAngle,0,0,-1024);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
			call(pColor,128,192,255,192);
		}
}

actor(fx_gunbulvertbeast)
{
		if(vactivetime==0)
		{
			call(pAngle,1024,0,-1024);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
			call(pColor,128,192,255,192);
		}
}

actor(fx_gunbuldiag1beast)
{
		if(vactivetime==0)
		{
			call(pAngle,512,0,-1024);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
			call(pColor,128,192,255,192);
		}
}

actor(fx_gunbuldiag2beast)
{
		if(vactivetime==0)
		{
			call(pAngle,-512,0,-1024);
			call(pFlipUV,true,false,false,false);
			call(pScale,25,10,false);
			call(pColor,128,192,255,192);
		}
}

actor(fx_flipuv)
{
		if(vactivetime==0)
		{
			call(pFlipUV,true,true,false,false);
		}
}


actor(fx_antirotate16)
{
		if(vactivetime==0)
		{
			call(pRotate,0,0,-16,false);
		}
}

actor(fx_beastfx)
{
		if(vactivetime==0)
		{
			call(pColor,255,64,64,255);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,-16,false);
		}
}

actor(fx_beastfx2)
{
		if(vactivetime==0)
		{
			call(pColor,255,64,64,255);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,16,false);
		}
}

actor(fx_priestfx)
{
		if(vactivetime==0)
		{
			call(pColor,128,128,255,128);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,-16,false);
		}
}

actor(fx_transport)
{
		if(vactivetime==0)
		{
			call(pColor,255,255,48,255);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,-16,false);
		}
		elseif(vactivetime==5)
		{
			call(pColor,255,128,0,128);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,-16,false);
		}
		elseif(vactivetime==15)
		{
			call(pColor,128,128,128,100);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,-16,false);
		}
		elseif(vactivetime==35)
		{
			call(pColor,80,80,80,40);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,-16,false);
		}
}

actor(fx_priestfx2)
{
		if(vactivetime==0)
		{
			call(pColor,128,128,255,128);
			call(pFader,0,0,0,1);
			call(pRotate,0,0,16,false);
		}
}



actor(fx_antirotate8)
{
		if(vactivetime==0)
		{
			call(pRotate,0,0,-8,false);
		}
}


actor(fx_madrotate)
{
		if(vactivetime==0)
		{
			call(pRotate,256,256,256,false);
		}
}
actor(fx_madrotatenegative)
{
		if(vactivetime==0)
		{
			call(pRotate,-256,-256,-256,false);
		}
}

actor(fx_madrotatenegative64)
{
		if(vactivetime==0)
		{
			call(pFlipUV,true,true,false,false);
			call(pRotate,-64,-64,-64,false);
		}
}



actor(fx_buzzsawsparks)
{
		if(vactivetime==0)
		{
			call(pScale,1,2,false);
		}
}

actor(fx_darkbloood)
{
		if(vactivetime==0)
		{
			//call(pColor,255,255,255,100);
			//call(pTrans,1,0);
			call(pScale,10,10,true);
		}
}

actor(fx_flamethrowsmoke)
{
		if(vactivetime==0)
		{
			call(pScale,24,24,false);
			call(pTrans,1,0);
			call(pFader,0,0,0,3);
		}
}

actor(fx_pumpgunsmoke)
{
		if(vactivetime==0)
		{
			call(pScale,16,16,false);
			call(pTrans,0,0);
			call(pColor,100,100,100,80);
			call(pScalar,2,8,8);
		}
}

actor(fx_machinegunsmoke)
{
		if(vactivetime==0)
		{
			call(pScale,16,16,false);
			call(pTrans,0,0);
			call(pColor,100,100,100,80);
			call(pScalar,2,8,8);
		}
}

actor(fx_machinegunsmokeac)
{
		if(vactivetime==0)
		{
			call(pScale,20,20,false);
			call(pTrans,0,0);
			call(pColor,100,100,100,128);
		}
}

actor(fx_harpoonsmoke)
{
		if(vactivetime==0)
		{
			call(pScale,60,60,false);
			call(pTrans,0,0);
			call(pColor,100,100,100,80);
			call(pScalar,2,30,30);
		}
}

actor(fx_buzzsawsmokesub)
{
		if(vactivetime==0)
		{
			call(pScale,24,24,false);
			call(pTrans,1,0);
			call(pFader,0,0,0,3);
		}
}


actor(fx_doorsteam)
{
		if(vactivetime==0)
		{
			call(pScale,30,30,false);
			call(pColor,192,255,255,16);
			call(pFader,0,0,0,-4);
			call(pAngle,0,0,-1024);
		}
}

actor(fx_radsteam)
{
		if(vactivetime==0)
		{
			call(pScale,30,30,false);
			call(pColor,10,255,10,16);
			call(pFader,0,0,0,-4);
			call(pAngle,0,0,-1024);
			//call(pRotate,0,0,64,true);
		}
}

actor(fx_icesteam)
{
		if(vactivetime==0)
		{
			call(pRotate,0,0,-64,true);
		}
}


actor(fx_bloodbig)
{
		if(vactivetime==0)
		{
			call(pScale,5,5,false);
		}
}


actor(fx_torchflareburn)
{
		if(VActiveTime==0)
		{
			call(pColor,16,32,255,255);
			call(pScale,2,2,false);
		}
}

actor(fx_torchflareidle)
{
		if(VActiveTime==0)
		{
			call(pColor,16,64,255,255);
			call(pScale,1.5,1.5,false);
		}
}

actor(fx_coplaserflareblue)
{
		if(VActiveTime==0)
		{
			call(pColor,8,8,255,192);
			call(pScale,2.5,2.5,false);
		}
}

actor(fx_heavycoplaserflare)
{
		if(VActiveTime==0)
		{
			call(pColor,128,128,255,192);
			call(pScale,3,3,false);
		}
}

actor(fx_coplaserflarered)
{
		if(VActiveTime==0)
		{
			call(pColor,255,8,8,192);
			call(pScale,2.5,2.5,false);
		}
}

actor(fx_rocklaserflarered)
{
		if(VActiveTime==0)
		{
			call(pColor,255,8,8,192);
			call(pScale,4,4,false);
		}
}

actor(fx_rocklaser)
{
		if(VActiveTime==0)
		{
			call(pScale,1,20,false);
		}
}


actor(fx_white)
{
		if(VActiveTime==0)
		{
			call(pColor,255,255,255,192);
		}
}
actor(fx_red)
{
		if(VActiveTime==0)
		{
			call(pColor,255,0,0,192);
		}
}

actor(fx_laserflickerred)
{
		if(VActiveTime==0)
		{
			float(_rnd2,LaserWallColour,127);
			float(_add,LaserWallColour,128);
			call(pColor,LaserWallColour,0,0,192);
		}
}

actor(fx_laserflickerblue)
{
		if(VActiveTime==0)
		{
			float(_rnd2,LaserWallColour,127);
			float(_add,LaserWallColour,128);
			call(pColor,0,0,LaserWallColour,192);
		}
}

actor(fx_laserflickergreen)
{
		if(VActiveTime==0)
		{
			float(_rnd2,LaserWallColour,127);
			float(_add,LaserWallColour,128);
			call(pColor,80,LaserWallColour,50,192);
		}
}

actor(fx_laserflickerredx)
{
		if(VActiveTime==0)
		{
			float(_rnd2,LaserWallColour,127);
			float(_add,LaserWallColour,128);
			call(pColor,LaserWallColour,0,0,192);
			call(pAngle,0,1028,0);
		}
}

actor(fx_redx)
{
		if(VActiveTime==0)
		{
			call(pColor,255,0,0,192);
			call(pAngle,0,1028,0);
		}
}
		
actor(fx_green)
{
		if(VActiveTime==0)
		{
			call(pColor,0,255,0,192);
		}
}
actor(fx_blue)
{
		if(VActiveTime==0)
		{
			call(pColor,0,0,255,192);
		}
}
actor(fx_orange)
{
		if(VActiveTime==0)
		{
			call(pColor,255,120,10,192);
		}
}
actor(fx_yellow)
{
		if(VActiveTime==0)
		{
			call(pColor,255,255,0,192);
		}
}
actor(fx_yellowx)
{
		if(VActiveTime==0)
		{
			call(pColor,255,255,0,192);
			call(pAngle,0,1028,0);
		}
}
	
actor(fx_cyan)
{
		if(VActiveTime==0)
		{
			call(pColor,0,255,255,192);
		}
}
actor(fx_purple)
{
		if(VActiveTime==0)
		{
			call(pColor,255,0,255,192);
		}
}
actor(fx_laserdisc)
{
		if(VActiveTime==0)
		{
			call(pColor,LaserDiscColorR,LaserDiscColorG,LaserDiscColorB,192);
		}
}

actor(fx_yellowa255)
{
		if(VActiveTime==0)
		{
			call(pColor,255,255,0,96);
		}
}
actor(fx_heavyland)
{
		if(VActiveTime==0)
		{
			call(pScale,10,10,false);
		}
}



actor(fx_add)
{
		if(VActiveTime==0)
		{
			call(pTrans,0,0);
			call(pColor,128,128,128,128);
		}
}

actor(fx_sub)
{
		if(VActiveTime==0)
		{
			call(pTrans,1,0);
			call(pColor,32,32,32,128);
		}
}

actor(fx_batteryflare)
{
		if(VActiveTime==0)
		{
			call(pColor,0,0,255,192);
			call(pScale,5,5,false);
		}
}

actor(fx_activebatteryflare)
{
		if(VActiveTime==0)
		{
			call(pColor,255,0,0,192);
			call(pScale,5,5,false);
		}
}
