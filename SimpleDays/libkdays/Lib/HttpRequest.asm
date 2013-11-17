ifdef	UNICODE
	_HttpRequest	equ	_HttpRequestW
else
	_HttpRequest	equ	_HttpRequestA
endif
		.const
wszPost		dw	'P','O','S','T',0
wszContentType	dw	'C','o','n','t','e','n','t','-','T','y','p','e',':',' '
		dw	'a','p','p','l','i','c','a','t','i','o','n','/'
		dw	'x','-','w','w','w','-','f','o','r','m','-','u','r','l','e','n','c','o','d','e','d',0dh,0ah,0
		.code
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;********************************************************************
; �ͷ��ڴ�
;********************************************************************
_HttpRequestFree proc	uses ebx edi esi _hMemory

		invoke	GlobalFree,_hMemory
		ret
_HttpRequestFree endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;********************************************************************
; ʹ��WinHttp����Post
;********************************************************************
_HttpRequestW	proc	uses ebx edi esi _lpszURL,_lpOptional
		local	@hHeap
		local	@stUrl:URL_COMPONENTS
		local	@lpszHostName,@lpszUrlPath,@lpszExtraInfo,@nURLSize,@lpszRequest
		local	@hSession,@hConnect,@hHTTP

		local	@lpBuf,@nSize
		local	@lpData,@nDataSize


		invoke	HeapCreate,0,0,0
		.if	eax && (eax < 0c0000000h)
			mov	@hHeap,eax
		.else
			xor	eax,eax
			ret
		.endif
		xor	eax,eax
		mov	@lpData,eax
;********************************************************************
; ���URL,Ϊ������׼��
;********************************************************************
		invoke	RtlZeroMemory,addr @stUrl,sizeof URL_COMPONENTS
;�ṹ��0��ʼ��

		invoke	lstrlenW,_lpszURL
		add	eax,2
		mov	ebx,2
		mul	ebx
		mov	@nURLSize,eax
		invoke	HeapAlloc,@hHeap,HEAP_ZERO_MEMORY,@nURLSize
		.if	eax && (eax < 0c0000000h)
			mov	@lpszHostName,eax
		.else
			Jmp	QuitNoHandle
		.endif
		invoke	HeapAlloc,@hHeap,HEAP_ZERO_MEMORY,@nURLSize
		.if	eax && (eax < 0c0000000h)
			mov	@lpszUrlPath,eax
		.else
			jmp	QuitNoHandle
		.endif
		invoke	HeapAlloc,@hHeap,HEAP_ZERO_MEMORY,@nURLSize
		.if	eax && (eax < 0c0000000h)
			mov	@lpszExtraInfo,eax
		.else
			jmp	QuitNoHandle
		.endif

		mov	@stUrl.dwStructSize,sizeof URL_COMPONENTS
;WinHttpCrackUrl�ὫURL���Ϊ3����,������Ϊÿ���ֵĴ�С�����趨
		
		push	@lpszHostName
		pop	@stUrl.lpszHostName
		push	@nURLSize
		pop	@stUrl.dwHostNameLength
		
		push	@lpszUrlPath
		pop	@stUrl.lpszUrlPath
		push	@nURLSize
		pop	@stUrl.dwUrlPathLength
		
		push	@lpszExtraInfo
		pop	@stUrl.lpszExtraInfo
		push	@nURLSize
		pop	@stUrl.dwExtraInfoLength
;���		
		invoke	WinHttpCrackUrl,_lpszURL,0,ICU_ESCAPE,addr @stUrl
		.if	!eax
			jmp	QuitNoHandle
		.endif
;�����2��������,ΪWinHttpOpenRequest��׼��
		invoke	lstrlenW,@stUrl.lpszUrlPath
		mov	ebx,eax
		invoke	lstrlenW,@stUrl.lpszExtraInfo
		add	ebx,eax
		inc	ebx
		mov	eax,2
		xchg	ebx,eax
		mul	ebx
		invoke	HeapAlloc,@hHeap,HEAP_ZERO_MEMORY,eax
		.if	eax && (eax < 0c0000000h)
			mov	@lpszRequest,eax
		.else
			jmp	QuitNoHandle
		.endif
		invoke	lstrcpyW,@lpszRequest,@stUrl.lpszUrlPath
		invoke	lstrcatW,@lpszRequest,@stUrl.lpszExtraInfo
;********************************************************************
; ��һ���Ự
;********************************************************************
		invoke	WinHttpOpen,0,WINHTTP_ACCESS_TYPE_NO_PROXY,WINHTTP_NO_PROXY_NAME,WINHTTP_NO_PROXY_BYPASS,NULL
		.if	!eax
			jmp	QuitNoHandle
		.endif
		mov	@hSession,eax
;********************************************************************
; ����DNS��������/����/����/���� ��ʱ
;********************************************************************		
		invoke	WinHttpSetTimeouts,@hSession,4000,4000,4000,4000
		.if	!eax
			jmp	QuitHandle1
		.endif
