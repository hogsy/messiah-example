

Action(movefast)
{
		trigger(_allDIR);
		move(0,0,-5);
		//loopframes(10,20);										//loopstartframe,loopendframe
}

Action(moveslow)
{
		trigger(_allDIR);
		move(0,0,-1);
		//loopframes(10,20);										//loopstartframe,loopendframe
}

Action(nomove)
{
		trigger(_allDIR);
		//loopframes(10,20);										//loopstartframe,loopendframe
}


Actor(rat)
{
		file(RatHeader);

		rank(_RankSergeantL);

		startstate(statenormal);
		startaction(nomove);

		float(_declare,RandomRatSound,0);

		if(VState==StateDead)
		{
			if(VAICon==0)
			{
				message("YOU CALL YOURSELF THE MESSIAH?",400,10);
				call(AIchangerank,0);
			}
			else
			{
				killactor();
			}
		}
		else
		{
			if(VAICon==0)
			{
				CallSub(BackGroundTriggerChecks);
				call(AIupdateAIvars);
			}

			//random ratty noises
			if(RandomRatSound<=0)
			{
				float(_rnd2,RandomRatSound,100);
				float(_add,RandomRatSound,100);
				sample(SFXrat3,-1);
			}
			else
			{
				float(_sub,RandomRatSound,1);
			}

			if(vaicon!=0)
			{
				Direction(_clr,_DIRaiRemoveFlags);

				if(VAIhaspath==0)
				{
					call(PickNewNode);
				}

				call(AIPickdest,10);
				if(vtrigger==_DIRtempflag)
				{
					call(PickNewNode);
				}
				CallSub(Sub_AI1WayAlignToPickDestAngle);
				if(VTrigger==_DIRleft)
				{
					turn(0,-40,0);
				}
				elseif(VTrigger==_DIRright)
				{
					turn(0,40,0);
				}
				if(vpickdestanglecorr>512 || vpickdestanglecorr<-512)	//might need bigger numbers
				{
					move(0,0,-1);
				}
				else
				{
					move(0,0,-10);
				}
			}
			else
			{
				if(vtrigger==_DIRpossesion)
				{
					Camera(rat_camera_distance,rat_camera_angle);
					Target(rat_camera_Tdistance,rat_camera_Tangle);
					callsub(Sub_InitPossesion,NoMove,NoMove,NoMove);

					if(VSniperMode!=0)
					{
						call(ChangeSniperMode,-2,0);
					}

					FirstPerson(1);
				}
				elseif(VActorFlag!=_AFLAGNoDepossession && vtrigger==_DIRdepossesion)
				{
					call(RoomForDeposses,BobSphereSize);
					if(VTrigger!=_DIRTempFlag)
					{
						callsub(Sub_InitDepossesion,MoveSlow,MoveSlow,MoveSlow);
						FirstPerson(0);
					}
					else
					{
						//	There isn't enough room!
						//
						SamplePlaying(SFXInvalidFunction,-1);
						if(VTrigger!=_DIRTempFlag)
						{
							Sample(SFXInvalidFunction,-1);
						}
					}

/*
					float(_seti,TmpFloat,VColSphereSize);

					Collision(0,0,0,0,BobSphereSize,0);
					if(vcolflag!=_DIRhorcol && vcolflag!=_DIRvercol)
					{
						callsub(Sub_InitDepossesion,MoveSlow,MoveSlow,MoveSlow);
						FirstPerson(0);
					}
*/
				}

				if(VFirstPerson!=0)
				{
					if(vtrigger==_DIRforward)
					{
						move(0,0,-10);
					}
					elseif(vtrigger==_DIRbackward)
					{
						move(0,0,5);
					}
				}
				else
				{
					if(vtrigger==_DIRforward)
					{
						move(0,0,-5);
					}
					elseif(vtrigger==_DIRbackward)
					{
						move(0,0,2);
					}
					if(VTrigger==_DIRleft)
					{
						turn(0,-20,0);
					}
					elseif(VTrigger==_DIRright)
					{
						turn(0,20,0);
					}
				}

				if(Vtrigger==_DIRbackward||Vtrigger==_DIRforward)
				{
					SamplePlaying(SFXRatScurry,-1);
					if(VTrigger!=_DIRTempFlag)
					{
						sample(SFXRatScurry,-1);
					}
				}
				else
				{
					SamplePlaying(SFXRatScurry,-1);
					if(VTrigger==_DIRTempFlag)
					{
						samplestop(SFXRatScurry);
					}
				}
			}

			if(VHealth<=0)
			{
				if(VAICon==0)
				{
					float(_seti,TmpFloat,VColSphereSize);
					Collision(0,0,0,0,BobSphereSize,0);
					if(vcolflag!=_DIRhorcol && VDifficulty<_DifficultyHard)
					{
						call(RoomForDeposses,BobSphereSize);
						if(VTrigger!=_DIRTempFlag)
						{
							callsub(Sub_InitDepossesion,MoveSlow,MoveSlow,MoveSlow);
							FirstPerson(0);
						}
						else
						{
							//	There isn't enough room!
							//
							SamplePlaying(SFXInvalidFunction,-1);
							if(VTrigger!=_DIRTempFlag)
							{
								Sample(SFXInvalidFunction,-1);
							}
						}
					}
				}
				callsub(Sub_DiePlease);
			}

			if(VColMaterialProperties==_MATDrown)
			{
				state(_or,StateDead);
				direction(_clr,_DIRalive);
				if(VAICon==0)
				{
					callsub(Sub_InitDepossesion,MoveSlow,MoveSlow,MoveSlow);
					FirstPerson(0);
				}
				callsub(Sub_DiePlease);
			}

		}

		if(VAItimenottarget>30)		//so it doesn't stay as an enemy
		{
			call(AIreinstateactoraiclass);
		}


}
