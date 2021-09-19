unsigned long __stdcall thread( LPVOID a1 )
{
    WarcraftButton tempbutton ( "AccountName" ); // AccountName - from UI\FrameDef\Glue\BattleNetMain.fdf
    

    while ( !tempbutton.IsOk( ) ) // if false - not found!
    {
        Sleep( 100 );
    }


    while ( true )
    {
        if ( !tempbutton.IsChecked( ) ) 
        {
            
            while ( !tempbutton.IsChecked( ) )
            {
                Sleep( 10 );
            }


            int btntextsize = tempbutton.GetBtnStringSize( );
            if ( btntextsize > 1 )
            {
                char * accountc = new char[ btntextsize+1 ];
                accountc[ btntextsize ] = '\0';
                ReadProcessMemory( GetCurrentProcess( ) , ( void* ) tempbutton.GetBtnStringAddr( ) , accountc , btntextsize , 0 );
                MessageBox( NULL , accountc , tempbutton.Author() , MB_OK );
                delete[ ]accountc;
            }
            


        }




        Sleep( 20 );
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