/**********************************************************************
 *
 * Copyright (C) Imagination Technologies Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful but, except
 * as otherwise stated in writing, without any warranty; without even the
 * implied warranty of merchantability or fitness for a particular purpose.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * The full GNU General Public License is included in this distribution in
 * the file called "COPYING".
 *
 * Contact Information:
 * Imagination Technologies Ltd. <gpl-support@imgtec.com>
 * Home Park Estate, Kings Langley, Herts, WD4 8LZ, UK
 *
 ******************************************************************************/

#if !defined(__SGX_BRIDGE_H__)
#define __SGX_BRIDGE_H__

#if defined (SUPPORT_SID_INTERFACE)
#include "sgxapi.h"
#else
#include "sgxapi_km.h"
#endif
#include "sgxinfo.h"
#include "pvr_bridge.h"

#if defined (__cplusplus)
extern "C" {
#endif


#define PVRSRV_BRIDGE_SGX_CMD_BASE (PVRSRV_BRIDGE_LAST_NON_DEVICE_CMD+1)
#define PVRSRV_BRIDGE_SGX_GETCLIENTINFO			PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+0)
#define PVRSRV_BRIDGE_SGX_RELEASECLIENTINFO		PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+1)
#define PVRSRV_BRIDGE_SGX_GETINTERNALDEVINFO	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+2)
#define PVRSRV_BRIDGE_SGX_DOKICK				PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+3)
#define PVRSRV_BRIDGE_SGX_GETPHYSPAGEADDR		PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+4)
#define PVRSRV_BRIDGE_SGX_READREGISTRYDWORD		PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+5)

#define PVRSRV_BRIDGE_SGX_2DQUERYBLTSCOMPLETE   PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+9)

#if defined(TRANSFER_QUEUE)
#define PVRSRV_BRIDGE_SGX_SUBMITTRANSFER			PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+13)
#endif
#define PVRSRV_BRIDGE_SGX_GETMISCINFO				PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+14)
#define PVRSRV_BRIDGE_SGXINFO_FOR_SRVINIT			PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+15)
#define PVRSRV_BRIDGE_SGX_DEVINITPART2				PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+16)

#define PVRSRV_BRIDGE_SGX_FINDSHAREDPBDESC			PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+17)
#define PVRSRV_BRIDGE_SGX_UNREFSHAREDPBDESC			PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+18)
#define PVRSRV_BRIDGE_SGX_ADDSHAREDPBDESC			PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+19)
#define PVRSRV_BRIDGE_SGX_REGISTER_HW_RENDER_CONTEXT	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+20)
#define PVRSRV_BRIDGE_SGX_FLUSH_HW_RENDER_TARGET	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+21)
#define PVRSRV_BRIDGE_SGX_UNREGISTER_HW_RENDER_CONTEXT	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+22)
#if defined(SGX_FEATURE_2D_HARDWARE)
#define PVRSRV_BRIDGE_SGX_SUBMIT2D					PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+23)
#define PVRSRV_BRIDGE_SGX_REGISTER_HW_2D_CONTEXT	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+24)
#define PVRSRV_BRIDGE_SGX_UNREGISTER_HW_2D_CONTEXT	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+25)
#endif
#define PVRSRV_BRIDGE_SGX_REGISTER_HW_TRANSFER_CONTEXT	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+26)
#define PVRSRV_BRIDGE_SGX_UNREGISTER_HW_TRANSFER_CONTEXT	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+27)

#define PVRSRV_BRIDGE_SGX_SCHEDULE_PROCESS_QUEUES		PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+28)

#define PVRSRV_BRIDGE_SGX_READ_HWPERF_CB			PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+29)
#define PVRSRV_BRIDGE_SGX_SET_RENDER_CONTEXT_PRIORITY      PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+30)
#define PVRSRV_BRIDGE_SGX_SET_TRANSFER_CONTEXT_PRIORITY      PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+31)

#if defined(PDUMP)
#define PVRSRV_BRIDGE_SGX_PDUMP_BUFFER_ARRAY		PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+32)
#define PVRSRV_BRIDGE_SGX_PDUMP_3D_SIGNATURE_REGISTERS	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+33)
#define PVRSRV_BRIDGE_SGX_PDUMP_COUNTER_REGISTERS	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+34)
#define PVRSRV_BRIDGE_SGX_PDUMP_TA_SIGNATURE_REGISTERS	PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+35)
#define PVRSRV_BRIDGE_SGX_PDUMP_HWPERFCB				PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+36)
#define PVRSRV_BRIDGE_SGX_PDUMP_SAVEMEM					PVRSRV_IOWR(PVRSRV_BRIDGE_SGX_CMD_BASE+37)
#endif



#define PVRSRV_BRIDGE_LAST_SGX_CMD (PVRSRV_BRIDGE_SGX_CMD_BASE+37)


typedef struct PVRSRV_BRIDGE_IN_GETPHYSPAGEADDR
{
	IMG_UINT32 ui32BridgeFlags;
	IMG_HANDLE hDevMemHeap;
	IMG_DEV_VIRTADDR sDevVAddr;
}PVRSRV_BRIDGE_IN_GETPHYSPAGEADDR;


typedef struct PVRSRV_BRIDGE_OUT_GETPHYSPAGEADDR
{
	PVRSRV_ERROR		eError;
	IMG_DEV_PHYADDR		DevPAddr;
	IMG_CPU_PHYADDR		CpuPAddr;
}PVRSRV_BRIDGE_OUT_GETPHYSPAGEADDR;


typedef struct PVRSRV_BRIDGE_IN_SGX_SET_TRANSFER_CONTEXT_PRIORITY_TAG
 {
	IMG_UINT32				ui32BridgeFlags;
 #if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
	IMG_SID					hHWTransferContext;
 #else
	IMG_HANDLE				hDevCookie;
	IMG_HANDLE				hHWTransferContext;
 #endif
    IMG_UINT32              ui32Priority;
    IMG_UINT32              ui32OffsetOfPriorityField;
}PVRSRV_BRIDGE_IN_SGX_SET_TRANSFER_CONTEXT_PRIORITY;


typedef struct PVRSRV_BRIDGE_IN_SGX_SET_RENDER_CONTEXT_PRIORITY_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
	IMG_SID					hHWRenderContext;
#else
	IMG_HANDLE				hDevCookie;
	IMG_HANDLE				hHWRenderContext;
#endif
    IMG_UINT32              ui32Priority;
    IMG_UINT32              ui32OffsetOfPriorityField;
}PVRSRV_BRIDGE_IN_SGX_SET_RENDER_CONTEXT_PRIORITY;


