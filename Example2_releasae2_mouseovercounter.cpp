unsigned long __stdcall thread( LPVOID a1 )
{
	WarcraftButton BattleNetButton = WarcraftButton( "BattleNetButton" ); // from mainmenu.fdf
	WarcraftButton BattleNetButtonText = WarcraftButton( "BattleNetButtonText" );
	int counter = 0;
	while ( true )
	{
		while ( !BattleNetButtonText.IsOk( ) )
		{
			Sleep( 50 );
		}
		while ( !BattleNetButton.IsOk( ) )
		{
			Sleep( 50 );
		}


		if ( BattleNetButton.IsBtnMouseOver( ) )
		{
			while ( BattleNetButton.IsBtnMouseOver( ) )
			{
				Sleep( 100 );
			}
			counter++;
			char * ccount = new char[ 50 ];
			sprintf_s( ccount , 50 , "|c0000FF00BATTLE.NET-%d" , counter );
			BattleNetButtonText.WriteText( ccount );
			delete [] ccount;
		}
		Sleep( 100 );
	}


	return 0;
}


HANDLE hThread;


BOOL WINAPI DllMain( HINSTANCE hDLL , UINT reason , LPVOID reserved )
{


	if ( reason == DLL_PROCESS_ATTACH )
	{
		hThread = CreateThread( 0 , 0 , thread , 0 , 0 , 0 );


	}
	else if ( reason == DLL_PROCESS_DETACH )
	{
		TerminateThread( hThread , 0 );
	}
	return TRUE;


}