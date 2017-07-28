#ifndef _CEXP_H_HEADER_INCLUDED_
#define _CEXP_H_HEADER_INCLUDED_  1


#ifdef DEBUG

#define TraceAssert( bValue , pMsg )               \
        {                                          \
            if( bValue )                           \
            {                                      \
                TRACE_LINE(#bValue);               \
                TRACE_LINE(pMsg);                  \
            }                                      \
        }

#define TRACE(a)    TRACE_LINE(#a)

#else

#define TRACE(a)

#endif

//runtime log
#define DUMP_RUNTIME_DEBUG_INFO
#define TRACE_FUNC_DETAIL
//debug tracer



#ifdef TRACE_FUNC_DETAIL
#define TRACE_FUNC()  {}
        //tracer.Out("%s:%s:%d",__FILE__,__func__,__LINE__ ); 

#else
#define TRACE_FUNC() 
#endif

#ifdef DUMP_RUNTIME_DEBUG_INFO

#define TRACE_LINE(str)   {}
    //tracer.Out("%s:%d,  %s",__FILE__,__LINE__,(str)) ;

/*
#define TRACE_ASSERT( bValue , pMsg )                                           \
        {                                                                       \
            if( bValue )                                                        \
            {                                                                   \
                //tracer.Out("%s:%d,Assert fail: %s , program exit"               \
                           ,__FILE__,__LINE__,(pMsg)) ;                         \
                exit(-1);                                                       \
            }                                                                   \
        }
*/

#define TRACE_LINE_2(str) { \
        WriteAppNormalLog("%s:%d,%s",__FILE__,__LINE__,(str));        \
    }

#define TRACE_HEX_LINE(str,len)
/*
//      { \
//              WriteAppNormalLog("[%s] [%s] [%d]",__FILE__,str,len);           \
//      } 
*/
#else


#define TRACE_LINE(str)
#define TRACE_HEX_LINE(str,len)
#endif                          //DUMP_RUNTIME_DEBUG_INFO


#define MAPCStr(a,b)          \
       ((char *)(a)[(b)].c_str())
       
#define MAPTransVar(a,b)      \
       ((string)g_mTransactions[(a)].m_mVars[(b)])
       
#define MAPTransVarCStr(a,b)  \
       ((char *)(g_mTransactions[(a)].m_mVars[(b)].c_str()))    
        
#define MAPDBVarCStr(a,b)     \
        ((char *)(g_mDbs[a].b.c_str (  )))
        
#define MAPIfFieldCStr(a,b)     \
        ((char *)(g_mInterfaces[a].b.c_str (  )))

class CTrsExp
{
  public:
    string retcode, retmsg;
    CTrsExp ( const char *str )
    {
        retmsg = string ( str );
        retcode = string ( "0" );
    };

    CTrsExp ( string str )
    {
        retmsg = string ( str );
        retcode = string ( "0" );
    };
    CTrsExp ( int cd, string str )
    {
        char szCd[32] = {0};
        
        sprintf(szCd , "%04d", cd);
        retmsg = str;
        retcode = string(szCd);
    };
    CTrsExp ( string cd, string str )
    {
        retmsg = str;
        retcode = cd;
    };
};

class CExecLogicalExp
{
  public:
    string retcode, retmsg;
    CExecLogicalExp ( const char *str )
    {
        retmsg = string ( str );
        retcode = string ( "0" );
    };

    CExecLogicalExp ( string str )
    {
        retmsg = string ( str );
        retcode = string ( "0" );
    };
    CExecLogicalExp ( int cd, string str )
    {
        char szCd[32] = {0};
        
        sprintf(szCd , "%04d", cd);
        retmsg = str;
        retcode = string(szCd);
    };
    CExecLogicalExp ( string cd, string str )
    {
        retmsg = str;
        retcode = cd;
    };
};

#define ThrowError(iCode,pszInfo) {         \
        gPtrAppLog->debug("[%s][%s:%d] pszInfo=[%s]", __func__, __FILE__, __LINE__, pszInfo); \
        throw(( (int)(iCode) ));   }
        
#define ThrowCTrsExp(iCode,pszInfo)     {   \
        gPtrAppLog->debug("[%s][%s:%d] pszInfo=[%s]", __func__, __FILE__, __LINE__, pszInfo); \
        throw( CTrsExp(iCode, pszInfo)); }    
        
        
#endif  /* _CEXP_H_HEADER_INCLUDED_ */
