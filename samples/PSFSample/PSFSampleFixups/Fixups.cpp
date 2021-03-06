//-------------------------------------------------------------------------------------------------------
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
//-------------------------------------------------------------------------------------------------------
//
// Fixups.cpp : Defines the PackageSupportFramework fixup behavior for the PSFSample Centennial app
//

#include "stdafx.h"
#define PSF_DEFINE_EXPORTS
#include <psf_framework.h>

#include <filesystem>
#include <string_view>
#include <winrt/Windows.Storage.h>

using namespace std::literals;

// Intercept and customize MessageBox calls
auto MessageBoxWImpl = &::MessageBoxW;
int WINAPI MessageBoxWFixup(
    _In_opt_ HWND hwnd,
    _In_opt_ LPCWSTR message,
    _In_opt_ LPCWSTR /*caption*/,
    _In_ UINT type)
{
    return MessageBoxWImpl(hwnd, message, L"Fixup Message", type);
}
DECLARE_FIXUP(MessageBoxWImpl, MessageBoxWFixup);

// Redirect log file writes to the app's cache folder
auto CreateFileWImpl = &::CreateFileW;
HANDLE WINAPI CreateFileWFixup(
    _In_ LPCWSTR lpFileName,
    _In_ DWORD dwDesiredAccess,
    _In_ DWORD dwShareMode,
    _In_opt_ LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    _In_ DWORD dwCreationDisposition,
    _In_ DWORD dwFlagsAndAttributes,
    _In_opt_ HANDLE hTemplateFile
){

    auto createFile = [&](_In_ LPCWSTR fileName) {return CreateFileWImpl(
        fileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
        dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile); };

    if ((dwDesiredAccess & GENERIC_WRITE) != 0)
    {
        std::experimental::filesystem::path filePath(lpFileName);
        if (filePath.extension().compare(L".log") == 0)
        {
            try
            {
                static auto localCacheFolder = winrt::Windows::Storage::ApplicationData::Current().LocalCacheFolder();
                auto cachedFilePath = std::experimental::filesystem::path(localCacheFolder.Path().c_str()) / filePath.filename();
                auto message = std::wstring(L"Redirecting log file write to:\n\n") + cachedFilePath.c_str();
                MessageBoxW(NULL, message.c_str(), L"", MB_OK);
                return createFile(cachedFilePath.c_str());
            }
            catch (...)
            {
                // Ensure that no exceptions escape.  If so, fall back to CreateFile with original arguments.
            }
        }
    }

    return createFile(lpFileName);
}
DECLARE_FIXUP(CreateFileWImpl, CreateFileWFixup);
