/*++

    The MIT License (MIT)

    Copyright (c) 2015 Aleksey Kabanov

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

Module Name:

    Communication.h

Abstract:

    Contains function prototypes for communication with the user-mode client(s).

Environment:

    Kernel mode.

--*/

#pragma once
#ifndef __LAZY_COPY_COMMUNICATION_H__
#define __LAZY_COPY_COMMUNICATION_H__

//------------------------------------------------------------------------
//  Includes.
//------------------------------------------------------------------------

#include "Globals.h"

//------------------------------------------------------------------------
//  Function prototypes.
//------------------------------------------------------------------------

_Check_return_
NTSTATUS
LcCreateCommunicationPort();

VOID
LcCloseCommunicationPort();

_Check_return_
NTSTATUS
LcOpenFileInUserMode(
    _In_  PCUNICODE_STRING SourceFile,
    _In_  PCUNICODE_STRING TargetFile,
    _Out_ PHANDLE          Handle
    );

_Check_return_
NTSTATUS
LcCloseFileHandle(
    _In_ HANDLE FileHandle
    );

_Check_return_
NTSTATUS
LcFetchFileInUserMode(
    _In_  PCUNICODE_STRING SourceFile,
    _In_  PCUNICODE_STRING TargetFile,
    _Out_ PLARGE_INTEGER   BytesCopied
    );

#endif // __LAZY_COPY_COMMUNICATION_H__
