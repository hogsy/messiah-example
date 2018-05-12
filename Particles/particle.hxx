
/*
  VERY IMPORTANT NOTE: Do not disturb the order of the first 7 particle types!
*/



//newest:
//		rebound(factor,settle)	settle==1 collision optimization ..cool! (horizontal settle)
//		tridi(false,displace)	you can z displace (aligned to the viewcam) a sprite so it doesn't cut into scenery, ie: i use it on explosions
//								NOTE: if displace is set to true on a polystrip, then that does something quite specific, come ask me!!
//
//		flipuv(false,false,false,false) <---- LAST TWO PARAMETERS MUST ALWAYS BE FALSE!
//
//		follow(true)			-- use the actors matrix when available every frame, not just the spawn frame!
//								-- hint: use for particles displayed for 1 frame only ,not wise for some types though!
//		scalar(2,startXsize,startYsize)
//		scale(x,y,random?)
//		priority: 0=always, 1=maybe
//		trans: second param is a frame number to swap transparancy type on, 0 means no swap
//		rotate: last flag = alternate rotation flip flop
//		fliccontrol: the last parameter when set to 'true' and while animated is set to 'false' will select
//						a random frame from the flic!!
//		flipuv(true,false);
//		func(hrout,vrout);		//ask me!!
//		collision(true,0);		//true/false,calc every nth frame (0 = every frame,1=every other frame,etc..)
//		spawnfromstart(true);
//	all spans come from orig start pos, not current pos

//name,operation,position,inertia,controlroutine
//where operation can be: -1 (static), 0 (root matrix), >=1 (bone matrix)
//controlroutine is either an actor or -1
//spawnparticle(NewparticleTest,-1,GactorPos,GactorIne,controlroutine);

//polystrips: NOTE: uses scale differently: 
//   xscale is used for distance of 1st strip, yscale is used for height of all strips

//flicontrol: animate,start frame,play speed,play direction
//trans: 0=add,1=sub,2=none
//polystrip: true?,use texture?
//Scalar: 0=disable,1=shrinktodeath, 2=growtilldeath
//rndmask: 0=positive only, 1=negative only, 2=pos & neg directions
//killwithactor() added
//sinus(true,inc,range,rnd)


//NOTE: goofx uses xscale as base and yscale as a randomizer
//random frames are automatically selected for goo FX













//---------------------------------------------------------------------------- goo fx
particle(fx_bulletholeglass)
{
		file(fx_bulletholes3header);
		lifespan(3);
		weight(0,0,0);
		scale(15,15,false);
		color(255,255,255,100);
		fader(0,0,0,0);
		trans(0,0);
		priority(0);
		follow(false);
}

particle(fx_bulletholecrack)
{
		file(fx_bulletholesheader);
		lifespan(3);
		weight(0,0,0);
		scale(12,12,false);
		color(255,255,255,100);
		fader(0,0,0,0);
		trans(0,0);
		priority(0);
		follow(false);
}

particle(fx_bullethole)
{
		file(fx_bulletholes2header);
		lifespan(3);
		weight(0,0,0);
		scale(6,6,false);
		color(255,255,255,100);
		fader(0,0,0,0);
		trans(1,0);
		priority(0);
		follow(false);
}

particle(fx_bloodstain)
{
		file(fx_bloodstainheader);
		lifespan(3);
		color(255,255,255,100);
		fader(0,0,0,0);
		scale(35,0,false);
		weight(0,0.3,0);
		trans(1,0);
		priority(0);
		follow(false);
}

//---------------------------------------------------------------------------- target fx