typedef struct PVRSRV_BRIDGE_IN_GETCLIENTINFO_TAG
{
	IMG_UINT32					ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID						hDevCookie;
#else
	IMG_HANDLE					hDevCookie;
#endif
}PVRSRV_BRIDGE_IN_GETCLIENTINFO;


typedef struct PVRSRV_BRIDGE_OUT_GETINTERNALDEVINFO_TAG
{
	SGX_INTERNAL_DEVINFO	sSGXInternalDevInfo;
	PVRSRV_ERROR				eError;
}PVRSRV_BRIDGE_OUT_GETINTERNALDEVINFO;


typedef struct PVRSRV_BRIDGE_IN_GETINTERNALDEVINFO_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
#else
	IMG_HANDLE				hDevCookie;
#endif
}PVRSRV_BRIDGE_IN_GETINTERNALDEVINFO;


typedef struct PVRSRV_BRIDGE_OUT_GETCLIENTINFO_TAG
{
	SGX_CLIENT_INFO  	sClientInfo;
	PVRSRV_ERROR			eError;
}PVRSRV_BRIDGE_OUT_GETCLIENTINFO;


typedef struct PVRSRV_BRIDGE_IN_RELEASECLIENTINFO_TAG
{
	IMG_UINT32			ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID				hDevCookie;
#else
	IMG_HANDLE			hDevCookie;
#endif
	SGX_CLIENT_INFO  	sClientInfo;
}PVRSRV_BRIDGE_IN_RELEASECLIENTINFO;


typedef struct PVRSRV_BRIDGE_IN_ISPBREAKPOLL_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
#else
	IMG_HANDLE				hDevCookie;
#endif
}PVRSRV_BRIDGE_IN_ISPBREAKPOLL;


typedef struct PVRSRV_BRIDGE_IN_DOKICK_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
#else
	IMG_HANDLE				hDevCookie;
#endif
	SGX_CCB_KICK			sCCBKick;
}PVRSRV_BRIDGE_IN_DOKICK;


