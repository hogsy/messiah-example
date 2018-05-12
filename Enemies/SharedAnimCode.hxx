SubRoutine(Sub_GetUpClearThrown84)
{
		if(vframe==84)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown68)
{
		if(vframe==68)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown64)
{
		if(vframe==64)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown55)
{
		if(vframe==55)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown46)
{
		if(vframe==46)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown38)
{
		if(vframe==38)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown36)
{
		if(vframe==36)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}


SubRoutine(Sub_GetUpClearThrown35)
{
		if(vframe==35)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}


SubRoutine(Sub_GetUpClearThrown24)
{
		if(vframe==24)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown19)
{
		if(vframe==19)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}

SubRoutine(Sub_GetUpClearThrown15)
{
		if(vframe==15)
		{
			state(_clr,StateThrown);
			State(_clr,StateCrouching);
		}
}


SubRoutine(Sub_ClrThrownFlag)
{
		State(_clr,StateThrown);
}

SubRoutine(Sub_ClrCombatMode)
{
		Direction(_clr,_DIRcombatmode);
}

SubRoutine(Sub_ActionDebugBreak)
{
		break();
}

SubRoutine(Sub_HeavyLand)
{
		if(VFrame==5)
		{
			call(ScreenShake,0,24,0,0.5);
		}

		if(VFrame==6||vframe==10||vframe==14)
		{
			vector(_set,fxvector,0,-200,0);
			call(SetParticleSetID);
			callsub(sub_shockwave,BulletShockWave,0);
		}
}

SubRoutine(Sub_clawblood)
{
		if(vframe>=10&&vframe<20)
		{
			if(vframe==10)
			{
				if(VAIcon==0)
				{
					call(AIchangemetoenemy);
				}
				spawnparticle(fx_bloodspray,12,emptyvector,emptyvector,-1);
			}
			if(vrnd<30)
			{
				spawnparticle(fx_blood,2,emptyvector,emptyvector,-1);
			}
		}
}

SubRoutine(Sub_Kicking)
{
		//CallSub(Sub_RandomKickedSFX);
		if(VAICon==0)
		{
			CallSub(Sub_ChangeMeToEnemy);
		}
}

SubRoutine(Sub_Punching)
{
		//CallSub(Sub_RandomKickedSFX);
		if(VAICon==0)
		{
			CallSub(Sub_ChangeMeToEnemy);
		}
}