particle(fx_crossin)
{
		file(fx_2crossoutheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(5,5,false);
		fliccontrol(false,0,1,0);
		color(255,101,17,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}


particle(fx_crossout)
{
		file(fx_2crossoutheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(14,14,false);
		fliccontrol(false,0,1,0);
		color(255,255,0,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_skull)
{
		file(fx_skullheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(3,3,false);
		fliccontrol(false,0,1,0);
		color(255,255,255,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}


//---------------------------------------------------------------------------- slugwake fx

particle(fx_slugwake)
{
		file(fx_slugwakeheader);
		lifespan(64);
		collision(false,0);
		rebound(0,false);
		coldeath(false);

		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(10,10,true);
		fliccontrol(false,0,0,true);
		color(224,224,255,128);
		fader(0,0,0,2);
		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}



//---------------------------------------------------------------------------- riotsheild fx
particle(fx_riotshield256)
{
		file(fx_riotshld256header);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,false);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(0.3125,0.3125,false);
		fliccontrol(false,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(true);
		func(-1,-1,-1);
		flipuv(false,false,true,false);
		priority(0);
		follow(true);
}

//---------------------------------------------------------------------------- bullet fx
particle(fx_bulletshrapnel)
{
		file(fx_bulletshrapnelheader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,8,16,8);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.05,0.2,0.05);
		angle(0,0,0);
		rotate(128,128,128,false);
		scale(10,10,true);
		fliccontrol(false,0,0,0);
		color(255,255,255,255);
		fader(0,0,0,1);
		trans(2,0);
		scalar(1,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_paktracer)
{
		file(fx_paktracerheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(512,0,0,false);
		scale(5,5,false);
		fliccontrol(false,0,0,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(true);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_tracer)
{
		file(fx_tracerheader);
		lifespan(24);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(512,0,0,false);
		scale(10,10,false);
		fliccontrol(false,0,0,true);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(true);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_machinegunshell)
{
		file(fx_gunshellheader);
		lifespan(128);
		collision(true,5);
		rebound(1.2,true);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,2,0,2);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0.5,0);
		angle(0,0,0);
		rotate(0,0,256,true);
		scale(2,2,false);
		fliccontrol(true,0,1,0);
		color(240,240,240,255);
		fader(0,0,0,0);
		trans(2,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_machinegunshellAI)
{
		file(fx_gunshellheader);
		lifespan(16);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,2,0,2);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0.5,0);
		angle(0,0,0);
		rotate(0,0,256,true);
		scale(2,2,false);
		fliccontrol(true,0,1,0);
		color(255,255,240,255);
		fader(0,0,0,16);
		trans(2,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_flamethrowerburn)
{
		file(fx_puff2header);
		lifespan(6);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(12,12,false);
		fliccontrol(true,0,2.666,0);
		color(192,192,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_flamethrowerroast)
{
		file(fx_xplobig4header);
		lifespan(19);
		collision(true,3);
		rebound(1.2,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(18,18,false);
		fliccontrol(true,0,0.421,0);

		color(0,0,255,218);
		fader(-12,-7,12,-2);

		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);

		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}


//---------------------------------------------------------------------------- blood fx
//-------relative blood
particle(fx_bloodspurtREL)
{
		file(fx_bloodspurtheader);
		lifespan(7);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(6,3,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(true);
}

particle(fx_bloodREL)
{
		file(Fx_BloodHeader);
		lifespan(64);
		collision(true,5);
		rebound(0,false);
		coldeath(true);
		spawn(true);
		spawnfreq(0.5);
		spawnmax(2);
		spawnrecurs(false);
		spawninertia(true);
		spawnfromstart(true);
		spawnrnd(0,0,0,10,10,10);
		spawnlifespan(48);
		spawnweight(0.05,0.2,0.05);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,10,10,10);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.05,0.2,0.05);
		angle(0,0,0);
		rotate(0,0,256,true);
		scale(5,5,true);
		fliccontrol(false,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,1,1);
		killwithactor(false);

		func(fx_bloodstain,fx_bloodstain,_pFuncBlood);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);			//gurp SHOULD BE TRUE ...collision problems!!
}

particle(fx_bloodsprayREL)
{
		file(Fx_BloodHeader);
		lifespan(48);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(6);
		spawnrecurs(true);
		spawninertia(false);
		spawnfromstart(true);
		spawnrnd(0,0,0,10,10,10);
		spawnlifespan(48);
		spawnweight(0.05,0.2,0.05);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(false,0);
		rnd(0,0,0,10,10,10);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.05,0.2,0.05);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,1,false);
		fliccontrol(false,0,1,0);
		color(148,0,0,112);
		fader(0,0,0,1);
		trans(1,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(true);
}



//-------absolute blood
particle(fx_bloodspurt)
{
		file(fx_bloodspurtheader);
		lifespan(7);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(6,3,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_blood)
{
		file(Fx_BloodHeader);
		lifespan(64);
		collision(true,3);
		rebound(0,false);
		coldeath(true);
		spawn(true);
		spawnfreq(0.5);
		spawnmax(2);
		spawnrecurs(false);
		spawninertia(true);
		spawnfromstart(true);
		spawnrnd(0,0,0,10,10,10);		//gurp
		spawnlifespan(48);
		spawnweight(0.1,0.4,0.1);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,10,10,10);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.1,0.4,0.1);
		angle(0,0,0);
		rotate(0,0,256,true);
		scale(5,5,true);
		fliccontrol(false,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,1,1);
		killwithactor(false);

		func(fx_bloodstain,fx_bloodstain,_pFuncBlood);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}
particle(fx_bloodlesser)
{
		file(Fx_BloodHeader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(0.5);
		spawnmax(2);
		spawnrecurs(false);
		spawninertia(true);
		spawnfromstart(true);
		spawnrnd(0,0,0,10,10,10);		//gurp
		spawnlifespan(24);
		spawnweight(0.1,0.4,0.1);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,10,10,10);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.1,0.4,0.1);
		angle(0,0,0);
		rotate(0,0,256,true);
		scale(5,5,true);
		fliccontrol(false,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,1,1);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


particle(fx_bloodspray)
{
		file(Fx_BloodHeader);
		lifespan(48);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(6);
		spawnrecurs(true);
		spawninertia(false);
		spawnfromstart(true);
		spawnrnd(0,0,0,10,10,10);		//gurp
		spawnlifespan(48);
		spawnweight(0.1,0.4,0.1);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(false,0);
		rnd(0,0,0,10,10,10);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.1,0.4,0.1);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,1,false);
		fliccontrol(false,0,1,0);
		color(148,0,0,112);
		fader(0,0,0,1);
		trans(1,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


particle(fx_footbloodspray)
{
		file(Fx_BloodHeader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(4);
		spawnrecurs(true);
		spawninertia(false);
		spawnfromstart(true);
		spawnrnd(0,0,0,6,8,6);
		spawnlifespan(32);
		spawnweight(0.1,0.2,0.1);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(false,0);
		rnd(0,0,0,6,8,6);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.1,0.2,0.1);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,2,false);
		fliccontrol(false,0,1,0);
		color(148,0,0,112);
		fader(0,0,0,1);
		trans(1,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

//---------------------------------------------------------------------------- other fx

particle(fx_electricstrip)
{
		file(fx_stripheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,20,false);			//(1,40
		fliccontrol(true,0,1,0);
		color(255,0,0,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_laserstrip)
{
		file(Fx_stripheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,10,false);
		fliccontrol(false,0,1,0);
		color(255,8,8,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_Vlaserstrip)
{
		file(Fx_stripheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		polystrip(true,true);
		tridi(true,true);
		rnd(0,0,0,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,20,false);
		fliccontrol(false,0,1,0);
		color(255,8,8,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_actorsmoke)
{
		file(fx_smokeyheader);
		lifespan(9);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		/*
		spawnfreq(1);
		spawnmax(19);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(15,0,15,2,4,2);
		spawnlifespan(19);
		spawnweight(0,0,0);
		spawnfromstart(true);
		*/

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(20,0,20,3,8,3);
		rndmask(2,0,2,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(12,12,false);
		color(0,255,255,128);
		fader(0,0,0,0);
		trans(0,0);
		fliccontrol(true,0,1.777,0);
		scalar(1,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_actorfire)
{
		file(fx_fieryheader);
		lifespan(9);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		/*
		spawnfreq(1);
		spawnmax(19);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(15,0,15,2,4,2);
		spawnlifespan(19);
		spawnweight(0,0,0);
		spawnfromstart(true);
		*/

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(15,0,15,4,8,4);
		rndmask(2,0,2,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(12,12,false);
		color(255,255,255,128);
		fader(0,0,0,0);
		trans(0,0);
		fliccontrol(true,0,1.777,0);
		scalar(1,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_evilfire)
{
		file(fx_fieryheader);
		lifespan(19);
		collision(false,0);
		rebound(0,false);
		coldeath(false);

		spawn(true);
		spawnfreq(0.5);
		spawnmax(9);
		spawnrecurs(false);
		spawninertia(false);
		spawnfromstart(true);
		spawnrnd(10,0,10,3,4,3);
		spawnlifespan(19);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(10,0,10,3,4,3);
		rndmask(2,0,2,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(10,10,false);
		color(255,255,255,192);
		fader(0,0,0,0);
		trans(0,0);
		fliccontrol(true,0,0.842,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


particle(fx_firejets)
{
		file(fx_xplobig3header);
		lifespan(21);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0.5,0.5,0.5);
		rndmask(0,0,0,2,2,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,128,true);
		scale(10,10,false);

//		color(0,0,255,218);
//		fader(-12,-7,12,-2);

		color(0,0,255,255);
		fader(-12,-7,12,0);

		trans(0,0);
		fliccontrol(true,0,0.95,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


particle(fx_smogjets)
{
		file(fx_expcloudheader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0.5,0.5,0.5);
		rndmask(0,0,0,2,2,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,128,true);
		scale(10,10,false);
		color(255,255,255,128);
		fader(0,0,0,4);
		trans(1,0);
		fliccontrol(false,0,1,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_Steam)
{
		file(Fx_puff2header);
		lifespan(18);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(15,15,false);
		color(192,255,192,64);
		fader(0,0,0,-7);
		trans(0,0);
		fliccontrol(true,0,0.888,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_Steampipes)
{
		file(Fx_puff2header);
		lifespan(28);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(0.5);
		spawnmax(24);
		spawnrecurs(false);
		spawninertia(true);
		spawnfromstart(true);
		spawnrnd(0,0,0,0,0,0);
		spawnlifespan(18);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,64,true);
		scale(28,28,false);
		color(192,255,192,128);
		fader(0,0,0,5);
		trans(0,0);
		fliccontrol(true,0,0.888,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


//---------------------------------------------------------------------------- misc fx

particle(fx_possess1)
{
		file(fx_stripheader);
		lifespan(256);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(256);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,0,0,0,0);
		rotatewithdir(false);
		spawnfromstart(false);
		spawnlifespan(256);
		spawnweight(0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.01,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,8,false);
		fliccontrol(false,0,0.5,0);
		color(128,128,128,255);
		fader(0,0,0,1);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_depossessflare)
{
		file(Fx_FlareHeader);
		lifespan(256);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(true,16,1,true);
		sinusy(true,16,1,true);
		sinusz(true,16,1,true);

		weight(0,-0.01,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(5,5,false);
		fliccontrol(true,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,1);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(fx_possess1,fx_possess1,_pFuncFollowSinus);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_chain)
{
		file(Fx_chainheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		polystrip(true,true);
		tridi(true,true);
		rnd(0,0,0,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,10,false);
		fliccontrol(false,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(2,0);
		scalar(0,2,2);
		killwithactor(true);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_possess2)
{
		file(fx_stripheader);
		lifespan(64);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(64);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,0,0,0,0);
		rotatewithdir(false);
		spawnfromstart(false);
		spawnlifespan(64);
		spawnweight(0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,8,false);
		fliccontrol(false,0,0.5,0);
		color(128,128,128,255);
		fader(0,0,0,4);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_possessflare)
{
		file(Fx_FlareHeader);
		lifespan(64);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(true,64,6,true);
		sinusy(true,64,6,true);
		sinusz(true,64,6,true);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(8,8,false);
		fliccontrol(true,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,4);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(fx_possess2,fx_possess2,_pFuncFollowSinus);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_scaledflare)
{
		file(fx_flareheader);
		lifespan(128);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,false);
		sinusy(false,0,0,false);
		sinusz(false,0,0,false);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(60,60,false);
		fliccontrol(true,0,1,0);
		color(0,0,255,128);
		fader(0,0,0,1);
		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}
particle(fx_msikaflare)
{
		file(Fx_FlareHeader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(2,2,false);
		fliccontrol(true,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,8);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_halo)
{
		file(fx_puff3header);
		lifespan(16);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(2,2,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,16);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_shockwave)
{
		file(fx_puff1header);
		lifespan(24);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(true,512,6,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(5,5,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,96);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_shockwaver)
{
		file(fx_puff1header);
		lifespan(30);
		collision(false,0);
		rebound(0,false);
		coldeath(false);

		spawn(true);
		spawnfreq(0.1);
		spawnmax(30);
		spawnrecurs(false);
		spawninertia(true);
		spawnrnd(0,0,0,0,0,0);
		spawnfromstart(true);
		spawnlifespan(24);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(15,15,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_flare)
{
		file(Fx_FlareHeader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(10,10,false);
		fliccontrol(true,0,1,0);
		color(255,128,128,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}


particle(fx_icesmoke)
{
		file(fx_puff1header);
		lifespan(56);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0.03,0);
		angle(0,0,0);
		rotate(0,0,64,true);
		scale(20,20,false);
		fliccontrol(true,0,0.2,0);
		color(128,128,192,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_fagsmoke)
{
		file(fx_puff1header);
		lifespan(60);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(5);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(1,16,1,0,1,0);
		spawnfromstart(true);
		spawnlifespan(60);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(1,16,1,0,1,0);
		rndmask(2,0,2,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,64,true);
		scale(5,5,false);
		fliccontrol(true,0,0.2,0);
		color(128,128,128,96);
		fader(0,0,0,0);
		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


particle(fx_fagblow)
{
		file(fx_puff1header);
		lifespan(60);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(5);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,4,0,1,6);
		spawnfromstart(true);
		spawnlifespan(60);
		spawnweight(0,0,0.1);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,4,0,1,6);
		rndmask(0,0,1,0,0,1);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.05,0.1);
		angle(0,0,0);
		rotate(0,0,64,true);
		scale(6,6,false);
		fliccontrol(true,0,0.2,0);
		color(96,96,96,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}



//---------------------------------------------------------------------------- muzzle flashes fx
particle(fx_pakflash)
{
		file(fx_puff1header);
		lifespan(12);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,true);
		tridi(false,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,true);
		sinusy(false,0,0,true);
		sinusz(false,0,0,true);

		weight(0,0.2,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(15,15,false);
		fliccontrol(true,0,1,0);
		color(156,156,192,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


particle(fx_torch)
{
		file(fx_torchheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(6,6,false);
		fliccontrol(false,0,0,1);
		color(255,255,255,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunflash)
{
		file(fx_gunflashheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,16,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunflashMachinegun)
{
		file(fx_gunflashheaderMachineGun);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,16,false);
		fliccontrol(false,0,1,0);
		color(128,192,128,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunflashPump)
{
		file(fx_gunflashheaderPump);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,16,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunflashMaimer)
{
		file(fx_gunflashheaderMaimer);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,16,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}


particle(fx_gunstrobe)
{
		file(fx_gunstrobeheader);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(15,15,false);
		fliccontrol(true,0,1,0);
		color(255,255,255,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunflashturret)
{
		file(fx_gunflashheaderac);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,10,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunbulletbeast)
{
		file(fx_gunflashheaderac);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,10,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(true);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunbulletturretac)
{
		file(fx_gunflashheaderac);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,10,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_gunflashturretac)
{
		file(fx_gunflashheaderac);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,-1024);
		rotate(0,0,0,false);
		scale(10,10,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_TurFlash)
{
		file(fx_gunflashheaderac);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,1024);
		rotate(0,2048,0,false);
		scale(10,10,false);
		fliccontrol(false,0,1,0);
		color(192,192,192,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunstrobeturret)
{
		file(fx_gunstrobeheaderac);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(12,12,false);
		fliccontrol(true,0,1,0);
		color(255,255,255,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunstrobePump)
{
		file(fx_gunstrobeheaderPump);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(15,15,false);
		fliccontrol(true,0,1,0);
		color(255,255,255,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunstrobeMachineGun)
{
		file(fx_gunstrobeheaderMachineGun);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(15,15,false);
		fliccontrol(true,0,1,0);
		color(220,255,220,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

particle(fx_gunstrobeMaimer)
{
		file(fx_gunstrobeheaderMaimer);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(1024,0,0);
		rotate(0,0,0,false);
		scale(13,13,false);
		fliccontrol(true,0,1,0);
		color(255,255,255,192);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}


particle(fx_coplaser)
{
		file(Fx_stripheader);
		lifespan(2);
		collision(true,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,10,false);
		fliccontrol(false,0,1,0);
		color(255,8,8,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);
}

//---------------------------------------------------------------------------- explosion & trails fx

particle(fx_explosionshards)
{
		file(fx_stripheader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1.2);
		spawnmax(7);
		spawnrecurs(true);
		spawninertia(false);
		spawnfromstart(true);
		spawnrnd(0,0,0,18,18,18);
		spawnlifespan(32);
		spawnweight(0.05,0.15,0.05);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(false,-256);
		rnd(0,0,0,18,18,18);
		rndmask(0,0,0,2,2,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.05,0.15,0.05);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,8,false);
		fliccontrol(false,0,0.25,0);
		color(255,255,255,255);
		fader(8,0,0,8);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_vshrapnel)
{
		file(fx_shrapnelheader);
		lifespan(32);
		collision(true,10);
		rebound(1.2,false);
		coldeath(false);
		spawn(true);
		spawnfreq(0.5);
		spawnmax(32);
		spawnrecurs(false);
		spawninertia(false);
		spawnfromstart(false);
		spawnrnd(0,0,0,0,0,0);
		spawnlifespan(32);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,-256);
		rnd(96,96,96,18,22,18);
		rndmask(0,0,0,2,2,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.05,0.1,0.05);
		angle(0,0,0);
		rotate(0,0,128,true);
		scale(10,10,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,8);
		trans(0,6);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_hshrapnel)
{
		file(fx_shrapnelheader);
		lifespan(32);
		collision(true,10);
		rebound(1.2,false);
		coldeath(false);
		spawn(true);
		spawnfreq(0.5);
		spawnmax(32);
		spawnrecurs(false);
		spawninertia(false);
		spawnfromstart(false);
		spawnrnd(0,0,0,0,0,0);
		spawnlifespan(32);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,-256);
		rnd(96,96,96,18,26,18);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.05,0.2,0.05);
		angle(0,0,0);
		rotate(0,0,128,true);
		scale(10,10,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,8);
		trans(0,6);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_bazookatrail)
{
		file(fx_btrailheader);
		lifespan(64);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,1,1,0);
		rndmask(0,0,0,2,2,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.005,0);
		angle(0,0,0);
		rotate(0,0,32,false);
		scale(28,28,false);
		fliccontrol(true,0,0.25,0);
		color(255,255,225,100);
		fader(0,0,0,1);
		trans(0,0);
		scalar(2,20,20);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_mainexplosion)
{
		file(fx_xplobigheader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(0.25);
		spawnmax(2);
		spawnrecurs(false);
		spawninertia(false);
		spawnfromstart(false);
		spawnrnd(128,128,128,0,0,0);
		spawnlifespan(32);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,-256);
		rnd(0,0,0,0,0,0);
		rndmask(2,2,2,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.001,0);
		angle(0,0,0);
		rotate(0,0,8,true);
		scale(30,30,false);
		fliccontrol(true,0,0.46875,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		//func(fx_hshrapnel,fx_vshrapnel,_pFuncNormal);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}


particle(fx_mainexplosion2)
{
		file(fx_xplobigheader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(0.25);
		spawnmax(2);
		spawnrecurs(false);
		spawninertia(false);
		spawnfromstart(false);
		spawnrnd(128,128,128,0,0,0);
		spawnlifespan(32);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);
		rndmask(2,2,2,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.001,0);
		angle(0,0,0);
		rotate(0,0,8,true);
		scale(30,30,false);
		fliccontrol(true,0,0.46875,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		//func(fx_hshrapnel,fx_vshrapnel,_pFuncNormal);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


particle(fx_explosionsmoke)
{
		file(fx_expcloudheader);
		lifespan(128);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(16);
		spawnrecurs(false);
		spawninertia(false);
		spawnfromstart(false);
		spawnrnd(96,96,96,0,0,0);
		spawnlifespan(128);
		spawnweight(0,-0.002,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,-256);
		rnd(0,0,0,0,0,0);
		rndmask(2,2,2,0,0,0);										   

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.002,0);
		angle(0,0,0);
		rotate(0,0,6,true);
		scale(30,30,false);
		fliccontrol(false,0,0.25,0);
		color(255,255,255,128);
		fader(0,0,0,1);
		trans(1,0);
		scalar(2,4,4);
		killwithactor(false);
		func(-1,-1,-1);
		//func(fx_hshrapnel,fx_vshrapnel,_pFuncNormal);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_smallexplosion)
{
		file(fx_xplosmallheader);
		lifespan(24);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,-32);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(30,30,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}


//---------------------------------------------------------------------------- 


particle(fx_TurretStrip)
{
		file(fx_stripheader);
		lifespan(64);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(16);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,0,0,0,0);
		rotatewithdir(false);
		spawnfromstart(false);
		spawnlifespan(32);
		spawnweight(0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

/*
		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);
*/

		sinusx(true,128,12,true);
		sinusy(true,128,12,true);
		sinusz(true,128,12,true);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,12,false);
		fliccontrol(false,0,0.5,0);
		color(128,128,128,255);
		fader(0,0,0,2);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(true);		//false
}

particle(fx_TurretStrip02)
{
		file(fx_stripheader);
		lifespan(64);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(16);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,0,0,0,0);
		rotatewithdir(false);
		spawnfromstart(false);
		spawnlifespan(32);
		spawnweight(0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

/*
		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);
*/

		sinusx(true,128,12,true);
		sinusy(true,128,12,true);
		sinusz(true,128,12,true);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,12,false);
		fliccontrol(false,0,0.5,0);
		color(10,100,255,255);
		fader(0,0,0,2);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);		//false
}

particle(fx_windspecks)
{
		file(fx_puff3header);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(false,true);
		rnd(48,0,48,0,0,0);
		rndmask(2,0,2,0,0,0);

		sinusx(true,64,2,true);
		sinusy(false,0,0,true);
		sinusz(true,64,2,true);

		weight(0,-0.2,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,1,false);
		fliccontrol(false,0,1,0);
		color(255,255,128,255);
		fader(0,0,0,4);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_windmatter)
{
		file(fx_puff3header);
		lifespan(48);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(48);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,0,0,0,0);
		spawnfromstart(false);
		spawnlifespan(48);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(true,0);
		rnd(64,0,64,0,0,0);
		rndmask(2,0,2,0,0,0);

		sinusx(true,64,4,true);
		sinusy(false,0,0,true);
		sinusz(true,64,4,true);

		weight(0,-0.1,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,3,false);
		fliccontrol(false,0,1,0);
		color(128,128,128,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_torchsparks)
{
		file(fx_stripheader);
		lifespan(64);
		collision(true,5);
		rebound(1.3,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(2);
		spawnrecurs(true);
		spawninertia(false);
		spawnrnd(0,0,0,4,3,4);
		spawnfromstart(true);
		spawnlifespan(64);
		spawnweight(0,0.05,0);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(false,0);
		rnd(0,0,0,4,3,4);
		rndmask(0,0,0,2,1,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.1,0.05,0.1);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,1,false);
		fliccontrol(false,0,0.5,0);
		color(255,128,128,255);
		fader(0,1,2,0);
		trans(2,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}


//---------------------------------------------------------------------------- 

particle(fx_sparks)
{
		file(fx_stripheader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(2);
		spawnrecurs(true);
		spawninertia(false);
		spawnrnd(0,0,0,3,3,3);
		spawnfromstart(true);
		spawnlifespan(32);
		spawnweight(0,0.05,0);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(false,0);
		rnd(0,0,0,3,3,3);
		rndmask(0,0,0,2,1,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.1,0.05,0.1);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,1,false);
		fliccontrol(false,0,0.5,0);
		color(255,128,128,255);
		fader(0,2,4,0);
		trans(2,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_impactsparks)
{
		file(fx_stripheader);
		lifespan(4);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(4);
		spawnrecurs(true);
		spawninertia(false);
		spawnrnd(0,0,0,12,12,12);
		spawnfromstart(true);
		spawnlifespan(4);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(true,false);
		tridi(true,0);
		rnd(0,0,0,12,12,12);
		rndmask(0,0,0,2,2,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,2,false);
		fliccontrol(false,0,0.5,0);
		color(251,147,77,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_impactpuff)
{
		file(fx_puff1header);
		lifespan(24);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);

		polystrip(false,false);
		tridi(false,0);
		rnd(0,4,0,0,4,0);
		rndmask(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(15,15,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,128);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_weaponsmoke)
{
		file(fx_puff1header);
		lifespan(48);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(true);
		spawnfreq(1);
		spawnmax(5);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,1,0,1,2,1);
		spawnfromstart(true);
		spawnlifespan(48);
		spawnweight(0,0,0);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(1,1,1,1,2,1);
		rndmask(2,0,2,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0.05,0,0.05);
		angle(0,0,0);
		rotate(0,0,64,true);
		scale(22,22,false);
		fliccontrol(true,0,0.25,0);
		color(255,255,255,128);
		fader(0,0,0,1);
		trans(0,0);
		scalar(2,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_trailoffire)
{
		file(fx_shrapnelheader);
		lifespan(32);
		collision(true,10);
		rebound(0,false);
		coldeath(true);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);
		rndmask(0,0,0,0,0,0);

//		sinusx(true,128,4,true);
//		sinusy(true,128,4,true);
//		sinusz(false,0,0,false);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,128,true);
		scale(10,10,false);
		fliccontrol(true,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,8);
		trans(0,6);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(false);
}

particle(fx_riotshieldshrapnel)
{
		file(fx_riotshldshrapnelheader);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,0);
		rnd(0,0,0,8,16,8);
		rndmask(0,0,0,2,0,2);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0.4,0);
		angle(512,512,512);
		rotate(64,64,64,false);
		scale(30,30,true);
		fliccontrol(false,0,0,0);
		color(255,255,255,255);
		fader(0,0,0,1);
		trans(0,0);
		scalar(1,0,0);
		killwithactor(false);

		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_plasmawall)
{
		file(fx_riotshld256header);
		lifespan(2);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(true,true);							//true here, marks an x axis wibble, instead of z
		rnd(0,0,0,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,1024,0);
		rotate(0,0,0,false);
		scale(2,1.333,false);
		fliccontrol(false,0,1,0);
		color(255,255,255,255);
		fader(0,0,0,0);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		//flipuv(true,false,true,false);			//still
		flipuv(false,false,true,true);				//wibble
		priority(0);
		follow(false);
}


particle(fx_maserstrip)
{
		file(fx_stripheader);
		lifespan(128);
		collision(true,5);
		rebound(0,false);
		coldeath(true);
		spawn(true);
		spawnfreq(1);
		spawnmax(128);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,0,0,0,0);
		rotatewithdir(false);
		spawnfromstart(false);
		spawnlifespan(128);
		spawnweight(0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(true,128,8,true);
		sinusy(true,128,8,true);
		sinusz(true,128,8,true);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,32,false);
		fliccontrol(false,0,0.5,0);
		color(16,255,64,255);
		fader(0,0,0,2);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}

particle(fx_Satanstrip)
{
		file(fx_stripheader);
		lifespan(64);
		collision(true,5);
		rebound(0,false);
		coldeath(true);
		spawn(true);
		spawnfreq(1);
		spawnmax(64);
		spawnrecurs(false);
		spawninertia(false);
		spawnrnd(0,0,0,0,0,0);
		rotatewithdir(false);
		spawnfromstart(false);
		spawnlifespan(64);
		spawnweight(0,0,0);

		polystrip(true,true);
		tridi(true,0);
		rnd(0,0,0,0,0,0);

		sinusx(true,512,32,true);
		sinusy(true,512,32,true);
		sinusz(true,512,32,true);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(1,128,false);
		fliccontrol(false,0,0.5,0);
		color(255,255,255,255);
		fader(0,0,0,4);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}


particle(fx_masersparks)
{
		file(fx_puff3header);
		lifespan(32);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);
		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(0,0,0,0,0,0);

		sinusx(true,64,1,true);
		sinusy(true,64,1,true);
		sinusz(true,64,3,true);

		//sinusx(false,0,0,0);
		//sinusy(false,0,0,0);
		//sinusz(false,0,0,0);

		weight(0,0,0);
		angle(0,0,0);
		rotate(0,0,0,false);
		scale(4,4,false);
		fliccontrol(true,0,0.25,0);
		color(16,255,64,255);
		fader(0,0,0,8);
		trans(0,0);
		scalar(0,2,2);
		killwithactor(false);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(1);
		follow(true);
}

particle(fx_subgirlthrusterjump)
{
		file(fx_puff1header);
		lifespan(12);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(4,0,4,0,0,0);
		rndmask(2,2,2,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.3,0);
		angle(0,0,0);
		rotate(0,0,64,true);
		scale(20,20,false);
		fliccontrol(true,0,1,0);
		color(255,220,220,128);
		fader(1,4,4,1);
		trans(0,0);
		scalar(2,15,15);
		killwithactor(true);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}


particle(fx_subgirlthruster)
{
		file(fx_puff1header);
		lifespan(6);
		collision(false,0);
		rebound(0,false);
		coldeath(false);
		spawn(false);

		rotatewithdir(false);
		polystrip(false,false);
		tridi(false,0);
		rnd(4,0,4,0,0,0);
		rndmask(2,2,2,0,0,0);

		sinusx(false,0,0,0);
		sinusy(false,0,0,0);
		sinusz(false,0,0,0);

		weight(0,-0.3,0);
		angle(0,0,0);
		rotate(0,0,64,true);
		scale(20,20,false);
		fliccontrol(true,0,2,0);
		color(255,255,255,128);
		fader(0,4,4,1);
		trans(0,0);
		scalar(2,15,15);
		killwithactor(true);
		func(-1,-1,-1);
		flipuv(false,false,false,false);
		priority(0);
		follow(false);
}