typedef struct PVRSRV_BRIDGE_IN_SGX_SCHEDULE_PROCESS_QUEUES_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
#else
	IMG_HANDLE				hDevCookie;
#endif
}PVRSRV_BRIDGE_IN_SGX_SCHEDULE_PROCESS_QUEUES;


#if defined(TRANSFER_QUEUE)

typedef struct PVRSRV_BRIDGE_IN_SUBMITTRANSFER_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
#else
	IMG_HANDLE				hDevCookie;
#endif
	PVRSRV_TRANSFER_SGX_KICK 			sKick;
}PVRSRV_BRIDGE_IN_SUBMITTRANSFER;

#if defined(SGX_FEATURE_2D_HARDWARE)

typedef struct PVRSRV_BRIDGE_IN_SUBMIT2D_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
#else
	IMG_HANDLE				hDevCookie;
#endif
	PVRSRV_2D_SGX_KICK 		sKick;
} PVRSRV_BRIDGE_IN_SUBMIT2D;
#endif
#endif


typedef struct PVRSRV_BRIDGE_IN_READREGDWORD_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
#else
	IMG_HANDLE				hDevCookie;
#endif
    IMG_PCHAR				pszKey;
    IMG_PCHAR				pszValue;
}PVRSRV_BRIDGE_IN_READREGDWORD;


typedef struct PVRSRV_BRIDGE_OUT_READREGDWORD_TAG
{
	PVRSRV_ERROR	eError;
	IMG_UINT32		ui32Data;
}PVRSRV_BRIDGE_OUT_READREGDWORD;


typedef struct PVRSRV_BRIDGE_IN_SGXGETMISCINFO_TAG
{
	IMG_UINT32		ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID			hDevCookie;
#else
	IMG_HANDLE		hDevCookie;
#endif
	SGX_MISC_INFO	*psMiscInfo;
}PVRSRV_BRIDGE_IN_SGXGETMISCINFO;

typedef struct PVRSRV_BRIDGE_IN_SGXINFO_FOR_SRVINIT_TAG
{
	IMG_UINT32		ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID			hDevCookie;
#else
	IMG_HANDLE		hDevCookie;
#endif
}PVRSRV_BRIDGE_IN_SGXINFO_FOR_SRVINIT;

typedef struct PVRSRV_BRIDGE_OUT_SGXINFO_FOR_SRVINIT_TAG
{
	PVRSRV_ERROR			eError;
	SGX_BRIDGE_INFO_FOR_SRVINIT	sInitInfo;
}PVRSRV_BRIDGE_OUT_SGXINFO_FOR_SRVINIT;

typedef struct PVRSRV_BRIDGE_IN_SGXDEVINITPART2_TAG
{
	IMG_UINT32		ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID			hDevCookie;
#else
	IMG_HANDLE		hDevCookie;
#endif
	SGX_BRIDGE_INIT_INFO	sInitInfo;
}PVRSRV_BRIDGE_IN_SGXDEVINITPART2;

typedef struct PVRSRV_BRIDGE_OUT_SGXDEVINITPART2_TAG
{
	PVRSRV_ERROR 	eError;
	IMG_UINT32 		ui32KMBuildOptions;

}PVRSRV_BRIDGE_OUT_SGXDEVINITPART2;


typedef struct PVRSRV_BRIDGE_IN_2DQUERYBLTSCOMPLETE_TAG
{
	IMG_UINT32				ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID					hDevCookie;
	IMG_SID					hKernSyncInfo;
#else
	IMG_HANDLE				hDevCookie;
	IMG_HANDLE				hKernSyncInfo;
#endif
	IMG_BOOL				bWaitForComplete;
}PVRSRV_BRIDGE_IN_2DQUERYBLTSCOMPLETE;


#define PVRSRV_BRIDGE_SGX_SHAREDPBDESC_MAX_SUBMEMINFOS 10

typedef struct PVRSRV_BRIDGE_IN_SGXFINDSHAREDPBDESC_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
#else
	IMG_HANDLE hDevCookie;
#endif
	IMG_BOOL   bLockOnFailure;
	IMG_UINT32 ui32TotalPBSize;
}PVRSRV_BRIDGE_IN_SGXFINDSHAREDPBDESC;

