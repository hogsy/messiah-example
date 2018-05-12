/*
		PRIORITY ADDED: use as follows ...

		set to 0 to always add the light
		set to 1 to add the light if the framerate allows
*/



//SpawnLight(Name,Bone,Pos,Color,Vec,Radius);
//				ID Int Vec Vec   Vec float

Light(Lvolumelight)
{
		type(_SXLomni|_SXLadditive|_SXLvolume);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(10,10,10,10,10,10,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(10,10,10,10,20,30,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(0);
		priority(1);
}

Light(Lomnilight)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(0);
		priority(1);
}


Light(Lomnilight2)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		priority(1);
		LightAcrossSets(on);
}

Light(Lomnilight3)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(0);
		priority(0);
}

Light(toruslight2)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(32);
		priority(0);
		LightAcrossSets(on);
}

Light(toruslight)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		priority(0);
		LightAcrossSets(on);
}

Light(LomnilightHelicopter)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(6);
		priority(1);
		LightAcrossSets(off);
}


Light(darklight)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		priority(0);
		LightAcrossSets(on);
}

Light(LomnilightAllSets)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		LightAcrossSets(on);
		priority(0);
}

Light(LightPulseOmni)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,300,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.9);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(32);
		priority(1);
}

Light(LightBlinkFade)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(60);
		priority(1);
		LightAcrossSets(on);
}

//used in War_rad (radiation sequence)
Light(LightPulseOmni2)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,600,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.2);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(150);
		priority(1);
}

// used in Club Perimeter (trap room)
Light(LightPulseOmni3)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,1000,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.3);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(3000);
		priority(0);
}

//used in OUtskirts (Broken elevator)
Light(LightPulseOmni4)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,50,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.2);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(150);
		priority(1);
}

//used in Wasteplant (wast12, under the floor)
Light(LightPulseOmni5)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,50,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.2);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(150);
		priority(1);
}


Light(fire_light)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(3);
		priority(1);
		LightAcrossSets(on);
}

Light(fire_light2)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(4);
		priority(1);
		LightAcrossSets(on);
}

Light(fire_light3)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(3);
		priority(0);
		LightAcrossSets(on);
}

Light(fire_light4)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(3);
		priority(0);
		LightAcrossSets(off);
}


Light(Lplanelight)
{
		type(_SXLplane|_SXLadditive);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Frequency(0.1);
		Rotate(0,60,0);				//Rotation x,y,z
		Collision(off);
		PlaneDistance(300);
		LightAcrossSets(on);
		LifeSpan(2000);
		priority(0);
}

Light(Lplanelight2)
{
		type(_SXLplane|_SXLadditive);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Frequency(0.7);
		Rotate(0,20,0);				//Rotation x,y,z
		Collision(off);
		PlaneDistance(300);
		LightAcrossSets(on);
		LifeSpan(455);
		priority(0);
}

Light(Lplanelight3)
{
		type(_SXLplane|_SXLadditive);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Frequency(0.1);
		Rotate(0,-32,0);				//Rotation x,y,z
		Collision(off);
		PlaneDistance(300);
		LightAcrossSets(on);
		LifeSpan(65);
		priority(0);
}

Light(Rplanelight)
{
		type(_SXLplane|_SXLadditive);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Frequency(0.1);
		Rotate(0,60,0);				//Rotation x,y,z
		Collision(off);
		PlaneDistance(35);
		LifeSpan(500);
		priority(0);
}
//name / bone / pos / color / empty / radius
//SpawnLight(flash_light,0,Gactorpos,tmpvector,EmptyVector,400);
Light(flash_light)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		priority(1);
}

Light(flash_light_across_set)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		priority(1);
		LightAcrossSets(on);
}


Light(HeavyCopSearchLight)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		priority(0);
		LightAcrossSets(on);
}

Light(Electric_light)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,100,50);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(2);
		priority(1);
}

Light(perm_light)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(600);
		priority(0);
		LightAcrossSets(on);
}

Light(Omni_Flash)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,200,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(10);
		priority(1);
}

Light(dark_light600)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(600);
		priority(0);
}

Light(ShortOmni)
{
		type(_SXLomni);
		Scale(1);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(300);
		priority(0);
}

Light(PossessLight)
{
		type(_SXLomni);
		Scale(0);					//scale over time 0=small at end, 1=no change over time
		Rnd(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		Fade(0,0,0,0,0,0,0,0);		//x,y,z,r,g,b,radius,planedist
		frequency(0.1);
		Rotate(0,1,0);				//Rotation x,y,z
		Collision(off);
		LifeSpan(128);
		priority(0);
}

