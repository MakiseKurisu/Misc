#include "libKDays.h"

LPKDAYS_BOOK_INFO WINAPI kdays_get_book_info(
    _In_    HANDLE hKDays,
    _In_    int bid
    )
{
    /*
    http://xs.kdays.cn/api/get_book_info?apikey=hWxE7C1PrB6f4uAiAv&id=400
    {
        "id":"400",
        "fav" : "0",
        "hit" : "64",
        "name" : "�ұ������������ˣ�",
        "introduce" : "�������ꡤ����Ҫת����һ����ʷ�ƾõ����Ŵ�С��ѧУ��",
        "spec" : "",
        "time" : "1370607945",
        "author" : "ˮ�ڵ���",
        "keyword" : "У԰,����",
        "firstword" : "w",
        "updated" : "1373946951",
        "jpname" : "���󥿥�!!��󥿥����ӤϤ���ޤ���",
        "status" : "0",
        "words" : "83611",
        "apply" : "0",
        "origin" : "0",
        "illustration" : "�ؤ���",
        "zt" : "",
        "like_num" : "0",
        "code" : 200
    }
    */
    return NULL;
}

LPKDAYS_BOOK_DIR WINAPI kdays_get_book_dir(
    _In_    HANDLE hKDays,
    _In_    INT bid
    )
{
    /*
    http://xs.kdays.cn/api/get_book_dir?apikey=hWxE7C1PrB6f4uAiAv&id=400
    {
        "code":"200",
        "msg" : "ok",
        "root" :
        {
            "19498":
            {
                "uptime":"1373946649",
                "name" : "��һ��",
                "content" : "",
            }
        },
        "node" :
        {
            "19498":
            {
                "19499":
                {
                    "name":"Prologue",
                    "size" : "4534",
                    "subid" : "19498",
                }
            }
        }
    }
    */
    return NULL;
}

LPKDAYS_BOOK_CONTENT WINAPI kdays_get_book_content(
    _In_    HANDLE hKDays,
    _In_    INT bid,
    _In_    INT cid
    )
{
    /*
    http://xs.kdays.cn/api/get_book_content?apikey=hWxE7C1PrB6f4uAiAv&id=400&cid=19499
    {
        "code":"200",
        "msg" : "ok",
        "prev" : null,
        "next" : "19500",
        "subid" : "19498",
        "content" : " * ���µĵ�һ�졣"
    }
    */
    return NULL;
}

LPKDAYS_BOOK_RESULT WINAPI kdays_search_book(
    _In_        HANDLE hKDays,
    _In_        LPCWSTR keyword,
    _In_opt_    INT spec,
    _In_opt_    INT status,
    _In_opt_    INT order
    )
{
    /*
    http://xs.kdays.cn/api/search_book?apikey=hWxE7C1PrB6f4uAiAv&keyword=%E5%8F%AF%E7%88%B1
    {
        "code":"200",
        "msg" : "search ok",
        "length" : 2,
        "result" : 
        [
            {
                "id":"443",
                "fav" : "0",
                "hit" : "12",
                "name" : "�ҵ�������17����(�ҵ����費������ô�ɰ�)",
                "introduce" : "���¡ʷ�����ж��꼶ѧ����ĳһ���ѧУ�ؼҵ�·�Ϻ�Ȼ������һ������ʶ��Ů�������� ��¡ ..",
                "spec" : "",
                "time" : "1384486471",
                "author" : "��ǰ��",
                "keyword" : "ħ��,����Ŀ�",
                "firstword" : "w",
                "updated" : "2013-11-15",
                "jpname" : "���Τ��`�����17�r�ˤʤä�",
                "status" : "1",
                "words" : "110864",
                "apply" : "0",
                "origin" : "0",
                "illustration" : "�ѥ���",
                "zt" : "",
                "like_num" : "0",
                "newchapter" : "���",
                "newchapterid" : "21039"
            },
            {
                "id":"69",
                "fav" : "1",
                "hit" : "4640",
                "name" : "�ҵ����ò�������ô�ɰ�",
                "introduce" : "�����ྩ�飨17�꣩�����ø���ͩ�ˣ�14�꣩�������˵Ĺ�ϵ�����괦����ս״̬����ĳ��ʱ�� ..",
                "spec" : "",
                "time" : "1355501852",
                "author" : "����˾",
                "keyword" : "��լ��,������,����,��,GAL,����Ŀ�",
                "firstword" : "w",
                "updated" : "2013-01-19",
                "jpname" : "�����ä�����ʤ˿ɐۤ��櫓���ʤ�",
                "status" : "1",
                "words" : "1557670",
                "apply" : "0",
                "origin" : "0",
                "illustration" : "���󤶤��Ҥ�",
                "zt" : "a:1:{s:1:\"c\",a:2:{i:0,s:1:\"1\",i:1,s:1:\"2\",}}",
                "like_num" : "0",
                "newchapter" : "���",
                "newchapterid" : "15272"
            }
        ]
    }
    */
    return NULL;
}

LPKDAYS_BOOK_RESULT WINAPI kdays_get_top(
    _In_        HANDLE hKDays,
    _In_opt_    INT order
    )
{
    /*
    http://kdays.cn/apidocs/doku.php?id=wkapi:get_top
    {
        "code":"200",
        "msg" : "ok",
        "type" : "hits",
        "result" :
        [
            {
                "name":"������",
                "hit" : "1305",
                "id" : "4",
                "introduce" : "��֮У԰�տ�ѧ���þ�ӭ��������תУ��"
            }
        ]
    }
    */
    return NULL;
}