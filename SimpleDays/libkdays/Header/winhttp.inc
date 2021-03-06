;--- include file created by h2incx v0.99.20 (copyright 2005-2009 japheth)
;--- source file: E:\Project\[Stuff]\Assemble\Lib\XMLHttp\h2incX\winhttp.h, last modified: 12/16/2009 20:8
;--- cmdline used for creation:  winhttp.h

ifndef	defined
	defined	macro x
		ifdef x
			exitm <1>
		else
			exitm <0>
		endif
	endm
endif

if	0 eq defined(_WINHTTPX_)
_WINHTTPX_	EQU	<>
endif
  
if	0 eq defined(_WINHTTP_INTERNAL_)
	WINHTTPAPI	EQU	<DECLSPEC_IMPORT>
else 
	WINHTTPAPI	EQU	<>
endif 

BOOLAPI		EQU	<WINHTTPAPI BOOL WINAPI>
HINTERNET	typedef	LPVOID
LPHINTERNET	typedef ptr HINTERNET
INTERNET_PORT	typedef WORD
LPINTERNET_PORT typedef ptr INTERNET_PORT
INTERNET_DEFAULT_PORT		EQU	0
INTERNET_DEFAULT_HTTP_PORT	EQU	80
INTERNET_DEFAULT_HTTPS_PORT	EQU	443
WINHTTP_FLAG_ASYNC	EQU	10000000h
WINHTTP_FLAG_SECURE	EQU	00800000h
WINHTTP_FLAG_ESCAPE_PERCENT	EQU	00000004h
WINHTTP_FLAG_NULL_CODEPAGE	EQU	00000008h
WINHTTP_FLAG_BYPASS_PROXY_CACHE	EQU	00000100h
WINHTTP_FLAG_REFRESH		EQU	<WINHTTP_FLAG_BYPASS_PROXY_CACHE>
WINHTTP_FLAG_ESCAPE_DISABLE	EQU	00000040h
WINHTTP_FLAG_ESCAPE_DISABLE_QUERY	EQU	00000080h
SECURITY_FLAG_IGNORE_UNKNOWN_CA	EQU	00000100h
SECURITY_FLAG_IGNORE_CERT_DATE_INVALID	EQU	00002000h
SECURITY_FLAG_IGNORE_CERT_CN_INVALID	EQU	00001000h
SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE	EQU	00000200h

WINHTTP_ASYNC_RESULT	struct 
	dwResult	DWORD	?
	dwError		DWORD	?
WINHTTP_ASYNC_RESULT	ends

LPWINHTTP_ASYNC_RESULT typedef ptr WINHTTP_ASYNC_RESULT

;HTTP_VERSION_INFO	struct 
;	dwMajorVersion	DWORD	?
;	dwMinorVersion	DWORD	?
;HTTP_VERSION_INFO	ends

LPHTTP_VERSION_INFO typedef ptr HTTP_VERSION_INFO

INTERNET_SCHEME		typedef DWORD
LPINTERNET_SCHEME	typedef ptr DWORD
;INTERNET_SCHEME_HTTP	EQU	1
;INTERNET_SCHEME_HTTPS	EQU	2

;URL_COMPONENTS	struct 
;	dwStructSize	DWORD	?
;	lpszScheme	LPWSTR	?
;	dwSchemeLength	DWORD	?
;	nScheme		INTERNET_SCHEME	?
;	lpszHostName	LPWSTR	?
;	dwHostNameLength DWORD	?
;	nPort		INTERNET_PORT	?
;	lpszUserName	LPWSTR	?
;	dwUserNameLength DWORD	?
;	lpszPassword	LPWSTR	?
;	dwPasswordLength DWORD	?
;	lpszUrlPath	LPWSTR	?
;	dwUrlPathLength	DWORD	?
;	lpszExtraInfo	LPWSTR	?
;	dwExtraInfoLength DWORD	?
;URL_COMPONENTS	ends

LPURL_COMPONENTS typedef ptr URL_COMPONENTS

;URL_COMPONENTSW		typedef URL_COMPONENTS
LPURL_COMPONENTSW	typedef LPURL_COMPONENTS

WINHTTP_PROXY_INFO	struct 
	dwAccessType	DWORD	?
	lpszProxy	LPWSTR	?
	lpszProxyBypass	LPWSTR	?
WINHTTP_PROXY_INFO	ends

LPWINHTTP_PROXY_INFO typedef ptr WINHTTP_PROXY_INFO

WINHTTP_PROXY_INFOW	typedef WINHTTP_PROXY_INFO
LPWINHTTP_PROXY_INFOW	typedef LPWINHTTP_PROXY_INFO

WINHTTP_AUTOPROXY_OPTIONS	struct 
	dwFlags			DWORD	?
	dwAutoDetectFlags	DWORD	?
	lpszAutoConfigUrl	LPWSTR	?
	lpvReserved		LPVOID	?
	dwReserved		DWORD	?
	fAutoLogonIfChallenged	BOOL	?
WINHTTP_AUTOPROXY_OPTIONS	ends

