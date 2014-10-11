/*
     File:       HIToolbox/Notification.h
 
     Contains:   Notification Manager interfaces
 
     Version:    HIToolbox-79.9~1
 
     Copyright:  � 1989-2001 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __NOTIFICATION__
#define __NOTIFICATION__

#ifndef __MACTYPES__
#include <CarbonCore/MacTypes.h>
#endif

#ifndef __OSUTILS__
#include <CarbonCore/OSUtils.h>
#endif




#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_STRUCT_ALIGN
    #pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
    #pragma pack(2)
#endif

typedef struct NMRec                    NMRec;
typedef NMRec *                         NMRecPtr;
typedef CALLBACK_API( void , NMProcPtr )(NMRecPtr nmReqPtr);
typedef STACK_UPP_TYPE(NMProcPtr)                               NMUPP;
struct NMRec {
  QElemPtr            qLink;                  /* next queue entry*/
  short               qType;                  /* queue type -- ORD(nmType) = 8*/
  short               nmFlags;                /* reserved*/
  long                nmPrivate;              /* reserved*/
  short               nmReserved;             /* reserved*/
  short               nmMark;                 /* item to mark in Apple menu*/
  Handle              nmIcon;                 /* handle to small icon*/
  Handle              nmSound;                /* handle to sound record*/
  StringPtr           nmStr;                  /* string to appear in alert*/
  NMUPP               nmResp;                 /* pointer to response routine*/
  long                nmRefCon;               /* for application use*/
};

/*
 *  NewNMUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern NMUPP
NewNMUPP(NMProcPtr userRoutine);

/*
 *  DisposeNMUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeNMUPP(NMUPP userUPP);

/*
 *  InvokeNMUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeNMUPP(
  NMRecPtr  nmReqPtr,
  NMUPP     userUPP);

/*
 *  NMInstall()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern OSErr 
NMInstall(NMRecPtr nmReqPtr);


/*
 *  NMRemove()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern OSErr 
NMRemove(NMRecPtr nmReqPtr);




#if PRAGMA_STRUCT_ALIGN
    #pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
    #pragma pack()
#endif

#ifdef __cplusplus
}
#endif

#endif /* __NOTIFICATION__ */
