		.code
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_IniParser	proc	uses ebx edi esi _lpszData,_lpszKeyName,_lpszValue
		
		.if	(!_lpszData) || (!_lpszKeyName) || (!_lpszValue)
			xor	eax,eax
			ret
		.endif
		mov	esi,_lpszData
		cld
		.while	TRUE	;����Ϊ��λ,�ж�Section,Key�Լ�����
			.break	.if	byte ptr [esi] == 0	;�ļ�ĩβ
			.if	(byte ptr [esi] == 0dh) || (byte ptr [esi] == 0ah)	;����
				inc	esi
				.continue
			.endif
			mov	edi,_lpszKeyName
			.while	TRUE	;�жϼ�ֵ
				.if	(byte ptr [esi] == 0dh) || (byte ptr [esi] == 0ah)	;���ҵ�����ĩβҲû��ƥ��
					inc	esi
					.break
				.endif
				.break	.if	byte ptr [esi] == 0				;���ҵ����ļ�ĩβ
				.if	(byte ptr [esi] == '=') && (byte ptr [edi] == 0)	;Keyƥ��
					inc	esi
					mov	edi,_lpszValue
					.while	TRUE
						lodsb
						.break	.if	(al == 0dh) || (al == 0ah)
						.if	al  ==	0
							dec	esi
							.break
						.endif
						stosb
					.endw
					xor	eax,eax
					stosb
					.break
				.endif
				cmpsb
				.if	!ZERO?	;Key��ƥ��
					.while	TRUE
						lodsb
						.break	.if	(al == 0dh) || (al == 0ah)
						.if	al  ==	0
							dec	edi
							.break
						.endif
					.endw
					.break
				.endif
			.endw
		.endw
		ret
_IniParser	endp