typedef struct PVRSRV_BRIDGE_OUT_SGXFINDSHAREDPBDESC_TAG
{
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID hKernelMemInfo;
	IMG_SID hSharedPBDesc;
	IMG_SID hSharedPBDescKernelMemInfoHandle;
	IMG_SID hHWPBDescKernelMemInfoHandle;
	IMG_SID hBlockKernelMemInfoHandle;
	IMG_SID hHWBlockKernelMemInfoHandle;
	IMG_SID ahSharedPBDescSubKernelMemInfoHandles[PVRSRV_BRIDGE_SGX_SHAREDPBDESC_MAX_SUBMEMINFOS];
#else
	IMG_HANDLE hKernelMemInfo;
	IMG_HANDLE hSharedPBDesc;
	IMG_HANDLE hSharedPBDescKernelMemInfoHandle;
	IMG_HANDLE hHWPBDescKernelMemInfoHandle;
	IMG_HANDLE hBlockKernelMemInfoHandle;
	IMG_HANDLE hHWBlockKernelMemInfoHandle;
	IMG_HANDLE ahSharedPBDescSubKernelMemInfoHandles[PVRSRV_BRIDGE_SGX_SHAREDPBDESC_MAX_SUBMEMINFOS];
#endif
	IMG_UINT32 ui32SharedPBDescSubKernelMemInfoHandlesCount;
	PVRSRV_ERROR eError;
}PVRSRV_BRIDGE_OUT_SGXFINDSHAREDPBDESC;

typedef struct PVRSRV_BRIDGE_IN_SGXUNREFSHAREDPBDESC_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hSharedPBDesc;
#else
	IMG_HANDLE hSharedPBDesc;
#endif
}PVRSRV_BRIDGE_IN_SGXUNREFSHAREDPBDESC;

typedef struct PVRSRV_BRIDGE_OUT_SGXUNREFSHAREDPBDESC_TAG
{
	PVRSRV_ERROR eError;
}PVRSRV_BRIDGE_OUT_SGXUNREFSHAREDPBDESC;


typedef struct PVRSRV_BRIDGE_IN_SGXADDSHAREDPBDESC_TAG
{
	IMG_UINT32 ui32BridgeFlags;
	IMG_UINT32 ui32TotalPBSize;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
	IMG_SID    hSharedPBDescKernelMemInfo;
	IMG_SID    hHWPBDescKernelMemInfo;
	IMG_SID    hBlockKernelMemInfo;
	IMG_SID    hHWBlockKernelMemInfo;
	IMG_SID    *phKernelMemInfoHandles;
#else
	IMG_HANDLE hDevCookie;
	IMG_HANDLE hSharedPBDescKernelMemInfo;
	IMG_HANDLE hHWPBDescKernelMemInfo;
	IMG_HANDLE hBlockKernelMemInfo;
	IMG_HANDLE hHWBlockKernelMemInfo;
	IMG_HANDLE *phKernelMemInfoHandles;
#endif
	IMG_UINT32 ui32KernelMemInfoHandlesCount;
	IMG_DEV_VIRTADDR sHWPBDescDevVAddr;
}PVRSRV_BRIDGE_IN_SGXADDSHAREDPBDESC;

typedef struct PVRSRV_BRIDGE_OUT_SGXADDSHAREDPBDESC_TAG
{
	PVRSRV_ERROR eError;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID      hSharedPBDesc;
#else
	IMG_HANDLE hSharedPBDesc;
#endif
}PVRSRV_BRIDGE_OUT_SGXADDSHAREDPBDESC;


#ifdef	PDUMP
typedef struct PVRSRV_BRIDGE_IN_PDUMP_BUFFER_ARRAY_TAG
{
	IMG_UINT32 ui32BridgeFlags;
	SGX_KICKTA_DUMP_BUFFER *psBufferArray;
	IMG_UINT32 ui32BufferArrayLength;
	IMG_BOOL bDumpPolls;
} PVRSRV_BRIDGE_IN_PDUMP_BUFFER_ARRAY;

typedef struct PVRSRV_BRIDGE_IN_PDUMP_3D_SIGNATURE_REGISTERS_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
	IMG_SID    hDevMemContext;
#else
	IMG_HANDLE hDevCookie;
	IMG_HANDLE hDevMemContext;
#endif
	IMG_UINT32 ui32DumpFrameNum;
	IMG_BOOL   bLastFrame;
	IMG_UINT32 *pui32Registers;
	IMG_UINT32 ui32NumRegisters;
}PVRSRV_BRIDGE_IN_PDUMP_3D_SIGNATURE_REGISTERS;