WINHTTP_AUTOPROXY_AUTO_DETECT	EQU	00000001h
WINHTTP_AUTOPROXY_CONFIG_URL	EQU	00000002h
WINHTTP_AUTOPROXY_HOST_KEEPCASE	EQU	00000004h
WINHTTP_AUTOPROXY_HOST_LOWERCASE EQU	00000008h
WINHTTP_AUTOPROXY_RUN_INPROCESS	EQU	00010000h
WINHTTP_AUTOPROXY_RUN_OUTPROCESS_ONLY	EQU	00020000h
WINHTTP_AUTO_DETECT_TYPE_DHCP	EQU	00000001h
WINHTTP_AUTO_DETECT_TYPE_DNS_A	EQU	00000002h

WINHTTP_CERTIFICATE_INFO	struct 
	ftExpiry		FILETIME	<>
	ftStart			FILETIME	<>
	lpszSubjectInfo		LPWSTR	?
	lpszIssuerInfo		LPWSTR	?
	lpszProtocolName	LPWSTR	?
	lpszSignatureAlgName	LPWSTR	?
	lpszEncryptionAlgName	LPWSTR	?
	dwKeySize		DWORD	?
WINHTTP_CERTIFICATE_INFO	ends

ifdef _WS2DEF_
	WINHTTP_CONNECTION_INFO	struct 
		cbSize		DWORD	?
		LocalAddress	SOCKADDR_STORAGE	?
		RemoteAddress	SOCKADDR_STORAGE	?
	WINHTTP_CONNECTION_INFO	ends