;********************************************************************
; ���ӷ�����
;********************************************************************
		invoke	WinHttpConnect,@hSession,@stUrl.lpszHostName,INTERNET_DEFAULT_PORT,0
		.if	!eax
			jmp	QuitHandle1
		.endif
		mov	@hConnect,eax
;********************************************************************
; ��������(URLת��)
;********************************************************************	
		;.if	_lpOptional
			invoke	WinHttpOpenRequest,@hConnect,addr wszPost,@lpszRequest,NULL,WINHTTP_NO_REFERER,WINHTTP_DEFAULT_ACCEPT_TYPES,WINHTTP_FLAG_ESCAPE_PERCENT OR WINHTTP_FLAG_REFRESH
		;.else
			;invoke	WinHttpOpenRequest,@hConnect,addr wszGet,@lpszRequest,NULL,WINHTTP_NO_REFERER,WINHTTP_DEFAULT_ACCEPT_TYPES,WINHTTP_FLAG_ESCAPE_PERCENT OR WINHTTP_FLAG_REFRESH
		;.endif
		.if	!eax
			jmp	QuitHandle2
		.endif
		mov	@hHTTP,eax
;********************************************************************
; ����POST�����ͷ
;********************************************************************
		.if	_lpOptional
			invoke	WinHttpAddRequestHeaders,@hHTTP,addr wszContentType,-1,WINHTTP_ADDREQ_FLAG_ADD OR WINHTTP_ADDREQ_FLAG_REPLACE
			.if	!eax
				jmp	QuitHandle3
			.endif
		.endif
;********************************************************************
; ���ͱ���
;********************************************************************
		.if	_lpOptional
			invoke	lstrlenA,_lpOptional
		.else
			xor	eax,eax
		.endif
		invoke	WinHttpSendRequest,@hHTTP,WINHTTP_NO_ADDITIONAL_HEADERS,NULL,_lpOptional,eax,eax,0
		.if	!eax
			jmp	QuitHandle3
		.endif
;********************************************************************
; ����
;********************************************************************
		invoke	WinHttpReceiveResponse,@hHTTP,0
		.if	!eax
			jmp	QuitHandle3
		.endif

		invoke	HeapAlloc,@hHeap,HEAP_ZERO_MEMORY,1
		.if	eax
			mov	@lpBuf,eax
			mov	@nDataSize,0
		.else
			jmp	QuitHandle3
		.endif
		.while	TRUE
;********************************************************************
; �鿴�ظ������ݴ�С,���仺����
;********************************************************************
			invoke	WinHttpQueryDataAvailable,@hHTTP,addr @nSize
			.if	!eax
				jmp	QuitHandle3
			.endif
			.if	!@nSize
				.break
			.else
				mov	eax,@nDataSize	;@nDataSize=ԭ�е��ֽ���
				add	eax,@nSize	;eax=�ܳ���
				invoke	HeapReAlloc,@hHeap,HEAP_ZERO_MEMORY,@lpBuf,eax
				.if	eax
					mov	@lpBuf,eax
				.else
					jmp	QuitHandle3
				.endif
			.endif
;********************************************************************
; ��ȡ����
;********************************************************************
			mov	eax,@lpBuf
			add	eax,@nDataSize
			mov	ecx,eax
			invoke	WinHttpReadData,@hHTTP,ecx,@nSize,addr @nSize
			.if	!eax
				jmp	QuitHandle3
			.endif
			mov	eax,@nDataSize
			add	eax,@nSize
			mov	@nDataSize,eax
		.endw
;********************************************************************
; �����ڴ�
;********************************************************************
		inc	@nDataSize
		invoke	GlobalAlloc,GPTR,@nDataSize
		.if	eax
			mov	@lpData,eax
		.else
			jmp	QuitHandle3
		.endif
		mov	ecx,@nDataSize
		dec	ecx
		mov	esi,@lpBuf
		mov	edi,@lpData
		cld
		rep	movsb
;********************************************************************
; ��β����
;********************************************************************
QuitHandle3:	invoke	WinHttpCloseHandle,@hHTTP
QuitHandle2:	invoke	WinHttpCloseHandle,@hConnect
QuitHandle1:	invoke	WinHttpCloseHandle,@hSession
QuitNoHandle:	invoke	HeapDestroy,@hHeap
		mov	eax,@lpData
		ret

_HttpRequestW	endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
;********************************************************************
; ʹ��WinHttp����Post(ANSI)
;********************************************************************
_HttpRequestA	proc	uses ebx edi esi _lpszURL,_lpOptional
		local	@lpszURL,@cchWideChar

		invoke	lstrlenA,_lpszURL
		shl	eax,2
		mov	@cchWideChar,eax
		invoke	GlobalAlloc,GPTR,eax
		mov	@lpszURL,eax

		invoke	MultiByteToWideChar,CP_ACP,NULL,_lpszURL,-1,@lpszURL,@cchWideChar	;����ȷ�Ľ���UTF8����ô?
		invoke	_HttpRequestW,@lpszURL,_lpOptional
		
		push	eax
		invoke	GlobalFree,@lpszURL
		pop	eax
		ret
_HttpRequestA	endp