typedef struct PVRSRV_BRIDGE_IN_PDUMPCOUNTER_REGISTERS_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
#else
	IMG_HANDLE hDevCookie;
#endif
	IMG_UINT32 ui32DumpFrameNum;
	IMG_BOOL bLastFrame;
	IMG_UINT32 *pui32Registers;
	IMG_UINT32 ui32NumRegisters;
}PVRSRV_BRIDGE_IN_PDUMP_COUNTER_REGISTERS;

typedef struct PVRSRV_BRIDGE_IN_PDUMP_TA_SIGNATURE_REGISTERS_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
#else
	IMG_HANDLE hDevCookie;
#endif
	IMG_UINT32 ui32DumpFrameNum;
	IMG_UINT32 ui32TAKickCount;
	IMG_BOOL bLastFrame;
	IMG_UINT32 *pui32Registers;
	IMG_UINT32 ui32NumRegisters;
}PVRSRV_BRIDGE_IN_PDUMP_TA_SIGNATURE_REGISTERS;

typedef struct PVRSRV_BRIDGE_IN_PDUMP_HWPERFCB_TAG
{
	IMG_UINT32			ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID				hDevCookie;
	IMG_SID				hDevMemContext;
#else
	IMG_HANDLE			hDevCookie;
	IMG_HANDLE			hDevMemContext;
#endif
	IMG_CHAR			szFileName[PVRSRV_PDUMP_MAX_FILENAME_SIZE];
	IMG_UINT32			ui32FileOffset;
	IMG_UINT32			ui32PDumpFlags;

}PVRSRV_BRIDGE_IN_PDUMP_HWPERFCB;

typedef struct PVRSRV_BRIDGE_IN_PDUMP_SAVEMEM
{
	IMG_UINT32			ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID				hDevCookie;
	IMG_SID				hDevMemContext;
#else
	IMG_HANDLE			hDevCookie;
#endif
	IMG_CHAR			szFileName[PVRSRV_PDUMP_MAX_FILENAME_SIZE];
	IMG_UINT32			ui32FileOffset;
	IMG_DEV_VIRTADDR 	sDevVAddr;
	IMG_UINT32			ui32Size;
#if !defined (SUPPORT_SID_INTERFACE)
	IMG_HANDLE			hDevMemContext;
#endif
	IMG_UINT32			ui32PDumpFlags;

}PVRSRV_BRIDGE_IN_PDUMP_SAVEMEM;

#endif

typedef struct PVRSRV_BRIDGE_IN_SGX_REGISTER_HW_RENDER_CONTEXT_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
#else
	IMG_HANDLE hDevCookie;
#endif
    IMG_CPU_VIRTADDR pHWRenderContextCpuVAddr;
    IMG_UINT32       ui32HWRenderContextSize;
    IMG_UINT32       ui32OffsetToPDDevPAddr;
    IMG_HANDLE       hDevMemContext;
}PVRSRV_BRIDGE_IN_SGX_REGISTER_HW_RENDER_CONTEXT;

typedef struct PVRSRV_BRIDGE_OUT_SGX_REGISTER_HW_RENDER_CONTEXT_TAG
{
	PVRSRV_ERROR eError;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hHWRenderContext;
#else
	IMG_HANDLE hHWRenderContext;
#endif
    IMG_DEV_VIRTADDR sHWRenderContextDevVAddr;
}PVRSRV_BRIDGE_OUT_SGX_REGISTER_HW_RENDER_CONTEXT;

typedef struct PVRSRV_BRIDGE_IN_SGX_UNREGISTER_HW_RENDER_CONTEXT_TAG
{
	IMG_UINT32 ui32BridgeFlags;
	IMG_BOOL   bForceCleanup;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
	IMG_SID    hHWRenderContext;
#else
	IMG_HANDLE hDevCookie;
	IMG_HANDLE hHWRenderContext;
#endif
}PVRSRV_BRIDGE_IN_SGX_UNREGISTER_HW_RENDER_CONTEXT;

typedef struct PVRSRV_BRIDGE_IN_SGX_REGISTER_HW_TRANSFER_CONTEXT_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
#else
	IMG_HANDLE hDevCookie;