endif 
WINHTTP_TIME_FORMAT_BUFSIZE	EQU	62
WinHttpTimeFromSystemTime proto stdcall :DWORD, :DWORD
WinHttpTimeToSystemTime proto stdcall :DWORD, :DWORD
ICU_NO_ENCODE	EQU	20000000h
ICU_DECODE	EQU	10000000h
ICU_NO_META	EQU	08000000h
ICU_ENCODE_SPACES_ONLY	EQU	04000000h
ICU_BROWSER_MODE	EQU	02000000h
ICU_ENCODE_PERCENT	EQU	00001000h
WinHttpCrackUrl proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
WinHttpCreateUrl proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
ICU_ESCAPE	EQU	80000000h
ICU_ESCAPE_AUTHORITY	EQU	00002000h
ICU_REJECT_USERPWD	EQU	00004000h
WinHttpCheckPlatform proto  
WinHttpGetDefaultProxyConfiguration proto stdcall :ptr WINHTTP_PROXY_INFO
WinHttpSetDefaultProxyConfiguration proto stdcall :ptr WINHTTP_PROXY_INFO
WinHttpOpen proto stdcall :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
WINHTTP_ACCESS_TYPE_DEFAULT_PROXY	EQU	0
WINHTTP_ACCESS_TYPE_NO_PROXY	EQU	1
WINHTTP_ACCESS_TYPE_NAMED_PROXY	EQU	3
WINHTTP_NO_PROXY_NAME	EQU	<NULL>
WINHTTP_NO_PROXY_BYPASS	EQU	<NULL>
WinHttpCloseHandle proto stdcall :DWORD
WinHttpConnect proto stdcall :DWORD, :DWORD, :INTERNET_PORT, :DWORD
WinHttpReadData proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
WinHttpWriteData proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
WinHttpQueryDataAvailable proto stdcall :DWORD, :DWORD
WinHttpQueryOption proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
WINHTTP_NO_CLIENT_CERT_CONTEXT	EQU	<NULL>
WinHttpSetOption proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
WinHttpSetTimeouts proto stdcall :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
WinHttpIsHostInProxyBypassList proto stdcall :ptr WINHTTP_PROXY_INFO, :PCWSTR, :INTERNET_SCHEME, :INTERNET_PORT, :ptr BOOL
WINHTTP_FIRST_OPTION	EQU	<WINHTTP_OPTION_CALLBACK>
WINHTTP_OPTION_CALLBACK	EQU	1
WINHTTP_OPTION_RESOLVE_TIMEOUT	EQU	2
WINHTTP_OPTION_CONNECT_TIMEOUT	EQU	3
WINHTTP_OPTION_CONNECT_RETRIES	EQU	4
WINHTTP_OPTION_SEND_TIMEOUT	EQU	5
WINHTTP_OPTION_RECEIVE_TIMEOUT	EQU	6
WINHTTP_OPTION_RECEIVE_RESPONSE_TIMEOUT	EQU	7
WINHTTP_OPTION_HANDLE_TYPE	EQU	9
WINHTTP_OPTION_READ_BUFFER_SIZE	EQU	12
WINHTTP_OPTION_WRITE_BUFFER_SIZE	EQU	13
WINHTTP_OPTION_PARENT_HANDLE	EQU	21
WINHTTP_OPTION_EXTENDED_ERROR	EQU	24
WINHTTP_OPTION_SECURITY_FLAGS	EQU	31
WINHTTP_OPTION_SECURITY_CERTIFICATE_STRUCT	EQU	32
WINHTTP_OPTION_URL	EQU	34
WINHTTP_OPTION_SECURITY_KEY_BITNESS	EQU	36
WINHTTP_OPTION_PROXY	EQU	38
WINHTTP_OPTION_USER_AGENT	EQU	41
WINHTTP_OPTION_CONTEXT_VALUE	EQU	45
WINHTTP_OPTION_CLIENT_CERT_CONTEXT	EQU	47
WINHTTP_OPTION_REQUEST_PRIORITY	EQU	58
WINHTTP_OPTION_HTTP_VERSION	EQU	59
WINHTTP_OPTION_DISABLE_FEATURE	EQU	63
WINHTTP_OPTION_CODEPAGE	EQU	68
WINHTTP_OPTION_MAX_CONNS_PER_SERVER	EQU	73
WINHTTP_OPTION_MAX_CONNS_PER_1_0_SERVER	EQU	74
WINHTTP_OPTION_AUTOLOGON_POLICY	EQU	77
WINHTTP_OPTION_SERVER_CERT_CONTEXT	EQU	78
WINHTTP_OPTION_ENABLE_FEATURE	EQU	79
WINHTTP_OPTION_WORKER_THREAD_COUNT	EQU	80
WINHTTP_OPTION_PASSPORT_COBRANDING_TEXT	EQU	81
WINHTTP_OPTION_PASSPORT_COBRANDING_URL	EQU	82
WINHTTP_OPTION_CONFIGURE_PASSPORT_AUTH	EQU	83
WINHTTP_OPTION_SECURE_PROTOCOLS	EQU	84
WINHTTP_OPTION_ENABLETRACING	EQU	85
WINHTTP_OPTION_PASSPORT_SIGN_OUT	EQU	86
WINHTTP_OPTION_PASSPORT_RETURN_URL	EQU	87
WINHTTP_OPTION_REDIRECT_POLICY	EQU	88
WINHTTP_OPTION_MAX_HTTP_AUTOMATIC_REDIRECTS	EQU	89
WINHTTP_OPTION_MAX_HTTP_STATUS_CONTINUE	EQU	90
WINHTTP_OPTION_MAX_RESPONSE_HEADER_SIZE	EQU	91
WINHTTP_OPTION_MAX_RESPONSE_DRAIN_SIZE	EQU	92
WINHTTP_OPTION_CONNECTION_INFO	EQU	93
WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST	EQU	94
WINHTTP_OPTION_SPN	EQU	96
WINHTTP_OPTION_GLOBAL_PROXY_CREDS	EQU	97
WINHTTP_OPTION_GLOBAL_SERVER_CREDS	EQU	98
WINHTTP_OPTION_UNLOAD_NOTIFY_EVENT	EQU	99
WINHTTP_OPTION_REJECT_USERPWD_IN_URL	EQU	100
WINHTTP_OPTION_USE_GLOBAL_SERVER_CREDENTIALS	EQU	101
WINHTTP_OPTION_RECEIVE_PROXY_CONNECT_RESPONSE	EQU	103
WINHTTP_OPTION_IS_PROXY_CONNECT_RESPONSE	EQU	104
WINHTTP_OPTION_SERVER_SPN_USED	EQU	106
WINHTTP_OPTION_PROXY_SPN_USED	EQU	107
WINHTTP_OPTION_SERVER_CBT	EQU	108
WINHTTP_LAST_OPTION	EQU	<WINHTTP_OPTION_SERVER_CBT>
WINHTTP_OPTION_USERNAME	EQU	1000h
WINHTTP_OPTION_PASSWORD	EQU	1001h
WINHTTP_OPTION_PROXY_USERNAME	EQU	1002h
WINHTTP_OPTION_PROXY_PASSWORD	EQU	1003h
WINHTTP_CONNS_PER_SERVER_UNLIMITED	EQU	0FFFFFFFFh
WINHTTP_AUTOLOGON_SECURITY_LEVEL_MEDIUM	EQU	0
WINHTTP_AUTOLOGON_SECURITY_LEVEL_LOW	EQU	1
WINHTTP_AUTOLOGON_SECURITY_LEVEL_HIGH	EQU	2
WINHTTP_AUTOLOGON_SECURITY_LEVEL_DEFAULT	EQU	<WINHTTP_AUTOLOGON_SECURITY_LEVEL_MEDIUM>
WINHTTP_OPTION_REDIRECT_POLICY_NEVER	EQU	0
WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP	EQU	1
WINHTTP_OPTION_REDIRECT_POLICY_ALWAYS	EQU	2
WINHTTP_OPTION_REDIRECT_POLICY_LAST	EQU	<WINHTTP_OPTION_REDIRECT_POLICY_ALWAYS>
WINHTTP_OPTION_REDIRECT_POLICY_DEFAULT	EQU	<WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP>
WINHTTP_DISABLE_PASSPORT_AUTH	EQU	00000000h
WINHTTP_ENABLE_PASSPORT_AUTH	EQU	10000000h
WINHTTP_DISABLE_PASSPORT_KEYRING	EQU	20000000h
WINHTTP_ENABLE_PASSPORT_KEYRING	EQU	40000000h
WINHTTP_DISABLE_COOKIES	EQU	00000001h
WINHTTP_DISABLE_REDIRECTS	EQU	00000002h
WINHTTP_DISABLE_AUTHENTICATION	EQU	00000004h
WINHTTP_DISABLE_KEEP_ALIVE	EQU	00000008h
WINHTTP_ENABLE_SSL_REVOCATION	EQU	00000001h
WINHTTP_ENABLE_SSL_REVERT_IMPERSONATION	EQU	00000002h
WINHTTP_DISABLE_SPN_SERVER_PORT	EQU	00000000h
WINHTTP_ENABLE_SPN_SERVER_PORT	EQU	00000001h
WINHTTP_OPTION_SPN_MASK	EQU	<WINHTTP_ENABLE_SPN_SERVER_PORT>

