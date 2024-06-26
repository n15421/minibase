#include <Windows.h>
#include <stdio.h>

#pragma comment(linker, "/export:WinHttpAddRequestHeaders=C:/Windows/System32/winhttp.WinHttpAddRequestHeaders")
#pragma comment(linker, "/export:WinHttpAutoProxySvcMain=C:/Windows/System32/winhttp.WinHttpAutoProxySvcMain")
#pragma comment(linker, "/export:WinHttpCheckPlatform=C:/Windows/System32/winhttp.WinHttpCheckPlatform")
#pragma comment(linker, "/export:WinHttpCloseHandle=C:/Windows/System32/winhttp.WinHttpCloseHandle")
#pragma comment(linker, "/export:WinHttpConnect=C:/Windows/System32/winhttp.WinHttpConnect")
#pragma comment(linker, "/export:WinHttpCrackUrl=C:/Windows/System32/winhttp.WinHttpCrackUrl")
#pragma comment(linker, "/export:WinHttpCreateProxyResolver=C:/Windows/System32/winhttp.WinHttpCreateProxyResolver")
#pragma comment(linker, "/export:WinHttpCreateUrl=C:/Windows/System32/winhttp.WinHttpCreateUrl")
#pragma comment(linker, "/export:WinHttpDetectAutoProxyConfigUrl=C:/Windows/System32/winhttp.WinHttpDetectAutoProxyConfigUrl")
#pragma comment(linker, "/export:WinHttpFreeProxyResult=C:/Windows/System32/winhttp.WinHttpFreeProxyResult")
#pragma comment(linker, "/export:WinHttpGetDefaultProxyConfiguration=C:/Windows/System32/winhttp.WinHttpGetDefaultProxyConfiguration")
#pragma comment(linker, "/export:WinHttpGetIEProxyConfigForCurrentUser=C:/Windows/System32/winhttp.WinHttpGetIEProxyConfigForCurrentUser")
#pragma comment(linker, "/export:WinHttpGetProxyForUrl=C:/Windows/System32/winhttp.WinHttpGetProxyForUrl")
#pragma comment(linker, "/export:WinHttpGetProxyForUrlEx=C:/Windows/System32/winhttp.WinHttpGetProxyForUrlEx")
#pragma comment(linker, "/export:WinHttpGetProxyResult=C:/Windows/System32/winhttp.WinHttpGetProxyResult")
#pragma comment(linker, "/export:WinHttpOpen=C:/Windows/System32/winhttp.WinHttpOpen")
#pragma comment(linker, "/export:WinHttpOpenRequest=C:/Windows/System32/winhttp.WinHttpOpenRequest")
#pragma comment(linker, "/export:WinHttpPalAcquireNextInterface=C:/Windows/System32/winhttp.WinHttpPalAcquireNextInterface")
#pragma comment(linker, "/export:WinHttpPalAcquireNextInterfaceAsync=C:/Windows/System32/winhttp.WinHttpPalAcquireNextInterfaceAsync")
#pragma comment(linker, "/export:WinHttpPalCancelRequest=C:/Windows/System32/winhttp.WinHttpPalCancelRequest")
#pragma comment(linker, "/export:WinHttpPalCreateCmSessionReference=C:/Windows/System32/winhttp.WinHttpPalCreateCmSessionReference")
#pragma comment(linker, "/export:WinHttpPalCreateRequestCtx=C:/Windows/System32/winhttp.WinHttpPalCreateRequestCtx")
#pragma comment(linker, "/export:WinHttpPalDllInit=C:/Windows/System32/winhttp.WinHttpPalDllInit")
#pragma comment(linker, "/export:WinHttpPalDllUnload=C:/Windows/System32/winhttp.WinHttpPalDllUnload")
#pragma comment(linker, "/export:WinHttpPalFreeProxyInfo=C:/Windows/System32/winhttp.WinHttpPalFreeProxyInfo")
#pragma comment(linker, "/export:WinHttpPalFreeRequestCtx=C:/Windows/System32/winhttp.WinHttpPalFreeRequestCtx")
#pragma comment(linker, "/export:WinHttpPalGetProxyCreds=C:/Windows/System32/winhttp.WinHttpPalGetProxyCreds")
#pragma comment(linker, "/export:WinHttpPalGetProxyForCurrentInterface=C:/Windows/System32/winhttp.WinHttpPalGetProxyForCurrentInterface")
#pragma comment(linker, "/export:WinHttpPalIsImplemented=C:/Windows/System32/winhttp.WinHttpPalIsImplemented")
#pragma comment(linker, "/export:WinHttpPalOnSendRequestComplete=C:/Windows/System32/winhttp.WinHttpPalOnSendRequestComplete")
#pragma comment(linker, "/export:WinHttpProbeConnectivity=C:/Windows/System32/winhttp.WinHttpProbeConnectivity")
#pragma comment(linker, "/export:WinHttpQueryAuthSchemes=C:/Windows/System32/winhttp.WinHttpQueryAuthSchemes")
#pragma comment(linker, "/export:WinHttpQueryDataAvailable=C:/Windows/System32/winhttp.WinHttpQueryDataAvailable")
#pragma comment(linker, "/export:WinHttpQueryHeaders=C:/Windows/System32/winhttp.WinHttpQueryHeaders")
#pragma comment(linker, "/export:WinHttpQueryOption=C:/Windows/System32/winhttp.WinHttpQueryOption")
#pragma comment(linker, "/export:WinHttpReadData=C:/Windows/System32/winhttp.WinHttpReadData")
#pragma comment(linker, "/export:WinHttpReceiveResponse=C:/Windows/System32/winhttp.WinHttpReceiveResponse")
#pragma comment(linker, "/export:WinHttpResetAutoProxy=C:/Windows/System32/winhttp.WinHttpResetAutoProxy")
#pragma comment(linker, "/export:WinHttpSaveProxyCredentials=C:/Windows/System32/winhttp.WinHttpSaveProxyCredentials")
#pragma comment(linker, "/export:WinHttpSendRequest=C:/Windows/System32/winhttp.WinHttpSendRequest")
#pragma comment(linker, "/export:WinHttpSetCredentials=C:/Windows/System32/winhttp.WinHttpSetCredentials")
#pragma comment(linker, "/export:WinHttpSetDefaultProxyConfiguration=C:/Windows/System32/winhttp.WinHttpSetDefaultProxyConfiguration")
#pragma comment(linker, "/export:WinHttpSetOption=C:/Windows/System32/winhttp.WinHttpSetOption")
#pragma comment(linker, "/export:WinHttpSetStatusCallback=C:/Windows/System32/winhttp.WinHttpSetStatusCallback")
#pragma comment(linker, "/export:WinHttpSetTimeouts=C:/Windows/System32/winhttp.WinHttpSetTimeouts")
#pragma comment(linker, "/export:WinHttpTimeFromSystemTime=C:/Windows/System32/winhttp.WinHttpTimeFromSystemTime")
#pragma comment(linker, "/export:WinHttpTimeToSystemTime=C:/Windows/System32/winhttp.WinHttpTimeToSystemTime")
#pragma comment(linker, "/export:WinHttpWebSocketClose=C:/Windows/System32/winhttp.WinHttpWebSocketClose")
#pragma comment(linker, "/export:WinHttpWebSocketCompleteUpgrade=C:/Windows/System32/winhttp.WinHttpWebSocketCompleteUpgrade")
#pragma comment(linker, "/export:WinHttpWebSocketQueryCloseStatus=C:/Windows/System32/winhttp.WinHttpWebSocketQueryCloseStatus")
#pragma comment(linker, "/export:WinHttpWebSocketReceive=C:/Windows/System32/winhttp.WinHttpWebSocketReceive")
#pragma comment(linker, "/export:WinHttpWebSocketSend=C:/Windows/System32/winhttp.WinHttpWebSocketSend")
#pragma comment(linker, "/export:WinHttpWebSocketShutdown=C:/Windows/System32/winhttp.WinHttpWebSocketShutdown")
#pragma comment(linker, "/export:WinHttpWriteData=C:/Windows/System32/winhttp.WinHttpWriteData")