#endif
    IMG_CPU_VIRTADDR pHWTransferContextCpuVAddr;
    IMG_UINT32       ui32HWTransferContextSize;
    IMG_UINT32       ui32OffsetToPDDevPAddr;
    IMG_HANDLE       hDevMemContext;
}PVRSRV_BRIDGE_IN_SGX_REGISTER_HW_TRANSFER_CONTEXT;

typedef struct PVRSRV_BRIDGE_OUT_SGX_REGISTER_HW_TRANSFER_CONTEXT_TAG
{
	PVRSRV_ERROR eError;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID      hHWTransferContext;
#else
	IMG_HANDLE hHWTransferContext;
#endif
    IMG_DEV_VIRTADDR sHWTransferContextDevVAddr;
}PVRSRV_BRIDGE_OUT_SGX_REGISTER_HW_TRANSFER_CONTEXT;

typedef struct PVRSRV_BRIDGE_IN_SGX_UNREGISTER_HW_TRANSFER_CONTEXT_TAG
{
	IMG_UINT32 ui32BridgeFlags;
	IMG_BOOL   bForceCleanup;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
	IMG_SID    hHWTransferContext;
#else
	IMG_HANDLE hDevCookie;
	IMG_HANDLE hHWTransferContext;
#endif
}PVRSRV_BRIDGE_IN_SGX_UNREGISTER_HW_TRANSFER_CONTEXT;

typedef struct PVRSRV_BRIDGE_IN_SGX_FLUSH_HW_RENDER_TARGET_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
#else
	IMG_HANDLE hDevCookie;
#endif
	IMG_DEV_VIRTADDR sHWRTDataSetDevVAddr;
}PVRSRV_BRIDGE_IN_SGX_FLUSH_HW_RENDER_TARGET;


#if defined(SGX_FEATURE_2D_HARDWARE)
typedef struct PVRSRV_BRIDGE_IN_SGX_REGISTER_HW_2D_CONTEXT_TAG
{
	IMG_UINT32 ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
#else
	IMG_HANDLE hDevCookie;
#endif
    IMG_CPU_VIRTADDR pHW2DContextCpuVAddr;
    IMG_UINT32       ui32HW2DContextSize;
    IMG_UINT32       ui32OffsetToPDDevPAddr;
    IMG_HANDLE       hDevMemContext;
}PVRSRV_BRIDGE_IN_SGX_REGISTER_HW_2D_CONTEXT;

typedef struct PVRSRV_BRIDGE_OUT_SGX_REGISTER_HW_2D_CONTEXT_TAG
{
	PVRSRV_ERROR eError;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hHW2DContext;
#else
	IMG_HANDLE hHW2DContext;
#endif
    IMG_DEV_VIRTADDR sHW2DContextDevVAddr;
}PVRSRV_BRIDGE_OUT_SGX_REGISTER_HW_2D_CONTEXT;

typedef struct PVRSRV_BRIDGE_IN_SGX_UNREGISTER_HW_2D_CONTEXT_TAG
{
	IMG_UINT32 ui32BridgeFlags;
	IMG_BOOL   bForceCleanup;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID    hDevCookie;
	IMG_SID    hHW2DContext;
#else
	IMG_HANDLE hDevCookie;
	IMG_HANDLE hHW2DContext;
#endif
}PVRSRV_BRIDGE_IN_SGX_UNREGISTER_HW_2D_CONTEXT;

#define	SGX2D_MAX_BLT_CMD_SIZ		256
#endif


typedef struct PVRSRV_BRIDGE_IN_SGX_READ_HWPERF_CB_TAG
{
	IMG_UINT32					ui32BridgeFlags;
#if defined (SUPPORT_SID_INTERFACE)
	IMG_SID						hDevCookie;
#else
	IMG_HANDLE					hDevCookie;
#endif
	IMG_UINT32					ui32ArraySize;
	PVRSRV_SGX_HWPERF_CB_ENTRY	*psHWPerfCBData;
} PVRSRV_BRIDGE_IN_SGX_READ_HWPERF_CB;

typedef struct PVRSRV_BRIDGE_OUT_SGX_READ_HWPERF_CB_TAG
{
	PVRSRV_ERROR		eError;
	IMG_UINT32			ui32DataCount;
	IMG_UINT32			ui32ClockSpeed;
	IMG_UINT32			ui32HostTimeStamp;
} PVRSRV_BRIDGE_OUT_SGX_READ_HWPERF_CB;

#if defined (__cplusplus)
}
#endif

#endif
