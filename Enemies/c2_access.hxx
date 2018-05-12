
		vector(_set,tmpvector,0,50,0);		//weapon displacement

		vector(_set,Gactorpos,-8675,20232,13077);
		vector(_set,Gactorangle,0,1024,0);
		InitActor(worker,Gactorpos,Gactorangle,"acs10",TRUE);
		vector(_add,gactorpos,tmpvector);
		InitActor(weapontorch,Gactorpos,Gactorangle,"acs10");