WINHTTP_CREDS	struct 
	lpszUserName	LPSTR	?
	lpszPassword	LPSTR	?
	lpszRealm	LPSTR	?
	dwAuthScheme	DWORD	?
	lpszHostName	LPSTR	?
	dwPort		DWORD	?
WINHTTP_CREDS	ends

PWINHTTP_CREDS typedef ptr WINHTTP_CREDS

WINHTTP_CREDS_EX	struct 
	lpszUserName	LPSTR	?
	lpszPassword	LPSTR	?
	lpszRealm	LPSTR	?
	dwAuthScheme	DWORD	?
	lpszHostName	LPSTR	?
	dwPort		DWORD	?
	lpszUrl		LPSTR	?
WINHTTP_CREDS_EX	ends

PWINHTTP_CREDS_EX typedef ptr WINHTTP_CREDS_EX

WINHTTP_HANDLE_TYPE_SESSION	EQU	1
WINHTTP_HANDLE_TYPE_CONNECT	EQU	2
WINHTTP_HANDLE_TYPE_REQUEST	EQU	3
WINHTTP_AUTH_SCHEME_BASIC	EQU	00000001h
WINHTTP_AUTH_SCHEME_NTLM	EQU	00000002h
WINHTTP_AUTH_SCHEME_PASSPORT	EQU	00000004h
WINHTTP_AUTH_SCHEME_DIGEST	EQU	00000008h
WINHTTP_AUTH_SCHEME_NEGOTIATE	EQU	00000010h
WINHTTP_AUTH_TARGET_SERVER	EQU	00000000h
WINHTTP_AUTH_TARGET_PROXY	EQU	00000001h
SECURITY_FLAG_SECURE		EQU	00000001h
SECURITY_FLAG_STRENGTH_WEAK	EQU	10000000h
SECURITY_FLAG_STRENGTH_MEDIUM	EQU	40000000h
SECURITY_FLAG_STRENGTH_STRONG	EQU	20000000h
WINHTTP_CALLBACK_STATUS_FLAG_CERT_REV_FAILED	EQU	00000001h
WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CERT	EQU	00000002h
WINHTTP_CALLBACK_STATUS_FLAG_CERT_REVOKED	EQU	00000004h
WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CA		EQU	00000008h
WINHTTP_CALLBACK_STATUS_FLAG_CERT_CN_INVALID	EQU	00000010h
WINHTTP_CALLBACK_STATUS_FLAG_CERT_DATE_INVALID	EQU	00000020h
WINHTTP_CALLBACK_STATUS_FLAG_CERT_WRONG_USAGE	EQU	00000040h
WINHTTP_CALLBACK_STATUS_FLAG_SECURITY_CHANNEL_ERROR	EQU	80000000h
WINHTTP_FLAG_SECURE_PROTOCOL_SSL2	EQU	00000008h
WINHTTP_FLAG_SECURE_PROTOCOL_SSL3	EQU	00000020h
WINHTTP_FLAG_SECURE_PROTOCOL_TLS1	EQU	00000080h
WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_1	EQU	00000200h
WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_2	EQU	00000800h
WINHTTP_FLAG_SECURE_PROTOCOL_ALL	EQU	( WINHTTP_FLAG_SECURE_PROTOCOL_SSL2  or  WINHTTP_FLAG_SECURE_PROTOCOL_SSL3  or  WINHTTP_FLAG_SECURE_PROTOCOL_TLS1 )
proto_WINHTTP_STATUS_CALLBACK typedef proto stdcall :DWORD,:DWORD,:DWORD,:LPVOID,:DWORD
WINHTTP_STATUS_CALLBACK typedef ptr proto_WINHTTP_STATUS_CALLBACK
LPWINHTTP_STATUS_CALLBACK typedef ptr WINHTTP_STATUS_CALLBACK
WinHttpSetStatusCallback proto stdcall :DWORD, :WINHTTP_STATUS_CALLBACK, :DWORD, :DWORD
WINHTTP_CALLBACK_STATUS_RESOLVING_NAME	EQU	00000001h
WINHTTP_CALLBACK_STATUS_NAME_RESOLVED	EQU	00000002h
WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER	EQU	00000004h
WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER	EQU	00000008h
WINHTTP_CALLBACK_STATUS_SENDING_REQUEST	EQU	00000010h
WINHTTP_CALLBACK_STATUS_REQUEST_SENT	EQU	00000020h
WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE	EQU	00000040h
WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED	EQU	00000080h
WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION	EQU	00000100h
WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED	EQU	00000200h
WINHTTP_CALLBACK_STATUS_HANDLE_CREATED	EQU	00000400h
WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING	EQU	00000800h
WINHTTP_CALLBACK_STATUS_DETECTING_PROXY	EQU	00001000h
WINHTTP_CALLBACK_STATUS_REDIRECT	EQU	00004000h
WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE	EQU	00008000h
WINHTTP_CALLBACK_STATUS_SECURE_FAILURE	EQU	00010000h
WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE	EQU	00020000h
WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE	EQU	00040000h
WINHTTP_CALLBACK_STATUS_READ_COMPLETE	EQU	00080000h
WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE	EQU	00100000h
WINHTTP_CALLBACK_STATUS_REQUEST_ERROR	EQU	00200000h
WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE	EQU	00400000h
API_RECEIVE_RESPONSE	EQU	1
API_QUERY_DATA_AVAILABLE	EQU	2
API_READ_DATA	EQU	3
API_WRITE_DATA	EQU	4
API_SEND_REQUEST	EQU	5
WINHTTP_CALLBACK_FLAG_RESOLVE_NAME	EQU	( WINHTTP_CALLBACK_STATUS_RESOLVING_NAME  or  WINHTTP_CALLBACK_STATUS_NAME_RESOLVED )
WINHTTP_CALLBACK_FLAG_CONNECT_TO_SERVER	EQU	( WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER  or  WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER )
WINHTTP_CALLBACK_FLAG_SEND_REQUEST	EQU	( WINHTTP_CALLBACK_STATUS_SENDING_REQUEST  or  WINHTTP_CALLBACK_STATUS_REQUEST_SENT )
WINHTTP_CALLBACK_FLAG_RECEIVE_RESPONSE	EQU	( WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE  or  WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED )
WINHTTP_CALLBACK_FLAG_CLOSE_CONNECTION	EQU	( WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION  or  WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED )
WINHTTP_CALLBACK_FLAG_HANDLES	EQU	( WINHTTP_CALLBACK_STATUS_HANDLE_CREATED  or  WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING )
WINHTTP_CALLBACK_FLAG_DETECTING_PROXY	EQU	<WINHTTP_CALLBACK_STATUS_DETECTING_PROXY>
WINHTTP_CALLBACK_FLAG_REDIRECT	EQU	<WINHTTP_CALLBACK_STATUS_REDIRECT>
WINHTTP_CALLBACK_FLAG_INTERMEDIATE_RESPONSE	EQU	<WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE>
WINHTTP_CALLBACK_FLAG_SECURE_FAILURE	EQU	<WINHTTP_CALLBACK_STATUS_SECURE_FAILURE>
WINHTTP_CALLBACK_FLAG_SENDREQUEST_COMPLETE	EQU	<WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE>
WINHTTP_CALLBACK_FLAG_HEADERS_AVAILABLE	EQU	<WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE>
WINHTTP_CALLBACK_FLAG_DATA_AVAILABLE	EQU	<WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE>
WINHTTP_CALLBACK_FLAG_READ_COMPLETE	EQU	<WINHTTP_CALLBACK_STATUS_READ_COMPLETE>
WINHTTP_CALLBACK_FLAG_WRITE_COMPLETE	EQU	<WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE>
WINHTTP_CALLBACK_FLAG_REQUEST_ERROR	EQU	<WINHTTP_CALLBACK_STATUS_REQUEST_ERROR>
WINHTTP_EQU_A	EQU	( WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE  or  WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE  or  WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE )
WINHTTP_EQU_B	EQU	( WINHTTP_CALLBACK_STATUS_READ_COMPLETE  or  WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE  or  WINHTTP_CALLBACK_STATUS_REQUEST_ERROR )
WINHTTP_CALLBACK_FLAG_ALL_COMPLETIONS	EQU	( WINHTTP_EQU_A or WINHTTP_EQU_B )
WINHTTP_CALLBACK_FLAG_ALL_NOTIFICATIONS	EQU	0ffffffffh
WINHTTP_INVALID_STATUS_CALLBACK	EQU	( ( WINHTTP_STATUS_CALLBACK ) - 1 )
WINHTTP_QUERY_MIME_VERSION	EQU	0
WINHTTP_QUERY_CONTENT_TYPE	EQU	1
WINHTTP_QUERY_CONTENT_TRANSFER_ENCODING	EQU	2
WINHTTP_QUERY_CONTENT_ID	EQU	3
WINHTTP_QUERY_CONTENT_DESCRIPTION	EQU	4
WINHTTP_QUERY_CONTENT_LENGTH	EQU	5
WINHTTP_QUERY_CONTENT_LANGUAGE	EQU	6
WINHTTP_QUERY_ALLOW	EQU	7
WINHTTP_QUERY_PUBLIC	EQU	8
WINHTTP_QUERY_DATE	EQU	9
WINHTTP_QUERY_EXPIRES	EQU	10
WINHTTP_QUERY_LAST_MODIFIED	EQU	11
WINHTTP_QUERY_MESSAGE_ID	EQU	12
WINHTTP_QUERY_URI	EQU	13
WINHTTP_QUERY_DERIVED_FROM	EQU	14
WINHTTP_QUERY_COST	EQU	15
WINHTTP_QUERY_LINK	EQU	16
WINHTTP_QUERY_PRAGMA	EQU	17
WINHTTP_QUERY_VERSION	EQU	18
WINHTTP_QUERY_STATUS_CODE	EQU	19
WINHTTP_QUERY_STATUS_TEXT	EQU	20
WINHTTP_QUERY_RAW_HEADERS	EQU	21
WINHTTP_QUERY_RAW_HEADERS_CRLF	EQU	22
WINHTTP_QUERY_CONNECTION	EQU	23
WINHTTP_QUERY_ACCEPT	EQU	24
WINHTTP_QUERY_ACCEPT_CHARSET	EQU	25
WINHTTP_QUERY_ACCEPT_ENCODING	EQU	26
WINHTTP_QUERY_ACCEPT_LANGUAGE	EQU	27
WINHTTP_QUERY_AUTHORIZATION	EQU	28
WINHTTP_QUERY_CONTENT_ENCODING	EQU	29
WINHTTP_QUERY_FORWARDED	EQU	30
WINHTTP_QUERY_FROM	EQU	31
WINHTTP_QUERY_IF_MODIFIED_SINCE	EQU	32
WINHTTP_QUERY_LOCATION	EQU	33
WINHTTP_QUERY_ORIG_URI	EQU	34
WINHTTP_QUERY_REFERER	EQU	35
WINHTTP_QUERY_RETRY_AFTER	EQU	36
WINHTTP_QUERY_SERVER	EQU	37
WINHTTP_QUERY_TITLE	EQU	38
WINHTTP_QUERY_USER_AGENT	EQU	39
WINHTTP_QUERY_WWW_AUTHENTICATE	EQU	40
WINHTTP_QUERY_PROXY_AUTHENTICATE	EQU	41
WINHTTP_QUERY_ACCEPT_RANGES	EQU	42
WINHTTP_QUERY_SET_COOKIE	EQU	43
WINHTTP_QUERY_COOKIE	EQU	44
WINHTTP_QUERY_REQUEST_METHOD	EQU	45
WINHTTP_QUERY_REFRESH	EQU	46
WINHTTP_QUERY_CONTENT_DISPOSITION	EQU	47
WINHTTP_QUERY_AGE	EQU	48
WINHTTP_QUERY_CACHE_CONTROL	EQU	49
WINHTTP_QUERY_CONTENT_BASE	EQU	50
WINHTTP_QUERY_CONTENT_LOCATION	EQU	51
WINHTTP_QUERY_CONTENT_MD5	EQU	52
WINHTTP_QUERY_CONTENT_RANGE	EQU	53
WINHTTP_QUERY_ETAG	EQU	54
WINHTTP_QUERY_HOST	EQU	55
WINHTTP_QUERY_IF_MATCH	EQU	56
WINHTTP_QUERY_IF_NONE_MATCH	EQU	57
WINHTTP_QUERY_IF_RANGE	EQU	58
WINHTTP_QUERY_IF_UNMODIFIED_SINCE	EQU	59
WINHTTP_QUERY_MAX_FORWARDS	EQU	60
WINHTTP_QUERY_PROXY_AUTHORIZATION	EQU	61
WINHTTP_QUERY_RANGE	EQU	62
WINHTTP_QUERY_TRANSFER_ENCODING	EQU	63
WINHTTP_QUERY_UPGRADE	EQU	64
WINHTTP_QUERY_VARY	EQU	65
WINHTTP_QUERY_VIA	EQU	66
WINHTTP_QUERY_WARNING	EQU	67
WINHTTP_QUERY_EXPECT	EQU	68
WINHTTP_QUERY_PROXY_CONNECTION	EQU	69
WINHTTP_QUERY_UNLESS_MODIFIED_SINCE	EQU	70
WINHTTP_QUERY_PROXY_SUPPORT	EQU	75
WINHTTP_QUERY_AUTHENTICATION_INFO	EQU	76
WINHTTP_QUERY_PASSPORT_URLS	EQU	77
WINHTTP_QUERY_PASSPORT_CONFIG	EQU	78
WINHTTP_QUERY_MAX	EQU	78
WINHTTP_QUERY_CUSTOM	EQU	65535
WINHTTP_QUERY_FLAG_REQUEST_HEADERS	EQU	80000000h
WINHTTP_QUERY_FLAG_SYSTEMTIME	EQU	40000000h
WINHTTP_QUERY_FLAG_NUMBER	EQU	20000000h
HTTP_STATUS_CONTINUE	EQU	100
HTTP_STATUS_SWITCH_PROTOCOLS	EQU	101
HTTP_STATUS_OK	EQU	200
HTTP_STATUS_CREATED	EQU	201
HTTP_STATUS_ACCEPTED	EQU	202
HTTP_STATUS_PARTIAL	EQU	203
HTTP_STATUS_NO_CONTENT	EQU	204
HTTP_STATUS_RESET_CONTENT	EQU	205
HTTP_STATUS_PARTIAL_CONTENT	EQU	206
HTTP_STATUS_WEBDAV_MULTI_STATUS	EQU	207
HTTP_STATUS_AMBIGUOUS	EQU	300
HTTP_STATUS_MOVED	EQU	301
HTTP_STATUS_REDIRECT	EQU	302
HTTP_STATUS_REDIRECT_METHOD	EQU	303
HTTP_STATUS_NOT_MODIFIED	EQU	304
HTTP_STATUS_USE_PROXY	EQU	305
HTTP_STATUS_REDIRECT_KEEP_VERB	EQU	307
HTTP_STATUS_BAD_REQUEST	EQU	400
HTTP_STATUS_DENIED	EQU	401
HTTP_STATUS_PAYMENT_REQ	EQU	402
HTTP_STATUS_FORBIDDEN	EQU	403
HTTP_STATUS_NOT_FOUND	EQU	404
HTTP_STATUS_BAD_METHOD	EQU	405
HTTP_STATUS_NONE_ACCEPTABLE	EQU	406
HTTP_STATUS_PROXY_AUTH_REQ	EQU	407
HTTP_STATUS_REQUEST_TIMEOUT	EQU	408
HTTP_STATUS_CONFLICT	EQU	409
HTTP_STATUS_GONE	EQU	410
HTTP_STATUS_LENGTH_REQUIRED	EQU	411
HTTP_STATUS_PRECOND_FAILED	EQU	412
HTTP_STATUS_REQUEST_TOO_LARGE	EQU	413
HTTP_STATUS_URI_TOO_LONG	EQU	414
HTTP_STATUS_UNSUPPORTED_MEDIA	EQU	415
HTTP_STATUS_RETRY_WITH	EQU	449
HTTP_STATUS_SERVER_ERROR	EQU	500
HTTP_STATUS_NOT_SUPPORTED	EQU	501
HTTP_STATUS_BAD_GATEWAY	EQU	502
HTTP_STATUS_SERVICE_UNAVAIL	EQU	503
HTTP_STATUS_GATEWAY_TIMEOUT	EQU	504
HTTP_STATUS_VERSION_NOT_SUP	EQU	505
;HTTP_STATUS_FIRST	EQU	<HTTP_STATUS_CONTINUE>
;HTTP_STATUS_LAST	EQU	<HTTP_STATUS_VERSION_NOT_SUP>
WinHttpOpenRequest proto stdcall :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :ptr LPWSTR, :DWORD
WINHTTP_NO_REFERER	EQU	<NULL>
WINHTTP_DEFAULT_ACCEPT_TYPES	EQU	<NULL>
WinHttpAddRequestHeaders proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
WINHTTP_ADDREQ_INDEX_MASK	EQU	0000FFFFh
WINHTTP_ADDREQ_FLAGS_MASK	EQU	0FFFF0000h
WINHTTP_ADDREQ_FLAG_ADD_IF_NEW	EQU	10000000h
WINHTTP_ADDREQ_FLAG_ADD	EQU	20000000h
WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA	EQU	40000000h
WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON	EQU	01000000h
WINHTTP_ADDREQ_FLAG_COALESCE	EQU	<WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA>
WINHTTP_ADDREQ_FLAG_REPLACE	EQU	80000000h
WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH	EQU	0
WinHttpSendRequest proto stdcall :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
WINHTTP_NO_ADDITIONAL_HEADERS	EQU	<NULL>
WINHTTP_NO_REQUEST_DATA	EQU	<NULL>
WinHttpSetCredentials proto stdcall :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :LPVOID
WinHttpQueryAuthSchemes proto stdcall :DWORD, :DWORD, :DWORD, :DWORD
WinHttpQueryAuthParams proto stdcall :DWORD, :DWORD, :ptr LPVOID
WinHttpReceiveResponse proto stdcall :DWORD, :LPVOID
WinHttpQueryHeaders proto stdcall :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
WINHTTP_HEADER_NAME_BY_INDEX	EQU	<NULL>
WINHTTP_NO_OUTPUT_BUFFER	EQU	<NULL>
WINHTTP_NO_HEADER_INDEX	EQU	<NULL>
WinHttpDetectAutoProxyConfigUrl proto stdcall :DWORD, :ptr LPWSTR
WinHttpGetProxyForUrl proto stdcall :DWORD, :DWORD, :ptr WINHTTP_AUTOPROXY_OPTIONS, :ptr WINHTTP_PROXY_INFO

