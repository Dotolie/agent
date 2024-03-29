//------------------------------------------------------------------------------
//
//  Copyright (C) 2008 MVTech Co., Ltd. All Rights Reserved
//  MVTech Co.,Ltd. Proprietary & Confidential
//
//  Reproduction in whole or in part is prohibited without the written consent 
//  of the copyright owner. MVTech reserves the right to make changes 
//  without notice at any time. MVTech makes no warranty, expressed, 
//  implied or statutory, including but not limited to any implied warranty of 
//  merchantability or fitness for any particular purpose, or that the use will
//  not infringe any third party patent,  copyright or trademark. 
//  MVTech must not be liable for any loss or damage arising from its use.
//
//  Module      :
//  File           : task.h
//  Description :
//  Author       : ywkim@mvtech.or.kr
//  Export       :
//  History      :
//
//------------------------------------------------------------------------------


#ifndef __TASK_H__
#define __TASK_H__


#include "object.h"
#include "stdafx.h"
#include "thread.h"
#include "work.h"
#include "timer.h"
#include "device.h"


class CTask : public CObject
{     
public:
	static unsigned short CRC16TBL[];
	struct MessageMap {
		int iMsg;
		int (CTask::*mfp)( int wparam, int lparam );
	};

	CWork	*m_pWork;
	Thread	*m_pthSocket; 
	CDevice 	*m_pDevice;
	Thread	*m_pthDevice;
	CTimer 	*m_pTimer;
	Thread	*m_pthTimer;
	
public:	
	CTask();
	~CTask();
	unsigned short CRC16( const unsigned char* pdata, int size );

	int On_PKT_ACK( int, int );
	int On_PKT_NAK( int, int );
	int On_PKT_REQ_GETPARAMS( int, int );
	int On_PKT_REQ_SETPARAMS( int, int );
	int On_PKT_RESET( int, int );		
	
	int On_MSG_CREATE( int, int );
	int On_MSG_CLOSE( int, int );
	int On_MSG_DISCONNECT( int, int );
	int On_MSG_QUIT( int, int );
	
	DECLARE_MESSAGE_MAP();

}; 


#endif /* __TASK_H__ */

