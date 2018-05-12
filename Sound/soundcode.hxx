

//sample(name,position,volume,lifespan)
//position= absolute if not attached to an actor
//position= -1 if attached to an actor

//MISSING: Check which character. Play male/female/baby sound
//MISSING: The character sounds must also check if health is positive before playing sounds.
//MISSING: Perhaps it will be a good idea to have a routine to stop all charactersounds for a character before starting a death-scream.

subroutine(Sound_HitSmall)
{
		sample(SFXKickedReact,-1);
		/*
		if(VClass==_ClassAngel)
		{
			sample(SFXPainMale2,-1);
		}
		else
		{
			sample(SFXPainMale3,-1);
		}
		*/
}

subroutine(Sub_RandomPunchedSFX)
{
		//if(vframe==14 || vframe==11 || vframe==13)
		if(vframe==1)
		{
			if(VAICon!=0)
			{
				sample(SFXPunchedReact,-1);
			}
			else
			{
				sample(SFXShotReact,-1);
			}
			sample(SFXManPunch,-1);
		}

}

subroutine(Sub_EatMaleSlowSFX)
{
	if(VFrame==20)
	{
		sample(SFXChotCrushed,-1);
		Sample(SFXWorkerOhNo,-1);
	}
	elseif(VFrame==100)
	{
		Sample(SFXOhGodNo,-1);
	}
	elseif(vframe==210)
	{
		sample(SFXChotCrushed,-1);
		Sample(SFXWorkerScream,-1);
	}
	elseif(vframe==310)
	{
		Sample(SFXBehemothAngry,-1);
	}
}

subroutine(Sub_EatMaleSFX)
{
	if(VFrame==20)
	{
		Sample(SFXWorkerOhNo,-1);
	}
	elseif(vframe==100)
	{
		Sample(SFXWorkerScream,-1);
	}
	elseif(vframe==200)
	{
		Sample(SFXBehemothAngry,-1);
	}
}

subroutine(Sub_RandomStrangledSFX)
{
		if(vframe==41 || vframe==61)
		{
			sample(SFXManStrangled,-1);
		}
}



subroutine(Sub_RandomWaterSFX)
{
		sample(SFXFootStepWat,-1);
}



subroutine(Sub_BobRollSFX)
{
	if (vframe==1)
	{
		sample(SFXBobClimb,-1);
	}
}

subroutine(Sub_RandomKickRollSFX)
{
		if(vframe==17)
		{
			sample(SFXManPunch,-1);
		}
}


subroutine(Sub_RandomKickedSFX)
{
		if(vframe==1)
		{
			if(VAICon!=0)
			{
				sample(SFXShotReact,-1);
			}
			else
			{
				sample(SFXKickedReact,-1);
			}
			sample(SFXManPunch,-1);
		}
}


SubRoutine(Sub_CheckFootSteps,const(Foot))
{
		if(vtrigger==_DIRwalking)
		{
			if(VClass==_ClassAngel)
			{
				float(_set,tmpfloat,90);
			}
			else
			{
				float(_set,tmpfloat,75);
			}
		}
		else
		{
			if(VClass==_ClassAngel)
			{
				float(_set,tmpfloat,100);
			}
			else
			{
				float(_set,tmpfloat,95);
			}
		}

		call(CheckFootCollision,Foot);
		if(VSpecialFlag==_sFLAGFootCollide)
		{
			float(_set,LastFootstep,1);

			if(VAIClass==_AIclassabeast)
			{
				sample(SFXClutchCap,-1,tmpfloat);
			}
			elseif(VAIClass==_AIclassbeast)
			{
				sample(SFXFootBeast,-1,tmpfloat);
			}
			elseif(VAIClass==_AIclasssatan)
			{
				sample(SFXFootSatan,-1,tmpfloat);
			}
			elseif(VClass==_ClassAngel)
			{
				sample(SFXFootStepBob,-1,tmpfloat);
			}
			elseif(VColMaterialProperties==_MATstair)
			{
				sample(SFXFootStepBig,-1,tmpfloat);
			}
			elseif(VColMaterialProperties==_MATWood)
			{
				sample(SFXFootStepWd,-1,tmpfloat);
			}
			elseif(VColMaterialProperties==_MATMetal)
			{
				if(VAIClass==_AIClassFemale)
				{
					sample(SFXFootStepFemMet,-1,tmpfloat);
				}
				else
				{
					sample(SFXFootStepMet,-1,tmpfloat);
				}
			}
			elseif(VColMaterialProperties==_MATSheetMetal)
			{
				if(VAIClass==_AIClassFemale)
				{
					sample(SFXFootStepFemMet,-1,tmpfloat);
				}
				else
				{
					sample(SFXFootStepWlk,-1,tmpfloat);
				}
			}
			elseif(VColMaterialProperties==_MATConcrete)
			{
				if(VAIClass==_AIClassFemale)
				{
					sample(SFXFootStepFemCon,-1,tmpfloat);
				}
				else
				{
					sample(SFXFootStepCon,-1,tmpfloat);
				}
			}
			elseif(VColMaterialProperties==_MATWater)
			{
				sample(SFXFootStepWat,-1,tmpfloat);
			}
			else
			{
				if(VAIClass==_AIClassFemale)
				{
					sample(SFXFootStepFemReg,-1,tmpfloat);
				}
				else
				{
					sample(SFXFootStepReg,-1,tmpfloat);
				}
			}
		}
}

//TH added 9-99:
subroutine(Sub_SFXCop_BackgroundChatter)//plugged-in
{
	if(VAIcon==1)//only do this for AI controlled characters
	{
		if(SoundDelayCounter<=0)//don't overlap sounds
		{
			float(_set,SoundDelayCounter,90);//set 3 second delay count-down until next sound can be triggered.
			sample(SFXChat,-1);
		}
	}
}

subroutine(Sub_RandomCopScratchesCrotch)//plugged-in
{ //don't overlap sounds
	//if(SoundDelayCounter<=0 && vframe==28)
	//{
	//	float(_set,SoundDelayCounter,90);//set delay count-down until next sound can be triggered.
	if(vframe==28)
	{
		sample(SFXCop_Scratch1,-1);
	}
}