WINHTTP_CURRENT_USER_IE_PROXY_CONFIG	struct 
	fAutoDetect	BOOL	?
	lpszAutoConfigUrl LPWSTR	?
	lpszProxy	LPWSTR	?
	lpszProxyBypass	LPWSTR	?
WINHTTP_CURRENT_USER_IE_PROXY_CONFIG	ends

WinHttpGetIEProxyConfigForCurrentUser proto stdcall :ptr WINHTTP_CURRENT_USER_IE_PROXY_CONFIG
WINHTTP_ERROR_BASE	EQU	12000
ERROR_WINHTTP_OUT_OF_HANDLES	EQU	( WINHTTP_ERROR_BASE + 1 )
ERROR_WINHTTP_TIMEOUT	EQU	( WINHTTP_ERROR_BASE + 2 )
ERROR_WINHTTP_INTERNAL_ERROR	EQU	( WINHTTP_ERROR_BASE + 4 )
ERROR_WINHTTP_INVALID_URL	EQU	( WINHTTP_ERROR_BASE + 5 )
ERROR_WINHTTP_UNRECOGNIZED_SCHEME	EQU	( WINHTTP_ERROR_BASE + 6 )
ERROR_WINHTTP_NAME_NOT_RESOLVED	EQU	( WINHTTP_ERROR_BASE + 7 )
ERROR_WINHTTP_INVALID_OPTION	EQU	( WINHTTP_ERROR_BASE + 9 )
ERROR_WINHTTP_OPTION_NOT_SETTABLE	EQU	( WINHTTP_ERROR_BASE + 11 )
ERROR_WINHTTP_SHUTDOWN	EQU	( WINHTTP_ERROR_BASE + 12 )
ERROR_WINHTTP_LOGIN_FAILURE	EQU	( WINHTTP_ERROR_BASE + 15 )
ERROR_WINHTTP_OPERATION_CANCELLED	EQU	( WINHTTP_ERROR_BASE + 17 )
ERROR_WINHTTP_INCORRECT_HANDLE_TYPE	EQU	( WINHTTP_ERROR_BASE + 18 )
ERROR_WINHTTP_INCORRECT_HANDLE_STATE	EQU	( WINHTTP_ERROR_BASE + 19 )
ERROR_WINHTTP_CANNOT_CONNECT	EQU	( WINHTTP_ERROR_BASE + 29 )
ERROR_WINHTTP_CONNECTION_ERROR	EQU	( WINHTTP_ERROR_BASE + 30 )
ERROR_WINHTTP_RESEND_REQUEST	EQU	( WINHTTP_ERROR_BASE + 32 )
ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED	EQU	( WINHTTP_ERROR_BASE + 44 )
ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN	EQU	( WINHTTP_ERROR_BASE + 100 )
ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND	EQU	( WINHTTP_ERROR_BASE + 101 )
ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND	EQU	( WINHTTP_ERROR_BASE + 102 )
ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN	EQU	( WINHTTP_ERROR_BASE + 103 )
ERROR_WINHTTP_HEADER_NOT_FOUND	EQU	( WINHTTP_ERROR_BASE + 150 )
ERROR_WINHTTP_INVALID_SERVER_RESPONSE	EQU	( WINHTTP_ERROR_BASE + 152 )
ERROR_WINHTTP_INVALID_HEADER	EQU	( WINHTTP_ERROR_BASE + 153 )
ERROR_WINHTTP_INVALID_QUERY_REQUEST	EQU	( WINHTTP_ERROR_BASE + 154 )
ERROR_WINHTTP_HEADER_ALREADY_EXISTS	EQU	( WINHTTP_ERROR_BASE + 155 )
ERROR_WINHTTP_REDIRECT_FAILED	EQU	( WINHTTP_ERROR_BASE + 156 )
ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR	EQU	( WINHTTP_ERROR_BASE + 178 )
ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT	EQU	( WINHTTP_ERROR_BASE + 166 )
ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT	EQU	( WINHTTP_ERROR_BASE + 167 )
ERROR_WINHTTP_NOT_INITIALIZED	EQU	( WINHTTP_ERROR_BASE + 172 )
ERROR_WINHTTP_SECURE_FAILURE	EQU	( WINHTTP_ERROR_BASE + 175 )
ERROR_WINHTTP_SECURE_CERT_DATE_INVALID	EQU	( WINHTTP_ERROR_BASE + 37 )
ERROR_WINHTTP_SECURE_CERT_CN_INVALID	EQU	( WINHTTP_ERROR_BASE + 38 )
ERROR_WINHTTP_SECURE_INVALID_CA	EQU	( WINHTTP_ERROR_BASE + 45 )
ERROR_WINHTTP_SECURE_CERT_REV_FAILED	EQU	( WINHTTP_ERROR_BASE + 57 )
ERROR_WINHTTP_SECURE_CHANNEL_ERROR	EQU	( WINHTTP_ERROR_BASE + 157 )
ERROR_WINHTTP_SECURE_INVALID_CERT	EQU	( WINHTTP_ERROR_BASE + 169 )
ERROR_WINHTTP_SECURE_CERT_REVOKED	EQU	( WINHTTP_ERROR_BASE + 170 )
ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE	EQU	( WINHTTP_ERROR_BASE + 179 )
ERROR_WINHTTP_AUTODETECTION_FAILED	EQU	( WINHTTP_ERROR_BASE + 180 )
ERROR_WINHTTP_HEADER_COUNT_EXCEEDED	EQU	( WINHTTP_ERROR_BASE + 181 )
ERROR_WINHTTP_HEADER_SIZE_OVERFLOW	EQU	( WINHTTP_ERROR_BASE + 182 )
ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW	EQU	( WINHTTP_ERROR_BASE + 183 )
ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW	EQU	( WINHTTP_ERROR_BASE + 184 )
ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY	EQU	( WINHTTP_ERROR_BASE + 185 )
ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY	EQU	( WINHTTP_ERROR_BASE + 186 )
WINHTTP_ERROR_LAST	EQU	( WINHTTP_ERROR_BASE + 186 )