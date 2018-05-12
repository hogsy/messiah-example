//Test Level


SubRoutine(InitSceneSound20)
{
}

SubRoutine(InitScene20)
{
			InitActor(Bob1,0,Gactorangle,"elevent");
			float(_set,Timer,0);

			callsub(InitSceneSound20);
}

SubRoutine(MainScene20)
{
	if(VCheatKeys==1)
	{
		if(VKey==KEY_M && VOKey!=KEY_M)
		{
			if(PowerOn==1)
			{
//				float(_set,PowerOn,0);
			}
			else
			{
				float(_set,PowerOn,1);
			}
		}
	}
}

SubRoutine(BackgroundTriggerChecksScene20)
{

}
