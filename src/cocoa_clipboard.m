//========================================================================
// GLFW 3.1 OS X - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2010 Camilla Berglund <elmindreda@elmindreda.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include "internal.h"

#include <limits.h>
#include <string.h>


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

void _glfwPlatformSetClipboardString(_GLFWwindow* window, const char* string)
{
    NSArray* types = [NSArray arrayWithObjects:NSStringPboardType, nil];

    NSPasteboard* pasteboard = [NSPasteboard generalPasteboard];
    [pasteboard declareTypes:types owner:nil];
    [pasteboard setString:[NSString stringWithUTF8String:string]
                  forType:NSStringPboardType];
}

const char* _glfwPlatformGetClipboardString(_GLFWwindow* window)
{
    NSPasteboard* pasteboard = [NSPasteboard generalPasteboard];

    if (![[pasteboard types] containsObject:NSStringPboardType])
    {
        _glfwInputError(GLFW_FORMAT_UNAVAILABLE, NULL);
        return NULL;
    }

    NSString* object = [pasteboard stringForType:NSStringPboardType];
    if (!object)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Cocoa: Failed to retrieve object from pasteboard");
        return NULL;
    }

    free(_glfw.ns.clipboardString);
    _glfw.ns.clipboardString = strdup([object UTF8String]);

    return _glfw.ns.clipboardString;
}

