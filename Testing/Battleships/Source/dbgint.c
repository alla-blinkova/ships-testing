/*******************************
 *      dbgint.cpp
 *
 *  Abstract:
 *      Debug interface
 *
 *  Authors:
 *      Inochkin Fedor, 2009
 *      fedor.inochkin@gmail.com
 *      Vasiliev Vladimir, 2010
 *      vasiliev.vb@yandex.ru
 *
 *******************************/

#include <windows.h>
#include <scttypes.h>
#include <ctypes.h>

//
// Functions
//
void DbgPrint(SDL_Charstring msg) //(SDL_Integer str)
/*++

Abstract:
    Output debug message

Parameters:
    msg [in] - message string

Returns:
    none
--*/
{
	int messageSize;
	char *message;

	OutputDebugStringA("DbgPrint: ");
    
	message = z_ctypes_32_cstring2cstar(msg);
	if(message == NULL)
	{	
		OutputDebugStringA("Error allocating 'message'");
		return;
	}
	else
	{
		OutputDebugStringA(message);

		messageSize = strlen(message);
		XFREE(&message, messageSize);
	}
	
	OutputDebugStringA("\n");
}

