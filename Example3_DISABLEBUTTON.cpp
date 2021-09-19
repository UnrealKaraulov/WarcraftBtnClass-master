unsigned long __stdcall thread( LPVOID a1 )
{
	WarcraftButton BattleNetButton = WarcraftButton( "BattleNetButton" ); // from mainmenu.fdf
	
	while ( true )
	{
		while ( !BattleNetButton.IsOk( ) )
		{
			Sleep( 50 );
		}

		if ( BattleNetButton.IsBtnEnabled( ) )
		{
			BattleNetButton.ClearBtnFlag(WarcraftButton::STATE_BUTTON_ENABLED);
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