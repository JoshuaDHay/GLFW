//========================================================================
// GLFW 3.3 Mir - www.glfw.org
//------------------------------------------------------------------------
// Copyright (c) 2014-2017 Brandon Schaefer <brandon.schaefer@canonical.com>
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

#include <stdlib.h>


//////////////////////////////////////////////////////////////////////////
//////                       GLFW internal API                      //////
//////////////////////////////////////////////////////////////////////////

// Poll for changes in the set of connected monitors
//
void _glfwPollMonitorsMir(void)
{
    int i;
    MirDisplayConfiguration* displayConfig =
        mir_connection_create_display_config(_glfw.mir.connection);

    for (i = 0;  i < displayConfig->num_outputs;  i++)
    {
        const MirDisplayOutput* out = displayConfig->outputs + i;

        if (out->used &&
            out->connected &&
            out->num_modes &&
            out->current_mode < out->num_modes)
        {
            _GLFWmonitor* monitor = _glfwAllocMonitor("Unknown",
                                                      out->physical_width_mm,
                                                      out->physical_height_mm);

            monitor->mir.x        = out->position_x;
            monitor->mir.y        = out->position_y;
            monitor->mir.outputId = out->output_id;
            monitor->mir.curMode  = out->current_mode;
            monitor->modes = _glfwPlatformGetVideoModes(monitor, &monitor->modeCount);

            _glfwInputMonitor(monitor, GLFW_CONNECTED, _GLFW_INSERT_LAST);
        }
    }

    mir_display_config_destroy(displayConfig);
}


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

void _glfwPlatformGetMonitorPos(_GLFWmonitor* monitor, int* xpos, int* ypos)
{
    if (xpos)
        *xpos = monitor->mir.x;
    if (ypos)
        *ypos = monitor->mir.y;
}

void FillInRGBBitsFromPixelFormat(GLFWvidmode* mode, const MirPixelFormat pf)
{
    switch (pf)
    {
      case mir_pixel_format_rgb_565:
          mode->redBits   = 5;
          mode->greenBits = 6;
          mode->blueBits  = 5;
          break;
      case mir_pixel_format_rgba_5551:
          mode->redBits   = 5;
          mode->greenBits = 5;
          mode->blueBits  = 5;
          break;
      case mir_pixel_format_rgba_4444:
          mode->redBits   = 4;
          mode->greenBits = 4;
          mode->blueBits  = 4;
          break;
      case mir_pixel_format_abgr_8888:
      case mir_pixel_format_xbgr_8888:
      case mir_pixel_format_argb_8888:
      case mir_pixel_format_xrgb_8888:
      case mir_pixel_format_bgr_888:
      case mir_pixel_format_rgb_888:
      default:
          mode->redBits   = 8;
          mode->greenBits = 8;
          mode->blueBits  = 8;
          break;
    }
}

GLFWvidmode* _glfwPlatformGetVideoModes(_GLFWmonitor* monitor, int* found)
{
    int i;
    GLFWvidmode* modes = NULL;
    MirDisplayConfiguration* displayConfig =
        mir_connection_create_display_config(_glfw.mir.connection);

    for (i = 0;  i < displayConfig->num_outputs;  i++)
    {
        const MirDisplayOutput* out = displayConfig->outputs + i;
        if (out->output_id != monitor->mir.outputId)
            continue;

        modes = calloc(out->num_modes, sizeof(GLFWvidmode));

        for (*found = 0;  *found < out->num_modes;  (*found)++)
        {
            modes[*found].width  = out->modes[*found].horizontal_resolution;
            modes[*found].height = out->modes[*found].vertical_resolution;
            modes[*found].refreshRate = out->modes[*found].refresh_rate;

            FillInRGBBitsFromPixelFormat(&modes[*found], out->output_formats[*found]);
        }

        break;
    }

    mir_display_config_destroy(displayConfig);

    return modes;
}

void _glfwPlatformGetVideoMode(_GLFWmonitor* monitor, GLFWvidmode* mode)
{
    *mode = monitor->modes[monitor->mir.curMode];
}

void _glfwPlatformGetGammaRamp(_GLFWmonitor* monitor, GLFWgammaramp* ramp)
{
    _glfwInputError(GLFW_PLATFORM_ERROR,
                    "Mir: Unsupported function %s", __PRETTY_FUNCTION__);
}

void _glfwPlatformSetGammaRamp(_GLFWmonitor* monitor, const GLFWgammaramp* ramp)
{
    _glfwInputError(GLFW_PLATFORM_ERROR,
                    "Mir: Unsupported function %s", __PRETTY_FUNCTION__);
}


//////////////////////////////////////////////////////////////////////////
//////                        GLFW native API                       //////
//////////////////////////////////////////////////////////////////////////

GLFWAPI int glfwGetMirMonitor(GLFWmonitor* handle)
{
    _GLFWmonitor* monitor = (_GLFWmonitor*) handle;
    _GLFW_REQUIRE_INIT_OR_RETURN(0);
    return monitor->mir.outputId;
}

